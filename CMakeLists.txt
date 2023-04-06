cmake_minimum_required(VERSION 3.0.0)
project(Jak_Dojade VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG  "-g")

file(GLOB source_files CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")


add_executable(Jak_Dojade ${source_files})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
