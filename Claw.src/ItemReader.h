#pragma once
#include "Item.h"

class ItemReader
{
	public:
		void* data;
		ItemReader();
	
		
		item Read(unsigned char* ItemPacket, int packetLength, bool weaponsOnly);
		item ReadFlags(int flags);
		

};
