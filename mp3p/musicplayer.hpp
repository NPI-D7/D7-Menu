#include <3ds.h>

extern "C" {


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


}


namespace Player {
    void playbackWatchdog(void* infoIn);
    static int changeFile(const char* ep_file, struct playbackInfo_t* playbackInfo);4
    void PlaySong(void);
}
 struct watchdogInfo
{
	PrintConsole*		screen;
	struct errInfo_t*	errInfo;
};