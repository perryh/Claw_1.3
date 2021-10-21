#include "Game.h"
#include "IniReadWrite.h"
#include <stdio.h>

void Game::loadIni()
{


	// ini load
	IniReadWrite Ini("\\Claw.ini");
 
//	int int2bool = atoi(Ini.Read("log", "fpw", "0"));
	//Chat("debug",false,"%d",int2bool);
//	if (int2bool==1) {doLogWhirlFrames = true;} else {doLogWhirlFrames = false;}

  //  stompRange = atof(Ini.Read("whirl", "range", "4.5"));
	//#define stompRange 3
	//Chat("debug", false, "stomprange <%d>", stompRange);

  //  whirlAngle = atof(Ini.Read("whirl", "angle", "2.09439"));
	//#define whirlAngle 2.09439 //2pi/3
	//Chat("debug", false, "whirlAngle <%lf>", whirlAngle);

	//#define CLOSE_THEN_PORTAL_DELAY 50 
	delays.closeThenPortal = atoi(Ini.Read("delays", "closeThenPortal", "50"));
	//#define PORTAL_RETRY_DELAY 250
	delays.portalRetry = atoi(Ini.Read("delays", "portalRetry", "250"));
	//#define ANYA_TRADE_BUTTON_DELAY 300
	delays.anyaTradeButton = atoi(Ini.Read("delays", "anyaTradeButton", "300"));
	//#define TRADE_DELAY 2000	
	delays.tradeDelay = atoi(Ini.Read("delays", "tradeDelay", "2000"));
	//#define ANYA_INTERACT_DELAY 50 
	delays.anyaInteract = atoi(Ini.Read("delays", "anyaInteract", "50"));
	//#define ANYA_FINALIZE_DELAY 40
	delays.anyaFinalize = atoi(Ini.Read("delays", "anyaFinalize", "40"));
	
	int int2bool = atoi(Ini.Read("log", "shopSuccess", "0"));
	if (int2bool==1) {logShopSuccess = true;} else {logShopSuccess = false;}

}

Game::Game(IProxy* proxy,Manager* manager) :
	_proxy(proxy),
	_manager(manager)
{ 
	// Add your code
	Manager::bGameConnected = true;
	runBot = false;
	inTrade = false;
	getIDs = false;
	inTemple = false;
	cycleC = 0; itemC = 0;
	loadIni();
	GetCurrentDirectory(sizeof(path), path);
	sprintf_s(path, "%s\\Plugins\\Claw.%d.csv", path, myID); // not that unique, but it'll serve
	printf("Writing logs to %s\n", path);
}

void __stdcall Game::Destroy()
{
	// Add your code
	if (cycleC>10) {Log(path, "c:%di:%d,     GameModule unloading, probable cause: game dropped\n", cycleC, itemC);}
	else			{printf("GameModule unloading, <10 cycles passed, not saving logs.\n");}
	Manager::bGameConnected = false;
	delete this;
}

void Game::Update()
{
	// Add your code
}