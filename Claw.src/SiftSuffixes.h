#pragma once

char* siftsuffixStr[] = 
{ //0 is unused, I'll use it for no affix
		"",
		"Health",
        "Protection",
        "Absorption",
        "Life",
        "Unused5",
        "Warding",
        "TheSentinel",
        "Guarding",
        "Negation",
        "Unused10",
        "Piercing",
        "Bashing",
        "Puncturing",
        "Thorns",
        "Spikes",
        "Readiness",
        "Alacrity",
        "Swiftness",
        "Quickness",
        "Blocking",
        "Deflecting",
        "TheApprentice",
        "TheMagus",
        "Frost",
        "TheGlacier",
        "Frost2",
        "Warmth3",
        "Flame",
        "Fire",
        "Burning",
        "Flame2",
        "Shock",
        "Lightning",
        "Thunder",
        "Shock2",
        "Craftsmanship",
        "Quality",
        "Maiming",
        "Slaying",
        "Gore",
        "Carnage",
        "Slaughter",
        "Maiming2",
        "Worth",
        "Measure",
        "Excellence",
        "Performance",
        "Measure2",
        "Blight",
        "Venom",
        "Pestilence",
        "Blight2",
        "Dexterity",
        "Dexterity2",
        "Skill",
        "Skill2",
        "Accuracy",
        "Precision",
        "Precision2",
        "Perfection",
        "Balance",
        "Stability",
        "Unused63",
        "Regeneration",
        "Regeneration2",
        "Regeneration3",
        "Regrowth",
        "Regrowth2",
        "Vileness",
        "Unused70",
        "Greed",
        "Wealth",
        "Chance",
        "Fortune",
        "Energy",
        "Energy2",
        "TheMind",
        "Brilliance",
        "Sorcery",
        "Wizardry",
        "TheBear",
        "Light",
        "Radiance",
        "TheSun",
        "Life2",
        "TheJackal",
        "TheFox",
        "TheWolf",
        "TheWolf2",
        "TheTiger",
        "TheMammoth",
        "TheMammoth2",
        "TheColosuss",
        "TheLeech",
        "TheLocust",
        "TheBat",
        "TheVampire",
        "Defiance",
        "Amelioration",
        "Remedy",
        "Unused101",
        "Simplicity",
        "Ease",
        "Unused104",
        "Strength",
        "Might",
        "TheOx",
        "TheOx2",
        "TheGiant",
        "TheGiant2",
        "TheTitan4",
        "Pacing",
        "Haste",
        "Speed",
        "Health2",
        "Protection2",
        "Absorption2",
        "Life3",
        "LifeEverlasting",
        "Protection3",
        "Absorption3",
        "Life4",
        "Anima",
        "Warding2",
        "TheSentinel2",
        "Guarding2",
        "Negation2",
        "TheSentinel3",
        "Guarding3",
        "Negation3",
        "Unused131",
        "Unused132",
        "Unused133",
        "Unused134",
        "Unused135",
        "Unused136",
        "Unused137",
        "Unused138",
        "Unused139",
        "Unused140",
        "Unused141",
        "Unused142",
        "Unused143",
        "Unused144",
        "Unused145",
        "Unused146",
        "Unused147",
        "Unused148",
        "Unused149",
        "Unused150",
        "Unused151",
        "Unused152",
        "Unused153",
        "Unused154",
        "Unused155",
        "Unused156",
        "Unused157",
        "Piercing2",
        "Unused158",
        "Unused159",
        "Thorns2",
        "Spikes2",
        "Razors",
        "Swords",
        "Malice",
        "Readiness2",
        "Alacrity2",
        "Swiftness2",
        "Quickness2",
        "Alacrity3",
        "Fervor",
        "Blocking2",
        "Deflecting2",
        "TheApprentice2",
        "TheMagus2",
        "Frost3",
        "TheIcicle",
        "TheGlacier2",
        "Winter",
        "Frost4",
        "Frigidity",
        "Warmth2",
        "Flame3",
        "Fire2",
        "Burning2",
        "Incineration",
        "Flame4",
        "Passion",
        "Shock3",
        "Lightning2",
        "Thunder2",
        "Storms",
        "Shock4",
        "Ennui",
        "Craftsmanship2",
        "Quality2",
        "Maiming3",
        "Slaying2",
        "Gore2",
        "Carnage2",
        "Slaughter2",
        "Butchery",
        "Evisceration",
        "Maiming4",
        "Craftsmanship3",
        "Craftsmanship4",
        "Craftsmanship5",
        "Quality3",
        "Quality4",
        "Maiming5",
        "Maiming6",
        "Unused212",
        "Unused213",
        "Unused214",
        "Unused215",
        "Unused216",
        "Unused217",
        "Unused218",
        "Unused219",
        "Ire",
        "Wrath",
        "Carnage3",
        "Worth2",
        "Measure3",
        "Excellence2",
        "Performance2",
        "Transcendence",
        "Worth3",
        "Measure4",
        "Excellence3",
        "Performance3",
        "Joyfulness",
        "Bliss",
        "Blight3",
        "Venom2",
        "Pestilence2",
        "Anthrax",
        "Blight4",
        "Envy",
        "Dexterity3",
        "Skill3",
        "Accuracy2",
        "Precision3",
        "Perfection2",
        "Nirvana",
        "Dexterity4",
        "Skill4",
        "Accuracy3",
        "Precision4",
        "Perfection3",
        "Dexterity5",
        "Skill5",
        "Accuracy4",
        "Precision5",
        "Dexterity6",
        "Dexterity7",
        "Dexterity8",
        "Dexterity9",
        "Dexterity10",
        "Dexterity11",
        "Daring",
        "Balance2",
        "Equilibrium",
        "Stability2",
        "Balance3",
        "Balance4",
        "Balance5",
        "Truth",
        "Regeneration4",
        "Regeneration5",
        "Regeneration6",
        "Regrowth3",
        "Regrowth4",
        "Revivification",
        "Honor",
        "Vileness2",
        "Greed2",
        "Wealth2",
        "Greed3",
        "Greed4",
        "Greed5",
        "Greed6",
        "Greed7",
        "Greed8",
        "Avarice",
        "Chance2",
        "Fortune3",
        "Fortune4",
        "Luck",
        "Fortune5",
        "GoodLuck",
        "Prosperity",
        "Energy3",
        "TheMind2",
        "Brilliance2",
        "Sorcery2",
        "Wizardry2",
        "Enlightenment",
        "Energy4",
        "TheMind3",
        "Brilliance3",
        "Sorcery3",
        "Wizardry3",
        "Energy5",
        "TheMind4",
        "Brilliance4",
        "Sorcery4",
        "Knowledge",
        "TheBear2",
        "Light2",
        "Radiance2",
        "TheSun2",
        "TheJackal2",
        "TheFox2",
        "TheWolf3",
        "TheTiger2",
        "TheMammoth3",
        "TheColosuss2",
        "TheSquid",
        "TheWhale",
        "TheJackal3",
        "TheFox3",
        "TheWolf4",
        "TheTiger3",
        "TheMammoth4",
        "TheColosuss3",
        "TheJackal4",
        "TheFox4",
        "TheWolf5",
        "TheTiger4",
        "TheMammoth5",
        "Life5",
        "Life6",
        "Life7",
        "Substinence",
        "Substinence2",
        "Substinence3",
        "Vita",
        "Vita2",
        "Vita3",
        "Life8",
        "Life9",
        "Substinence4",
        "Substinence5",
        "Vita4",
        "Vita5",
        "Life10",
        "Substinence6",
        "Vita6",
        "Spirit",
        "Hope",
        "TheLeech2",
        "TheLocust2",
        "TheLamprey",
        "TheLeech3",
        "TheLocust3",
        "TheLamprey2",
        "TheLeech4",
        "TheBat2",
        "TheWraith",
        "TheVampire2",
        "TheBat3",
        "TheWraith2",
        "TheVampire3",
        "TheBat4",
        "Defiance2",
        "Amelioration2",
        "Remedy2",
        "Simplicity2",
        "Ease2",
        "Freedom",
        "Strength2",
        "Might2",
        "TheOx3",
        "TheGiant3",
        "TheTitan2",
        "Atlus",
        "Strength3",
        "Might3",
        "TheOx4",
        "TheGiant4",
        "TheTitan3",
        "Strength4",
        "Might4",
        "TheOx5",
        "TheGiant5",
        "Strength5",
        "Strength6",
        "Strength7",
        "Strength8",
        "Strength9",
        "Strength10",
        "Virility",
        "Pacing2",
        "Haste2",
        "Speed2",
        "Traveling",
        "Acceleration",
        "Inertia",
        "Inertia2",
        "Inertia3",
        "Self",
        "FastRepair",
        "Ages",
        "Replenishing",
        "Propogation",
        "TheKraken",
        "Memory",
        "TheElephant",
        "Unused410",
        "Unused411",
        "Unused412",
        "Unused413",
        "Unused414",
        "Unused415",
        "Unused416",
        "Unused417",
        "Firebolts",
        "Firebolts2",
        "Firebolts3",
        "ChargedShield",
        "ChargedShield2",
        "ChargedShield3",
        "Icebolt",
        "Unused425",
        "Unused426",
        "Unused427",
        "FrostShield",
        "Unused429",
        "Unused430",
        "Unused431",
        "Nova",
        "Nova2",
        "NovaShield",
        "NovaShield2",
        "NovaShield3",
        "Lightning3",
        "Unused438",
        "Unused439",
        "Unused440",
        "Unused441",
        "ChainLightning",
        "ChainLightning2",
        "ChainLightning3",
        "Unused445",
        "Unused446",
        "Unused447",
        "Unused448",
        "Unused449",
        "Unused450",
        "Unused451",
        "Unused452",
        "Unused453",
        "HydraShield",
        "Unused455",
        "Unused456",
        "Unused457",
        "MagicArrows",
        "Unused459",
        "Unused460",
        "FireArrows",
        "InnerSight",
        "InnerSight2",
        "Unused464",
        "Unused465",
        "ColdArrows",
        "ColdArrows2",
        "MultipleShot",
        "MultipleShot2",
        "PowerStrike",
        "PowerStrike2",
        "Unused472",
        "Unused473",
        "ExplodingArrows",
        "ExplodingArrows2",
        "Unused476",
        "Unused477",
        "Unused478",
        "Unused479",
        "Unused480",
        "Unused481",
        "IceArrows",
        "IceArrows2",
        "Unused484",
        "Unused485",
        "ChargedStrike",
        "ChargedStrike2",
        "Unused488",
        "Unused489",
        "Unused490",
        "Unused491",
        "Unused492",
        "Unused493",
        "FreezingArrows",
        "FreezingArrows2",
        "LightningStrike",
        "LightningStrike2",
        "Unused498",
        "Unused499",
        "FireBolts",
        "FireBolts2",
        "ChargedBolts",
        "ChargedBolts2",
        "IceBolts",
        "IceBolts2",
        "Unused506",
        "Unused507",
        "Unused508",
        "Unused509",
        "Telekinesis",
        "Telekinesis2",
        "FrostNovas",
        "FrostNovas2",
        "IceBlasts",
        "IceBlasts2",
        "Unused516",
        "Unused517",
        "FireBalls",
        "FireBalls2",
        "Novas",
        "Novas2",
        "Lightning4",
        "Lightning5",
        "Unused524",
        "Unused525",
        "Unused526",
        "Unused527",
        "Enchantment",
        "Enchantment2",
        "ChainLightning4",
        "ChainLightning5",
        "Teleportation",
        "Teleportation2",
        "GlacialSpikes",
        "GlacialSpikes2",
        "Meteors",
        "Meteors2",
        "Unused538",
        "Unused539",
        "Unused540",
        "Unused541",
        "Blizzards",
        "Blizzards2",
        "Unused544",
        "Unused545",
        "Unused546",
        "Unused547",
        "FrozenOrbs",
        "FrozenOrbs2",
        "Unused550",
        "Unused551",
        "Teeth",
        "Teeth2",
        "Unused554",
        "Unused555",
        "Unused556",
        "Unused557",
        "DimVision",
        "DimVision2",
        "Weaken",
        "Weaken2",
        "PoisonDagger",
        "PoisonDagger2",
        "Unused564",
        "Unused565",
        "Unused566",
        "Unused567",
        "Unused568",
        "Unused569",
        "Terror",
        "Terror2",
        "Unused572",
        "Unused573",
        "Unused574",
        "Unused575",
        "Confusion",
        "Confusion2",
        "LifeTap",
        "LifeTap2",
        "Unused580",
        "Unused581",
        "BoneSpears",
        "BoneSpears2",
        "Unused584",
        "Unused585",
        "Attraction",
        "Attraction2",
        "Unused588",
        "Unused589",
        "Unused590",
        "Unused591",
        "Unused592",
        "Unused593",
        "LowerResistance",
        "LowerResistance2",
        "PoisonNovas",
        "PoisonNovas2",
        "BoneSpirits",
        "BoneSpirits2",
        "Unused600",
        "Unused601",
        "Unused602",
        "Unused603",
        "Sacrifice",
        "Sacrifice2",
        "HolyBolts",
        "HolyBolts2",
        "Zeal",
        "Zeal2",
        "Vengeance",
        "Vengeance2",
        "BlessedHammers",
        "BlessedHammers2",
        "Unused614",
        "Unused615",
        "Unused616",
        "Unused617",
        "Bashing2",
        "Bashing3",
        "Unused620",
        "Unused621",
        "Unused622",
        "Unused623",
        "Unused624",
        "Unused625",
        "Unused626",
        "Unused627",
        "Stunning",
        "Stunning2",
        "Unused630",
        "Unused631",
        "Concentration",
        "Concentration2",
        "Unused634",
        "Unused635",
        "Unused636",
        "Unused637",
        "GrimWard",
        "GrimWard2",
        "Unused640",
        "Unused641",
        "Unused642",
        "Unused643",
        "Firestorms",
        "Firestorms2",
        "Unused644",
        "Unused645",
        "Eruption",
        "Eruption2",
        "Unused650",
        "Unused651",
        "Twister",
        "Twister2",
        "Volcano",
        "Volcano2",
        "Tornado",
        "Tornado2",
        "Unused658",
        "Unused659",
        "Unused660",
        "Unused661",
        "DamageAmplification",
        "TheIcicle2",
        "TheGlacier3",
        "Fire3",
        "Burning3",
        "Lightning6",
        "Thunder3",
        "Daring2",
        "Daring3",
        "Knowledge2",
        "Knowledge3",
        "Virility2",
        "Virility3",
        "Readiness3",
        "Craftsmanship6",
        "Quality5",
        "Maiming7",
        "Craftsmanship7",
        "Quality6",
        "Craftsmanship8",
        "Blight5",
        "Venom3",
        "Pestilence3",
        "Anthrax2",
        "Blight6",
        "Venom4",
        "Pestilence4",
        "Anthrax3",
        "Blight7",
        "Venom5",
        "Pestilence5",
        "Anthrax4",
        "Frost5",
        "TheIcicle3",
        "TheGlacier4",
        "Winter2",
        "Frost6",
        "TheIcicle4",
        "TheGlacier5",
        "Winter3",
        "Frost7",
        "TheIcicle5",
        "TheGlacier6",
        "Winter4",
        "Flame5",
        "Fire4",
        "Burning4",
        "Incineration2",
        "Flame6",
        "Fire5",
        "Burning5",
        "Incineration3",
        "Flame7",
        "Fire6",
        "Burning6",
        "Incineration4",
        "Shock5",
        "Lightning7",
        "Thunder4",
        "Storms2",
        "Shock6",
        "Lightning8",
        "Thunder5",
        "Storms3",
        "Shock7",
        "Lightning9",
        "Thunder6",
        "Storms4",
        "Dexterity12",
        "Dexterity13",
        "Strength11",
        "Strength12",
        "Thorns3",
        "Frost8",
        "Flame8",
        "Blight8",
        "Shock8",
        "Regeneration7",
        "Energy6",
        "Light3",
        "TheLeech5",
        "TheLocust4",
        "TheLamprey3",
        "TheBat5",
        "TheWraith3",
        "TheVampire4"
};