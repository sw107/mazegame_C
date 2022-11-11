#ifndef MAZE_H
# define MAZE_H
# include<windows.h>
# include<stdio.h>

// 상하좌우 상수값
# define up 72
# define down 80
# define left 75
# define right 77

// 글자 색상 변경
# define color(A) SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), A);

// 커서 설정 (1 == on / 0 == off)
void cursor(int n)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

// 글자 출력 위치 설정
void Gotxy(int x, int y)
{
    COORD Pos = { y , x};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

#endif 