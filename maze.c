#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "maze.h"


void upmove(int maze[][20]);
void downmove(int maze[][20]);
void rightmove(int maze[][20]);
void leftmove(int maze[][20]);
void select_level();
void printmaze(int maze[][20]);
void movemaze(int maze[][20]);

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

int main()
{
    cursor(0);
    system("mode con cols=60 lines=25 | title mazegame");                       //????????? ?????? ??????
    Gotxy(6, 23);
    printf("?????? ????????????");
    Gotxy(15, 15);
    printf("??????????????? enter?????? ???????????????.");
    
    char enter;
    while(1){
        while(1){
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
            system("cls");
            Gotxy(11,27);
            printf("clear!");
            getch();
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
            system("cls");
            Gotxy(11,27);
            printf("clear!");
            getch();
            break;
        case 3:
            return 0;
        }
    }
    
    return 0;
}

//?????? ??????
void upmove(int maze[][20])
{
    if(maze[x-1][y] != 1 && x != 0){
            maze[x][y] = 0;
            maze[x-1][y] = 2;
            x = x-1;
    }
}
//????????? ??????
void downmove(int maze[][20])
{
    if(maze[x+1][y] != 1){
            maze[x][y] = 0;
            maze[x+1][y] = 2;
            x = x+1;
    }
}
//????????? ??????
void rightmove(int maze[][20])
{
    if(maze[x][y+1] != 1){
            maze[x][y] = 0;
            maze[x][y+1] = 2;
            y=y+1;
    }
}
//?????? ??????
void leftmove(int maze[][20])
{
    if(maze[x][y-1] != 1 && y != 0){
            maze[x][y] = 0;
            maze[x][y-1] = 2;
            y = y-1;
    }
}

//?????? ?????? ??????
void select_level()
{
    system("cls"); 
    Gotxy(10,18); color(4);
    printf("1");
    Gotxy(10,40); color(7);
    printf("2");
    Gotxy(20, 27); color(7);
    printf("exit");

    char key, enter;

    for (;;) {
        key = _getch();
        if (key == 13) {                                                        //???????????? ??????
            color(7);
            break;
        }
        else {
            switch (key)
            {
            case left:                                                          //?????? ??? ????????? ??????1 ??????
                Gotxy(10,18); color(4);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                Gotxy(20, 27); color(7);
                printf("exit");
                level = 1;
                break;

            case right:                                                         //????????? ??? ????????? ??????2 ??????
                Gotxy(10,18); color(7);
                printf("1");
                Gotxy(10,40); color(4);
                printf("2");
                Gotxy(20, 27); color(7);
                printf("exit");
                level = 2;
                break;
            
            case down:
                Gotxy(10,18); color(7);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                Gotxy(20, 27); color(4);
                printf("exit");
                level = 3;
                break; 
            case up:
                Gotxy(10,18); color(4);
                printf("1");
                Gotxy(10,40); color(7);
                printf("2");
                Gotxy(20, 27); color(7);
                printf("exit");
                level = 1;
                break;

            }
        
        }
    }
}

//???????????? ??????s
void printmaze(int maze[][20])
{

    for(int i=0;i<20;i++){
        Gotxy(2+i,10);
        for(int j=0;j<20;j++){
            if(maze[i][j] == 1){                                               //?????? ???       
                color(1);
                printf("??? ");
            }
            else if(maze[i][j] == 0){                                           //?????? ???
                color(7);
                printf("  ");
            }
            else if(maze[i][j] == 2){                                           //?????? ??????
                color(4);
                printf("??? ");
            }
            else if(maze[i][j] == 3){                                           //?????? ??????
                color(4);
                printf("??? ");
            }
        }
        puts("");
    }  
}

//?????? ??????
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