#include "Address.h"



Address::Address(string addr)
{
	address = addr;
}


Address::~Address()
{
}

string Address::getAddress()
{
	return address;
}
