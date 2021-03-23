#include <bangtal.h>
#include<stdio.h>
#include<stdlib.h>
SceneID sc;
TimerID time;
int  klk, a, b, ax[5], ay[5], x[5][5] = { 0, }, y[5][5] = { 0, }, j[8] = { 3,0,4,1,5,0,4,-1 };
ObjectID r, l, sb, rb, eb, ori, cau;
ObjectID i[5][5] = {
		{ createObject("\\images\\21.png"), createObject("\\images\\16.png"), createObject("\\images\\11.png"), createObject("\\images\\6.png"), createObject("\\images\\1.png")},
		{ createObject("\\images\\22.png"),createObject("\\images\\17.png"),createObject("\\images\\12.png") ,createObject("\\images\\7.png") ,createObject("\\images\\2.png") },
		{ createObject("\\images\\23.png"),createObject("\\images\\18.png"),createObject("\\images\\13.png") ,createObject("\\images\\8.png") ,createObject("\\images\\3.png") },
		{ createObject("\\images\\24.png"),createObject("\\images\\19.png"),createObject("\\images\\14.png") ,createObject("\\images\\9.png") ,createObject("\\images\\4.png") },
		{ createObject("\\images\\25.png"),createObject("\\images\\20.png"),createObject("\\images\\15.png") ,createObject("\\images\\10.png") ,createObject("\\images\\5.png") }
};
ObjectID mulchae(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}
void ans() {
	for (a = 0; a < 5; a++) {
		ax[a] = 60 + 100 * a;
	}
	for (b = 0; b < 5; b++) {
		ay[b] = 100 * b;
	}
	for (a = 0; a < 5; a++) {
		for (b = 0; b < 5; b++) {
			locateObject(i[a][b], sc, ax[a], ay[b]);
			x[a][b] = a; y[a][b] = b;
			showObject(i[a][b]);
		}
	}
}
void win() {
	ans();
	stopTimer(time);
	showMessage("축하합니다. 역시 중앙인이군요.");
}
int xgap(ObjectID obj)
{
	int a = 0, b = 0; {
		if (obj == i[0][0]) { a = 0; b = 0; }
		else if (obj == i[0][1]) { a = 0; b = 1; }
		else if (obj == i[0][2]) { a = 0; b = 2; }
		else if (obj == i[0][3]) { a = 0; b = 3; }
		else if (obj == i[0][4]) { a = 0; b = 4; }
		else if (obj == i[1][0]) { a = 1; b = 0; }
		else if (obj == i[1][1]) { a = 1; b = 1; }
		else if (obj == i[1][2]) { a = 1; b = 2; }
		else if (obj == i[1][3]) { a = 1; b = 3; }
		else if (obj == i[1][4]) { a = 1; b = 4; }
		else if (obj == i[2][0]) { a = 2; b = 0; }
		else if (obj == i[2][1]) { a = 2; b = 1; }
		else if (obj == i[2][2]) { a = 2; b = 2; }
		else if (obj == i[2][3]) { a = 2; b = 3; }
		else if (obj == i[2][4]) { a = 2; b = 4; }
		else if (obj == i[3][0]) { a = 3; b = 0; }
		else if (obj == i[3][1]) { a = 3; b = 1; }
		else if (obj == i[3][2]) { a = 3; b = 2; }
		else if (obj == i[3][3]) { a = 3; b = 3; }
		else if (obj == i[3][4]) { a = 3; b = 4; }
		else if (obj == i[4][0]) { a = 4; b = 0; }
		else if (obj == i[4][1]) { a = 4; b = 1; }
		else if (obj == i[4][2]) { a = 4; b = 2; }
		else if (obj == i[4][3]) { a = 4; b = 3; }
		else if (obj == i[4][4]) { a = 4; b = 4; }
	}
	return a;
}
int ygap(ObjectID obj)
{
	int a = 0, b = 0; {
		if (obj == i[0][0]) { a = 0; b = 0; }
		else if (obj == i[0][1]) { a = 0; b = 1; }
		else if (obj == i[0][2]) { a = 0; b = 2; }
		else if (obj == i[0][3]) { a = 0; b = 3; }
		else if (obj == i[0][4]) { a = 0; b = 4; }
		else if (obj == i[1][0]) { a = 1; b = 0; }
		else if (obj == i[1][1]) { a = 1; b = 1; }
		else if (obj == i[1][2]) { a = 1; b = 2; }
		else if (obj == i[1][3]) { a = 1; b = 3; }
		else if (obj == i[1][4]) { a = 1; b = 4; }
		else if (obj == i[2][0]) { a = 2; b = 0; }
		else if (obj == i[2][1]) { a = 2; b = 1; }
		else if (obj == i[2][2]) { a = 2; b = 2; }
		else if (obj == i[2][3]) { a = 2; b = 3; }
		else if (obj == i[2][4]) { a = 2; b = 4; }
		else if (obj == i[3][0]) { a = 3; b = 0; }
		else if (obj == i[3][1]) { a = 3; b = 1; }
		else if (obj == i[3][2]) { a = 3; b = 2; }
		else if (obj == i[3][3]) { a = 3; b = 3; }
		else if (obj == i[3][4]) { a = 3; b = 4; }
		else if (obj == i[4][0]) { a = 4; b = 0; }
		else if (obj == i[4][1]) { a = 4; b = 1; }
		else if (obj == i[4][2]) { a = 4; b = 2; }
		else if (obj == i[4][3]) { a = 4; b = 3; }
		else if (obj == i[4][4]) { a = 4; b = 4; }
	}
	return b;
}
void change(ObjectID obj) {
	int a = 0, b = 0, xxx, yyy;
	a = xgap(obj);
	b = ygap(obj);
	xxx = x[a][b]; x[a][b] = x[4][0]; x[4][0] = xxx;
	yyy = y[a][b]; y[a][b] = y[4][0]; y[4][0] = yyy;
	locateObject(i[a][b], sc, ax[x[a][b]], ay[y[a][b]]);
	locateObject(i[4][0], sc, ax[x[4][0]], ay[y[4][0]]);
}
int check(ObjectID obj) {
	int  aaa, bbb;
	aaa = x[xgap(obj)][ygap(obj)];
	bbb = y[xgap(obj)][ygap(obj)];
	if (aaa == x[4][0] - 1 && bbb == y[4][0] || aaa == x[4][0] && bbb == y[4][0] + 1 || aaa == x[4][0] + 1 && bbb == y[4][0] || aaa == x[4][0] && bbb == y[4][0] - 1)
		return 1;
	else
		return 0;
}
void game() {
	time = createTimer(20);
	showTimer(time);
	startTimer(time);
	hideObject(ori);
	hideObject(sb);
	showObject(rb);
	ans();
	for (int k = 0; k < 100000; k++) {
		int qq=rand() % 5, ww=rand() % 5;
		if(check(i[qq][ww])==1)
		change(i[qq][ww]);
	}
}
void timerCallback(TimerID timer) {
	if (timer == time) showMessage("시간이 지난것같아요 ~");
}
void mouseCallback(ObjectID obj, int xax, int yay, MouseAction act) {
	if (obj == eb)endGame();
	else if (obj == sb || obj == rb)game();
	else if (check(obj) == 1) { 
		change(obj);
		klk = 0;
		for (int xzx = 0; xzx < 5; xzx++) {
			for (int yzy = 0; yzy < 5; yzy++) {
				if (x[xzx][yzy] == xzx && y[xzx][yzy] == yzy)klk = klk + 1;
			}
		}
		if (klk == 25)win();
	}
	else if (obj == cau)win();
}
int main() {
	time = createTimer(9999);
	showObject(ori);
	sc = createScene("어려운게임", "\\images\\blank.png");
	setTimerCallback(timerCallback);
	setMouseCallback(mouseCallback);
	cau = mulchae("\\images\\cau.png", sc, 675, 350, true);
	l = mulchae("\\images\\left.png", sc, 0, 0, true);
	r = mulchae("\\images\\right.png", sc, 560, 0, true);
	sb = mulchae("\\images\\start.png", sc, 660, 10, true);
	eb = mulchae("\\images\\end.png", sc, 660, 50, true);
	rb = mulchae("\\images\\restart.png", sc, 660, 10, false);
	ori = mulchae("\\images\\mid.png", sc, 60, 0, true);
	showMessage("게임을 시작합니다. 중앙대학교를 찾아보세요 ~");
	startGame(sc);
}