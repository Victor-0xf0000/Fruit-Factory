cmake_minimum_required(VERSION 3.16)
project(FruitFactory)

include_directories("src/include")


add_executable(FruitFactory "src/main.cpp" 
"src/Game.cpp" 
"src/Renderer.cpp"
"src/Level.cpp"
"src/Sprite.cpp"
"src/InputController.cpp"
"src/MathHelper.cpp"
# Managers
"src/WindowManager.cpp"
"src/SceneManager.cpp"
"src/EntityManager.cpp"
# Scenes
"src/Scene.cpp"
"src/TestScene.cpp"
# Entities
"src/Entity.cpp"
"src/BananaBox.cpp"
"src/InputBlock.cpp"
# UI
"src/UIComponent.cpp"
"src/UIMenu.cpp"
"src/UICButton.cpp"
"src/UIEntitySelector.cpp"
# Tiles
"src/TileSystem.cpp"
"src/StorageTile.cpp"
)

# target_compile_options(FruitFactory PRIVATE -Wall)

target_link_libraries(FruitFactory libSDL2-2.0.so.0 libSDL2_image.so libSDL2_ttf.so)
