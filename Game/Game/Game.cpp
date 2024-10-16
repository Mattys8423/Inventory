#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Regen.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    std::cout << reader.OpenFile();
    reader.GetItems();
    //reader.DisplayItems();

    //Regen cell(RegenName::ShieldCell, "Shield", "Restores 25 shields.", 1, 4, 4, 25, 0, 3);

    return 0;
}