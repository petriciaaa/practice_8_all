#include <iostream>
#include <math.h>
#include <windows.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

const COLORREF color = (RGB(223, 220, 87));


struct PolarRoseParams {
    int centerX;
    int centerY;
    int radius;
    int petals;

};
double toPolarCords(double a, int n, double angle) { return { a * sin(n * angle) }; }

COORD toDecartCords(double r, double angle) { return { short(r * cos(angle)),short(r * sin(angle)) }; }

void clearConsole() {

    system("cls");
}

void hideCursor(HANDLE hStdout) {

    CONSOLE_CURSOR_INFO cursor;

    GetConsoleCursorInfo(hStdout, &cursor);

    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(hStdout, &cursor);

}


void drawPolarRose(HDC hDeviceContext, PolarRoseParams params, bool fill = 1) {

    POINT points[361];

    for (int i = 0; i < 360; i++) {

        double angle = i * 3.14 / 180.0;
        double r = toPolarCords(params.radius, params.petals, angle);

        COORD point = toDecartCords(r, angle);

        point.X += params.centerX;

        point.Y += params.centerY;

        points[i].x = point.X;

        points[i].y = point.Y;

    }

    points[360] = points[0]; // close the polygon


    if (!fill) {
        
        HBRUSH hBrush = CreateSolidBrush(color);
        SelectObject(hDeviceContext, hBrush);
        Polygon(hDeviceContext, points,params.petals%2==0?361: 180);
        DeleteObject(hBrush);

    }
    else {

        HPEN hPen = CreatePen(PS_SOLID, 3, color);

        SelectObject(hDeviceContext, hPen);
        for (int i = 0; i <= 360; i++) {
            MoveToEx(hDeviceContext, points[i].x, points[i].y, NULL);
            LineTo(hDeviceContext, points[(i + 1) % 360].x, points[(i + 1) % 360].y);

        }
        DeleteObject(hPen);
    }
   

}

int main()
{

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    hideCursor(hStdout);

    HWND hWindow = GetConsoleWindow();
    HDC hDeviceContext = GetDC(hWindow);


    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdout, &csbi);

    const int windowHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1, windowWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    const int start = 3, end = 36;
    for (int i = start; i <= end; i++)
    {
        std::cout << "N = " << i << " Petals: " << (i % 2 == 0 ? i * 2 : i);
        PolarRoseParams params = { 700, 300, 250,i };
        drawPolarRose(hDeviceContext, params, i % 2 == 0);
        Sleep(1000);
        clearConsole();

    }


    ReleaseDC(hWindow, hDeviceContext);
    _getche();

    return 0;
}