#include "stdafx.h"

#include <SADXModLoader.h>
#include <shellapi.h>	// for CommandLineToArgvW
#include <string>
#include <unordered_map>
#include <algorithm>
using std::wstring;
using std::unordered_map;

auto loc_40C318 = (const void*)0x0040C318;

__declspec(naked) void ForceTrialMode()
{
	__asm
	{
		mov GameMode, GameModes_Trial
		jmp loc_40C318
	}
}

static const unordered_map<wstring, uint8_t> levelidsnamemap = {
	{ L"hedgehoghammer", LevelIDs_HedgehogHammer },
	{ L"emeraldcoast", LevelIDs_EmeraldCoast },
	{ L"windyvalley", LevelIDs_WindyValley },
	{ L"twinklepark", LevelIDs_TwinklePark },
	{ L"speedhighway", LevelIDs_SpeedHighway },
	{ L"redmountain", LevelIDs_RedMountain },
	{ L"skydeck", LevelIDs_SkyDeck },
	{ L"lostworld", LevelIDs_LostWorld },
	{ L"icecap", LevelIDs_IceCap },
	{ L"casinopolis", LevelIDs_Casinopolis },
	{ L"finalegg", LevelIDs_FinalEgg },
	{ L"hotshelter", LevelIDs_HotShelter },
	{ L"chaos0", LevelIDs_Chaos0 },
	{ L"chaos2", LevelIDs_Chaos2 },
	{ L"chaos4", LevelIDs_Chaos4 },
	{ L"chaos6", LevelIDs_Chaos6 },
	{ L"perfectchaos", LevelIDs_PerfectChaos },
	{ L"egghornet", LevelIDs_EggHornet },
	{ L"eggwalker", LevelIDs_EggWalker },
	{ L"eggviper", LevelIDs_EggViper },
	{ L"zero", LevelIDs_Zero },
	{ L"e101", LevelIDs_E101 },
	{ L"e101r", LevelIDs_E101R },
	{ L"stationsquare", LevelIDs_StationSquare },
	{ L"eggcarrieroutside", LevelIDs_EggCarrierOutside },
	{ L"eggcarrierinside", LevelIDs_EggCarrierInside },
	{ L"mysticruins", LevelIDs_MysticRuins },
	{ L"past", LevelIDs_Past },
	{ L"twinklecircuit", LevelIDs_TwinkleCircuit },
	{ L"skychase1", LevelIDs_SkyChase1 },
	{ L"skychase2", LevelIDs_SkyChase2 },
	{ L"sandhill", LevelIDs_SandHill },
	{ L"ssgarden", LevelIDs_SSGarden },
	{ L"ecgarden", LevelIDs_ECGarden },
	{ L"mrgarden", LevelIDs_MRGarden },
	{ L"chaorace", LevelIDs_ChaoRace }
};

static uint8_t ParseLevelID(const wstring &str)
{
	wstring str2 = str;
	std::transform(str2.begin(), str2.end(), str2.begin(), ::towlower);
	auto lv = levelidsnamemap.find(str2);
	if (lv != levelidsnamemap.end())
		return lv->second;
	else
		return (uint8_t)wcstol(str.c_str(), nullptr, 10);
}

static const unordered_map<wstring, uint8_t> charnamemap = {
	{ L"sonic", Characters_Sonic },
	{ L"eggman", Characters_Eggman },
	{ L"tails", Characters_Tails },
	{ L"knuckles", Characters_Knuckles },
	{ L"tikal", Characters_Tikal },
	{ L"amy", Characters_Amy },
	{ L"gamma", Characters_Gamma },
	{ L"big", Characters_Big },
	{ L"metalsonic", Characters_MetalSonic }
};

static uint8_t ParseCharacterID(const wstring &str)
{
	wstring s = str;
	transform(s.begin(), s.end(), s.begin(), ::towlower);
	auto ch = charnamemap.find(s);
	if (ch != charnamemap.end())
		return ch->second;
	else
		return (uint8_t)wcstol(str.c_str(), nullptr, 10);
}

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		int argc = 0;
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

		bool level_set = false;
		bool act_set = false;

		// Prevents CurrentCharacter from being overwritten. There could be other side effects,
		// but there are none that I've noticed thus far.
		WriteData<5>((void*)0x00415007, 0x90i8);

		for (int i = 1; i < argc; i++)
		{
			if (!wcscmp(argv[i], L"--level") || !wcscmp(argv[i], L"-l"))
			{
				CurrentLevel = ParseLevelID(argv[++i]);
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
				auto ch = ParseCharacterID(argv[++i]);
				if (ch == Characters_MetalSonic)
				{
					MetalSonicFlag = 1;
					ch = 0;
				}
				CurrentCharacter = ch;
				PrintDebug("Loading character: %d\n", CurrentCharacter);
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

				StartPosition position = {
					CurrentLevel, CurrentAct,
					// Position
					{ (float)_wtof(argv[++i]), (float)_wtof(argv[++i]), (float)_wtof(argv[++i]) },
					// YRot
					0
				};

				helperFunctions.RegisterStartPosition((Uint8)CurrentCharacter, position);
			}
		}

		if (level_set || act_set)
		{
			WriteJump((void*)0x0040C115, ForceTrialMode);
		}

		LocalFree(argv);
	}
}