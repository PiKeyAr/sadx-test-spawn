#pragma once

enum EventFlag
{
	SSVAR_EGG_ON = 0x40,
	FLAG_SONIC_PLAYABLE = 0x41,
	FLAG_MILES_PLAYABLE = 0x42,
	FLAG_KNUCKLES_PLAYABLE = 0x43,
	FLAG_AMY_PLAYABLE = 0x44,
	FLAG_E102_PLAYABLE = 0x45,
	FLAG_BIG_PLAYABLE = 0x46,
	FLAG_SUPERSONIC_PLAYABLE = 0x47,
	FLAG_SONIC_COMPLETE = 0x48,
	FLAG_MILES_COMPLETE = 0x49,
	FLAG_KNUCKLES_COMPLETE = 0x4A,
	FLAG_AMY_COMPLETE = 0x4B,
	FLAG_E102_COMPLETE = 0x4C,
	FLAG_BIG_COMPLETE = 0x4D,
	FLAG_SUPERSONIC_COMPLETE = 0x4E,
	FLAG_GET_GOLDEGG = 0x4F,
	FLAG_GET_SILVEREGG = 0x50,
	FLAG_GET_BLACKEGG = 0x51,
	FLAG_SONIC_CHAO_GARDEN = 0x52,
	FLAG_MILES_CHAO_GARDEN = 0x53,
	FLAG_KNUCKLES_CHAO_GARDEN = 0x54,
	FLAG_AMY_CHAO_GARDEN = 0x55,
	FLAG_E102_CHAO_GARDEN = 0x56,
	FLAG_BIG_CHAO_GARDEN = 0x57,
	FLAG_PLAYING_SUPERSONIC = 0x58,
	FLAG_METALSONIC_PLAYABLE = 0x59,
	FLAG_SONIC_SS_BARRICADE = 0x80,
	FLAG_SONIC_SS_HOTEL_FRONT = 0x81,
	FLAG_SONIC_SS_STATION_FRONT = 0x82,
	FLAG_SONIC_SS_ENTRANCE_SEWER = 0x83,
	FLAG_SONIC_SS_EXIT_SEWER = 0x84,
	FLAG_SONIC_SS_ICESTONE = 0x85,
	FLAG_SONIC_SS_HOTEL_BACK = 0x86,
	FLAG_SONIC_SS_ENTRANCE_CASINO = 0x87,
	FLAG_SONIC_SS_STATION_BACK = 0x88,
	FLAG_SONIC_SS_TPARK_ELEVATOR = 0x89,
	FLAG_SONIC_SS_ENTRANCE_CIRCUIT = 0x8A,
	FLAG_SONIC_SS_CARD = 0x8B,
	FLAG_SONIC_SS_ENTRANCE_HIGHWAY = 0x8C,
	FLAG_SONIC_SS_LIGHTSHOOSE = 0x8D,
	FLAG_SONIC_SS_CRYSTALRING = 0x8E,
	FLAG_SONIC_EC_MONORAIL = 0x8F,
	FLAG_SONIC_EC_EGGLIFT = 0x90,
	FLAG_SONIC_EC_TRANSFORM = 0x91,
	FLAG_SONIC_EC_TORNADO2_LOST = 0x92,
	FLAG_SONIC_EC_SINK = 0x93,
	FLAG_SONIC_MR_WINDYSTONE = 0x94,
	FLAG_SONIC_MR_ENTRANCE_WINDY = 0x95,
	FLAG_SONIC_MR_WESTROCK = 0x96,
	FLAG_SONIC_MR_ICESTONE = 0x97,
	FLAG_SONIC_MR_ENTRANCE_ICECAP = 0x98,
	FLAG_SONIC_MR_ENTRANCE_MOUNTAIN = 0x99,
	FLAG_SONIC_MR_ISLANDDOOR = 0x9A,
	FLAG_SONIC_MR_TRUCK = 0x9B,
	FLAG_SONIC_MR_ENTRANCE_RUIN = 0x9C,
	FLAG_SONIC_MR_APPEAR_FINALEGG = 0x9D,
	FLAG_SONIC_MR_ENTRANCE_SANDBOARD = 0x9E,
	FLAG_SONIC_MR_ANCIENT_LIGHT = 0x9F,
	FLAG_SONIC_MR_ENTRANCE_FINALEGG = 0xA0,
	FLAG_SONIC_TRAIN = 0xA1,
	FLAG_SONIC_BOAT = 0xA2,
	FLAG_SONIC_RAFT = 0xA3,
	FLAG_SONIC_MBOSS_E102 = 0xA4,
	FLAG_SONIC_MBOSS_KNUCKLES = 0xA5,
	FLAG_SONIC_CLEAR_BEACH = 0xA6,
	FLAG_SONIC_CLEAR_WINDY = 0xA7,
	FLAG_SONIC_CLEAR_CASINO = 0xA8,
	FLAG_SONIC_CLEAR_TWINKLEPARK = 0xA9,
	FLAG_SONIC_CLEAR_HIGHWAY = 0xAA,
	FLAG_SONIC_CLEAR_MOUNTAIN = 0xAB,
	FLAG_SONIC_CLEAR_SNOW = 0xAC,
	FLAG_SONIC_CLEAR_SKYDECK = 0xAD,
	FLAG_SONIC_CLEAR_RUIN = 0xAE,
	FLAG_SONIC_CLEAR_FINALEGG = 0xAF,
	FLAG_SONIC_CLEAR_CHAOS0 = 0xB0,
	FLAG_SONIC_CLEAR_CHAOS4 = 0xB1,
	FLAG_SONIC_CLEAR_CHAOS6 = 0xB2,
	FLAG_SONIC_CLEAR_EGGMOBILE1 = 0xB3,
	FLAG_SONIC_CLEAR_EGGMOBILE3 = 0xB4,
	FLAG_SONIC_CLEAR_SHOOTING = 0xB5,
	FLAG_SONIC_CLEAR_SHOOTING2 = 0xB6,
	FLAG_SONIC_ARRIVE_IN_SS = 0xB7,
	FLAG_SONIC_ARRIVE_IN_EC = 0xB8,
	FLAG_SONIC_ARRIVE_IN_MR = 0xB9,
	FLAG_MILES_SS_BARRICADE = 0xC0,
	FLAG_MILES_SS_HOTEL_FRONT = 0xC1,
	FLAG_MILES_SS_HOTEL_BACK = 0xC2,
	FLAG_MILES_SS_HOTEL_POOL = 0xC3,
	FLAG_MILES_SS_ICESTONE = 0xC4,
	FLAG_MILES_SS_ENTRANCE_CASINO = 0xC5,
	FLAG_MILES_SS_ENTRANCE_HIGHWAY = 0xC6,
	FLAG_MILES_SS_TPARK_ELEVATOR = 0xC7,
	FLAG_MILES_SS_ENTRANCE_CIRCUIT = 0xC8,
	FLAG_MILES_SS_CARTPASSPORT = 0xC9,
	FLAG_MILES_SS_STATION_FRONT = 0xCA,
	FLAG_MILES_SS_STATION_BACK = 0xCB,
	FLAG_MILES_SS_HOTELSWITCH = 0xCC,
	FLAG_MILES_SS_JETANKLET = 0xCD,
	FLAG_MILES_EC_MONORAIL = 0xCE,
	FLAG_MILES_EC_EGGLIFT = 0xCF,
	FLAG_MILES_EC_TRANSFORM = 0xD0,
	FLAG_MILES_EC_TORNADO2_LOST = 0xD1,
	FLAG_MILES_EC_SINK = 0xD2,
	FLAG_MILES_MR_WINDYSTONE = 0xD3,
	FLAG_MILES_MR_ENTRANCE_WINDY = 0xD4,
	FLAG_MILES_MR_WESTROCK = 0xD5,
	FLAG_MILES_MR_ICESTONE = 0xD6,
	FLAG_MILES_MR_ENTRANCE_ICECAP = 0xD7,
	FLAG_MILES_MR_TRUCK = 0xD8,
	FLAG_MILES_MR_ENTRANCE_RUIN = 0xD9,
	FLAG_MILES_MR_ENTRANCE_SANDBOARD = 0xDA,
	FLAG_MILES_MR_RHYTHMBROOCH = 0xDB,
	FLAG_MILES_TRAIN = 0xDC,
	FLAG_MILES_BOAT = 0xDD,
	FLAG_MILES_RAFT = 0xDE,
	FLAG_MILES_MBOSS_E102 = 0xDF,
	FLAG_MILES_MBOSS_KNUCKLES = 0xE0,
	FLAG_MILES_CLEAR_WINDY = 0xE1,
	FLAG_MILES_CLEAR_CASINO = 0xE2,
	FLAG_MILES_CLEAR_HIGHWAY = 0xE3,
	FLAG_MILES_CLEAR_SNOW = 0xE4,
	FLAG_MILES_CLEAR_SKYDECK = 0xE5,
	FLAG_MILES_CLEAR_SANDBOARD = 0xE6,
	FLAG_MILES_CLEAR_CHAOS4 = 0xE7,
	FLAG_MILES_CLEAR_EGGMOBILE2 = 0xE8,
	FLAG_MILES_CLEAR_EGGMOBILE1 = 0xE9,
	FLAG_MILES_CLEAR_SHOOTING = 0xEA,
	FLAG_MILES_CLEAR_SHOOTING2 = 0xEB,
	FLAG_MILES_CLEAR_BEACH = 0xEC,
	FLAG_MILES_CLEAR_MOUNTAIN = 0xED,
	FLAG_MILES_ARRIVE_IN_SS = 0xEE,
	FLAG_MILES_ARRIVE_IN_EC = 0xEF,
	FLAG_MILES_ARRIVE_IN_MR = 0xF0,
	FLAG_KNUCKLES_SS_BARRICADE = 0x100,
	FLAG_KNUCKLES_SS_HOTEL_FRONT = 0x101,
	FLAG_KNUCKLES_SS_HOTEL_BACK = 0x102,
	FLAG_KNUCKLES_SS_ENTRANCE_CASINO = 0x103,
	FLAG_KNUCKLES_SS_ENTRANCE_HIGHWAY = 0x104,
	FLAG_KNUCKLES_SS_TPARK_ELEVATOR = 0x105,
	FLAG_KNUCKLES_SS_ENTRANCE_CIRCUIT = 0x106,
	FLAG_KNUCKLES_SS_CARTPASSPORT = 0x107,
	FLAG_KNUCKLES_SS_STATION_FRONT = 0x108,
	FLAG_KNUCKLES_SS_STATION_BACK = 0x109,
	FLAG_KNUCKLES_EC_MONORAIL = 0x10A,
	FLAG_KNUCKLES_EC_EGGLIFT = 0x10B,
	FLAG_KNUCKLES_EC_TRANSFORM = 0x10C,
	FLAG_KNUCKLES_EC_PALMSWITCH = 0x10D,
	FLAG_KNUCKLES_EC_TORNADO2_LOST = 0x10E,
	FLAG_KNUCKLES_EC_SINK = 0x10F,
	FLAG_KNUCKLES_MR_ENTRANCE_MOUNTAIN = 0x110,
	FLAG_KNUCKLES_MR_WESTROCK = 0x111,
	FLAG_KNUCKLES_MR_ISLANDDOOR = 0x112,
	FLAG_KNUCKLES_MR_MONKEYDOOR = 0x113,
	FLAG_KNUCKLES_MR_TRUCK = 0x114,
	FLAG_KNUCKLES_MR_REDCUBE = 0x115,
	FLAG_KNUCKLES_MR_BLUECUBE = 0x116,
	FLAG_KNUCKLES_MR_ENTRANCE_RUIN = 0x117,
	FLAG_KNUCKLES_MR_APPEAR_FINALEGG = 0x118,
	FLAG_KNUCKLES_MR_SHOVELCLAW = 0x119,
	FLAG_KNUCKLES_MR_FIGHTINGGROVE = 0x11A,
	FLAG_KNUCKLES_TRAIN = 0x11B,
	FLAG_KNUCKLES_BOAT = 0x11C,
	FLAG_KNUCKLES_RAFT = 0x11D,
	FLAG_KNUCKLES_MBOSS_SONIC = 0x11E,
	FLAG_KNUCKLES_CLEAR_CASINO = 0x11F,
	FLAG_KNUCKLES_CLEAR_HIGHWAY = 0x120,
	FLAG_KNUCKLES_CLEAR_MOUNTAIN = 0x121,
	FLAG_KNUCKLES_CLEAR_RUIN = 0x122,
	FLAG_KNUCKLES_CLEAR_CHAOS2 = 0x123,
	FLAG_KNUCKLES_CLEAR_CHAOS6 = 0x124,
	FLAG_KNUCKLES_CLEAR_CHAOS4 = 0x125,
	FLAG_KNUCKLES_CLEAR_SKYDECK = 0x126,
	FLAG_KNUCKLES_ARRIVE_IN_SS = 0x127,
	FLAG_KNUCKLES_ARRIVE_IN_EC = 0x128,
	FLAG_KNUCKLES_ARRIVE_IN_MR = 0x129,
	FLAG_KNUCKLES_MR_MONKEYDOOR_ENTER = 0x12A,
	FLAG_KNUCKLES_MR_MONKEYCAGEA_BOMB = 0x12B,
	FLAG_KNUCKLES_SS_ENTRANCE_CHAOS2 = 0x12C,
	FLAG_AMY_SS_HOTEL_FRONT = 0x140,
	FLAG_AMY_SS_HOTEL_BACK = 0x141,
	FLAG_AMY_SS_HOTEL_POOL = 0x142,
	FLAG_AMY_SS_ENTRANCE_CASINO = 0x143,
	FLAG_AMY_SS_TPARK_ELEVATOR = 0x144,
	FLAG_AMY_SS_ENTRANCE_CIRCUIT = 0x145,
	FLAG_AMY_SS_STATION_FRONT = 0x146,
	FLAG_AMY_SS_STATION_BACK = 0x147,
	FLAG_AMY_EC_MONORAIL = 0x148,
	FLAG_AMY_EC_EGGLIFT = 0x149,
	FLAG_AMY_EC_TRANSFORM = 0x14A,
	FLAG_AMY_EC_MOGURATATAKI = 0x14B,
	FLAG_AMY_EC_TORNADO2_LOST = 0x14C,
	FLAG_AMY_EC_SINK = 0x14D,
	FLAG_AMY_MR_ISLANDDOOR = 0x14E,
	FLAG_AMY_MR_TRUCK = 0x14F,
	FLAG_AMY_MR_APPEAR_FINALEGG = 0x150,
	FLAG_AMY_MR_ENTRANCE_FINALEGG = 0x151,
	FLAG_AMY_MR_FIGHTERSFEATHER = 0x152,
	FLAG_AMY_TRAIN = 0x153,
	FLAG_AMY_BOAT = 0x154,
	FLAG_AMY_RAFT = 0x155,
	FLAG_AMY_CLEAR_TWINKLEPARK = 0x156,
	FLAG_AMY_CLEAR_HOTSHELTER = 0x157,
	FLAG_AMY_CLEAR_FINALEGG = 0x158,
	FLAG_AMY_CLEAR_ZERO = 0x159,
	FLAG_AMY_EC_1STVISIT = 0x15A,
	FLAG_AMY_ARRIVE_IN_SS = 0x15B,
	FLAG_AMY_ARRIVE_IN_EC = 0x15C,
	FLAG_AMY_ARRIVE_IN_MR = 0x15D,
	FLAG_AMY_EC_LONGHAMMER = 0x15E,
	FLAG_E102_SS_HOTEL_FRONT = 0x180,
	FLAG_E102_SS_HOTEL_POOL = 0x181,
	FLAG_E102_SS_STATION_FRONT = 0x182,
	FLAG_E102_SS_TPARK_ELEVATOR = 0x183,
	FLAG_E102_SS_ENTRANCE_CIRCUIT = 0x184,
	FLAG_E102_SS_CARTPASSPORT = 0x185,
	FLAG_E102_EC_MONORAIL = 0x186,
	FLAG_E102_EC_EGGLIFT = 0x187,
	FLAG_E102_EC_TRANSFORM = 0x188,
	FLAG_E102_EC_BOOSTER = 0x189,
	FLAG_E102_EC_TYPE3LASER = 0x18A,
	FLAG_E102_EC_TORNADO2_LOST = 0x18B,
	FLAG_E102_EC_SINK = 0x18C,
	FLAG_E102_EC_HOTSHELTER = 0x18D,
	FLAG_E102_MR_GOODSCORE = 0x18E,
	FLAG_E102_MR_FREEPASS = 0x18F,
	FLAG_E102_MR_WINDYSTONE = 0x190,
	FLAG_E102_MR_ENTRANCE_WINDY = 0x191,
	FLAG_E102_MR_WESTROCK = 0x192,
	FLAG_E102_MR_ENTRANCE_MOUNTAIN = 0x193,
	FLAG_E102_MR_ISLANDDOOR = 0x194,
	FLAG_E102_MR_TRUCK = 0x195,
	FLAG_E102_MR_APPEAR_FINALEGG = 0x196,
	FLAG_E102_TRAIN = 0x197,
	FLAG_E102_BOAT = 0x198,
	FLAG_E102_RAFT = 0x199,
	FLAG_E102_MBOSS_SONIC = 0x19A,
	FLAG_E102_CLEAR_BEACH = 0x19B,
	FLAG_E102_CLEAR_WINDY = 0x19C,
	FLAG_E102_CLEAR_MOUNTAIN = 0x19D,
	FLAG_E102_CLEAR_HOTSHELTER = 0x19E,
	FLAG_E102_CLEAR_FINALEGG = 0x19F,
	FLAG_E102_CLEAR_E101 = 0x1A0,
	FLAG_E102_CLEAR_E101R = 0x1A1,
	FLAG_E102_ARRIVE_IN_SS = 0x1A2,
	FLAG_E102_ARRIVE_IN_EC = 0x1A3,
	FLAG_E102_ARRIVE_IN_MR = 0x1A4,
	FLAG_BIG_SS_HOTEL_FRONT = 0x1C0,
	FLAG_BIG_SS_HOTEL_BACK = 0x1C1,
	FLAG_BIG_SS_TPARK_ELEVATOR = 0x1C2,
	FLAG_BIG_SS_ENTRANCE_CIRCUIT = 0x1C3,
	FLAG_BIG_SS_STATION_FRONT = 0x1C4,
	FLAG_BIG_SS_ICESTONE = 0x1C5,
	FLAG_BIG_SS_HOTEL_POOL = 0x1C6,
	FLAG_BIG_EC_MONORAIL = 0x1C7,
	FLAG_BIG_EC_EGGLIFT = 0x1C8,
	FLAG_BIG_EC_TRANSFORM = 0x1C9,
	FLAG_BIG_EC_TORNADO2_LOST = 0x1CA,
	FLAG_BIG_EC_SINK = 0x1CB,
	FLAG_BIG_MR_WESTROCK = 0x1CC,
	FLAG_BIG_MR_ICESTONE = 0x1CD,
	FLAG_BIG_MR_ENTRANCE_ICECAP = 0x1CE,
	FLAG_BIG_MR_TRUCK = 0x1CF,
	FLAG_BIG_MR_LIFEBELT = 0x1D0,
	FLAG_BIG_MR_POWERROD = 0x1D1,
	FLAG_BIG_TRAIN = 0x1D2,
	FLAG_BIG_BOAT = 0x1D3,
	FLAG_BIG_RAFT = 0x1D4,
	FLAG_BIG_CLEAR_BEACH = 0x1D5,
	FLAG_BIG_CLEAR_HOTSHELTER = 0x1D6,
	FLAG_BIG_CLEAR_TWINKLEPARK = 0x1D7,
	FLAG_BIG_CLEAR_SNOW = 0x1D8,
	FLAG_BIG_CLEAR_CHAOS6 = 0x1D9,
	FLAG_BIG_ARRIVE_IN_SS = 0x1DA,
	FLAG_BIG_ARRIVE_IN_EC = 0x1DB,
	FLAG_BIG_ARRIVE_IN_MR = 0x1DC,
	FLAG_BIG_ARRIVE_IN_SEWER = 0x1DD,
	FLAG_BIG_RUAR_BLUE = 0x1DE,
	FLAG_BIG_RUAR_GOLD = 0x1DF,
	FLAG_BIG_RUAR_NORMAL = 0x1E0,
	FLAG_BIG_RUAR_RED = 0x1E1,
	FLAG_BIG_RUAR_SILVER = 0x1E2,
	FLAG_EVENT_HINTBOX_DISP = 0x1E3,
	FLAG_EVENT_NPC_DISP = 0x1E4,
	FLAG_ALL_LAST = 0x1E5,
};

