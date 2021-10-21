#include "IModule.h"

typedef void(__stdcall *DestroyPlugin)(void* Info);
typedef IModule*(__stdcall *ModuleCreator)(IProxy* proxy, ModuleKind Kind);

//All plugins should have this string for security reasons.
extern const char PatchRegion[];
const char PatchRegion[] = "q9fvn4q2hb3456223434hs0sj3q5gfamkzc32vhsdpopdj028qhe";

struct PluginInfo {
	  const char* Name;
	  const char* Author;
	  int SDKVersion;
	  DestroyPlugin Destroy;
	  ModuleCreator Create;
	};

typedef void(__stdcall *WriteLogType)(char* Text);
typedef HWND*(__stdcall *GetWindowHandleType)();

struct RedVexInfo {
	  WriteLogType WriteLog;
	  GetWindowHandleType GetWindowHandle;
	};