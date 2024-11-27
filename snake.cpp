#include <iostream>
#include <graphics.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

struct snakep
{
    float x;
    float y;
    float speed;
    int shape;
    float alpha;
};
struct reward
{
    int x;
    int y;
    int value;
    int color;

};


void rgb(double ratio, int& Or, int& Og, int& Ob)
{
    int normalized = int(ratio * 256 * 6);

    
    int region = normalized / 256;

    
    int x = normalized % 256;

    uint8_t r = 0, g = 0, b = 0;
    switch (region)
    {
    case 0: r = 255; g = 0;   b = 0;   g += x; break;
    case 1: r = 255; g = 255; b = 0;   r -= x; break;
    case 2: r = 0;   g = 255; b = 0;   b += x; break;
    case 3: r = 0;   g = 255; b = 255; g -= x; break;
    case 4: r = 0;   g = 0;   b = 255; r += x; break;
    case 5: r = 255; g = 0;   b = 255; b -= x; break;
    }
    
    Or = r;
    Og = g;
    Ob = b;
}

void drawGrid(int size)
{
    setlinestyle(SOLID_LINE, 1, 1);
    setcolor(COLOR(64, 64, 64));
    int marginLeft = 40;
    int marginRight = 240;
    int marginTop = 40;
    int marginBottom = 240;
    int g = 20;
    for (int i = marginLeft; i <= size - marginRight; i += g)
    {
        line(i, marginTop, i, size - marginBottom);
        line(marginLeft, i, size - marginRight, i);
    }
    rectangle(620, 200, 720, 260);
    rectangle(620, 300, 720, 360);

}




void drawSnake(vector<snakep> snake)
{
    setlinestyle(SOLID_LINE, 1, 2);
    setcolor(COLOR(25, 220, 40));
    setfillstyle(SOLID_FILL, COLOR(25, 220, 40));
    int r;
    int g;
    int b;
    for (int i = 0; i < snake.size(); i++)
    {
        rgb((float)i / snake.size(), r, g, b);
        
        
        setcolor(COLOR(r, g, b));
        setfillstyle(SOLID_FILL, COLOR(r, g, b));
            
        
        fillellipse(snake[i].x, snake[i].y, 7, 7);
    }


}
void moveSnake(vector<snakep> &snake)
{
    float kx = snake[0].speed * cos(snake[0].alpha);
    float ky = snake[0].speed * sin(snake[0].alpha);
    snake[0].x += kx;
    snake[0].y += ky;
    
}


void drawPoint(reward point)
{
    setcolor(COLOR(255, 0, 0));
    setfillstyle(SOLID_FILL, COLOR(255, 0, 0));
    fillellipse(point.x, point.y, 4, 4);
}


bool checkBorder(vector<snakep>& snake)
{
    if (snake[0].x+5 >= 560)
    {
        snake[0].x = 41+5;
        return true;
    }
    else if (snake[0].x - 5 <= 40)
    {
        snake[0].x = 559 - 5;
        return true;
    }
    else if (snake[0].y - 5 <= 40)
    {
        snake[0].y = 559 - 5;
        return true;
    }
    else if (snake[0].y + 5 >= 560)
    {
        snake[0].y = 41 + 5;
        return true;
    }
}

void collisionPoint(vector<snakep> &snake, vector<reward> &points, int &score)
{
    for(int i=0;i<points.size();i++)
    {
        if (sqrt(pow(snake[0].x - points[i].x,2) + pow(snake[0].y - points[i].y,2)) < 12)
        {
            
            points.erase(points.begin() + i);
            reward point{ (3 + rand() % 24) * 20,(3 + rand() % 24) * 20, 1,1 };
            
            points.push_back(point);
            snakep d;
            
            snake.push_back(d);

            score++;
            
            break;
            
        }
    }
   
}
void collisionSnake(vector<snakep>& snake, int& score, int hs, int k)
{
    for (int i = k; i < snake.size(); i++)
    {
        if (sqrt(pow(snake[0].x - snake[i].x, 2) + pow(snake[0].y - snake[i].y, 2)) < 5)
        {
            getch();
            closegraph();
            if (score > hs)
            {
                fstream plik;
                plik.open("hs.txt", ios::out);
                plik << score;
                plik.close();
            }
            
            exit(0);
        }
    }

}
int main()
{

    srand(time(0));
    int sizes = 1;
    
    
    vector<snakep> snake;
    vector<reward> points;

    int page = 1;
    int size = 800; 
    
    initwindow(size, size);

   
    for (int i = 0; i < 10; i++)
    {
        reward point{ (3 + rand() % 24) * 20,(3 + rand() % 24) * 20, 1,1 };
        points.push_back(point);
    }
    for (int i = 0; i < sizes; i++)
    {
        snakep p{ 300,300,1,1,0 };
        snake.push_back(p);
    }
    int l = 0;
    int score = 0;
    char buff[10];
    string hs;
    int highScore = 0;

    fstream plik;
    plik.open("hs.txt", ios::in);
    getline(plik, hs);
    plik.close();
    int t = 0;
    bool p = false;
    int k = 100000000;

    highScore = stoi(hs);

    while (true)
    {
        if (t % 50 == 0) p = false;
        setcolor(COLOR(255, 255, 255));
        settextstyle(SMALL_FONT, HORIZ_DIR, 11);
        sprintf_s(buff, "%3.3i", score);
        outtextxy(630, 210, buff);
        
        sprintf_s(buff, "%3.3i", highScore);
        outtextxy(630, 310, buff);
        drawGrid(size);
        drawSnake(snake);

        if (p)
        {
            t++;
            collisionSnake(snake, score, highScore, k);
        }
        if (!p)
        {
            collisionSnake(snake, score, highScore, 5);
        }
        if (t % 3000 == 0)
        {
            t = 0;
            p = false;
        }

        for (int i = 0; i < points.size(); i++)
        {
            drawPoint(points[i]);
        }
        
        delay(1);



        setactivepage(page);
        setvisualpage(1 - page);
        page = 1 - page;

        cleardevice();
        


        moveSnake(snake);
        p = checkBorder(snake);
        collisionPoint(snake, points, score);
        
       

        if (ismouseclick(WM_LBUTTONDOWN) and snake.size()>2)
        {
            snake[0].speed = 2;
            l++;
            if (l % 7 == 0)
            {
                snake.erase(snake.begin() + snake.size() - 1);
                score--;
            }

        }
        if (ismouseclick(WM_LBUTTONUP))
        {
            snake[0].speed = 1;
            
            clearmouseclick(WM_LBUTTONDOWN);
            clearmouseclick(WM_LBUTTONUP);
        }
        if (snake.size() == 2) snake[0].speed = 1;
            
        

        float alpha = atan2(mousey() - snake[0].y, mousex() - snake[0].x);
        snake[0].alpha = alpha;

        for (int i = 0; i < snake.size() - 1; i++) 
        {
            float alpha = atan2(snake[i].y - snake[i+1].y,snake[i].x - snake[i+1].x);
            float px = 5 * cos(alpha);
            float py = 5 * sin(alpha);
            snake[i + 1].x = snake[i].x - px;
            snake[i + 1].y = snake[i].y - py;
        }

        
       
        

        
        
    }
   



    getch();
    closegraph();
}


