/**
 * @file
 * @copyright Copyright (c) 2022-2023.
 */

#pragma once

#include <map>
#include <optional>
#include <string>
#include <vector>

namespace argParser {

/**
 * @brief Command line arguments parser.
 */
class CmdLineParser
{
public:
    /**
     * @brief Parse the command line arguments.
     *
     * @param argc Number of command line arguments.
     * @param argv Command line arguments.
     */
    void parse(const int argc, char const* argv[]);

    /**
     * @brief Get the command line arguments.
     *
     * @return Command line arguments.
     */
    std::vector<std::string> getArgs() const;

    /**
     * @brief Check if the command line arguments has the option specified.
     *
     * This method is useful to check if, for example, a `<option>` is passed to the command line arguments.
     *
     * @param option Command line option to check if was passed.
     *
     * @return True if the option was passed, false otherwise.
     */
    bool hasOption(const std::string& option) const;

    /**
     * @brief Get the value for the option specified.
     *
     * This method is useful to check if, for example, a `<option> <option_value>` is passed to the command line
     * arguments, and to get the option value.
     *
     * @param option Command line option to check if was passed and to get its value.
     *
     * @return Command line option value if the option was passed, a null optional otherwise.
     */
    std::optional<std::string> getOption(const std::string& option) const;

    /**
     * @brief Set the application name.
     *
     * The application name is used when the version information is shown.
     *
     * @param name Application name.
     */
    void setAppName(const std::string& name);

    /**
     * @brief Get the application name.
     *
     * @return Application name.
     */
    std::string getAppName() const;

    /**
     * @brief Set the application version.
     *
     * The application version is used when the version information is shown.
     *
     * @param version Application version.
     */
    void setAppVersion(const std::string& version);

    /**
     * @brief Get the application version.
     *
     * @return Application version.
     */
    std::string getAppVersion() const;

    /**
     * @brief Set the application description.
     *
     * The application description is used when the version information is shown.
     *
     * @param description Application description.
     */
    void setAppDescription(const std::string& description);

    /**
     * @brief Get the application description.
     *
     * @return Application description.
     */
    std::string getAppDescription() const;

    /**
     * @brief Show the version information.
     *
     * Example:
     * - Application name: Parser
     * - Application version: 1.0.0
     * - Application description: Command line arguments parser
     * - Output:
     * @code
     * Parser 1.0.0
     * Command line arguments parser
     * @endcode
     */
    void showVersion() const;

    /**
     * @brief Set the application usage information.
     *
     * The application usage information is used when the help message is shown.
     *
     * @param exeName Executable name of the application.
     * @param optionsUsageInfo Usage information of the options.
     * @param options Map with the options.
     */
    void setAppUsageInfo(const std::string& exeName,
                         const std::string& optionsUsageInfo,
                         const std::map<std::string, std::string>& options);

    /**
     * @brief Get the executable name of the application.
     *
     * @return Executable name of the application.
     */
    std::string getExeAppName() const;

    /**
     * @brief Get the usage information of the options.
     *
     * @return Usage information of the options.
     */
    std::string getOptionsUsageInfo() const;

    /**
     * @brief Get the command line options defined to be used in the help message.
     *
     * @return Map with the options.
     */
    std::map<std::string, std::string> getOptions() const;

    /**
     * @brief Show the help message.
     *
     * Example:
     * - exeName: ParserExe
     * - optionsUsageInfo: [OPTIONS]
     * - options: "-h, --help", "show help message"
     * - Output:
     * @code
     * Usage: ParserExe [OPTIONS]
     *
     *     -h, --help        show help message
     * @endcode
     */
    void showHelp() const;

private:
    /// Arguments.
    std::vector<std::string> mArgs{};

    /// Application name.
    std::string mAppName{};
    /// Application version.
    std::string mAppVersion{};
    /// Application description.
    std::string mAppDescription{};

    /// Executable name of the application.
    std::string mExeAppName{};
    /// Usage information of the options.
    std::string mOptionsUsageInfo{};
    /// Map with the options.
    std::map<std::string, std::string> mOptions{};
};

} // namespace argParser
