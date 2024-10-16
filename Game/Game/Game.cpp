#include "ParsingLib/ParsingLib.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    std::cout << reader.OpenFile();
    //reader.GetItems();
    reader.DisplayItems();
    return 0;
}