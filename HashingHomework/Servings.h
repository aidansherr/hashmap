#pragma once
#include <string>

using namespace std;

class Servings
{
public:
	Servings(string amnt);		// sets serving size upon object creation
	~Servings();
	string getServingSize();	// returns serving size

private:
	string amount;				// serving size stored in object
};

