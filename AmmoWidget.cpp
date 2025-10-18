#include "AmmoWidget.h"
#include "Components/Image.h"

void UAmmoWidget::UpdateAmmoDisplay(int32 CurrentAmmo)
{
    if (!AmmoImage)
    {
        UE_LOG(LogTemp, Warning, TEXT("AmmoImage não encontrado no UAmmoWidget!"));
        return;
    }
    //Ericson precisa importar as imagens e fatiar em 36 para ter o Array de Brushes preenchido.
    // Verifica se temos um brush para esta contagem de munição
    if (AmmoBrushes.IsValidIndex(CurrentAmmo))
    {
        // Define o brush da imagem para o sprite correspondente
        AmmoImage->SetBrush(AmmoBrushes[CurrentAmmo]);
        AmmoImage->SetVisibility(ESlateVisibility::Visible);
    }
    else
    {
        // Se a contagem estiver fora do intervalo, esconde a imagem ou define um padrão
        UE_LOG(LogTemp, Warning, TEXT("Contagem de munição (%d) fora do intervalo de AmmoBrushes!"), CurrentAmmo);
        AmmoImage->SetVisibility(ESlateVisibility::Hidden);
    }
}