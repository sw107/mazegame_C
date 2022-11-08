#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "maze.h"

int level = 1;
int x,y;

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

int maze2[20][20] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1},
                     {1,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,3},
                     {1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1},
                     {1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1},
                     {1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1},
                     {1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,1,1,1,0,1},
                     {1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,1},
                     {1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,1,1},
                     {1,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,1,1},
                     {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1},
                     {1,0,1,0,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,1},
                     {1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1},
                     {1,0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1},
                     {1,0,0,1,1,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1},
                     {1,1,0,0,0,0,1,1,0,1,0,0,1,1,1,1,1,0,0,1},
                     {1,0,0,1,0,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1},
                     {1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,1,1,0,0,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1}};

//위로 이동
void upmove(int maze[][20])
{
    if(maze[x-1][y] != 1){
            maze[x][y] = 0;
            maze[x-1][y] = 2;
            x = x-1;
    }
}
//아래로 이동
void downmove(int maze[][20])
{
    if(maze[x+1][y] != 1){
            maze[x][y] = 0;
            maze[x+1][y] = 2;
            x = x+1;
    }
}
//오른쪽 이동
void rightmove(int maze[][20])
{
    if(maze[x][y+1] != 1){
            maze[x][y] = 0;
            maze[x][y+1] = 2;
            y=y+1;
    }
}
//왼쪽 이동
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
    system("cls");
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(maze[i][j] == 1){                                                //미로 벽       
                color(1);
                printf("■ ");
            }
            else if(maze[i][j] == 0){                                           //미로 길
                color(7);
                printf("  ");
            }
            else if(maze[i][j] == 2){                                           //유저 위치
                color(4);
                printf("▲ ");
            }
            else if(maze[i][j] == 3){                                           //탈출 지점 
                color(4);
                printf("● ");
            }
        }
        puts("");
    }
    
}

//유저 이동
void movemaze(int maze[][20]){
    char key = _getch();
    if (key == -32){
        key = _getch();
    
        if(key == up){
            upmove(maze);
            }
    
        else if (key == down){
            downmove(maze);
            }
    
        else if (key == right){
            rightmove(maze);
            }
    
        else if (key == left){
            leftmove(maze);
            }
    }
}




int main()
{
    cursor(0);
    system("mode con cols=60 lines=25 | title mazegame");                       //콘솔창 크기 설정
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
        x = 0;
        y = 1;
        while(1)
        {
        printmaze(maze1);
        movemaze(maze1);
        
        if((x==11)&&(y==19))
            break;
        }
        break;
    case 2:
        x = 19;
        y = 14;
        while(1)
        {
        printmaze(maze2);
        movemaze(maze2);

        if((x==2)&&(y==19))
            break;
        }
        break;
    case 3:
        return 0;
    }
    
    return 0;
}