#pragma once
#include <string>

using namespace std;

class Address
{
public:
	Address(string addr);		// sets address upon object creation
	~Address();

	string getAddress();		// returns address

private:
	string address;				// address stored in object
};

