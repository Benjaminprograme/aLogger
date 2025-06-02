#include "headers/logging.h"

int main() {
    console::log("",console::input);
    console::log("Hello World");
    console::log("This is a warning",console::warning);
    console::log("This is an error",console::error);
    console::log("",console::error);
    return 0;
}