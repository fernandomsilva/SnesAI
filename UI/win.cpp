#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#ifdef USE_THREADS
#include <sched.h>
#include <pthread.h>
#endif
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#ifdef HAVE_SYS_IOCTL_H
//#include <sys/ioctl.h>
#endif
#ifndef NOSOUND
//#include <sys/soundcard.h>
//#include <sys/mman.h>
#endif
#ifdef JOYSTICK_SUPPORT
//#include <linux/joystick.h>
#endif

#include "snes9x.h"
#include "memmap.h"
#include "apu/apu.h"
#include "gfx.h"
#include "snapshot.h"
#include "controls.h"
#include "cheats.h"
#include "movie.h"
#include "logger.h"
#include "display.h"
#include "conffile.h"
#ifdef NETPLAY_SUPPORT
#include "netplay.h"
#endif
#ifdef DEBUGGER
#include "debug.h"
#endif
#include "statemanager.h"

#include <iostream>

static const char *rom_filename = NULL;


void snesconfig(int argc, char *argv[])
{
	memset(&Settings, 0, sizeof(Settings));
	Settings.MouseMaster = true;
	Settings.SuperScopeMaster = true;
	Settings.JustifierMaster = true;
	Settings.MultiPlayer5Master = true;
	Settings.FrameTimePAL = 20000;
	Settings.FrameTimeNTSC = 16667;
	Settings.SixteenBitSound = true;
	Settings.Stereo = true;
	Settings.SoundPlaybackRate = 32000;
	Settings.SoundInputRate = 32000;
	Settings.SupportHiRes = true;
	Settings.Transparency = true;
	Settings.AutoDisplayMessages = true;
	Settings.InitialInfoStringTimeout = 120;
	Settings.HDMATimingHack = 100;
	Settings.BlockInvalidVRAMAccessMaster = true;
	
	rom_filename = S9xParseArgs(argv, argc);
	
	if (!Memory.Init() || !S9xInitAPU())
	{
		std::cout << "Snes9x: Memory allocation failure - not enough RAM/virtual memory available.\nExiting...\n" << std::endl;
		Memory.Deinit();
		S9xDeinitAPU();
		exit(1);
	}
	
	S9xInitSound(16, 0);
	S9xSetSoundMute(TRUE);

	S9xReportControllers();
}

int main(int argc, char *argv[])
{
	bool8 loaded = FALSE;
	
	std::cout << "Hello" << std::endl;
	
	snesconfig(argc, argv);
	
	if (rom_filename)
	{
		std::cout << rom_filename << std::endl;
		loaded = Memory.LoadROM(rom_filename);
		if (loaded)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	
	S9xMainLoop();
	
	std::cout << "Bye" << std::endl;
	return 0;
}