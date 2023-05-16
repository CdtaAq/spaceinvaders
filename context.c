#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int spaceshipX;
int spaceshipY;
int bulletX;
int bulletY;
int alienX;
int alienY;
int score;
int gameover;

void setup()
{
    spaceshipX = WIDTH / 2;
    spaceshipY = HEIGHT - 1;
    bulletX = spaceshipX;
    bulletY = spaceshipY - 1;
    alienX = WIDTH / 2;
    alienY = 0;
    score = 0;
    gameover = 0;
}

void draw()
{
    system("cls");

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (y == spaceshipY && x == spaceshipX)
                printf("V");
            else if (y == bulletY && x == bulletX)
                printf("|");
            else if (y == alienY && x == alienX)
                printf("A");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
    printf("Press 'q' to quit.\n");
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();
        if (key == 'a' && spaceshipX > 0)
            spaceshipX--;
        else if (key == 'd' && spaceshipX < WIDTH - 1)
            spaceshipX++;
        else if (key == 'w' && bulletY == spaceshipY - 1)
            bulletY--;
        else if (key == 'q')
            gameover = 1;
    }
}

void update()
{
    if (bulletY >= 0)
        bulletY--;

    if (alienY < HEIGHT)
    {
        if (bulletY == alienY && bulletX == alienX)
        {
            score++;
            alienX = rand() % WIDTH;
            alienY = 0;
            bulletY = -1;
        }
        else
        {
            alienY++;
        }
    }
    else
    {
        gameover = 1;
    }
}

int main()
{
    setup();

    while (!gameover)
    {
        draw();
        input();
        update();
        Sleep(100);
    }

    printf("Game Over! Your score: %d\n", score);

    return 0;
}
