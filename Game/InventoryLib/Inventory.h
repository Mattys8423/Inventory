#pragma once
#include "Weapon.h"
#include "Ammo.h"
#include "Grenade.h"
#include "Regen.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

#define REFLECT_MEMBER(member) {#member, &MyClass::member}

class Inventory {
private:
    std::vector<Weapon> weapon;
    std::vector<Ammo> ammo;
    std::vector<Grenade> grenade;
    std::vector<Regen> regen;

public:
    Inventory() = default;

    void addWeapon(const Weapon& target);
    void removeWeapon(const std::string& weaponName);

    void addAmmo(const Ammo& target);
    void removeAmmo(const std::string& ammoType);

    void addGrenade(const Grenade& target);
    void removeGrenade(const std::string& grenadeName);

    void addRegen(const Regen& target);
    void removeRegen(const std::string& regenName);

    void LoadFromSave(std::vector < std::vector<std::map<std::string, std::string>>>& _items);
    void LoadWeapon(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i);
    void LoadAmmo(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i);
    void LoadRegen(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i);
    void LoadGrenade(std::vector<std::vector<std::map<std::string, std::string>>>& _items, int& i);

    void showInventory();
    void SearchInventory();
    void SearchWeapon(int& _itemFoundNbr, std::string& _lowerInput);
    void SearchAmmo(int& _itemFoundNbr, std::string& _lowerInput);
    void SearchRegen(int& _itemFoundNbr, std::string& _lowerInput);
    void SearchGrenade(int& _itemFoundNbr, std::string& _lowerInput);
    std::string toLower(const std::string& str);

    void SortWeaponsByName(bool& _isAsc);
	void SortWeaponsBySkin(bool& _isAsc);
    void SortWeaponsByType(bool& _isAsc);
	void SortWeaponsByAmmoType(bool& _isAsc);
    void SortWeaponsByMagCapacity(bool& _isAsc);
	void SortWeaponsByDamageBody(bool& _isAsc);
	void SortWeaponsByDamageHead(bool& _isAsc);
	void SortWeaponsByDamageLegs(bool& _isAsc);
	void SortWeaponsByTacticalReloadTime(bool& _isAsc);
	void SortWeaponsByFullReloadTime(bool& _isAsc);
    void SortAmmosByType(bool& _isAsc);
	void SortAmmosByAmount(bool& _isAsc);
	void SortAmmosByStackSize(bool& _isAsc);
	void SortRegenByName(bool& _isAsc);
	void SortRegenByType(bool& _isAsc);
	void SortRegenByAmount(bool& _isAsc);
	void SortRegenByStackSize(bool& _isAsc);
    void SortRegenByShieldRegen(bool& _isAsc);
	void SortRegenByHealthRegen(bool& _isAsc);
	void SortRegenByUltimateRegen(bool& _isAsc);
	void SortRegenByUseTime(bool& _isAsc);
	void SortGrenadeByName(bool& _isAsc);
	void SortGrenadeByType(bool& _isAsc);
	void SortGrenadeByAmount(bool& _isAsc);
	void SortGrenadeByIgnitionTime(bool& _isAsc);

    void OrderInventoryDecision(int& _value);

    bool SortToBool();
    void SortWeaponsMenu(int& _value);
    void SortAmmosMenu(int& _value);
    void SortRegenMenu(int& _value);
    void SortGrenadeMenu(int& _value);

	std::vector<Weapon>& GetWeapon() { return weapon; }
	std::vector<Ammo>& GetAmmo() { return ammo; }
	std::vector<Grenade>& GetGrenade() { return grenade; }
	std::vector<Regen>& GetRegen() { return regen; }
};