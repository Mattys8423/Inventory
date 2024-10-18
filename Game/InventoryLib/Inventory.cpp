#include "Inventory.h"
#include <iostream>


// Ajouter une arme � l'inventaire
void Inventory::addWeapon(Weapon& target){
    weapon.push_back(target);
}

// Supprimer une arme de l'inventaire par son nom
void Inventory::removeWeapon(Weapon& target) {
    auto it = std::find_if(weapon.begin(), weapon.end(),
        [&target](const Weapon& w) { return w.getName() == target.getName(); });

    if (it != weapon.end()) {
        std::cout << "Weapon " << it->getName() << " removed from inventory." << std::endl;
        weapon.erase(it);
    }
    else {
        std::cout << "Weapon " << target.getName() << " not found in inventory." << std::endl;
    }
}



// Ajouter les munitions � l'inventaire
void Inventory::addAmmo(Ammo& target) {
    ammo.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeAmmo(Ammo& target) {
    auto it = std::find_if(ammo.begin(), ammo.end(),
        [&target](const Ammo& a) { return a.GetType() == target.GetType(); });

    if (it != ammo.end()) {
        std::cout << "Ammo " << it->GetType() << " removed from inventory." << std::endl;
        ammo.erase(it);
    }
    else {
        std::cout << "Ammo " << target.GetType() << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions � l'inventaire
void Inventory::addGrenade(Grenade& target) {
    grenade.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeGrenade(Grenade& target) {
    auto it = std::find_if(grenade.begin(), grenade.end(),
        [&target](const Grenade& g) { return g.GetType() == target.GetType(); });

    if (it != grenade.end()) {
        std::cout << "Grenade " << it->GetType() << " removed from inventory." << std::endl;
        grenade.erase(it);
    }
    else {
        std::cout << "Grenade " << target.GetType() << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions � l'inventaire
void Inventory::addRegen(Regen& target) {
    regen.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeRegen(Regen& target) {
    auto it = std::find_if(regen.begin(), regen.end(),
        [&target](const Regen& r) { return r.GetType() == target.GetType(); });

    if (it != regen.end()) {
        std::cout << "Regen " << it->GetType() << " removed from inventory." << std::endl;
        regen.erase(it);
    }
    else {
        std::cout << "Regen " << target.GetType() << " not found in inventory." << std::endl;
    }
}

// Charger l'inventaire a partir d'un fichier
void Inventory::LoadFromSave(std::vector<std::vector<std::map<std::string, std::string>>>& _items) {
    for (int i = 0; i < _items.size(); i++) {
        for (int j = 0; j < _items[i].size(); j++) {
            const std::string& header = _items[i][j]["Header"]; // Cherche le header qui est le nom de classe
            if (header == "Weapon") {
                LoadWeapon(_items, i);
                break;
            } else if (header == "Ammo") {
                LoadAmmo(_items, i);
                break;
            } else if (header == "Regen") {
                LoadRegen(_items, i);
                break;
            } else if (header == "Grenade") {
                LoadGrenade(_items, i);
                break;
            }
        }
    }
}

// Charge les armes du fichier de sauvegarde dans l'inventaire
void Inventory::LoadWeapon(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i) {
    std::string name, skin, type, ammoType, fireModes;
    double damageBody = 0, damageHead = 0, damageLegs = 0, tacticalReloadTime = 0, fullReloadTime = 0;
    bool isFullyKitted = false;
    int kittedLevel = 0, magCapacity = 0;

    for (const auto& attributes : _items[i]) {
        for (const auto& k : attributes) { // Parcourt les attibuts et attribus leurs valeurs
            if (k.first == "Name") name = k.second;
            else if (k.first == "Skin") skin = k.second;
            else if (k.first == "Type") type = k.second;
            else if (k.first == "AmmoType") ammoType = k.second;
            else if (k.first == "FireModes") fireModes = k.second;
            else if (k.first == "MagCapacity") magCapacity = std::stoi(k.second);
            else if (k.first == "DamageBody") damageBody = std::stod(k.second);
            else if (k.first == "DamageHead") damageHead = std::stod(k.second);
            else if (k.first == "DamageLegs") damageLegs = std::stod(k.second);
            else if (k.first == "TacticalReloadTime") tacticalReloadTime = std::stod(k.second);
            else if (k.first == "FullReloadTime") fullReloadTime = std::stod(k.second);
            else if (k.first == "IsFullyKitted") isFullyKitted = (k.second == "true");
            else if (k.first == "KittedLevel") kittedLevel = std::stoi(k.second);
        }
    }

    // Creer l'arme avec les valeurs correspondantes
    Weapon weapon(
        name, skin, type, ammoType, fireModes, magCapacity, damageBody, damageHead, damageLegs, tacticalReloadTime, fullReloadTime,
        isFullyKitted, kittedLevel
    );

    addWeapon(weapon); // Ajoute l'arme a l'inventaire
}

// Charge les munitions du fichier de sauvegarde dans l'inventaire
void Inventory::LoadAmmo(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i) {
    std::string type;
    int totalAmmo = 0, stackSize = 0;

    for (const auto& attributes : _items[i]) {
        for (const auto& k : attributes) { // Parcourt les attibuts et attribus leurs valeurs
            if (k.first == "Type") type = k.second;
            else if (k.first == "Amount") totalAmmo = std::stoi(k.second);
            else if (k.first == "StackSize") stackSize = std::stoi(k.second);
        }
    }

    // Creer la munition avec les valeurs correspondantes
    Ammo ammo(type, totalAmmo, stackSize);
    addAmmo(ammo); // Ajoute la munition a l'inventaire
}

// Charge les regen du fichier de sauvegarde dans l'inventaire
void Inventory::LoadRegen(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i) {
    std::string name, type, description;
    int level = 0, number = 0, stackNumber = 0, shieldRegen = 0, healthRegen = 0, ultimateRegen = 0;
    double useTime = 0;

    for (const auto& attributes : _items[i]) {
        for (const auto& k : attributes) { // Parcourt les attibuts et attribus leurs valeurs
            if (k.first == "Name") name = k.second;
            else if (k.first == "Type") type = k.second;
            else if (k.first == "Level") level = std::stoi(k.second);
            else if (k.first == "Amount") number = std::stoi(k.second);
            else if (k.first == "StackNumber") stackNumber = std::stoi(k.second);
            else if (k.first == "ShieldRegen") shieldRegen = std::stoi(k.second);
            else if (k.first == "HealthRegen") healthRegen = std::stoi(k.second);
            else if (k.first == "UltimateRegen") ultimateRegen = std::stoi(k.second);
            else if (k.first == "UseTime") useTime = std::stod(k.second);
            else if (k.first == "Description") description = k.second;
        }
    }

    // Creer la regen avec les valeurs correspondantes
    Regen regen(name, type, description, level, number, stackNumber, shieldRegen, healthRegen, ultimateRegen, useTime);
    addRegen(regen); // Ajoute la regen a l'inventaire
}

// Charge les grenades du fichier de sauvegarde dans l'inventaire
void Inventory::LoadGrenade(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i) {
    std::string name, type, description;
    int number = 0;
    double ignitionTime = 0;

    for (const auto& attributes : _items[i]) {
        for (const auto& k : attributes) { // Parcourt les attibuts et attribus leurs valeurs
            if (k.first == "Name") name = k.second;
            else if (k.first == "Type") type = k.second;
            else if (k.first == "Number") number = std::stoi(k.second);
            else if (k.first == "IgnitionTime") ignitionTime = std::stod(k.second);
            else if (k.first == "Description") description = k.second;
        }
    }

    // Creer la grenade avec les valeurs correspondantes
    Grenade grenade(name, type, description, number, ignitionTime);
    addGrenade(grenade); // Ajoute la grenade a l'inventaire
}

// Afficher toutes les armes de l'inventaire
void Inventory::showInventory()
{
    system("cls");

    // Si toutes les listes sont vides renvoie un message specifique et quitte la fonction
    if (GetWeapon().empty() && GetAmmo().empty() && GetRegen().empty() && GetGrenade().empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    // Cherche les armes dans la liste et les affichent
    std::cout << "_____________________________________" << std::endl;
    std::cout << "Weapons in Inventory:\n" << std::endl;
    for (const auto& w : GetWeapon()) {
        w.displayInConsole();
    }

    // Cherche les munitions dans la liste et les affichent
    std::cout << "_____________________________________" << std::endl;
    std::cout << "Ammunitiions in Inventory:\n" << std::endl;
    for (const auto& a : GetAmmo()) {
        a.displayInConsole();
    }

    // Cherche les regen dans la liste et les affichent
    std::cout << "_____________________________________" << std::endl;
    std::cout << "Regen in Inventory:\n" << std::endl;
    for (const auto& r : GetRegen()) {
        r.displayInConsole();
    }

    // Cherche les grenades dans la liste et les affichent
    std::cout << "_____________________________________" << std::endl;
    std::cout << "Grenade in Inventory:\n" << std::endl;
    for (const auto& g : GetGrenade()) {
        g.displayInConsole();
    }
}

// Cherche et affiche dans l'inventaire ce que le joueur recherche
void Inventory::SearchInventory()
{
    system("cls");
    
    std::string input;

    int convInput;

    bool correctInput = false;

    while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
    {
        try {
            std::cout << "1 - Any \n2 - Weapon \n3 - Ammo \n4 - Regen \n5 - Grenade \n\nRechercher par : ";
            std::cin >> input;
            std::cout << "\n";
            convInput = std::stoi(input);
            if (convInput == 1 || convInput == 2 || convInput == 3 || convInput == 4 || convInput == 5)
                correctInput = true;
            else
                std::cerr << "Erreur: l'entree n'est pas valide.\n\n";
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas valide.\n";
        }
    }

    int itemFoundNbr = 0;

    std::cout << "Rechercher : ";

    std::cin >> input;

    std::cout << "\n";

    std::string lowerInput = toLower(input); // Convertie ce que le joueur a entre en lower case (minuscule)

    switch (convInput)
    {
    case 1 : // Any - Tout dans l'inventaire
        SearchWeapon(itemFoundNbr, lowerInput);
        SearchAmmo(itemFoundNbr, lowerInput);
        SearchRegen(itemFoundNbr, lowerInput);
        SearchGrenade(itemFoundNbr, lowerInput);
        break;
    case 2: // Seulement les armes dans l'inventaire
        SearchWeapon(itemFoundNbr, lowerInput);
        break;
    case 3: // Seulement les munitions dans l'inventaire
        SearchAmmo(itemFoundNbr, lowerInput);
        break;
    case 4: // Seulement les regen dans l'inventaire
        SearchRegen(itemFoundNbr, lowerInput);
        break;
    case 5: // Seulement les grenades dans l'inventaire
        SearchGrenade(itemFoundNbr, lowerInput);
        break;
    default:
        break;
    }

    if (itemFoundNbr == 0) // Renvoie un message si rien n'a ete trouve
    {
        std::cout << "\nAucun item n'a ete trouve.\n";
    }
}

// Cherche les armes dans l'inventaire et les affichent
void Inventory::SearchWeapon(int& _itemFoundNbr, std::string& _lowerInput)
{
    for (const auto& w : GetWeapon())  // Cherche le nom, le skin, le type, le type de munitions et les modes de tir
    {
        std::string lowerName = toLower(w.getName());
        std::string lowerSkin = toLower(w.getSkin());
        std::string lowerType = toLower(w.getType());
        std::string lowerAmmoType = toLower(w.getAmmo());
        std::string lowerFireModes = toLower(w.getFireModes());

        if (lowerName.find(_lowerInput) != std::string::npos || lowerType.find(_lowerInput) != std::string::npos || lowerSkin.find(_lowerInput) != std::string::npos || lowerFireModes.find(_lowerInput) != std::string::npos || lowerAmmoType.find(_lowerInput) != std::string::npos)
        {
            w.displayInConsole();
            _itemFoundNbr++;
        }
    }
}

// Cherche les munitions dans l'inventaire et les affichent
void Inventory::SearchAmmo(int& _itemFoundNbr, std::string& _lowerInput)
{
    for (const auto& a : GetAmmo()) // Cherche le type
    {
        std::string lowerType = toLower(a.GetType());
        if (lowerType.find(_lowerInput) != std::string::npos)
        {
            a.displayInConsole();
            _itemFoundNbr++;
        }
    }
}

// Cherche les regen dans l'inventaire et les affichent
void Inventory::SearchRegen(int& _itemFoundNbr, std::string& _lowerInput)
{
    for (const auto& r : GetRegen()) // Cherche le nom, le type et la description
    {
        std::string lowerName = toLower(r.GetName());
        std::string lowerType = toLower(r.GetType());
        std::string lowerDescr = toLower(r.GetDescription());
        if (lowerName.find(_lowerInput) != std::string::npos || lowerType.find(_lowerInput) != std::string::npos || lowerDescr.find(_lowerInput) != std::string::npos)
        {
            r.displayInConsole();
            _itemFoundNbr++;
        }
    }
}

// Cherche les grenades dans l'inventaire et les affichent
void Inventory::SearchGrenade(int& _itemFoundNbr, std::string& _lowerInput)
{
    for (const auto& g : GetGrenade()) // Cherche le nom, le type et la description
    {
        std::string lowerName = toLower(g.GetName());
        std::string lowerType = toLower(g.GetType());
        std::string lowerDescr = toLower(g.GetDescription());
        if (lowerName.find(_lowerInput) != std::string::npos || lowerType.find(_lowerInput) != std::string::npos || lowerDescr.find(_lowerInput) != std::string::npos)
        {
            g.displayInConsole();
            _itemFoundNbr++;
        }
    }
}

// Converti les string en lower case (minuscule)
std::string Inventory::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
};