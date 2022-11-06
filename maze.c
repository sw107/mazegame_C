#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "maze.h"
//■
int level = 1;

//방향키 입력함수
int move()
{   
    char key;
    key = _getch();
    return key;
}

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
        key = _getch();
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
    int a[100][100] = {{1,0,1}};
    printf("%d\n", move());
    printf("%d\n%d\n%d", a[0][0], a[0][1], a[0][2]);
    getch();

    
    
    getch();
    return 0;
}