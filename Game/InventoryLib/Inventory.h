#pragma once
#include "Weapon.h"
#include "Ammo.h"
#include "Grenade.h"
#include "Regen.h"
#include <vector>
#include <iostream>
#include <map>

class Inventory {
private:
    std::vector<Weapon> weapon;
    std::vector<Ammo> ammo;
    std::vector<Grenade> grenade;
    std::vector<Regen> regen;

public:
    Inventory() = default;

    void addWeapon(Weapon& target);
    void removeWeapon(Weapon& target);

    void addAmmo(Ammo& target);
    void removeAmmo(Ammo& target);

    void addGrenade(Grenade& target);
    void removeGrenade(Grenade& target);

    void addRegen(Regen& target);
    void removeRegen(Regen& target);

    void LoadFromSave(std::vector < std::vector<std::map<std::string, std::string>>>& _items);
    bool stringToBool(const std::string& str) { return str == "true" || str == "1"; }

    void showInventory();
};