#ifndef INPUT_BLOCK_H
#define INPUT_BLOCK_H

#include <Core/Entity.h>

class InputBlock : public Entity
{
public:
    InputBlock(struct SpriteData spr);
    virtual ~InputBlock();

    // Entity functions...
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

#endif // INPUT_BLOCK_H