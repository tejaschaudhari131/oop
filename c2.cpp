#include<iostream>
#include<graphics.h>

using namespace std;

class Triangle
{		
	public:
		int x1,x2,y1,y2,x3,y3,xavg,yavg;
		void get_coordinates()
		{
			cout<<"Enter the co-ordinates:";
			cin>>x1>>y1>>x2>>y2>>x3>>y3;
		}
		
		void get_midpoint()
		{
			xavg = (x1+x2+x3)/3;
			yavg = (y1+y2+y3)/3;
		}
};

class Fill:public Triangle
{
	//int o_color,n_color,a,b;
	public:
		void floodfill(int a,int b,int o_color,int n_color)
		{
			int current_pixel = getpixel(a,b);
			if(current_pixel == o_color)
			{	
				putpixel(a,b,n_color);
				floodfill(a+1,b,o_color,n_color);
				floodfill(a-1,b,o_color,n_color);
				floodfill(a,b+1,o_color,n_color);
				floodfill(a,b-1,o_color,n_color);
			
			}
		}
};

int main()
{
	Fill pol1;
	pol1.get_coordinates();
	pol1.get_midpoint();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(pol1.x1,pol1.y1,pol1.x2,pol1.y2);
	line(pol1.x2,pol1.y2,pol1.x3,pol1.y3);
	line(pol1.x1,pol1.y1,pol1.x3,pol1.y3);
	pol1.floodfill(pol1.xavg,pol1.yavg,BLACK,RED);
	getch();
	
	return 0;
}
