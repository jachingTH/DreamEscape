#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "DreamEscapeGameInstance.generated.h"

// UI 노출용 서버 리스트 구조체
USTRUCT(BlueprintType)
struct FServerListEntry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly) FString ServerName;
    UPROPERTY(BlueprintReadOnly) int32 CurrentPlayers = 0;
    UPROPERTY(BlueprintReadOnly) int32 MaxPlayers = 4;
    UPROPERTY(BlueprintReadOnly) int32 Ping = 0;
    UPROPERTY(BlueprintReadOnly) FString BuildVersion;
    UPROPERTY(BlueprintReadOnly) int32 SearchResultIndex = INDEX_NONE;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnServerListUpdated, const TArray<FServerListEntry>&, ServerList);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionFailureMessage, const FString&, ErrorMessage);

UCLASS()
class DREAMESCAPE_API UDreamEscapeGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    UDreamEscapeGameInstance();
    virtual void Init() override;

    // UI 호출 인터페이스
    UFUNCTION(BlueprintCallable, Category = "Network|Session")
    void HostSession(int32 InMaxPlayers = 4);

    UFUNCTION(BlueprintCallable, Category = "Network|Session")
    void FindGameSessions();

    UFUNCTION(BlueprintCallable, Category = "Network|Session")
    void JoinGameSession(int32 SearchIndex);

    UFUNCTION(BlueprintCallable, Category = "Network|Session")
    void CleanupAndDestroySession();

    // UI 이벤트 디스패처
    UPROPERTY(BlueprintAssignable, Category = "Network|Events")
    FOnServerListUpdated OnServerListUpdated;

    UPROPERTY(BlueprintAssignable, Category = "Network|Events")
    FOnSessionFailureMessage OnSessionFailureMessage;

protected:
    IOnlineSessionPtr SessionInterface;
    TSharedPtr<FOnlineSessionSearch> SessionSearch;

    const FName SessionNameConst = FName("GameSession");
    const FString CurrentBuildVersion = TEXT("0.1.0");

    // 델리게이트 핸들
    FDelegateHandle CreateHandle;
    FDelegateHandle FindHandle;
    FDelegateHandle JoinHandle;
    FDelegateHandle DestroyHandle;

    // 내부 콜백 함수
    void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
    void OnFindSessionsComplete(bool bWasSuccessful);
    void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
    void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
    void OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
};