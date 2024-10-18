#include "GameManager.h"


void GameManager::Gameloop()
{
	bool gameRunning = true;
	bool welcomeMessage = true;

	while (gameRunning)
	{
		ParsingLib reader("Inventory.ini");
		reader.OpenFile();
		//reader.GetItems();

		Inventory Inventory;

		Inventory.LoadFromSave(reader.GetItems());

		if (welcomeMessage)
			WelcomeMessage(reader, welcomeMessage);

		//Inventory.showInventory();

		std::cout << "Que souhaitez vous faire ?\n\n";

		std::cout << "1 - Afficher l'inventaire\n5 - Quitter\n\n";

		int input = 0;

		std::cin >> input;

		switch (input)
		{
		case 1:
			Inventory.showInventory();
			break;
		case 5:
			gameRunning = false;
			break;
		}

		//reader.CreateSave("test", Inventory);

	}
}

void GameManager::WelcomeMessage(ParsingLib& _reader, bool& _welcomeMessage)
{
	system("cls");

	std::cout << "Bienvenue dans le gestionnaire d'inventaire !\n\n";

	std::cout << "L'inventaire a ete charge a partir de " + _reader.GetFilePath() + "\n\n";
	
	_welcomeMessage = false;
}