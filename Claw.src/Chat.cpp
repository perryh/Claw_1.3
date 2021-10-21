#include "Chat.h"

Chat::Chat(IProxy* proxy,Manager* manager) :
	_proxy(proxy),
	_manager(manager)
{ 
	// Add code
	Manager::bChatConnected = true;
}

void __stdcall Chat::Destroy()
{
	// Add code
	Manager::bChatConnected = false;
	delete this;
}

void Chat::Update()
{
	// Add your code
}

// Add extra functions here