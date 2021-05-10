#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <unordered_map>
#include <string>

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	void createScene(const char* name, class Scene* scene);
	void destroyScene(const char* name);
	void selectScene(const char* name);

	class Scene* getCurrent();

private:
	std::unordered_map<std::string, class Scene*>* scenes;
	std::string current;
};

#endif // SCENE_MANAGER_H
