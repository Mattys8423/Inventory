#pragma once
#include "Weapon.h"
#include "Ammo.h"
#include "Grenade.h"
#include "Regen.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>


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

	std::vector<Weapon>& GetWeapon() { return weapon; }
	std::vector<Ammo>& GetAmmo() { return ammo; }
	std::vector<Grenade>& GetGrenade() { return grenade; }
	std::vector<Regen>& GetRegen() { return regen; }
};