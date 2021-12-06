#include <stdio.h>
#include <graphics.h>
#include <Windows.h>
#include <math.h>
#include <conio.h>

#define STEP_SIZE 5 //步长

struct dot {
	double x;
	double y;
};
struct dot aa, bb, cc;  //三个焦点的坐标 
double a = 180, b = 90, c = 200;  //三条边的长度   左为a  右为b 下为c

struct dot dd; //下边的最右侧点
int d = c + 100;

//计算a，b，c点的x,y坐标
void calcXY(){
	double tx,ty;
	//计算b点位置  通过a,b,c三边计算角a的余弦值  然后求出c点距离a点的横长和纵长
	tx = ((b * b + c * c - 2 * b * c) / (a * a)) * b;
	ty = sqrt(b * b - tx * tx);
	cc.x = aa.x - tx;
	cc.y = aa.y - ty;

	//a点和b点在同一水平上
	bb.x = aa.x;
	bb.y = aa.y - c;

	//d点和a点也在同一水平上
	dd.x = aa.x;
	dd.y = aa.y + d - (aa.y - bb.y);
}

void draw() {
	cleardevice();  //清屏
	setlinestyle(PS_SOLID, 8);
	setlinecolor(LIGHTGREEN);
	line(aa.y, aa.x, cc.y, cc.x);
	setlinecolor(LIGHTRED);
	line(cc.y, cc.x, bb.y, bb.x);
	setfillcolor(YELLOW);
	solidrectangle(aa.y - 30, aa.x - 10, aa.y + 30, aa.x + 10);
	setlinecolor(LIGHTBLUE);
	line(dd.y, dd.x, bb.y, bb.x);
	setfillcolor(BLACK);
	fillcircle(aa.y, aa.x, 1);
	fillcircle(bb.y, bb.x, 1);
	fillcircle(cc.y, cc.x, 1);
}

int main() {
	initgraph(800, 400);
	aa.x = 200;
	aa.y = 400;
	dd.x = 200;
	dd.y = 500;

	while (true) {
		while (dd.y - aa.y > 40) {
			c += STEP_SIZE;
			calcXY();
			draw();
			Sleep(200);
		}
		while (dd.y - aa.y < 90) {
			c -= STEP_SIZE;
			calcXY();
			draw();
			Sleep(200);
		}
	}
}