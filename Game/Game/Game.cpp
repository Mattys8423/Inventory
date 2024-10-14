#include "ParsingLib/FileReader.h"

int main()
{
    FileReader reader("../Inventory.ini");
    std::cout << reader.readFile();
    reader.GetItems();
    return 0;
}