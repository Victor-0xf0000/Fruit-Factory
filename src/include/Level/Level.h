#ifndef LEVEL_H
#define LEVEL_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include <vector>
#include <unordered_map>

#include <Entities/EntityTypes.h>

class Level
{
public:
    Level();
    virtual ~Level();

    void loadLevel(class Game* game, const char* path);
    void loadBlockmap(EntityType* map[11 * 11], const char* path);
    void saveEntities(class Scene* scene, const char* path);
    void saveBlockmap(EntityType* map[11 * 11], const char* path);

    std::unordered_map<int, int>* inputItems; // first int for quantity and second for item id
private:
    char* jsonLevel;
    rapidjson::Document jsonDocument;

};

#endif // LEVEL_H