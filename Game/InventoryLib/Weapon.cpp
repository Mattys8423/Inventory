#include "Weapon.h"
#include <iostream>

const void Weapon::displayInConsole() const {
    std::cout << "Weapon Info:" << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Skin: " << getSkin() << "\n";
    std::cout << "Type: " << getType() << "\n";
    std::cout << "Ammo: " << getAmmo() << "\n";
    std::cout << "Fire Modes: " << getFireModes() << "\n";
    std::cout << "Mag Capacity: " << getMagCapacity() << "\n";
    std::cout << "Damage (Body): " << getDamageBody() << "\n";
    std::cout << "Damage (Head): " << getDamageHead() << "\n";
    std::cout << "Damage (Legs): " << getDamageLegs() << "\n";
    std::cout << "Tactical Reload Time: " << getTacticalReloadTime() << "\n";
    std::cout << "Full Reload Time: " << getFullReloadTime() << "\n";
    std::cout << "Is Fully Kitted: " << (getIsFullyKitted() ? "Yes" : "No") << "\n";
    std::cout << "Kitted Level: " << getKittedLevel() << "\n\n";
}

// Méthode statique pour créer une arme à partir de l'entrée utilisateur
Weapon Weapon::CreateFromInput() {
    std::string name, skin, type, ammoType, fireModes;
    int magCapacity;
    double damageBody, damageHead, damageLegs, tacticalReloadTime, fullReloadTime;
    bool isFullyKitted;
    int kittedLevel;

    // Entrées utilisateur
    std::cout << "Entrez le nom de l'arme: ";
    std::getline(std::cin, name);

    std::cout << "Entrez le skin de l'arme: ";
    std::getline(std::cin, skin);

    std::cout << "Entrez le type de l'arme: ";
    std::getline(std::cin, type);

    std::cout << "Entrez le type de munitions utiliss par l'arme: ";
    std::getline(std::cin, ammoType);

    std::cout << "Entrez les modes de tir (ex: Single, Auto): ";
    std::getline(std::cin, fireModes);

    std::cout << "Entrez la capacite du chargeur: ";
    std::cin >> magCapacity;

    std::cout << "Entrez les degâts sur le corps: ";
    std::cin >> damageBody;

    std::cout << "Entrez les degâts sur la tête: ";
    std::cin >> damageHead;

    std::cout << "Entrez les degâts sur les jambes: ";
    std::cin >> damageLegs;

    std::cout << "Entrez le temps de rechargement tactique: ";
    std::cin >> tacticalReloadTime;

    std::cout << "Entrez le temps de rechargement complet: ";
    std::cin >> fullReloadTime;

    std::cout << "L'arme est-elle complètement equipe (1 pour oui, 0 pour non) ? ";
    std::cin >> isFullyKitted;

    std::cout << "Entrez le niveau d'equipement: ";
    std::cin >> kittedLevel;

    // Ignore les restes de la ligne
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Créer et retourner l'objet Weapon
    return Weapon(name, skin, type, ammoType, fireModes, magCapacity, damageBody, damageHead, damageLegs,
        tacticalReloadTime, fullReloadTime, isFullyKitted, kittedLevel);
}