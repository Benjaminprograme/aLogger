#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

namespace aLogger {
    using namespace std;

    enum types {
        message = 1,
        warning,
        error,
        questions,
        internalLoggerMessage
    };

    class logEntry {
    public:
        string content;
        string formatedContent;
        int type;
        static vector<logEntry*> instances;

        logEntry(const string& content,const string& formatedContent ,int type) {
            this->content = content;
            this->type = type;
            this->formatedContent = formatedContent;
            instances.push_back(this);
            cout << content;
        }

        // Destructor does NOT remove from instances to keep entries alive
        ~logEntry() = default;
    };

    // Static member definition
    vector<logEntry*> logEntry::instances;

    const int defaultTyping = types::message;

    void log(const string& outputString) {
        const char prefix = '@';
        char suffix = '.';
        const string colorCode = "\033[32m";
        const string resetColor = "\033[0m";

        if (!outputString.empty() && (outputString.back() == '.' || outputString.back() == '!' || outputString.back() == '?')) {
            suffix = ' ';
        }

        new logEntry(colorCode + prefix + resetColor + outputString + colorCode + suffix + resetColor + "\n", outputString +  suffix +  "\n" ,defaultTyping);
    }

    void log(const string& outputString, bool formatOutput) {
        const char prefix = '@';
        if (formatOutput) {
            new logEntry(string(1, prefix) + outputString + "\n", outputString +"\n" ,defaultTyping);
        } else {
            log(outputString, defaultTyping);
        }
    }

    void log(const string& outputString, int type) {
        string prefix;
        string suffix;
        string colorCode = "\033[32m";
        const string resetColor = "\033[0m";

        if (type == message) {
            prefix = "Message: ";
            suffix = ".";
        } else if (type == warning) {
            prefix = "Warning: ";
            suffix = " !";
            colorCode = "\033[33m";
        } else if (type == error) {
            prefix = "Error: ";
            suffix = " !!!";
            colorCode = "\033[31m";
        } else if (type == questions) {
            suffix = " ?";
            colorCode = "\033[36m";
        }

        if (!outputString.empty() && (outputString.back() == '.' || outputString.back() == '!' || outputString.back() == '?')) {
            suffix = "";
        }

        new logEntry("@" + colorCode + prefix + resetColor + outputString + colorCode + suffix + resetColor + "\n",prefix +  outputString +  suffix +  "\n" ,type);
    }

    void saveLogData(const string& fileName) {
        cout << "Saving log data to " << fileName << endl;
        ofstream file(fileName + ".txt");
        cout << "Total entries: " << logEntry::instances.size() << endl;
        file <<fileName <<":\n" <<"Total entries: " << logEntry::instances.size() << "\n \n";
        for (auto entry : logEntry::instances) {
            file << entry->formatedContent;
        }
        file.close();
    }

    // Optional: clear all stored entries and free memory (call at program end if needed)
    void clearLogEntries() {
        for (auto entry : logEntry::instances) {
            delete entry;
        }
        logEntry::instances.clear();
    }
}
