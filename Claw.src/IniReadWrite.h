/*
An Ini Reader and Write class written by buzz44 (RedVex forums > http://redvex.d2help.com/memberlist.php?mode=viewprofile&sid=81670f552433b62ec185b35713209646&u=686)
*/

#pragma once
#include <Windows.h>

class IniReadWrite
{
public:

	//Constructor...
	IniReadWrite(char* fileName); 

	//Prototypes...
	char* Read(char* section, char* key, const char* defaultValue);
	int Write(char* section, char* key, const char* format, ...);

	void ChangeFileName(char* fileName);
	char path[MAX_PATH];

private:
};