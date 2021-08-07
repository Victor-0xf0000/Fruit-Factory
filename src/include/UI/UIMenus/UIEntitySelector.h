#ifndef UI_ENTITY_SELECTOR_H
#define UI_ENTITY_SELECTOR_H

#include <UI/UIMenu.h>
#include <vector>
#include <Entities/EntityTypes.h>

class UIEntitySelector : public UIMenu
{
public:
	UIEntitySelector(int x, int y, EntityType* type);
	virtual ~UIEntitySelector();

	void onMouseClick() override;
	void update() override;
	void render(SDL_Renderer* renderer) override;
	void addEntityOption(EntityType id);
	EntityType getEntityType() const
	{
		return *this->type;
	}
private:
	std::vector<EntityType> entityOptions;

	// Boxes to select for entity
	std::vector<class SpriteData> boxSprites;

	// Entity Manager to add entities
	EntityType* type;

	int x;
	int y;
	int bsx; // box start x
	int bsy; // box start y
	int bw; // box width
	int bh; // box height
};

#endif // UI_ENTITY_SELECTOR_H
