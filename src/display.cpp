/*  display.cpp

This source file implements functions from display.hpp.

*/

#include <iostream>
#include <windows.h>

#include "display.hpp"

Display::Display(int width, int height, const char* title, const char* window_id) {
    std::cout << "Created a Display object" << std::endl;
    
    running = true;
    
    HINSTANCE instance = GetModuleHandleA(NULL);
            
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
    
    window = CreateWindowExA(0, window_id, title, WS_OVERLAPPEDWINDOW, 100, 100, width, height, NULL, NULL, instance, this);
    
    if (window == NULL) {
        std::cout << "Failed to create window :(" << std::endl;
        success = false;
    }
    
    if (success == true) {
        std::cout << "Successfully created a window! :D" << std::endl;
        ShowWindow(window, SW_SHOW);
    }
};

LRESULT Display::windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam) {
    LRESULT result = 0;
    Display* display_pointer;
    
    if (msg == WM_NCCREATE) {
        CREATESTRUCT* create_pointer = reinterpret_cast<CREATESTRUCT*>(lParam);
        display_pointer = reinterpret_cast<Display*>(create_pointer -> lpCreateParams);
        
        SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(display_pointer));
    } else {
        display_pointer = reinterpret_cast<Display*>(GetWindowLongPtr(window, GWLP_USERDATA));
    }
    
    switch(msg) {
        case WM_CLOSE: {
            display_pointer -> running = false;
            break;
        }
        default: {
            result = DefWindowProcA(window, msg, wParam, lParam);
        }
    }
    
    return result;
};

void Display::update_window() {
    MSG msg;
    
    while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
};