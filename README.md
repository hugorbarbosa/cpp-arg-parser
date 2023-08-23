# C++ arguments parser

A simple C++ command line arguments parser.

## Table of contents

- [Project structure](#project-structure)
- [Features](#features)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Running](#running)
- [Tests](#tests)
- [License](#license)

## Project structure

This project is structured in the following directories:

- `cmake`: useful CMake files.
- `src`: source code of the project.
- `tests`: files related with tests.

## Features

The command line arguments parser of this project is a simple parser that allows the following:

- Check if a command line option was passed (for example, `-h` or `--help`).
- Get the value of a command line option (for example, `-f <value>` or `--file <value>`).
- Show a help message.
- Show a version information message.

The parser is implemented [here](./src/argParser/). An example of how to use it can be seen in the following code snippet (extracted from [here](./src/main.cpp)).

```C++
#include <argParser/CmdLineParser.h>
#include <iostream>

int main(int argc, char const* argv[])
{
    // Arguments parser instance
    argParser::CmdLineParser argParser{};

    // Set application information
    argParser.setAppName("Application name");
    argParser.setAppVersion("1.0.0");
    argParser.setAppDescription("Application description");

    // Set application usage information
    const std::map<std::string, std::string> options{
        {"-h, --help", "show help message"},
        {"-v, --version", "show version"},
        {"-V, --verbose", "enable verbose messages"},
        {"-f, --file", "file path"},
    };
    argParser.setAppUsageInfo("AppExec", "-f <file_path> [options]", options);

    // Parse
    argParser.parse(argc, argv);

    // Check if help option was passed
    if (argParser.hasOption("-h") || argParser.hasOption("--help")) {
        argParser.showHelp();
        return EXIT_SUCCESS;
    }

    // Check if version option was passed
    if (argParser.hasOption("-v") || argParser.hasOption("--version")) {
        argParser.showVersion();
        return EXIT_SUCCESS;
    }

    // File path (example of a mandatory option, with value)
    auto option = argParser.getOption("-f");
    if (!option.has_value()) {
        option = argParser.getOption("--file");
        if (!option.has_value()) {
            std::cout << "Missing file path\n" << std::endl;
            argParser.showHelp();
            return EXIT_SUCCESS;
        }
    }
    std::cout << "File path: " << option.value() << std::endl;

    // Check if verbose option was passed (example of a not mandatory option)
    bool verbose{false};
    if (argParser.hasOption("-V") || argParser.hasOption("--verbose")) {
        verbose = true;
    }
    std::cout << "Verbose option passed: " << std::boolalpha << verbose << std::endl;

    return EXIT_SUCCESS;
}
```

The information related to the application (name, version and description) is used when the version information message is shown. The application usage information (executable name and available options) is utilized in the help message.

The following are some results using the options available in this example:

- Specifying the help option:
    ```sh
    $ ./SimpleArgParser -h
    Usage: AppExec -f <file_path> [options]
        -V, --verbose           enable verbose messages
        -f, --file              file path
        -h, --help              show help message
        -v, --version           show version
    ```
- Specifying the version option:
    ```sh
    $ ./SimpleArgParser -v
    Application name 1.0.0
    Application description
    ```
- Without specifying options (`-f <file_path>` is required in this example):
    ```sh
    $ ./SimpleArgParser
    Missing file path

    Usage: AppExec -f <file_path> [OPTIONS]
        -V, --verbose           enable verbose messages
        -f, --file              file path
        -h, --help              show help message
        -v, --version           show version
    ```

## Requirements

Necessary tools:

- CMake: system to manage the build process.
- C++ compiler: for software compilation.

## Compilation

The CMake options for configuration of this project are:

| CMake option | Description | Default value |
| --- | --- | --- |
| BUILD_TESTS | Build unit tests | OFF |

The following commands can be utilized to configure the project (example for Debug configuration):

```sh
$ cd <project-directory>
$ mkdir build-debug
$ cd build-debug
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
```

To compile the software, use the following command:

```sh
$ cmake --build . -j 4
```

## Running

After compiling the project, an executable file is created and can be run using the following command (note that some configuration generators (e.g., Visual Studio) may add a configuration folder (e.g., Debug) in the path):

```sh
$ ./bin/<config>/SimpleArgParser
```

## Tests

To run the unit tests, use the commands below (note that it is necessary to configure CMake with `BUILD_TESTS` option to ON):

```sh
$ cd <project-directory>
$ mkdir build-debug
$ cd build-debug
$ cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON
$ cmake --build . -j 4
$ ctest
```

## License

Licensed under the [MIT license](./LICENSE).
