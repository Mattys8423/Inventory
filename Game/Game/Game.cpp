#include "ParsingLib/FileReader.h"

int main()
{
    FileReader reader("Inventory.ini");
    std::cout << reader.OpenFile();
    //reader.GetItems();
    reader.DisplayItems();
    return 0;
}