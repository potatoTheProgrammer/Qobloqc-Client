/*  debug.hpp

This header file provides the Debug class.

*/

#pragma once

#include <fstream>
#include <string>

class Debug {
    public:
        Debug(std::string log_path);
        void log_raw(std::string text);
        void new_line();
        void log_info(std::string text);
    private:
        std::ofstream log_file;
};