//���Ƥ����έp
#include<iostream>
using namespace std;

int main(void) {
	int students;                     //�ǥͼƶq
	int student[100];                 //�̦h100�Ӿǥ�
	int grades[6];                    //���Z�έp
	
	for (int i = 0; i < 6; i++) {     //��l�ư}�C��0
		grades[i] = 0;
	}
	
	cout << "How many students? ";    //���h�־ǥ�
	cin >> students;
	cout << "Input the grade of each student >> ";    
	for (int i = 0; i < students; i++) {             
		cin >> student[i];                           //��J�C��ǥͦ��Z
		grades[student[i]]++;                        //�P�ɲέp�ƶq
	}
	cout << endl;

	for (int i = 0; i < 6; i++) {                    //��X�έp���G
		cout << grades[i] << " grade(s) of " << i << endl;
	}

	system("pause");
	return(0);
}