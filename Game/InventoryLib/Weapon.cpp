#include "Weapon.h"
#include <iostream>

const void Weapon::displayInConsole() const {
    std::cout << "Weapon Info:" << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Skin: " << skin << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Ammo: " << ammoType << "\n";
    std::cout << "Fire Modes: " << fireModes << "\n";
    std::cout << "Damage (Body): " << damageBody << "\n";
    std::cout << "Damage (Head): " << damageHead << "\n";
    std::cout << "Damage (Legs): " << damageLegs << "\n";
    std::cout << "Tactical Reload Time: " << tacticalReloadTime << "\n";
    std::cout << "Full Reload Time: " << fullReloadTime << "\n";
    std::cout << "Is Fully Kitted: " << (isFullyKitted ? "Yes" : "No") << "\n";
    std::cout << "Kitted Level: " << kittedLevel << "\n\n";
}
