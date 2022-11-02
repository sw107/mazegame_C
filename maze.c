#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include "maze.h"

int level = 1;

//미로 선택 함수
void select_level()
{
    system("cls"); 
    Gotxy(10,20); color(4);
    printf("1");
    Gotxy(10,40); color(7);
    printf("2");

    char key, enter;

    for (;;) {
        key = getch();
        if (key == 13) {                                                        //미로선택 확정
            color(7);
            break;
        }
        else {
            switch (key)
            {
            case left:                                                          //왼쪽 키 누르면 미로1 선택
                system("cls");
                Gotxy(10,20); color(4);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                level = 1;
                break;

            case right:                                                         //오른쪽 키 누르면 미로2 선택
                system("cls");
                Gotxy(10,20); color(7);
                printf("1");
                Gotxy(10,40); color(4);
                printf("2");
                level = 2;
                break;
            }
        }
    }
}

void move()
{
    //■
    char key;
    for(;;){
        key = getchar();
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
    for(;;){
        enter = getchar();
        printf("%c", enter);
        if (enter == '\n') {
            select_level();
            break;
        }
    }
    
    system("cls");
    printf("미로 %d 선택", level);
    getch();
    system("cls");

    char a[100][100] = {"■■■■■■■■■■■\0","■             ■\0","■■■■■■■■■■■\0"};
    printf("%s\n%s\n%s", a[0], a[1], a[2]);
    getch();
    return 0;
}