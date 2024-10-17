#include "Inventory.h"
#include <iostream>


// Ajouter une arme à l'inventaire
void Inventory::addWeapon(Weapon& target){
    weapon.push_back(target);
}

// Supprimer une arme de l'inventaire par son nom
void Inventory::removeWeapon(Weapon& target) {
    auto it = std::find_if(weapon.begin(), weapon.end(),
        [&target](const Weapon& w) { return w.getName() == target.getName(); });

    if (it != weapon.end()) {
        std::cout << "Weapon " << it->getName() << " removed from inventory." << std::endl;
        weapon.erase(it);
    }
    else {
        std::cout << "Weapon " << target.getName() << " not found in inventory." << std::endl;
    }
}



// Ajouter les munitions à l'inventaire
void Inventory::addAmmo(Ammo& target) {
    ammo.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeAmmo(Ammo& target) {
    auto it = std::find_if(ammo.begin(), ammo.end(),
        [&target](const Ammo& a) { return a.GetType() == target.GetType(); });

    if (it != ammo.end()) {
        std::cout << "Ammo " << it->GetType() << " removed from inventory." << std::endl;
        ammo.erase(it);
    }
    else {
        std::cout << "Ammo " << target.GetType() << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions à l'inventaire
void Inventory::addGrenade(Grenade& target) {
    grenade.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeGrenade(Grenade& target) {
    auto it = std::find_if(grenade.begin(), grenade.end(),
        [&target](const Grenade& g) { return g.GetType() == target.GetType(); });

    if (it != grenade.end()) {
        std::cout << "Grenade " << it->GetType() << " removed from inventory." << std::endl;
        grenade.erase(it);
    }
    else {
        std::cout << "Grenade " << target.GetType() << " not found in inventory." << std::endl;
    }
}


// Ajouter les munitions à l'inventaire
void Inventory::addRegen(Regen& target) {
    regen.push_back(target);
}

// Supprimer les munitions de l'inventaire par son nom
void Inventory::removeRegen(Regen& target) {
    auto it = std::find_if(regen.begin(), regen.end(),
        [&target](const Regen& r) { return r.GetType() == target.GetType(); });

    if (it != regen.end()) {
        std::cout << "Regen " << it->GetType() << " removed from inventory." << std::endl;
        regen.erase(it);
    }
    else {
        std::cout << "Regen " << target.GetType() << " not found in inventory." << std::endl;
    }
}


void Inventory::LoadFromSave(std::vector<std::vector<std::map<std::string, std::string>>>& _items) {
    bool isWeapon = false;
	bool isAmmo = false;
	bool isRegen = false;
	bool isGrenade = false;

    for (int i = 0; i < _items.size(); i++) { // Parcours la liste des items de l'inventaire
        for (int j = 0; j < _items[i].size(); j++) { // Parcours les caractéristiques des items
            if (_items[i][j]["Header"] == "Weapon_1" || _items[i][j]["Header"] == "Weapon_2") 
            { // Si l'item est une arme
                isWeapon = true;
                break;
            }
			else if (_items[i][j]["Header"] == "Ammo") 
            { // Si l'item est une munition
				isAmmo = true;
				break;
			}
            else if (_items[i][j]["Header"] == "Regen") 
            { // Si l'item est une munition
                isRegen = true;
                break;
            }
            else if (_items[i][j]["Header"] == "Grenade") 
            { // Si l'item est une munition
                isGrenade = true;
                break;
            }
        }

        if (isWeapon) {
            std::string name, skin, type, ammoType, fireModes, attachmentMag, attachmentOptics, attachmentStandardStock, equippedAttachmentOptics;
            int equippedAttachmentMagLevel = 0, equippedAttachmentStandardStockLevel = 0, magCapacity = 0;
            double damageBody = 0, damageHead = 0, damageLegs = 0, tacticalReloadTime = 0, fullReloadTime = 0;
            bool isFullyKitted = false;
            int kittedLevel = 0;

            for (int j = 0; j < _items[i].size(); j++) {
                for (auto& k : _items[i][j]) {
                    if (k.first == "Name") name = k.second;
                    else if (k.first == "Skin") skin = k.second;
                    else if (k.first == "Type") type = k.second;
                    else if (k.first == "AmmoType") ammoType = k.second;
                    else if (k.first == "FireModes") fireModes = k.second;
                    else if (k.first == "AttachmentMag") attachmentMag = k.second;
                    else if (k.first == "AttachmentOptics") attachmentOptics = k.second;
                    else if (k.first == "AttachmentStock") attachmentStandardStock = k.second;
                    else if (k.first == "EquippedAttachmentMagLevel") equippedAttachmentMagLevel = std::stoi(k.second);
                    else if (k.first == "EquippedAttachmentOptics") equippedAttachmentOptics = k.second;
                    else if (k.first == "EquippedAttachmentStockLevel") equippedAttachmentStandardStockLevel = std::stoi(k.second);
                    else if (k.first == "MagCapacity") magCapacity = std::stoi(k.second);
                    else if (k.first == "DamageBody") damageBody = std::stod(k.second);
                    else if (k.first == "DamageHead") damageHead = std::stod(k.second);
                    else if (k.first == "DamageLegs") damageLegs = std::stod(k.second);
                    else if (k.first == "TacticalReloadTime") tacticalReloadTime = std::stod(k.second);
                    else if (k.first == "FullReloadTime") fullReloadTime = std::stod(k.second);
                    else if (k.first == "IsFullyKitted") isFullyKitted = (k.second == "true");
                    else if (k.first == "KittedLevel") kittedLevel = std::stoi(k.second);
                }
            }

            Weapon weapon(
                name, skin, type, ammoType, fireModes, attachmentMag, attachmentOptics, attachmentStandardStock,
                equippedAttachmentMagLevel, equippedAttachmentOptics, equippedAttachmentStandardStockLevel,
                magCapacity, damageBody, damageHead, damageLegs, tacticalReloadTime, fullReloadTime,
                isFullyKitted, kittedLevel
            );

            addWeapon(weapon);
            isWeapon = false;
        }

		if (isAmmo) 
        {
			std::string type;
			int totalAmmo = 0, stackSize = 0;

			for (int j = 0; j < _items[i].size(); j++) {
				for (auto& k : _items[i][j]) {
					if (k.first == "Type") type = k.second;
					else if (k.first == "Amount") totalAmmo = std::stoi(k.second);
					else if (k.first == "StackSize") stackSize = std::stoi(k.second);
				}
			}

			Ammo ammo(type, totalAmmo, stackSize);
			addAmmo(ammo);
			isAmmo = false;
		}

		if (isRegen) {
			std::string name, type, description;
			int level = 0, number = 0, stackNumber = 0, shieldRegen = 0, healthRegen = 0, ultimateRegen = 0, useTime = 0;

			for (int j = 0; j < _items[i].size(); j++) {
				for (auto& k : _items[i][j]) {
					if (k.first == "Name") name = k.second;
					else if (k.first == "Type") type = k.second;
					else if (k.first == "Level") level = std::stoi(k.second);
					else if (k.first == "Number") number = std::stoi(k.second);
					else if (k.first == "StackNumber") stackNumber = std::stoi(k.second);
					else if (k.first == "ShieldRegen") shieldRegen = std::stoi(k.second);
					else if (k.first == "HealthRegen") healthRegen = std::stoi(k.second);
                    else if (k.first == "UltimateRegen") ultimateRegen = std::stoi(k.second);
                    else if (k.first == "UseTime") useTime = std::stod(k.second);
                    else if (k.first == "Description") description = k.second;
				}
			}

            Regen regen(name, type, description, level, number, stackNumber, shieldRegen, healthRegen, ultimateRegen, useTime);
			addRegen(regen);
			isRegen = false;
		}

		if (isGrenade) {
			std::string name, type, description;
            int number = 0;
			double ignitiontime = 0;

			for (int j = 0; j < _items[i].size(); j++) {
				for (auto& k : _items[i][j]) {
                    if (k.first == "Name") name = k.second;
					else if (k.first == "Type") type = k.second;
					else if (k.first == "Number") number = std::stoi(k.second);
					else if (k.first == "IgnitionTime") ignitiontime = std::stod(k.second);
					else if (k.first == "Description") description = k.second;
				}
			}

			Grenade grenade(name, type, description, number, ignitiontime);
			addGrenade(grenade);
			isGrenade = false;
		}
    }
}














// Afficher toutes les armes de l'inventaire
void Inventory::showInventory()
{
    system("cls");

    if (weapon.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }

    std::cout << "_____________________________________" << std::endl;
    std::cout << "Weapons in Inventory:\n" << std::endl;
    for (const auto& w : weapon) {
        w.displayInConsole();
    }

    std::cout << "_____________________________________" << std::endl;
    std::cout << "Ammunitiions in Inventory:\n" << std::endl;
    for (const auto& a : ammo) {
        a.displayInConsole();
    }

    std::cout << "_____________________________________" << std::endl;
    std::cout << "Regen in Inventory:\n" << std::endl;
    for (const auto& r : regen) {
        r.displayInConsole();
    }

    std::cout << "_____________________________________" << std::endl;
    std::cout << "Grenade in Inventory:\n" << std::endl;
    for (const auto& g : grenade) {
        g.displayInConsole();
    }
}