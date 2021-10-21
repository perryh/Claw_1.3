#include <windows.h>
#include "Chat.h"
#include "Realm.h"
#include "Game.h"
#include "Manager.h"
#include "PluginTypes.h"
#include "IModule.h"

PluginInfo Info;
bool bLoaded = false;
Manager* manager;
FILE *stream;



int __stdcall DllMain(HINSTANCE instance, int reason, void* reserved)
{
	return 1;
}

void __stdcall FreePlugin(PluginInfo* Info)
{
   //Cleanup Stuff
}

IModule* __stdcall CreateModule(IProxy* proxy, ModuleKind Kind)
{
	if( bLoaded == false )
	{
		manager = new Manager();
		bLoaded = true;
	}
	switch(Kind)
	{
		case RealmModule: return new Realm(proxy,manager); break;
		case ChatModule: return new Chat(proxy,manager); break;
		case GameModule: return new Game(proxy,manager); break;
	}
 
	return 0;
}


extern "C"
{
	__declspec(dllexport) PluginInfo* __stdcall InitPlugin(RedVexInfo* Funcs)
	{ 
		AllocConsole();
		freopen_s(&stream, "conout$", "w", stdout);
		Info.Name = "Claw 1.3"; //Change this to your plugin name
		Info.Author = "Zeiris Updated by Unknownforce"; //Change this to your name
		Info.SDKVersion = 3;
		Info.Destroy = (DestroyPlugin)&FreePlugin;
		Info.Create = &CreateModule;
		return &Info;
	}
}