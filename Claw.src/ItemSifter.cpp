#include "Game.h"
#include "IniReadWrite.h"
#include "ItemCodes.h"
#include "ItemNames.h"
#include "SiftPrefixes.h"
#include "SiftSuffixes.h"
#include "SiftSkills.h"
#include "LowerCase.h"
#include <string>
#include <atlstr.h>
#include <stdio.h>

//#include "Skills.h"

#define PREFIX		Claw.ItemAffix[0]
#define SUFFIX		Claw.ItemAffix[1]
#define ITEM(...)	(_stricmp(Claw.BaseItem.c_str(), __VA_ARGS__))
#define SOCKETS		Claw.Sockets
#define SKILL(...)		CheckClawSkill(Claw, __VA_ARGS__)
#define LIFE		CheckLife(Claw)
#define STR			CheckStrength(Claw)
#define MAX_STRING	4096


	IniReadWrite Ini("\\Claw.ini");
	IniReadWrite ClawItems("\\ClawItems.ini");

int Game::CheckClawSkill(item& Claw, unsigned int skillID)
{
	if ((Claw.stats[107].ID==107) && (Claw.stats[107].p1==skillID)) {
		return Claw.stats[107].p2;
//		Log(path, "+%d to skill %s found\n", Claw.stats[107].p2, skillStr[Claw.stats[107].p1]);
	} 
	if ((Claw.stats[107*10].ID==107*10) && (Claw.stats[107*10].p1==skillID)) {
		return Claw.stats[107*10].p2;
	} 
	if ((Claw.stats[107*100].ID==107*100) && (Claw.stats[107*100].p1==skillID)) {
		return Claw.stats[107*100].p2;
	} 
return 0;
}

int Game::CheckLife(item& Claw) 
{
	if (Claw.stats[7].ID==7) {return Claw.stats[7].p1;} else {return 0;}
}

int Game::CheckStrength(item& Claw) 
{
//	if (Claw.stats.find(0)!=Claw.stats.end()) {return Claw.stats[0].p1;} else {return 0;}
	if (Claw.stats[350].ID==350) {return Claw.stats[350].p1;} else {return 0;}
}

