/*  debug.cpp

This source file implements functions from debug.hpp.

*/

#include <iostream>
#include <fstream>
#include <string>
#include "debug.hpp"

Debug::Debug(std::string log_path) {
    log_file = std::ofstream(log_path);
};

void Debug::log_raw(std::string text) {
    std::cout << text << std::endl;
    log_file << text << std::endl;
};

void Debug::new_line() {
    log_raw("");
};

void Debug::log_info(std::string text) {
    log_raw("[INFO] " + text);
};