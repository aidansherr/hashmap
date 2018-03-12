#include "Main.h"
#include "Map.h"
#include "Address.h"
#include "Servings.h"

void integerMap();	//creates a map of integers and performs the four major function on the map
void stringMap();	//creates a map of string and performs the four major function on the map
void addressMap();	//creates a map of address objects and performs the four major function on the map
void servingsMap();	//creates a map of serving size objects and performs the four major function on the map

Main::Main()
{
}


Main::~Main()
{
}

int main()
{
	cout << endl << "Creating map of integer values: " << endl;
	integerMap();
	cout << endl << "Creating map of string values: " << endl;
	stringMap();
	cout << endl << "Creating map of names and address values: " << endl;
	addressMap();
	cout << endl << "Creating map of serving size values: " << endl;
	servingsMap();

	cout << "\n\nPress Enter to Exit.\n";
	cin.get(); // to keep output open for review

	return 0;
}

void integerMap()
{
	string key;						// stores the string to be hashed and stored in the map
	int * value = nullptr;			// pointer to the value returned from Map's getValue() to check if a null value was returned
	Map<int> intmap;				// map of integers
	bool success = false;			// check if insert successful

	// uses for loop to create unique key/value pairs
	for (int i = 0; i <= 100; ++i)
	{
		key = "ABC" + to_string(i);			
		success = intmap.insertValue(key, i);

		// if insert failed, report to user
		if (success == false)
		{
			cout << "Insertion of key, " << key << ", failed. Key already exists" << endl;
		}
	}

	for (int i = 100; i < 102; ++i)
	{
		key = "ABC" + to_string(i);			

		cout << "Getting value mapped to key: " << key << " : " << endl;

		// search for value, if null, value not found.
		// keep track of size of map to verify removal of elements
		value = intmap.getValue(key);
		if (value != nullptr)
		{
			cout << "Size of map = " << intmap.sizeOfMap() << endl;
			cout << "The value mapped to key " << key << " is " << *value << endl;

			value = nullptr;		// done using value, set back to null to avoid referencing old data

			// try to insert key/value pair
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << i << endl;
			success = intmap.insertValue(key, i);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << intmap.sizeOfMap() << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (intmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << intmap.sizeOfMap() << endl;
		}
		else
		{
			cout << "Size of map = " << intmap.sizeOfMap() << endl;
			cout << "Key, " << key << ", does not exist in map." << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (intmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}

			cout << "Size of map = " << intmap.sizeOfMap() << endl;

			// try to insert key/value pair
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << i << endl;		
			success = intmap.insertValue(key, i);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << intmap.sizeOfMap() << endl;
		}
	}
}

void stringMap()
{
	string key;						// stores the string to be hashed and stored in the map
	string * value = nullptr;		// pointer to the value returned from Map's getValue() to check if a null value was returned
	Map<string> strmap;				// map of strings
	bool success = false;			// bool to check if insertion successful

	// uses for loop to create unique key/value pairs
	for (int i = 0; i <= 100; ++i)
	{
		key = "abc" + to_string(i);				
		success = strmap.insertValue(key, ("AZ" + to_string(i)));		 

		// if insert failed, report to user
		if (success == false)
		{
			cout << "Insertion of key, " << key << ", failed. Key already exists" << endl;
		}
	}

	for (int i = 100; i < 102; ++i)
	{
		key = "abc" + to_string(i);				

		cout << "Getting value mapped to key: " << key << " : " << endl;

		// search for value, if null, value not found.
		// keep track of size of map to verify removal of elements
		value = strmap.getValue(key);
		if (value != nullptr)
		{
			cout << "Size of map = " << strmap.sizeOfMap() << endl;
			cout << "The value mapped to key " << key << " is " << *value << endl;

			value = nullptr;		// done using value, set back to null to avoid referencing old data

			// try to insert key/value pair
			cout << "Inserting new key/value pair: Key = " << key << "  Value = AZ" << i << endl;
			success = strmap.insertValue(key, to_string(i));

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << strmap.sizeOfMap() << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (strmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << strmap.sizeOfMap() << endl;
		}
		else
		{
			cout << "Size of map = " << strmap.sizeOfMap() << endl;
			cout << "Key, " << key << ", does not exist in map." << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (strmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << strmap.sizeOfMap() << endl;

			// try to insert key/value pair
			cout << "Inserting new key/value pair: Key = " << key << "  Value = AZ" << i << endl;
			success = strmap.insertValue(key, to_string(i));

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << strmap.sizeOfMap() << endl;
		}
	}
}

void addressMap()
{
	string key;						// stores the string to be hashed and stored in the map
	Address * value = nullptr;		// pointer to the value returned from Map's getValue() to check if a null value was returned
	Map<Address> addrmap;			// map of address objects
	bool success = false;			// bool to check if insertion was successful
	
	// uses for loop to create unique key/value pairs
	for (int i = 0; i <= 100; ++i)
	{
		key = "John Smith" + to_string(i);							
		Address addr = Address(to_string(i) + " 5th Ave. Nashua, NH 03060");	// address to store in map as a value
		success = addrmap.insertValue(key, addr);

		// if insert failed, report to user
		if (success == false)
		{
			cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
		}
	}

	for (int i = 100; i < 102; ++i)
	{
		key = "John Smith" + to_string(i);							

		cout << "Getting value mapped to key: " << key << " : " << endl;

		// search for value, if null, value not found.
		// keep track of size of map to verify removal of elements
		value = addrmap.getValue(key);
		if (value != nullptr)
		{
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;			
			cout << "The address of the value mapped to key " << key << " is " 
				 << value->getAddress() << endl;

			value = nullptr;		// done using value, set back to null to avoid referencing old data

			// try to insert key/value pair
			Address addr = Address(to_string(i) + " 5th Ave. Nashua, NH 03060");	// address to store in map as a value
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << addr.getAddress() << endl;
			success = addrmap.insertValue(key, addr);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (addrmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;
		}
		else
		{
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;
			cout << "Key, " << key << ", does not exist in map." << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (addrmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;

			// try to insert key/value pair
			Address addr = Address(to_string(i) + " 5th Ave. Nashua, NH 03060");	// address to store in map as a value
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << addr.getAddress() << endl;
			success = addrmap.insertValue(key, addr);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << addrmap.sizeOfMap() << endl;
		}
	}
}

void servingsMap()
{
	string key;						// stores the string to be hashed and stored in the map
	Servings * value = nullptr;		// pointer to the value returned from Map's getValue() to check if a null value was returned
	Map<Servings> servmap;			// map of serving size objects	
	bool success = false;			// bool to check if insertion was successful

	// uses for loop to create unique key/value pairs
	for (int i = 0; i <= 100; ++i)
	{
		key = "Ingredient " + to_string(i);			
		Servings serving = Servings(to_string(i) + " grams");	// serving size to store in the map as a value
		success = servmap.insertValue(key, serving);

		// if insert failed, report to user
		if (success == false)
		{
			cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
		}
	}

	for (int i = 100; i < 102; ++i)
	{
		key = "Ingredient " + to_string(i);		

		cout << "Getting value mapped to key: " << key << " : " << endl;

		// search for value, if null, value not found.
		// keep track of size of map to verify removal of elements
		value = servmap.getValue(key);
		if (value != nullptr)
		{
			cout << "Size of map = " << servmap.sizeOfMap() << endl;
			cout << "The serving size of the value mapped to key " << key << " is " 
				 << value->getServingSize() << endl;

			value = nullptr;		// done using value, set back to null to avoid referencing old data

			// try to insert key/value pair
			Servings serving = Servings(to_string(i) + " grams");	// serving size to store in the map as a value
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << serving.getServingSize() << endl;
			success = servmap.insertValue(key, serving);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << servmap.sizeOfMap() << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (servmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << servmap.sizeOfMap() << endl;
		}
		else
		{
			cout << "Size of map = " << servmap.sizeOfMap() << endl;
			cout << "Key, " << key << ", does not exist in map." << endl;

			// remove element. if true, removal ok, check size again, else key wasn't there
			if (servmap.removeValue(key) == true)
			{
				cout << "Removed key/value pair successfully." << endl;
			}
			else
			{
				cout << "Removal of key/value pair failed. Key not found." << endl;
			}
			cout << "Size of map = " << servmap.sizeOfMap() << endl;

			// try to insert key/value pair
			Servings serving = Servings(to_string(i) + " grams");	// serving size to store in the map as a value
			cout << "Inserting new key/value pair: Key = " << key << "  Value = " << serving.getServingSize() << endl;
			success = servmap.insertValue(key, serving);

			// if insert failed, report to user, show new size of map
			if (success == false)
			{
				cout << "Insertion of key, " << key << ", failed. Key already exists." << endl;
			}
			cout << "Size of map = " << servmap.sizeOfMap() << endl;
		}
	}
}