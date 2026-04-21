cmake_minimum_required(VERSION 3.20)

project(TMPLTR)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tmpl
    src/main.cpp

    src/actions/del.cpp
    src/actions/mv.cpp
    src/actions/new.cpp
    src/actions/use.cpp
    src/utils/utils.cpp

    include/tmpltr.hpp
    include/utils/utils.hpp
)

target_include_directories(tmpl PRIVATE
    include
)