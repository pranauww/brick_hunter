#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

#define MOVE_LEFT 75
#define MOVE_RIGHT 77
#define ESC 27

char ch;
int lives = 3;  // Player starts with 3 lives
int score = 0;  // Initial score

void print_line();
void print_line2();
void messagebox();
void winner();
void update_score();
void display_lives_and_score();

void main()
{
    int gd, gm;
    int IMG1, IMG2, IMG3, x, y, i, j, win = 0;
    void *BUFFER1, *BUFFER2, *BUFFER3;
    int x_axis = 325, y_axis = 325, x_direction = -1, y_direction = -1;
    int speed = 15;
    int X_POSITION = 0, Y_POSITION = 0;

    gd = DETECT;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();
    setbkcolor(2);

    /* DRAWING BRICKS */
    rectangle(0, 0, 60, 22);
    setfillstyle(1, 9);  // Standard bricks
    floodfill(2, 2, 15);

    IMG1 = imagesize(0, 0, 60, 22);
    BUFFER1 = malloc(IMG1);
    getimage(0, 0, 60, 22, BUFFER1);

    putimage(0, 0, BUFFER1, XOR_PUT);

    /* PRINTNG BRICKS */
    for (j = 0; j < 300; j += 30)
        for (i = 8; i < 600; i += 70)
        {
            putimage(i, 30 + j, BUFFER1, XOR_PUT);
        }

    print_line();
    print_line2();

    /* DRAWING PADDLE */
    setcolor(6);
    rectangle(80, 445, 180, 460);
    setfillstyle(1, 15);
    floodfill(82, 447, 6);
    IMG2 = imagesize(80, 445, 180, 460);
    BUFFER2 = malloc(IMG2);
    getimage(80, 445, 180, 460, BUFFER2);

    /* DRAWING BALL */
    setcolor(WHITE);
    setfillstyle(1, 12);
    circle(350, 350, 10);
    floodfill(350, 350, WHITE);
    IMG3 = imagesize(340, 340, 360, 360);
    BUFFER3 = malloc(IMG3);
    getimage(340, 340, 360, 360, BUFFER3);
    putimage(340, 340, BUFFER3, XOR_PUT);

    while (lives > 0)  // Run the game as long as the player has lives
    {
        display_lives_and_score();  // Display lives and score at the top

        putimage(x_axis, y_axis, BUFFER3, XOR_PUT);
        delay(speed);
        putimage(x_axis, y_axis, BUFFER3, XOR_PUT);

        x_axis = x_axis + (x_direction * 2);
        y_axis = y_axis + (y_direction * 3);

        if (x_axis + 10 - 1 > 640)
        {
            x_direction *= -1;
            x_axis = 640 - 10 + 1;
        }

        if (x_axis < 0)
        {
            x_direction *= -1;
            x_axis = 0;
        }

        if (y_axis + 10 - 1 > 470)
        {
            cleardevice();
            initgraph(&gd, &gm, "C:\\turboc3\\bgi");
            outtextxy(200, 200, "You lost a life!");
            delay(1000);
            lives--;  // Decrease lives when the ball is lost
            x_axis = 325;
            y_axis = 325;
            if (lives <= 0)
            {
                cleardevice();
                outtextxy(200, 200, "Game Over!");
                delay(2000);
                break;
            }
        }

        if (getpixel(x_axis, y_axis) == 6)  // Paddle collision
        {
            y_direction *= -1;
            sound(900);
            delay(15);
            nosound();
        }

        if (getpixel(x_axis, y_axis) == 9)  // Brick collision
        {
            sound(300);
            delay(50);
            nosound();
            y_direction *= -1;
            x = x_axis;
            y = y_axis;
            x = (x / 70) * 70 + 8;
            y = (y / 30) * 30;
            putimage(x, y, BUFFER1, XOR_PUT);
            win++;
            score += 100;  // Increase score when a brick is hit
            update_score();  // Update score display

            if (win == 40)
            {
                winner();
            }
        }

        if (y_axis < 0)
        {
            y_direction *= -1;
            y_axis = 0;
        }

        if (kbhit())
        {
            ch = getch();
            if (ch != ESC)
            {
                putimage(80 + X_POSITION, 445 + Y_POSITION, BUFFER2, XOR_PUT);
                if (ch == MOVE_LEFT)
                    X_POSITION += -40;
                if (ch == MOVE_RIGHT)
                    X_POSITION += 40;
                putimage(80 + X_POSITION, 445 + Y_POSITION, BUFFER2, XOR_PUT);
            }

            if (ch == ESC)
            {
                /* FREE MEMORY OCCUPIED BY IMAGES */
                free(BUFFER1);
                free(BUFFER2);
                free(BUFFER3);
                closegraph();
                exit(0);
            }
        }
    }
}

void print_line()
{
    setcolor(WHITE);
    line(0, 18, 640, 18);
    line(0, 19, 640, 19);
    line(0, 20, 640, 20);
    line(0, 21, 640, 21);
    line(0, 22, 640, 22);
}

void print_line2()
{
    line(0, 465, 640, 465);
    line(0, 466, 640, 466);
    line(0, 467, 640, 467);
    line(0, 468, 640, 468);
    line(0, 469, 640, 469);
}

void display_lives_and_score()
{
    char text[50];
    setcolor(WHITE);
    sprintf(text, "Lives: %d | Score: %d", lives, score);
    outtextxy(10, 10, text);  // Show lives and score at the top
}

void update_score()
{
    setcolor(WHITE);
    char score_text[20];
    sprintf(score_text, "Score: %d", score);
    outtextxy(500, 10, score_text);
}

void winner()
{
    cleardevice();
    setbkcolor(0);
    setcolor(WHITE);
    rectangle(179, 109, 457, 207);
    outtextxy(222, 140, "Hey You Win the Game !");
    sound(3333);
    delay(999);
    nosound();
    delay(2000);
    exit(0);
}
