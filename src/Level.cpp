#include <Level/Level.h>
#include <Core/ErrorLog.h>
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
        char* str = (char*) malloc(sizeof(char*) * 100);
        strcpy(str, "\0");


        std::vector<int> v; // numbers
        for (int i = 0; i < this->jsonDocument["input"].GetArray().Size(); i++)
        {
            strcpy(str, this->jsonDocument["input"].GetArray()[i].GetString());
            strcat(str, "\0");

            // get quantity
            int q = 0;
            int mode = 0; // 0 = read number, 1 = read item
            int cnt = 0; // for count the index of item
            std::string s;


            for (int c = 0; c < strlen(str); c++)
            {
                if (str[c] != ' ')
                {
                    if (mode == 1) // case the mode is read item
                    {
                        if (c == strlen(str))
                        {
                            printf("str: %s\n", s);
                            s = "";
                        }
                        else
                            printf("c: %c\n", str[c]);
                    }
                    if (mode == 0) // case the mode is read number
                    {
                        if (str[c] == 'x')
                        {
                            q = atoi(s.c_str());
                            v.push_back(q);
                            s = "";
                            mode = 1;
                        }
                    }
                   
                    s += str[c];
                }
            }
            // reset...
            cnt = 0;
            s = "\0";
            mode = 0;
            q = 0;

        }
        free(str);
    }

    LOG("Level load finished.");
}