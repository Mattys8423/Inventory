#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    reader.OpenFile();
    reader.GetItems();

    Inventory Inventory;

	Inventory.LoadFromSave(reader.GetItems());

    Inventory.showInventory();

    reader.CreateSave("test", Inventory);

    return 0;
}