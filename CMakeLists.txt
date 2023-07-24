cmake_minimum_required(VERSION 3.25)
project(Flare)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 添加自定义宏定义
add_definitions(-DFLARE_LIB)

# 包含头文件目录
include_directories(include/FlareUI)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/msvc2019_64")

# 查找并链接 Qt 库
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

# 添加目标源文件
set(SOURCES
        BaseButton.cpp
        PushButton.cpp
        ListView.cpp
        Widget.cpp
        FlareColor.cpp
        SystemIcon.cpp
        ProgressBar.cpp
        RadioButton.cpp
        include/FlareUI/BaseButton.h
        include/FlareUI/PushButton.h
        include/FlareUI/ListView.h
        include/FlareUI/Widget.h
        include/FlareUI/FlareColor.h
        include/FlareUI/SystemIcon.h
        include/FlareUI/ProgressBar.h
        include/FlareUI/RadioButton.h)

# 生成静态库目标
add_library(Flare STATIC ${SOURCES})

# 链接 Qt 库
target_link_libraries(Flare PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )
