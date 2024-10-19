#include "GameManager.h"
#include "InventoryLib/Inventory.h"

// Boucle de jeu
void GameManager::Gameloop()
{
	bool gameRunning = true;
	bool welcomeMessage = true;

	ParsingLib reader("Inventory.ini");

	Inventory Inventory;

	LoadFile(Inventory, reader);

	while (gameRunning) // Tant que gameRunning est true, le jeu tourne
	{
		if (welcomeMessage)
			WelcomeMessage(reader, welcomeMessage);

		std::string input;

		int convInput;

		bool correctInput = false;

		while (!correctInput) // Tant que l'input n'est pas valable, proposer au joueur de rentrer un input
		{
			try {
				std::cout << "========================================================================================================================\n\n";
				std::cout << "Fichier charge : " + reader.GetFilePath();
				std::cout << "\n\nQue souhaitez vous faire ?\n\n";
				std::cout << "1 - Afficher l'inventaire\n2 - Sauvegarder l'inventaire dans un fichier\n3 - Charger l'inventaire a partir d'un fichier\n4 - Supprimer un Objet\n5 - Ajouter un Objet\n6 - Chercher un item\n0 - Quitter\n\n";
				std::cin >> input;

				if (input == "Guido" || input == "Pitstop" || input == "Mcqueen" || input == "Ketchaw") // Et oui petit easter egg
				{
					EasterEgg(input);
				}

				convInput = std::stoi(input);
				correctInput = true;
				break;
			}
			catch (const std::invalid_argument& e) { // Gestion des input invalides
				system("cls");
				std::cerr << "Erreur: l'entree n'est pas un entier valide.\n";
			}
		}

		switch (convInput) // Lance une fonction en fonction de ce que le joueur a rentre
		{
		case 0:
			gameRunning = false;
			break;
		case 1:
			Inventory.showInventory();
			break;
		case 2:
			SaveInFile(reader, Inventory);
			break;
		case 3:
			LoadFile(Inventory, reader);
			break;
		case 4:
			DeleteItem(Inventory);
			break;
		case 5:
			AddItem(Inventory);
			break;
		case 6:
			Inventory.SearchInventory();
			break;

		}		

	}
}

void GameManager::LoadFile(Inventory& _inventory, ParsingLib& _reader)
{
	system("cls");

	std::string fileName;
	bool fileLoaded = false;

	while (!fileLoaded)
	{
		try
		{
			std::cout << "1 - Charger l'inventaire par defaut\n2 - Charger un fichier specifique\n\nVous : ";

			std::string input;

			std::cin >> input;

			if (input == "1")
			{
				_reader.SetFilePath("Inventory.ini");
				_inventory.ClearInventory();

				if (_reader.OpenFile())
				{
					_inventory.LoadFromSave(_reader.GetItems());
					_reader.ClearElement();
					_reader.ClearItems();
					fileLoaded = true;
				}
				else
				{
					system("cls");
					std::cerr << "Erreur: le fichier n'a pas pu etre ouvert. Veuillez reessayer.\n\n";
				}
				break;
			}
			else if (input == "2")
			{
				system("cls");
				std::cout << "Entrer le nom du fichier a charger : ";
				std::cin >> fileName;

				_reader.SetFilePath(fileName);
				_inventory.ClearInventory();

				if (_reader.OpenFile())
				{
					_inventory.LoadFromSave(_reader.GetItems());
					_reader.ClearElement();
					_reader.ClearItems();
					fileLoaded = true;
				}
				else
				{
					system("cls");
					std::cerr << "Erreur: le fichier n'a pas pu etre ouvert. Veuillez reessayer.\n\n";
				}
			}
			else
			{
				std::cerr << "Erreur: l'entree n'est pas valide.\n";
			}


		}
		catch (const std::exception& e)
		{
			std::cerr << "Erreur: " << e.what() << "\n";
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
			std::cout << "1 - Supprimer l'arme\n2 - Supprimer des munitions\n3 - Supprimer des grenades\n4 - Supprimer des outils de Regeneration\n5 - Annuler\n\n";
			std::cin >> input;
			convInput = std::stoi(input);
			if (convInput < 1) {
				correctInput = false;
			}
			else if (convInput > 5) {
				correctInput = false;
			}
			else {
				correctInput = true;
			}
		}
		catch (const std::invalid_argument& e) {
			system("cls");
			std::cerr << "Erreur: l'entree n'est pas un entier valide." << std::endl;
		}
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
		std::cout << "Donnez moi le nom de l'outil de regeneration." << std::endl;
		std::getline(std::cin, nom);
		Inventory.removeRegen(nom);
		break;
	case 5:
		break;
	}
}

