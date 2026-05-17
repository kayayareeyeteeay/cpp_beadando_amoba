cmake_minimum_required(VERSION 3.30.5)
project(CLionGraphicsKit)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(graphics graphics.cpp)

include_directories(include)
link_directories(lib)

target_link_libraries( graphics SDL2 SDL2.dll SDL2main SDL2_ttf SDL2_ttf.dll)


add_executable(CLionGraphicsKit main.cpp
        Application.cpp
        Application.hpp
        JatekMester.cpp
        JatekMester.hpp
        AmobaWidget.cpp
        AmobaWidget.hpp
        SelectorWidget.cpp
        SelectorWidget.hpp
        Widget.cpp
        Widget.hpp
        NumericWidget.cpp
        NumericWidget.hpp
        LabelWidget.cpp
        LabelWidget.hpp
)
target_link_libraries(CLionGraphicsKit graphics)
