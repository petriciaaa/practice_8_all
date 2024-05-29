#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib")

void drawCircle(HDC hDeviceContext, const COORD CENTER, double radius, COLORREF color, bool stroke = true) {


    HBRUSH hBrush = CreateSolidBrush(color);
    HPEN hPen = (HPEN)GetStockObject(NULL_PEN);

    if (!stroke)
    {
        HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        SelectObject(hDeviceContext, hPen);
    }

    SelectObject(hDeviceContext, hBrush);

    Ellipse(hDeviceContext, CENTER.X - radius, CENTER.Y - radius, CENTER.X + radius, CENTER.Y + radius);
    DeleteObject(hPen);
    DeleteObject(hBrush);

}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(hStdout, &cursor);
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(hStdout, &cursor);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);

    HWND hWindow = GetConsoleWindow();
    HDC hDeviceContext = GetDC(hWindow);


    const int WindowHeight = 600 - 15, WindowWidth = 1440 - 15;
    //const int WindowHeight = 1440 - 15, WindowWidth = 600 - 15;

    srand(time(NULL));


    int directionX = 1;
    int directionY = 1;
    int pounceCounter = 0;
    const int radius = 15;


    COLORREF color = RGB(rand() % 255, rand() % 255, rand() % 255);
    COORD start = { rand() % (WindowWidth - 1) ,rand() % (WindowHeight - 1) };

    COORD prevStart = start;
    int speed = 120;


    while (true)
    {

        drawCircle(hDeviceContext, prevStart, 15, RGB(230, 230, 250), false);
        drawCircle(hDeviceContext, start, 15, color);

        int x = start.X;
        int y = start.Y;
        x += directionX * radius;
        y += directionY * radius;

        if (x == radius / 2 && y == radius / 2 || x == radius / 2 && y == WindowHeight - radius / 2 - 1 ||
            x == WindowWidth - radius / 2 - 1 && y == radius / 2 - 1 || x == WindowWidth - radius / 2 - 1 && y == WindowHeight - radius / 2 - 1)
        {

            directionX = -directionX;
            directionY = -directionY;
            speed -= 10;
            PlaySound(TEXT(R"(assets\boing2.wav)"), NULL, SND_ASYNC);
            color = RGB(rand() % 255, rand() % 255, rand() % 255, );

        }
        else if (x <= radius || x >= WindowWidth - radius / 2)
        {

            directionX = -directionX;
            speed -= 10;
            PlaySound(TEXT(R"(assets\boing2.wav)"), NULL, SND_ASYNC);
            color = RGB(rand() % 255, rand() % 255, rand() % 255, );

        }
        else if (y <= radius || y >= WindowHeight - radius / 2) {

            directionY = -directionY;
            speed -= 10;
            PlaySound(TEXT(R"(assets\floop2_x.wav)"), NULL, SND_ASYNC);
            color = RGB(rand() % 255, rand() % 255, rand() % 255, );

        }
        prevStart = start;

        start = { short(x),short(y) };
        pounceCounter++;

        Sleep(speed >= 0 ? speed : 1);



    }


    _getche();

    return 0;

}