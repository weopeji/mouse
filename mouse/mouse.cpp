#include <Windows.h>
#include <iostream>

void moveMouse(int x, int y, int movex, int movey)
{
    SetCursorPos(movex, movey);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(110);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

    /*int count = 100;

    int _X = x;
    int _Y = y;

    int razX = (movex - x) * 0.1;
    int razY = (movey - y) * 0.1;

    for (int i = 0; i <= count; i++)
    {
        _X = _X + razX;
        _Y = _Y + razY;

        SetCursorPos(_X, _Y);
        Sleep(1);
    }*/
}

int to_int(char* str) {
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

int main(int argc, char* argv[], char* envp[])
{
    int first = to_int(argv[1]);
    int second = to_int(argv[2]);

    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

    int Height  = GetSystemMetrics(SM_CYSCREEN);
    int Width   = GetSystemMetrics(SM_CXSCREEN);

    moveMouse(Width, Height, first, second);

    return 0;
}