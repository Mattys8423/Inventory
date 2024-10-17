#include "Weapon.h"
#include <iostream>

const void Weapon::displayInConsole() const {
    std::cout << "Weapon Info:" << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Skin: " << getSkin() << "\n";
    std::cout << "Type: " << getType() << "\n";
    std::cout << "Ammo: " << getAmmo() << "\n";
    std::cout << "Fire Modes: " << getFireModes() << "\n";
    std::cout << "Damage (Body): " << getDamageBody() << "\n";
    std::cout << "Damage (Head): " << getDamageHead() << "\n";
    std::cout << "Damage (Legs): " << getDamageLegs() << "\n";
    std::cout << "Tactical Reload Time: " << getTacticalReloadTime() << "\n";
    std::cout << "Full Reload Time: " << getFullReloadTime() << "\n";
    std::cout << "Is Fully Kitted: " << (getIsFullyKitted() ? "Yes" : "No") << "\n";
    std::cout << "Kitted Level: " << getKittedLevel() << "\n\n";
}
