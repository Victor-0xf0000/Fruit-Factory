cmake_minimum_required(VERSION 3.18)
project(FruitFactory)


include_directories("src/include")

add_executable(FruitFactory "src/main.cpp")

target_link_libraries(FruitFactory "lib/SDL2" "lib/SDL2main" "lib/SDL2_image")
