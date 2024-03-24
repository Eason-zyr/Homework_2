//randomized challenge-response �t��
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

void random(int num[]);                             //�H���ͦ��Ʀr
void input(int pin,const int num[]);                //�ϥΪ̿�J
int compare(int pin, const int num[], int nput);    //�T�{�K�X�O�_���T

int main(void) {
	int pin = 12345;                                //���T�K�X
	int num[10];                                    //�H���Ʀr�}�C
	srand(time(NULL));                              //�ϨC���H�����G���P
	random(num);                                    //�i���H��
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;     //��X���G�ܿù�
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		if (i < 9) {
			cout << num[i] << " ";
		}
		else {
			cout << num[i] << endl;
		}
	}
	input(pin, num);                     //�ϥΪ̿�J

	system("pause");
	return(0);
}

void random(int num[]) {                 //�H��10��1~3���Ʀr����0~9
	for (int i = 0; i < 10; i++) {
		num[i] = (rand() % 3) + 1;
	}
}

void input(int pin,const int num[]) {    //��J������NUM������Ʀr��K�X
	int input;
	cout << "Use the above NUM to enter your password (five digits) >> ";
	cin >> input;
	if (compare(pin, num, input)) {      //�i����&��ܵ��G
		cout << "Correct input." << endl;
	}
	else {
		cout << "Wrong input." << endl;
	}
}

int compare(int pin, const int num[], int input) {    //����J�O�_�����T�K�X
	int count = 0;                                    //���T��ƭp�ƾ�
	for (int i = 4; i >= 0; i--) {                    //��ƶi��@�@���
		for (int j = 0; j < 10; j++) {
			if ((input / int(pow(10, i)))%10 == num[j] && j == int((pin / pow(10, i)))%10) {
				count++;
				break;
			}
		}
	}
	if (count == 5) {                                 //�C��ҥ��T�h�^��true,�_�hfalse
		return(1);
	}
	else {
		return(0);
	}
}