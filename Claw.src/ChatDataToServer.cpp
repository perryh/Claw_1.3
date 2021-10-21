#include "Chat.h"

void Chat::OnRelayDataToServer(IPacket* packet, const IModule* owner)
{
	const BYTE* bytes = static_cast<const BYTE*>( packet->GetData() );
	UINT iPacket;
	iPacket = bytes[1];
	
	// Add your code
}