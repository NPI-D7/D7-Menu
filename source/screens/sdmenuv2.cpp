
#include "sdmenuv2.hpp"
#include "mainMenu.hpp"
#include "gameManagement.hpp"

extern bool touching(touchPosition touch, Structs::ButtonPos button);
extern bool exiting;

void SDMenu::Draw(void) const {
	GFX::DrawTop();
	Gui::DrawStringCentered(0, 2, 0.8f, WHITE, "D7-Menu-> SDMenu", 400);
	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	GFX::DrawBottom();

	// Draw Buttons. ;P
	for (int i = 0; i < (int)this->mainButtons.size(); i++) {
		if (this->Selection == i) {
			C2D_DrawImageAt(GameManagement::installedTitles[i++]->icon(), mainButtons[i++].x+0, mainButtons[i++].y+0, 0.5f);
			Gui::Draw_Rect(mainButtons[i].x+0, mainButtons[i].y+0, 51, 51, WHITE);
		}
		else {
				C2D_DrawImageAt(GameManagement::installedTitles[i++]->icon(), mainButtons[i++].x+0, mainButtons[i++].y+0, 0.5f);
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

	// Press <A> on a Button to enter example screen.
	if (hDown & KEY_A) {
		if (this->Selection == 0) {
			
		} else if (this->Selection == 1) {
			
		}
	}

	// Touch the button to enter example screen.
	if (hDown & KEY_TOUCH) {
		if (touching(touch, this->mainButtons[0])) {
			Gui::setScreen(std::make_unique<MainMenu>(), true, false);
		} else if (touching(touch, this->mainButtons[1])) {
			
		}
	}

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->mainButtons.size() - 1)	this->Selection++;
	}

	// Press Up to go one entry up.
	if (hDown & KEY_UP) {
		if (this->Selection > 0)	this->Selection--;
	}
}