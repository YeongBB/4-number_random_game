#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
using namespace std;

void ru(int* num)						// 랜덤 숫자 4개 설정
{

	srand(time(NULL));
	for (int a = 0; a < 4; a++)
	{
		num[a] = rand() % 10;
		for (int g = 0; g < a; g++)		// 숫자가 같은것이 있는지 체크
			if (num[g] == num[a])		// 있다면 a = a-1
				a--;
	}
}
void str(int* inum)
{
	string input;							// 입력 변수
	int check = 0;							// 중복 판단
	int num = 0;							// 문자 -> 정수 변환때 필요
	while (1)
	{
		check = 0;
		cout << " 숫자 4개를 입력해 주세요. (중복 X)\n 입력:";
		cin >> input;

		if (isdigit(input[0]) && isdigit(input[1]) && isdigit(input[2]) && isdigit(input[3]) && input.size() == 4)
		{	// 입력한 값이 모두 정수인지 체크, 입력한 값의 크기가 4인지 체크
			num = stoi(input);

			for (int t = 3; t > -1; t--)		// 입력한 4자리 숫자를 각각의 자릿수로 쪼개어 저장
			{
				inum[t] = num % 10;
				num /= 10;
			}

			for (int i = 0; i < 4; i++)			// 입력값 중에서 같은 숫자가 있는지 검사
			{
				for (int j = 0; j < i; j++)
					if (inum[j] == inum[i])		// 있다면 check++
						check++;
			}
			if (check == 0)						// 같은 숫자가 없다면 check=0, 탈출
				break;
		}
		else
			cout << " -------------------- " << endl;
	}
}

void main()
{
	int  rn[4];								// 랜덤 난수
	int count = 1;							// 시도 횟수
	int inum[4];							// 입력 변수
	ru(rn);

	while (1)
	{
		int strike = 0, ball = 0;			// 스트라이크, 볼

		str(inum);							// 입력 함수 호출
		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if (rn[a] == inum[b])		// 난수와 입력값이 같으면
				{
					if (a == b)				// 난수의 위치와 입력값의 위치가 같으면
						strike++;
					else
						ball++;
				}
			}
		}
		if (strike == 4)
		{
			cout << " -------------------- " << endl;
			cout << " ★ 정답★ \t 시도 횟수 : " << count << endl;
			cout << " -------------------- " << endl;
			break;
		}
		else
			cout << " strike : " << strike << "\t ball : " << ball << endl;
		cout << " -------------------- " << endl;
		count++;
	}
	getchar();
	getchar();
}

