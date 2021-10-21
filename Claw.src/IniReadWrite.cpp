/*
An Ini Reader and Write class written by buzz44 (RedVex forums > http://redvex.d2help.com/memberlist.php?mode=viewprofile&sid=81670f552433b62ec185b35713209646&u=686)
*/

#include "IniReadWrite.h"
#include <iostream>

IniReadWrite::IniReadWrite(char* fileName)
{
	// Set the filename...
	ChangeFileName(fileName);
}

char* IniReadWrite::Read(char* section, char* key, const char* defaultValue)
{
	// Destination string...
	char* string = new char[4096];

	GetPrivateProfileString(section,  key, defaultValue, string, 4096, path); 

	/* 
	If neither "section" nor "key" is NULL and "string" is too small to hold the requested string, 
	the string is truncated and followed by a null character, and the return value is equal to nSize (4096) minus one.

	If either "section" or "key" is NULL and "string" is too small to hold all the strings, 
	the last string is truncated and followed by two null characters. 
	In this case, the return value is equal to nSize(4096) minus two.
	*/
	return string;
}

int IniReadWrite::Write(char* section, char* key, const char* format, ...) 
{
	// Format string code...
	char value[4096];
	va_list arguments;
	va_start(arguments, format);
	vsprintf_s(value, sizeof(value), format, arguments);
	va_end(arguments);   

	// If sucessful the return value is non-zero...
	return WritePrivateProfileString(section, key, value, path);
}

void IniReadWrite::ChangeFileName(char* fileName)
{
	// Get the current working directory...
	GetCurrentDirectory(sizeof(path), path);

	// Append the new filename onto the end to get a full string...
	// eg. "C:\Folder\File.Ini"
	strcat_s(path, fileName);
}