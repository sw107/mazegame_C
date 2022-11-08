#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "maze.h"
//■
int level = 1;
int x = 0,y = 1;

int maze1[20][20] = {{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1},
                     {1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1},
                     {1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1},
                     {1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1},
                     {1,0,1,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1},
                     {1,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1},
                     {1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0,1,1,0,1},
                     {1,0,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
                     {1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1},
                     {1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1},
                     {1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,3},
                     {1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1},
                     {1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,0,0,1,0,1},
                     {1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1},
                     {1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1},
                     {1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
                     {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1},
                     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
        };

//방향키 입력함수
int move()
{   
    char key;
    key = _getch();
    if(key == -32)
        key = _getch();
    return key;
}

void upmove(int maze[][20])
{
    if(maze[x-1][y] != 1){
            maze[x][y] = 0;
            maze[x-1][y] = 2;
            x = x-1;
    }
}

void downmove(int maze[][20])
{
    if(maze[x+1][y] != 1){
            maze[x][y] = 0;
            maze[x+1][y] = 2;
            x = x+1;
    }
}

void rightmove(int maze[][20])
{
    if(maze[x][y+1] != 1){
            maze[x][y] = 0;
            maze[x][y+1] = 2;
            y=y+1;
    }
}

void leftmove(int maze[][20])
{
    if(maze[x][y-1] != 1){
            maze[x][y] = 0;
            maze[x][y-1] = 2;
            y = y-1;
    }
}
//미로 선택 함수
void select_level()
{
    system("cls"); 
    Gotxy(10,20); color(4);
    printf("1");
    Gotxy(10,40); color(7);
    printf("2");
    Gotxy(20, 28); color(7);
    printf("exit");

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
                Gotxy(20, 28); color(7);
                printf("exit");
                level = 1;
                break;

            case right:                                                         //오른쪽 키 누르면 미로2 선택
                system("cls");
                Gotxy(10,20); color(7);
                printf("1");
                Gotxy(10,40); color(4);
                printf("2");
                Gotxy(20, 28); color(7);
                printf("exit");
                level = 2;
                break;
            
            case down:
                system("cls");
                Gotxy(10,20); color(7);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                Gotxy(20, 28); color(4);
                printf("exit");
                level = 3;
                break; 
            case up:
                system("cls");
                Gotxy(10,20); color(4);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                Gotxy(20, 28); color(7);
                printf("exit");
                level = 1;
                break;

            }
        
        }
    }
}

//미로출력 함수
void printmaze(int maze[][20])
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(maze[i][j] == 1){
                color(1);
                printf("■ ");
            }
            else if(maze[i][j] == 0){
                color(7);
                printf("  ");
            }
            else if(maze[i][j] == 2){
                color(4);
                printf("▲ ");
            }
            else if(maze[i][j] == 3){
                color(4);
                printf("● ");
            }
        }

        puts("");
    }
    
}

void movemaze(int maze[][20]){
    if(move() == up){
        upmove(maze);
        system("cls");
        printmaze(maze);
        }
    
    else if (move() == down){
        downmove(maze);
        system("cls");
        printmaze(maze);
        }
    
    else if (move() == right){
        rightmove(maze);
        system("cls");
        printmaze(maze);
        }
    
    else if (move() == left){
        leftmove(maze);
        system("cls");
        printmaze(maze);
        }
}




int main()
{
    cursor(0);
    system("mode con cols=60 lines=25 | title mazegame");    //콘솔창 크기 설정
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
    switch(level)
    {
    case 1:
        printf("미로 1\n");
        printmaze(maze1);
        while(1)
        {
        movemaze(maze1);
        if((x==11)&&(y==19))
            break;
        }
        break;
    case 3:
        return 0;
    }
    
    return 0;
}