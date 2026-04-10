#imgui library
set(GLADSRC
        src/glad.c)
add_library(glad STATIC ${GLADSRC})
#target_link_libraries(imgui glfw)
#target_include_directories(glad PRIVATE ${PROJECT_SOURCE_DIR}/external/glad/include)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(glad PROPERTIES OUTPUT_NAME glad)
set_target_properties(glad PROPERTIES FOLDER "Dependencies")