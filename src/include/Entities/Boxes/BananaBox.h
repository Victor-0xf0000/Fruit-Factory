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
    void setX(int x) override {this->x = x * 100 + 50;};
    void setY(int y) override {this->y = y * 100 + 50;};
private:

};

#endif // BANANA_BOX_H