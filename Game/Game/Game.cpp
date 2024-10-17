#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    reader.OpenFile();

    Inventory Inventory;

	Inventory.LoadFromSave(reader.GetItems());

    Inventory.showInventory();

    reader.CreateSave("test");

    return 0;
}