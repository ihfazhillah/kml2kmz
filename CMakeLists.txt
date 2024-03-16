cmake_minimum_required(VERSION 3.17)
include(GNUInstallDirs)

project(KMLTool
    VERSION 1.0
    DESCRIPTION "a KML Tool"
    LANGUAGES CXX
    )


add_executable(
    reader
    src/reader.cpp
    lib/pugixml/pugixml.cpp
)

find_package(LibArchive REQUIRED)
target_link_libraries(reader PRIVATE LibArchive::LibArchive)

