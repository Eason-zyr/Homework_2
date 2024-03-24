//�q�v����&�������
#include<iostream>
#include<cmath>
using namespace std;
const int Movies_Num = 6;    //�q�v�ƶq
const int Reviewers = 4;     //�v���ƶq

int compare(int reviews[][Movies_Num], int movies[3], int score[3]);                          //����P�ֳ̬ۦ�
double cal_distance(int reviews[][Movies_Num], int movies[3], int score[3], int reviewer);    //�p��t����

int main(void) {
	int closest;                                             //�̱����
	int movies[3], score[3];                                 //������3���q�v�M����
	int reviews[Reviewers][Movies_Num] = { {3,1,5,2,1,5},    //�v���P�q�v���������
										   {4,2,1,4,2,4},
										   {3,1,2,4,4,1},
										   {5,1,4,2,4,2} };
	bool error;                                              //��J�O�_���~
	cout << "Movie numbers 100~105 ,ratings 1~5." << endl;
	cout << "Giving three movies and ratings (example. 102 5) >> ";
	do {
		error = false;
		for (int i = 0; i < 3; i++) {                                                              //��J3���q�v�ε���
			cin >> movies[i] >> score[i];
			if (!(movies[i] >= 100 && movies[i] <= 105) || !(score[i] >= 1 && score[i] <= 5)) {    //�˴���J�O�_���T
				error = true;
				cout << "Input error ,please input again!" << endl;
			}
		}
		if (movies[0] == movies[1] || movies[0] == movies[2] || movies[1] == movies[2]) {          //�˴��O�_���ƿ�J
			error = true;
			cout << "Duplicate input ,please input again!" << endl;
		}
	} while (error);
	closest = compare(reviews, movies, score);                                                     //�I�s�禡�i����
	cout << "The closest match of your ratings is reviewer " << closest << endl;                   //��ܵ��G
	for (int i = 0; i < Movies_Num; i++) {                                                         //������l�q�v�ϥΪ̥i��|��������
		if (i + 100 != movies[0] &&
			i + 100 != movies[1] &&
			i + 100 != movies[2]) {
			cout << "You may give rating " << reviews[closest][i] << " to movie " << i + 100 << endl;
		}
	}
	system("pause");
	return(0);
}

int compare(int reviews[][Movies_Num], int movies[3], int score[3]) {    //���̱���֪�����
	int closest = 0;                                                     //�w�]�̱���0��
	double distance[Reviewers];                                          //�M�C�쪺�t����
	for (int i = 0; i < Reviewers; i++) {
		distance[i] = cal_distance(reviews, movies, score, i);           //�I�s�禡�i��p��
	}
	for (int i = 1; i < Reviewers; i++) {
		if (distance[i] < distance[closest]) {                           //�@�@���
			closest = i;
		}
	}
	return(closest);                                                     //�^�ǳ̱����
}

double cal_distance(int reviews[][Movies_Num], int movies[3], int score[3], int reviewer) {    //�p��t����
	double distance = 0;                                                                       //�t����
	for (int i = 0; i < 3; i++) {
		distance += pow((score[i] - reviews[reviewer][movies[i] - 100]), 2);                   //�t���Ȥ����B�J1
	}
	return(sqrt(distance));                                                                    //�B�J2&�^��
}
