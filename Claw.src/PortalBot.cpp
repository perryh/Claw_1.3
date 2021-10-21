#include "Game.h"

// This is a mess. It was meant to be a test, not production... How wrong I was.

// Leave it as it is.

// Don't fuck with it unless you absolutely HAVE to.
// Oh gods it gets stuck due to random lag sometimes. I'll need to add a state machine
// that keeps track of what's up, and re-sends tp entry commands as needed. Goddamn it.

// PS selecting portal instead of anya or vice versa when prompted leads to fail

void Game::PortalBot(IPacket* packet, const IModule* owner, const BYTE* bytes)
{
// shop inventory interaction+refresh code (warning: may cause R/D)
if ((bytes[0]==0x60) && (bytes[2]==0x6D)) {
		// see red portal leading back to town, take it after a small delay
		inTemple = true;
		templeEntered = GetTickCount();
		backPortal = *reinterpret_cast<const int*>(bytes+3);

	} else if ((bytes[0]==0x60) && (bytes[2]==0x79)) {
		// we came from the temple to harrogath, talk to anya now
		inTemple = false;
		// send 0x59 packet
		unsigned char* buffer17 = new unsigned char[17];
		buffer17[0] = 0x59; 
		buffer17[1] = 0x01; buffer17[2] = 0x00;	buffer17[3] = 0x00; buffer17[4] = 0x00;
		*(int*)&buffer17[5] = anyaID;
		*(int*)&buffer17[9] = myX;
		*(int*)&buffer17[13] = myY;
		//Chat("Debug", "sending anya interact packets");
		IPacket* packet17 = _proxy->CreatePacket(buffer17, 17);
		_proxy->RelayDataToServer(packet17, this);
		delete packet17;
		delete[] buffer17;
//
		Sleep(delays.anyaInteract);

		// send run+interact packets, then a finalize packet
		runToObject(anyaID, 0x01);
		interactWithObject(anyaID, 0x01);
		Sleep(delays.anyaFinalize);
		// send 0x2f packet
		npcFinalize(anyaID, 0x01);

		//Chat("Debug", "waiting for the trade button to appear");
		Sleep(delays.anyaTradeButton);
		//Chat("Debug", "accepting trade");
		
		// send 0x38 packet (open shop inventory)
		unsigned char* buffer13 = new unsigned char[13];
		buffer13[0] = 0x38; 
		buffer13[1] = 0x01; buffer13[2] = 0x00;	buffer13[3] = 0x00; buffer13[4] = 0x00;
		*(int*)&buffer13[5] = anyaID;
		*(int*)&buffer13[9] = 0;
		
		IPacket* packet13 = _proxy->CreatePacket(buffer13, 13);
		_proxy->RelayDataToServer(packet13, this);
		delete packet13;
		delete[] buffer13;
		tradeOpened = GetTickCount();
		inTrade = true;
		if (logShopSuccess) {printf("\nitem packets received: ");}
	}	// anya shop window opening procedure done - onto other things that are run when bot is on...

	// if we've been in trade window for a while, bail out (TRADE_DELAY sets trade window time)
	if ((inTrade) && (GetTickCount()>(tradeOpened + delays.tradeDelay)) ) {
		// send 0x13 packet
		//Chat("Debug", "closing trade window");
		cycleC++;
		unsigned char* buffer = new unsigned char[9];
		buffer[0] = 0x30; 
		buffer[1] = 0x01; buffer[2] = 0x00;	buffer[3] = 0x00; buffer[4] = 0x00;
		*(int*)&buffer[5] = anyaID;
		IPacket* packet = _proxy->CreatePacket(buffer, 9);
		_proxy->RelayDataToServer(packet, this);
		delete packet; 	delete[] buffer;
		inTrade = false;
					//Chat("Debug", "delay between trade window close and tp entry");
		Sleep(delays.closeThenPortal);
		
		//Chat("Debug", "delay done, going to temple");
		runToObject(eyeID, 0x02);
		interactWithObject(eyeID, 0x02);

	} else if ((inTemple) && ((templeEntered+delays.portalRetry)<GetTickCount()) ) {
		templeEntered = GetTickCount();
		runToObject(backPortal, 0x02);
		interactWithObject(backPortal, 0x02);
		//Log(path,"Seem to be hung up on Temple side of the portal... Re-trying to enter town.\n");
	}
}
