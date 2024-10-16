#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>

class ParsingLib 
{
public:
    ParsingLib(const std::string& filePath) : filePath(filePath) {}

    void SetFilePath(const std::string& _filePath) { filePath = _filePath; }
    std::string GetFilePath() const { return filePath; }

    bool HasValidExtension(const std::string& extension) const;
    bool OpenFile();
    void ReadFile(std::ifstream& _file);
    void GetHeader(const std::string& _line, int _lineNbr);
    void GetVariables(const std::string& _line, int _lineNbr);

    void AddElement(const std::map<std::string, std::string>& _item) { element.push_back(_item); }
    std::vector<std::map<std::string, std::string>>& GetElements() { return element; }
    std::map<std::string, std::string>& GetElement(int _index) { return element[_index]; }
    void ClearElement() { element.clear(); }
    void RemoveElement(int _index) { element.erase(element.begin() + _index); }

    void AddItem(std::vector<std::map<std::string, std::string>> _item) { items.push_back(_item); }
    std::vector < std::vector<std::map<std::string, std::string>>>& GetItems() { return items; }
    void ClearItems() { items.clear(); }
	void DisplayItems();
    void AddItems();

private:
    std::string filePath;
    std::vector < std::vector<std::map<std::string, std::string>>> items; // Liste des items (armes, regen, etc.)
    std::vector<std::map<std::string, std::string>> element; // Liste avec toutes les caracteristiques des items (equivalent a avoir toutes les lignes du fichier)
};
