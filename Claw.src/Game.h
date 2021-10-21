#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#pragma once

#include "Globals.h"

#include "IModule.h"
#include "IPacket.h"
#include "IProxy.h"

#include "Manager.h"

#include "ItemReader.h"
#include "Logger.h"


/*
#define CLOSE_THEN_PORTAL_DELAY 50 
#define PORTAL_RETRY_DELAY 250
#define ANYA_TRADE_BUTTON_DELAY 300
#define TRADE_DELAY 2000	
#define ANYA_INTERACT_DELAY 50 
#define ANYA_FINALIZE_DELAY 40 
*/
struct delayHolder {
	int closeThenPortal; // time between closing trade window and entering portal
	int portalRetry; // if this amount of time passes and we're still at temple, go back to town
	int tradeDelay; // how long the shop screen is open for
	int anyaTradeButton; // how long to wait for button for
	int anyaInteract;// delay between move and interact, or something?
	int anyaFinalize;// delay before sending finalize packet (optional?)
};

class Game :
	public IModule
{
public:
	Game(IProxy* proxy,Manager* manager);
	void __stdcall Destroy();
	void _stdcall OnRelayDataToServer(IPacket* packet, const IModule* owner);
	void _stdcall OnRelayDataToClient(IPacket* packet, const IModule* owner);
	void _stdcall Update();
	
	int CheckStrength(item& Claw);
	int CheckLife(item& Claw); 
	int CheckItem(item& Claw);
	int CheckClawSkill(item& Claw, unsigned int skillID);
	
	void loadIni();
	void PortalBot(IPacket* packet, const IModule* owner, const BYTE* bytes);
	// net command functions
	void buyItem(unsigned int dealerUID, unsigned int itemUID);
	void runToObject(int targetID, unsigned char objectType);
	void interactWithObject(int targetID, unsigned char objectType);
	void Chat(const char* name, const char* format, ...);
	void npcFinalize(int targetID, unsigned char objectType);




private:
	IProxy* _proxy;
	Manager* _manager;
	bool inTemple, runBot, getIDs, inTrade;
	unsigned int backPortal, eyeID, anyaID, myID;
	unsigned int tradeOpened, templeEntered;
	unsigned short myX, myY;
	unsigned int cycleC, itemC;
	struct delayHolder delays;
	char path[MAX_PATH];
	bool logShopSuccess;
	


};

#endif