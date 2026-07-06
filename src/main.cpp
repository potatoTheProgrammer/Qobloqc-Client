/*  main.cpp

This is the entry point of the program.
It does everything you'd expect a "main.cpp" to do: bringing everything that makes up the Qobloqc Client together.

*/

#include <fstream>
#include <filesystem>

#include "display.hpp"
#include "node_map.hpp"
#include "nodes.hpp"
#include "debug.hpp"

void attempt_node_creation(Debug& log, std::string path, NodeMap& node_map) {
    log.log_info("Trying to create \"" + path + "\"...");
    node_map.create_node("Node", path);
};

int main(int argc, char *argv[]) {
    
    std::filesystem::create_directory("Qobloqc");
    Debug log_file("Qobloqc/log.txt");
    
    bool debug_mode = false;
    
    std::string debug_text;
    
    std::string debug_argument("debug");
    
    if (argc >= 2) {
        if (argv[1] == debug_argument) {
            debug_mode = true;
        }
    }
    
    if (debug_mode == true) {
        debug_text = " (Debug mode)";
    } else {
        debug_text = "";
    }
    
    std::string title = "Qobloqc Client version 0.1.0";
    std::string title_printed = title;
    
    #ifdef _WIN32
        title_printed += " running on Windows";
    #else
        title_printed += " not running on Windows";
    #endif
    
    title_printed += debug_text;
    
    log_file.log_raw(title_printed);
    log_file.new_line();
    log_file.log_raw("This software is licensed under the GNU GPLv3.");
    log_file.log_raw("For more information, see the LICENSE.txt file found in the source code.");
    log_file.log_raw("You can get a copy of the source code from the following URL:");
    log_file.log_raw("https://github.com/potatoTheProgrammer/Qobloqc-Client");
    log_file.new_line();
    
    std::ofstream test_file("Qobloqc/test_file.txt");
    if (test_file.is_open()) {
        
        test_file << "Hello!";
        test_file.close();
        
    }
    
    std::string window_id = "Main";
    const char *title_c = title.c_str();
    const char *window_id_c = window_id.c_str();
    
    NodeMap my_node_map{};
    
    attempt_node_creation(log_file, "Root", my_node_map);
    attempt_node_creation(log_file, "Root.Test1", my_node_map);
    attempt_node_creation(log_file, "Root.Test2", my_node_map);
    attempt_node_creation(log_file, "Root.Test2.Test3", my_node_map);
    attempt_node_creation(log_file, "Root.Test4.Test5", my_node_map);
    attempt_node_creation(log_file, "Root..Test6", my_node_map);
    attempt_node_creation(log_file, "", my_node_map);
    attempt_node_creation(log_file, "Root.", my_node_map);
    
    my_node_map.list_nodes();
    
    Display my_display(800, 600, title_c, window_id_c);
    
    while (my_display.running) {
        my_display.update_window();
    }
    
    return 0;
    
}