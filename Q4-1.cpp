//24�ɨ���12�ɨ�u��
#include<iostream>
using namespace std;

void Input_time(void);                               //��J�ɶ�
void conversion(char AM, int hours, int minutes);    //�ɶ��ഫ(A.M.)
void conversion(int hours, int minutes, char PM);    //�ɶ��ഫ(P.M.)
void output_time(int hours, int minutes, char time);    //��X�ɶ�

int main(void) {
	char again;          //�Ω�T�{�O�_�A�Ӥ@�M
	do {
		Input_time();    //�I�s�禡��J
		cout << "Do you want to input again? Input Y or y(Yes), or N or n(No) >> ";    //�T�{�O�_�A������
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');            //Yes�h�A�Ӥ@��
	cout << "The procedure is terminated." << endl;    //��X�����T��
	system("pause");
	return(0);
}

void Input_time(void) {
	int hours, minutes;                              //�X�I,�X��
	char time;                                       //AM�٬OPM
	cout << "Iuput time (hours and minutes) >> ";    //��J�ɶ�
	cin >> hours >> minutes;
	if (hours <= 12) {                               //�P�wAM��PM,�I�s�ഫ
		time = 'A';
		conversion(time, hours, minutes);
	}
	else {
		time = 'P';
		conversion(hours, minutes, time);
	}
}

void conversion(char AM, int hours, int minutes) {    //AM�i������X
	output_time(hours, minutes, AM);
}

void conversion(int hours, int minutes, char PM) {    //PM��12�p��
	hours -= 12;
	output_time(hours, minutes, PM);
}

void output_time(int hours, int minutes, char time) {    //�P�_AM��PM�ӿ�X�T��
	if (time == 'A') {
		cout << "It is " << hours << ":" << minutes << " A.M. now." << endl;
	}
	if (time == 'P') {
		cout << "It is " << hours << ":" << minutes << " P.M. now." << endl;
	}
}