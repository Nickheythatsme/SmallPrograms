cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(CellSimulation)

# Add the libraries and files from src
add_subdirectory(cell)

# Define the sources for the executable
set(SOURCES
    main.cpp
    )

# Make the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the libraries to the executable
target_link_libraries(${PROJECT_NAME}
    cell
    )

enable_testing()
