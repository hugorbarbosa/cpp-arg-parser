/**
 * @file
 * @copyright Copyright (c) 2022.
 */

#include "CmdLineParser.h"
#include <algorithm>
#include <iostream>

namespace argParser {

void CmdLineParser::parse(const int argc, char const* argv[])
{
    for (auto i{0}; i < argc; ++i) {
        mArgs.push_back(std::string(argv[i]));
    }
}

std::vector<std::string> CmdLineParser::getArgs() const
{
    return mArgs;
}

bool CmdLineParser::hasOption(const std::string& option) const
{
    const auto it{std::find(mArgs.cbegin(), mArgs.cend(), option)};

    return (it != mArgs.cend()) ? true : false;
}

std::string CmdLineParser::getOption(const std::string& option) const
{
    auto it{std::find(mArgs.begin(), mArgs.end(), option)};

    if (it != mArgs.end() && ++it != mArgs.end()) {
        return *it;
    }

    return "";
}

void CmdLineParser::setAppName(const std::string& name)
{
    mAppName = name;
}

std::string CmdLineParser::getAppName() const
{
    return mAppName;
}

void CmdLineParser::setAppVersion(const std::string& version)
{
    mAppVersion = version;
}

std::string CmdLineParser::getAppVersion() const
{
    return mAppVersion;
}

void CmdLineParser::setAppDescription(const std::string& description)
{
    mAppDescription = description;
}

std::string CmdLineParser::getAppDescription() const
{
    return mAppDescription;
}

void CmdLineParser::showVersion() const
{
    std::cout << mAppName << " " << mAppVersion << std::endl;
    std::cout << mAppDescription << std::endl;
}

void CmdLineParser::setAppUsageInfo(const std::string& exeName,
                                    const std::string& optionsUsageInfo,
                                    const std::map<std::string, std::string>& options)
{
    mExeAppName = exeName;
    mOptionsUsageInfo = optionsUsageInfo;
    mOptions = options;
}

std::string CmdLineParser::getExeAppName() const
{
    return mExeAppName;
}

std::string CmdLineParser::getOptionsUsageInfo() const
{
    return mOptionsUsageInfo;
}

std::map<std::string, std::string> CmdLineParser::getOptions() const
{
    return mOptions;
}

void CmdLineParser::showHelp() const
{
    std::cout << "Usage: " << mExeAppName << " " << mOptionsUsageInfo << std::endl;

    for (const auto& it : mOptions) {
        std::cout << "\t" << it.first << "\t\t" << it.second << std::endl;
    }
}

} // namespace argParser
