#include "Grenade.h"

// Afficher les caracteristiques de la grenade
const void Grenade::displayInConsole() const {
    std::cout << "Grenade Name: " << GetName() << "\n";
    std::cout << "Type: " << GetType() << "\n";
    std::cout << "Number: " << GetNumber() << "\n";
    std::cout << "Ignition Time: " << GetIgnitionTime() << " seconds" << "\n";
    std::cout << "Description: " << GetDescription() << "\n";
    std::cout << "\n";
}