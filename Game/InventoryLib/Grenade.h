#pragma once

#include <string>
#include <iostream>

struct GrenadeName
{
	static const std::string FragName;
	static const std::string ThermiteName;
	static const std::string ArcStarName;
};

const std::string GrenadeName::FragName = "Frag Grenade";
const std::string GrenadeName::ThermiteName = "Thermite Grenade";
const std::string GrenadeName::ArcStarName = "Arc Star";

struct GrenadeType
{
	static const std::string Thrown;
	static const std::string Homing;
};

const std::string GrenadeType::Thrown = "Thrown";
const std::string GrenadeType::Homing = "Homing";

struct GrenadeDescription
{
	static const std::string FragDescr;
	static const std::string ThermiteDescr;
	static const std::string ArcStarDescr;
};

const std::string GrenadeDescription::FragDescr = "Explosive ordnance. Throw to start fuse.";
const std::string GrenadeDescription::ThermiteDescr = "Creates a horizontal wall of flames.";
const std::string GrenadeDescription::ArcStarDescr = "Sticks, then explodes after a short delay. Causes damage and blurred vision.";

class Grenade
{
public:
	Grenade(const std::string& _name, const std::string& _type, const std::string& _description, int _number, double _ignitionTime) : name(_name), type(_type), description(_description), number(_number), ignitionTime(_ignitionTime) {}

	// Setters ------------------------------------------------------------------------------

	void SetName(std::string _name) { name = _name; }
	void SetType(std::string _type) { type = _type; }
	void SetDescription(std::string _description) { description = _description; }
	void SetNumber(int _number) { number = _number; }
	void SetUseTime(double _ignitionTime) { ignitionTime = _ignitionTime; }

	// Getters ------------------------------------------------------------------------------

	std::string& GetName() { return name; }
	std::string& GetType() { return type; }
	std::string& GetDescription() { return description; }
	int& GetNumber() { return number; }
	double& GetUseTime() { return ignitionTime; }

private:
	std::string name;
	std::string type;
	std::string description;
	int number;
	double ignitionTime;

};

