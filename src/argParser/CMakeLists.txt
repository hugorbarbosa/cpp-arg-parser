# ----------------------------------------------------------------------------
# Project setup
project(ArgParser)

# ----------------------------------------------------------------------------
# Library
add_library(${PROJECT_NAME} STATIC
    CmdLineParser.cpp
)
add_library(SimpleArgParser::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# ----------------------------------------------------------------------------
# Build

target_include_directories(${PROJECT_NAME}
    PUBLIC .
)
