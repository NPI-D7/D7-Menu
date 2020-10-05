
#include "sdmenuv2.hpp"
#include "mainMenu.hpp"
#include "gameManagement.hpp"
#include  "utils.hpp"

extern bool touching(touchPosition touch, Structs::ButtonPos button);
extern bool exiting;

SDMenu::SDMenu() {
	
	maxTitles = (int)GameManagement::installedTitles.size();
}

void SDMenu::Draw(void) const {
	GFX::DrawTop();
	GFX::DrawBetteryTop();
	Gui::DrawString(0, 2 , 0.8f, WHITE, timeStr());
	Gui::DrawStringCentered(0, 2, 0.8f, WHITE, "D7-Menu-> SDMenu", 400);
        Gui::Draw_Rect(10, 50, 380, 100, C2D_Color32(130, 130, 130, 255));
	Gui::DrawStringCentered(0, 75, 0.7f, BLACK, GameManagement::installedTitles[Selection]->name());
	Gui::DrawStringCentered(0, 105, 0.7f, BLACK, GameManagement::installedTitles[Selection]->Author());
        Gui::DrawString(397-Gui::GetStringWidth(0.8f, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles)), 237-Gui::GetStringHeight(0.8f, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles)), 0.8f, WHITE, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles));


	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	GFX::DrawBottom();

	// Draw Buttons. ;P
	for (int i = 0; i < (int)this->mainButtons.size(); i++) {
		if (this->Selection == i) {
			
			Gui::Draw_Rect(mainButtons[i].x-2, mainButtons[i].y-2, 52, 52, BLUE);
                        C2D_DrawImageAt(GameManagement::installedTitles[i]->icon(), mainButtons[i].x+0, mainButtons[i].y+0, 0.5f);
		}
		else {
				C2D_DrawImageAt(GameManagement::installedTitles[i]->icon(), mainButtons[i].x+0, mainButtons[i].y+0, 0.5f);
		}
	}

    


	

	

		
		// Installed Title Icon.



	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
}


void SDMenu::Logic(u32 hDown, u32 hHeld, touchPosition touch) {
	// Press Start to exit the app.
	if (hDown & KEY_START) {
		fadecolor = 0;
		fadeout = true;
		exiting = true;
	}
		if (hDown & KEY_SELECT){

		
		GFX::DrawTopSP();
		Gui::DrawString(1, 30, 0.8f, WHITE, "\uE000: Start");
		Gui::DrawString(1, 60, 0.8f, WHITE, "\uE006: Navigate");
		
		
		Gui::DrawString(1, 90, 0.8f, WHITE, "Press \uE002 to go to MainMenu");

		Gui::DrawString(1, 120, 0.8f, WHITE, "Press \uE045 to exit!");
        if (hDown & KEY_X){
         
        Gui::setScreen(std::make_unique<MainMenu>(), true, false);


        }

	// Press <A> on a Button to enter example screen.
	

        if (hDown & KEY_A) {
			if (!GameManagement::installedTitles.empty()) {
				u8 param[0x300];
				u8 hmac[0x20];
				memset(param, 0, sizeof(param));
				memset(hmac, 0, sizeof(hmac));
				APT_PrepareToDoApplicationJump(0, GameManagement::installedTitles[Selection]->ID(), MEDIATYPE_SD);
				APT_DoApplicationJump(param, sizeof(param), hmac);
			}
		}

	// Touch the button to enter example screen.
	

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->mainButtons.size() - 5)	this->Selection+= 5;
	}
        if (hDown & KEY_RIGHT) {
		if (this->Selection < (int)this->mainButtons.size() - 1)	this->Selection++;
	}
        if (hDown & KEY_LEFT) {
		if (this->Selection > 0)	this->Selection--;
	}

	// Press Up to go one entry up.
	if (hDown & KEY_UP) {
		if (this->Selection > 4)	this->Selection-= 5;
	}
}
