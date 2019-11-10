
cmake_minimum_required(VERSION 3.14)
project(bridge)

set (ROOT_PATH_THIRD_PARTY "/usr/local/ssd/projects/ThirdParty" CACHE PATH "root path ThirdParty ")
set (CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/installed")



set(inc_dest "include")
set(lib_dest "lib")


add_subdirectory (lib)
add_subdirectory (app)
add_subdirectory (tests)


