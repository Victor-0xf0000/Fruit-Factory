cmake_minimum_required(VERSION 3.16)
project(FruitFactory)

include_directories("src/include")

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
"src/EntityManager.cpp"
"src/Renderer.cpp")

add_compile_options("-Wall -Werror")

target_link_libraries(FruitFactory libSDL2-2.0.so.0 libSDL2_image.so)