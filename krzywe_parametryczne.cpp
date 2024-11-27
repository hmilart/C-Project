// prawy przycisk myszy tworzy kwadrat
// tworząc 4 kwadraty dodaje nam się krzywa 
// lewy przycisk myszy umozliwa przesuwanie kwadratow
// utworzenie więcej lub mniej kwadratów nie wyświetla krzywej



#include <iostream>
#include <graphics.h>
#include <math.h>
#include <vector>

using namespace std;

class square
{
public:
    square(int, int ,int, int);
    void draw();
    void move(float, float);
    int getX() { return x; };
    int getY() { return y; };
    int getH() { return h; };
    void setCondition(int condition) { this->condition = condition; };
    int getCondition() { return condition; };


private:
    int x;
    int y;
    int h;
    int condition = 0;

};
square::square(int x, int y, int h, int condition)
{
    this->x = x;
    this->y = y;
    this->h = h;
    this->condition = condition;
}
void square::draw()
{
    bar(x - h / 2, y - h / 2, x + h / 2, y + h / 2);
}
void square::move(float mx, float my)
{
    x = mx;
    y = my;
}
double silnia(int n)
{
    double w = 1;
    for (int i = 1; i <= n; i++)
    {
        w *= i;
    }
    return w;
}

int main()
{
    double si[170];
    int condition = 0;
    initwindow(800, 600);
    int page = 1;

    int n = NULL;

    vector<square> sq;


    for (int i = 1; i < 170; i++)
    {
        si[i-1] = silnia(i);
    }
    
    


    while (true)
    {
        for (int i = 0; i < sq.size(); i++)
        {
            sq[i].draw();
        }
        if (sq.size() == 4)
        {
            moveto(sq[0].getX(), sq[0].getY());
            setlinestyle(SOLID_LINE, 1, 3);
            for (float t = 0.00; t < 1.0; t += 0.01)
            {
                float px = sq[0].getX() *  pow(1.0-t, 3) + 3 * sq[1].getX() * t *  pow(1.0-t, 2) + 3 * sq[2].getX() * pow(t, 2) * (1.0 - t) + sq[3].getX() * pow(t, 3);
                float py = sq[0].getY() *  pow(1.0-t, 3) + 3 * sq[1].getY() * t *  pow(1.0-t, 2) + 3 * sq[2].getY() * pow(t, 2) * (1.0 - t) + sq[3].getY() * pow(t, 3);
                lineto(px, py);
            }
        }


        delay(1);




        setvisualpage(page);
        setactivepage(1 - page);
        page = 1 - page;
        cleardevice();


        for (int i = 0; i < sq.size(); i++)
        {
            if (sq[i].getCondition() != 1 and mousex() >= sq[i].getX() - sq[i].getH() / 2 and mousex() <= sq[i].getX() + sq[i].getH() / 2 and mousey() >= sq[i].getY() - sq[i].getH() / 2 and mousey() <= sq[i].getY() + sq[i].getH() / 2 and ismouseclick(WM_LBUTTONDOWN))
            {
                sq[i].setCondition(1);
                n = i;
            }
            if (sq[n].getCondition() == 1) sq[n].move(mousex(), mousey());
            if (ismouseclick(WM_LBUTTONUP))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                sq[n].setCondition(0);
                clearmouseclick(WM_LBUTTONUP);
            }
           

        }
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            clearmouseclick(WM_RBUTTONDOWN);
            square s(mousex(), mousey(), 10, 0);
            sq.push_back(s);
        }

        if (sq.size() > 1)
        {
            moveto(sq[0].getX(), sq[0].getY());
            for (int i = 0; i < sq.size(); i++)
            {
                setlinestyle(DOTTED_LINE, 1, 1);
                lineto(sq[i].getX(), sq[i].getY());
            }
        }

    }
    

    getch();
    closegraph();
}
