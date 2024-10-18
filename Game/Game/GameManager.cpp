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

		std::string input = "";

		int convInput;

		bool correctInput = false;

		while (!correctInput)
		{
			try {
				std::cout << "\nQue souhaitez vous faire ?\n\n";
				std::cout << "1 - Afficher l'inventaire\n2 - Sauvegarder l'inventaire dans un fichier\n5 - Quitter\n\n";
				std::cin >> input;
				convInput = std::stoi(input);
				correctInput = true;
				// Utilisez convInput comme nécessaire
			}
			catch (const std::invalid_argument& e) {
				system("cls");
				std::cerr << "Erreur: l'entree n'est pas un entier valide." << std::endl;
				// Gérer l'erreur comme nécessaire
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

	std::cout << "Entrer \"quit\" ou 0 pour quitter le système de sauvegarde.\n";
	std::cout << "Entrer le nom du fichier : ";

	std::cin >> fileName;

	if (fileName == "Quit" || fileName == "quit" || fileName == "0")
	{
		return;
	}

	_reader.CreateSave(fileName, _inventory);
}