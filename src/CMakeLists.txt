# Fix for eclipse C++11 headers
set (CMAKE_CXX_COMPILER_ARG1 "-std=c++11")

project (LorenzAttractor)

set(CMAKE_BUILD_TYPE "Release")

set (ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 -w -m64 -fno-omit-frame-pointer -fopenmp")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROOT_DIR}/CMake/Modules/")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ROOT_DIR}/../build/")
message( "output: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

find_package( OpenCV REQUIRED )
file(GLOB LorenzAttractor_SOURCES *.cpp)

add_executable( LorAttr ${LorenzAttractor_SOURCES} )
target_link_libraries( LorAttr ${OpenCV_LIBS} )
