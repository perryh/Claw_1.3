// itemreader.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "BitField.h"
#include <conio.h>
#include "ItemReader.h"
#include "BitField.h"
#include <string>
#include <iostream>
#include "Logger.h"


ItemReader::ItemReader()
{
}

item ItemReader::Read(unsigned char* ItemPacket, int packetLength, bool weaponsOnly)
{
	data = reinterpret_cast<void*>(ItemPacket);

	BitField field(data, sizeof(data));

	int currentPos = 0;
	int i = 0;
	
	const int sizes[] =
	{
		8, 8, 8, 8, 32, 8, 32, 32, 8, 2, 3, 16, 16, 4,
		4, 3, 4, 3, 7, 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7, 8,8,8,8, 1, 32, 12, 3, 7, 4, 1,3, 1,11, 
	};

	item thisItem;

	int action = field.ReadBits(currentPos, sizes[i]);
		switch (action)
		{
		printf("%u\n", action );
		case OwnedItem:
			{
				thisItem.PacketType = OwnedItem;
				break;
			}

		case WorldItem:
			{
				thisItem.PacketType = WorldItem;
				break;
			}
		}


		currentPos += sizes[i];
		i++;
		int ThisAction = field.ReadBits(currentPos, sizes[i]);

///////////////////////////////////////////////////////////////
////cheap hack by alex to make redvex not crash////////////////
/////////parser will ignore non-shop items/////////////////////
///////////////////////////////////////////////////////////////
//////////this is okay because this is a shopbot right?////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

		if (ThisAction!=AddToShop) {return thisItem;}

		switch (ThisAction)
		{
		case AddToGround:
			{
				thisItem.Action = AddToGround;
				break;
			}
		case GroundToCursor:
			{
				thisItem.Action = GroundToCursor;
				break;
			}
		case DropToGround:
			{
				thisItem.Action = DropToGround;
				break;
			}
		case OnGround:
			{
				thisItem.Action = OnGround;
				break;
			}
		case PutInContainer:
			{
				thisItem.Action = PutInContainer;
				break;
			}
		case RemoveFromContainer:
			{
				thisItem.Action = RemoveFromContainer;
				break;
			}
		case Equip:
			{
				thisItem.Action = Equip;
				break;
			}
		case IndirectlySwapBodyItem:
			{
				thisItem.Action = IndirectlySwapBodyItem;
				break;
			}
		case Unequip:
			{
				thisItem.Action = Unequip;
				break;
			}
		case SwapBodyItem:
			{
				thisItem.Action = SwapBodyItem;
				break;
			}
		case AddQuantity:
			{
				thisItem.Action = AddQuantity;
				break;
			}
		case AddToShop:
			{
				thisItem.Action = AddToShop;
				break;
			}

		case RemoveFromShop:
			{
				thisItem.Action = RemoveFromShop;
				break;
			}
		case SwapInContainer:
			{
				thisItem.Action = SwapInContainer;
				break;
			}
		case PutInBelt:
			{
				thisItem.Action = PutInBelt;
				break;
			}
		case RemoveFromBelt:
			{
				thisItem.Action = RemoveFromBelt;
				break;
			}
		case SwapInBelt:
			{
				thisItem.Action = SwapInBelt;
				break;
			}
		case AutoUnequip:
			{
				thisItem.Action = AutoUnequip;
				break;
			}
		case RemoveFromHireling:
			{
				thisItem.Action = RemoveFromHireling;
				break;
			}
		case ItemInSocket:
			{
				thisItem.Action = ItemInSocket;
				break;
			}
		case UNKNOWN1:
			{
				thisItem.Action = UNKNOWN1;
				break;
			}
		case UpdateStats:
			{
				thisItem.Action = UpdateStats;
				break;
			}
		case UNKNOWN2:
			{
				thisItem.Action = UNKNOWN2;
				break;
			}
		case WeaponSwitch:
			{
				thisItem.Action = WeaponSwitch;
				break;
			}
		}

		
		currentPos += sizes[i];
		i++;

		thisItem.PacketLength = field.ReadBits(currentPos, sizes[i]);



		currentPos += sizes[i];
		i++;

		switch (field.ReadBits(currentPos, sizes[i]))
		{
		case Helm:
			{
				thisItem.Category = Helm;
				break;
			}
		case Armor:
			{
				thisItem.Category = Armor;
				break;
			}
		case Weapon:
			{
				thisItem.Category = Weapon;
				break;
			}
		case Weapon2:
			{
				thisItem.Category = Weapon2;
				break;
			}
			case Shield:
			{
				thisItem.Category = Shield;
				break;
			}
			case Special:
				{
					thisItem.Category = Special;
					break;
				}
			case Misc:
				{
					thisItem.Category = Misc;
					break;
				}
		}
		if ((weaponsOnly) && (thisItem.Category != Weapon)) {return thisItem;}


		currentPos += sizes[i];
		i++;
		

		thisItem.Id = field.ReadBits(currentPos, sizes[i]);



		currentPos += sizes[i];
		i++;

		if (thisItem.PacketType == OwnedItem)
		{
			switch (field.ReadBits(currentPos, sizes[i]))
			{
			case Player:
				{
					thisItem.OwnerType = Player;
					break;
				}
			case NPC:
				{
					thisItem.OwnerType = NPC;
					break;
				}
			case Object:
				{
					thisItem.OwnerType = Object;
					break;
				}
			case Missile:
				{
					thisItem.OwnerType = Missile;
					break;
				}
			case Item:
				{
					thisItem.OwnerType = Item;
					break;
				}
			case WP:
				{
					thisItem.OwnerType = WP;
					break;
				}
			}

			
			currentPos += sizes[i];
			i++;

			thisItem.OwnerId = field.ReadBits(currentPos, sizes[i]);

			currentPos += sizes[i];
			i++;
		}

		else
		{
			thisItem.OwnerId = -1;
			thisItem.OwnerType = None;
			i+= 2;
		}
		//Reading flags this might be ugly
		int j = 0;
		int flagPos = currentPos;
		ItemFlags thisFlags;
		int flagSizes[] = {
							1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 4
						   };

		thisFlags.Equipped = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN1 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.InSocket = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Identified = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN2 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.SwitchedIn = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.SwitchedOut = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Broken = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN3 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Potion = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Socketed = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN4 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.InStore = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.NotInSocket = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN5 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Ear = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.StartItem = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN6 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.SimpleItem = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Ethereal = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Any = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Personalized = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Gamble = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.Runeword = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN7 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisFlags.UNKNOWN8 = field.ReadBits(flagPos, flagSizes[j]);
		flagPos += flagSizes[j];
		j++;

		thisItem.Flags = thisFlags;

							

		currentPos+= sizes[i];
		i++;

		thisItem.Version = field.ReadBits(currentPos, sizes[i]);

		currentPos += sizes[i];
		i++;

		int unk1 = field.ReadBits(currentPos, sizes[i]);
		thisItem.Unknown1 = unk1;
		currentPos += sizes[i];
		i++;

		int dest = field.ReadBits(currentPos, sizes[i]);
		switch (dest)
		{
		case Unspecified:
			{
				thisItem.Destination = Unspecified;
				//printf("Dest is: %u\n", dest);
				break;
			}
		case Equipment:
			{
				thisItem.Destination = Equipment;
				//printf("Dest is: %u\n", dest);
				break;
			}
		case Belt:
			{
				thisItem.Destination = Belt;
				//printf("Dest is: %u\n", dest);
				break;
			}
		case Ground:
			{
				thisItem.Destination = Ground;
				//printf("Dest is: %u\n", dest);
				break;
			}
		case Cursor:
			{
				thisItem.Destination = Cursor;
				//printf("Dest is: %u\n", dest);
				break;
			}
		case InItem:
			{
				thisItem.Destination = InItem;
				break;
			}
		}

		currentPos += sizes[i];
		i++;

		if (thisItem.Destination == Ground)
		{
			Position pos;
			pos.xPos = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			pos.yPos = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			thisItem.Pos = pos;
			i+=4;
		}
		else
		{
			i+=2;

			switch (field.ReadBits(currentPos, sizes[i]))
			{
			case Eq_NotApplicable:
				{
					thisItem.EquipLoc = Eq_NotApplicable;
					break;
				}
			case Eq_Helm:
				{
					thisItem.EquipLoc = Eq_Helm;
					break;
				}
			case Eq_Amulet:
				{
					thisItem.EquipLoc = Eq_Amulet;
					break;
				}
			case Eq_Armor:
				{
					thisItem.EquipLoc = Eq_Armor;
					break;
				}
			case Eq_RightHand:
				{
					thisItem.EquipLoc = Eq_RightHand;
					break;
				}
			case Eq_LeftHand:
				{
					thisItem.EquipLoc = Eq_LeftHand;
					break;
				}
			case Eq_RightHandRing:
				{
					thisItem.EquipLoc = Eq_RightHandRing;
					break;
				}
			case Eq_LeftHandRing:
				{
					thisItem.EquipLoc = Eq_LeftHandRing;
					break;
				}
			case Eq_Belt:
				{
					thisItem.EquipLoc = Eq_Belt;
					break;
				}
			case Eq_Boots:
				{
					thisItem.EquipLoc = Eq_Boots;
					break;
				}
			case Eq_Gloves:
				{
					thisItem.EquipLoc = Eq_Gloves;
					break;
				}
			case Eq_RightHandSwitch:
				{
					thisItem.EquipLoc = Eq_RightHandSwitch;
					break;
				}
			case Eq_LeftHandSwitch:
				{
					thisItem.EquipLoc = Eq_LeftHandSwitch;
					break;
				}
			}
			currentPos += sizes[i];
			i++;

			Position pos;
			pos.xPos = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			pos.yPos = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			thisItem.Pos = pos;

			switch (field.ReadBits(currentPos, sizes[i]))
			{
			case Inventory:
				{
					thisItem.Container = Inventory;
					break;
				}
			case Trade:
				{
					thisItem.Container = Trade;
					break;
				}
			case Cube:
				{
					thisItem.Container = Cube;
					break;
				}
			case Stash:
				{
					thisItem.Container = Stash;
					break;
				}
			}
			currentPos += sizes[i];
			i++;

		}

		if (thisItem.Flags.Ear == 1)
		{
			thisItem.EarStats.charClass = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;

			thisItem.EarStats.charLevel = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;

			std::string Name("");
			for (int j=0; j < 15; j++)
			{
				const char nextChar = char(field.ReadBits(currentPos, sizes[i]));
				if (nextChar != 0)
				{
					Name.append(1, nextChar);
					printf(".. %c\n", nextChar);
					currentPos += sizes[i];
				}

				i++;
			}

			thisItem.EarStats.charName = Name;

			return thisItem;
		}

		else
		{
			i += 17;
		}

		std::string baseItemName = "";
		for (int j=0; j < 3; j++)
		{
			const char nextChar = char(field.ReadBits(currentPos, sizes[i]));
			baseItemName.append(1, nextChar);
			currentPos += sizes[i];
			i++;
		}

		currentPos += sizes[i];
		i++;

		thisItem.BaseItem = baseItemName;

		if (_stricmp(thisItem.BaseItem.c_str(), "gld") == 0)
		{
			int bigpile = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;

			int goldAmount;
			if (bigpile == 1)
			{
				goldAmount = field.ReadBits(currentPos, sizes[i]);
				i+=2;
			}
			else
			{
				i++;
				goldAmount = field.ReadBits(currentPos, sizes[i]);
				currentPos += sizes[i];
				i++;

			}
			thisItem.GoldAmount = goldAmount;

			return thisItem;
		}
		else
		{
			i+= 3;
		}


		int usedSockets = field.ReadBits(currentPos, sizes[i]);
		currentPos += sizes[i];
		i++;
		thisItem.UsedSockets = usedSockets;

		if ((thisItem.Flags.SimpleItem==1) | (thisItem.Flags.Gamble== 1))
		{
			return thisItem;
		}

		int itemLevel = field.ReadBits(currentPos, sizes[i]);
		thisItem.ItemLevel = itemLevel;
		currentPos += sizes[i];
		i++;

		int quality = field.ReadBits(currentPos, sizes[i]);
		switch (quality)
		{
		case Inferior:
			{
				thisItem.Quality = Inferior;
				break;
			}
		case Normal:
			{
				thisItem.Quality = Normal;
				break;
			}
		case Superior:
			{
				thisItem.Quality = Superior;
				break;
			}
		case Magic:
			{
				thisItem.Quality = Magic;
				break;
			}
		case Set:
			{
				thisItem.Quality = Set;
				break;
			}
		case Rare:
			{
				thisItem.Quality = Rare;
				break;
			}
		case Unique:
			{
				thisItem.Quality = Unique;
				break;
			}
		case Crafted:
			{
				thisItem.Quality = Crafted;
				break;
			}
		}
		currentPos += sizes[i];
		i++;

		int hasGraphic = field.ReadBits(currentPos, sizes[i]);
		currentPos += sizes[i];
		i++;

		if (hasGraphic == 1)
		{
			int graphic = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			thisItem.Graphic = graphic;
		}
		else
		{
			i++;
		}


		int hasColor = field.ReadBits(currentPos, sizes[i]);
		currentPos += sizes[i];
		i++;

		if (hasColor == 1)
		{
			int color = field.ReadBits(currentPos, sizes[i]);
			currentPos += sizes[i];
			i++;
			thisItem.Color = color;
		}
		else
		{
			thisItem.Color = -1;
			i++;
		}

		if (thisItem.Flags.Identified == 1)
		{
			int Affix[2];
//			int uId; //Unused - alex
			int offset = 0;
			switch (thisItem.Quality)
			{
			case Inferior:
				{
					offset = 3;
					Affix[0] = field.ReadBits(currentPos, offset);
					Affix[1] = -1;
					break;
				}		
			case Superior:
				{
					offset = 3;
					Affix[0] = field.ReadBits(currentPos, offset);
					Affix[1] = -1;
					break;
				}
			case Magic:		// This seems to be prefix and suffix?
				{
					offset = 22;
					Affix[0] = field.ReadBits(currentPos, 11);
					currentPos += 11;
					Affix[1] = field.ReadBits(currentPos, 11);
					currentPos +=11;
					break;
				}
			case Rare: // does not handle all affixes only first two? 
			case Crafted: // does not handle all affixes
				{
					unsigned int exists;
					Affix[0] = field.ReadBits(currentPos, 8);
					currentPos += 8;
					Affix[1] = field.ReadBits(currentPos, 8);
					currentPos += 8;
					 // The order is prefix-suffix-prefix-suffix-prefix-suffix
					 for (i = 0; i < 3; i++)
					 {
						exists = field.ReadBits(currentPos, 1); currentPos++;
						if (exists == 1)   // means the next affix exists
						{
							exists = field.ReadBits(currentPos, 11); currentPos+=11;
							thisItem.Prefix[i] = exists;
						}
						exists = field.ReadBits(currentPos, 1); currentPos++;
						if (exists == 1)   // means the next affix exists
						{
							exists = field.ReadBits(currentPos, 11); currentPos+=11;
							thisItem.Suffix[i] = exists;
						}
					 } 
					break;
				}
			case Set:
				{
					offset = 12;
					Affix[0] = field.ReadBits(currentPos, 12);
					Affix[1] = -2;
					currentPos += offset;
					break;
				}
			case Unique:
				{
					offset = 12;
					Affix[0] = field.ReadBits(currentPos, 12);
					Affix[1] = -3;
					currentPos += offset;
					break;
				}
			}
			thisItem.ItemAffix[0] = Affix[0]; // affix[1] is negative if non-magic/rare/crafted
			thisItem.ItemAffix[1] = Affix[1];

//////////////////////////
// the following code added by zeiris, and dubious at best
// made for specific purpose, makes lots of assumptions about what it WON'T get used for!
/////////////////////////////
			if (thisItem.Flags.Personalized==1) {
				// lets ignore this for now, stuff in shops shouldn't be personalized
				printf("Skipping personalized item.\n");
				return thisItem;

			}

		}
		if (thisItem.Flags.Runeword==1) {
			// no runewords
			return thisItem;
		}
		if ((thisItem.Category==Armor) ||
			(thisItem.Category==Shield) || // this is for defense, hope it covers everything?
			(thisItem.Category==Helm) || // gloves, boots, and probably other armour that has no sockets
			((thisItem.Category==Misc) && // is misc - sadly so are runes gems and pots and (probably) arrows+bolts
				(thisItem.Quality>Normal)) ) // this means the bot WON'T read white misc items
		{								
			int itemDef = field.ReadBits(currentPos, 11);
			thisItem.Defense = itemDef-10;
			currentPos += 11;
		}

		if ((thisItem.Category==Armor) ||
			(thisItem.Category==Shield) || 
			(thisItem.Category==Weapon) || // this is for durability
			(thisItem.Category==Weapon2) || // pretty sure there's other stuff that also has it (misc?)
			(thisItem.Category==Misc) ||	// for gloves - special?
			(thisItem.Category==Helm)) 
		{
			int itemMaxDur = field.ReadBits(currentPos, 8);
			thisItem.DurabilityMax = itemMaxDur;
			currentPos += 8;
			int itemDur = field.ReadBits(currentPos, 8);
			thisItem.Durability = itemDur;
			currentPos += 8;
		}
		if (thisItem.DurabilityMax!=0) { // NOT indistructable by default (phase blades)
			currentPos++;
		}
		// finally, sheesh, sockets!
		if (thisItem.Flags.Socketed==1) {
			int itemSockets = field.ReadBits(currentPos, 4);
			thisItem.Sockets = itemSockets;
			currentPos += 4;
		} else {thisItem.Sockets = 0;}
		
		// there may be 5 bits of set item data here
		// there is a 9 bit item stack count for throwing weapons and shiz here

		if ((thisItem.Quality==Set) || (thisItem.Flags.Runeword==1)) {
		// runewords and set items have shiz here
		// but afterwards, it's the item stats!
		// we don't really care about sets and runewords 
			return thisItem;
		}
					
   // Stats
   /*
    * Lots of stats are read the same way but with slightly different parameters.
    * This loop first checks the stat ID then sets the appropriate parameters and the reading
    * method which is executed afterwards.
    * Some stats must be read individually and if there is need for it, it is done in the first run of the loop.
    * Look at the comments above each methods for an explanation how it works in detail.
    */
	//printf("Entering stat reading while loop\n");
   const unsigned int METHOD_NORMAL = 10000; 
   const unsigned int METHOD_NORMAL2 = 10001; 
   const unsigned int METHOD_ADD = 10002;   

   unsigned int NormalParam = 0;
   unsigned int Normal2Param1 = 0, Normal2Param2 = 0;
   unsigned int AddParamAdd = 0, AddParamBits = 0;


   unsigned int p1, p2, p3, p4, StatID = 0;
   unsigned int Output = 0, RunNumber=0;

   while (true)
   {
		//printf("loop entered\n");
      if (Output < 10000)      // Because continue in switch(..) jumps back to while (..)
      {                  // Output >= 10000 means we've set the reading method and jump straight to reading
		//printf("Output under 10000\n");
		  if (currentPos>=(packetLength*8-1))	{
			  //printf("stat data end hit!\n");
            return thisItem;	// aand we're done (nonlinear, but oh well)
		  }
		// if there's still data, read a stat ID
		 Output = field.ReadBits(currentPos, 9); currentPos+=9;
		 StatID = Output;

         // TODO: For set items, there is still data after this for set items.
         //       I haven't checked that yet but I assume it could be set bonuses.
         //       Just the Same way as the runeword stats follow here.
         if (Output == 511)
         {
		  //printf("511 statID hit at %d bits (0-based) into a %d bit (1-based) packet\n", currentPos, packetLength*8);
			if (thisItem.Flags.Runeword==1)
            {
				//printf("511: item is a runeword");
               if (RunNumber == 1)
                  return thisItem;
               RunNumber++;
               continue;
            }
			 
            return thisItem;
         } // I don't know what this does, and won't mess with it until I do - Alex
         
         p1 = p2 = p3 = p4 = 0;
      }
      // TODO: Add the decoding methods here in an else-structure to gain
      // a minimum increase in performance (must take out the reading methods of switch(..) then)

      switch (Output)
      {
      case 0:      // +x to strength (actual ID is 350, replaced at the end of the function)
		//printf("+x to strength detected\n");
		  // ZEIRIS: Most strange. I've only seen this work with weapons. Definitely DNW with gloves.
         Output = METHOD_ADD; AddParamAdd = 32; AddParamBits = 8;
         continue;
      case 1:      // +x to energy
      case 2:      // +x to dexterity
      case 3:      // +x to Vitality
         Output = METHOD_ADD; AddParamAdd = 32; AddParamBits = 7;
         continue;
      case 7:      // +x to life
         Output = METHOD_ADD; AddParamAdd = 32; AddParamBits = 9;
         continue;
      case 9:      // +x to mana
         Output = METHOD_ADD; AddParamAdd = 32; AddParamBits = 8;
         continue;
      case 11:   // +x stamina
         Output = METHOD_ADD; AddParamAdd = 32; AddParamBits = 8;
         continue;
      case 16:   // +x% enhanced defense
         Output = METHOD_NORMAL; NormalParam = 9;
         continue;
      case 17:   // +x% enhanced Damage
         // I have no idea, what parameter 2 is good for but p1 is always the
         // same as p2, so one could be for minimum dmg and the other for max dmg
         // or perhaps for melee/throw dmg although i never saw a difference between them
         Output = METHOD_NORMAL2; Normal2Param1 = 9; Normal2Param2 = 9;
         continue;
      case 19:   // +x to attack rating
         Output = METHOD_NORMAL; NormalParam = 10;
         continue;
      case 20:   // +x% increased chance of blocking
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 21:   // +x minimum dmg (onehand)
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 22:   // +x maximum dmg (onehand)
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 23:   // +x minimum dmg (twohand)
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 24:   // +x maximum dmg (twohand)
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 27:   // Regenerate mana x%
      case 28:   // heal stamina +x%
         Output = METHOD_NORMAL; NormalParam = 8;
         continue;
      case 31:   // +x def
         Output = METHOD_ADD; AddParamAdd = 10; AddParamBits = 11;
         continue;
      case 32:   // +x def vs. missiles
         Output = METHOD_NORMAL; NormalParam = 9;
         continue;
      case 33:   // +x def vs. melee
         Output = METHOD_NORMAL; NormalParam = 8;
         continue;
      case 34:   // dmg reduced by x
      case 35:   // magic dmg reduced by x
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 36:   // dmg reduced by x%
         Output = METHOD_NORMAL; NormalParam = 8;   // WTF?! 8 bits... dmg reduced by 200%+?^^
         continue;
      case 37:   // +x% magic resist
      case 39:   // +x% fire resist
      case 41:   // +x% lightning resist
      case 43:   // +x% cold resist
      case 45:   // +x% poison resist
         Output = METHOD_ADD; AddParamAdd = 50; AddParamBits = 8;
         continue;
      case 38:   // +x% maximum magic resist
      case 40:   // +x% maximum fire resist
      case 42:   // +x% maximum lighning resist
      case 44:   // +x% maximum cold resist
      case 46:   // +x% maximum poison resist
         Output = METHOD_NORMAL; NormalParam = 5;
         continue;
      case 48:   // +x-y fire dmg
         Output = METHOD_NORMAL2; Normal2Param1 = 8; Normal2Param2 = 9;
         continue;
      case 50:   // +x-y lightning dmg
         Output = METHOD_NORMAL2; Normal2Param1 = 6; Normal2Param2 = 10;
         continue;
      case 52:   // +x-y magic dmg
         Output = METHOD_NORMAL2; Normal2Param1 = 8; Normal2Param2 = 9;
         continue;
      case 54:   // +x-y cold dmg (z seconds duration)
         p1=field.ReadBits(currentPos, 8); currentPos+=8;
         p2=field.ReadBits(currentPos, 9); currentPos+=9;
         p3=field.ReadBits(currentPos, 8); currentPos+=8;
         // p3 is the duration in frames, I will not convert it to seconds here,
         // because there are items which have cold durations that are not
         // whole multiples of a second
         break;
      case 57:   // +x-y poison dmg over z seconds
         p1=field.ReadBits(currentPos, 10); currentPos+=10;
         p2=field.ReadBits(currentPos, 10); currentPos+=10;
         p3=field.ReadBits(currentPos, 9); currentPos+=9;
		 // TODO: There's still a small error here (ex: D2:175 poison <-> my Prog: 179)
         //       Maybe the packet does not give 10*pDmg per second, but 10.xx*pDmg/sec
         p3 *= (unsigned int)(0.04);
         p1 *= (unsigned int)((double)p3*0.1);   // 10*dmg per second -> total dmg
         p2 *= (unsigned int)((double)p3*0.1);
         break;
      case 60:   // x% life stolen per hit
      case 62:   // x% mana stolen per hit
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 73:   // +x maximum durability
         // This is a hidden stat. It normally comes with uniques/sets
         Output = METHOD_NORMAL; NormalParam = 8;
         continue;
      case 74:   // Replenish life +x
         Output = METHOD_ADD; AddParamAdd = 30; AddParamBits = 6;
         continue;
      case 75:   // increase maximum durability x%
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 7;
         continue;
      case 76:   // increase maximum life x%
      case 77:   // increase maximum mana x%
         Output = METHOD_ADD; AddParamAdd = 10; AddParamBits = 6;
         continue;
      case 78:   // Attacker takes dmg of x
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 79:   // x% extragold from monsters
         Output = METHOD_ADD; AddParamAdd = 100; AddParamBits = 9;
         continue;
      case 80:   // +x% magic find
         Output = METHOD_ADD; AddParamAdd = 100; AddParamBits = 8;
         continue;
      case 81:   // Knockback
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 83:   // +x to class y skill levels
         Output = METHOD_NORMAL2; Normal2Param1 = 3; Normal2Param2 = 3;
         continue;
      case 85:   // +x% experience gained
         Output = METHOD_ADD; AddParamAdd = 50; AddParamBits = 9;
         continue;
      case 86:   // +x to life after each kill
      case 87:   // reduces all vendor prices x%
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 89:   // +x to light radius
         Output = METHOD_ADD; AddParamAdd = 4; AddParamBits = 4;
         continue;
      case 91:   // Requirements +x%
         Output = METHOD_ADD; AddParamAdd = 100; AddParamBits = 8;
         continue;
      case 92:   // + level requirements and possibly more stuff
         // This is a hidden stat. It appears on items which have been upgraded to their
         // exceptional or elite version.
         // TODO: I don't know what the other stuff in the packet means and neither do I know
         //       for sure how many bits the first parameter has.
         Output = METHOD_NORMAL2; Normal2Param1= 5; Normal2Param2 = 18;
         continue;
      case 93:   // x% increased attack speed
      case 96:   // x% faster run/walk
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 7;
         continue;
      case 97:   // +x to skill y (all classes)
         Output = METHOD_NORMAL2; Normal2Param1 = 9; Normal2Param2 = 6;
         continue;
      case 99:   // x% faster hit recovery
      case 102:   // +x% faster block rate
      case 105:   // x% faster cast rate
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 7;
         continue;
      case 108:   // slain monsters rest in peace
         Output = METHOD_NORMAL; NormalParam = 1;
         continue;
      case 107:   // +x to skill y (class only)
         Output = METHOD_NORMAL2; Normal2Param1 = 9; Normal2Param2 = 3;
         continue;
      case 110:   // Poison Length reduced by x%
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 8;
         continue;
      case 111:   // Damage +x
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 9;
         continue;
      case 112:   // Hit causes monster to flee x%
         // p1 == number out of 127 hits which will cause the monster to flee
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 113:   // Hit blinds target
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 114:
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 115:   // ignore target defense
         Output = METHOD_NORMAL; NormalParam = 1;
         continue;
      case 116:   // -x% target defense
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 117:   // prevent monster heal
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 118:   // half freeze duration
         Output = METHOD_NORMAL; NormalParam = 1;
         continue;
      case 119:   // +x% Bonus to attack rating
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 9;
         continue;
      case 120:   // +x target def per hit
         Output = METHOD_ADD; AddParamAdd = 128; AddParamBits = 7;
         continue;
      case 121:   // +x% dmg to demons
      case 122:   // +x% dmg to undead
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 9;
         continue;
      case 123:   // +x attack rating against demons
      case 124:   // +x attack rating against undead
         Output = METHOD_ADD; AddParamAdd = 128; AddParamBits = 10;
         continue;
      case 126:   // +x to elemntal skills y
         Output = METHOD_NORMAL2; Normal2Param1 = 3; Normal2Param2 = 3;
         continue;
      case 127:   // +x to all skills
         Output = METHOD_NORMAL; NormalParam = 3;
         continue;
      case 128:   // attacker takes lightning dmg of x
         Output = METHOD_NORMAL; NormalParam = 5;
         continue;
      case 134:   // freezes target +x
         Output = METHOD_NORMAL; NormalParam = 5;
         continue;
      case 135:   // x% chance on open wounds
      case 136:   // x% Chance on crushing blow
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 138:   // +x to mana after each kill
      case 139:   // +x to life after each demon kill
      case 141:   // x% deadly strike
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 142:   // x% fire absorb
      case 143:   // +x fire absorb
      case 144:   // x% lighning absorb
      case 145:   // +x lightning absorb
      case 146:   // x% magic absorb
      case 147:   // +x magic absorb
      case 148:   // x% cold absorb
      case 149:   // +x cold absorb
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 150:   // slows target by x%
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 151:   // Level x Aura y when equipped
         Output = METHOD_NORMAL2; Normal2Param1 = 9; Normal2Param2 = 5;
         continue;
      case 152:   // indestructible
      case 153:   // cannot be frozen
         Output = METHOD_NORMAL; NormalParam = 1;
         continue;
      case 154:   // slower stamina drain
         Output = METHOD_ADD; AddParamAdd = 20; AddParamBits = 7;
         continue;
      case 155:   // x% reanimate as y
         p1=field.ReadBits(currentPos, 10); //monster ID 
		  currentPos+=10;
         p2=field.ReadBits(currentPos, 7); //chance
		  currentPos+=7;
         break;
      case 156:   // Piercing attack (x%)
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 157:   // fires magic arrows
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 158:   // fires exploding arrows/bolts
         // TODO: I don't know what paramater 1 means exactly (could perhaps be the level
         //       of the exploding arrow (for calculating the explosion radius))
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 159:   // +x minimum throw dmg
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 160:   // +x maximum throw dmg
         Output = METHOD_NORMAL; NormalParam = 7;
         continue;
      case 188:   // +x to skill tab y (class only)
		 p1=field.ReadBits(currentPos, 3); // Skill tab offset
          currentPos+=3;
		 p2=field.ReadBits(currentPos, 3); //class ID
		  currentPos+=3;
         p3=field.ReadBits(currentPos, 10); //todo I dunno
		  currentPos+=10;
         p4=field.ReadBits(currentPos, 3); //+skill bonus
		  currentPos+=3;
         break;
      case 195:   // x% chance to cast level y skill z on attack
      case 196:   // x% chance to cast level y skill z when you kill an enemy
      case 197:   // x% chance to cast level y skill z when you die
      case 198:   // x% chance to cast level y skill z on striking
      case 199:   // x% chance to cast level y skill z when you level up
      case 201:   // x% chance to cast level y skill z when struck
		 p1=field.ReadBits(currentPos, 6); // lvel
		  currentPos+=6;
         p2=field.ReadBits(currentPos, 10); //skill ID
		  currentPos+=10;
         p3=field.ReadBits(currentPos, 7); //chance
		  currentPos+=7;
         break;
      case 204:   // level x skill y (a/b charges)
		 p1=field.ReadBits(currentPos, 6);  currentPos+=6;
         p2=field.ReadBits(currentPos, 10); currentPos+=10;
         p3=field.ReadBits(currentPos, 8);  currentPos+=8;
         p4=field.ReadBits(currentPos, 8);  currentPos+=8;
         
         break;
      case 214:   // +x defense per char level
      case 216:   // +x life per char level
      case 217:   // +x mana per char level
      case 218:   // +x maximum dmg per char level
      case 219:   // +x% increased maximum dmg per char level
         // p1 == 8 * def per char level (214)
         // p1 == 8 * life per char level (216)
         // p1 == 8 * dmg per level (218)
         // p1 == 8 * dmg % per char level (219)
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 220:   // +x strength per char level
      case 221:   // +x dexterity per char level
      case 222:   // +x energy per char level
      case 223:   // +x vitality per char level
      case 224:   // +x attack rating per char level
      case 225:   // +x % attack rating per char level
      case 230:   // +x% cold resistance per char level
      case 231:   // +x% fire resistance per char level
      case 232:   // +x% lightning resistance per char level
      case 233:   // +x% poisons resistance per char level
      case 234:   // absorbs x cold dmg per char level
      case 235:   // absorbs x fire dmg per char level
      case 236:   // absorbs x lightning dmg per char level
      case 237:   // absorbs x poison dmg per char level
         // p1 == 8 * stat per char level (220/221/222/223)
         // p1 == 2 * ar per level (224)
         // p1 == 2 * ar % per level (225)
         // p1 == 8 * resistance per level (230/231/232/233)
         // p1 == 8 * absorb per char level (234/235/236/237)
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 238:   // attacker takes dmg of x per char level
         Output = METHOD_NORMAL; NormalParam = 5;
         // p1 == 8 * dmg per level
         continue;
      case 239:   // +x% extragold from monsters per char level
      case 240:   // +x% better chance on getting magic item per char level
      case 241:   // heal stamina +x% per char level
      case 242:   // +x to maximum stamina per char level
      case 243:   // +x% dmg to demons per char level
      case 244:   // +x% dmg to undead per char level
      case 245:   // +x to attack rating against demons per char level
      case 246:   // +x to attack rating against undead per char level
         // p1 == 8 * extra gold per level (239)
         // p1 == 8 * mf per level (240)
         // p1 == 8 * rate per level (241)
         // p1 == 8 * max stamina per level (242)
         // p1 == 8 * dmg % per level (243/244)
         // p1 == 2 * attack rating per level (245/246)
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 250:   // x% deadly strike per level
         // p1 == 8 * deadly strike per level
         Output = METHOD_NORMAL; NormalParam = 6;
         continue;
      case 252:   // repairs 1 durability in x seconds
         p1=field.ReadBits(currentPos, 6);  currentPos+=6;
         p1 = (unsigned int)(100.0/(double)p1);   // durability per 100 sec -> 1 durability per x sec
         break;
      case 253:   // replenishes quantity (1 per x seconds)
         // The exact value is normally hidden by the game
		 p1=field.ReadBits(currentPos, 6); 
         // p1 == x per 100 seconds
         p1 = (unsigned int)(100.0/(double)p1);
         break;
      case 254:   // +x stack size
         // The exact value is normally hidden by the game
         Output = METHOD_NORMAL; NormalParam = 8;
         continue;
      case 329:   // +x% to fire skill dmg
      case 330:   // +x% to lightning skill dmg
      case 331:   // +x% to cold skill dmg
      case 332:   // +x% to poison skill dmg
         Output = METHOD_ADD; AddParamAdd = 50; AddParamBits = 9;
         continue;
      case 333:   // -x% to enemy fire resistance
      case 334:   // -x% to enemy lighning resistance
      case 335:   // -x% to enemy cold resistance
      case 336:   // -x% to enemy poison resistance
         Output = METHOD_NORMAL; NormalParam = 8;
         continue;

         
   // Reading methods
      case METHOD_NORMAL:
         // This one just reads some bits for stats with only one parameter.
         // NormalParam tells it how many bits to read.
		 p1=field.ReadBits(currentPos, NormalParam); currentPos+=NormalParam;
         Output = 0;
         break;

      case METHOD_NORMAL2:
         // Just the same as above but for stats with 2 parameters.
         p1=field.ReadBits(currentPos, Normal2Param1);  currentPos+=Normal2Param1;
         p2=field.ReadBits(currentPos, Normal2Param2); currentPos+=Normal2Param2;
         Output = 0;
         break;

      case METHOD_ADD:
         // ActualValue == ReceivedValue+Constant
         // AddParamAdd: the constant which is added
         // AddParamBits: the number of bits to read;
         p1=field.ReadBits(currentPos, AddParamBits); currentPos+=AddParamBits;
         p1 -= AddParamAdd;
         Output = 0;
         break;

      default:
         //printf("Unknown Stat %d in byte %d\n", Output, currentPos);
		  //if (thisItem.Category==Weapon) {printf("Unknown Stat %d in byte %d on a weapon\n", Output, currentPos);}

         return thisItem;
         break;
      }
	
	  if (StatID==0) {StatID=350;} // strength, 0 doesn't work well with the next bit it seems

	  while (thisItem.stats.find(StatID)!=thisItem.stats.end()) // ID*10 until there's space for an entry
	  {
			StatID*=10;
	  }
	  thisItem.stats[StatID].p1 = p1;
      thisItem.stats[StatID].p2 = p2;
      thisItem.stats[StatID].p3 = p3;
      thisItem.stats[StatID].p4 = p4;
      thisItem.stats[StatID].ID = StatID;

	  //Log(path, "Adding stats: p1=%d p2=%d p3=%d p4=%d ID=%d\n", p1, p2, p3, p4, StatID);

   } // end of while(1) loop



		



			
		return thisItem;





}
