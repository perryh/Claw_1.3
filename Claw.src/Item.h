#pragma once
#include <string>
#include <map>

enum ItemPacketType
		{
			WorldItem = 0x9c,
			OwnedItem = 0x9d
		};

		enum ItemCategory
		{
			Helm   = 0,
			Armor   = 1,       
			Weapon   = 5,  
			Weapon2   = 6,        
			Shield   = 7,   
			Special = 10,
			Misc   = 16   
	    };

		enum UnitType
		{
			None = -1,
			Player = 0,
			NPC = 1,
			Object = 2,
			Missile = 3,
			Item = 4,
			WP = 5
		};

		enum ItemAction
		{
			AddToGround = 0,
			GroundToCursor = 1,        
			DropToGround = 2,
			OnGround = 3,
			PutInContainer = 4,
			RemoveFromContainer = 5,
			Equip = 6,
			IndirectlySwapBodyItem = 7,
			Unequip = 8,
			SwapBodyItem = 9,
			AddQuantity = 0x0A,
			AddToShop = 0x0B,
			RemoveFromShop = 0x0C,
			SwapInContainer = 0x0D,
			PutInBelt = 0x0E,
			RemoveFromBelt = 0x0F,
			SwapInBelt = 0x10,
			AutoUnequip = 0x11,
			RemoveFromHireling = 0x12,
			ItemInSocket = 0x13,
			UNKNOWN1 = 0x14,
			UpdateStats = 0x15,
			UNKNOWN2 = 0x16,
			WeaponSwitch = 0x17,
		};

		enum ItemDestination
		{
			Unspecified,
			Equipment,
			Belt,
			Ground,
			Cursor,
			InItem = 6
		};

		enum EquipmentLocation
	   {
		  Eq_NotApplicable   = 0,
		  Eq_Helm         = 1,
		  Eq_Amulet         = 2,
		  Eq_Armor         = 3,
		  Eq_RightHand      = 4,
		  Eq_LeftHand      = 5,
		  Eq_RightHandRing   = 6,
		  Eq_LeftHandRing   = 7,
		  Eq_Belt         = 8,
		  Eq_Boots         = 9,
		  Eq_Gloves         = 10,
		  Eq_RightHandSwitch   = 11,
		  Eq_LeftHandSwitch   = 12,
	   };

		struct Position
		{
			int xPos;
			int yPos;
		};

		enum ItemContainer
		{
			Inventory      = 2,
			Trade         = 0,
			Cube         = 3,
			Stash         = 4,
		};

		struct ItemFlags
		{
			int Equipped;
			int UNKNOWN1;
			int InSocket;
			int Identified;
			int UNKNOWN2;
			int SwitchedIn;
			int SwitchedOut;
			int Broken;
			int UNKNOWN3;
			int Potion;
			int Socketed;
			int UNKNOWN4;
			int InStore;
			int NotInSocket;
			int UNKNOWN5;
			int Ear;
			int StartItem;
			int UNKNOWN6;
			int SimpleItem;
			int Ethereal;
			int Any;
			int Personalized;
			int Gamble;
			int Runeword;
			int UNKNOWN7;
			int UNKNOWN8;
		};

		struct earStats
		{
			int charClass;
			int charLevel;
			std::string charName;
		};

		enum ItemQuality
		{
			Inferior = 1,
			Normal = 2,
			Superior = 3,
			Magic = 4,
			Set = 5,
			Rare = 6,
			Unique = 7,
			Crafted = 8,
		};
		
		struct itemStat
		{
			unsigned int ID;
			unsigned int p1;
			unsigned int p2;
			unsigned int p3;
			unsigned int p4;
		};

		struct item
		{
			std::map<int,itemStat> stats;
			ItemPacketType PacketType;
			ItemAction Action;
			int PacketLength;
			ItemCategory Category;
			int Id;
			UnitType OwnerType;
			int OwnerId;
			int Version;
			int Unknown1;
			ItemDestination Destination;
			Position Pos;
			EquipmentLocation EquipLoc;
			ItemContainer Container;
			ItemFlags Flags;
			earStats EarStats;
			std::string BaseItem;
			int GoldAmount;
			int UsedSockets;
			int ItemLevel;
			ItemQuality Quality;
			int Graphic;
			int Color;
			int ItemAffix[2];
			int Prefix[3];
			int Suffix[3];
			int Durability;
			int DurabilityMax;
			int Defense;
			int Sockets;
			unsigned int cycleTmpC, itemTmpC;
		};