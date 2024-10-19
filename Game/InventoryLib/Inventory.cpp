#include "Inventory.h"
#include <iostream>


// Ajouter une arme � l'inventaire
void Inventory::addWeapon(const Weapon& target) {
    weapon.push_back(target);
}

// Supprimer une arme de l'inventaire par son nom
void Inventory::removeWeapon(const std::string& weaponName) {
    auto it = std::find_if(weapon.begin(), weapon.end(),
        [&weaponName](const Weapon& w) { return w.getName() == weaponName; });

    if (it != weapon.end()) {
        std::cout << "Weapon " << it->getName() << " removed from inventory." << std::endl;
        weapon.erase(it);
    }
    else {
        std::cout << "Weapon " << weaponName << " not found in inventory." << std::endl;
    }
}



// Ajouter les munitions � l'inventaire
void Inventory::addAmmo(const Ammo& target) {
    ammo.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeAmmo(const std::string& ammoType) {
    auto it = std::find_if(ammo.begin(), ammo.end(),
        [&ammoType](const Ammo& a) { return a.GetType() == ammoType; });

    if (it != ammo.end()) {
        std::cout << "Ammo " << it->GetType() << " removed from inventory." << std::endl;
        ammo.erase(it);
        std::cout << "Remaining ammo count: " << ammo.size() << std::endl; // Affichage du nombre restant
    }
    else {
        std::cout << "Ammo " << ammoType << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions � l'inventaire
void Inventory::addGrenade(const Grenade& target) {
    grenade.push_back(target);
}

// Supprimer les grenades de l'inventaire par son nom
void Inventory::removeGrenade(const std::string& grenadeType) {
    auto it = std::find_if(grenade.begin(), grenade.end(),
        [&grenadeType](const Grenade& g) { return g.GetName() == grenadeType; });

    if (it != grenade.end()) {
        std::cout << "Grenade " << it->GetName() << " removed from inventory." << std::endl;
        grenade.erase(it);
        std::cout << "Remaining grenade count: " << grenade.size() << std::endl; // Affichage du nombre restant
    }
    else {
        std::cout << "Grenade " << grenadeType << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions � l'inventaire
void Inventory::addRegen(const Regen& target) {
    regen.push_back(target);
}

// Supprimer les r�g�n�rations de l'inventaire par son nom
void Inventory::removeRegen(const std::string& regenName) {
    auto it = std::find_if(regen.begin(), regen.end(),
        [&regenName](const Regen& r) { return r.GetName() == regenName; });

    if (it != regen.end()) {
        std::cout << "Regen " << it->GetName() << " removed from inventory." << std::endl;
        regen.erase(it);
    }
    else {
        std::cout << "Regen " << regenName << " not found in inventory." << std::endl;
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

    std::string input;

    int convInput;

    bool correctInput = false;

    while (!correctInput) // Tant que l'input n'est pas valable, proposer au joueur de rentrer un input
    {
        try {
            std::cout << "1 - Any\n2 - Weapon \n3 - Ammo\n4 - Regen\n5 - Grenade\n6 - Quitter\n\n";
            std::cin >> input;
            convInput = std::stoi(input);
            OrderInventoryDecision(convInput);
            correctInput = true;
            break;
        }
        catch (const std::invalid_argument& e) { // Gestion des input invalides
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas un entier valide.\n";
        }
    }

	if (convInput == 6) return;

	if (convInput > 0 && convInput < 6) system("cls");

    if (convInput == 1 || convInput == 2)
    {
        // Cherche les armes dans la liste et les affichent
        std::cout << "_______________________________________________________________________________________________________________" << std::endl;
        std::cout << "Weapons in Inventory:\n" << std::endl;
        for (const auto& w : GetWeapon()) {
            w.displayInConsole();
        }
    }

    if (convInput == 1 || convInput == 3)
    {
        // Cherche les munitions dans la liste et les affichent
        std::cout << "_______________________________________________________________________________________________________________" << std::endl;
        std::cout << "Ammunitions in Inventory:\n" << std::endl;
        for (const auto& a : GetAmmo()) {
            a.displayInConsole();
        }
    }

    if (convInput == 1 || convInput == 4)
    {
        // Cherche les regen dans la liste et les affichent
        std::cout << "_______________________________________________________________________________________________________________" << std::endl;
        std::cout << "Regen in Inventory:\n" << std::endl;
        for (const auto& r : GetRegen()) {
            r.displayInConsole();
        }
    }

    if (convInput == 1 || convInput == 5)
    {
        // Cherche les grenades dans la liste et les affichent
        std::cout << "_______________________________________________________________________________________________________________" << std::endl;
        std::cout << "Grenade in Inventory:\n" << std::endl;
        for (const auto& g : GetGrenade()) {
            g.displayInConsole();
        }
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

        // Vérifie si l'entrée de l'utilisateur contient "mag"
        if (_lowerInput.find(_lowerInput) != std::string::npos ||
            lowerName.find(_lowerInput) != std::string::npos ||
            lowerType.find(_lowerInput) != std::string::npos ||
            lowerSkin.find(_lowerInput) != std::string::npos ||
            lowerFireModes.find(_lowerInput) != std::string::npos ||
            lowerAmmoType.find(_lowerInput) != std::string::npos)
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

// =========================================================================== TRI DE L'INVENTAIRE ===========================================================================

// Selectionne la fonction de tri a effectuer par rapport au parametre _value
void Inventory::OrderInventoryDecision(int& _value)
{
    switch (_value)
    {
	case 2:
		SortWeaponsMenu(_value);
		break;
	case 3:
		SortAmmosMenu(_value);
		break;
	case 4:
		SortRegenMenu(_value);
		break;
	case 5:
		SortGrenadeMenu(_value);
		break;
	default:
		break;
    }
}

// Converti l'input du joueur en un booleen pour determiner si l'ordre de tri est ascendant ou descendant
bool Inventory::SortToBool()
{
	bool correctInput = false;

	std::string input;

	int convInput;

	while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
	{
		try {
			std::cout << "Trier de maniere : 1 - Ascendante	2 - Descendante\n\nVous : ";
			std::cin >> input;
			std::cout << "\n";
			convInput = std::stoi(input);
			if (convInput == 1 || convInput == 2)
				correctInput = true;
		}
		catch (const std::invalid_argument& e) {
			system("cls");
			std::cerr << "Erreur: l'entree n'est pas valide.\n";
		}
	}

	return convInput == 1;

}

// Menu qui determine si les armes doivent etre triees et de quelle maniere 
void Inventory::SortWeaponsMenu(int& _value)
{
    bool correctInput = false;

    std::string input;

    int convInput;

    system("cls");

    while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
    {
        try {
            std::cout << "Voulez vous trier les armes ?\n\n1 - Oui	2 - Non\nVous : ";
            std::cin >> input;
            std::cout << "\n";
            convInput = std::stoi(input);
            if (convInput == 1 || convInput == 2)
                system("cls");
                correctInput = true;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas valide.\n";
        }
    }

    correctInput = false;

    bool trueAnswer = true;

    if (convInput == 1)
    {
        while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
        {
            try {
                std::cout << "Trier par les armes par :\n\n1 - Nom \n2 - Skin\n3 - Type \n4 - Type de munition \n5 - Capacite de chargeur \n"
							 "6 - Degats a la tete \n7 - Degats au corps \n8 - Degats aux jambes \n9 - Duree de rechargement tactique \n10 - Duree de rechargement complet\n\nVous : ";
                std::cin >> input;
                std::cout << "\n";
                convInput = std::stoi(input);
                bool answer = SortToBool();

                switch (convInput)
                {
				case 1:
					SortWeaponsByName(answer);
					correctInput = true;
					break;
				case 2:
					SortWeaponsBySkin(answer);
					correctInput = true;
					break;
				case 3:
					SortWeaponsByType(answer);
					correctInput = true;
					break;
				case 4:
					SortWeaponsByAmmoType(answer);
					correctInput = true;
					break;
				case 5:
					SortWeaponsByMagCapacity(answer);
					correctInput = true;
					break;
				case 6:
                    SortWeaponsByDamageHead(answer);
					correctInput = true;
					break;
				case 7:
					SortWeaponsByDamageBody(answer);
					correctInput = true;
					break;
				case 8:
					SortWeaponsByDamageLegs(answer);
					correctInput = true;
					break;
				case 9:
					SortWeaponsByTacticalReloadTime(answer);
					correctInput = true;
					break;
				case 10:
					SortWeaponsByFullReloadTime(answer);
					correctInput = true;
					break;
                default:
                    SortWeaponsByName(answer);
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
                system("cls");
                std::cerr << "Erreur: l'entree n'est pas valide.\n";
            }
        }
    }
    else SortWeaponsByName(trueAnswer);
}

// Menu qui determine si les munitions doivent etre triees et de quelle maniere 
void Inventory::SortAmmosMenu(int& _value)
{
    bool correctInput = false;

    std::string input;

    int convInput;

    system("cls");

    while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
    {
        try {
            std::cout << "Voulez vous trier les munitions ?\n\n1 - Oui	2 - Non\nVous : ";
            std::cin >> input;
            std::cout << "\n";
            convInput = std::stoi(input);
            if (convInput == 1 || convInput == 2)
                system("cls");
            correctInput = true;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas valide.\n";
        }
    }

    correctInput = false;

    bool trueAnswer = true;

    if (convInput == 1)
    {
        while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
        {
            try {
                std::cout << "Trier par les munitions par :\n\n1 - Type \n2 - Quantite \n3 - Taille de stack\n\nVous : ";
                std::cin >> input;
                std::cout << "\n";
                convInput = std::stoi(input);
                bool answer = SortToBool();

                switch (convInput)
                {
                case 1:
                    SortAmmosByType(answer);
                    correctInput = true;
                    break;
                case 2:
                    SortAmmosByAmount(answer);
                    correctInput = true;
                    break;
                case 3:
                    SortAmmosByStackSize(answer);
                    correctInput = true;
                    break;
                default:
                    SortAmmosByType(answer);
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
                system("cls");
                std::cerr << "Erreur: l'entree n'est pas valide.\n";
            }
        }
    }
    else SortAmmosByType(trueAnswer);
}

// Menu qui determine si les items regen doivent etre tries et de quelle maniere 
void Inventory::SortRegenMenu(int& _value)
{
    bool correctInput = false;

    std::string input;

    int convInput;

    system("cls");

    while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
    {
        try {
            std::cout << "Voulez vous trier les items de regen ?\n\n1 - Oui	2 - Non\nVous : ";
            std::cin >> input;
            std::cout << "\n";
            convInput = std::stoi(input);
            if (convInput == 1 || convInput == 2)
                system("cls");
            correctInput = true;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas valide.\n";
        }
    }

    correctInput = false;

    bool trueAnswer = true;

    if (convInput == 1)
    {
        while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
        {
            try {
                std::cout << "Trier par les items de regen par :\n\n1 - Nom \n2 - Type \n3 - Quantite \n4 - Taille de Stack \n5 - Regen de Shield \n6 - Regen de Vie \n7 - Regen d'ultime \n8 - Temps d'utilisation\n\nVous : ";
                std::cin >> input;
                std::cout << "\n";
                convInput = std::stoi(input);
                bool answer = SortToBool();

                switch (convInput)
                {
                case 1:
					SortRegenByName(answer);
                    correctInput = true;
                    break;
                case 2:
					SortRegenByType(answer);
                    correctInput = true;
                    break;
                case 3:
					SortRegenByAmount(answer);
                    correctInput = true;
                    break;
                case 4:
					SortRegenByStackSize(answer);
                    correctInput = true;
                    break;
                case 5:
					SortRegenByShieldRegen(answer);
                    correctInput = true;
                    break;
				case 6:
					SortRegenByHealthRegen(answer);
					correctInput = true;
					break;
				case 7:
					SortRegenByUltimateRegen(answer);
					correctInput = true;
					break;
				case 8:
					SortRegenByUseTime(answer);
					correctInput = true;
					break;
                default:
					SortRegenByName(answer);
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
                system("cls");
                std::cerr << "Erreur: l'entree n'est pas valide.\n";
            }
        }
    }
    else SortRegenByName(trueAnswer);
}

// Menu qui determine si les grenades doivent etre triees et de quelle maniere 
void Inventory::SortGrenadeMenu(int& _value)
{
    bool correctInput = false;

    std::string input;

    int convInput;

    system("cls");

    while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
    {
        try {
            std::cout << "Voulez vous trier les grenades ?\n\n1 - Oui	2 - Non\nVous : ";
            std::cin >> input;
            std::cout << "\n";
            convInput = std::stoi(input);
            if (convInput == 1 || convInput == 2)
                system("cls");
            correctInput = true;
        }
        catch (const std::invalid_argument& e) {
            system("cls");
            std::cerr << "Erreur: l'entree n'est pas valide.\n";
        }
    }

    correctInput = false;

    bool trueAnswer = true;

    if (convInput == 1)
    {
        while (!correctInput) // Boucle tant que le joueur ne rentre pas une option valable
        {
            try {
                std::cout << "Trier par les grenades par :\n\n1 - Nom \n2 - Type \n3 - Quantite \n4 - Temps d'allumage\n\nVous : ";
                std::cin >> input;
                std::cout << "\n";
                convInput = std::stoi(input);
                bool answer = SortToBool();

                switch (convInput)
                {
                case 1:
                    SortGrenadeByName(answer);
                    correctInput = true;
                    break;
                case 2:
					SortGrenadeByType(answer);
                    correctInput = true;
                    break;
                case 3:
					SortGrenadeByAmount(answer);
                    correctInput = true;
                    break;
                case 4:
					SortGrenadeByIgnitionTime(answer);
                    correctInput = true;
                    break;
                default:
					SortGrenadeByName(answer);
                    break;
                }
            }
            catch (const std::invalid_argument& e) {
                system("cls");
                std::cerr << "Erreur: l'entree n'est pas valide.\n";
            }
        }
    }
    else SortGrenadeByName(trueAnswer);
}


// ================================================================================================================================================================================
// ===============================================================             TRI PAR CARACTERISTIQUES             ===============================================================
// ================================================================================================================================================================================

// ------------------------------------------------------------------------ Tri des armes ------------------------------------------------------------------------

// Tri des armes par nom
void Inventory::SortWeaponsByName(bool& _isAsc)
{
    if (_isAsc)
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getName() < b.getName();
            });
    }
    else
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getName() > b.getName();
            });
    }
}

// Tri des armes par skin
void Inventory::SortWeaponsBySkin(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getSkin() < b.getSkin();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getSkin() > b.getSkin();
			});
	}
}

// Tri des armes par type
void Inventory::SortWeaponsByType(bool& _isAsc)
{
    if (_isAsc)
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getType() < b.getType();
            });
    }
    else
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getType() > b.getType();
            });
    }
}

