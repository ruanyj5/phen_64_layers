cmake_minimum_required(VERSION 3.15)
project(open_MP_SOS_v1)

set(CMAKE_CXX_STANDARD 20)

# set multi .cpp
aux_source_directory(. DIRSRCS)
add_executable(open_MP_SOS_v1 ${DIRSRCS})


#target_link_libraries(open_MP_EOS_v1 gdal)

set(CMAKE_C_FLAGS "-fopenmp")
set(CMAKE_CXX_FLAGS "-fopenmp")
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -g -Wall  -O2")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -g -Wall -O2")


# gdal
find_package(GDAL REQUIRED)

message(STATUS "GDAL library status:")
message(STATUS "    version: ${GDAL_VERSION}")
message(STATUS "    libraries: ${GDAL_LIBRARY}")
message(STATUS "    include path: ${GDAL_INCLUDE_DIRS}")

include_directories(${GDAL_INCLUDE_DIRS})
target_link_libraries(open_MP_SOS_v1 ${GDAL_LIBRARY})

