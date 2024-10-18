#pragma once

#include <string>
#include <iostream>

class Grenade
{
public:
	Grenade(const std::string& _name, const std::string& _type, const std::string& _description, int _number, double _ignitionTime) : name(_name), type(_type), description(_description), number(_number), ignitionTime(_ignitionTime) {}
	~Grenade() = default;

	// Setters ------------------------------------------------------------------------------

	void SetName(std::string _name) { name = _name; }
	void SetType(std::string _type) { type = _type; }
	void SetDescription(std::string _description) { description = _description; }
	void SetNumber(int _number) { number = _number; }
	void SetIgnitionTime(double _ignitionTime) { ignitionTime = _ignitionTime; }

	// Getters ------------------------------------------------------------------------------

	const std::string& GetName() const { return name; }
	const std::string& GetType() const { return type; }
	const std::string& GetDescription() const { return description; }
	const int& GetNumber() const { return number; }
	const double& GetIgnitionTime() const { return ignitionTime; }


	const void displayInConsole() const;
	static Grenade CreateFromInput();

private:
	std::string name;
	std::string type;
	std::string description;
	int number;
	double ignitionTime;

};

