#include <Level/Level.h>
#include <fstream>
#include <iostream>
#include <string.h>


Level::Level()
{
    

    this->jsonLevel = (char*) malloc(sizeof(char*) * 1000);

    strcpy(this->jsonLevel, "\0");
}

Level::~Level()
{
    delete this->jsonLevel;
}

void Level::loadLevel(const char* path)
{
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
    printf("Level:\n%s\n", this->jsonLevel);

    jsonDocument.Parse(this->jsonLevel);

    // EXAMPLE: 
    // if (d["layer1"].HasMember("cupcake machine"))
    // {
    //     printf("cupcake machine first input: %s\n", d["layer1"].GetObject()["cupcake machine"].GetObject()["input"].GetArray()[0].GetString());
    // }
    // else 
    // {
    //     printf("Here's position? :(\n");
    // }
}