set(SOURCE_DIR "Source")

set(SOURCES
        main.cpp
        align.cpp
        arrive.cpp
        behavior.cpp
        flee.cpp
        kinematic.cpp
        mover.cpp
        seek.cpp
        steeringoutput.cpp
        vec2.cpp
)

# Add the executable target
add_executable(steering ${SOURCES})
set_target_properties(steering PROPERTIES OUTPUT_NAME prog.x)
#target_include_directories(steering PRIVATE ${PROJECT_SOURCE_DIR}/external/raylib/src)
#target_include_directories(steering PRIVATE ${PROJECT_SOURCE_DIR}/external/)

target_link_libraries(steering PRIVATE imgui)
target_link_libraries(steering PRIVATE raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
#if (APPLE)
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
#endif()