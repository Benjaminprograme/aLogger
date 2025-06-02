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

    template<typename T>
    static std::string formatLogEntry(T content, const int type) {
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
                prefix += "WARNING";
                prefixColor = "\033[33m";  // yellow
                break;
            case logTypes::error:
                prefix += "ERROR";
                prefixColor = "\033[31m";  // red
                break;
            case logTypes::internalConsoleError:
                prefix += "INTERNAL CONSOLE ERROR";
                prefixColor = "\033[35m";  // magenta
                break;
            case logTypes::table:
                prefix += "TABLE";
                prefixColor = "\033[36m";  // cyan
                break;
            case logTypes::input:
                prefix += ">/";
             content = "";
                prefixColor = "\033[32m";  // green
                break;
            default:
                prefix = "@";
                prefixColor = "\033[37m";  // white
                break;
        }
        string timestampColor = "\033[35m";
        string formattedString ;

        if (content != "" ) {
            ostringstream oss;
            oss << content;
            formattedString =  prefixColor + prefix + reset + timestampColor + " [" + timestamp + "]: " + reset +  oss.str() + reset;
        }else if (type == input){
            std::string input;
            cout <<  prefixColor + prefix;
       cin >> input;
            formattedString =  prefixColor + prefix + reset + timestampColor + " [" + timestamp + "]: " + reset +  input + reset;
        }


        // Format string: background white, colored prefix, reset, normal content

        return formattedString;
    }

    template<typename T>
   void log(const T& content) {
        std::cout << formatLogEntry(content ,logTypes::warning) << std::endl;
}

    template<typename T,typename T2>
    void log(const T& content,const T2 type) {
        std::cout << formatLogEntry(content, type) << std::endl;
    }
}

