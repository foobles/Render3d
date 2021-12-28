cmake_minimum_required(VERSION 3.17)
project(RenderEngine3d)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_INCLUDES "src")

find_package(sdl2 REQUIRED)
find_package(sdl2_ttf REQUIRED)

set(EXTERNAL_INCLUDES "${SDL2_INCLUDE};${SDL2_TTF_INCLUDE}")
set(EXTERNAL_LIBRARIES "${SDL2_LIBRARIES};${SDL2_TTF_LIBRARIES}")
set(EXTERNAL_DLLS "${SDL2_DLL};${SDL2_TTF_DLLS}")

add_executable(RenderEngine3d
        src/main.cpp

        src/session.hpp src/session.cpp
        src/game_state.hpp

        src/engine.hpp src/engine.cpp
        src/graphics.hpp src/graphics.cpp
        src/input.hpp src/input.cpp

        src/engine_controller.hpp src/engine_controller.cpp
        src/graphics_controller.hpp src/graphics_controller.cpp
        src/input_controller.hpp src/input_controller.cpp

        src/scancode.hpp
        src/mouse.hpp
        src/keybinding.hpp

        src/ivec2.hpp
        src/color.hpp
        src/units.hpp
        src/assert.hpp src/assert.cpp
)

target_include_directories(RenderEngine3d PRIVATE SOURCE_INCLUDES "${EXTERNAL_INCLUDES}")
target_link_libraries(RenderEngine3d PRIVATE "${EXTERNAL_LIBRARIES}")

foreach(DLL ${EXTERNAL_DLLS})
    string(STRIP "${DLL}" DLL)
    add_custom_command(
            TARGET RenderEngine3d
            POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${DLL}"
            $<TARGET_FILE_DIR:RenderEngine3d>
    )
endforeach()