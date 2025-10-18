#include "MyCharacter.h"
#include "AmmoWidget.h"
// #include "EnhancedInputComponent" se estiver usando !!

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Vincula a ação "Fire" (que você deve mapear para Left Mouse Button 
    // em Project Settings -> Input) para a nossa função C++.
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMyCharacter::OnFirePressed);
    
    // Se você não quiser usar Ações de Input e quiser o clique direto (não recomendado):
    // PlayerInputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &AMyCharacter::OnFirePressed);
}

AMyCharacter::AMyCharacter()
{
    // Inicializa as variáveis no construtor
    MaxAmmo = 5;  // 5 balas no máximo
    CurrentAmmo = MaxAmmo;  // Começa com munição cheia
}

void AMyCharacter::OnFirePressed()
{
    // Decrementa a munição (cicla de 5 até 0)
    CurrentAmmo = (CurrentAmmo > 0) ? CurrentAmmo - 1 : MaxAmmo;

    // Atualiza o widget de munição se ele existir
    if (AmmoWidget)
    {
        AmmoWidget->UpdateAmmoDisplay(CurrentAmmo);
    }

    // Chama o evento de Blueprint para lógica adicional
    HandleFireInput();
}