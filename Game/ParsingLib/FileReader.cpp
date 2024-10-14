#include "FileReader.h"

bool FileReader::readFile() {
    std::ifstream file(GetFilePath());
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier: " << GetFilePath() << "\n";
        return false;
    }

    std::string line;
	int lineNbr = 0;
    while (std::getline(file, line)) {
		for (int i = 0; i < line.size(); i++) 
        {
			if (line[i] == '[')
			{
                std::map<std::string, std::string> item;
                item["Header"] = "Header";
                item["Line"] = line;
                AddItem(item);
			}
            else if (line[i] == '=')
            {
                std::string header = line.substr(0, i);
                std::string value = line.substr(i + 1);
                std::map<std::string, std::string> item;
                item["Variable"] = header;
                item["Value"] = value;
                AddItem(item);
            }
		}
		lineNbr++;
    }

    file.close();
    return true;
}