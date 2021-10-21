#include "Realm.h"

void Realm::OnRelayDataToServer(IPacket* packet, const IModule* owner)
{
	const BYTE* bytes = static_cast<const BYTE*>( packet->GetData() );
	UINT iPacket;
	iPacket = bytes[2];
	
	// Add your code
}