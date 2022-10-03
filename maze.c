#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include "maze.h"

//단계 선택 함수
void select_level()
{
    system("cls");
    color(4);
    Gotxy(10,20);
    printf("1");
    Gotxy(10,40);
    color(7);
    printf("2\n");

    char key, enter;

    for (;;) {
        key = getch();

        if (key == 13) {                                                        //단계선택 확정
            color(7);
            system("cls");
            printf("단계선택");
            break;
        }
        else {
            switch (key)
            {
            case left:                                                          //왼쪽 키 누르면 1단계 선택
                system("cls");
                color(4);
                Gotxy(10,20);
                printf("1");
                Gotxy(10,40);
                color(7);
                printf("2");
                printf("\n");
                break;

            case right:                                                         //오른쪽 키 누르면 2단계 선택
                system("cls");
                color(7);
                Gotxy(10,20);
                printf("1");
                Gotxy(10,40);
                color(4);
                printf("2");
                printf("\n");
                break;
            }
        }
    }
}

int main()
{
    cursor(0);
    system("mode con cols=60 lines=20 | title mazegame");    //콘솔창 크기 설정
    Gotxy(6, 23);
    printf("미로 찾기게임");
    Gotxy(15, 15);
    printf("시작하려면 enter키를 입력하세요.");

    char enter;
    enter = getchar();
    printf("%c", enter);

    if (enter == '\n') {
        select_level();
    }

    
    return 0;
}