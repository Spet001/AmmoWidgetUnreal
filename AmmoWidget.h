#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"
#include "AmmoWidget.generated.h"

class UImage;

UCLASS()
class YOURPROJECT_API UAmmoWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    /**
     * Atualiza a imagem da munição com base na contagem atual.
     * @param CurrentAmmo A contagem atual de balas (ex: 0 a 5).
     */
    UFUNCTION(BlueprintCallable, Category = "Ammo")
    void UpdateAmmoDisplay(int32 CurrentAmmo);

protected:
    /**
     * A imagem no UMG que iremos atualizar. Ericson tem que colocar a imagem no Blueprint.
     */
    UPROPERTY(meta = (BindWidget))
    UImage* AmmoImage;

    /**
     * Array de Brushes (imagens) para os estados da munição.
     * Iremos preencher isso no Blueprint.
     * Espera-se que:
     * Index 0 = Vazio
     * Index 1 = 1 Bala
     * ...
     * Index 5 = 5 Balas (Cheio)
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TArray<FSlateBrush> AmmoBrushes;
};