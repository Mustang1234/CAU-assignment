#include<stdio.h>
#include<bangtal.h>
#include<windows.h>
int b, jk, x, y, joker[2] = { 0, }, player[8] = { 0, }, c[12][12] = { 0, }, st[10], nem[10] = { 0, }, nemm, nemmm, pan = 13, pann = 0, ai[8][10] = { 0, }, aiai[8][13] = { 0, };
SceneID sc;
ObjectID mulchae(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}
ObjectID obj, sb, rb, rbb, eeb, eb, cheat, startsc, gamesc, cardy[7], card[12][12], jocker[2], enter, pass, rules, click[10] = { 0, }, clickx[10] = { 0, }, xno[12] = { 0, }, pas[8] = { 0, };
void sleep(int tt) {
	int time = 0;
	for (int c = 0; c < tt; c++)for (int a = 0; a < 1111111; a++)
		if (time == 0)time++;
		else if (time == 1)time--;
}
void win() {
	if (player[0] == 0) {
		showObject(rbb);
		showMessage("Congratulations, You Won!!!");
	}
	else if (player[1] == 0) {
		showObject(rbb);
		showMessage("player1 Won, You Lose");
		hideObject(cardy[0]);
	}
	else if (player[2] == 0) {
		showObject(rbb);
		showMessage("player2 Won, You Lose");
		hideObject(cardy[1]);
	}
	else if (player[3] == 0) {
		showObject(rbb);
		showMessage("player3 Won, You Lose");
		hideObject(cardy[2]);
	}
	else if (player[4] == 0) {
		showObject(rbb);
		showMessage("player4 Won, You Lose");
		hideObject(cardy[3]);
	}
	else if (player[5] == 0) {
		showObject(rbb);
		showMessage("player5 Won, You Lose");
		hideObject(cardy[4]);
	}
	else if (player[6] == 0) {
		showObject(rbb);
		showMessage("player6 Won, You Lose");
		hideObject(cardy[5]);
	}
	else if (player[7] == 0) {
		showObject(rbb);
		showMessage("player7 Won, You Lose");
		hideObject(cardy[6]);
	}
}
void game() {
	int k, j, a = -1, deck = 0;
	b = 0; jk = 0;
	for (k = 0; k < 12; k++)
		for (j = 0; j <= k; j++)
			if ((c[k][j] % 100) / 10 == 0) {
				showObject(card[k][j]);
				locateObject(card[k][j], sc, 110 + 54 * deck, 60);
				c[k][j] = c[k][j] % 100 + 100 * deck;
				deck++;
			}
	for (k = 0; k < 2; k++)
		if ((joker[k] % 100) / 10 == 0) {
			showObject(jocker[k]);
			locateObject(jocker[k], sc, 110 + 54 * deck, 60);
			joker[k] = joker[k] % 100 + 10000 * (k + 1) + 100 * deck;
			deck++;
		}
	for (k = 0; k < 10; k++)if (obj == click[k] || obj == clickx[k])a = k;
	if (a >= 0) {
		for (k = 0; k < 12; k++)for (j = 0; j <= k; j++)if (c[k][j] / 100 == a && c[k][j] % 100 - c[k][j] % 10 == 0)b = 100 * k + j + 101;
		for (k = 0; k < 2; k++)if ((joker[k] % 10000) / 100 == a && joker[k] % 100 - joker[k] % 10 == 0)jk = 10000 * (k + 1);
		if (b != 0 && jk == 0)
			if (c[(b % 10000) / 100 - 1][b % 100 - 1] % 10 == 0) {
				c[(b % 10000) / 100 - 1][b % 100 - 1]++;
				hideObject(clickx[a]);
				showObject(click[a]);
				st[a] = b;
			}
			else if (c[(b % 10000) / 100 - 1][b % 100 - 1] % 10 == 1) {
				c[(b % 10000) / 100 - 1][b % 100 - 1]--;
				hideObject(click[a]);
				showObject(clickx[a]);
				st[a] = 0;
			}
		if (b == 0 && jk != 0)
			if (joker[(jk / 10000) - 1] % 10 == 0) {
				joker[(jk / 10000) - 1]++;
				hideObject(clickx[a]);
				showObject(click[a]);
				st[a] = jk;
			}
			else if (joker[(jk / 10000) - 1] % 10 == 1) {
				joker[(jk / 10000) - 1]--;
				hideObject(click[a]);
				showObject(clickx[a]);
				st[a] = 0;
			}
	}
	win();
}
void gameplay() {
	int k, j;
	for (k = 0; k < 12; k++)for (j = 0; j <= k; j++)if ((c[k][j] % 100) / 10 == 8)hideObject(card[k][j]);
	for (k = 0; k < nemmm; k++)
		if (nem[k] / 10000 != 0) {
			locateObject(jocker[nem[k] / 10000 - 1], sc, 325, 325);
			joker[nem[k] / 10000 - 1] = joker[nem[k] / 10000 - 1] - joker[nem[k] / 10000 - 1] % 100 + 80;
		}
		else {
			locateObject(card[nem[k] / 100 - 1][nem[k] % 100 - 1], sc, 325, 325);
			c[nem[k] / 100 - 1][nem[k] % 100 - 1] = c[nem[k] / 100 - 1][nem[k] % 100 - 1] - c[nem[k] / 100 - 1][nem[k] % 100 - 1] % 100 + 80;
		}
	for (k = 0; k < 12; k++) hideObject(xno[k]);
	showObject(xno[nemmm - 1]);
	player[0] = player[0] - nemmm;
	game();
}
void aigameplay(unsigned short int aip) {
	printf("\n\n\n\nIt's player%d's turn.\n", aip);
	int k, j, p, deck = 0, aic = 0, pa;
	for (k = 0; k < 8; k++)for (j = 0; j < 10; j++)ai[k][j] = 0;
	for (k = 0; k < 8; k++)for (j = 0; j < 13; j++)aiai[k][j] = 0;
	for (k = 0; k < 12; k++)for (j = 0; j <= k; j++)if ((c[k][j] % 100) / 10 == aip)
	{
		ai[aip][deck] = 100 * k + j;
		deck++;
	}
	for (k = 0; k < 2; k++)if ((joker[k] % 100) / 10 == aip)
	{
		ai[aip][deck] = 10000 * k + 10000;
		deck++;
	}
	for (k = 0; k < deck; k++)
		if (ai[aip][k] / 100 < 12 && ai[aip][k] / 100 < 100)aiai[aip][ai[aip][k] / 100]++;
		else if (ai[aip][k] / 100 >= 100)aiai[aip][12]++;
	if (pann % 10 == aip) {
		printf("my turn again\n");
		pann = 0;
		for (k = 11; k >= 0; k--)if (aiai[aip][k] > aic) aic = k;
		for (k = 0; k < 12; k++)for (j = 0; j <= k; j++)if ((c[k][j] % 100) / 10 == 8)hideObject(card[k][j]);
		sleep(500);
		for (k = 0; k < 12; k++) hideObject(xno[k]);
		for (k = 0; k < 10; k++)
			if (ai[aip][k] / 100 == aic) {
				showObject(card[ai[aip][k] / 100][ai[aip][k] % 100]);
				locateObject(card[ai[aip][k] / 100][ai[aip][k] % 100], sc, 325, 325);
				c[ai[aip][k] / 100][ai[aip][k] % 100] = 100 * (c[ai[aip][k] / 100][ai[aip][k] % 100] / 100) + 80;
				player[aip]--;
				pann++;
			}
		pan = aic + 1;
		if (aic != 0) {
			showObject(xno[pann - 1]);
			pann = pann * 10 + aip;
		}
		else if (aic == 0) {
			showObject(xno[0]);
			pann = 10 + aip;
		}
	}
	else if (pann % 10 != aip) {
		for (k = pan - 2; k >= -1; k--) {
			if (aiai[aip][k] >= pann / 10 && k >= 0) {
				pa = pann / 10;
				pann = 0;
				for (p = 0; p < 12; p++)for (j = 0; j <= p; j++)if ((c[p][j] % 100) / 10 == 8)hideObject(card[p][j]);
				for (p = 0; p < 12; p++) hideObject(xno[p]);
				for (j = 0; j < 10; j++)
					if (ai[aip][j] / 100 == k && pann < pa) {
						showObject(card[ai[aip][j] / 100][ai[aip][j] % 100]);
						locateObject(card[ai[aip][j] / 100][ai[aip][j] % 100], sc, 325, 325);
						c[ai[aip][j] / 100][ai[aip][j] % 100] = 100 * (c[ai[aip][j] / 100][ai[aip][j] % 100] / 100) + 80;
						player[aip]--;
						pann++;
						pan = 1 + ai[aip][j] / 100;
					}
				if (k != 0) {
					showObject(xno[pann - 1]);
					pann = pann * 10 + aip;
				}
				else if (k == 0) {
					showObject(xno[0]);
					pann = 10 + aip;
				}
				break;
			}
			if (k == -1) {
				showObject(pas[aip]);
				sleep(500);
				hideObject(pas[aip]);
				printf("\nplayer%d passed\n", aip);
				if (aip == 1)showMessage("player1 passed");
				else if (aip == 2)showMessage("player2 passed");
				else if (aip == 3)showMessage("player3 passed");
				else if (aip == 4)showMessage("player4 passed");
				else if (aip == 5)showMessage("player5 passed");
				else if (aip == 6)showMessage("player6 passed");
				else if (aip == 7)showMessage("player7 passed");
				break;
			}
		}
	}
	printf("\ncard%d  X %d on board and it's from %d\n", pan, pann / 10, pann % 10);
	win();
}
void playai() {
	int k;
	for (k = 1; k < 8; k++) {
		sleep(500);
		aigameplay(k);
		sleep(500);
	}
	if (pann % 10 != 0)showMessage("It's your turn.");
	else if (pann % 10 == 0)showMessage("It's your turn again.");
}
void setup() {
	hideObject(startsc);
	showObject(gamesc);
	for (int a = 0; a < 7; a++)showObject(cardy[a]);
	for (int a = 0; a < 10; a++) {
		hideObject(click[a]);
		showObject(clickx[a]);
	}
	for (int a = 0; a < 12; a++)hideObject(xno[a]);
	hideObject(sb);
	hideObject(rbb);
	showObject(eb);
	showObject(rb);
	showObject(enter);
	showObject(pass);
	showObject(rules);
	showObject(cheat);
	pan = 0; pann = 0;
	int k, j, r;
	for (k = 0; k < 2; k++)joker[k] = 10000 * (k + 1);
	for (k = 0; k < 8; k++)player[k] = 0;
	for (k = 0; k < 12; k++)for (j = 0; j < 12; j++)c[k][j] = 0;
	for (k = 0; k < 2; k++) {
		hideObject(jocker[k]);
		r = (rand() + x) % 8;
		joker[k] += r * 10;
		player[r] ++;
	}
	for (k = 0; k < 12; k++) {
		for (j = 0; j <= k; j++) {
			hideObject(card[k][j]);
			r = (rand() + x) % 8;
			if (player[r] < 10) {
				c[k][j] += r * 10;
				player[r] ++;
			}
			else if (player[r] >= 10) j--;
		}
	}
}
void mouseCallback(ObjectID objj, int xx, int yy, MouseAction act) {
	int k, j;
	x = xx; y = yy; obj = objj;
	if (obj == eb || obj == eeb)endGame();
	else if (obj == cheat) {
		player[0] = 0;
		win();
	}
	else if (obj == sb || obj == rb || obj == rbb) {
		setup();
		showMessage("GAME START    *console important*");
		game();
	}
	for (k = 0; k < 10; k++)if (obj == click[k] || obj == clickx[k])game();
	if (obj == rules) {
		showMessage("Rules : The numbers on the cards are its rank. Choose cards with same rank. Then first round goes. When your turn comes again, you can either play the same number of cards but lower in rank than the former played, or pass. Once everyone has passed, the round is finished. The last player is then able to play a set of cards to start another round. If one has no card, that's the winner. Good luck."); 
	}
	else if (obj == enter) {
		for (k = 0; k < 12; k++)for (j = 0; j <= k; j++)if (c[k][j] % 10 == 1)c[k][j]--;
		for (k = 0; k < 2; k++)if (joker[k] % 10 == 1)joker[k]--;
		for (k = 0; k < 10; k++) {
			hideObject(click[k]);
			showObject(clickx[k]);
		}
		nemm = 0;
		nemmm = 0;
		for (k = 0; k < 10; k++)
			if (st[k] != 0) {
				nem[nemm] = st[k];
				nemm++;
			}
		for (k = 0; k < nemm - 1; k++)
			if (nem[k] / 10000 != 0 || nem[k + 1] / 10000 != 0)nemmm++;
			else if (nem[k] / 100 == nem[k + 1] / 100)nemmm++; nemmm++;
		if (nemmm == nemm) {
			if (pann % 10 == 0) {
				if (nem[0] / 10000 == 0)pan = nem[0] / 100;
				else if (nem[0] / 10000 != 0)pan = 13;
				pann = nemmm * 10;
				gameplay();
				sleep(500);
				playai();
			}
			else if (nemmm == pann / 10 && nem[0] / 100 < pan) {
				pan = nem[0] / 100;
				pann = pann - pann % 10;
				gameplay();
				sleep(500);
				playai();
			}
			else showMessage("Choose Your Card Following Rules!!!");
			game();
		}
		else showMessage("Choose Your Card Following Rules!!!");
		for (k = 0; k < 10; k++) {
			st[k] = 0;
			nem[k] = 0;
		}
		game();
	}
	else if (obj == pass) {
		showObject(pas[0]);
		sleep(500);
		hideObject(pas[0]);
		sleep(500);
		playai();
		game();
	}
}
int main() {
	setMouseCallback(mouseCallback);
	int a = 0;
	sc = createScene("카우점프", "\\images\\sc.png");
	startsc = mulchae("\\images\\startsc.png", sc, 0, 0, true);
	gamesc = mulchae("\\images\\gamesc.png", sc, 0, 0, false);
	enter = mulchae("\\images\\enter.png", sc, 653, 75, false);
	pass = mulchae("\\images\\pass.png", sc, 696, 75, false);
	rules = mulchae("\\images\\rules.png", sc, 50, 75, false);
	sb = mulchae("\\images\\start.png", sc, 349, 30, true);
	rb = mulchae("\\images\\restart.png", sc, 339, 30, false);
	eeb = mulchae("\\images\\end.png", sc, 357, 10, true);
	eb = mulchae("\\images\\end1.png", sc, 357, 10, false);
	jocker[0] = mulchae("\\images\\joker.png", sc, 0, 0, false);
	jocker[1] = mulchae("\\images\\joker.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[0][a] = mulchae("\\images\\card1.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[1][a] = mulchae("\\images\\card2.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[2][a] = mulchae("\\images\\card3.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[3][a] = mulchae("\\images\\card4.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[4][a] = mulchae("\\images\\card5.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[5][a] = mulchae("\\images\\card6.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[6][a] = mulchae("\\images\\card7.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[7][a] = mulchae("\\images\\card8.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[8][a] = mulchae("\\images\\card9.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[9][a] = mulchae("\\images\\card10.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[10][a] = mulchae("\\images\\card11.png", sc, 0, 0, false);
	for (a = 0; a < 12; a++)card[11][a] = mulchae("\\images\\card12.png", sc, 0, 0, false);
	for (a = 0; a < 10; a++)click[a] = mulchae("\\images\\click.png", sc, 110 + 54 * a, 160, false);
	for (a = 0; a < 10; a++)clickx[a] = mulchae("\\images\\clickx.png", sc, 110 + 54 * a, 160, false);
	cardy[0] = mulchae("\\images\\card.png", sc, 60, 210, false);
	cardy[1] = mulchae("\\images\\card.png", sc, 60, 335, false);
	cardy[2] = mulchae("\\images\\card.png", sc, 60, 460, false);
	cardy[3] = mulchae("\\images\\card.png", sc, 353, 610, false);
	cardy[4] = mulchae("\\images\\card.png", sc, 646, 460, false);
	cardy[5] = mulchae("\\images\\card.png", sc, 646, 335, false);
	cardy[6] = mulchae("\\images\\card.png", sc, 646, 210, false);
	xno[0] = mulchae("\\images\\x1.png", sc, 375, 300, false);
	xno[1] = mulchae("\\images\\x2.png", sc, 375, 300, false);
	xno[2] = mulchae("\\images\\x3.png", sc, 375, 300, false);
	xno[3] = mulchae("\\images\\x4.png", sc, 375, 300, false);
	xno[4] = mulchae("\\images\\x5.png", sc, 375, 300, false);
	xno[5] = mulchae("\\images\\x6.png", sc, 375, 300, false);
	xno[6] = mulchae("\\images\\x7.png", sc, 375, 300, false);
	xno[7] = mulchae("\\images\\x8.png", sc, 375, 300, false);
	xno[8] = mulchae("\\images\\x9.png", sc, 375, 300, false);
	xno[9] = mulchae("\\images\\x10.png", sc, 375, 300, false);
	xno[10] = mulchae("\\images\\x11.png", sc, 375, 300, false);
	xno[11] = mulchae("\\images\\x12.png", sc, 375, 300, false);
	pas[0] = mulchae("\\images\\aipass.png", sc, 350, 190, false);
	pas[1] = mulchae("\\images\\aipass.png", sc, 125, 225, false);
	pas[2] = mulchae("\\images\\aipass.png", sc, 125, 350, false);
	pas[3] = mulchae("\\images\\aipass.png", sc, 125, 475, false);
	pas[4] = mulchae("\\images\\aipass.png", sc, 350, 544, false);
	pas[5] = mulchae("\\images\\aipass.png", sc, 580, 225, false);
	pas[6] = mulchae("\\images\\aipass.png", sc, 580, 350, false);
	pas[7] = mulchae("\\images\\aipass.png", sc, 580, 475, false);
	rbb = mulchae("\\images\\restartt.png", sc, 0, 0, false);
	cheat = mulchae("\\images\\cheat.png", sc, 0, 0, false);
	startGame(sc);
}