#include "FileReader.h"

// Fonction verifiant si le fichier a une extension valide
bool FileReader::HasValidExtension(const std::string& extension) {
    std::string filePath = GetFilePath();
    if (filePath.size() >= extension.size() && filePath.compare(filePath.size() - extension.size(), extension.size(), extension) == 0) 
    {
        return true;
    }
    return false;
}

// Fonction ouvrant le fichier
bool FileReader::OpenFile() {

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
void FileReader::ReadFile(std::ifstream& _file)
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
void FileReader::GetHeader(std::string& _line, int& _lineNbr)
{
    if (_line.find("[") != std::string::npos)
    {
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
void FileReader::GetVariables(std::string& _line, int& _lineNbr)
{
    if (_line.empty() || _line[0] == '[')
    {
        return;
    }

	int equalIndex = 0;

    bool hasEqual = false;

	for (int i = 0; i < _line.size(); i++)
	{
		if (_line[i] == '=')
		{
			equalIndex = i;
			hasEqual = true;
			break;
		}
	}

	if (_line[equalIndex + 1] == NULL || equalIndex == 0 || !hasEqual)
	{
        MessageBoxA(NULL, ("Le fichier possede une erreur de formatage\n\nL'erreur se trouve a la ligne : " + std::to_string(_lineNbr) + "\n\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
        return;
	}

    std::map<std::string, std::string> item;
    std::string key = _line.substr(0, equalIndex);
    key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
    std::string value = _line.substr(equalIndex + 1, _line.size() - equalIndex - 1);
    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
    item[key] = value;
    AddItem(item);
}

