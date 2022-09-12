#include<stdio.h>
#include<windows.h>

// 상하좌우 상수값
#define up 72
#define down 80
#define left 75
#define right 77

//단계 선택 함수
void select_level()
{
    char key, enter;
    system("cls");
    for(;;){
        key = getch();
        
        if(key == 13){                        //단계선택 확정
            printf("단계선택");
            break;
        }
        
        else{
            switch(key)
          {
             case left :                      //왼쪽 이동
                    printf("left\n");
                    break;
            
                case right :                  //오른쪽 이동
                   printf("right\n");
                   break;
            }
        }
    } 
}

int main()
{
    printf("미로 찾기게임\n\n\n시작하려면 enter키를 입력하세요.");

    char enter;
    enter = getchar();
    printf("%c", enter);
    
    if(enter == '\n'){
        select_level();
    }

    return 0;
}