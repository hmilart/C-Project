#include <graphics.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <random>
#include <functional>
#include <chrono>
#include <math.h>

using namespace std;

int losuj(int min, int max)
{
	auto int_rand = std::bind(std::uniform_int_distribution<int>(min, max),
		mt19937(chrono::high_resolution_clock::now().time_since_epoch().count()));

	return int_rand();
}


class SnowFlake
{
public:
	SnowFlake();
	void move();
	void draw();
	void gain() { size += 1; };
	float get_y() { return y; };
	float get_x() { return x; };

private:
	void Snow1();
	void Snow2();
	void Snow3();
	void Snow4();
	float x;
	float y;
	float vx;
	float vy;
	float size;
	int n;
	float test;
	//
};
SnowFlake::SnowFlake()
{
	x = losuj(40,760);
	y = losuj(1,560);
	size = losuj(10,30);
	vx = 0;
	vy = losuj(3,5);
	n = losuj(1, 4);
	test = losuj(1, 100);

}
void SnowFlake::move()
{
	x += sin(test / 70);
	y += vy;
	test += 5;
	
}
void SnowFlake::draw()
{
	switch (n)
	{
	case 1:Snow1(); break;
	case 2:Snow2(); break;
	case 3:Snow3(); break;
	case 4:Snow4(); break;
	
	}
	
}
void SnowFlake::Snow1()
{
	line(x - (size / 2), y, x + (size / 2), y);
	line(x, y - (size / 2), x, y + (size / 2));
	line(x - (size / 3), y - (size / 3), x + (size / 3), y + (size / 3));
	line(x - (size / 3), y + (size / 3), x + (size / 3), y - (size / 3));
}
void SnowFlake::Snow2()
{
	line(x - (size / 2), y, x + (size / 2), y);
	line(x, y - (size / 2), x, y + (size / 2));
	line(x - (size / 3), y - (size / 3), x + (size / 3), y + (size / 3));
	line(x - (size / 3), y + (size / 3), x + (size / 3), y - (size / 3));


	line(x - ((size / 2.2)), y - (size/10), x - ((size / 2.2)) + (size/10), y);
	line(x - ((size / 2.2)), y + (size/10), x - ((size / 2.2)) + (size / 10), y);

	line(x + ((size / 2.2)), y + (size / 10), x + ((size / 2.2)) - (size / 10), y);
	line(x + ((size / 2.2)), y - (size / 10), x + ((size / 2.2)) - (size / 10), y);

	line(x - (size / 10), y - (size / 2.2), x, y - (size / 2.2) + (size / 10));
	line(x + (size / 10), y - (size / 2.2), x, y - (size / 2.2) + (size / 10));

	line(x + (size / 10), y + (size / 2.2), x, y + (size / 2.2) - (size / 10));
	line(x - (size / 10), y + (size / 2.2), x, y + (size / 2.2) - (size / 10));

	line(x - (size / 4) , y - (size / 4), x - (size / 4) + (size / 50), y - (size / 4)- (size / 10));
	line(x - (size / 4), y - (size / 4), x - (size / 4) - (size / 10), y - (size / 4)+ (size / 50));

	line(x + (size / 4), y + (size / 4), x + (size / 4) + (size / 10), y + (size / 4) - (size / 50));
	line(x + (size / 4), y + (size / 4), x + (size / 4) - (size / 50), y + (size / 4) + (size / 10));

	line(x - (size / 4), y + (size / 4), x - (size / 4) - (size / 10), y + (size / 4) - (size / 50));
	line(x - (size / 4), y + (size / 4), x - (size / 4) + (size / 50), y + (size / 4) + (size / 10));

	line(x + (size / 4), y - (size / 4), x + (size / 4) - (size/50), y - (size / 4) - (size / 10));
	line(x + (size / 4), y - (size / 4), x + (size / 4) + (size / 10), y - (size / 4) + (size / 50));

}
void SnowFlake::Snow3()
{
	line(x - (size / 2), y, x + (size / 2), y);
	line(x, y - (size / 2), x, y + (size / 2));

	line(x - (size / 10), y - (size / 2.2), x, y - (size / 2.2) + (size / 10));
	line(x + (size / 10), y - (size / 2.2), x, y - (size / 2.2) + (size / 10));

	line(x + (size / 10), y + (size / 2.2), x, y + (size / 2.2) - (size / 10));
	line(x - (size / 10), y + (size / 2.2), x, y + (size / 2.2) - (size / 10));

	line(x - ((size / 2.2)), y - (size / 10), x - ((size / 2.2)) + (size / 10), y);
	line(x - ((size / 2.2)), y + (size / 10), x - ((size / 2.2)) + (size / 10), y);

	line(x + ((size / 2.2)), y + (size / 10), x + ((size / 2.2)) - (size / 10), y);
	line(x + ((size / 2.2)), y - (size / 10), x + ((size / 2.2)) - (size / 10), y);

	line(x - (size / 3), y - (size / 3), x + (size / 3), y + (size / 3));
	line(x - (size / 3), y + (size / 3), x + (size / 3), y - (size / 3));




	
}
void SnowFlake::Snow4()
{
	line(x - (size / 2), y, x + (size / 2), y);
	line(x, y - (size / 2), x, y + (size / 2));

	line(x - (size / 4), y, x - (size / 2), y + (size / 2));
	line(x - (size / 4), y, x - (size / 2), y - (size / 2));

	line(x + (size / 4), y, x + (size / 2), y - (size / 2));
	line(x + (size / 4), y, x + (size / 2), y + (size / 2));

	line(x, y + (size / 4), x - (size / 2), y + (size / 2));
	line(x, y + (size / 4), x + (size / 2), y + (size / 2));

	line(x, y - (size / 4), x - (size / 2), y - (size / 2));
	line(x, y - (size / 4), x + (size / 2), y - (size / 2));




}
int main()
{
	int page = 1;
	initwindow(800, 600);
	vector<SnowFlake> snow;
	for (int i = 0; i < 100; i++)
	{
		SnowFlake s;
		snow.push_back(s);
	}
	


	while (true)
	{
		for (auto i : snow)
		{
			i.draw();
		}
		
		delay(1);
		setactivepage(page);
		setvisualpage(1 - page);
		page = 1 - page;
		cleardevice();
		for (int i = 0;i<snow.size();i++)
		{
			snow[i].move();
			if (snow[i].get_y() > 600)
			{
				snow.erase(snow.begin() + i);
				SnowFlake s;
				snow.push_back(s);
			}
		}


		//s.gain();
	}
	

	getch();
	closegraph();
	return 0;
}


