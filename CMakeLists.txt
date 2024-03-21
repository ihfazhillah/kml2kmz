cmake_minimum_required(VERSION 3.17)
# include(GNUInstallDirs)

project(KMLTool
    VERSION 1.0
    DESCRIPTION "a KML Tool"
    LANGUAGES CXX
    )


include(FetchContent)

# libarchive
FetchContent_Declare(
  archive
  URL https://github.com/libarchive/libarchive/releases/download/v3.7.2/libarchive-3.7.2.zip
  OVERRIDE_FIND_PACKAGE
  SOURCE_DIR libarchive
)

# wx
FetchContent_Declare(
    wxWidgets
    URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.zip
    # OVERRIDE_FIND_PACKAGE
)

set(ENABLE_TEST OFF)
set(wxBUILD_SHARED OFF)



FetchContent_MakeAvailable(archive)
FetchContent_MakeAvailable(wxWidgets)


add_library(pugixml STATIC lib/pugixml/pugixml.cpp)


add_executable(
    kmltool_gui
    src/kmltool_gui.cpp
    src/reader.cpp
    lib/ui/kmltool.cpp
)
find_package(archive)
find_package(wxWidgets)
if(NOT wxwidgets_POPULATED)
   FetchContent_Populate(wxWidagets)
   add_subdirectory(${wxwidgets_SOURCE_DIR} ${wxwidgets_BUILD_DIR})
endif()


find_package(wxWidgets COMPONENTS core base propgrid REQUIRED)
target_include_directories(kmltool_gui PRIVATE ${wxWidgets_SOURCE_DIR}/include)
target_link_libraries(kmltool_gui wxcore wxnet wxbase wxxrc archive pugixml)
