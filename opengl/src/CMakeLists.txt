set(SOURCE_DIR "Source")

set(SOURCES
        triangle.cpp
)

# Add the executable target
add_executable(opengl ${SOURCES})
set_target_properties(opengl PROPERTIES OUTPUT_NAME opengl.x)
#target_include_directories(A1 PRIVATE ${PROJECT_SOURCE_DIR}/external/)
#target_include_directories(A1 PRIVATE ${PROJECT_SOURCE_DIR}/external/)
#target_include_directories(A1 PRIVATE ${PROJECT_SOURCE_DIR}/external/glad/include)
#target_include_directories(A1 PRIVATE ${PROJECT_SOURCE_DIR}/external/glfw/include)
#target_include_directories(A1 PRIVATE ${PROJECT_SOURCE_DIR}/external/glm)
target_link_libraries(opengl glad)
target_link_libraries(opengl glfw)