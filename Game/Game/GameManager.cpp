#include "GameManager.h"


void GameManager::Gameloop()
{
	bool gameRunning = true;
	bool welcomeMessage = true;

	ParsingLib reader("Inventory.ini");
	reader.OpenFile();
	//reader.GetItems();

	Inventory Inventory;

	Inventory.LoadFromSave(reader.GetItems());

	while (gameRunning)
	{
		if (welcomeMessage)
			WelcomeMessage(reader, welcomeMessage);

		std::string input = "";

		int convInput;

		bool correctInput = false;

		while (!correctInput)
		{
			try {
				std::cout << "Que souhaitez vous faire ?\n\n";
				std::cout << "1 - Afficher l'inventaire\n2 - Sauvegarder l'inventaire dans un fichier\n4 - Chercher un item\n5 - Quitter\n\n";
				std::cin >> input;
				convInput = std::stoi(input);
				correctInput = true;
			}
			catch (const std::invalid_argument& e) {
				system("cls");
				std::cerr << "Erreur: l'entree n'est pas un entier valide.\n";
			}
		}

		switch (convInput)
		{
		case 1:
			Inventory.showInventory();
			break;
		case 2:
			SaveInFile(reader, Inventory);
			break;
		case 4:
			Inventory.SearchInventory();
			break;
		case 5:
			gameRunning = false;
			break;
		}		

	}
}

void GameManager::WelcomeMessage(ParsingLib& _reader, bool& _welcomeMessage)
{
	system("cls");

	std::cout << "Bienvenue dans le gestionnaire d'inventaire !\n\n";

	std::cout << "L'inventaire a ete charge a partir de " + _reader.GetFilePath() + "\n\n";
	
	_welcomeMessage = false;
}

void GameManager::SaveInFile(ParsingLib& _reader, Inventory& _inventory)
{
	std::string fileName;

	system("cls");

	std::cout << "Entrer \"quit\" ou 0 pour quitter le systeme de sauvegarde.\n";
	std::cout << "Entrer le nom du fichier : ";

	std::cin >> fileName;

	if (fileName == "Quit" || fileName == "quit" || fileName == "0")
	{
		system("cls");
		return;
	}

	_reader.CreateSave(fileName, _inventory);
}