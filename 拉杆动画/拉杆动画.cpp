#include <stdio.h>
#include <graphics.h>
#include <Windows.h>
#include <math.h>
#include <conio.h>

#define STEP_SIZE 5 //����

struct dot {
	double x;
	double y;
};
struct dot aa, bb, cc;  //������������� 
double a = 180, b = 90, c = 200;  //�����ߵĳ���   ��Ϊa  ��Ϊb ��Ϊc

struct dot dd; //�±ߵ����Ҳ��
int d = c + 100;

//����a��b��c���x,y����
void calcXY(){
	double tx,ty;
	//����b��λ��  ͨ��a,b,c���߼����a������ֵ  Ȼ�����c�����a��ĺ᳤���ݳ�
	tx = ((b * b + c * c - 2 * b * c) / (a * a)) * b;
	ty = sqrt(b * b - tx * tx);
	cc.x = aa.x - tx;
	cc.y = aa.y - ty;

	//a���b����ͬһˮƽ��
	bb.x = aa.x;
	bb.y = aa.y - c;

	//d���a��Ҳ��ͬһˮƽ��
	dd.x = aa.x;
	dd.y = aa.y + d - (aa.y - bb.y);
}

void draw() {
	cleardevice();  //����
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