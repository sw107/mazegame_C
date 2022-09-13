#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

// 상하좌우 상수값
#define up 72
#define down 80
#define left 75
#define right 77

// 글자 색상 변경
#define color(A) SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), A);

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
    COORD Pos = { y - 1,x - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//단계 선택 함수
void select_level()
{
    system("cls");
    color(4);
    printf("1");
    color(7);
    printf("          2\n");

    char key, enter;

    for (;;) {
        key = getch();

        if (key == 13) {                                                        //단계선택 확정
            color(7);
            printf("단계선택");
            break;
        }
        else {
            switch (key)
            {
            case left:                                                          //왼쪽 키 누르면 1단계 선택
                color(4);
                printf("1");
                color(7);
                printf("          2");
                printf("\n");
                break;

            case right:                                                         //오른쪽 키 누르면 2단계 선택
                color(7);
                printf("1");
                color(4);
                printf("          2");
                printf("\n");
                break;
            }
        }
    }
}

int main()
{
    cursor(0);
    Gotxy(3, 20);
    printf("미로 찾기게임");
    Gotxy(10, 13);
    printf("시작하려면 enter키를 입력하세요.");

    char enter;
    enter = getchar();
    printf("%c", enter);

    if (enter == '\n') {
        select_level();
    }

    return 0;
}