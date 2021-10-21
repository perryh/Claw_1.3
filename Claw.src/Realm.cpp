#include "Realm.h"

Realm::Realm(IProxy* proxy,Manager* manager) :
	_proxy(proxy),
	_manager(manager)
{ 
	// Add your code
	Manager::bRealmConnected = true;
}

void __stdcall Realm::Destroy()
{
	// Add your code
	Manager::bRealmConnected = false;
	delete this;
}

void Realm::Update()
{
	// Add your code
}