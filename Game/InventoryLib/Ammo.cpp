#include "Ammo.h"

const void Ammo::displayInConsole() const {
	std::cout << "Ammo Type: " << GetType() << "\n";

	std::cout << "Amount: " << GetAmount() << "\n";
	std::cout << "Ammo per stack: " << GetStackSize() << "\n";

	int stack = GetAmount() / GetStackSize();
	int rest = GetAmount() % GetStackSize();
	std::cout << "Stack: " << stack << "\n";

	if (rest != 0) {
		std::cout << "Last Stack: " << rest << "\n";
	}
}