set(SOURCE_DIR "Source")

set(SOURCES
        TestShaderCode.cpp
)

# Add the executable target
add_executable(shader ${SOURCES})
set_target_properties(shader PROPERTIES OUTPUT_NAME prog.x)
#target_include_directories(steering PRIVATE ${PROJECT_SOURCE_DIR}/external/raylib/src)
#target_include_directories(steering PRIVATE ${PROJECT_SOURCE_DIR}/external/)

target_link_libraries(shader PRIVATE imgui)
target_link_libraries(shader PRIVATE raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
#if (APPLE)
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
#    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
#endif()