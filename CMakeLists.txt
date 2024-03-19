cmake_minimum_required(VERSION 3.17)
include(GNUInstallDirs)

project(KMLTool
    VERSION 1.0
    DESCRIPTION "a KML Tool"
    LANGUAGES CXX
    )


# add_executable(
#     reader
#     src/reader.cpp
#     lib/pugixml/pugixml.cpp
# )
add_executable(
    kmltool_gui
    src/kmltool_gui.cpp
    src/reader.cpp
    lib/ui/kmltool.cpp
    lib/pugixml/pugixml.cpp
)

find_package(LibArchive REQUIRED)
# target_link_libraries(kmltool_gui PRIVATE LibArchive::LibArchive)

find_package(wxWidgets REQUIRED COMPONENTS net core base xrc)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
# set(LIB_SOURCES wxWidgets_LIBRARIES LibArchive::LibArchive)
target_link_libraries(kmltool_gui ${wxWidgets_LIBRARIES}  LibArchive::LibArchive)
