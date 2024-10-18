#include "Grenade.h"

// Afficher les caracteristiques de la grenade
const void Grenade::displayInConsole() const {
    std::cout << "Grenade Name: " << GetName() << "\n";
    std::cout << "Type: " << GetType() << "\n";
    std::cout << "Number: " << GetNumber() << "\n";
    if (GetIgnitionTime() == 0.0) {
        std::cout << "Ignition Time: " << "Instant\n";
    }
    else {
        std::cout << "Ignition Time: " << GetIgnitionTime() << " seconds\n";
    }
    std::cout << "Description: " << GetDescription() << "\n";
    std::cout << "\n";
}

Grenade Grenade::CreateFromInput() {
    std::string name, type, description;
    int number;
    double ignitionTime;

    std::cout << "Entrez le nom de la grenade: ";
    std::getline(std::cin, name);

    std::cout << "Entrez le type de la grenade: ";
    std::getline(std::cin, type);

    std::cout << "Entrez la description de la grenade: ";
    std::getline(std::cin, description);

    std::cout << "Entrez le nombre de grenades: ";
    while (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrée invalide. Veuillez entrer un nombre entier pour le nombre: ";
    }

    std::cout << "Entrez le temps d'ignition (en secondes): ";
    while (!(std::cin >> ignitionTime)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrée invalide. Veuillez entrer un nombre réel pour le temps d'ignition: ";
    }

    // Ignore le reste de la ligne
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Grenade(name, type, description, number, ignitionTime);
}