#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class FileReader {
public:
    FileReader(const std::string& filePath) : filePath(filePath) {}

	void SetFilePath(std::string _filePath) { filePath = _filePath; }
	std::string GetFilePath() { return filePath; }

    bool readFile();

	void AddItem(std::map<std::string, std::string> _item) { items.push_back(_item); }
	void ClearItems() { items.clear(); }
	void RemoveItem(int _index) { items.erase(items.begin() + _index); }
	std::vector<std::map<std::string, std::string>>& GetItems() { return items; }

private:
    std::string filePath;
	std::vector<std::map<std::string, std::string>> items;
};