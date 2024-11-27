// "a" żeby zwiększyć współczynnik a
// "z" żeby zmniejszyć współczynnik a

// "s" żeby zwiększyć współczynnik b
// "x" żeby zmniejszyć współczynnik b

// "d" żeby zwiększyć współczynnik c
// "c" żeby zmniejszyć współczynnik c

// "n" żeby przybliżyć oś x
// "h" żeby oddalić oś x

// "m" żeby przybliżyć oś y
// "j" żeby oddalić oś y

//przytrzymując lewy przycisk myszy na kwadracikach umieszczonych na bokach wyśwtetlanego pola można manipulować wielkością tego pola
//przytrzymując lewy przycisk myszy wewnątrz wyświetlanego pola można dowolnie przesuwać te pole


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <graphics.h>
#include <math.h>
//#include <conio.h>

using namespace std;

class grid
{
public:
    grid(int, int, int, int);
    void draw();
    void setpos(int ,int);
    int getW() { return w; };
    int getH() { return h; };
    int getX0() { return x0; };
    int getY0() { return y0; };
    int getMW() { return mw; };
    int getMH() { return mh; };
    void changeSizeRD(int, int);
    void changeSizeRU(int, int);
    void changeSizeR(int, int);
    void changeSizeU(int, int);
    void changeSizeD(int, int);
    void changeSizeL(int, int);
    void changeSizeLU(int, int);
    void changeSizeLD(int, int);
    void lFunction(float, float);
    void sqFunction(float, float, float);
    void setXcut(int);
    void setYcut(int);
private:
    int w;
    int h;
    int x0;
    int y0;
    int mw = 2;
    int mh = 2;
    int cx = 0;
    int cy = 0;
    float kroky;
    float krokx;
    vector<float> x;
    vector<float> y;
    void functionDraw();
    void changeCut(float, float);
    int xcut = 10;
    int ycut = 10;

};
grid::grid(int x0 = 20, int  y0 = 20, int w = 400, int h = 400)
{
    this->x0 = x0;
    this->y0 = y0;
    this->w = w;
    this->h = h;
}
void grid::draw()
{
    setlinestyle(SOLID_LINE, 1,1);
    setcolor(COLOR(81, 90, 90));
    setfillstyle(SOLID_FILL, COLOR(255, 255, 255));
    rectangle(x0, y0, x0 + w, y0 + h);
    setcolor(COLOR(255, 255, 255));
    bar(x0 - mw, y0 - mh, x0 + mw, y0 + mh); //lewy górny
    bar(x0 - mw, y0 + h - mh, x0 + mw, y0 + h + mh); //lewy dolny

    bar(x0 + w - mw, y0 + h - mh, x0 + w + mw, y0 + h + mh); // prawy dolny
    bar(x0 + w - mw, y0 - mh, x0 + w + mw, y0 + mh); // prawy górny


    bar(w / 2 + x0 - mw, y0 - mh, w / 2 + x0 + mw, y0 + mh); //góra
    bar(w / 2 + x0 - mw, y0 + h - mh, w / 2 + x0 + mw, y0 + h + mh); //dół

    bar(x0 - mw, h / 2 + y0 - mh, x0 + mw, h / 2 + y0 + mh); //lewo
    bar(x0 + w - mw, h / 2 + y0 - mh, x0 + w + mw, h / 2 + y0 + mh); //prawo

    line(x0, y0 + h / 2, x0 + w, y0 + h / 2);
    line(x0 + w/2, y0, x0 + w/2, y0 + h);

    
    
    kroky = h / 2 / ycut;
    krokx = w / 2 / xcut;
    
    char buff[10];

    settextstyle(SMALL_FONT, HORIZ_DIR, 4);

    for (int i = 1; i < ycut; i++)
    {
        line(x0 + w / 2 - 4, y0 + h / 2 + kroky * i, x0 + w / 2 + 4, y0 + h / 2 + kroky * i);
        _itoa(-i, buff, 10);
        outtextxy(x0 + w / 2 - 12, y0 + h / 2 + kroky * i - 5, buff );


        line(x0 + w / 2 - 4, y0 + h / 2 - kroky * i, x0 + w / 2 + 4, y0 + h / 2 - kroky * i);
        
    }

    for (int i = 1; i < xcut; i++)
    {
        line(x0 + w / 2 + krokx * i, y0 + h / 2 + 4, x0 + w / 2 + krokx * i, y0 + h / 2 - 4);
        _itoa(i, buff, 10);
        outtextxy(x0 + w / 2 + krokx * i - 3 , y0 + h / 2 + 6, buff);


       
        line(x0 + w / 2 - krokx * i, y0 + h / 2 + 4, x0 + w / 2 - krokx * i, y0 + h / 2 - 4);
    }
}
void grid::setpos(int x, int y)
{
    this->x0 = x;
    this->y0 = y;
    
}
void grid::changeSizeRD(int x, int y)
{
    w =  x - x0;
    h =  y - y0;
    
}
void grid::changeSizeRU(int x, int y)
{
    w = x - x0; 
    h = h - y + y0;
    y0 = y ;
}
void grid::changeSizeR(int x, int y)
{
    w = x - x0;
}
void grid::changeSizeU(int x, int y)
{
    h = h - y + y0;
    y0 = y;
}
void grid::changeSizeD(int x, int y)
{
    h = y - y0;
}
void grid::changeSizeL(int x, int y)
{
    w = w - x + x0;
    x0 = x;
}
void grid::changeSizeLU(int x, int y)
{
    w = w - x + x0;
    x0 = x;
    h = h - y + y0;
    y0 = y;
}
void grid::changeSizeLD(int x, int y)
{
    w = w - x + x0;
    x0 = x;

    h = y - y0;
    
}
void grid::lFunction(float a, float b )
{
    char buff[10];
    
    x.clear();
    y.clear();
    for (float i = -xcut; i < xcut; i+=0.1)
    {
        x.push_back(i * krokx);
        y.push_back(a * i * kroky + b * kroky);
    }

    functionDraw();
    setcolor(COLOR(255, 255, 255));
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    sprintf(buff, "a: %2.2f", a);
    outtextxy(x0 + w - 45, y0 + 20, buff);
    sprintf(buff, "b: %2.2f", b);
    outtextxy(x0 + w - 45, y0 + 40, buff);
}
void grid::sqFunction(float a, float b, float c)
{
    float delta = pow(b,2) - 4*a*c;
    float xzero = 0;
    float xone = 0;
    

    char buff[100];
    
    x.clear();
    y.clear();
    for (float i = -xcut; i <= xcut; i+=0.1)
    {
        x.push_back(i * krokx);
        y.push_back(a * pow(i,2) * kroky + b * i * kroky + c * kroky);
    }
    
    functionDraw();
    setcolor(COLOR(255, 255, 255));
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    sprintf(buff, "a: %2.2f", a);
    outtextxy(x0 + w - 45, y0 + 20, buff);
    sprintf(buff, "b: %2.2f", b);
    outtextxy(x0 + w - 45, y0 + 40, buff);
    sprintf(buff, "c: %2.2f", c);
    outtextxy(x0 + w - 45, y0 + 60, buff);

    
    if (delta > 0)
    {
        xzero = (-b - sqrt(delta)) / (2 * a);
        xone = (-b + sqrt(delta)) / (2 * a);
        sprintf(buff, "x1: %2.2f", xzero);
        outtextxy(x0 + 25, y0 + 20, buff);
        sprintf(buff, "x2: %2.2f", xone);
        outtextxy(x0 + 25, y0 + 40, buff);
    }
    else if (delta == 0)
    {
        xzero = -b / (2 * a);
        sprintf(buff, "x1: %2.2f", xzero);
        outtextxy(x0 + 25, y0 + 20, buff);
        sprintf(buff, "x2: %2.2f", xzero);
        outtextxy(x0 + 25, y0 + 40, buff);
    }
    else
    {
        sprintf(buff, "x1: brak");
        outtextxy(x0 + 25, y0 + 20, buff);
        sprintf(buff, "x2: brak");
        outtextxy(x0 + 25, y0 + 40, buff);
    }
        

}
void grid::setXcut(int xcut)
{
    this->xcut += xcut;
}
void grid::setYcut(int ycut)
{
    this->ycut += ycut;
}
void grid::functionDraw()
{
    
    for (int i = 0; i < x.size(); i++)
    {
        if (y[i] <= ycut * kroky and y[i] >= -ycut * kroky)
        {
            moveto(x0 + x[i] + w / 2, y0 + -y[i] + h / 2);
            break;
        }
    }
    
    for (int i = 0; i < x.size(); i++)
    {
        if (y[i] <= ycut * kroky and y[i] >= -ycut * kroky)lineto(x0 + x[i] + w / 2, y0 + -y[i] + h / 2);
    }
    setfillstyle(SOLID_FILL, COLOR(255, 50, 0));
    setcolor(COLOR(255, 50, 0));
    for (int i = 0; i < x.size(); i++)
    {
        if(y[i]<= ycut*kroky and y[i] >=  -ycut * kroky)fillellipse(x0 + x[i] + w / 2, y0 + -y[i] + h / 2, 2, 2);
    }




}
void grid::changeCut(float xcut, float ycut)
{
    this->xcut = xcut;
    this->ycut = ycut;
}

