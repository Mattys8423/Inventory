#pragma once

#include <iostream>
#include <limits>
#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"

class GameManager
{
public:

	void Gameloop();

	void DeleteItem(Inventory& Inventory);
	void WelcomeMessage(ParsingLib& _reader, bool& _welcomeMessage);
	void SaveInFile(ParsingLib& _reader, Inventory& _inventory);
};

