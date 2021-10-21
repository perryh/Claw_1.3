#include "Game.h"
#include "IPacket.h"
#include "IProxy.h"
#include <windows.h>
#include <stdio.h>

void Game::buyItem(unsigned int dealerUID, unsigned int itemUID)
{
	unsigned char* buffer = new unsigned char[17];

	buffer[0] = 0x32;

	*(int*)&buffer[1] = dealerUID;
	*(int*)&buffer[5] = itemUID;
	*(int*)&buffer[9] = 0; // buffer id seems to always be this?
	*(int*)&buffer[13] = 0; // we dunno cost

	IPacket* packet = _proxy->CreatePacket(buffer, 17);
	packet->SetFlag(packet->PacketFlag_Hidden);
   	_proxy->RelayDataToServer(packet, this);
   	delete packet;
 	delete[] buffer;
}

void Game::runToObject(int targetID, unsigned char objectType)
{
	unsigned char* buffer = new unsigned char[9];

	buffer[0] = 0x04;

	buffer[1] = objectType;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;
				
	*(int*)&buffer[5] = targetID;

	IPacket* packet = _proxy->CreatePacket(buffer, 9);
	packet->SetFlag(packet->PacketFlag_Hidden);
   	_proxy->RelayDataToServer(packet, this);
   	delete packet;
 	delete[] buffer;
}
void Game::interactWithObject(int targetID, unsigned char objectType)
{
	unsigned char* buffer = new unsigned char[9];

	buffer[0] = 0x13;

	buffer[1] = objectType;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;
				
	*(int*)&buffer[5] = targetID;

	IPacket* packet = _proxy->CreatePacket(buffer, 9);
	packet->SetFlag(packet->PacketFlag_Hidden);
   	_proxy->RelayDataToServer(packet, this);
   	delete packet;
 	delete[] buffer;
}

void Game::npcFinalize(int targetID, unsigned char objectType)
{
	unsigned char* buffer = new unsigned char[9];

	buffer[0] = 0x2f;

	buffer[1] = 0x01;
	buffer[2] = 0x00;
	buffer[3] = 0x00;
	buffer[4] = 0x00;
				
	*(int*)&buffer[5] = targetID;

	IPacket* packet = _proxy->CreatePacket(buffer, 9);
	packet->SetFlag(packet->PacketFlag_Hidden);
   	_proxy->RelayDataToServer(packet, this);
   	delete packet;
 	delete[] buffer;
}

void Game::Chat(const char* name, const char* format, ...)
{
   bool whisper=false;
   char text[4096];

   va_list arguments;
   va_start(arguments, format);
   vsprintf_s(text, sizeof(text), format, arguments);
   va_end(arguments);   

   int length = static_cast<int>(strlen(text) + strlen(name)) + 12;
   unsigned char* buffer = new unsigned char[length];
   int offset = 0;

   buffer[offset++] = 0x26;
   buffer[offset++] = whisper ? 0x02 : 0x01;
   buffer[offset++] = 0x00;
   buffer[offset++] = 0x02;
   buffer[offset++] = 0x00;
   buffer[offset++] = 0x00;
   buffer[offset++] = 0x00;
   buffer[offset++] = 0x00;
   buffer[offset++] = 0x00;
   buffer[offset++] = whisper ? 0x01 : 0x05;

   for (int i = 0; name[i] != '\0'; i++)
   {
      buffer[offset++] = name[i];
   }
   buffer[offset++] = 0x00;

   for (int i = 0; text[i] != '\0'; i++)
   {
      buffer[offset++] = text[i];
   }
   buffer[offset++] = 0x00;

   IPacket* packet = _proxy->CreatePacket(buffer, length);
   packet->SetFlag(IPacket::PacketFlag_Hidden);
   _proxy->RelayDataToClient(packet, this);
   delete packet;

   delete[] buffer;
}