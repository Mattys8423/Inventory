#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>

class ParsingLib {
public:
    ParsingLib(const std::string& filePath) : filePath(filePath) {}

    void SetFilePath(const std::string& _filePath) { filePath = _filePath; }
    std::string GetFilePath() const { return filePath; }

    bool HasValidExtension(const std::string& extension) const;
    bool OpenFile();
    void ReadFile(std::ifstream& _file);
    void GetHeader(const std::string& _line, int _lineNbr);
    void GetVariables(const std::string& _line, int _lineNbr);

    void AddItem(const std::map<std::string, std::string>& _item) { items.push_back(_item); }
    void ClearItems() { items.clear(); }
    void RemoveItem(int _index) { items.erase(items.begin() + _index); }
    std::vector<std::map<std::string, std::string>>& GetItems() { return items; }
	void DisplayItems();

private:
    std::string filePath;
    std::vector<std::map<std::string, std::string>> items;
};
