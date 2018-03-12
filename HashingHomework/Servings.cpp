#include "Servings.h"

Servings::Servings(string amnt)
{
	amount = amnt;
}

Servings::~Servings()
{
}

string Servings::getServingSize()
{
	return amount;
}