int Game::CheckItem(item& Claw) 
{
	if ((strcmp(Claw.BaseItem.c_str(), "aqv")==0) || (strcmp(Claw.BaseItem.c_str(), "cqv")==0)) { return 0; }
	int i, IniDebug;
	char szBuffer[MAX_STRING];
	char* szSection=0;
	itemC++;
	IniDebug = atoi(Ini.Read("log", "DebugNewIni", "0"));
	Claw.itemTmpC = itemC;
	Claw.cycleTmpC = cycleC;
	GetPrivateProfileString(NULL,NULL,NULL,szBuffer,MAX_STRING,ClawItems.path);
	szSection = szBuffer;
	for (i=0; i==0 || (szBuffer[i-1]!=0 || szBuffer[i]!=0) ; i++) {
		if ( szBuffer[i]==0 ) {
			char IniItemName[MAX_STRING], IniSuffix[MAX_STRING], IniSkill[MAX_STRING], IniPrefix[MAX_STRING], szSkillLvl[MAX_STRING], szSockets[MAX_STRING], szForceSockets[MAX_STRING];
			int n = 0, c = 0;
			GetPrivateProfileString(szSection,"ItemName","",IniItemName,MAX_STRING,ClawItems.path);
			while((n<496) && (strcmp(itemnameStr[n], IniItemName)!=0)) {
				n++;
			}
			while((c<496) && (strcmp(itemcodeStr[c], Claw.BaseItem.c_str())!=0)) {
				c++;
			}
			GetPrivateProfileString(szSection,"Suffix","Any",IniSuffix,MAX_STRING,ClawItems.path);
			GetPrivateProfileString(szSection,"Prefix","Any",IniPrefix,MAX_STRING,ClawItems.path);
			GetPrivateProfileString(szSection,"Skill","Any",IniSkill,MAX_STRING,ClawItems.path);
			GetPrivateProfileString(szSection,"MinSkillLevel","0",szSkillLvl,MAX_STRING,ClawItems.path);
			GetPrivateProfileString(szSection,"Sockets","0",szSockets,MAX_STRING,ClawItems.path);
			GetPrivateProfileString(szSection,"ForceSockets","0",szForceSockets,MAX_STRING,ClawItems.path);
			unsigned int IniSkillLvl = atoi(szSkillLvl);
			int IniSockets = atoi(szSockets);
			int IniForceSockets = atoi(szForceSockets);
		// Check Item Code
			if ((n == c) || (strcmp(IniItemName,"Any")==0)) {
				if ((IniDebug==1) && (strcmp(IniItemName,"Any")!=0)) Log(path,"C:%d, i:%d, ItemName Match for: '%s' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniItemName, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
		// Check Prefix
				if ((Claw.ItemAffix[0]>=0) && (Claw.ItemAffix[0]<=670)) {
					char* oo = (char*)calloc(100,sizeof(char));
					char* uu = (char*)calloc(100,sizeof(char));
					string hh;
					hh=IniPrefix;
					strcpy(uu,hh.c_str());
					char* lowerIniPrefix = toLowerCase(uu);
					string jj;
					jj=siftprefixStr[Claw.ItemAffix[0]];
					strcpy(oo,jj.c_str());
					char* lowerGamePrefix = toLowerCase(oo);
					if ((strstr(lowerGamePrefix,lowerIniPrefix)) || (strcmp(IniPrefix,"Any")==0)) {
						if ((IniDebug==1) && (strcmp(IniPrefix,"Any")!=0)) Log(path,"C:%d, i:%d, Prefix Match for: '%s' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniPrefix, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
		// Check Suffix
						if ((Claw.ItemAffix[1]>=0) && (Claw.ItemAffix[1]<=750)) {
							hh=IniSuffix;
							strcpy(uu,hh.c_str());
							char* lowerIniSuffix = toLowerCase(uu);
							jj=siftsuffixStr[Claw.ItemAffix[1]];
							strcpy(oo,jj.c_str());
							char* lowerGameSuffix = toLowerCase(oo);
							if (strstr(lowerGameSuffix,lowerIniSuffix) || (strcmp(IniSuffix,"Any")==0)) {
								if ((IniDebug==1) && (strcmp(IniSuffix,"Any")!=0)) Log(path,"C:%d, i:%d, Suffix Match for: '%s' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSuffix, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
		// Check Skill, Level And Sockets
								if((Claw.stats[107].ID==107) && (strcmp(IniSkill,"Any")!=0)) {
									hh=IniSkill;
									strcpy(uu,hh.c_str());
									char* lowerIniSkill = toLowerCase(uu);
									jj=siftskillStr[Claw.stats[107].p1];
									strcpy(oo,jj.c_str());
									char* lowerGameSkill = toLowerCase(oo);
									if (strstr(lowerGameSkill,lowerIniSkill)) {
										if ((IniDebug==1) && (strcmp(IniSkill,"Any")!=0)) Log(path,"C:%d, i:%d, Skill Match for: '%s' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkill, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
										if (Claw.stats[107].p2>=IniSkillLvl) {
											if ((IniDebug==1) && (IniSkillLvl!=0)) Log(path,"C:%d, i:%d, MinSkillLevel Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkillLvl, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
											if ((IniForceSockets==0) && (SOCKETS>=IniSockets)) {
												if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
												Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
												return Claw.Id;
											} else {
												if ((IniForceSockets==1) && (SOCKETS==IniSockets)) {
													if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
													Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
													return Claw.Id;
													}
											}
										}
									}
								}
								if((Claw.stats[107*10].ID==107*10) && (strcmp(IniSkill,"Any")!=0)) {
									hh=IniSkill;
									strcpy(uu,hh.c_str());
									char* lowerIniSkill = toLowerCase(uu);
									jj=siftskillStr[Claw.stats[107*10].p1];
									strcpy(oo,jj.c_str());
									char* lowerGameSkill = toLowerCase(oo);
									if (strstr(lowerGameSkill,lowerIniSkill)) {
										if ((IniDebug==1) && (strcmp(IniSkill,"Any")!=0)) Log(path,"C:%d, i:%d, Skill Match for: '%s' In section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkill, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
										if (Claw.stats[107*10].p2>=IniSkillLvl) {
											if ((IniDebug==1) && (IniSkillLvl!=0)) Log(path,"C:%d, i:%d, MinSkillLevel Match for: '%d' In section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkillLvl, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
											if ((IniForceSockets==0) && (SOCKETS>=IniSockets)) {
												if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
												Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
												return Claw.Id;
											} else {
												if ((IniForceSockets==0) && (SOCKETS==IniSockets)) {
													if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
													Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
													return Claw.Id;
													}
											}
										}
									}
								}
								if((Claw.stats[107*100].ID==107*100) && (strcmp(IniSkill,"Any")!=0)) {
									hh=IniSkill;
									strcpy(uu,hh.c_str());
									char* lowerIniSkill = toLowerCase(uu);
									jj=siftskillStr[Claw.stats[107*100].p1];
									strcpy(oo,jj.c_str());
									char* lowerGameSkill = toLowerCase(oo);
									if (strstr(lowerGameSkill,lowerIniSkill)) {
										if ((IniDebug==1) && (strcmp(IniSkill,"Any")!=0)) Log(path,"C:%d, i:%d, Skill Match for: '%s' In section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkill, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
										if (Claw.stats[107*100].p2>=IniSkillLvl) {
											if ((IniDebug==1) && (IniSkillLvl!=0)) Log(path,"C:%d, i:%d, MinSkillLevel Match for: '%d' In section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSkillLvl, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
											if ((IniForceSockets==0) && (SOCKETS>=IniSockets)) {
												if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
												Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
												return Claw.Id;
											} else {
												if ((IniForceSockets==1) && (SOCKETS==IniSockets)) {
													if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
													Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
													return Claw.Id;
													}
											}
										}
									}
								}
			// Skill is set to Any: Skip, Check sockets
								if (strcmp(IniSkill,"Any")==0) {
									if ((IniForceSockets==0) && (SOCKETS>=IniSockets)) {
												if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
												Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
												return Claw.Id;
											} else {
												if ((IniForceSockets==1) && (SOCKETS==IniSockets)) {
													if ((IniDebug==1) && (IniSockets!=0)) Log(path,"C:%d, i:%d, Sockets Match for: '%d' Ini section: %s\nC:%d, i:%d, Item: %s, %s, %s\n", cycleC, itemC, IniSockets, szSection, cycleC, itemC, siftprefixStr[Claw.ItemAffix[0]], itemnameStr[c], siftsuffixStr[Claw.ItemAffix[1]]);
													Log(path, "C:%d, i:%d, Complete Match found!\n", cycleC, itemC);
													return Claw.Id;
													}
											}
								}
							}
						}
					}
				}
			} else {
				c = 0;
				n = 0;
			}
			szSection = &szBuffer[i+1];
			}
		}
	return 0;
}

/*
int Game::CheckItem(item& Claw) 
{
	itemC++;
	Claw.itemTmpC = itemC;
	Claw.cycleTmpC = cycleC;
	

	 // MY PICKIT
	switch (Claw.Category) {
		case Misc:
			//		+3 jav			20 IAS		
			if ((PREFIX==441) && (SUFFIX==170)) {return Claw.Id;}
					// (have enough of these for now)
			break;
		case Helm:
			break;
		case Special:
			break;
		case Armor:
			//if (ITEM("utp") == 0)) {LogItem(path, Claw);} // archon plate
			//if (Claw.Flags.Socketed==4) {LogItem(path, Claw);}
			if (LIFE==100) {LogItem(path, Claw);}

			// 3 sockets + 80 life
			//	light plates			mage plates
			if ((ITEM("ltp")==0) || (ITEM("xtp")==0)) {
			//		Artificer's				3 socket armor			squid		80 life only
				if ((PREFIX==421) && (SOCKETS==3) && (SUFFIX==319) && (LIFE>=75) && (Ini.Read("armors", "AoS", "no")=="yes")) { return Claw.Id; }
			}

			// 4 sockets + 100 life
			//if ((SOCKETS==4) && (LIFE==100)) { return Claw.Id; }

			// 4 sockets + whale + archon plate
			if ((PREFIX==422) && (SOCKETS==4) &&//		jeweller's					4 socket
				(SUFFIX==320) && (ITEM("utp") == 0)) //		of the whale				archon plate only
			{return Claw.Id;}
			
			// 4 sockets + fhr + archon plate
			if ((PREFIX==422) && (SOCKETS==4) && //		jeweller's			4 socket
				(SUFFIX==264) && (ITEM("utp") == 0)) //		stability2				archon plate only
			{return Claw.Id;}



			// done armor
			break;
		case Weapon:
			// CURIOUS
			//if (PREFIX==489) {LogItem(path, Claw);} //echoing

			//if ((PREFIX==507) && (Claw.stats[107].ID==107)) {LogItem(path, Claw);} //cunning +3 traps
			//if ((PREFIX==510) && (Claw.stats[107].ID==107)) {LogItem(path, Claw);} //shadow +3 shadow
			// 9hw isn't Greater Talons, it's bullshit  -  Greater Talons is 9tw
			//if ((ITEM("9tw")==0)) {LogItem(path, Claw);}
			if ((PREFIX==591) && (Claw.stats[107].ID==107)) {LogItem(path, Claw);} //witch-hunter's +2 assassin (witch2)
			if (SKILL(271)>2) {LogItem(path, Claw);}// +3 lightning sentry
			//if (SKILL(278)>2) {LogItem(path, Claw);}// +3 venom
			//if (SKILL(267)>2) {LogItem(path, Claw);}// +3 fade
			//if (Claw.stats[107*100].ID==107*100) {LogItem(path, Claw);} // triple +skilled claw

			// grab
			// blue, red, green, and +15 str spears
			if (ITEM("glv")==0) { // light weapons only
				if ((PREFIX==489)) { // echoing
					//   winter			incineration		2				3
					if ((SUFFIX==179) || (SUFFIX==186) || (SUFFIX==709) || (SUFFIX==713) || 
						//	4				anthrax			2					3
						(SUFFIX==717) || (SUFFIX==237) || (SUFFIX==685) || (SUFFIX==689) || 
						// 4				thegiant5	perfect str roll
						(SUFFIX==693) || ((SUFFIX==386) && (STR==15)) ) 
						{return Claw.Id;}
				}
			}
			//if ((PREFIX==510) && (SKILL(267)==3)) {return Claw.Id;} // 6 fade prebuff
			//if ((PREFIX==510) && (SKILL(278)==3)) {return Claw.Id;} // 6 venom? prebuff
			//if (ITEM("9tw")==0) { //GREATER TALONS
				if ((PREFIX==507) && (SKILL(271)==3)) {return Claw.Id;} // 6 LS
				if ((PREFIX==591) && (SKILL(271)==3)) {return Claw.Id;} // 5 LS +2 sin witch2
			//}
			break;
		case Weapon2:
		

			break;
		case Shield:
			if (SOCKETS==4) {LogItem(path, Claw);} // jeweller's 

			// 3 socket NOT jeweller's + 30/20
			//		Artificer's				3 socket 			 deflecting
			if ((PREFIX==421) && (Claw.Sockets==3) && (SUFFIX==173) && ITEM("gts") && (Ini.Read("shields", "AoD", "no")=="yes")) {return Claw.Id;}
			//	Chat("Claw", "###3 socket 30/20 shield (non-jeweller's, LLD probably)###");
			//	return Claw.Id;
			//} 
			//DO I NEED THIS atm?
			
			// TODO: figure out the vulpine stat, then only shop 12% ones
			// vulpine			30/20			bone shields
			if ((PREFIX==199) && (SUFFIX==173) && (ITEM("bsh")==0) && (Ini.Read("shields", "VoD", "no")=="yes")) {return Claw.Id;} 

			// 4 socket + 30/20
			if ((Claw.Sockets==4) && (SUFFIX==173)) {return Claw.Id;} 

			// 4 socket + Colossus (41-60 life)
			//if ((Claw.Sockets==4) && ((SUFFIX==326)) )  {return Claw.Id;} 
			// 3 socket + Colossus (preferably only 60?)
			//if ((Claw.Sockets==4) && (SUFFIX==326) && (LIFE>55) )  {return Claw.Id;} 

			break;
	}
	// MY PICKIT

	return 0; // 0 is a-okay anything else stops the bot (will eventually be used to buy)
}
*/