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
void FileReader::GetHeader(const std::string& _line, int& _lineNbr)
{
    if (_line[0] == '[')
    {
        std::map<std::string, std::string> item;
        std::string result = _line;
        result.erase(std::begin(result));
        result.erase(result.size() - 1);
        item["Header"] = result;
        AddItem(item);
    }
}

// Fonction recuperant les variables et leur valeur
void FileReader::GetVariables(const std::string& _line, int& _lineNbr)
{
    if (_line[0] == '[' || _line[0] == NULL)
    {
        return;
    }

	int equalIndex = 0;

	for (int i = 0; i < _line.size(); i++)
	{
		if (_line[i] == '=')
		{
			equalIndex = i;
			break;
		}
	}

	if (_line[equalIndex + 1] == NULL || _line[equalIndex + 1] == ' ')
	{
        int testNbr = 20;
        MessageBoxA(NULL, ("Le fichier possede une erreur de formatage\nL'erreur se trouve a la ligne : " + std::to_string(_lineNbr) + "\n\"" + _line + "\"").c_str(), "Erreur", MB_ICONERROR | MB_OK);
	}

    std::map<std::string, std::string> item;
    std::string key = _line.substr(0, equalIndex);
    std::string value = _line.substr(equalIndex + 1, _line.size() - equalIndex - 1);
    item[key] = value;
    AddItem(item);
}

