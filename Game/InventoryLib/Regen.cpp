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

// Méthode statique pour créer un objet Regen à partir de l'entrée utilisateur
Regen Regen::CreateFromInput() {
    std::string name, type, description;
    int level, amount, stackSize, shieldRegen, healthRegen, ultimateRegen;
    double useTime;

    std::cout << "Entrez le nom de l'objet de R\x82g\x82n\x82ration: ";
    std::getline(std::cin, name);

    std::cout << "Entrez le type de l'objet de R\x82g\x82n\x82ration: ";
    std::getline(std::cin, type);

    std::cout << "Entrez la description de l'objet de R\x82g\x82n\x82ration: ";
    std::getline(std::cin, description);

    std::cout << "Entrez le niveau de l'objet de R\x82g\x82n\x82ration: ";
    while (!(std::cin >> level)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrée invalide. Veuillez entrer un nombre entier pour le niveau: ";
    }

    std::cout << "Entrez la quantit\x82: ";
    while (!(std::cin >> amount)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre entier pour la quantit\x82: ";
    }

    std::cout << "Entrez la taille de la pile: ";
    while (!(std::cin >> stackSize)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre entier pour la taille de la pile: ";
    }

    std::cout << "Entrez les points de r\x82g\x82n\x82ration de bouclier: ";
    while (!(std::cin >> shieldRegen)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre entier pour la r\x82g\x82n\x82ration de bouclier: ";
    }

    std::cout << "Entrez les points de r\x82g\x82n\x82ration de sant\x82: ";
    while (!(std::cin >> healthRegen)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre entier pour la r\x82g\x82n\x82ration de sant\x82: ";
    }

    std::cout << "Entrez les points de r\x82g\x82n\x82ration ultime: ";
    while (!(std::cin >> ultimateRegen)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre entier pour la r\x82g\x82n\x82ration ultime: ";
    }

    std::cout << "Entrez le temps d'utilisation (en secondes): ";
    while (!(std::cin >> useTime)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entr\x82e invalide. Veuillez entrer un nombre r\x82el pour le temps d'utilisation: ";
    }

    // Ignore le reste de la ligne
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Regen(name, type, description, level, amount, stackSize, shieldRegen, healthRegen, ultimateRegen, useTime);
}