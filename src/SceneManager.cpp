#include <Core/SceneManager.h>
#include <Core/Scene.h>
#include <Core/ErrorLog.h>

SceneManager::SceneManager()
{
	this->current = "";
	this->scenes = new std::unordered_map<std::string, Scene*>(); // TODO: make it a stack
}

SceneManager::~SceneManager()
{
	
	delete scenes;
}

void SceneManager::createScene(const char* name, Scene* scene)
{
	this->scenes->insert(std::unordered_map<std::string, Scene*>::value_type((std::string)name, scene));
}

void SceneManager::destroyScene(const char* name)
{
	if (this->scenes->at(name))
	{
		fERROR("Cannot find scene\n");
		exit(0);
	}
	this->scenes->erase(name);
}

void SceneManager::selectScene(const char* name)
{
	if (this->scenes->empty())
	{
		fERROR("Cannot select scene, scenes is empty\n");
		exit(0);
	}
	this->current = name;
}

Scene* SceneManager::getCurrent()
{
	if (this->scenes->empty())
	{
		fERROR("Cannot get current scene, scenes is empty\n");
		exit(0);
	}
	return this->scenes->at(this->current);
}

