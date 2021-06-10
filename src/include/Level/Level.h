#ifndef LEVEL_H
#define LEVEL_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include <vector>
#include <map>

class Level
{
public:
    Level();
    virtual ~Level();

    void loadLevel(const char* path);

private:
    char* jsonLevel;
    rapidjson::Document jsonDocument;

    std::map<int, int>* inputItems; // first int for quantity and second for item id
};

#endif // LEVEL_H