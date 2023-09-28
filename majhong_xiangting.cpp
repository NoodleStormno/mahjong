#include <iostream>
using namespace std;
char cards[17];
int x, m, d, c, q;
int wan[9], suo[9], tong[9], zi[9], middle[9];
int temp;


void judge(int pai[9]) {
	for (int i = 0; i < 9; i++) {
		if (pai[i] > 0 && pai[i + 1] > 0 && pai[i + 2] > 0) {
			m++;
			pai[i]--;
			pai[i + 1]--;
			pai[i + 2]--;//顺子
		}
		if (pai[i] >= 3) {
			m++;
			pai[i] = pai[i] - 3;//刻子
		}
	}
	for (int i = 0; i < 8; i++) {
		if (pai[i] > 0 && pai[i + 1] > 0) {
			d++;
			pai[i]--;
			pai[i + 1]--;//搭子1
		}
	}
	for (int i = 0; i < 9; i++) {
		if (pai[i] == 2) {
			d++;
			q++;
			pai[i] = pai[i] - 2;//对子，雀头
		}
	}
	for (int i = 0; i < 7; i++) {
		if (pai[i] > 0 && pai[i + 2] > 0) {
			d++;
			pai[i]--;
			pai[i + 2]--;//搭子2
		}
	}
}//估计是数组超界的问题。

void bubble_sort() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j <= 16 - i; j++) {
			if (cards[j] == 'm' || cards[j] == 'p' || cards[j] == 's' || cards[j] == 'z')
				continue;
			else if (cards[j] > cards[j + 1]) {
				temp = cards[j];
				cards[j] = cards[j + 1];
				cards[j + 1] = temp;
			}
		}
	}
}//冒泡排序，免得某些傻逼乱输入.

void sort() {
	for (int i = 0; i < 17; i++) {

		if (cards[i] == 'm') {
			for (int j = 0; j < 9; j++) {
				wan[j] = middle[j];
				middle[j] = 0;
			}
			continue;
		}
		if (cards[i] == 'p') {
			for (int j = 0; j < 9; j++) {
				tong[j] = middle[j];
				middle[j] = 0;
			}
			continue;
		}
		if (cards[i] == 's') {
			for (int j = 0; j < 9; j++) {
				suo[j] = middle[j];
				middle[j] = 0;
			}
			continue;
		}
		if (cards[i] == 'z') {
			for (int j = 0; j < 9; j++) {
				zi[j] = middle[j];
				middle[j] = 0;
			}
			continue;
		}
		middle[cards[i] - '1']++;
	}
}//各个牌有几张

int main() {
	cout << "mpsz" << '\n';
	for (int i = 0; i < 17; i++) {
		cin >> cards[i];
	}
	//bubble_sort();
	sort();
	//存入没问题
	judge(wan);
	judge(suo);
	judge(tong);

	for (int i = 0; i < 9; i++) {

		if (zi[i] >= 3) {
			m++;
			zi[i] = zi[i] - 3;//字刻子
		}
		if (zi[i] == 2) {
			d++;
			q++;
			zi[i] = zi[i] - 2;//字对子，雀头
		}
	}

	c = m + d - 5;
	if (c <= 0)
		c = 0;
	if (m + d <= 4)
		q = 1;
	else {
		if (q >= 1)
			q = 1;
		else
			q = 0;
	}


	x = 9 - 2 * m - d + c - q;//主要计算公式


	cout << '\n' << x << '\n';

	return 0;
}
//然后再写一个牌效
//然后随机生成牌，然后做题咯。