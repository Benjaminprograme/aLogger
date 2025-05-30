#include <iostream>
#include <fstream>
#include <vector>
#include "headers/logging.h"

int main() {
    aLogger::log("This is a test.");
    aLogger::log("This is a warning!", aLogger::warning);
    aLogger::saveLogData("log_output"); // This writes to log_output.txt
    return 0;
}