// Tri des armes par type de munitions
void Inventory::SortWeaponsByAmmoType(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getAmmo() < b.getAmmo();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getAmmo() > b.getAmmo();
			});
	}
}

// Tri des armes par capacite de chargeur
void Inventory::SortWeaponsByMagCapacity(bool& _isAsc)
{
    if (_isAsc)
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getMagCapacity() < b.getMagCapacity();
            });
    }
    else
    {
        std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
            return a.getMagCapacity() > b.getMagCapacity();
            });
    }
}

// Tri des armes par degats a la tete
void Inventory::SortWeaponsByDamageHead(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageHead() < b.getDamageHead();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageHead() > b.getDamageHead();
			});
	}
}

// Tri des armes par degats au corps
void Inventory::SortWeaponsByDamageBody(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageBody() < b.getDamageBody();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageBody() > b.getDamageBody();
			});
	}
}

// Tri des armes par degats aux jambes
void Inventory::SortWeaponsByDamageLegs(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageLegs() < b.getDamageLegs();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getDamageLegs() > b.getDamageLegs();
			});
	}
}

// Tri des armes par duree de rechargement tactique
void Inventory::SortWeaponsByTacticalReloadTime(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getTacticalReloadTime() < b.getTacticalReloadTime();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getTacticalReloadTime() > b.getTacticalReloadTime();
			});
	}
}

