#include "Game.h"
#include "Logger.h"


void Game::OnRelayDataToClient(IPacket* packet, const IModule* owner)
{
	const BYTE* bytes = static_cast<const BYTE*>( packet->GetData() );
	UINT iPacket;
	iPacket = bytes[0];
	if (iPacket==0x0B) {
		myID = *reinterpret_cast<const int*>(bytes + 2); // game entered, init
	} 
	if ((iPacket == 0x9d) || (iPacket == 0x9c)) {
		ItemReader* Reader = new ItemReader();
		try {
		item Claw = Reader->Read((unsigned char *)bytes, packet->GetSize(), false);
		if (Claw.Action==AddToShop) {
			if (logShopSuccess) {printf("*");}
			unsigned int itemID = CheckItem(Claw);
			//LogItem(path, Claw); /// TEMPORARY DEBUG LOG DATA
			if (itemID!=0) { // something worth buying, maybe?
				buyItem(anyaID, itemID);
				Log(path, "C:%d, i:%d, #########BUYING#########\n", cycleC, itemC);
			}
		}					 
		} 
		catch(...)
		{
			Log(path, "Exception caught and ignored.\n");
		}
		delete Reader;

		
		
	} else if (runBot) {PortalBot(packet, owner, bytes);}
	// this will go in and out of the portal and bring up Anya's trade screen
	// generating 9d/9c packets which we look at above
	// there's a delay during which parsing/buying can be done - hopefully it's long
	// enough
}