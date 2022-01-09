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

        src/engine/session.hpp src/engine/session.cpp
        src/engine/game_state.hpp

        src/engine/engine.hpp src/engine/engine.cpp
        src/engine/subsys/graphics.hpp src/engine/subsys/graphics.cpp
        src/engine/subsys/input.hpp src/engine/subsys/input.cpp

        src/engine/engine_controller.hpp src/engine/engine_controller.cpp
        src/engine/subsys/graphics_controller.hpp src/engine/subsys/graphics_controller.cpp
        src/engine/subsys/input_controller.hpp src/engine/subsys/input_controller.cpp

        src/engine/io/scancode.hpp
        src/engine/io/mouse.hpp
        src/engine/io/keybinding.hpp

        src/engine/assert.hpp src/engine/assert.cpp

        src/engine/media/texture.cpp src/engine/media/texture.hpp

        src/engine/3d/camera.cpp src/engine/3d/camera.hpp
        src/engine/3d/transform.cpp src/engine/3d/transform.hpp

        src/engine/prim/ivec.hpp
        src/engine/prim/fvec.hpp
        src/engine/prim/fmat.hpp
        src/engine/prim/color.hpp
        src/engine/prim/units.hpp
        )

target_include_directories(RenderEngine3d PRIVATE "${SOURCE_INCLUDES}" "${EXTERNAL_INCLUDES}")
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