#pragma once

#include <iostream>
#include <limits>
#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"
#include <windows.h>

class GameManager
{
public:

	void Gameloop();

	void LoadFile(Inventory& _inventory, ParsingLib& _reader);
	void DeleteItem(Inventory& Inventory);
	void AddItem(Inventory& Inventory);
	void WelcomeMessage(ParsingLib& _reader, bool& _welcomeMessage);
	void SaveInFile(ParsingLib& _reader, Inventory& _inventory);

	void EasterEgg(std::string& _file);
};

