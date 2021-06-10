#ifndef INPUT_BLOCK_H
#define INPUT_BLOCK_H

#include <Core/Entity.h>

class InputBlock : public Entity
{
public:
    InputBlock();
    virtual ~InputBlock();

    // Entity functions...
    void render(SDL_Renderer* renderer) override;
    void update(const float dt) override;
    void inputHandler() override;
private:
    
};

#endif // INPUT_BLOCK_H