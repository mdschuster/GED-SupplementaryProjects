set(SOURCE_DIR "Source")

set(SOURCES
        main.cpp
        vec2.cpp
        ball.cpp
        physics.cpp
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME prog.x)

#Add external libraries to link, using public includes defined in the library
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)





