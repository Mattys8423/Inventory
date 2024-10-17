#include "ParsingLib.h"

// Fonction verifiant si le fichier a une extension valide
bool ParsingLib::HasValidExtension(const std::string& extension) const {
    std::string filePath = GetFilePath();
    if (filePath.size() >= extension.size() && filePath.compare(filePath.size() - extension.size(), extension.size(), extension) == 0) 
    {
        return true;
    }
    return false;
}

// Fonction ouvrant le fichier
bool ParsingLib::OpenFile() {

    if (!HasValidExtension(".ini")) {
        MessageBoxA(NULL, "Le type d'extension est invalide.\n\nVeuillez utiliser un fichier au format ini.", "Erreur", MB_ICONERROR | MB_OK);
        return false;
    }

    std::ifstream file(GetFilePath());
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier: " << GetFilePath() << "\n";
        return false;
    }

    ReadFile(file);

    file.close();
    return true;
}

// Fonction lisant le fichier
void ParsingLib::ReadFile(std::ifstream& _file)
{
    std::string line;
    int lineNbr = 0;
    while (std::getline(_file, line)) {
        GetHeader(line, lineNbr);
        GetVariables(line, lineNbr);
		lineNbr++;
    }
    AddItems();
}

// Fonction recuperant les headers
void ParsingLib::GetHeader(const std::string& _line, int _lineNbr)
{
    if (_line.find("[") != std::string::npos || _line.find("]") != std::string::npos)
    {
        if (_line.find("[") == std::string::npos || _line.find("]") == std::string::npos)
        {
            MessageBoxA(NULL, ("Le fichier possede une erreur de formatage a la ligne : " + std::to_string(_lineNbr + 1) + "\n\nL'objet ne sera pas considere.\n\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
            return;
        }

        std::map<std::string, std::string> item;
        std::string result = _line;
        result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
        result.erase(std::remove(result.begin(), result.end(), '['), result.end());
        result.erase(std::remove(result.begin(), result.end(), ']'), result.end());
        item["Header"] = result;
        AddElement(item);
    }
}

// Fonction recuperant les variables et leur valeur
void ParsingLib::GetVariables(const std::string& _line, int _lineNbr)
{
    if (_line.empty() || _line[0] == '[')
    {
        return;
    }

    size_t equalIndex = _line.find('=');

    if (equalIndex == std::string::npos || equalIndex == 0 || equalIndex == _line.size() - 1)
    {

        MessageBoxA(NULL, ("Le fichier possede une erreur de formatage a la ligne : " + std::to_string(_lineNbr + 1) + "\n\nLa variable ne sera pas considere.\n\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
        return;
    }

    std::map<std::string, std::string> item;
    std::string key = _line.substr(0, equalIndex);
    std::string value = _line.substr(equalIndex + 1);
    if (_line.find("\"") == std::string::npos)
    {
        key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
    }
    else
    {
        key.erase(std::remove(key.begin(), key.end(), '\"'), key.end());
        value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
    }
    item[key] = value;
    AddElement(item);
}

// Fonction affichant les items dans la console
void ParsingLib::DisplayItems()
{
    system("cls");
    for (const auto& item : GetElements())
    {
        for (const auto& pair : item)
        {
			if (pair.first == "Header")
			{
				std::cout << "\n-------------------------------------- " << pair.second << " --------------------------------------" << "\n\n";
			}
            std::cout << pair.first << " : " << pair.second << "\n";
        }
        std::cout << "\n";
    }
}

// Fonction ajoutant un item dans la liste des items
void ParsingLib::AddItems()
{
    std::vector<std::map<std::string, std::string>> item;
    bool doPushBack = false;
    for (int i = 0; i < GetElements().size(); i++)
    {
        for (auto& pair : GetElement(i))
        {
            if (pair.first == "Header" && i != 0)
            {
                doPushBack = true;
            }
        }
        if (doPushBack)
        {
            items.push_back(item);
            item.clear();
            doPushBack = false;
        }
        item.push_back(GetElement(i));
    }
    // Ajout du dernier element
    if (!item.empty())
    {
        items.push_back(item);
    }
}

// Fonction creant un fichier de sauvegarde
void ParsingLib::CreateSave(const std::string& _fileName)
{
    std::string nameOfFile = _fileName;

	if (nameOfFile.find(".ini") == std::string::npos)
	{
		nameOfFile.append(".ini");
	}

	std::ofstream file(nameOfFile);
	if (!file.is_open())
	{
		std::cerr << "Impossible de creer le fichier: " << GetFilePath() << "\n";
		return;
	}

	for (const auto& item : GetItems())
	{
		for (const auto& element : item)
		{
            for (const auto& pair : element)
            {
				if (pair.first == "Header")
				{
					file << "[" << pair.second << "]\n";
				}
                else if (CheckIfString(pair.first))
                {
                    file << pair.first << "=\"" << pair.second << "\"" << "\n";
                }
                else
                {
                    file << pair.first << "=" << pair.second << "\n";
                }
            }
		}
		file << "\n";
	}

	file.close();
}

bool ParsingLib::CheckIfString(const std::string& _string)
{
    if (_string == "Name" || _string == "Skin" || _string == "AttachmentMag" || _string == "AttachmentOptics" || _string == "AttachmentStock" || _string == "EquippedAttachmentOptics" || _string == "Description" || _string == "Type" || _string == "AmmoType" || _string == "FireModes")
    {
		return true;
    }
	return false;
}
