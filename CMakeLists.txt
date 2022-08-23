# CMakeList.txt: projeto de CMake para python-nbiobsp, incluir origem e definir
# lógica específica a um projeto aqui.

cmake_minimum_required (VERSION 3.8)

project ("pynviobsp")


include_directories(${PROJECT_SOURCE_DIR}/include)


add_library(NBioBSP SHARED IMPORTED)
set_property(TARGET NBioBSP PROPERTY IMPORTED_IMPLIB "C:\\Program Files\\NITGEN eNBSP x64\\SDK\\Lib\\x64\\NBioBSP.lib")

# Generate Python module
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG        v2.10.0
)

FetchContent_GetProperties(pybind11)
if(NOT pybind11_POPULATED)
    FetchContent_Populate(pybind11)
    add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()

pybind11_add_module(pynbiobsp "src/main.cpp")

target_link_libraries(pynbiobsp PRIVATE NBioBSP)