void GameManager::AddItem(Inventory& Inventory) {

	std::string nom;
	std::string input = "";
	Weapon weapon("", "", "", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0, false, 0);
	Ammo ammo("", 0, 0);
	Grenade grenade("", "", "", 0, 0.0);
	Regen regen("", "", "", 0, 0, 0, 0, 0, 0, 0.0);

	int convInput;

	bool correctInput = false;

	while (!correctInput)
	{
		try {
			std::cout << "\nQue souhaitez vous ajouter ?\n\n";
			std::cout << "1 - Ajouter l'arme\n2 - Ajouter des munitions\n3 - Ajouter des grenades\n4 - Ajouter des outils de Regeneration\n5 - Annuler\n\n";
			std::cin >> input;
			convInput = std::stoi(input);
			if (convInput < 1) {
				correctInput = false;
			}
			else if (convInput > 5) {
				correctInput = false;
			}
			else {
				correctInput = true;
			}
		}
		catch (const std::invalid_argument& e) {
			system("cls");
			std::cerr << "Erreur: l'entree n'est pas un entier valide." << std::endl;
		}
		std::cin.ignore();
	}

	switch (convInput) {
	case 1:
		weapon = Weapon::CreateFromInput();
		Inventory.addWeapon(weapon);
		break;
	case 2:
		ammo = Ammo::CreateFromInput();
		Inventory.addAmmo(ammo);
		break;
	case 3:
		grenade = Grenade::CreateFromInput();
		Inventory.addGrenade(grenade);
		break;
    case 4:
		regen = Regen::CreateFromInput();
		Inventory.addRegen(regen);
		break;
	case 5:
		std::cout << "Ajout annule.\n";
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

// Sauvegarde l'inventaire actuel dans un fichier
void GameManager::SaveInFile(ParsingLib& _reader, Inventory& _inventory)
{
	std::string fileName;

	system("cls");

	std::cout << "Entrer \"quit\" ou 0 pour quitter le systeme de sauvegarde.\n";
	std::cout << "Entrer le nom du fichier : ";

	std::cin >> fileName;

	if (fileName == "Quit" || fileName == "quit" || fileName == "0") // Permet au joueur de revenir en arriere
	{
		system("cls");
		return;
	}

	_reader.CreateSave(fileName, _inventory); // Creer la sauvegarde avec le nom de fichier que le joueur a rentre
}

// La touche mystere
void GameManager::EasterEgg(std::string& _input)
{
	const DWORD bufferSize = 1024;
	wchar_t buffer[bufferSize];

	DWORD length = GetCurrentDirectory(bufferSize, buffer);
	if (length == 0 || length > bufferSize) {
		std::wcerr << L"Erreur lors de l'obtention du r�pertoire courant." << std::endl;
	}

	std::wstring relativePath;

	if (_input == "Guido" || _input == "Pitstop")
		relativePath = L"Guido.jpg"; // Chemin relatif de l'image
	if (_input == "Mcqueen" || _input == "Ketchaw")
		relativePath = L"Mcqueen.png"; // Chemin relatif de l'image

	std::wstring imagePath = std::wstring(buffer) + L"\\" + relativePath;

	if (GetFileAttributes(imagePath.c_str()) == INVALID_FILE_ATTRIBUTES) {
		std::wcerr << L"Le fichier n'existe pas ou le chemin est incorrect: " << imagePath << std::endl;
	}

	// Utilisation de ShellExecute pour ouvrir l'image avec le programme par d�faut
	HINSTANCE result = ShellExecuteW(NULL, L"open", imagePath.c_str(), NULL, NULL, SW_SHOWNORMAL);

	// V�rifiez le r�sultat de ShellExecute
	if ((int)result <= 32) {
		std::wcerr << L"Erreur lors de l'ouverture de l'image." << std::endl;
	}
}