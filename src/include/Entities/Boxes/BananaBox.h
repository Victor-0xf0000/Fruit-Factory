#ifndef BANANA_BOX_H
#define BANANA_BOX_H

#include <Core/Entity.h>

class BananaBox: public Entity
{
public:
    BananaBox(class SpriteData* spr);
    ~BananaBox();

    void render(SDL_Renderer* renderer) override;
    void update(const float dt) override;
    void inputHandler() override;
private:

};

#endif // BANANA_BOX_H