//Author MOHAN SIRVI
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)
#define MOD 1000000007
#include <conio.h>
#include <windows.h>

bool gameOver;

const int width = 20;
const int height = 20;

int x, y, ballX, ballY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;


//Setup Function
void Setup()
{
    gameOver = false;
    dir = STOP;

    x = width / 2;
    y = height / 2;

    ballX = rand() % width;
    ballY = rand() % height;

    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width+2; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0){
                cout << "#";
            }
            if (i == y && j == x){
                cout << "O";
            }
            else if (i == ballY && j == ballX){
                cout << "F";
            }
            else
            {
                bool print = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print){
                    cout << " ";
                }
            }


            if (j == width - 1){
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++){
        cout << "#";
    }

    cout << endl;

    cout << "Score:" << score << endl;

}

//Keyboard input for moving the snake
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
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
        case 'x':
            gameOver = true;
            break;
        }
    }
}

//Main logic of Game and Implementation of Tail of snake
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
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

    if (x > width || x < 0 || y > height || y < 0){
        gameOver = true;
    }

    if (x >= width){
        x = 0;
    }
    else if (x < 0){
        x = width - 1;
    }
    if (y >= height){
        y = 0;
    }
    else if (y < 0){
        y = height - 1;
    }

    for (int i = 0; i < nTail; i++){
        if (tailX[i] == x && tailY[i] == y){
            gameOver = true;
        }
    }

    if (x == ballX && y == ballY)
    {
        score += 10;
        ballX = rand() % width;
        ballY = rand() % height;
        nTail++;
    }
}


int main()
{
    //For Setup of game like walls and starting point
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200); //sleep(10);
    }

    return 0;
}
