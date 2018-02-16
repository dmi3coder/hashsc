cmake_minimum_required(VERSION 3.7)
project(hashsc)

set(CMAKE_CXX_STANDARD 11)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(yamlcpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

set(SOURCE_FILES ./command/hashing/base64.cpp hashsc.cpp ./command/command.cpp ./command/hashing/base64_encoder_command.cpp command/stream_command.cpp command/stream_command.h stripper/stripper.cpp stripper/stripper.h)
add_executable(hashsc ${SOURCE_FILES})
add_dependencies(hashsc yamlcpp)
target_link_libraries(hashsc yaml-cpp)
