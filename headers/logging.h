#pragma once
#include <iostream>
#include <string>
#include <chrono>

#include <vector>
#include <fstream>
#include <sstream>

namespace console {
enum logTypes {
    regular =0,
    warning,
    error,
    internalConsoleError,
    table,
    input,
};

    static std::string formatLogEntry(std::string content, const int type) {
        using namespace std;
        string prefix = "@";
        string prefixColor = "\033[37m"; // default: white text
        string reset = "\033[0m";
        string bgWhite = "\033[47m"; // white background

        auto now = std::chrono::system_clock::now();
        string timestamp = std::format("{:%Y-%m-%d %H:%M:%S}", now);

        // Determine prefix and color
        switch (type) {
            case logTypes::regular:
                prefix = "@";
                prefixColor = "\033[37m";  // white
                break;
            case logTypes::warning:
                prefix += "WARNING:";
                prefixColor = "\033[33m";  // yellow
                break;
            case logTypes::error:
                prefix += "ERROR:";
                prefixColor = "\033[31m";  // red
                break;
            case logTypes::internalConsoleError:
                prefix += "INTERNAL CONSOLE ERROR:";
                prefixColor = "\033[35m";  // magenta
                break;
            case logTypes::table:
                prefix += "TABLE:";
                prefixColor = "\033[36m";  // cyan
                break;
            case logTypes::input:
                prefix += ">/";
                prefixColor = "\033[32m";  // green
                break;
            default:
                prefix = "@";
                prefixColor = "\033[37m";  // white
                break;
        }
string timestampColor = "\033[35m";
        // Format string: background white, colored prefix, reset, normal content
        string formattedString =
              prefixColor + prefix + reset + timestampColor + " [" + timestamp + "]: " + reset + content + reset;

        return formattedString;
    }

    template<typename T>
   void log(const T& content) {
    std::ostringstream oss;
    oss << content;

    std::cout << formatLogEntry(oss.str(), logTypes::warning) << std::endl;
}
}

