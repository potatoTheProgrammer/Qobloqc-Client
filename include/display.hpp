/*  display.hpp

This header provides the (eventually) multi-platform Display class. Currently it's simply a wrapper for window creation on Windows.

*/

#pragma once

#include <unordered_map>
#include <memory>
#include <windows.h>

class Display {
    public:
        Display(int width, int height, const char* title, const char* window_id);
        void update_window();
        bool running;
    private:
        HWND window;
        static LRESULT CALLBACK windows_window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam);
};