#ifndef LEVEL_H
#define LEVEL_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>

class Level
{
public:
    Level();
    virtual ~Level();

    void loadLevel(const char* path);

private:
    char* jsonLevel;
    rapidjson::Document jsonDocument;
};

#endif // LEVEL_H