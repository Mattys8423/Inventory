#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Regen.h"
#include "InventoryLib/Grenade.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    std::cout << reader.OpenFile();
    reader.GetItems();
    //reader.DisplayItems();

    //Regen cell(RegenName::ShieldCell, "Shield", "Restores 25 shields.", 1, 4, 4, 25, 0, 3);

	Grenade grenade(GrenadeName::FragName, GrenadeType::Thrown, GrenadeDescription::FragDescr, 1, 4);

    return 0;
}