#pragma once

#include <string>
#include <iostream>

class Regen
{
public:
	Regen(const std::string& _name, const std::string& _type, const std::string& _description, int _level, int _amount, int _stackSize, int _shieldRegen, int _healthRegen, int _ultimateRegen, double _useTime) : name(_name), type(_type), description(_description), level(_level), amount(_amount), stackSize(_stackSize), shieldRegen(_shieldRegen), healthRegen(_healthRegen), ultimateRegen(_ultimateRegen), useTime(_useTime) {}
	~Regen() = default;

	// Setters ------------------------------------------------------------------------------

	void SetName(std::string _name) { name = _name; }
	void SetType(std::string _type) { type = _type; }
	void SetDescription(std::string _description) { description = _description; }
	void SetLevel(int _level) { level = _level; }
	void SetAmount(int _amount) { amount = _amount; }
	void SetStackSize(int _stackSize) { stackSize = _stackSize; }
	void SetShieldRegen(int _shieldRegen) { shieldRegen = _shieldRegen; }
	void SetHealthRegen(int _healthRegen) { healthRegen = _healthRegen; }
	void SetUltimateRegen(int _ultimateRegen) { ultimateRegen = _ultimateRegen; }
	void SetUseTime(double _useTime) { useTime = _useTime; }

	// Getters ------------------------------------------------------------------------------

	const std::string& GetName() const { return name; }
	const std::string& GetType() const { return type; }
	const std::string& GetDescription() const { return description; }
	const int& GetLevel() const { return level; }
	const int& GetAmount() const { return amount; }
	const int& GetStackSize() const{ return stackSize; }
	const int& GetShieldRegen() const{ return shieldRegen; }
	const int& GetHealthRegen() const{ return healthRegen; }
	const int& GetUltimateRegen() const { return ultimateRegen; }
	const double& GetUseTime() const { return useTime; }


	const void displayInConsole() const;
	static Regen CreateFromInput();

private:
	std::string name, type, description;
	int level, amount, stackSize, shieldRegen, healthRegen, ultimateRegen;
	double useTime;
};

