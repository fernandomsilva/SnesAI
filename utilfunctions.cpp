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

void S9xMessage (int type, int number, const char *message)
{
}

bool8 S9xOpenSoundDevice (void)
{
}

const char * S9xGetDirectory (enum s9x_getdirtype dirtype)
{
}

void S9xExit (void)
{
}

const char * S9xChooseMovieFilename (bool8 read_only)
{
	return;
}

const char * S9xChooseFilename (bool8 read_only)
{
}

const char * S9xGetFilename (const char *ex, enum s9x_getdirtype dirtype)
{
}

const char * S9xGetFilenameInc (const char *ex, enum s9x_getdirtype dirtype)
{
}

void S9xToggleSoundChannel (int c)
{
}

void S9xExtraUsage (void)
{
}

void S9xParseArg (char **argv, int &i, int argc)
{
}

void S9xParsePortConfig (ConfigFile &conf, int pass)
{
}

const char * S9xBasename (const char *f)
{
}

bool8 S9xOpenSnapshotFile (const char *filename, bool8 read_only, STREAM *file)
{
}

void S9xCloseSnapshotFile (STREAM file)
{
}

bool8 S9xInitUpdate (void)
{
}

bool8 S9xDeinitUpdate (int width, int height)
{
}

bool8 S9xContinueUpdate (int width, int height)
{
}

const char * S9xStringInput (const char *message)
{
}

void S9xHandlePortCommand (s9xcommand_t cmd, int16 data1, int16 data2)
{
}

bool S9xPollButton (uint32 id, bool *pressed)
{
}

bool S9xPollAxis (uint32 id, int16 *value)
{
}

bool S9xPollPointer (uint32 id, int16 *x, int16 *y)
{
}

void S9xSyncSpeed (void)
{
}

void S9xAutoSaveSRAM (void)
{
}

void S9xOnSNESPadRead()
{
}

void SetInfoDlgColor(unsigned char r, unsigned char g, unsigned char b)
{
}

void S9xSetPalette (void)
{
	return;
}

void WinDisplayStringFromBottom (const char *string, int linesFromBottom, int pixelsFromLeft, bool allowWrap)
{
}
