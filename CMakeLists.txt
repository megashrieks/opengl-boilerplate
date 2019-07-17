cmake_minimum_required(VERSION 2.8)

project(my-first-graphics-app)

include_directories(./lib/)
add_subdirectory("~/custom/glfw/" "./build/")
file(GLOB_RECURSE RES_FILES *.frag *.vert)
add_executable(${PROJECT_NAME} "Application.cpp" "./lib/VertexBuffer.cpp" ${RES_FILES})
include_directories("~/custom/glfw/include/")


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(my-first-graphics-app glfw GLEW ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.vert
        ${CMAKE_CURRENT_BINARY_DIR}/res/shaders/basic.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.frag
        ${CMAKE_CURRENT_BINARY_DIR}/res/shaders/basic.frag COPYONLY)