#include <iostream>
#include <time.h>
#include <conio.h>//입력 받은 문자를 바로바로 실행해주게 하는 헤더파일(q를 입력하고 엔터를 치지 않아도 바로 행동에 맞게 실행)
using namespace std;
/*
숫자 빙고 게임
1~25까지의 숫자가 있고 이 숫자를 골고루 섞어서 5*5로 출력
플레이어는 수사를 입력받는다. 1~25 사이의 숫자를 입력받아야 한다.

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

		//퍼즐이 맞추어졌는지 확인한다
		for (int i = 0; i < 24; i++) {
			if (NumberPuzzle[i] != i + 1) {
				run = false;
				break;
			}
		}

		if (run == true) {
			cout << "축하합니다! 모든 숫자를 정렬하였습니다" << endl;
			break;
		}

		cout << "w = 위, s = 아래, a = 왼쪽, d = 오른쪽, q = 종료 : ";

		//_getch : 입력 받은 문자를 바로바로 실행해주게 함(q를 입력하고 엔터를 치지 않아도 문자를 누르는 순간 반환하고 종료)
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			cout << endl << "종료하셨습니다." << endl;
			break;
		}

		switch (cInput) {
		case 'w' :
		case 'W' :
			/*내가 짠 코드
			//만약 Star_Index가 0보다 작거나 24보다 크면 좌표 값을 넘어감으로 0~24의 사이에서만 동작하게 함
			if (0 > Star_Index-5 || Star_Index-5 > 24)
				break;
			else {
				Temp = NumberPuzzle[Star_Index];
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index - 5];
				NumberPuzzle[Star_Index - 5] = Temp;
				Star_Index -= 5;
			}
			*/

			//가장 윗줄일 때는 w를 눌러도 위로 올라가서는 안된다
			if (Star_Index > 4) {
				//별이 있는 위치에 바로 위에 있는 값(좌표로는 -5)을 넣어준다.
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index - 5];
				//위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다
				NumberPuzzle[Star_Index - 5] = INT_MAX;
				//별이 한칸 이동했으므로 한칸 위의 인덱스를 Star_Index로 저장한다.
				Star_Index -= 5;
			}
			break;
		case 's':
		case 'S':
			//가장 윗줄일 때는 w를 눌러도 위로 올라가서는 안된다
			if (Star_Index < 20) {
				//별이 있는 위치에 바로 위에 있는 값(좌표로는 -5)을 넣어준다.
				NumberPuzzle[Star_Index] = NumberPuzzle[Star_Index + 5];
				//위의 위치에 별을 넣어주어서 2개의 값을 서로 교체한다
				NumberPuzzle[Star_Index + 5] = INT_MAX;
				//별이 한칸 이동했으므로 한칸 위의 인덱스를 Star_Index로 저장한다.
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
			//나머지가 4일 때 못 움직이게 함
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


