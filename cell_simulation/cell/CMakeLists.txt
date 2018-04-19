cmake_minimum_required(VERSION 3.5)

# Communicate that this CMakeLists file has been included
message("Including Cell library")

# Define the library name
set(LIBRARY_NAME cell)

# Define the sources to be added to the library
set(SOURCES
    seed.cpp
    seed.h
    )


# Create the library
add_library(${LIBRARY_NAME} STATIC ${SOURCES})
message("Made library: ${LIBRARY_NAME}")

# Make sure the compiler can find header files for the library
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
