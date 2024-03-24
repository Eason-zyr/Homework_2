//mph�禡&����
#include<iostream>
using namespace std;

double convertToMPH(int minutes, int seconds);    //�γt�v�ഫ
double convertToMPH(double kph);                  //�Τ����p���ഫ

int main(void) {
	int minutes, seconds;    //�X��,�X��
	double kph, mph;         //�����p��,�^���p��
	char again;              //�T�{�O�_�A������
	
	cout << "Testing 1" << endl;
	do {
		cout << "Input your pace (minutes and seconds per mile, Ex. 5 30) >> ";    //��J�X���X��@�^��
		cin >> minutes >> seconds;
		mph = convertToMPH(minutes, seconds);                                      //�Ĥ@���禡����
		cout << "Your mph (miles per hour) is " << mph << endl;                    //���յ��G
		cout << "Test again? (y or n) >> ";                                        //�O�_�A������
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');
	
	cout << "Testing 2" << endl;
	do {
		cout << "Input your kph (kilometers per hours) >> ";    //��J�����p��
		cin >> kph;
		mph = convertToMPH(kph);                                //�ĤG���禡����
		cout << "Your mph is " << mph << endl;                  //���յ��G
		cout << "Test again? (y or n) >> ";                     //�O�_�A������
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');
	
	cout << "Testing terminated." << endl;                      //���յ���
	system("pause");
	return(0);
}

double convertToMPH(int minutes, int seconds) {
	double mph;
	mph = 3600 / (double(minutes) * 60 + double(seconds));      //mph�p�⦡
	return(mph);
}

double convertToMPH(double kph) {
	double mph;
	mph = kph / 1.61;                                           //mph�p�⦡
	return(mph);
}