int main()
{
    initwindow(800, 600);

    grid g;
    int page = 1;
    int condition = 0;

    int mx = 0;
    int my = 0;

    int cx = 0;
    int cy = 0;

    
    float a, b, c;
    a = 1;
    b = 0;
    c = 0;

    char buff[10];

    
    while (true)
    {
        
        g.draw();
        g.sqFunction(a,b,c);
        
        


        delay(1);
        setactivepage(page);
        setvisualpage(1 - page);
        page = 1 - page;


        cleardevice();
       
       


        if (mousex() > g.getX0()+15 and mousex() < g.getX0()-15 + g.getW() and mousey() > g.getY0()+15 and mousey() < g.getY0()-15 + g.getH() and ismouseclick(WM_LBUTTONDOWN))
        {
            
            if(condition!=2) condition = 1;
            else if(condition==2)
            {
                g.setpos(mousex() - mx, mousey() - my);
            }
           
        }
        if (mousex() > g.getX0() + g.getW() - g.getMW() - 8 and mousex() < g.getX0() + g.getW() + g.getMW() + 8 and mousey() > g.getY0() + g.getH()  - g.getMH() - 8 and mousey() < g.getY0() + g.getH() + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
           // prawy dolny
            g.changeSizeRD(mousex(), mousey());
        }
        if (mousex() > g.getX0() + g.getW() - g.getMW() - 8 and mousex() < g.getX0() + g.getW() + g.getMW() + 8 and mousey() > g.getY0()  - g.getMH() - 8 and mousey() < g.getY0()  + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            // prawy górny
            g.changeSizeRU(mousex(), mousey());
        }
        if (mousex() > g.getX0() + g.getW() - g.getMW() - 8 and mousex() < g.getX0() + g.getW() + g.getMW() + 8 and mousey() > g.getY0() + (g.getH()/2) - g.getMH() - 8 and mousey() < g.getY0() + (g.getH()/2) + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            //prawo
            g.changeSizeR(mousex(), mousey());
        }
        if (mousex() > g.getX0() + g.getW()/2 - g.getMW() - 8 and mousex() < g.getX0() + g.getW()/2 + g.getMW() + 8 and mousey() > g.getY0() - g.getMH() - 8 and mousey() < g.getY0() + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
             //góra
            g.changeSizeU(mousex(), mousey());
        }
        if (mousex() > g.getX0() + g.getW() / 2 - g.getMW() - 8 and mousex() < g.getX0() + g.getW() / 2 + g.getMW() + 8 and mousey() > g.getY0() + g.getH() - g.getMH() - 8 and mousey() < g.getY0() + g.getH() + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            //dół
            g.changeSizeD(mousex(), mousey());
        }
        if (mousex() > g.getX0() - g.getMW() - 8 and mousex() < g.getX0() + g.getMW() + 8 and mousey() > g.getY0() + (g.getH() / 2) - g.getMH() - 8 and mousey() < g.getY0() + (g.getH() / 2) + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            //lewo
            g.changeSizeL(mousex(), mousey());
        }
        if (mousex() > g.getX0() - g.getMW() - 8 and mousex() < g.getX0() + g.getMW() + 8 and mousey() > g.getY0() - g.getMH() - 8 and mousey() < g.getY0() + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            // lewy górny
            g.changeSizeLU(mousex(), mousey());
        }
        if (mousex() > g.getX0() - g.getMW() - 8 and mousex() < g.getX0() + g.getMW() + 8 and mousey() > g.getY0() + g.getH() - g.getMH() - 8 and mousey() < g.getY0() + g.getH() + g.getMH() + 8 and ismouseclick(WM_LBUTTONDOWN))
        {
            // lewy górny
            g.changeSizeLD(mousex(), mousey());
        }



        if(ismouseclick(WM_LBUTTONUP))
        {
            condition = 0;
            clearmouseclick(WM_LBUTTONDOWN);
            clearmouseclick(WM_LBUTTONUP);
        }
        if (condition == 1)
        {
            mx = mousex() - g.getX0();
            my = mousey() - g.getY0();
            condition = 2;
        }
        
        if (kbhit())
        {
            
            switch (getch())
            {
                case 'a':
                {
                    a += 0.01;
                }break;
                case 'z':
                {
                    a -= 0.01;
                }break;
                case 's':
                {
                    b += 0.1;
                }break;
                case 'x':
                {
                    b -= 0.1;
                }break;
                case 'd':
                {
                    c += 0.1;
                }break;
                case 'c':
                {
                    c -= 0.1;
                }break;
                case 'r':
                {
                    a = 1.00;
                    b = 0.00;
                    c = 0.00;
                }break;
                case 'h':
                {
                    g.setXcut(1);
                }break;
                case 'n':
                {
                    g.setXcut(-1);
                }break;
                case 'j':
                {
                    g.setYcut(1);
                }break;
                case 'm':
                {
                    g.setYcut(-1);
                }break;
            }
        }




        
    }
   
    


    getch();

}

