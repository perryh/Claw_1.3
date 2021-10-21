#include "Manager.h"

bool Manager::bChatConnected = false;
bool Manager::bChatAuthed = false;
bool Manager::bGameConnected = false;
bool Manager::bRealmConnected = false;
bool Manager::bRealmAuthed = false;
HWND Manager::hD2Wnd = NULL;

Manager::Manager()
{
	Cleanup();
}

Manager::~Manager()
{
	Cleanup();
}

void Manager::Cleanup()
{
	bChatConnected = false;
	bChatAuthed = false;
	bGameConnected = false;
	bRealmConnected = false;
	bRealmAuthed = false;
	hD2Wnd = NULL;
}