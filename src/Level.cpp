#include <Level/Level.h>
#include <Core/ErrorLog.h>
#include <Core/Scene.h>
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
    fLOG("Loading level...");
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

    this->jsonDocument.Parse(this->jsonLevel);

    if (this->jsonDocument.HasMember("input"))
    {
        for (size_t i = 0; i < this->jsonDocument["input"].GetArray().Size(); i++)
        {
            this->inputItems->insert(std::unordered_map<int, int>::value_type(
                this->jsonDocument["input"].GetArray()[i].GetArray()[0].GetInt(),
                this->jsonDocument["input"].GetArray()[i].GetArray()[0].GetInt()            
            ));
        }
    }

    if (this->jsonDocument.HasMember("entities"))
    {
        for (size_t i = 0; i < this->jsonDocument["entities"].GetArray().Size(); i++)
        {
            EntityType entityId = (EntityType) this->jsonDocument["entities"].GetArray()[i][0].GetInt();
            if (entityId == EntityType::bananaBox)
            {
                int x = this->jsonDocument["entities"].GetArray()[i][2].GetInt();
                int y = this->jsonDocument["entities"].GetArray()[i][3].GetInt();
                SpriteData sd = SpriteData();
                sd.ssx = 0;
                sd.ssy = 0;
                sd.width = 16;
                sd.height = 16;
                sd.scale = 3;
                BananaBox* box = new BananaBox(sd);
                box->setX(x);
                box->setY(y);
                game->getEntityManager()->addEntity(box);
            }
        }
    }
    fLOG("Level load finished.");
}

void Level::saveEntities(Scene* scene, const char* path)
{
    fLOG("Saving level...");
    this->jsonDocument["entities"].GetArray().Clear();

    int iEntity = 0;
    for (auto i : scene->getEntityManager()->getEntities())
    {
        rapidjson::Value entity(rapidjson::kArrayType);
        entity.PushBack(i->getType(), this->jsonDocument.GetAllocator()); // add type
        entity.PushBack(iEntity, this->jsonDocument.GetAllocator()); // add id (id is a string, but it's converted to int)
        entity.PushBack(i->getX(), this->jsonDocument.GetAllocator()); // add x
        entity.PushBack(i->getY(), this->jsonDocument.GetAllocator()); // add y
        this->jsonDocument["entities"].PushBack(entity, this->jsonDocument.GetAllocator());
        iEntity++;
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    this->jsonDocument.Accept(writer);
    const char* output = buffer.GetString();

    std::ofstream outfile((std::string)path);
    if (outfile.is_open())
    {
        outfile << output;
    }

    fLOG("Level save complete");
}

void Level::saveBlockmap(EntityType* blockMap[11*11], const char* path)
{
    fLOG("Saving blockmap...");

    this->jsonDocument["blockmap"].GetArray().Clear();

    for (int i = 0; i < 11; i++)
    {
        rapidjson::Value array(rapidjson::kArrayType);
        for (int j = 0; j < 11; j++)
        {
            array.PushBack(*blockMap[i + j * 11], this->jsonDocument.GetAllocator());
        }
        this->jsonDocument["blockmap"].PushBack(array, this->jsonDocument.GetAllocator());
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    this->jsonDocument.Accept(writer);
    const char* output = buffer.GetString();

    std::ofstream outfile((std::string)path);
    if (outfile.is_open())
    {
        outfile << output;
    }

    fLOG("blockmap save complete");
}

void Level::loadBlockmap(EntityType* blockmap[11*11], const char* path)
{

    fLOG("Loading level...");
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

    this->jsonDocument.Parse(this->jsonLevel);

    if (this->jsonDocument.HasMember("blockmap"))
    {
        for (size_t i = 0; i < this->jsonDocument["blockmap"].GetArray().Size(); i++)
        {
            for (size_t j = 0; j < this->jsonDocument["blockmap"].GetArray()[i].GetArray().Size(); j++)
            {
                *blockmap[i + j*11] = (EntityType) this->jsonDocument["blockmap"].GetArray()[i].GetArray()[j].GetInt();
            }
        }
    }

    if (this->jsonDocument.HasMember("entities"))
    {
        for (size_t i = 0; i < this->jsonDocument["entities"].GetArray().Size(); i++)
        {
            EntityType entityId = (EntityType) this->jsonDocument["entities"].GetArray()[i][0].GetInt();
            if (entityId == EntityType::bananaBox)
            {
                int x = this->jsonDocument["entities"].GetArray()[i][2].GetInt();
                int y = this->jsonDocument["entities"].GetArray()[i][3].GetInt();
                SpriteData sd = SpriteData();
                sd.ssx = 0;
                sd.ssy = 0;
                sd.width = 16;
                sd.height = 16;
                sd.scale = 3;
                BananaBox* box = new BananaBox(sd);
                box->setX(x);
                box->setY(y);
            }
        }
    }
    fLOG("Level load finished.");
}