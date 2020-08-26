#include "stdafx.h"
#include "Data.h"
#include "Trampoline.h"

static const auto loc_40C318 = reinterpret_cast<const void*>(0x0040C318);

static Trampoline* Title_Main_t = nullptr;
static Trampoline* Chaos2_Main_t = nullptr;
static Trampoline* Chaos6_Main_t = nullptr;

__declspec(naked) void ForceTrialMode()
{
	__asm
	{
		mov GameMode, GameModes_Trial
		jmp loc_40C318
	}
}

static const std::unordered_map<std::wstring, uint8_t> level_name_ids_map = {
	{ L"hedgehoghammer",    LevelIDs_HedgehogHammer },
	{ L"emeraldcoast",      LevelIDs_EmeraldCoast },
	{ L"windyvalley",       LevelIDs_WindyValley },
	{ L"twinklepark",       LevelIDs_TwinklePark },
	{ L"speedhighway",      LevelIDs_SpeedHighway },
	{ L"redmountain",       LevelIDs_RedMountain },
	{ L"skydeck",           LevelIDs_SkyDeck },
	{ L"lostworld",         LevelIDs_LostWorld },
	{ L"icecap",            LevelIDs_IceCap },
	{ L"casinopolis",       LevelIDs_Casinopolis },
	{ L"finalegg",          LevelIDs_FinalEgg },
	{ L"hotshelter",        LevelIDs_HotShelter },
	{ L"chaos0",            LevelIDs_Chaos0 },
	{ L"chaos2",            LevelIDs_Chaos2 },
	{ L"chaos4",            LevelIDs_Chaos4 },
	{ L"chaos6",            LevelIDs_Chaos6 },
	{ L"perfectchaos",      LevelIDs_PerfectChaos },
	{ L"egghornet",         LevelIDs_EggHornet },
	{ L"eggwalker",         LevelIDs_EggWalker },
	{ L"eggviper",          LevelIDs_EggViper },
	{ L"zero",              LevelIDs_Zero },
	{ L"e101",              LevelIDs_E101 },
	{ L"e101r",             LevelIDs_E101R },
	{ L"stationsquare",     LevelIDs_StationSquare },
	{ L"eggcarrieroutside", LevelIDs_EggCarrierOutside },
	{ L"eggcarrierinside",  LevelIDs_EggCarrierInside },
	{ L"mysticruins",       LevelIDs_MysticRuins },
	{ L"past",              LevelIDs_Past },
	{ L"twinklecircuit",    LevelIDs_TwinkleCircuit },
	{ L"skychase1",         LevelIDs_SkyChase1 },
	{ L"skychase2",         LevelIDs_SkyChase2 },
	{ L"sandhill",          LevelIDs_SandHill },
	{ L"ssgarden",          LevelIDs_SSGarden },
	{ L"ecgarden",          LevelIDs_ECGarden },
	{ L"mrgarden",          LevelIDs_MRGarden },
	{ L"chaorace",          LevelIDs_ChaoRace }
};

static uint8_t parse_level_id(const std::wstring& str)
{
	std::wstring lowercase = str;
	std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::towlower);

	const auto it = level_name_ids_map.find(lowercase);

	if (it != level_name_ids_map.end())
		return it->second;

	return static_cast<uint8_t>(std::stol(lowercase));
}

static const std::unordered_map<std::wstring, uint8_t> character_name_ids_map = {
	{ L"sonic",      Characters_Sonic },
	{ L"eggman",     Characters_Eggman },
	{ L"tails",      Characters_Tails },
	{ L"knuckles",   Characters_Knuckles },
	{ L"tikal",      Characters_Tikal },
	{ L"amy",        Characters_Amy },
	{ L"gamma",      Characters_Gamma },
	{ L"big",        Characters_Big },
	{ L"metalsonic", Characters_MetalSonic }
};

static uint8_t parse_character_id(const std::wstring& str)
{
	std::wstring lowercase = str;
	transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::towlower);

	const auto it = character_name_ids_map.find(lowercase);

	if (it != character_name_ids_map.end())
		return it->second;

	return static_cast<uint8_t>(std::stol(lowercase));
}

static int get_event_data(int event_id, char type)
{
	for (int i = 0; i < LengthOfArray(CutsceneList); i++)
	{
		if (CutsceneList[i].cutscene_id == event_id)
		{
			if (!type) return CutsceneList[i].level;
			else if (type == 1) return CutsceneList[i].act;
			else if (type == 2) return CutsceneList[i].character;
			else return CutsceneList[i].scene_select;
		}
	}
	return 0;
}

