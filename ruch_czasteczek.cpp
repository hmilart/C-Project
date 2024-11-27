#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;


struct point
{
    float x;
    float y;
    float vx;
    float vy;
};


float distance(point p1, point p2)
{
     return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
float randFloat(float min, float max)
{
    return min + (max - min) * (float)rand() / RAND_MAX;
}

void drawPoint(point p, int c)
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(p.x, p.y, 3, 3);
}

void draw()
{

}

int main()
{
    int w = 300;
    int h = 300;

    int n = 60;

    float minDistance = 0;

    int page = 1;

    srand(time(0));
    initwindow(800, 600);

    vector<point> pointCollection;
    

    for (int i = 0; i < n; i++)
    {
        point p;
        p.x = rand() % w;
        p.y = rand() % h;
        p.vx = randFloat(-2, 2);
        p.vy = randFloat(-2, 2);
        pointCollection.push_back(p);
    }
    while (true)
    {
        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                minDistance = w * h;
                point p{ x,y };
                for (int i = 0; i < n; i++)
                {

                    float dist = distance(pointCollection[i], p);
                    if (dist < minDistance) minDistance = dist;
                }
                int color = 10*(int)(255 * (minDistance / (w + h)));
                drawPoint(p, COLOR(color, color, color));

            }
        }
        for (auto i : pointCollection)
        {
            drawPoint(i, COLOR(255, 255, 255));
        }
        //delay(1);

        setactivepage(page);
        setvisualpage(1 - page);
        page = 1 - page;
        cleardevice();

        for (int i = 0; i < n; i++)
        {
          
            pointCollection[i].x += pointCollection[i].vx;
            pointCollection[i].y += pointCollection[i].vy;
            

            if (pointCollection[i].x<0 or pointCollection[i].x > w) pointCollection[i].vx *= -1;
            if (pointCollection[i].y<0 or pointCollection[i].y > h) pointCollection[i].vy *= -1;
        }
        
        
    }
    


    getch();
    closegraph();
    return 0;
}

