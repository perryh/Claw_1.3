#include "Game.h"
#include "Prefixes.h"
#include "Suffixes.h"
#include "Skills.h"
#include <map>


void Log(const char* path, const char* format, ...)
{
    char text[4096];

    va_list arguments;
    va_start(arguments, format);
    vsprintf_s(text, sizeof(text), format, arguments);
    va_end(arguments);   
	
	FILE *fp;
	if (fopen_s(&fp, path, "a")==0) {
		fprintf(fp, text);
		printf(text);
		if (fp) {fclose(fp);}
	}


}

/*void SilentLog(const char* filename, const char* format, ...)
{
    char text[4096];

    va_list arguments;
    va_start(arguments, format);
    vsprintf_s(text, sizeof(text), format, arguments);
    va_end(arguments);   

	char path[MAX_PATH];
	GetCurrentDirectory(sizeof(path), path);
	strcat_s(path, "\\Plugins\\");
	strcat_s(path, filename);
	strcat_s(path, ".csv");
	//Chat("wwPkDEBUG",false,path);
	FILE *fp;
	if (fopen_s(&fp, path, "a")==0) {
		fprintf(fp, text);
		if (fp) {fclose(fp);}
	}


}*/

void PrintStats(const char* path, item& Item)
{
	Log(path, "c:%di:%d,     ", Item.cycleTmpC, Item.itemTmpC);
}

void LogItem(const char* path, item& Item)
{// category base_item prefix suffix sockets
map <int, char*> ItemType;
ItemType[0]="Helm";
ItemType[1]="Armor";
ItemType[5]="Weapon";
ItemType[6]="Weapon2";
ItemType[7]="Shield";
ItemType[10]="Special";
ItemType[16]="Misc";

int life;
if (Item.stats[7].ID==7) {life = Item.stats[7].p1;} else {life = 0;}
int strength;  // ZEIRIS: Most strange. I've only seen this work with weapons. Definitely DNW with gloves.
if (Item.stats[350].ID==350) {strength = Item.stats[350].p1;} else {strength = 0;}

	PrintStats(path, Item);
	Log(path, "%s, %s, %s, %s, %d life, %d str, %d sockets\n",
		prefixStr[Item.ItemAffix[0]], ItemType[Item.Category], suffixStr[Item.ItemAffix[1]],
				  Item.BaseItem.c_str(), life, strength, Item.Sockets);

	if (Item.stats[107].ID==107) {
		PrintStats(path, Item);
		Log(path, "   +%d to %s\n", Item.stats[107].p2, skillStr[Item.stats[107].p1]);
	} 
	if (Item.stats[107*10].ID==107*10) {
		PrintStats(path, Item);
		Log(path, "   +%d to %s\n", Item.stats[107*10].p2, skillStr[Item.stats[107*10].p1]);
	} 
	if (Item.stats[107*100].ID==107*100) {
		PrintStats(path, Item);
		Log(path, "   +%d to %s\n", Item.stats[107*100].p2, skillStr[Item.stats[107*100].p1]);
	} 

ItemType.clear();
}