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
    int lineNbr = 1;
    while (std::getline(_file, line)) {
        GetHeader(line, lineNbr);
        GetVariables(line, lineNbr);
		lineNbr++;
    }
}

// Fonction recuperant les headers
void ParsingLib::GetHeader(const std::string& _line, int _lineNbr)
{
    if (_line.find("[") != std::string::npos || _line.find("]") != std::string::npos)
    {
        if (_line.find("[") == std::string::npos || _line.find("]") == std::string::npos)
        {
            MessageBoxA(NULL, ("Le fichier possede une erreur de formatage a la ligne : " + std::to_string(_lineNbr) + "\n\nL'objet ne sera pas considere.\n\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
            return;
        }
        std::map<std::string, std::string> item;
        std::string result = _line;
        result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
        result.erase(std::remove(result.begin(), result.end(), '['), result.end());
        result.erase(std::remove(result.begin(), result.end(), ']'), result.end());
        item["Header"] = result;
        AddItem(item);
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
        MessageBoxA(NULL, ("Le fichier possede une erreur de formatage a la ligne : " + std::to_string(_lineNbr) + "\n\nLa variable ne sera pas considere.\n\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
        return;
    }

    std::map<std::string, std::string> item;
    std::string key = _line.substr(0, equalIndex);
    key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
    std::string value = _line.substr(equalIndex + 1);
    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
    item[key] = value;
    AddItem(item);
}

void ParsingLib::DisplayItems()
{
    system("cls");
    for (const auto& item : GetItems())
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