struct AdventureData_
{
	char TimeOfDay;
	char emerald;
	__int16 seqno;
	__int16 seq;
	__int16 nextsec;
	unsigned __int16 stage;
	unsigned __int16 destination;
};

struct SceneSelectData_
{
	void* Code;
	char Level;
	char Act;
	__int16 Entrance;
	char Name[32];
};

struct __declspec(align(4)) TitleNewWk
{
	char Stat;
	char PrevMode;
	char NextMode;
	float BaseZ;
	float T;
	unsigned int BaseCol;
	char SubMode;
	EntityData1* AlertTsk;
	char VMStatAll;
	int titletimer;
	unsigned int titleblinktimer;
	EntityData1* CamTskPtr;
	unsigned int wavetimer;
	unsigned int logotimer;
	int bBgmEnabled;
	unsigned int movetimer;
	float kumotimer;
	char kumoindex;
};

struct DemoData
{
	__int16 level;
	__int16 act;
	__int16 character;
	__int16 cutscene;
};

struct CutsceneLevelData
{
	int cutscene_id;
	int level;
	int act;
	int character;
	char scene_select;
};

CutsceneLevelData CutsceneList[] = {
	//Sonic events
	{ 0x001, 26, 3, 0, 0 }, //Sonic Intro
	{ 0x002, 15, 0, 0, 0 }, //Sonic defeats Chaos 0
	{ 0x003, 26, 4, 0, 1 }, //Sonic sees Tails crash
	{ 0x006, 26, 4, 0, 1 }, //Sonic and Tails poolside
	{ 0x007, 33, 0, 0, 2 }, //Sonic faces off with the Egg Hornet
	{ 0x008, 33, 0, 0, 2 }, //Chaos 1 Emerges
	{ 0x009, 26, 1, 0, 0 }, //Sonic and Tails are gassed
	{ 0x00B, 33, 0, 0, 5 }, //Chaos 4 Transformation
	{ 0x00C, 33, 0, 0, 5 }, //Sonic and Tails part ways with Knuckles
	{ 0x00D, 33, 0, 0, 5 }, //Tornado 1 Lift Off Cutscene
	{ 0x011, 26, 4, 0, 6 }, //Sonic falling into Station Square
	{ 0x012, 26, 1, 0, 6 }, //Amy finds Sonic
	{ 0x013, 26, 3, 0, 7 }, //Amy and Sonic go to Twinkle Park
	{ 0x014, 26, 5, 0, 8 }, //Sonic goes looking for Amy
	{ 0x015, 26, 1, 0, 9 }, //Sonic finds Zero and Amy
	{ 0x016, 33, 0, 0, 9 }, //Zero transported to the Egg Carrier
	{ 0x017, 5,  1, 0, 9 }, //Sonic and Tails on the Tornado 2
	{ 0x01A, 29, 2, 0, 10 }, //Eggman takes Birdie's Emerald
	{ 0x01B, 29, 2, 0, 10 }, //Sonic goes to put Eggman out of commission
	{ 0x01C, 18, 0, 0, 11 }, //Sonic finds Chaos 6
	{ 0x01D, 18, 0, 0, 12 }, //Sonic chases Eggman to the Mystic Ruins
	{ 0x01E, 33, 2, 0, 12 }, //Sonic prepares to enter Lost World
	{ 0x020, 7,  2, 0, 12 }, //Sonic views the Perfect Chaos Mural
	{ 0x021, 34, 2, 0, 13 }, //Sonic enters the Past
	{ 0x022, 34, 2, 0, 13 }, //Sonic listens to Tikal in the Past
	{ 0x023, 33, 2, 0, 14 }, //Sonic sees Eggman heading to his base
	{ 0x024, 22, 0, 0, 14 }, //Sonic's Final Battle with Eggman
	{ 0x026, 33, 0, 0, 1 }, //Sonic's Outro
	{ 0x028, 33, 0, 0, 5 }, //Sonic vs. Knuckles
	{ 0x029, 29, 0, 0, 10 }, //Tornado 2 lands on the Egg Carrier
	{ 0x02A, 26, 1, 0, 4 }, //Sonic and Tails awaken after being gassed
	{ 0x02B, 15, 0, 0, 0 }, //Sonic meets Chaos 0
	//Tails events
	{ 0x030, 26, 3, 2, 0 }, //Tails Intro
	{ 0x031, 1,  1, 2, 0 }, //Tails is rescued by Sonic
	{ 0x032, 26, 4, 2, 0 }, //Tails and Sonic poolside
	{ 0x033, 33, 0, 2, 1 }, //Tails faces off with Egg Hornet
	{ 0x034, 33, 0, 2, 1 }, //Chaos 1 Emerges
	{ 0x035, 26, 1, 2, 2 }, //Tails and Sonic are gassed at Casinopolis - broken
	{ 0x038, 33, 0, 2, 4 }, //Tails vs. Knuckles
	{ 0x039, 33, 0, 2, 4 }, //Chaos 4 Emerges
	{ 0x03A, 33, 0, 2, 4 }, //Tails and Sonic follow Eggman after Chaos 4
	{ 0x03B, 33, 0, 2, 4 }, //Tails and Sonic depart on the Tornado 1
	{ 0x03E, 33, 2, 2, 5 }, //Tails' flashback
	{ 0x040, 33, 0, 2, 6 }, //Tails wakes up from his dream
	{ 0x042, 33, 2, 2, 6 }, //Tails chases Froggy
	{ 0x044, 34, 0, 2, 6 }, //Tails enters the Past
	{ 0x045, 34, 0, 2, 6 }, //Tails talks to Tikal
	{ 0x046, 33, 0, 2, 7 }, //Tails returns and meets Big
	{ 0x047, 33, 0, 2, 7 }, //The Tornado 2 takes flight
	{ 0x048, 5,  1, 2, 7 }, //Tails finds Sonic in Red Mountain
	{ 0x04B, 29, 2, 2, 8 }, //Tails faces off with Gamma
	{ 0x04C, 29, 2, 2, 9 }, //Tails departs the Egg Carrier with Amy
	{ 0x04D, 26, 3, 2, 10 }, //Eggman launches his missile attack
	{ 0x04E, 26, 3, 2, 10 }, //Tails follows Eggman after the missile
	{ 0x050, 26, 1, 2, 11 }, //Tails takes on the Egg Walker
	{ 0x051, 26, 1, 2, 11 }, //Egg Walker defeated, Station Square saved
	{ 0x052, 33, 0, 2, 0 }, //Tails Outro
	{ 0x053, 26, 0, 2, -1 }, //Error
	{ 0x054, 29, 1, 2, 8 }, //Gonna land on the Egg Carrier
	{ 0x055, 38, 0, 2, 6 }, //Cutscene with Froggy after Sand Hill
	{ 0x056, 26, 1, 2, 3 }, //Tails and Sonic awake after being gassed
	//Amy events
	{ 0x058, 26, 0, 5, 0 }, //Amy's pre-intro ??
	{ 0x060, 26, 0, 5, 0 }, //Amy's intro
	{ 0x061, 26, 0, 5, 0 }, //Amy meets Birdie
	{ 0x062, 26, 1, 5, 1 }, //Amy meets up with Sonic
	{ 0x063, 26, 3, 5, 1 }, //Amy and Sonic visit Twinkle Park
	{ 0x064, 26, 3, 5, 2 }, //Amy's kidnapped by Zero
	{ 0x065, 32, 3, 5, 2 }, //Amy locked up, talking to Gamma
	{ 0x066, 12, 1, 5, 2 }, //Amy goes to the past after Hot Shelter
	{ 0x067, 34, 0, 5, 3 }, //Amy enters the past
	{ 0x068, 34, 1, 5, 3 }, //Amy meets Tikal
	{ 0x069, 29, 2, 5, 4 }, //Eggman takes Birdie's Emerald
	{ 0x06A, 29, 2, 5, 4 }, //Amy and Tails leave the Egg Carrier
	{ 0x06B, 26, 0, 5, -1 }, //Error
	{ 0x06C, 29, 5, 5, 3 }, //Amy returns to the present
	{ 0x06D, 26, 3, 5, 5 }, //Hunt to find Birdie's family
	{ 0x06E, 33, 2, 5, 6 }, //Amy discovers the Egg Base
	{ 0x06F, 10, 0, 5, 6 }, //Amy chased by Zero in Final Egg
	{ 0x070, 33, 3, 5, 7 }, //Amy and Birdie head back to the Egg Carrier
	{ 0x071, 23, 0, 5, 8 }, //Zero confronts Amy
	{ 0x072, 29, 0, 5, 8 }, //Amy's Outro
	{ 0x075, 26, 1, 5, 2 }, //Amy's kidnapped to the Mystic Ruins
	//Knuckles events
	{ 0x080, 33, 1, 3, 0 }, //Knuckles Intro
	{ 0x082, 26, 3, 3, 1 }, //Knuckles goes hunting for the Master Emerald
	{ 0x083, 9,  0, 3, 2 }, //Knuckles enters the Past
	{ 0x084, 34, 0, 3, 2 }, //Knuckles while in the Past
	{ 0x085, 34, 0, 3, 2 }, //Tikal's Crisis
	{ 0x086, 26, 1, 3, 2 }, //Knuckles returns from the Past
	{ 0x087, 26, 4, 3, 3 }, //Knuckles and Chaos 2 face off
	{ 0x088, 16, 0, 3, 3 }, //Eggman tricks Knuckles
	{ 0x089, 33, 0, 3, 3 }, //Knuckles goes after Sonic
	{ 0x08A, 33, 0, 3, 4 }, //Knuckles vs. Sonic
	{ 0x08B, 33, 0, 3, 4 }, //Chaos 4 emerges
	{ 0x08C, 33, 0, 3, 4 }, //Knuckles departs from Sonic and Tails
	{ 0x08D, 7,  1, 3, 5 }, //Knuckles goes to the Past (from Lost World)
	{ 0x08E, 34, 1, 3, 5 }, //Knuckles back in the Past
	{ 0x08F, 34, 1, 3, 5 }, //Tikal's crisis again
	{ 0x091, 33, 1, 3, 6 }, //Knuckles restores most of the Master Emerald
	{ 0x092, 33, 2, 3, 6 }, //Knuckles follows Gamma to Final Egg base
	{ 0x094, 29, 0, 3, 6 }, //Knuckles on the Egg Carrier
	{ 0x095, 6,  2, 3, 7 }, //Knuckles finds the last missing piece
	{ 0x096, 34, 2, 3, 8 }, //Knuckles travels back to the past one last time
	{ 0x097, 34, 2, 3, 8 }, //The aftermath of Tikal's plight
	{ 0x098, 29, 5, 3, 8 }, //Knuckles returns to the present
	{ 0x099, 18, 1, 3, 9 }, //Knuckles fights Chaos 6
	{ 0x09A, 29, 0, 3, 9 }, //Knuckles has all collected the final shards
	{ 0x09B, 18, 1, 3, 9 }, //Knuckles defeats Chaos 6
	{ 0x09C, 26, 0, 3, -1 }, //Error
	{ 0x09D, 33, 1, 3, 10 }, //Knuckles restores the Master Emerald
	{ 0x09F, 33, 1, 3, 10 }, //Knuckles Outro
	{ 0x0A0, 26, 4, 3, 1 }, //Knuckles follows Eggman in Station Square hotel
	//Gamma events
	{ 0x0B0, 33, 3, 6, 0 }, //Gamma Intro
	{ 0x0B1, 33, 3, 6, 1 }, //Gamma Enters Final Egg
	{ 0x0B2, 33, 3, 6, 1 }, //Gamma Exits Final Egg
	{ 0x0B3, 33, 3, 6, 1 }, //Useless machine
	{ 0x0B4, 33, 3, 6, 1 }, //Gamma's Fight with Beta
	{ 0x0B5, 33, 3, 6, 1 }, //Gamma defeats Beta
	{ 0x0B7, 32, 1, 6, 2 }, //The hunt for Froggy begins
	{ 0x0B8, 1,  0, 6, 2 }, //Gamma goes to the Past
	{ 0x0B9, 34, 1, 6, 3 }, //Gamma in the Past
	{ 0x0BA, 34, 1, 6, 3 }, //Gamma and Tikal meet
	{ 0x0BB, 32, 1, 6, 3 }, //Gamma returns to the Egg Carrier
	{ 0x0BC, 32, 1, 6, 4 }, //Gamma goes to the wrong room
	{ 0x0BD, 32, 1, 6, 4 }, //Beta's new body being built
	{ 0x0BE, 32, 1, 6, 4 }, //Gamma leaves Beta's room
	{ 0x0BF, 32, 3, 6, 4 }, //Gamma enters the jail, meets Amy
	{ 0x0C0, 32, 1, 6, 4 }, //Gamma heading to the rear of the ship
	{ 0x0C1, 29, 2, 6, 4 }, //Gamma emerges to fight Sonic
	{ 0x0C2, 29, 2, 6, 4 }, //Gamma after the battle with Sonic
	{ 0x0C3, 33, 0, 6, 5 }, //Gamma's objectives changed (wtf?)
	//{ 0x0C4, 0, 0 }, //Doesn't exist in SADX
	{ 0x0C5, 33, 1, 6, 7 }, //Gamma remembers his brothers
	{ 0x0C7, 25, 0, 6, 8 }, //Gamma Outro
	//Big events
	{ 0x0D0, 33, 2, 7, 0 }, //Big Intro
	{ 0x0D1, 26, 3, 7, 0 }, //Big goes searching for Froggy
	{ 0x0D2, 26, 0, 7, 1 }, //Froggy heads into the sewers
	{ 0x0D3, 33, 0, 7, 0 }, //Big finds Froggy with Tails
	{ 0x0D4, 1,  2, 7, 3 }, //Big loses Froggy to Gamma
	{ 0x0D8, 32, 1, 7, 4 }, //Big enters Hot Shelter
	{ 0x0D9, 12, 0, 7, 4 }, //Big spots Froggy inside the tanks
	{ 0x0DA, 12, 0, 7, 4 }, //Big saves Froggy - brokent
	{ 0x0DB, 34, 1, 7, 5 }, //Big heads into the past
	{ 0x0DC, 34, 1, 7, 5 }, //Tikal talks to Big
	{ 0x0DD, 32, 1, 7, 5 }, //Big returns and is ready to leave the Egg Carrier
	{ 0x0DE, 18, 0, 7, 6 }, //Chaos 6 takes Froggy
	{ 0x0DF, 18, 0, 7, 6 }, //Sonic saves Froggy
	{ 0x0E0, 29, 0, 7, 6 }, //Big finds the Tornado 2 and leaves
	{ 0x0E1, 26, 0, 7, -1 }, //Error
	{ 0x0E2, 33, 2, 7, 7 }, //Big Outro
	{ 0x0E3, 26, 3, 7, 1 }, //Big sees Froggy heading to the beach
	//Last Story
	{ 0x0F0, 33, 2, 0, 0 }, //Tornado 2 Flash scene
	{ 0x0F2, 33, 2, 0, 1 }, //Eggman heading to the Mystic Ruins base
	{ 0x0F3, 33, 1, 0, 1 }, //Knuckles at the Master Emerald
	{ 0x0F4, 33, 0, 0, 1 }, //Tails runs to Sonic
	{ 0x0F5, 33, 1, 0, 1 }, //Sonic and Tails find Eggman and Knuckles
	{ 0x0F6, 34, 2, 0, 1 }, //Sonic travels to the past
	{ 0x0F7, 34, 2, 0, 1 }, //Tikal pleads with her father
	{ 0x0F8, 34, 2, 0, 1 }, //Tikal seals Chaos
	{ 0x0F9, 33, 1, 0, 1 }, //Sonic returns to the present
	{ 0x0FA, 33, 2, 0, 2 }, //Sonic and Tails find the Tornado 2
	{ 0x0FB, 34, 2, 0, 2 }, //Sonic checks on Tikal in the past
	{ 0x0FD, 19, 0, 0, 2 }, //Perfect Chaos reveals himself
	{ 0x0FE, 19, 0, 0, 2 }, //Last Story Outro
	{ 0x0FF, 19, 0, 0, 2 }, //Everyone brings Sonic the emeralds
	//Extra Sonic events
	{ 0x100, 29, 0, 0, 10 }, //Sonic and Tails after landing on the Egg Carrier
	{ 0x101, 29, 0, 0, 10 }, //Sonic and Tails Sky Chase attack (don't get too many ideas)
	{ 0x102, 29, 1, 0, 10 }, //The Egg Carrier Transforms
	{ 0x103, 29, 1, 0, 10 }, //Sonic at the Sky Deck Entrance - broken
	{ 0x104, 32, 1, 0, 10 }, //Sonic right after Sky Deck (Is that it?)
	{ 0x106, 29, 2, 0, 10 }, //Sonic heading to transform the Egg Carrier
	{ 0x107, 29, 3, 3, 10 }, //Egg Carrier returns to normal - broken
	//Additional Tails events
	{ 0x110, 29, 0, 2, 8 }, //Tails and Sonic after landing on the Egg Carrier
	{ 0x111, 29, 0, 2, 8 }, //Tails' Sky Chase Attack
	{ 0x112, 29, 1, 2, 8 }, //The Egg Carrier Transforms
	{ 0x113, 29, 1, 2, 8 }, //Tails at the Sky Deck Entrance - broken
	{ 0x114, 32, 1, 2, 8 }, //Tails right after Sky Deck
	//Additional Knuckles events
	{ 0x120, 29, 2, 3, 9 }, //Egg Carrier Transforms 1
	{ 0x121, 29, 2, 3, 9 }, //Egg Carrier Transforms 2
	{ 0x122, 29, 5, 3, 9 }, //Knuckles sensing the emeralds on the Egg Carrier - broken
	//Additional Amy events
	{ 0x130, 32, 2, 5, 2 }, //Introduction to Hedgehog Hammer
	{ 0x131, 32, 2, 5, 2 }, //Winning at Hedgehog Hammer - broken
	//Additional Gamma events
	{ 0x140, 32, 1, 6, 4 }, //Gamma is told to find the Jet Booster - broken
	{ 0x141, 29, 0, 6, 7 }, //Gamma heads to Hot Shelter
	{ 0x142, 29, 0, 6, 7 }, //Gamma rescues E-105
	//Additional Big events
	{ 0x150, 29, 3, 7, 4 }, //Egg Carrier Transforms - broken
	//Additional Last Story events
	{ 0x160, 34, 2, 0, 1 }, //The Echidna tribe faces Chaos
	//Upgrade Cutscenes - broken
	{ 0x165, 26, 4, 0, 0 }, //Sonic gets the Crystal Ring
	{ 0x166, 26, 2, 0, 0 }, //Sonic gets the LSDash Shoe
	{ 0x167, 33, 1, 0, 0 }, //Sonic gets the Ancient Light
	{ 0x168, 26, 3, 2, 0 }, //Tails gets the Jet Anklet
	{ 0x169, 34, 0, 2, 0 }, //Tails gets the Rhythm Badge
	{ 0x16A, 33, 2, 3, 0 }, //Knuckles gets the Fighting Gloves
	{ 0x16B, 33, 0, 3, 0 }, //Knuckles gets the Shovel Claw
	{ 0x16C, 32, 2, 5, 0 }, //Amy gets the Long Hammer
	{ 0x16D, 32, 2, 5, 0 }, //Amy gets the Warrior Feather
	{ 0x16E, 32, 4, 6, 0 }, //Gamma gets the Laser Blaster
	{ 0x16F, 32, 0, 6, 0 }, //Gamma gets the Jet Booster
	{ 0x170, 33, 2, 7, 0 }, //Big gets the PowerRod
	{ 0x171, 33, 1, 7, 0 }, //Big gets the Life Belt
	//Misc Events
	{ 0x176, 26, 1, 0, 1 }, //Ice Stone appears (Sonic)
	{ 0x177, 26, 1, 2, 0 }, //Ice Stone appears (Tails)
	{ 0x178, 26, 3, 7, 0 }, //Ice Stone appears (Big)
	{ 0x179, 26, 3, 0, 1 }, //Employee Card appears
	{ 0x17A, 33, 0, 0, 1 }, //Passage to Angel Island opens (Sonic)
	{ 0x17B, 33, 0, 2, 0 }, //Passage to Angel Island opens (Tails)
	{ 0x17C, 33, 0, 7, 1 }, //Passage to Angel Island opens (Big)
	{ 0x180, 5,  0, 0, 9 }, //Egg Carrier in Red Mountain
};

FunctionPointer(void, StopMusicAndLoadNextMenu, (int a1), 0x505B40);
FunctionPointer(void, SeqRun, (), 0x412AC0);
FunctionPointer(void, SeqSetPlayer, (__int16 character), 0x413380);
FunctionPointer(void, SeqSetSection, (__int16 sequence), 0x4133E0);
FunctionPointer(void, RunSceneSelect, (), 0x413870);
DataPointer(ObjectMaster*, CurrentMenuObjectMaster_Maybe, 0x3C5E8D0);
DataPointer(DemoData, FirstDemo, 0x913AE0);
DataArray(DemoData, DemosArray, 0x913AE0, 6);
DataArray(LandTable*, LandTableArray, 0x97DBE8, 193);
DataPointer(AdventureData_*, CurrentAdventureData_, 0x3B0EF4C);
DataPointer(SceneSelectData_*, CurrentSceneSelectData, 0x03B18A08);
DataArray(AdventureData, Stories, 0x3B183A8, 8);