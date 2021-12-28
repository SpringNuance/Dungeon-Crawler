cmake_minimum_required (VERSION 3.8)

project ("DungeonCrawler")

set(CMAKE_BUILD_TYPE Release)

set(SFML_DIR "./libs/SFML-2.5.1_build")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

file(GLOB SOURCES 
    "src/*.cpp"
    "src/Characters/*.cpp"
    "src/DungeonGeneration/*.cpp"
    "src/Items/*.cpp"
)

set(HEADER_FILES src/Characters src/DungeonGeneration src/Items src/Graphics libs/SFML-2.5.1/include/SFML)

add_executable(DungeonCrawler ${SOURCES} ${HEADER_FILES})

target_link_libraries(DungeonCrawler sfml-graphics sfml-window sfml-system sfml-audio)
target_include_directories(DungeonCrawler PUBLIC ${HEADER_FILES})