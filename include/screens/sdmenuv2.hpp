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
		{15, 37, 48, 48}, // Button 1.
		{15, 97, 48, 48}, // Button 2.
		{15, 157, 48, 48}, // Button 3.
                {73, 37, 48, 48},
                {73, 97, 48, 48},
                {73, 157, 48, 48},
                {131, 37, 48, 48},
                {131, 97, 48, 48},
                {131, 157, 48, 48},
                {189, 37, 48, 48},
                {189, 97, 48, 48},
                {189, 157, 48, 48},
                {247, 37, 48, 48},
                {247, 97, 48, 48},
                {247, 157, 48, 48},
       
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