// Tri des armes par duree de rechargement complet
void Inventory::SortWeaponsByFullReloadTime(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getFullReloadTime() < b.getFullReloadTime();
			});
	}
	else
	{
		std::sort(GetWeapon().begin(), GetWeapon().end(), [](const Weapon& a, const Weapon& b) {
			return a.getFullReloadTime() > b.getFullReloadTime();
			});
	}
}


// ------------------------------------------------------------------------ Tri des munitions ------------------------------------------------------------------------

// Tri des munitions par type
void Inventory::SortAmmosByType(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetType() < b.GetType();
			});
	}
	else
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetType() > b.GetType();
			});
	}
}

// Tri des munitions par quantite
void Inventory::SortAmmosByAmount(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetAmount() < b.GetAmount();
			});
	}
	else
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetAmount() > b.GetAmount();
			});
	}
}

// Tri des munitions par taille de stack
void Inventory::SortAmmosByStackSize(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetStackSize() < b.GetStackSize();
			});
	}
	else
	{
		std::sort(GetAmmo().begin(), GetAmmo().end(), [](const Ammo& a, const Ammo& b) {
			return a.GetStackSize() > b.GetStackSize();
			});
	}
}

// ------------------------------------------------------------------------ Tri des regen ------------------------------------------------------------------------

