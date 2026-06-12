/*  main.cpp

This is the entry point of the program.
It does everything you'd expect a "main.cpp" to do: bringing everything that makes up the Qobloqc Client together.

*/

#include <iostream>
#include <fstream>
#include <filesystem>

#include "display.hpp"
#include "node_map.hpp"
#include "nodes.hpp"

int main(int argc, char *argv[]) {
    
    bool debug_mode = false;
    
    std::string debug_text;
    
    std::string debug_idk("debug");
    
    if (argc >= 2) {
        if (argv[1] == debug_idk) {
            debug_mode = true;
        }
    }
    
    if (debug_mode == true) {
        debug_text = " (Debug mode)";
    } else {
        debug_text = "";
    }
    
    std::string title = "Qobloqc Client version 0.1.0";
    
    std::cout << title;
    
    #ifdef _WIN32
        std::cout << " running on Windows";
    #else
        std::cout << " not running on Windows";
    #endif
    
    std::cout << debug_text << std::endl;
    
    std::cout << "" << std::endl;
    std::cout << "This software is licensed under the GNU GPLv3." << std::endl;
    std::cout << "For more information, see the LICENSE.txt file found in the source code." << std::endl;
    std::cout << "You can get a copy of the source code from the following URL:" << std::endl;
    std::cout << "https://github.com/potatoTheProgrammer/Qobloqc-Client" << std::endl;
    std::cout << "" << std::endl;
    
    std::cout << "Hello World!" << std::endl;
    
    std::filesystem::create_directory("Qobloqc");
    std::ofstream test_file("Qobloqc/test_file.txt");
    if (test_file.is_open()) {
        
        test_file << "Hello!";
        test_file.close();
        
    }
    
    std::string window_id = "Main";
    const char *title_c = title.c_str();
    const char *window_id_c = window_id.c_str();
    
    std::cout << std::endl;
    
    NodeMap my_node_map{};
    std::cout << "Trying to create \"Root\"..." << std::endl;
    my_node_map.create_node("Node", "Root");
    std::cout << "Trying to create \"Root.Test1\"..." << std::endl;
    my_node_map.create_node("Node", "Root.Test1");
    std::cout << "Trying to create \"Root.Test2\"..." << std::endl;
    my_node_map.create_node("Node", "Root.Test2");
    std::cout << "Trying to create \"Root.Test2.Test3\"..." << std::endl;
    my_node_map.create_node("Node", "Root.Test2.Test3");
    std::cout << "Trying to create \"Root.Test4.Test5\"..." << std::endl;
    my_node_map.create_node("Node", "Root.Test4.Test5");
    std::cout << "Trying to create \"Root..Test6\"..." << std::endl;
    my_node_map.create_node("Node", "Root..Test6");
    std::cout << "Trying to create \"\"..." << std::endl;
    my_node_map.create_node("Node", "");
    std::cout << "Trying to create \".Root.Test7\"..." << std::endl;
    my_node_map.create_node("Node", ".Root.Test7");
    std::cout << "Trying to create \"Root.Test8.\"..." << std::endl;
    my_node_map.create_node("Node", "Root.Test8.");
    
    Display my_display(800, 600, title_c, window_id_c);
    
    while (my_display.running) {
        my_display.update_window();
    }
    
    return 0;
    
}