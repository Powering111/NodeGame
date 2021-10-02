#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <conio.h>

#include "test.hpp"

int main(){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    DWORD prevConsoleMode;
    GetConsoleMode(hwnd,&prevConsoleMode);
    SetConsoleMode(hwnd, ENABLE_EXTENDED_FLAGS | (~ENABLE_QUICK_EDIT_MODE & prevConsoleMode));

    HDC dc = GetDC(hwnd);
    for(int i=0;i<700;i++){
        for(int j=0;j<700;j++){
            SetPixel(dc, j, i, RGB(i%255,(i+j)%255,j%255));
        }
    }
    ReleaseDC(hwnd, dc);


    std::cin.get();
    hi();
    hi();
    hi();
    std::cin.get();
    return 0;
}