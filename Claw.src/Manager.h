#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#pragma once

#include "Globals.h"

// extend this class to handle config data and other things
// it is ment to be used as a data pipe between ALL the servers
class Manager
{
public:
	Manager();
	~Manager();
	// Example statics you can see used in the server classes
	static bool bChatConnected;
	static bool bChatAuthed;
	static bool bGameConnected;
	static bool bRealmConnected;
	static bool bRealmAuthed;
	static HWND hD2Wnd;
private:
	void Cleanup();
protected:

};

#endif