// Tri des regen par nom
void Inventory::SortRegenByName(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetName() < b.GetName();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetName() > b.GetName();
			});
	}
}

// Tri des regen par type
void Inventory::SortRegenByType(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetType() < b.GetType();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetType() > b.GetType();
			});
	}
}

// Tri des regen par quantite
void Inventory::SortRegenByAmount(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetAmount() < b.GetAmount();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetAmount() > b.GetAmount();
			});
	}
}

// Tri des regen par taille de stack
void Inventory::SortRegenByStackSize(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetStackSize() < b.GetStackSize();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetStackSize() > b.GetStackSize();
			});
	}
}

// Tri des regen par regen de shield
void Inventory::SortRegenByShieldRegen(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetShieldRegen() < b.GetShieldRegen();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetShieldRegen() > b.GetShieldRegen();
			});
	}
}

// Tri des regen par regen de vie
void Inventory::SortRegenByHealthRegen(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetHealthRegen() < b.GetHealthRegen();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetHealthRegen() > b.GetHealthRegen();
			});
	}
}

// Tri des regen par regen d'ultime
void Inventory::SortRegenByUltimateRegen(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetUltimateRegen() < b.GetUltimateRegen();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetUltimateRegen() > b.GetUltimateRegen();
			});
	}
}

// Tri des regen par temps d'utilisation
void Inventory::SortRegenByUseTime(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetUseTime() < b.GetUseTime();
			});
	}
	else
	{
		std::sort(GetRegen().begin(), GetRegen().end(), [](const Regen& a, const Regen& b) {
			return a.GetUseTime() > b.GetUseTime();
			});
	}
}

// ------------------------------------------------------------------------ Tri des regen ------------------------------------------------------------------------

// Tri des grenades par nom
void Inventory::SortGrenadeByName(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetName() < b.GetName();
			});
	}
	else
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetName() > b.GetName();
			});
	}
}

// Tri des grenades par type
void Inventory::SortGrenadeByType(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetType() < b.GetType();
			});
	}
	else
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetType() > b.GetType();
			});
	}
}

// Tri des grenades par quantite
void Inventory::SortGrenadeByAmount(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetNumber() < b.GetNumber();
			});
	}
	else
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetNumber() > b.GetNumber();
			});
	}
}

// Tri des grenades par temps d'allumage
void Inventory::SortGrenadeByIgnitionTime(bool& _isAsc)
{
	if (_isAsc)
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetIgnitionTime() < b.GetIgnitionTime();
			});
	}
	else
	{
		std::sort(GetGrenade().begin(), GetGrenade().end(), [](const Grenade& a, const Grenade& b) {
			return a.GetIgnitionTime() > b.GetIgnitionTime();
			});
	}
}