#ifndef CHAT_H_INCLUDED
#define CHAT_H_INCLUDED
#pragma once

#include "Globals.h"

#include "IModule.h"
#include "IPacket.h"
#include "IProxy.h"

#include "Manager.h"

class Chat :
	public IModule
{
public:
	Chat(IProxy* proxy,Manager* manager);
	void __stdcall Destroy();
	void _stdcall OnRelayDataToServer(IPacket* packet, const IModule* owner);
	void _stdcall OnRelayDataToClient(IPacket* packet, const IModule* owner);
	void _stdcall Update();

private:
	IProxy* _proxy;
	Manager* _manager;
};

#endif