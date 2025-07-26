cmake_minimum_required(VERSION 3.10)
project(wxwidgets_clion_project)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(wxwidgets_clion_project
        MyApp.cpp
        GameFrame.cpp
        GamePanel.cpp
        Snake.cpp
        Snake.h
        Config.h
        CellType.h
        Snake.cpp
        Direction.h
        Apple.h
        Apple.cpp
        RandomGenerator.h
        RandomGenerator.cpp
        GameBoard.h
        GameBoard.cpp)

target_link_libraries(wxwidgets_clion_project ${wxWidgets_LIBRARIES})
