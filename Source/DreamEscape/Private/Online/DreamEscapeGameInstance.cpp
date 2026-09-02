#include "Online/DreamEscapeGameInstance.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"
#include "Kismet/GameplayStatics.h"

UDreamEscapeGameInstance::UDreamEscapeGameInstance() {}

void UDreamEscapeGameInstance::Init()
{
    Super::Init();

    if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
    {
        SessionInterface = Subsystem->GetSessionInterface();
    }

    // 네트워크 오류 글로벌 바인딩
    if (GEngine)
    {
        GEngine->OnNetworkFailure().AddUObject(this, &UDreamEscapeGameInstance::OnNetworkFailure);
    }
}

void UDreamEscapeGameInstance::HostSession(int32 InMaxPlayers)
{
    UE_LOG(LogTemp, Warning, TEXT("1. HostSession Called!"));

    if (!SessionInterface.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("2. SessionInterface is INVALID!"));
        return;
    }

    // ★ 앞에 'TSharedPtr<FOnlineSessionSettings>' 타입을 직접 명시
    TSharedPtr<FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings());
    SessionSettings->bIsLANMatch = false;
    SessionSettings->NumPublicConnections = InMaxPlayers;
    SessionSettings->bShouldAdvertise = true;
    SessionSettings->bAllowJoinInProgress = true;
    SessionSettings->bAllowJoinViaPresence = true;

    // Steam 세션 필수 일치 옵션
    SessionSettings->bUsesPresence = true;
    SessionSettings->bUseLobbiesIfAvailable = true;

    SessionSettings->Set(FName(TEXT("PRESENCESEARCH")), true, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

    CreateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(
        FOnCreateSessionCompleteDelegate::CreateUObject(this, &UDreamEscapeGameInstance::OnCreateSessionComplete)
    );

    UE_LOG(LogTemp, Warning, TEXT("3. CreateSession Request Sent!"));
    const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
    SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *SessionSettings);
}
void UDreamEscapeGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
    UE_LOG(LogTemp, Warning, TEXT("4. OnCreateSessionComplete - Result: %s"), bWasSuccessful ? TEXT("SUCCESS") : TEXT("FAILED"));

    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateHandle);
    }

    if (bWasSuccessful)
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName("/Game/Maps/Lobby"), true, "listen");
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("CreateSession Failed!"));
    }
}

void UDreamEscapeGameInstance::FindGameSessions()
{
    if (!SessionInterface.IsValid()) return;

    FindHandle = SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(
        FOnFindSessionsCompleteDelegate::CreateUObject(this, &UDreamEscapeGameInstance::OnFindSessionsComplete)
    );

    SessionSearch = MakeShareable(new FOnlineSessionSearch());
    SessionSearch->bIsLanQuery = false;
    SessionSearch->MaxSearchResults = 20;
    SessionSearch->QuerySettings.Set(FName(TEXT("PRESENCESEARCH")), true, EOnlineComparisonOp::Equals);
    const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
    SessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}

void UDreamEscapeGameInstance::OnFindSessionsComplete(bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(FindHandle);
    }

    TArray<FServerListEntry> EntryList;
    if (bWasSuccessful && SessionSearch.IsValid())
    {
        for (int32 i = 0; i < SessionSearch->SearchResults.Num(); ++i)
        {
            const auto& Result = SessionSearch->SearchResults[i];
            FString ServerBuildVersion;
            Result.Session.SessionSettings.Get(FName("BUILD_VERSION"), ServerBuildVersion);

            if (ServerBuildVersion == CurrentBuildVersion)
            {
                FServerListEntry Entry;
                Entry.ServerName = Result.Session.OwningUserName;
                Entry.MaxPlayers = Result.Session.SessionSettings.NumPublicConnections;
                Entry.CurrentPlayers = Entry.MaxPlayers - Result.Session.NumOpenPublicConnections;
                Entry.Ping = Result.PingInMs;
                Entry.BuildVersion = ServerBuildVersion;
                Entry.SearchResultIndex = i;
                EntryList.Add(Entry);
            }
        }
    }
    OnServerListUpdated.Broadcast(EntryList);
}

void UDreamEscapeGameInstance::JoinGameSession(int32 SearchIndex)
{
    if (!SessionInterface.IsValid() || !SessionSearch.IsValid() || !SessionSearch->SearchResults.IsValidIndex(SearchIndex))
    {
        OnSessionFailureMessage.Broadcast(TEXT("유효하지 않은 방 정보입니다."));
        return;
    }

    JoinHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(
        FOnJoinSessionCompleteDelegate::CreateUObject(this, &UDreamEscapeGameInstance::OnJoinSessionComplete)
    );

    const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
    SessionInterface->JoinSession(*LocalPlayer->GetPreferredUniqueNetId(), SessionNameConst, SessionSearch->SearchResults[SearchIndex]);
}

void UDreamEscapeGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(JoinHandle);
    }

    if (Result == EOnJoinSessionCompleteResult::Success)
    {
        FString ConnectString;
        if (SessionInterface->GetResolvedConnectString(SessionName, ConnectString))
        {
            if (APlayerController* PC = GetFirstLocalPlayerController())
            {
                PC->ClientTravel(ConnectString, ETravelType::TRAVEL_Absolute);
            }
        }
    }
    else
    {
        OnSessionFailureMessage.Broadcast(TEXT("방 참가에 실패했습니다."));
    }
}

void UDreamEscapeGameInstance::CleanupAndDestroySession()
{
    if (!SessionInterface.IsValid())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
        return;
    }

    DestroyHandle = SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(
        FOnDestroySessionCompleteDelegate::CreateUObject(this, &UDreamEscapeGameInstance::OnDestroySessionComplete)
    );

    SessionInterface->DestroySession(SessionNameConst);
}

void UDreamEscapeGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
    if (SessionInterface.IsValid())
    {
        SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(DestroyHandle);
    }
    UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
}

void UDreamEscapeGameInstance::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)
{
    CleanupAndDestroySession();
}