#ifndef LEVEL_H
#define LEVEL_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include <vector>
#include <unordered_map>

class Level
{
public:
    Level();
    virtual ~Level();

    void loadLevel(class Game* game, const char* path);

    std::unordered_map<int, int>* inputItems; // first int for quantity and second for item id
private:
    char* jsonLevel;
    rapidjson::Document jsonDocument;

};

#endif // LEVEL_H