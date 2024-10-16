#pragma once

#include <string>
#include <iostream>

struct RegenName
{
	static const std::string ShieldCell;
	static const std::string ShieldBattery;
	static const std::string Syringe;
	static const std::string MedKit;
	static const std::string PhoenixKit;
	static const std::string UltimateAccelerant;
};

const std::string RegenName::ShieldCell = "Shield Cell";
const std::string RegenName::ShieldBattery = "Shield Battery";
const std::string RegenName::Syringe = "Syringe";
const std::string RegenName::MedKit = "Med Kit";
const std::string RegenName::PhoenixKit = "Phoenix Kit";
const std::string RegenName::UltimateAccelerant = "Ultimate Accelerant";

struct RegenType
{
	static const std::string Shield;
	static const std::string Health;
	static const std::string Combo;
	static const std::string Ultimate;
};

const std::string RegenType::Shield = "Shield";
const std::string RegenType::Health = "Health";
const std::string RegenType::Combo = "Combo";
const std::string RegenType::Ultimate = "Ultimate";

class Regen
{
public:
	Regen(const std::string& _name, const std::string& _type, const std::string& _description, int _level, int _number, int _stackNumber, int _shieldRegen, int _healthRegen, int _useTime) : name(_name), type(_type), description(_description), level(_level), number(_number), stackNumber(_stackNumber), shieldRegen(_shieldRegen), healthRegen(_healthRegen), useTime(_useTime) {}

	// Setters ------------------------------------------------------------------------------

	void SetName(std::string _name) { name = _name; }
	void SetType(std::string _type) { type = _type; }
	void SetDescription(std::string _description) { description = _description; }
	void SetLevel(int _level) { level = _level; }
	void SetNumber(int _number) { number = _number; }
	void SetStackNumber(int _stackNumber) { stackNumber = _stackNumber; }
	void SetShieldRegen(int _shieldRegen) { shieldRegen = _shieldRegen; }
	void SetHealthRegen(int _healthRegen) { healthRegen = _healthRegen; }
	void SetUseTime(double _useTime) { useTime = _useTime; }

	// Getters ------------------------------------------------------------------------------

	std::string& GetName() { return name; }
	std::string& GetType() { return type; }
	std::string& GetDescription() { return description; }
	int& GetLevel() { return level; }
	int& GetNumber() { return number; }
	int& GetStackNumber() { return stackNumber; }
	int& GetShieldRegen() { return shieldRegen; }
	int& GetHealthRegen() { return healthRegen; }
	double& GetUseTime() { return useTime; }

private:
	std::string name;
	std::string type;
	std::string description;
	int level, number, stackNumber, shieldRegen, healthRegen;
	double useTime;

};

