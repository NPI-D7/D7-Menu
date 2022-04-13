#include "common.hpp"
#include "init.hpp"
#include "splash.hpp"
#include "structs.hpp"
#include "msg.hpp"
#include "ptmu_x.h"
#include "TitleManager.hpp"
#include "colors.hpp"
#include "sound.h"






#include <3ds.h>
#include <algorithm>
#include <dirent.h>
#include <unistd.h>
#include <iostream>
#include <vector>


sound *bgm = NULL;
bool songIsFound = false;
bool dspFound = false;


bool exiting = false;

C2D_SpriteSheet sprites;

// If button Position pressed -> Do something.
bool touching(touchPosition touch, Structs::ButtonPos button) {
	if (touch.px >= button.x && touch.px <= (button.x + button.w) && touch.py >= button.y && touch.py <= (button.y + button.h))	return true;
	else	return false;
}

void Init::loadSoundEffects(void) {
	if (dspFound) {
		if (access("sdmc:/3ds/NPI/music/Test/Figureeeeeeeeee.wav", F_OK ) != -1) {
			bgm = new sound("sdmc:/3ds/NPI/music/Test/Figure.wav", 1, true);
			songIsFound = true;
		}
	}
}

void Init::playMusic(void) {
	if (songIsFound) {
		bgm->play();
	}
}

void Init::stopMusic(void) {
	if (songIsFound) {
		bgm->stop();
	}
}


	
	
	

Result Init::Initialize() {
	// Here we set the initial fade effect for fadein.
	fadealpha = 255;
	fadein = true;

	gfxInitDefault();
	romfsInit();
	Gui::init();
	Gui::loadSheet("romfs:/gfx/sprites.t3x", sprites);
	cfguInit();
	mcuInit();
	osSetSpeedupEnable(true);
	acInit();
	// For battery status
	ptmuInit();
	// For AC adapter status
	ptmuxInit();
	amInit();
	FS_OpenArchive(&sdmc_archive, ARCHIVE_SDMC);
	archive = sdmc_archive;
	FS_RecursiveMakeDir(sdmc_archive, "/3ds/NPI/apps/D7-Menu/");
	FS_RecursiveMakeDir(sdmc_archive, "/3ds/NPI/screenshots/D7-Menu");
	FS_RecursiveMakeDir(sdmc_archive, "/3ds/NPI/music/D7-Menu");
	
       

	// For battery status
   	//if (R_FAILED(res = ptmuInit())) {
   	//    return DisplayStartupError("ptmuInit failed.", res);
   	//}	//
   	//// For AC adapter status
   	//if (R_FAILED(res = ptmuxInit())) {
   	//    return DisplayStartupError("ptmuxInit failed.", res);
   	//}

	Msg::DisplayMsg("Scanning sdcard...");
	TitleManager::ScanSD();
	//Msg::DisplayMsgPGR(2, 6, "Scanning SD Card...");
	//GameManagement::scanTitleID(); 

	
	playbackInfo_t playbackInfo;
	changeFile("romfs:/ItachiTheme.ogg", &playbackInfo);
	
	aptSetSleepAllowed(false);

	Gui::setScreen(std::make_unique<Stack>(), false, false); // Set the screen initially as Stack Screen.
   // if ( access( "sdmc:/3ds/dspfirm.cdc", F_OK ) != -1 ) {
	//	ndspInit();
	//	dspFound = true;
	//	loadSoundEffects();
	//	playMusic();
	//}
	return 0;
	
}

Result Init::MainLoop() {
	// Initialize everything.
	Init::Initialize();

	// Loop as long as the status is not exiting.
	while (aptMainLoop()) {
		// Scan the input.
		hidScanInput();
		u32 hDown = hidKeysDown();
		u32 hHeld = hidKeysHeld();
		touchPosition touch;
		hidTouchRead(&touch);

		Gui::clearTextBufs(); // Clear Text Buffer before.
		C2D_TargetClear(Top, C2D_Color32(0, 0, 0, 0));
		C2D_TargetClear(Bottom, C2D_Color32(0, 0, 0, 0));

		// Screen Logic & Draw.
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		Gui::DrawScreen(false);
		Gui::ScreenLogic(hDown, hHeld, touch, true, false);
		C3D_FrameEnd(0);
		if (exiting) {
                        stopPlayback();
            stopMusic();
			if (!fadeout)	break;
		}

		// Call the fade effects here. :D
		Gui::fadeEffects(6, 6, false);
	}
	// Exit all services and exit the app.
	Init::Exit();
        aptSetSleepAllowed(true);
	return 0;
}

Result Init::Exit() {
	Gui::exit();
	Gui::unloadSheet(sprites);
	gfxExit();
	cfguExit();
	ptmuxExit();
	mcuExit();
	romfsExit();
	FS_CloseArchive(sdmc_archive);
	return 0;
}
