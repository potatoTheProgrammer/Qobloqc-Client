/*  main.cpp

This is the entry point of the program.
It does everything you'd expect a "main.cpp" to do: bringing everything that makes up the Qobloqc Client together.

*/

#include <iostream>
#include <fstream>
#include <filesystem>

#include <windows.h>

#include "display.hpp"

static bool running = true;
static HWND window;

class Window {
    public:
        
        static LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
            LRESULT result = 0;
            
            switch(msg) {
                case WM_CLOSE: {
                    running = false;
                    break;
                }
                default: {
                    result = DefWindowProcA(window, msg, wParam, lParam);
                }
            }
            
            return result;
            
        }
        
        Window(int width, int height, const char* title, const char* window_id) {
            HINSTANCE instance = GetModuleHandleA(0);
            
            WNDCLASSA wc = {};
            wc.hInstance = instance;
            wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
            wc.hCursor = LoadCursor(NULL, IDC_ARROW);
            wc.lpszClassName = window_id;
            wc.lpfnWndProc = windows_window_callback;
            
            bool success = true;
            
            if (!RegisterClassA(&wc)) {
                std::cout << "Failed to create window class :(" << std::endl;
                success = false;
            }
            
            window = CreateWindowExA(0, window_id, title, WS_OVERLAPPEDWINDOW, 100, 100, width, height, NULL, NULL, instance, NULL);
            
            if (window == NULL) {
                std::cout << "Failed to create window :(" << std::endl;
                success = false;
            }
            
            if (success == true) {
                std::cout << "Successfully created a window! :D" << std::endl;
                ShowWindow(window, SW_SHOW);
            }
            
        }
        
        void update_window() {
            MSG msg;
            
            while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        
};

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
    
    std::string title = "Qobloqc Client version 0.0.1";
    
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
    Display my_display;
    
    std::filesystem::create_directory("Qobloqc");
    std::ofstream test_file("Qobloqc/test_file.txt");
    if (test_file.is_open()) {
        
        test_file << "Hello!";
        test_file.close();
        
    }
    
    std::string window_id = "Main";
    const char *title_c = title.c_str();
    const char *window_id_c = window_id.c_str();
    
    Window my_window(800, 600, title_c, window_id_c);
    
    while (running) {
        my_window.update_window();
    }
    
    return 0;
    
}