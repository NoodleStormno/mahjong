#include<iostream>
using namespace std;
//�����ж�������Ҳ��֪��ΪʲôҪ�ʹ��ӷֿ�����
void judge(int *pai,int *mianzi,int *dazi,int *duizi){
    int m=0;
    int d=0;
    int q=0;
    for (int i = 0; i < 7; i++) {
		if (pai[i] > 0 && pai[i + 1] > 0 && pai[i + 2] > 0) {
			m++;
			pai[i]--;
			pai[i + 1]--;
			pai[i + 2]--;//˳��
		}

	}
	for(int i=0;i<9;i++){
        if (pai[i] >= 3) {
			m++;
			pai[i] = pai[i] - 3;//����
		}
	}
    *mianzi=m+*mianzi;
    *dazi=d+*dazi;
    *duizi=q+*duizi;//ָ�봫ֵ
}
//�����ж�����û����
void judge_dazi(int *pai,int *mianzi,int *dazi,int *duizi){
    int m=0;
    int d=0;
    int q=0;
    for (int i = 0; i < 8; i++) {
		if (pai[i] > 0 && pai[i + 1] > 0) {
			d++;
			pai[i]--;
			pai[i + 1]--;//����1
		}
	}
	for (int i = 0; i < 9; i++) {
		if (pai[i] == 2) {
			d++;
			q++;
			pai[i] = pai[i] - 2;//���ӣ�ȸͷ
		}
	}
	for (int i = 0; i < 7; i++) {
		if (pai[i] > 0 && pai[i + 2] > 0) {
			d++;
			pai[i]--;
			pai[i + 2]--;//����2
		}
	}
	*mianzi=m+*mianzi;
    *dazi=d+*dazi;
    *duizi=q+*duizi;//ָ�봫ֵ
}
//Ҫ�õĻ�ֱ�ӵ������������
int xiangtin(char *cards){
    int x,m;
    int d=0;
    int q=0;
    int wan[9],suo[9],tong[9],zi[9];
    int middle[9]={0,0,0,0,0,0,0,0,0};//��֪��Ϊʲô������ͻ������
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
   //�ҰѴ����Ƶĺ����Ž�������



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
   //���������һ�Σ�û����


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
    //�ж������һ�����е�mdq��m��q���������ʹ��ӻᱬը
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
    if(m+d<=5) x=8-2*m-d;//��ʽ���������
    else {
        x=4-m;
        if(q>0) x--;
    }
    return x;
}
//������������ʱ��ŵ�����ļ���ȥ��
int main(){
    char cards[18];
    int get_keyboard=999;
    while(get_keyboard!=0){
        cin>>get_keyboard;

        if(get_keyboard==1) {
            cout<<"please input your cards"<<'\n';
            for(int i=0;i<17;i++)
            cin>>cards[i];//���뿨
            cout<<"�⸱��"<<xiangtin(cards)<<"����"<<'\n';
        }
    else break;
    }

}
