#include "Game.h"

void Game::OnRelayDataToServer(IPacket* packet, const IModule* owner)
{
	const BYTE* bytes = static_cast<const BYTE*>( packet->GetData() );
	UINT iPacket;
	iPacket = bytes[0];

	switch(iPacket) {
		// skill switch packet
		case 0x3C: {
			if (runBot) {
				Chat("Claw", "claw stopped, do not restart in this game, restart redvex and diablo and create a new game to start again");
				runBot = false;
				getIDs = false;
				inTemple = false;
				loadIni();
			}
		} break;
		case 0x13:
			if ((*reinterpret_cast<const int*>(bytes+1)==0x01) &&
				(getIDs)) {	// anya clicked on
				anyaID = *reinterpret_cast<const int*>(bytes+5);
				Chat("Claw", "wait a few seconds, then enter the red portal");
			}
			if ((*reinterpret_cast<const int*>(bytes+1)==0x02) &&
				(getIDs)) {	// redeye clicked on
				eyeID = *reinterpret_cast<const int*>(bytes+5);	
				Chat("Claw", "claw started, select a different skill to stop");
				getIDs = false;
			}		
		break;
		case 0x03: {
				myX = *reinterpret_cast<const unsigned short*>(bytes + 1);
				myY = *reinterpret_cast<const unsigned short*>(bytes + 3);
				//Chat("debug", false, "myX, myY: <%d, %d>", myX, myY);
		} break;
		case 0x01: {
				myX = *reinterpret_cast<const unsigned short*>(bytes + 1);
				myY = *reinterpret_cast<const unsigned short*>(bytes + 3);
				//Chat("debug", false, "myX, myY: <%d, %d>", myX, myY);
		} break;
		//chat packet
		case 0x15: {
			//state = stateIDLE;
			//Chat("debug", false, "state set to Idle");
			if ((bytes[3]=='.') & (bytes[4]=='h') & (bytes[5]=='e') & (bytes[6]=='l') & (bytes[7]=='p')) {
				Chat("Claw", ".claw starts the bot");
				packet->SetFlag(packet->PacketFlag_Virtual);
			}
			if ((bytes[3]=='.') &
				(bytes[4]=='c') &
				(bytes[5]=='l') &
				(bytes[6]=='a') &
				(bytes[7]=='w')) {
				packet->SetFlag(packet->PacketFlag_Dead);
				if (runBot) {
					Chat("Claw", "claw stopped");
					runBot = false;
					getIDs = false;
					inTemple = false;
					loadIni();
				} else {
					getIDs = true;
					runBot = true;
					inTemple = false;
					Chat("Claw", "click on Anya, or another suitable NPC near the red portal");
					loadIni();
				}
			}
		} break;
	}
}