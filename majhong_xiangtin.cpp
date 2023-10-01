#include<iostream>
using namespace std;
//面子判断喵，我也不知道为什么要和搭子分开来喵
void judge(int *pai,int *mianzi,int *dazi,int *duizi){
    int m=0;
    int d=0;
    int q=0;
    for (int i = 0; i < 7; i++) {
		if (pai[i] > 0 && pai[i + 1] > 0 && pai[i + 2] > 0) {
			m++;
			pai[i]--;
			pai[i + 1]--;
			pai[i + 2]--;//顺子
		}

	}
	for(int i=0;i<9;i++){
        if (pai[i] >= 3) {
			m++;
			pai[i] = pai[i] - 3;//刻子
		}
	}
    *mianzi=m+*mianzi;
    *dazi=d+*dazi;
    *duizi=q+*duizi;//指针传值
}
//搭子判断喵，没了喵
void judge_dazi(int *pai,int *mianzi,int *dazi,int *duizi){
    int m=0;
    int d=0;
    int q=0;
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
	*mianzi=m+*mianzi;
    *dazi=d+*dazi;
    *duizi=q+*duizi;//指针传值
}
//要用的话直接调用这个函数喵
int xiangtin(char *cards){
    int x,m;
    int d=0;
    int q=0;
    int wan[9],suo[9],tong[9],zi[9];
    int middle[9]={0,0,0,0,0,0,0,0,0};//不知道为什么不置零就会出问题
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
   //我把存入牌的函数放进来了喵



	for(int i=0;i<9;i++){
        cout<<wan[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<suo[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<tong[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<zi[i];
	}
	cout<<'\n';
   //存入完输出一次，没问题


    judge(wan,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    judge(suo,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    judge(tong,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    judge_dazi(wan,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    judge_dazi(suo,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    judge_dazi(tong,&m,&d,&q);
    cout<<m<<' '<<d<<' '<<q<<'\n';
    //判断完输出一次现有的mdq，m和q都正常，就搭子会爆炸
    for(int i=0;i<9;i++){
        if(zi[i]>=3){
            m++;
            zi[i]=zi[i]-3;
        }
        else if(zi[i]==2){
            d++;q++;
            zi[i]=zi[i]-2;
        }
    }
    for(int i=0;i<9;i++){
        cout<<wan[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<suo[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<tong[i];
	}
	cout<<'\n';
	for(int i=0;i<9;i++){
        cout<<zi[i];
	}
	cout<<'\n';
    cout<<m<<' '<<d<<' '<<q<<'\n';
    if(m+d<=5) x=8-2*m-d;//公式就是这段喵
    else {
        x=4-m;
        if(q>0) x--;
    }
    return x;
}
//主函数喵，到时候放到别的文件里去喵
int main(){
    char cards[18];
    int get_keyboard=999;
    while(get_keyboard!=0){
        cin>>get_keyboard;

        if(get_keyboard==1) {
            cout<<"please input your cards"<<'\n';
            for(int i=0;i<17;i++)
            cin>>cards[i];//存入卡
            cout<<"这副牌"<<xiangtin(cards)<<"向听"<<'\n';
        }
    else break;
    }

}
