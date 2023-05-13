/**
 * @file
 * @copyright Copyright (c) 2022-2023.
 */

#include <argParser/CmdLineParser.h>
#include <iostream>

/**
 * @brief Main function.
 *
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 *
 * @return Program exit code.
 */
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
    argParser.setAppUsageInfo("AppExec", "-f <file_path> [OPTIONS]", options);

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
    auto option{argParser.getOption("-f")};
    if (!option.has_value()) {
        option = argParser.getOption("--file");
        if (!option.has_value()) {
            std::cout << "Missing file path\n" << std::endl;
            argParser.showHelp();
            return EXIT_SUCCESS;
        }
    }
    if (option.has_value()) {
        std::cout << "File path: " << option.value() << std::endl;
    }

    // Check if verbose option was passed (example of a not mandatory option)
    auto verbose{false};
    if (argParser.hasOption("-V") || argParser.hasOption("--verbose")) {
        verbose = true;
    }
    std::cout << "Verbose option passed: " << std::boolalpha << verbose << std::endl;

    return EXIT_SUCCESS;
}
