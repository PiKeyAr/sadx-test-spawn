#include "stdafx.h"

#include <SADXModLoader.h>
#include <shellapi.h>	// for CommandLineToArgvW
#include <string>

constexpr auto loc_40C318 = (const void*)0x0040C318;

__declspec(naked) void ForceTrialMode()
{
	__asm
	{
		mov GameMode, GameModes_Trial
		jmp loc_40C318
	}
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
		WriteData((void*)0x00415007, 0x90i8, 5);

		for (int i = 1; i < argc; i++)
		{
			if (!wcscmp(argv[i], L"--level") || !wcscmp(argv[i], L"-l"))
			{
				CurrentLevel = _wtoi(argv[++i]);
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
				CurrentCharacter = _wtoi(argv[++i]);
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