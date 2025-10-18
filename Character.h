#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class YOURPROJECT_API AMyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Construtor
    AMyCharacter();

protected:
    /** Widget de munição que será atualizado */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    class UAmmoWidget* AmmoWidget;

    /** Quantidade atual de munição */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentAmmo;

    /** Quantidade máxima de munição */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxAmmo;

protected:
    /** Aperta o botão esquerdo do mouse  */
    void OnFirePressed();

    /** * Evento de Blueprint chamado quando OnFirePressed() é executado.
     * A lógica de ciclagem de munição será implementada no Blueprint.
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
    void HandleFireInput();

    // --- FUNÇÕES PADRÃO ---
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};