#include "GameManager.h"
#include "InventoryLib/Inventory.h"

// Boucle de jeu
void GameManager::Gameloop()
{
	bool gameRunning = true;
	bool welcomeMessage = true;

	ParsingLib reader("Inventory.ini");
	reader.OpenFile();
	//reader.GetItems();

	Inventory Inventory;

	Inventory.LoadFromSave(reader.GetItems());

	while (gameRunning) // Tant que gameRunning est true, le jeu tourne
	{
		if (welcomeMessage)
			WelcomeMessage(reader, welcomeMessage);

		std::string input = "";

		int convInput;

		bool correctInput = false;

		while (!correctInput) // Tant que l'input n'est pas valable, proposer au joueur de rentrer un input
		{
			try {
				std::cout << "Que souhaitez vous faire ?\n\n";
				std::cout << "1 - Afficher l'inventaire\n2 - Sauvegarder l'inventaire dans un fichier\n3 - Supprimer un Objet\n4 - Ajouter un Objet\n5 - Chercher un item\n6 - Quitter\n\n";
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
		case 1:
			Inventory.showInventory();
			break;
		case 2:
			SaveInFile(reader, Inventory);
			break;
		case 3:
			DeleteItem(Inventory);
			break;
		case 4:
			AddItem(Inventory);
		case 5:
			Inventory.SearchInventory();
			break;
		case 6:
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
			std::cout << "1 - Supprimer l'arme\n2 - Supprimer des munitions\n3 - Supprimer des grenades\n4 - Supprimer des outils de R\x82g\x82n\x82ration\n5 - Annuler\n\n";
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
			// Utilisez convInput comme n�cessaire
		}
		catch (const std::invalid_argument& e) {
			system("cls");
			std::cerr << "Erreur: l'entree n'est pas un entier valide." << std::endl;
			// G�rer l'erreur comme n�cessaire
		}
		// Ignore le caract�re de nouvelle ligne restant
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

void GameManager::AddItem(Inventory& Inventory) {

	// D�clarez les variables en dehors du switch
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
			std::cout << "\nQue souhaitez vous supprimer ?\n\n";
			std::cout << "1 - Ajouter l'arme\n2 - Ajouter des munitions\n3 - Ajouter des grenades\n4 - Ajouter des outils de R\x82g\x82n\x82ration\n5 - Annuler\n\n";
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
			// G�rer l'erreur comme n�cessaire
		}
		// Ignore le caract�re de nouvelle ligne restant
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
		std::cout << "Ajout annul\x82.\n";
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