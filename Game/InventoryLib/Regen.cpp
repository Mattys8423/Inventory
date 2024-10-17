#include "Regen.h"

// Afficher les caracteristiques de l'objet Regen
const void Regen::displayInConsole() const {
    std::cout << "Name: " << GetName() << "\n";
    std::cout << "Type: " << GetType() << "\n";
    std::cout << "Level: " << GetLevel() << "\n";
    std::cout << "Number: " << GetAmount() << "\n";
    std::cout << "Stack Size: " << GetStackSize() << "\n";

	if (GetType() == "Shield")
	{
        std::cout << "Regen: " << GetShieldRegen() << " " << GetType() << "\n";
	}
    if (GetType() == "Health")
    {
        std::cout << "Regen: " << GetHealthRegen() << " " << GetType() << "\n";
    }
    if (GetType() == "Ultimate")
    {
        std::cout << "Regen: " << GetUltimateRegen() << "% " << GetType() << "\n";
    }
    
    std::cout << "Use Time: " << GetUseTime() << " seconds" << "\n";
    std::cout << "Description: " << GetDescription() << "\n";
    std::cout << "\n";
}