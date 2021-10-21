#pragma once

const char* itemnameStr[] = 
{ //0 is unused, I'll use it for no affix
		"Any",
		"Short Sword",
		"Gladius",
		"Falcata",
		"Scimitar",
		"Cutlass",
		"Ataghan",
		"Saber",
		"Shamshir",
		"Elegant Blade",
		"Falchion",
		"Tulwar",
		"Hydra Edge",
		"Crystal Sword",
		"Dimensional Blade",
		"Phase Blade",
		"Broad Sword",
		"Battle Sword",
		"Conquest Sword",
		"Long Sword",
		"Rune Sword",
		"Cryptic Sword",
		"War Sword",
		"Ancient Sword",
		"Mythical Sword",
		"Two-Handed Sword",
		"Espadon",
		"Legend Sword",
		"Claymore",
		"Dacian Falx",
		"Highland Blade",
		"Giant Sword",
		"Tusk Sword",
		"Balrog Blade",
		"Bastard Sword",
		"Gothic Sword",
		"Champion Sword",
		"Flamberge",
		"Zweihander",
		"Colossus Sword",
		"Great Sword",
		"Executioner Sword",
		"Colossus Blade",
		"Hand Axe",
		"Hatchet",
		"Tomahawk",
		"Axe",
		"Cleaver",
		"Small Crescent",
		"Double Axe",
		"Twin Axe",
		"Ettin Axe",
		"Military Pick",
		"Crowbill",
		"War Spike",
		"War Axe",
		"Naga",
		"Berserker Axe",
		"Large Axe",
		"Military Axe",
		"Feral Axe",
		"Broad Axe",
		"Bearded Axe",
		"Silver Edged Axe",
		"Battle Axe",
		"Tabar",
		"Decapitator",
		"Great Axe",
		"Gothic Axe",
		"Champion Axe",
		"Giant Axe",
		"Ancient Axe",
		"Glorious Axe",
		"Club",
		"Cudgel",
		"Truncheon",
		"Spiked Club",
		"Barbed Club",
		"Tyrant Club",
		"War Hammer",
		"Battle Hammer",
		"Legendary Mallet",
		"Maul",
		"War Club",
		"Ogre Maul",
		"Great Maul",
		"Martel de Fer",
		"Thunder Maul",
		"Mace",
		"Flanged Mace",
		"Reinforced Mace",
		"Morning Star",
		"Jagged Star",
		"Devil Star",
		"Flail",
		"Knout",
		"Scourge",
		"Dagger",
		"Poignard",
		"Bone Knife",
		"Dirk",
		"Rondel",
		"Mithral Point",
		"Kris",
		"Cinquedeas",
		"Fanged Knife",
		"Blade",
		"Stilleto",
		"Legend Spike",
		"Spear",
		"War Spear",
		"Hyperion Spear",
		"Trident",
		"Fuscina",
		"Stygian Pike",
		"Brandistock",
		"War Fork",
		"Mancatcher",
		"Spetum",
		"Yari",
		"Ghost Spear",
		"Pike",
		"Lance",
		"War Pike",
		"Bardiche",
		"Lochaber Axe",
		"Ogre Axe",
		"Voulge",
		"Bill",
		"Colossus Voulge",
		"Scythe",
		"Battle Scythe",
		"Thresher",
		"Poleaxe",
		"Partizan",
		"Cryptic Axe",
		"Halberd",
		"Bec-de-Corbin",
		"Great Poleaxe",
		"War Scythe",
		"Grim Scythe",
		"Giant Thresher",
		"Short Staff",
		"Jo Staff",
		"Walking Stick",
		"Long Staff",
		"Quarterstaff",
		"Stalagmite",
		"Gnarled Staff",
		"Cedar Staff",
		"Elder Staff",
		"Battle Staff",
		"Gothic Staff",
		"Shillelah",
		"War Staff",
		"Rune Staff",
		"Archon Staff",
		"Wand",
		"Burnt Wand",
		"Polished Wand",
		"Yew Wand",
		"Petrified Wand",
		"Ghost Wand",
		"Bone Wand",
		"Tomb Wand",
		"Lich Wand",
		"Grim Wand",
		"Grave Wand",
		"Unearthed Wand",
		"Scepter",
		"Rune Scepter",
		"Mighty Scepter",
		"Grand Scepter",
		"Holy Water Sprinkler",
		"Seraph Rod",
		"War Scepter",
		"Divine Scepter",
		"Caduceus",
		"Short Bow",
		"Edge Bow",
		"Spider Bow",
		"Hunter's Bow",
		"Razor Bow",
		"Blade Bow",
		"Long Bow",
		"Cedar Bow",
		"Shadow Bow",
		"Composite Bow",
		"Double Bow",
		"Great Bow",
		"Short Battle Bow",
		"Short Siege Bow",
		"Diamond Bow",
		"Long Battle Bow",
		"Long Siege Bow",
		"Crusader Bow",
		"Short War Bow",
		"Rune Bow",
		"Ward Bow",
		"Long War Bow",
		"Gothic Bow",
		"Hydra Bow",
		"Light Crossbow",
		"Arbalest",
		"Pellet Bow",
		"Crossbow",
		"Siege Crossbow",
		"Gorgon Crossbow",
		"Heavy Crossbow",
		"Balista",
		"Colossus Crossbow",
		"Repeating Crossbow",
		"Chu-Ko-Nu",
		"Demon Crossbow",
		"Throwing Knife",
		"Battle Dart",
		"Flying Knife",
		"Balanced Knife",
		"War Dart",
		"Winged Knife",
		"Throwing Axe",
		"Francisca",
		"Flying Axe",
		"Balanced Axe",
		"Hurlbat",
		"Winged Axe",
		"Javelin",
		"War Javelin",
		"Hyperion Javelin",
		"Pilum",
		"Great Pilum",
		"Stygian Pilum",
		"Short Spear",
		"Simbilan",
		"Balrog Spear",
		"Glaive",
		"Spiculum",
		"Ghost Glaive",
		"Throwing Spear",
		"Harpoon",
		"Winged Harpoon",
		"Maiden Javelin",
		"Ceremonial Javelin",
		"MatriarchalJavelin",
		"Maiden Spear",
		"Ceremonial Spear",
		"Matriarchal Spear",
		"Maiden Pike",
		"Ceremonial Pike",
		"Matriarchal Pike",
		"Stag Bow",
		"Ashwood Bow",
		"Matriarchal Bow",
		"Reflex Bow",
		"Ceremonial Bow",
		"Grand Matron Bow",
		"Katar",
		"Quhab",
		"Suwayyah",
		"Wrist Blade",
		"Wrist Spike",
		"Wrist Sword",
		"Hatchet Hands",
		"Fascia",
		"War Fist",
		"Cestus",
		"Hand Scythe",
		"Battle Cestus",
		"Claws",
		"Greater Claws",
		"Feral Claws",
		"Blade Talons",
		"Greater Talons",
		"Runic Talons",
		"Scissors Katar",
		"Scissors Quhab",
		"Scissors Suwayyah",
		"Eagle Orb",
		"Glowing Orb",
		"Heavenly Stone",
		"Sacred Globe",
		"Crystalline Globe",
		"Eldritch Orb",
		"Smoked Sphere",
		"Cloudy Sphere",
		"Demon Heart",
		"Clasped Orb",
		"Sparkling Ball",
		"Vortex Orb",
		"Dragon Stone",
		"Swirling Crystal",
		"Dimensional Shard",
		"Quilted Armor",
		"Ghost Armor",
		"Dusk Shroud",
		"Leather Armor",
		"Serpentskin Armor",
		"Wyrmhide",
		"Hard Leather Armor",
		"Demonhide Armor",
		"Scarab Husk",
		"Studded Leather",
		"Trellised Armor",
		"Wire Fleece",
		"Ring Mail",
		"Linked Mail",
		"Diamond Mail",
		"Scale Mail",
		"Tigulated Mail",
		"Loricated Mail",
		"Chain Mail",
		"Mesh Armor",
		"Boneweave",
		"Breast Plate",
		"Cuirass",
		"Great Hauberk",
		"Splint Mail",
		"Russet Armor",
		"Balrog Skin",
		"Light Plate",
		"Mage Plate",
		"Archon Plate",
		"Field Plate",
		"Sharktooth Armor",
		"Kraken Shell",
		"Plate Mail",
		"Templar Coat",
		"Hellforged Plate",
		"Gothic Plate",
		"Embossed Plate",
		"Lacquered Plate",
		"Full Plate Mail",
		"Chaos Armor",
		"Shadow Plate",
		"Ancient Armor",
		"Ornate Armor",
		"Sacred Armor",
		"Buckler",
		"Defender",
		"Heater",
		"Small Shield",
		"Round Shield",
		"Luna",
		"Large Shield",
		"Scutum",
		"Hyperion",
		"Spiked Shield",
		"Barbed Shield",
		"Blade Barrier",
		"Kite Shield",
		"Dragon Shield",
		"Monarch",
		"Bone Shield",
		"Grim Shield",
		"Troll Nest",
		"Gothic Shield",
		"Ancient Shield",
		"Ward",
		"Tower Shield",
		"Pavise",
		"Aegis",
		"Sash",
		"Demonhide Sash",
		"Spiderweb Sash",
		"Light Belt",
		"Sharkskin Belt",
		"Vampirefang Belt",
		"Belt",
		"Mesh Belt",
		"Mithril Coil",
		"Heavy Belt",
		"Battle Belt",
		"Troll Belt",
		"Girdle",
		"War Belt",
		"Colossus Girdle",
		"Cap",
		"War Hat",
		"Shako",
		"Skull Cap",
		"Sallet",
		"Hydraskull",
		"Mask",
		"Death Mask",
		"Demonhead",
		"Bone Helm",
		"Grim Helm",
		"Bone Visage",
		"Helm",
		"Casque",
		"Armet",
		"Full Helm",
		"Basinet",
		"Giant Conch",
		"Crown",
		"Grand Crown",
		"Corona",
		"Great Helm",
		"Winged Helm",
		"Spired Helm",
		"Circlet",
		"Coronet",
		"Tiara",
		"Diadem",
		"Gloves",
		"Demonhide Gloves",
		"Bramble Mitts",
		"Heavy Gloves",
		"Sharkskin Gloves",
		"Vampirebone Gloves",
		"Chain Gloves",
		"Heavy Bracers",
		"Vambraces",
		"Light Gauntlets",
		"Battle Gauntlets",
		"Crusader Gauntlets",
		"Gauntlets",
		"War Gauntlets",
		"Ogre Gauntlets",
		"Leather Boots",
		"Demonhide Boots",
		"Wyrmhide Boots",
		"Heavy Boots",
		"Sharkskin Boots",
		"Scarabshell Boots",
		"Chain Boots",
		"Mesh Boots",
		"Boneweave Boots",
		"Light Plate Boots",
		"Battle Boots",
		"Mirrored Boots",
		"Greaves",
		"War Boots",
		"Myrmidon Greaves",
		"Targe",
		"Akaran Targe",
		"Sacred Targe",
		"Rondache",
		"Akaran Rondache",
		"Sacred Rondache",
		"Heraldic Shield",
		"Protector Shield",
		"Kurast Shield",
		"Aerin Shield",
		"Gilded Shield",
		"Zakarum Shield",
		"Crown Shield",
		"Royal Shield",
		"Vortex Shield",
		"Jawbone Cap",
		"Jawbone Visor",
		"Carnage Helm",
		"Fanged Helm",
		"Lion Helm",
		"Fury Visor",
		"Horned Helm",
		"Rage Mask",
		"Destroyer Helm",
		"Assault Helmet",
		"Savage Helmet",
		"Conquerer Crown",
		"Avenger Guard",
		"Slayer Guard",
		"Guardian Crown",
		"Wolf Head",
		"Alpha Helm",
		"Blood Spirt",
		"Hawk Helm",
		"Griffon Headress",
		"Sun Spirit",
		"Antlers",
		"Hunter's Guise",
		"Earth Spirit",
		"Falcon Mask",
		"Sacred Feathers",
		"Sky Spirit",
		"Spirit Mask",
		"Totemic Mask",
		"Dream Spirit",
		"Preserved Head",
		"Mummified Trophy",
		"Minion Skull",
		"Zombie Head",
		"Fetish Trophy",
		"Hellspawn Skull",
		"Unraveller Head",
		"Sexton Trophy",
		"Overseer Skull",
		"Gargoyle Head",
		"Cantor Trophy",
		"Succubae Skull",
		"Demon Head",
		"Heirophant Trophy",
		"Bloodlord Skull",
		"Arrows",
		"Bolts"
	};