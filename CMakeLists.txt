cmake_minimum_required(VERSION 3.16)
project(FruitFactory)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/") 

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories("src/include" ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(FruitFactory "src/main.cpp" 
	"src/Game.cpp" 
	"src/WindowManager.cpp"
	"src/SceneManager.cpp"
	"src/Scene.cpp"
	"src/TestScene.cpp"
	"src/InputController.cpp"
	"src/Sprite.cpp"
	"src/Entity.cpp"
	"src/BananaBox.cpp"
	"src/EntityManager.cpp")


target_link_libraries(FruitFactory ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
