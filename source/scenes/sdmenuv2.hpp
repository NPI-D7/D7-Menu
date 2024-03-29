#pragma once
#include "common.hpp"

#include "TitleManager.hpp"

#include <vector>

#define ENTRIES_PER_SCREENN 15

class SDMenu : public RenderD7::Scene {
public:
  void Draw(void) const override;
  void Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) override;
  SDMenu();

private:
  int selectedTitle = 0;
  bool GameSelected = false;
  int maxTitles;

  mutable int screenPos = 0;
  mutable int screenPosList = 0;
  mutable int selection = 0;
  int Selection = 0;
  std::vector<RenderD7::TLBtn> mainButtons = {
      {20, 37, 48, 48},   {78, 37, 48, 48},   {136, 37, 48, 48},
      {194, 37, 48, 48},  {252, 37, 48, 48},  {20, 97, 48, 48},
      {78, 97, 48, 48},   {136, 97, 48, 48},  {194, 97, 48, 48},
      {252, 97, 48, 48},  {20, 157, 48, 48},  {78, 157, 48, 48},
      {136, 157, 48, 48}, {194, 157, 48, 48}, {252, 157, 48, 48},

  };
  std::shared_ptr<Title> titleFromIndex(int i) const {
    if (i == -2) {
      return nullptr;
    } else if ((size_t)i < TitleManager::sdtitles.size()) {
      return TitleManager::sdtitles[i];
    }
    return nullptr;
  }
};
