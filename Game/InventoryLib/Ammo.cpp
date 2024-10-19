#include "Ammo.h"

const void Ammo::displayInConsole() const {
	std::cout << "Ammo Type: " << GetType() << "\n";

	std::cout << "Amount: " << GetAmount() << "\n";
	std::cout << "Ammo per stack: " << GetStackSize() << "\n";

	double stack = static_cast<double>(GetAmount()) / static_cast<double>(GetStackSize());
	int rest = GetAmount() % GetStackSize();
	std::cout << "Stack: " << std::ceill(stack) << "\n";

	if (rest != 0) {
		std::cout << "Last Stack Ammo Amount: " << rest << "\n";
	}
    std::cout << "\n";
}

Ammo Ammo::CreateFromInput() {
    std::string type;
    int amount, stackSize;

    std::cout << "Entrez le type des munitions: ";
    std::getline(std::cin, type);

    std::cout << "Entrez le nombre total de munitions: ";
    std::cin >> amount;

    std::cout << "Entrez la taille d'un stack: ";
    std::cin >> stackSize;

    // Ignore any remaining newline characters in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Ammo(type, amount, stackSize);
}