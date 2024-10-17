#pragma once

#include <string>

struct AmmoType
{
	static const std::string SniperAmmo;
	static const std::string HeavyAmmo;
	static const std::string ShotgunShells;
	static const std::string EnergyAmmo;
	static const std::string LightAmmo;
};

const std::string AmmoType::SniperAmmo = "Sniper";
const std::string AmmoType::HeavyAmmo = "Heavy";
const std::string AmmoType::ShotgunShells = "Shotgun Shells";
const std::string AmmoType::EnergyAmmo = "Energy";
const std::string AmmoType::LightAmmo = "Light";

enum StackSize
{
	SniperAmmo = 28,
	HeavyAmmo = 60,
	ShotgunShells = 20,
	EnergyAmmo = 54,
	LightAmmo = 72,
};

class Ammo
{
public:

	Ammo(const std::string& _type, int _amount) : type(_type), amount(_amount)
	{
		if (_type == AmmoType::SniperAmmo)
			stackSize = StackSize::SniperAmmo;
		else if (_type == AmmoType::HeavyAmmo)
			stackSize = StackSize::HeavyAmmo;
		else if (_type == AmmoType::ShotgunShells)
			stackSize = StackSize::ShotgunShells;
		else if (_type == AmmoType::EnergyAmmo)
			stackSize = StackSize::EnergyAmmo;
		else if (_type == AmmoType::LightAmmo)
			stackSize = StackSize::LightAmmo;
		else
			stackSize = 0;
	}

	// Setters ------------------------------------------------------------------------------

	void SetType(std::string _type) { type = _type; }
	void SetAmount(int _amount) { amount = _amount; }
	void SetStackSize(int _stackSize) { stackSize = _stackSize; }

	// Getters ------------------------------------------------------------------------------

	std::string& GetType() { return type; }
	int& GetAmount() { return amount; }
	int& GetStackSize() { return stackSize; }

private:
	std::string type;
	int amount, stackSize;

};

