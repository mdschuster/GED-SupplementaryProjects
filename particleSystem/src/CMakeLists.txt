set(SOURCE_DIR "Source")

set(SOURCES
        main.cpp
        particlesystem.cpp
        profiler.cpp
        vec2.cpp
)

# Add the executable target
add_executable(particle ${SOURCES})
set_target_properties(particle PROPERTIES OUTPUT_NAME prog.x)
#target_include_directories(particle PRIVATE ${PROJECT_SOURCE_DIR}/external/raylib/src)
#target_include_directories(particle PRIVATE ${PROJECT_SOURCE_DIR}/external/)

target_link_libraries(particle PRIVATE imgui)
target_link_libraries(particle PRIVATE raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
#if (APPLE)
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
#endif()