#ifndef BANANA_BOX_H
#define BANANA_BOX_H

#include <Core/Entity.h>

class BananaBox: public Entity
{
public:
    BananaBox(class SpriteData spr);
    ~BananaBox();

    void render(SDL_Renderer* renderer) override;
    void update(const float dt) override;
    void inputHandler() override;
    void setX(int x) override 
    {
        int hmgx = x / 48;
        this->x = hmgx * 48;
    }

    void setY(int y) override 
    {
        int hmgy = y / 48;
        this->y = hmgy * 48;
    }
private:

};

#endif // BANANA_BOX_H