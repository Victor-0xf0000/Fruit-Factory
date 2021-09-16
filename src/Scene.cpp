#include <Core/Scene.h>

#include <Game.h>

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::loadData(Game* game) {}

void Scene::inputHandler(struct InputHandler* inputHandler_s, const float dt) {}
void Scene::update(const float dt)       {}
void Scene::render(SDL_Renderer* renderer)       {}

EntityManager* Scene::getEntityManager()
{
    return this->entityManager;
}
