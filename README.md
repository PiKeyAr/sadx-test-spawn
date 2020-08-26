# Sonic Adventure DX Test Spawn mod

This is a mod for Sonic Adventure DX PC (2004) that lets you load the game directly on any level/act and with any character.

**Using the mod**

Enable the mod in SADX Mod Manager and run sonic.exe from the command line with the arguments below.

`-level` or `-l` - Level ID (0-based decimal or by name, such as `emeraldcoast`)

`-act` or `-a` - Act ID (0-based decimal)

`-character` or `-c` - Character ID (0-based decimal or by name, such as `metalsonic`)

`-event` or `-e` - Cutscene ID (0-based decimal)

`-position` or `-p` - Character position (three floats, requires `-level` or `-act`)

`-rotation` or `-r` - Character Y rotation (from -32768 to 32767, requires `-position`)

Examples: 

`sonic.exe -l 4 -a 2 -c 3` spawns Knuckles in Speed Highway Act 3

`sonic.exe -e 40` plays "Sonic vs Knuckles" cutscene

A full cutscene list is available [here](https://github.com/sonicretro/sadx-test-spawn/blob/master/Cutscenes.md) (Credit to ItsEasyActually who made the original list of EV files in SA1).
