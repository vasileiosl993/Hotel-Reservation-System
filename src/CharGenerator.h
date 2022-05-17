#ifndef CharGenerator_H
#define CharGenerator_H

#include <stdio.h>     
#include <stdlib.h>     
#include <string>
#include <iostream>
#include <algorithm>

#define  len 15

using namespace std;

string cgener(size_t length){
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

#endif