static int parse_event_id(const std::wstring& str, int type)
{
	Uint32 event_id;
	std::wstring str2 = str;
	std::transform(str2.begin(), str2.end(), str2.begin(), ::towlower);
	return (Uint32)wcstol(str.c_str(), nullptr, 10);
}

static void set_event_flags(EventFlags a1)
{
	SeqRun();
	if (FirstDemo.cutscene >= 240 && FirstDemo.cutscene <= 255) LastStoryFlag = 1;
	else if (FirstDemo.cutscene == 355) LastStoryFlag = 1;
	SeqSetPlayer(get_event_data(FirstDemo.cutscene, 2));
	CurrentAdventureData_->seq = get_event_data(FirstDemo.cutscene, 3);
	SeqSetSection(get_event_data(FirstDemo.cutscene, 3));
	std::string SequenceName = CurrentSceneSelectData[get_event_data(FirstDemo.cutscene, 3)].Name;
	PrintDebug("\n \n Loading sequence: %s\n", SequenceName.c_str());
	if (FirstDemo.cutscene == 64 || FirstDemo.cutscene == 66) SetTimeOfDay_Evening();
	if (FirstDemo.cutscene == 80 || FirstDemo.cutscene == 81) SetTimeOfDay_Night();
	//Sand Hill haccs
	WriteData<1>((char*)0x7B0DA0, 0xC3u); //Lost World 3 hacc
	SetEventFlag((EventFlags)FLAG_SONIC_SS_ENTRANCE_CASINO); //Open Casino for Sonic
	SetEventFlag((EventFlags)FLAG_MILES_SS_ENTRANCE_CASINO); //Open Casino for Tails
	switch (FirstDemo.cutscene)
	{
	case 85:
		WriteData<1>((char*)0x598040, 0xC3u);
		WriteData<1>((char*)0x79E4C0, 0xC3u);
		WriteData<5>((char*)0x597BF3, 0x90u);
		break;
	case 110:
		SetEventFlag((EventFlags)FLAG_AMY_MR_ENTRANCE_FINALEGG); //Open Final Egg for Amy
		break;
	case 114:
		SetEventFlag((EventFlags)FLAG_AMY_EC_SINK); //Egg Carrier sunk in Amy's outro
		break;
	case 146:
		SetEventFlag((EventFlags)FLAG_KNUCKLES_MR_APPEAR_FINALEGG); //Open Final Egg for Knuckles
		break;
	case 149:
		WriteData<5>((char*)0x5EF6D0, 0x90u); //Sky Deck music
		WriteData<1>((char*)0x450370, 0xC3u); //Rings
		WriteData<1>((char*)0x7A1AA0, 0xC3u); //Tikal hints
		WriteData<1>((char*)0x476440, 0xC3u); //Radar
		break;
	case 179:
		SetEventFlag((EventFlags)FLAG_E102_MR_FREEPASS); //Open Final Egg for useless machine
		SetEventFlag((EventFlags)FLAG_E102_CLEAR_BEACH); //Open Final Egg for useless machine
		SetEventFlag((EventFlags)FLAG_E102_CLEAR_FINALEGG); //Open Final Egg for useless machine
		SetEventFlag((EventFlags)FLAG_E102_MR_APPEAR_FINALEGG); //Open Final Egg for useless machine
		break;
	case 184:
		WriteData<1>((char*)0x61CA90, 0xC3u); //Kill Emerald Coast music
		WriteData<1>((char*)0x4AD140, 0xC3u); //Kill Kikis
		WriteData<1>((char*)0x4FA320, 0xC3u); //Kill OFrog
		break;
	case 192:
		SetEventFlag((EventFlags)FLAG_E102_EC_BOOSTER); //Cutscenes where Gamma appears with the Jet Booster
		break;
	case 197:
		SetEventFlag((EventFlags)FLAG_E102_MR_ENTRANCE_MOUNTAIN);
		break;
	case 212:
		WriteData<1>((char*)0x61CA90, 0xC3u); //Kill Emerald Coast music
		break;
	case 218:
		//WriteData<5>((char*)0x59A3F9, 0x90u); //Remove Froggy
		break;
	case 321:
	case 322:
		SetEventFlag((EventFlags)FLAG_E102_EC_SINK); //Egg Carrier sunk in Gamma's outro
		break;
	case 374:
		SetEventFlag((EventFlags)FLAG_SONIC_SS_ICESTONE);
		break;
	case 375:
		SetEventFlag((EventFlags)FLAG_MILES_SS_ICESTONE);
		break;
	case 376:
		SetEventFlag((EventFlags)FLAG_BIG_SS_ICESTONE);
		break;
	case 377:
		SetEventFlag((EventFlags)FLAG_SONIC_SS_CARD);
		break;
	case 378:
		SetEventFlag((EventFlags)FLAG_SONIC_MR_WESTROCK);
		break;
	case 379:
		SetEventFlag((EventFlags)FLAG_MILES_MR_WESTROCK);
		break;
	case 380:
		SetEventFlag((EventFlags)FLAG_BIG_MR_WESTROCK);
		break;
	}
}

