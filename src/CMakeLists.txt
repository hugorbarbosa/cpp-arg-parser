# ----------------------------------------------------------------------------
# Project setup
project(SimpleArgParser)

# Subdirectories
add_subdirectory(argParser)

# ----------------------------------------------------------------------------
# Executable
add_executable(${PROJECT_NAME}
    main.cpp
)

# ----------------------------------------------------------------------------
# Build

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SimpleArgParser::ArgParser
)

# Generate executable in a specific directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
