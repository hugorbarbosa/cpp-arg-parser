/**
 * @file
 * @copyright Copyright (c) 2022.
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
    const auto argParser{std::make_unique<argParser::CmdLineParser>()};

    // Set application information
    argParser->setAppName("Application name");
    argParser->setAppVersion("1.0.0");
    argParser->setAppDescription("Application description");

    // Set application usage information
    const std::map<std::string, std::string> options{
        {"-h, --help", "show help message"},
        {"-v, --version", "show version"},
        {"-V, --verbose", "enable verbose messages"},
        {"-f, --file", "file path"},
    };
    argParser->setAppUsageInfo("AppExec", "-f <file_path> [OPTIONS]", options);

    // Parse
    argParser->parse(argc, argv);

    // Check help option
    if (argParser->hasOption("-h") || argParser->hasOption("--help")) {
        argParser->showHelp();
        return 0;
    }

    // Check version option
    if (argParser->hasOption("-v") || argParser->hasOption("--version")) {
        argParser->showVersion();
        return 0;
    }

    // Check verbose option (option example)
    auto verbose{false};
    if (argParser->hasOption("-V") || argParser->hasOption("--verbose")) {
        verbose = true;
    }

    // File path (required option example, with value)
    auto option{argParser->getOption("-f")};
    if (option.empty()) {
        option = argParser->getOption("--file");
        if (option.empty()) {
            std::cout << "Missing file path" << std::endl;
            std::cout << std::endl;
            argParser->showHelp();
        }
    }
    if (!option.empty()) {
        std::cout << "File path: " << option << std::endl;
    }

    return 0;
}
