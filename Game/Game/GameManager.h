#pragma once

#include <iostream>
#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"

class GameManager
{
public:

	void Gameloop();

	void WelcomeMessage(ParsingLib& _reader, bool& _welcomeMessage);
};

