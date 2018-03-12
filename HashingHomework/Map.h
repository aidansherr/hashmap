#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class valueType>
class Map
{
public:
	Map()
	{
	}
	~Map()
	{
	}

	bool insertValue(string key, valueType value)	//adds a value to the map using the specified key
	{
		hash<string> str_hash;		// hash object to hash key string for storing
		size_t hashed_key = str_hash(key);

		for (vector<size_t>::iterator it = Keys.begin(); it != Keys.end(); ++it)
		{
			// search through map, if key exists, do not insert and return false
			if (*it == hashed_key)
			{
				return false;
			}
		}

		// if key not found, ok to insert, return true
		Keys.push_back(hashed_key);
		Values.push_back(value);

		return true;
	}
	valueType * getValue(string key)					//returns the value associated with the specified key
	{
		int pos;					// to access same index in Values vector where key was found in Keys vector
		hash<string> str_hash;		// hash object to hash key string for storing
		size_t hashed_key = str_hash(key);

		for (vector<size_t>::iterator it = Keys.begin(); it != Keys.end(); ++it)
		{
			// if key found, return pointer to same index in Values vector
			if (*it == hashed_key)
			{
				pos = distance(Keys.begin(), it);		// gets index
				return & Values[pos];
			}
		}

		// if key not found, return nullptr
		return nullptr;
	}
	bool removeValue(string key)					//removes the value with the associated key
	{
		int pos;					// to ensure we remove the same index in Values vector as we did in Keys vector
		hash<string> str_hash;		// hash object to hash key string for storing
		size_t hashed_key = str_hash(key);

		for (vector<size_t>::iterator it = Keys.begin(); it != Keys.end(); ++it)
		{
			// if key found, remove index in Keys vector and Values vector and return true
			if (*it == hashed_key)
			{
				pos = distance(Keys.begin(), it);					// gets index		
				vector<valueType>::iterator it1 = Values.begin();	// iterator for Values vector
				advance(it1, pos);									// moves Values iterator to correct index
				Keys.erase(it);										// erases Keys index where key found
				Values.erase(it1);									// erases corresponding Values index
				return true;
			}
		}

		// key not found, return false
		return false;
	}
	int sizeOfMap() 								//returns number of elements stored in the map
	{
		int size = Keys.size();
		return size;
	}

private:
	vector<size_t> Keys;			// vector of hashed keys
	vector<valueType> Values;		// vector of corresponding values to keys
									// each index in Keys corresponds to the same index in Values
};

