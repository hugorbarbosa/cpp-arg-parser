/**
 * @file
 * @copyright Copyright (c) 2022.
 */

#include <argParser/CmdLineParser.h>
#include <gtest/gtest.h>
#include <memory>

using namespace testing;
using namespace argParser;

/**
 * @brief Test class of CmdLineParser.
 */
class CmdLineParserTest : public Test
{
protected:
    /**
     * @brief Constructor.
     */
    CmdLineParserTest()
        : mCmdLineParser{std::make_unique<CmdLineParser>()}
    {
    }

    /**
     * @brief Test suite setup.
     */
    void SetUp() override {}

    /**
     * @brief Test suite teardown.
     */
    void TearDown() override {}

protected:
    /// Command line parser.
    std::unique_ptr<CmdLineParser> mCmdLineParser{};
};

/**
 * @brief Test if the command line arguments are parsed correctly.
 */
TEST_F(CmdLineParserTest, ParseCommandLineArgs)
{
    const int argc = 2;
    const char* argv[] = {"exe", "--help"};

    mCmdLineParser->parse(argc, argv);

    // Verify command line args
    const auto args{mCmdLineParser->getArgs()};

    EXPECT_EQ(args.size(), argc);
    EXPECT_EQ(args.at(0), std::string(argv[0]));
    EXPECT_EQ(args.at(1), std::string(argv[1]));
}

/**
 * @brief Test if parser has the command line option passed.
 */
TEST_F(CmdLineParserTest, HaveCommandOption)
{
    const int argc = 2;
    const char* argv[] = {"exe", "-h"};

    mCmdLineParser->parse(argc, argv);

    // Verify if option is present
    const auto hasOptionArg{mCmdLineParser->hasOption(std::string(argv[1]))};
    EXPECT_TRUE(hasOptionArg);
}

/**
 * @brief Test if parser does not have a command line option not passed.
 */
TEST_F(CmdLineParserTest, NotHaveCommandOption)
{
    const int argc = 2;
    const char* argv[] = {"exe", "-h"};

    mCmdLineParser->parse(argc, argv);

    // Verify if option is not present
    const auto hasOptionArg{mCmdLineParser->hasOption("-v")};
    EXPECT_FALSE(hasOptionArg);
}

/**
 * @brief Test if parser gets the command line option value passed.
 */
TEST_F(CmdLineParserTest, GetCommandOptionValue)
{
    const int argc = 3;
    const char* argv[] = {"exe", "--param", "1"};

    mCmdLineParser->parse(argc, argv);

    // Verify option value
    const auto value{mCmdLineParser->getOption(std::string(argv[1]))};
    EXPECT_EQ(value, std::string(argv[2]));
}

/**
 * @brief Test if parser returns an empty string when the command line option value is not passed.
 */
TEST_F(CmdLineParserTest, GetCommandOptionEmpty)
{
    const int argc = 2;
    const char* argv[] = {"exe", "--param"};

    mCmdLineParser->parse(argc, argv);

    // Verify option value
    const auto value{mCmdLineParser->getOption(std::string(argv[1]))};
    EXPECT_TRUE(value.empty());
}

/**
 * @brief Test the definition of the application name.
 */
TEST_F(CmdLineParserTest, SetAppName)
{
    const std::string name{"Application Name"};
    mCmdLineParser->setAppName(name);
    EXPECT_EQ(mCmdLineParser->getAppName(), name);
}

/**
 * @brief Test the definition of the application version.
 */
TEST_F(CmdLineParserTest, SetAppVersion)
{
    const std::string version{"1.0.0"};
    mCmdLineParser->setAppVersion(version);
    EXPECT_EQ(mCmdLineParser->getAppVersion(), version);
}

/**
 * @brief Test the defintion of the application description.
 */
TEST_F(CmdLineParserTest, SetAppDescription)
{
    const std::string description{"Description for this application"};
    mCmdLineParser->setAppDescription(description);
    EXPECT_EQ(mCmdLineParser->getAppDescription(), description);
}

/**
 * @brief Test the defintion of the application usage information.
 */
TEST_F(CmdLineParserTest, SetAppUsageInfo)
{
    const std::string exeName{"exe"};
    const std::string optionsUsageInfo{"[OPTION] -f file"};
    const std::map<std::string, std::string> options{
        {"-h, --help", "show help message"},
        {"-v, --version", "show version"},
        {"-f, --file", "output file"},
    };

    mCmdLineParser->setAppUsageInfo(exeName, optionsUsageInfo, options);

    EXPECT_EQ(mCmdLineParser->getExeAppName(), exeName);
    EXPECT_EQ(mCmdLineParser->getOptionsUsageInfo(), optionsUsageInfo);
    EXPECT_EQ(mCmdLineParser->getOptions(), options);
}
