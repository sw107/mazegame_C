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

//미로출력 함수
void printmaze(int maze[][10])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(maze[i][j] == 1)
                printf("■");
            else if(maze[i][j] == 0)
                printf(" ");
            else if(maze[i][j] == 2)
                printf("▲");
        }

        printf("\n");
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
    system("cls");
    printf("%d\n", move());
    getch();
    int maze1[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,2,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,1,1,1,1,1,1,1,1,1}};
    printmaze(maze1);
    
    getch();
    return 0;
}