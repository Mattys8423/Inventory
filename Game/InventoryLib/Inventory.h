#include <string>
#include <map>

class Inventory {
private:
    std::map<std::string, int> items;

public:
    Inventory() = default;

    void addItem(const std::string& itemName, int quantity);
    void removeItem(const std::string& itemName, int quantity);
    void showInventory() const;
};