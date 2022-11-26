
#include "sdmenuv2.hpp"
#include "mainMenu.hpp"
#include "utils.hpp"

#define BOXES 15

SDMenu::SDMenu() { maxTitles = (int)TitleManager::sdtitles.size(); }

void SDMenu::Draw(void) const {
  RenderD7::OnScreen(Top);
  RenderD7::Draw::Rect(0, 0, 400, 240, COOLWHITE);
  RenderD7::Draw::Rect(0, 0, 400, 30, COOLDARK);
  RenderD7::Draw::TextCentered(0, 2, 0.8f, COOLWHITE, "D7-Menu -> SDMenu", 400);
  RenderD7::Draw::Rect(6, 46, 388, 108, C2D_Color32(180, 180, 180, 255));
  RenderD7::Draw::Rect(10, 50, 380, 100, C2D_Color32(130, 130, 130, 255));

  RenderD7::Draw::Text(15, 55, 0.7f, BLACK,
                       TitleManager::sdtitles[Selection]->name());
  RenderD7::Draw::Text(15, 75, 0.7f, BLACK,
                       TitleManager::sdtitles[Selection]->author(), 290);
  RenderD7::Draw::Text(15, 125, 0.7f, BLACK,
                       "Media: " + TitleManager::sdtitles[Selection]->MediaTP(),
                       290);
  RenderD7::Draw::Rect(303, 63, 76, 76, C2D_Color32(180, 180, 180, 255));
  RenderD7::Draw::Image(TitleManager::sdtitles[Selection]->icon(), 305, 65, 1.5,
                        1.5);
  
  RenderD7::OnScreen(Bottom);
  RenderD7::Draw::Rect(0, 0, 320, 240, COOLWHITE);
  RenderD7::Draw::Rect(0, 0, 320, 30, COOLDARK);
  RenderD7::Draw::Text(2, 3, 0.8f, COOLWHITE,
                       "Title: " + std::to_string(Selection + 1) + "/ " +
                           std::to_string(maxTitles));

  for (int i = 0; i < BOXES && i < maxTitles; i++) {
    if (screenPos + i == Selection) {
      RenderD7::Draw::Rect(mainButtons[i].x - 2, mainButtons[i].y - 2, 52, 52,
                           BLUE);
      C2D_DrawImageAt(TitleManager::sdtitles[screenPos + i]->icon(),
                      mainButtons[i].x + 0, mainButtons[i].y + 0, 0.5f);
    }

    C2D_DrawImageAt(TitleManager::sdtitles[screenPos + i]->icon(),
                    mainButtons[i].x + 0, mainButtons[i].y + 0, 0.5f);
    // Installed Title Icon.
  }

  RenderD7::Draw::Text(37, 214, 0.8f, BLACK, "Hold \uE046 to show controols!");
}

void SDMenu::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {
  // Press Start to exit the app.
  if (hDown & KEY_START) {
    RenderD7::ExitApp();
  }

  if (hHeld & KEY_SELECT) {

    RenderD7::OnScreen(Top);
    RenderD7::Draw::Rect(0, 0, 400, 240, RenderD7::Color::Hex("#000000", 80));
    RenderD7::Draw::Text(1, 30, 0.8f, BLACK, "\uE000: Start");
    RenderD7::Draw::Text(1, 60, 0.8f, BLACK, "\uE006: Navigate");

    RenderD7::Draw::Text(1, 90, 0.8f, BLACK, "Press \uE001 to go to MainMenu");

    RenderD7::Draw::Text(1, 120, 0.8f, BLACK, "Press \uE045 to exit!");
  }
  if (hDown & KEY_B) {

    RenderD7::Scene::Load(std::make_unique<MainMenu>());
  }

  if (hDown & KEY_A) {
    if (!TitleManager::sdtitles.empty()) {
      u8 param[0x300];
      u8 hmac[0x20];
      memset(param, 0, sizeof(param));
      memset(hmac, 0, sizeof(hmac));
      APT_PrepareToDoApplicationJump(
          0, TitleManager::sdtitles[Selection]->ID(),
          TitleManager::sdtitles[Selection]->mediatype());
      APT_DoApplicationJump(param, sizeof(param), hmac);
    }
  }

  if (hDown & KEY_DOWN) {
    if (this->Selection < (int)this->maxTitles - 5)
      this->Selection += 5;
  }
  if (hDown & KEY_RIGHT) {
    if (this->Selection < (int)this->maxTitles - 1)
      this->Selection++;
  }
  if (hDown & KEY_LEFT) {
    if (this->Selection > 0)
      this->Selection--;
  }

  // Press Up to go one entry up.
  if (hDown & KEY_UP) {
    if (this->Selection > 4)
      this->Selection -= 5;
  }
  if (Selection < screenPos) {
    screenPos = Selection;
  }
  if (Selection > screenPos + BOXES - 1) {
    screenPos = Selection - BOXES + 1;
  }
}
