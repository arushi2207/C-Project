#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int i, j, height = 20, width = 20;
int gameover, x, y, fruitx, fruity, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirecton dir;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Print()
{
   //GotoXY(10,12);
   printf("\n\tWelcome to the Snake game. (press any key to continue)\n");
   getch();
   system("cls");
   printf("\n\tGAME INSTRUCTIONS :\n");
   printf("\n-> Use WASD keys to move the snake.\n\tW -> UP\n\tA -> LEFT\n\tD -> RIGHT\n\tS -> DOWN\n\n-> You will be provided with a fruit at several coordinates of the screen which you have to eat.\n Everytime you eat a food the length of the snake will be increased and the score by 10.\n\n-> The game ends as you hit the snake's body.\n\n-> You can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
   printf("\n\nPress any key to play the game...");
   if(getch()==27)
   exit(0);
}

void load(){
    system("cls");
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    Sleep(30);
    system("cls");
    gotoxy(30,15);
    printf("press a key to comtinue...");
    getch();
}

void setup()
{
    gameover = 0;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}


void draw()
{
    system("cls");
    for (i = 0; i < width + 2; i++)
        printf("-");
    printf("\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (j == 0)
                printf("|");
            if (i == y && j == x)
                printf("O");
            else if (i == fruity && j == fruitx)
                printf("F");
            else {
                int isprint = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        isprint = 1;
                    }
                }
                if (isprint == 0)
                    printf(" ");
            }

            if (j == width - 1)
                printf("|");
        }
        printf("\n");
    }

    for (i = 0; i < width + 2; i++)
        printf("-");
    printf("\n");
    printf("Score:%d", score);
}

void input()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP; 
            break;
        case 's':
            dir = DOWN;
            break;
        case 27:
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;

    if (x == fruitx && y == fruity) { 
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        nTail++;
    }
}

void record(){
    int score=nTail*10;
    Sleep(2000);
    system("cls");
    gotoxy(30,15);
    printf("!!!GAMEOVER!!!\n\n\t\t\tyour score = %d",score);
    Sleep(3000);
    system("cls");
    char plname[20],cha,c;
    FILE *info;
    info=fopen("record2.txt","a+");
    // getch();
    // system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]",plname);

    fprintf(info,"Player Name :%s\n",plname);
    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    fprintf(info,"Score:%d\n",score);
    for(i=0;i<=50;i++)
    fprintf(info,"%c",'_');
    fprintf(info,"\n");
    system("cls");

    printf("press 'y' to see scoreboard...\n");
    cha=getch();
    system("cls");
    if(cha=='y'){
    info=fopen("record2.txt","r");
    do{
       putchar(c=getc(info));
       }
    while(c!=EOF);}
    //    Sleep(2000);
       system("pause");
    fclose(info);
}

int main()
{
    int m, n;

    // Generate random seed
    srand(time(NULL));
    Print();
    load();
    setup();
    while (!gameover) {  // main game loop
        draw();
        input();
        logic();
        Sleep(10); // Sleep for 10 milliseconds
    }
    record();

    return 0;
}