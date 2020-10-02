#include "common.hpp"
#include "structs.hpp"

#include "gameManagement.hpp"

#include <vector>

#define ENTRIES_PER_SCREENN

class SDMenu : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
private:

	
	int selectedTitle = 0;
	bool GameSelected   = false;
	int maxTitles;

	mutable int screenPos = 0;
	mutable int screenPosList = 0;
	mutable int selection = 0;
	int Selection = 0;
	std::vector<Structs::ButtonPos> mainButtons = {
		{10, 40, 48, 48}, // Button 1.
		{10, 100, 48, 48}, // Button 2.
		{10, 160, 48, 48}, // Button 3.
                {68, 40, 48, 48},
                {68, 100, 48, 48},
                {68, 160, 48, 48},
                {126, 40, 48, 48},
                {126, 100, 48, 48},
                {126, 160, 48, 48},
                {184, 40, 48, 48},
                {184, 100, 48, 48},
                {184, 160, 48, 48},
                {242, 40, 48, 48},
                {242, 100, 48, 48},
                {242, 160, 48, 48},
       
	};
    std::shared_ptr<TitleManagement> titleFromIndex(int i) const
	{
		if (i == -2)
		{
			return nullptr;
		}
		else if ((size_t)i < GameManagement::installedTitles.size())
		{
			return GameManagement::installedTitles[i];
		}
		return nullptr;
	}
};