static void Obj_Icecap_r(ObjectMaster* o)
{
	if (o)
	{
		MovePlayerToStartPoint(EntityData1Ptrs[0]);
		o->MainSub = Obj_Icecap;
		Obj_Icecap(o);
	}
}

static void Title_Main_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(Title_Main_r)*>(Title_Main_t->Target());
	TitleNewWk* v1;
	v1 = (TitleNewWk*)a1->UnknownB_ptr;
	original(a1);
	if (v1->Stat == 2)
	{
		v1->T = 0;
		v1->Stat = 3;
		*((_DWORD*)CurrentMenuObjectMaster_Maybe->UnknownB_ptr + 4) = 107;
		StopMusicAndLoadNextMenu(0);
	}
}

static void Chaos2_Main_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(Chaos2_Main_r)*>(Chaos2_Main_t->Target());
	if (FirstDemo.cutscene == 136)
	{
		DeleteChildObjects(a1);
		CheckThingButThenDeleteObject(a1);
	}
	original(a1);
}

static void Chaos6_Main_r(ObjectMaster* a1)
{
	auto original = reinterpret_cast<decltype(Chaos6_Main_r)*>(Chaos6_Main_t->Target());
	int land_id = 24;
	if (FirstDemo.cutscene == 29 || FirstDemo.cutscene == 155)
	{
		if (FirstDemo.cutscene == 155) land_id = 25;
		for (int i = 0; i < LandTableArray[land_id]->COLCount; i++)
		{
			if (LandTableArray[land_id]->Col[i].Flags == 1 || LandTableArray[land_id]->Col[i].Flags == 0x20000001) LandTableArray[land_id]->Col[i].Flags = 0;
		}
		DeleteChildObjects(a1);
		CheckThingButThenDeleteObject(a1);
	}
	original(a1);
}

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = {
		/* Version:      */ ModLoaderVer,
		/* Init:         */ nullptr,
		/* Patches:      */ nullptr,
		/* PatchCount:   */ 0,
		/* Jumps:        */ nullptr,
		/* JumpCount:    */ 0,
		/* Calls:        */ nullptr,
		/* CallCount:    */ 0,
		/* Pointers:     */ nullptr,
		/* PointerCount: */ 0
	};

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		int argc = 0;
		int event_id = 0;
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
		
		StartPosition position;
		bool level_set     = false;
		bool act_set       = false;
		bool position_set  = false;
		bool character_set = false;
		bool event_set     = false;

		// NOP. Prevents CurrentCharacter from being overwritten. There could be other side
		// effects, but there are none that we've noticed thus far.
		WriteData<5>(reinterpret_cast<void*>(0x00415007), 0x90u);

		for (int i = 1; i < argc; i++)
		{
			if (!wcscmp(argv[i], L"--level") || !wcscmp(argv[i], L"-l"))
			{
				CurrentLevel = parse_level_id(argv[++i]);
				PrintDebug("Loading level: %d\n", CurrentLevel);
				level_set = true;
			}
			else if (!wcscmp(argv[i], L"--act") || !wcscmp(argv[i], L"-a"))
			{
				CurrentAct = _wtoi(argv[++i]);
				PrintDebug("Loading act: %d\n", CurrentAct);
				act_set = true;
			}
			else if (!wcscmp(argv[i], L"--character") || !wcscmp(argv[i], L"-c"))
			{
				uint8_t character_id = parse_character_id(argv[++i]);
				
				if (character_id == Characters_MetalSonic)
				{
					MetalSonicFlag = 1;
					character_id = 0;
				}

				character_set = true;
				CurrentCharacter = character_id;
				PrintDebug("Loading character: %d\n", CurrentCharacter);
			}
			else if (!wcscmp(argv[i], L"--event") || !wcscmp(argv[i], L"-e"))
			{
				event_id = parse_event_id(argv[++i], 0);
				switch (event_id)
				{
				case 36:
					event_set = false;
					level_set = true;
					CurrentLevel = 22;
					CurrentAct = 0;
					CurrentCharacter = 0;
					break;
				case 49:
					event_set = false;
					level_set = true;
					CurrentLevel = 1;
					CurrentAct = 1;
					CurrentCharacter = 2;
					break;
				case 72:
					event_set = false;
					level_set = true;
					CurrentLevel = 5;
					CurrentAct = 1;
					CurrentCharacter = 2;
					break;
				case 135:
					event_set = false;
					level_set = true;
					CurrentLevel = 16;
					CurrentAct = 0;
					CurrentCharacter = 3;
					break;
				default:
					if (!level_set) CurrentLevel = get_event_data(event_id, 0);
					if (!act_set) CurrentAct = get_event_data(event_id, 1);
					if (!character_set) CurrentCharacter = get_event_data(event_id, 2);
					if (get_event_data(event_id, 3) != -1) WriteCall((void*)0x42C893, set_event_flags);
					PrintDebug("Loading event: %d in level %d act %d character %d\n", event_id, CurrentLevel, CurrentAct, CurrentCharacter);
					for (int i = 0; i < 6; i++)
					{
						DemosArray[i].cutscene = event_id;
						DemosArray[i].level = CurrentLevel;
						DemosArray[i].act = CurrentAct;
						DemosArray[i].character = CurrentCharacter;
					}
					event_set = true;
					WriteData<1>((char*)0x510350, 0xC3u); //Kill title screen
					WriteData<1>((int*)0x0040C10C, 11); //Force GameMode to 11
					WriteData<1>((char*)0x457D10, 0xC3u); //Kill "Press Start"
					break;
				}
			}
			else if (!wcscmp(argv[i], L"--position") || !wcscmp(argv[i], L"-p"))
			{
				if (!level_set && !act_set)
				{
					MessageBoxA(nullptr, "Insufficient arguments for parameter: --position.\n"
					            "Either --level or --act must be specified before --position.",
					            "Insufficient arguments", MB_OK);

					continue;
				}

				if (i + 3 >= argc)
				{
					MessageBoxA(nullptr, "Insufficient arguments for parameter: --position.\n"
					            "All 3 components (X, Y, Z) of the spawn position must be provided. Default spawn point will be used.",
					            "Insufficient arguments", MB_OK);

					continue;
				}

				if (CurrentLevel == LevelIDs_IceCap)
				{
					// NOPs to disable several checks for LevelIDs_IceCap which prevent
					// correct player positioning and orienting.
					WriteData<2>(reinterpret_cast<void*>(0x004149EC), 0x90u);
					WriteData<2>(reinterpret_cast<void*>(0x0041497F), 0x90u);
					WriteData<2>(reinterpret_cast<void*>(0x00414A70), 0x90u);

					using LevelObjectFunc = void(__cdecl*)(ObjectMaster* this_);
					LevelObjects[LevelIDs_IceCap] = Obj_Icecap_r;
				}

				position_set = true;
				const float x = std::stof(argv[++i]);
				const float y = std::stof(argv[++i]);
				const float z = std::stof(argv[++i]);

				position = {
					CurrentLevel,
					static_cast<int16_t>(CurrentAct),
					// Position
					{ x, y, z },
					// YRot
					0
				};				
			}
			else if (!wcscmp(argv[i], L"--rotation") || !wcscmp(argv[i], L"-r"))
			{
				if (!position_set)
				{
					MessageBoxA(nullptr, "Insufficient arguments for parameter: --rotation.\n"
						"Position must be specified before --rotation.",
						"Insufficient arguments", MB_OK);

					continue;
				}
				position.YRot = (Uint16)_wtof(argv[++i]);
			}
		}

		if (level_set || act_set)
		{
			WriteJump(reinterpret_cast<void*>(0x0040C115), ForceTrialMode);
		}
		
		if (position_set) helperFunctions.RegisterStartPosition(static_cast<Uint8>(CurrentCharacter), position);

		if (event_set)
		{
			Title_Main_t  = new Trampoline(0x5101A0, 0x5101AA, Title_Main_r);
			Chaos2_Main_t = new Trampoline(0x54DB90, 0x54DB96, Chaos2_Main_r);
			Chaos6_Main_t = new Trampoline(0x559FC0, 0x559FC8, Chaos6_Main_r);
		}

		LocalFree(argv);
	}
}
