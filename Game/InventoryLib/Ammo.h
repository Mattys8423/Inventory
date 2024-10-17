#pragma once

#include <string>
#include <iostream>

class Ammo
{
public:

	Ammo(const std::string& _type, int _amount, int _stackSize) : type(_type), amount(_amount), stackSize(_stackSize) {}
	~Ammo() = default;

	// Setters ------------------------------------------------------------------------------

	void SetType(std::string _type) { type = _type; }
	void SetAmount(int _amount) { amount = _amount; }
	void SetStackSize(int _stackSize) { stackSize = _stackSize; }

	// Getters ------------------------------------------------------------------------------

	const std::string& GetType() const { return type; }
	const int& GetAmount() const { return amount; }
	const int& GetStackSize() const { return stackSize; }

	// Fonctions ----------------------------------------------------------------------------

	// Afficher les caracteristiques de la munition
	const void displayInConsole() const;

private:
	std::string type;
	int amount, stackSize;

};

