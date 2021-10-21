#ifndef REALM_H_INCLUDED
#define REALM_H_INCLUDED
#pragma once

#include "Globals.h"

#include "IModule.h"
#include "IPacket.h"
#include "IProxy.h"

#include "Manager.h"

class Realm :
	public IModule
{
public:
	Realm(IProxy* proxy,Manager* manager);
	void __stdcall Destroy();
	void _stdcall OnRelayDataToServer(IPacket* packet, const IModule* owner);
	void _stdcall OnRelayDataToClient(IPacket* packet, const IModule* owner);
	void _stdcall Update();

private:
	IProxy* _proxy;
	Manager* _manager;
};

#endif