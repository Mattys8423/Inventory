#include "GameManager.h"
#include "InventoryLib/Inventory.h"


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

		//Inventory.showInventory();

		std::string input = "";

		int convInput;

		bool correctInput = false;

		while (!correctInput)
		{
			try {
				std::cout << "\nQue souhaitez vous faire ?\n\n";
				std::cout << "1 - Afficher l'inventaire\n2 - Sauvegarder l'inventaire dans un fichier\n3 - Supprimer un Objet\n5 - Quitter\n\n";
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
		case 3:
			DeleteItem(Inventory);
			break;
		case 5:
			gameRunning = false;
			break;
		}		

	}
}

void GameManager::DeleteItem(Inventory& Inventory) {

	std::string nom;
	std::string input = "";

	int convInput;

	bool correctInput = false;

	while (!correctInput)
	{
		try {
			std::cout << "\nQue souhaitez vous supprimer ?\n\n";
			std::cout << "1 - Supprimer l'arme 1\n2 - Supprimer des munitions\n3 - Supprimer des grenades\n4 - Supprimer des outils de R\x82g\x82n\x82ration\n5 - Annuler\n\n";
			std::cin >> input;
			convInput = std::stoi(input);
			if (convInput < 1) {
				correctInput = false;
			}
			else if (convInput > 6) {
				correctInput = false;
			}
			else {
				correctInput = true;
			}
			// Utilisez convInput comme \x82n\x82cessaire
		}
		catch (const std::invalid_argument& e) {
			system("cls");
			std::cerr << "Erreur: l'entree n'est pas un entier valide." << std::endl;
			// Gérer l'erreur comme nécessaire
		}
		// Ignore le caractère de nouvelle ligne restant
		std::cin.ignore();
	}

	switch (convInput) {
	case 1:
		std::cout << "Donnez moi le nom de l'arme." << std::endl;
		std::getline(std::cin, nom);
		Inventory.removeWeapon(nom);
		break;
	case 2:
		std::cout << "Donnez moi le nom des munitions." << std::endl;
		std::getline(std::cin, nom);
		Inventory.removeAmmo(nom);
		break;
	case 3:
		std::cout << "Donnez moi le nom des grenades." << std::endl;
		std::getline(std::cin, nom);
		Inventory.removeGrenade(nom);
		break;
	case 4:
		std::cout << "Donnez moi le nom de l'outil de r\x82g\x82n\x82ration." << std::endl;
		std::getline(std::cin, nom);
		Inventory.removeRegen(nom);
		break;
	case 5:
		break;
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