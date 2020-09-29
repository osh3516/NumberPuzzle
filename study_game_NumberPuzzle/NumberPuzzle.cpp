#include <iostream>
#include <time.h>
#include <conio.h>//�Է� ���� ���ڸ� �ٷιٷ� �������ְ� �ϴ� �������(q�� �Է��ϰ� ���͸� ġ�� �ʾƵ� �ٷ� �ൿ�� �°� ����)
using namespace std;
/*
���� ���� ����
1~25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5*5�� ���
�÷��̾�� ���縦 �Է¹޴´�. 1~25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.

*/

int main() {
	srand((unsigned int)time(0));

	int NumberPuzzle[25];
	int Temp, Index1, Index2;
	int Star_Index = 24;
	bool run = true;

	for (int i = 0; i < 24; i++) {
		NumberPuzzle[i] = i + 1;
		NumberPuzzle[24] = INT_MAX;
	}
	
	for (int i = 0; i < 100; i++) {
		Index1 = rand() % 24;
		Index2 = rand() % 24;

		Temp = NumberPuzzle[Index1];
		NumberPuzzle[Index1] = NumberPuzzle[Index2];
		NumberPuzzle[Index2] = Temp;
	}

	while (1) {
		system("cls");

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (NumberPuzzle[i * 5 + j] == INT_MAX) 
					cout << "*"<< '\t';
				else
				cout << NumberPuzzle[i * 5 + j] << '\t';
			}
			cout << "" << endl;
		}

		//������ ���߾������� Ȯ���Ѵ�
		for (int i = 0; i < 24; i++) {
			if (NumberPuzzle[i] != i + 1) {
				run = false;
				break;
			}
		}

		if (run == true) {
			cout << "�����մϴ�! ��� ���ڸ� �����Ͽ����ϴ�" << endl;
			break;
		}

		cout << "w = ��, s = �Ʒ�, a = ����, d = ������, q = ���� : ";

		//_getch : �Է� ���� ���ڸ� �ٷιٷ� �������ְ� ��(q�� �Է��ϰ� ���͸� ġ�� �ʾƵ� ���ڸ� ������ ���� ��ȯ�ϰ� ����)
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			cout << endl << "�����ϼ̽��ϴ�." << endl;
			break;
		}

		switch (cInput) {
		case 'w' :
		case 'W' :
			/*���� § �ڵ�
			//���� Star_Index�� 0���� �۰ų� 24���� ũ�� ��ǥ ���� �Ѿ���� 0~24�� ���̿����� �����ϰ� ��
			if (0 > Star_Index-5 || Star_Index-5 > 24)
				break;
			else {
				Temp = NumberPuzzle[Star_Index];
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index - 5];
				NumberPuzzle[Star_Index - 5] = Temp;
				Star_Index -= 5;
			}
			*/

			//���� ������ ���� w�� ������ ���� �ö󰡼��� �ȵȴ�
			if (Star_Index > 4) {
				//���� �ִ� ��ġ�� �ٷ� ���� �ִ� ��(��ǥ�δ� -5)�� �־��ش�.
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index - 5];
				//���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�
				NumberPuzzle[Star_Index - 5] = INT_MAX;
				//���� ��ĭ �̵������Ƿ� ��ĭ ���� �ε����� Star_Index�� �����Ѵ�.
				Star_Index -= 5;
			}
			break;
		case 's':
		case 'S':
			//���� ������ ���� w�� ������ ���� �ö󰡼��� �ȵȴ�
			if (Star_Index < 20) {
				//���� �ִ� ��ġ�� �ٷ� ���� �ִ� ��(��ǥ�δ� -5)�� �־��ش�.
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index + 5];
				//���� ��ġ�� ���� �־��־ 2���� ���� ���� ��ü�Ѵ�
				NumberPuzzle[Star_Index + 5] = INT_MAX;
				//���� ��ĭ �̵������Ƿ� ��ĭ ���� �ε����� Star_Index�� �����Ѵ�.
				Star_Index += 5;
			}
			break;
		case 'a':
		case 'A':
			if (Star_Index%5==0)
				break;
			else {
				Temp = NumberPuzzle[Star_Index];
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index -1];
				NumberPuzzle[Star_Index -1] = Temp;
				Star_Index -=1;
			}
			break;
		case 'd':
		case 'D':
			//�������� 4�� �� �� �����̰� ��
			if (Star_Index % 5 == 4)
				break;
			else {
				Temp = NumberPuzzle[Star_Index];
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index + 1];
				NumberPuzzle[Star_Index + 1] = Temp;
				Star_Index += 1;
			}
			break;
		}
	}
}


