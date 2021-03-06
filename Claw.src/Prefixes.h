#pragma once

const char* prefixStr[] = 
{ //0 is unused, I'll use it for no affix
		"",
		"Unused1",
        "Sturdy",
        "Strong",
        "Glorious",
        "Blessed",
        "Saintly",
        "Holy",
        "Devious",
        "Fortified",
        "Unused10",
        "Unused11",
        "Unused12",
        "Jagged6",
        "Deadly",
        "Vicious",
        "Brutal",
        "Massive",
        "Savage",
        "Merciless",
        "Vulpine",
        "Unused21",
        "Unused22",
        "Unused23",
        "Unused24",
        "Tireless",
        "Rugged",
        "Bronze",
        "Iron",
        "Steel",
        "Silver",
        "Unused31",
        "Gold",
        "Platinum",
        "Meteoric",
        "Sharp",
        "Fine",
        "Warriors",
        "Soldiers",
        "Knights",
        "Lords",
        "Kings",
        "Howling",
        "Fortuitous",
        "Unused44",
        "Unused45",
        "Unused46",
        "Unused47",
        "Unused48",
        "Glimmering",
        "Glowing7",
        "Unused51",
        "Unused52",
        "Lizards",
        "Unused54",
        "Snakes",
        "Serpents",
        "Serpents2",
        "Drakes",
        "Dragons",
        "Dragons2",
        "Wyrms",
        "Unused62",
        "Unused63",
        "Prismatic",
        "Prismatic2",
        "Azure",
        "Lapis",
        "Lapis2",
        "Cobalt",
        "Cobalt2",
        "Unused71",
        "Sapphire",
        "Unused73",
        "Unused74",
        "Crimson",
        "Burgundy",
        "Burgundy2",
        "Garnet",
        "Garnet2",
        "Unused80",
        "Ruby",
        "Unused82",
        "Unused83",
        "Ocher",
        "Tangerine",
        "Tangerine2",
        "Coral",
        "Coral2",
        "Unused89",
        "Amber",
        "Unused91",
        "Unused92",
        "Beryl",
        "Jade",
        "Jade2",
        "Viridian",
        "Viridian2",
        "Unused98",
        "Emerald",
        "Unused100",
        "Fletchers",
        "Archers",
        "Archers2",
        "Monks",
        "Priests",
        "Priests2",
        "Summoners",
        "Necromancers",
        "Necromancers2",
        "Angels",
        "Arch",
        "Arch2",
        "Slayers",
        "Berserkers",
        "Berserkers2",
        "Unused116",
        "Unused117",
        "Triumphant",
        "Stout",
        "Stout2",
        "Stout3",
        "Burly",
        "Burly2",
        "Burly3",
        "Stalwart",
        "Stalwart2",
        "Stalwart3",
        "Stout4",
        "Stout5",
        "Stout6",
        "Burly4",
        "Burly5",
        "Stalwart4",
        "Stalwart5",
        "Stout7",
        "Stout8",
        "Burly6",
        "Stalwart6",
        "Blanched",
        "Eburin",
        "Bone",
        "Ivory",
        "Sturdy2",
        "Sturdy3",
        "Strong2",
        "Glorious2",
        "Blessed2",
        "Saintly2",
        "Holy2",
        "Godly",
        "Unused151",
        "Unused152",
        "Unused153",
        "Unused154",
        "Unused155",
        "Unused156",
        "Unused157",
        "Unused158",
        "Unused159",
        "Unused160",
        "Unused161",
        "Unused162",
        "Unused163",
        "Unused164",
        "Unused165",
        "Scarlet",
        "Crimson2",
        "Unused168",
        "Unused169",
        "Unused170",
        "Unused171",
        "Unused172",
        "Unused173",
        "Unused174",
        "Unused175",
        "Unused176",
        "Unused177",
        "Unused178",
        "Unused179",
        "Unused180",
        "Unused181",
        "Unused182",
        "Carbuncle",
        "Carmine",
        "Vermillion",
        "Jagged2",
        "Deadly2",
        "Vicious2",
        "Brutal2",
        "Massive2",
        "Savage2",
        "Merciless2",
        "Ferocious",
        "Cruel",
        "Cinnabar",
        "Rusty",
        "Realgar",
        "Ruby2",
        "Vulpine2",
        "Dun",
        "Tireless2",
        "Tireless3",
        "Brown",
        "Rugged2",
        "Rugged3",
        "Rugged4",
        "Rugged5",
        "Rugged6",
        "Rugged7",
        "Rugged8",
        "Rugged9",
        "Rugged10",
        "Rugged11",
        "Rugged12",
        "Vigorous",
        "Chestnut",
        "Maroon",
        "Bronze2",
        "Bronze3",
        "Bronze4",
        "Iron2",
        "Iron3",
        "Iron4",
        "Steel2",
        "Steel3",
        "Steel4",
        "Bronze5",
        "Bronze6",
        "Bronze7",
        "Iron5",
        "Iron6",
        "Steel5",
        "Steel6",
        "Bronze8",
        "Bronze9",
        "Iron7",
        "Steel7",
        "Bronze10",
        "Iron8",
        "Steel8",
        "Silver2",
        "Gold2",
        "Platinum2",
        "Meteoric2",
        "Strange",
        "Weird",
        "Nickel",
        "Tin",
        "Silver3",
        "Argent",
        "Fine2",
        "Fine3",
        "Sharp2",
        "Fine4",
        "Sharp3",
        "Fine5",
        "Sharp4",
        "Fine6",
        "Warriors2",
        "Soldiers2",
        "Knights2",
        "Lords2",
        "Kings2",
        "Masters",
        "Grandmasters",
        "Glimmering2",
        "Glowing2",
        "Bright",
        "Screaming",
        "Howling2",
        "Wailing",
        "Screaming2",
        "Howling3",
        "Wailing2",
        "Lucky",
        "Lucky2",
        "Lucky3",
        "Lucky4",
        "Lucky5",
        "Lucky6",
        "Felicitous",
        "Fortuitous2",
        "Emerald2",
        "Lizards3",
        "Lizards4",
        "Lizards5",
        "Snakes2",
        "Snakes3",
        "Snakes4",
        "Serpents3",
        "Serpents4",
        "Serpents5",
        "Lizards6",
        "Lizards7",
        "Lizards8",
        "Snakes5",
        "Snakes6",
        "Serpents6",
        "Serpents7",
        "Lizards9",
        "Lizards10",
        "Snakes7",
        "Serpents8",
        "Lizards11",
        "Snakes8",
        "Serpents9",
        "Serpents10",
        "Drakes2",
        "Dragons3",
        "Dragons4",
        "Wyrms2",
        "Great",
        "Bahamuts",
        "Zircon",
        "Jacinth",
        "Turquoise",
        "Shimmering",
        "Shimmering2",
        "Shimmering3",
        "Shimmering4",
        "Shimmering5",
        "Shimmering6",
        "Shimmering7",
        "Rainbow",
        "Scintillating",
        "Prismatic3",
        "Chromatic",
        "Shimmering8",
        "Rainbow2",
        "Scintillating2",
        "Prismatic4",
        "Chromatic2",
        "Shimmering9",
        "Rainbow3",
        "Scintillating3",
        "Shimmering10",
        "Scintillating4",
        "Azure2",
        "Lapis3",
        "Cobalt3",
        "Sapphire2",
        "Azure3",
        "Lapis4",
        "Cobalt4",
        "Sapphire3",
        "Azure4",
        "Lapis5",
        "Cobalt5",
        "Sapphire4",
        "Azure5",
        "Lapis6",
        "Lapis7",
        "Cobalt6",
        "Cobalt7",
        "Sapphire5",
        "Lapis8",
        "Sapphire6",
        "Crimson3",
        "Russet",
        "Garnet3",
        "Ruby3",
        "Crimson4",
        "Russet2",
        "Garnet4",
        "Ruby4",
        "Crimson5",
        "Russet5",
        "Garnet5",
        "Ruby5",
        "Russet6",
        "Russet7",
        "Garnet6",
        "Garnet7",
        "Ruby6",
        "Garnet8",
        "Ruby7",
        "Tangerine3",
        "Ocher2",
        "Coral3",
        "Amber2",
        "Tangerine4",
        "Ocher3",
        "Coral4",
        "Amber3",
        "Tangerine5",
        "Ocher4",
        "Coral5",
        "Amber4",
        "Tangerine6",
        "Ocher5",
        "Ocher6",
        "Coral6",
        "Coral7",
        "Amber5",
        "Camphor",
        "Ambergris",
        "Beryl2",
        "Viridian3",
        "Jade3",
        "Emerald3",
        "Beryl3",
        "Viridian4",
        "Jade4",
        "Emerald4",
        "Beryl4",
        "Viridian5",
        "Jade5",
        "Emerald5",
        "Beryl5",
        "Viridian6",
        "Viridian7",
        "Jade6",
        "Jade7",
        "Emerald6",
        "Beryl6",
        "Jade8",
        "Triumphant2",
        "Victorious",
        "Aureolin",
        "Mechanists",
        "Artificers",
        "Jewelers",
        "Assamic",
        "Arcadian",
        "Unearthly",
        "Astral",
        "Elysian",
        "Celestial",
        "Diamond",
        "Fletchers2",
        "Acrobats",
        "Harpoonists",
        "Fletchers3",
        "Bowyers",
        "Archers3",
        "Acrobats2",
        "Gymnasts",
        "Athletes",
        "Harpoonists2",
        "Spearmaidens",
        "Lancers",
        "Burning",
        "Sparking",
        "Chilling",
        "Burning2",
        "Blazing",
        "Volcanic",
        "Sparking2",
        "Charged",
        "Powered",
        "Chilling2",
        "Freezing",
        "Glacial",
        "Hexing",
        "Fungal",
        "Graverobbers",
        "Hexing2",
        "Blighting",
        "Accursed",
        "Fungal2",
        "Noxious",
        "Venomous",
        "Graverobbers2",
        "Vodoun",
        "Golemlords",
        "Lion",
        "Captains",
        "Preservers",
        "Lion2",
        "Hawk",
        "Rose",
        "Captains2",
        "Commanders",
        "Marshals",
        "Preservers2",
        "Warders",
        "Guardians",
        "Experts",
        "Fanatic",
        "Sounding",
        "Experts2",
        "Veterans",
        "Masters2",
        "Fanatic2",
        "Raging",
        "Furious",
        "Sounding2",
        "Resonant",
        "Echoing",
        "Trainers",
        "Spiritual",
        "Natures",
        "Trainers2",
        "Caretakers",
        "Keepers",
        "Spiritual2",
        "Feral",
        "Communal",
        "Natures2",
        "Terras",
        "Gaeas",
        "Entrapping",
        "Mentalists",
        "Shogukushas",
        "Entrapping2",
        "Tricksters",
        "Cunning",
        "Mentalists2",
        "Psychic",
        "Shadow",
        "Shogukushas2",
        "Senseis",
        "Kenshis",
        "Unused514",
        "Unused515",
        "Unused516",
        "Unused517",
        "Unused518",
        "Unused519",
        "Paleocene",
        "Paleocene2",
        "Unused520",
        "Unused521",
        "Unused522",
        "Unused523",
        "Trump",
        "Unused525",
        "Unused526",
        "Unused527",
        "Unused528",
        "Gritty",
        "Unused530",
        "Unused531",
        "Unused532",
        "Unused533",
        "Unused534",
        "Hawkeye",
        "Unused535",
        "Visionary",
        "Mnemonic",
        "Snowflake",
        "Shivering",
        "Boreal",
        "Hibernal",
        "Ember",
        "Smoldering",
        "Smoking",
        "Flaming",
        "Scorching",
        "Static",
        "Glowing3",
        "Buzzing",
        "Arcing",
        "Shocking",
        "Septic",
        "Envenomed",
        "Corosive",
        "Toxic",
        "Pestilent",
        "Maidens",
        "Valkyries",
        "Maidens2",
        "Valkyries2",
        "Monks2",
        "Priests3",
        "Monks3",
        "Priests4",
        "Monks4",
        "Priests5",
        "Summoners2",
        "Necromancers3",
        "Summoners3",
        "Necromancers4",
        "Angels2",
        "Arch3",
        "Angels3",
        "Arch4",
        "Slayers2",
        "Berserkers3",
        "Slayers3",
        "Berserkers4",
        "Slayers4",
        "Berserkers5",
        "Shamans",
        "Hierophants",
        "Shamans2",
        "Hierophants2",
        "Magekillers",
        "Witch",
        "Magekillers2",
        "Witch2",
        "Compact",
        "Thin",
        "Dense",
        "Consecrated",
        "Pure",
        "Sacred",
        "Hallowed",
        "Divine",
        "Pearl",
        "Crimson6",
        "Red",
        "Sanguinary",
        "Bloody",
        "Red2",
        "Sanguinary2",
        "Red3",
        "Jagged3",
        "Forked",
        "Serrated",
        "Jagged4",
        "Forked2",
        "Jagged5",
        "Snowflake2",
        "Shivering2",
        "Boreal2",
        "Hibernal2",
        "Snowflake3",
        "Shivering3",
        "Boreal3",
        "Hibernal3",
        "Snowflake4",
        "Shivering4",
        "Boreal4",
        "Hibernal4",
        "Ember2",
        "Smoldering2",
        "Smoking2",
        "Flaming2",
        "Ember3",
        "Smoldering3",
        "Smoking3",
        "Flaming3",
        "Ember4",
        "Smoldering4",
        "Smoking4",
        "Flaming4",
        "Static2",
        "Glowing4",
        "Arcing2",
        "Shocking2",
        "Static3",
        "Glowing5",
        "Arcing3",
        "Shocking3",
        "Static4",
        "Glowing6",
        "Arcing4",
        "Shocking4",
        "Septic2",
        "Envenomed2",
        "Toxic2",
        "Pestilent2",
        "Septic3",
        "Envenomed3",
        "Toxic3",
        "Pestilent3",
        "Septic4",
        "Envenomed4",
        "Toxic4",
        "Pestilent4",
        "Tireless4",
        "Lizards2",
        "Azure6",
        "Crimson7",
        "Tangerine7",
        "Beryl7",
        "Godly2",
		"Cruel2"
};