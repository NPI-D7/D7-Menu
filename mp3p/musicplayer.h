#include <3ds.h>

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "all.h"
#include "error.h"
#include "file.h"

#include "playback.h"




struct watchdogInfo
{
	PrintConsole*		screen;
	struct errInfo_t*	errInfo;
};

void playbackWatchdog(void* infoIn);