#include <Level/Level.h>
#include <Core/ErrorLog.h>
#include <Entities/Boxes/BananaBox.h>
#include <Game.h>
#include <fstream>
#include <iostream>
#include <string.h>


Level::Level()
{
    this->inputItems = new std::unordered_map<int, int>();   

    this->jsonLevel = (char*) malloc(sizeof(char*) * 1000);

    strcpy(this->jsonLevel, "\0");
}

Level::~Level()
{
    delete this->jsonLevel;
}

void Level::loadLevel(Game* game, const char* path)
{
    LOG("Loading level...");
    std::string ln;
    std::ifstream file(path);
    int counter = 0;

    if (file.is_open())
    {
        while (getline(file, ln))
        {
            strcat(this->jsonLevel, ln.c_str());
            strcat(this->jsonLevel, "\n");
            counter++;
        }
        strcat(this->jsonLevel, "\0");
        strcat(this->jsonLevel, "\0");
    }

    jsonDocument.Parse(this->jsonLevel);

    if (this->jsonDocument.HasMember("input"))
    {
        for (int i = 0; i < this->jsonDocument["input"].GetArray().Size(); i++)
        {
            this->inputItems->insert(std::unordered_map<int, int>::value_type(
                this->jsonDocument["input"].GetArray()[i].GetArray()[0].GetInt(),
                this->jsonDocument["input"].GetArray()[i].GetArray()[0].GetInt()            
            ));
        }
    }

    if (this->jsonDocument.HasMember("entities"))
    {
        for (int i = 0; i < this->jsonDocument["entities"].GetArray().Size(); i++)
        {
            std::string entityId = this->jsonDocument["entities"].GetArray()[i][0].GetString();
            if (entityId == "bananabox")
            {
                int x = this->jsonDocument["entities"].GetArray()[i][2].GetInt();
                int y = this->jsonDocument["entities"].GetArray()[i][3].GetInt();
                SpriteData* sd = new SpriteData();
                sd->ssx = 0;
                sd->ssy = 0;
                sd->width = 16;
                sd->height = 16;
                sd->scale = 4;
                BananaBox* box = new BananaBox(sd);
                box->setX(x);
                box->setY(y);
                game->getEntityManager()->addEntity(this->jsonDocument["entities"].GetArray()[i][1].GetString(),
                 "global\0", box);
            }
        }
    }
    LOG("Level load finished.");
}