#include "ParsingLib/ParsingLib.h"
#include "InventoryLib/Inventory.h"

int main()
{
    ParsingLib reader("Inventory.ini");
    std::cout << reader.OpenFile();
    reader.GetItems();
    //reader.DisplayItems();

    Inventory Inventory;

	Inventory.LoadFromSave(reader.GetItems());

 //   Weapon flatline("Flatline", "fortl", "AR", 10, "Auto", "Extended_Heavy_Mag", "Optics", "Standard_Stock", 2, 5, 5, 5, 5.5, 5.5, 5.5, 5.5, 5.5, false, 5);
	////flatline.displayInConsole();
	//Inventory.addWeapon(flatline);

 //   Regen cell("Shield Cell", "Shield", "Restores 25 shields.", 1, 4, 4, 25, 0, 0, 3);
 //   //cell.displayInConsole();
	//Inventory.addRegen(cell);

 //   Regen syringe("Syringe", "Health", "Restores 25 Health.", 1, 4, 4, 0, 25, 0, 5);
 //   //syringe.displayInConsole();
 //   Inventory.addRegen(syringe);

	//Grenade grenade("Frag Grenade", "Thrown", "Explosive ordnance. Throw to start fuse.", 1, 4);
	////grenade.displayInConsole();
	//Inventory.addGrenade(grenade);

	//Ammo ammo("Ammo", 240, 60);
	////ammo.displayInConsole();
	//Inventory.addAmmo(ammo);

 //   reader.CreateSave("test");

    Inventory.showInventory();

    return 0;
}