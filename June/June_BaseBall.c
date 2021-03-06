#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define NUM_OF_CASE 3

typedef enum { false, true } bool;
typedef struct GAMEDATA {
	int try_count;
	int input_Count;
	int ball_Count;
	int strike_Count;
	bool isGameEnd;
	int *random_num;
	int *input_num;
}GAMEDATA;
/*
1. 숫자 야구 게임
 - 중복되지 않은 임의의 수 3개를 생성
 - 키보드 입력으로 3개의 숫자를 순서대로 입력받음
 - 입력받은 숫자와 임의로 생성한 숫자를 비교
 - 숫자만 맞으면 Ball, 숫자와 순서가 맞으면 Strike 로 카운트
 - 1번의 시도횟수마다 Ball, Strike 출력
 - 3 Strike 시 현재까지 시도한 횟수 출력후 게임 종료
 */

void GenerateData(int** nData, int nSize) {
	
	int* tmp = (int*)malloc(sizeof(int) * nSize);
	for (int i = 0; i < nSize; i++) {
		tmp[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++) {
			if (tmp[j] == tmp[i]) {
				i--; //현재 들어온 i번째 숫자가 전에 있던 숫자들(j)과 중복되면, i를 다시 수행한다.
			}
		}
	}
	*nData = tmp;
}

void InputData(int** nData, int nSize) {
	int* tmp = (int*)malloc(sizeof(int) * nSize);
	char buff[2048] = { 0, };

	gets_s(buff, sizeof(buff));
	sscanf(buff, "%d %d %d", &tmp[0], &tmp[1], &tmp[2]);

	// tokenize
	//char* sp;
	//char* tmp = strtok_s(buff, " ", &sp);
	//while (tmp)
	//{
	//	int value = atoi(tmp);

	//	tmp = strtok_s(NULL, " ", &sp);
	//}

	*nData = tmp;
}

void PrintData(int *nData, int nSize) {
	int i = 0;
	for (i = 0; i < nSize; i++) {
		printf("%d \t", nData[i]);
	}
}

void BallStrikeCalculate(GAMEDATA *gData) {
	//Calculate Ball / Strike
	for (int i = 0; i < NUM_OF_CASE; i++) {
		printf("***CASE %d***\n", i + 1);
		for (int j = 0; j < NUM_OF_CASE; j++) {
			if (gData->input_num && gData->random_num)
			{
				if (gData->input_num[j] == gData->random_num[i]) {
					if (j == i) {
						gData->strike_Count++;
						printf("***Strike!!!***\n\n");
					}
					else
					{
						gData->ball_Count++;
						printf("***Ball***\n");
					}
				}
			}
			else
			{
				printf("error\n");
			}
		}
	}
}

void GameResult(GAMEDATA *gData) {
	//게임 종료 여부 판별
	if (gData->strike_Count == NUM_OF_CASE) {
		printf("\n\n%d Strike!! 축하합니다! 숫자야구 게임이 종료되었습니다.\n", NUM_OF_CASE);
		printf("\n게임을 시도한 횟수 : %d번\n", gData->try_count);
		gData->isGameEnd = true;
		free(gData->random_num);
	}
	else {
		printf("%d번만 더 strike 하지.....", NUM_OF_CASE - gData->strike_Count);
		printf("\n게임을 다시 시작합니다........\n");
		printf(".\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
		gData->isGameEnd = false;
	}

	gData->strike_Count = 0;
	gData->ball_Count = 0;

	//게임을 성공해도 메모리 해제, 실패해도 재 시작할것이므로 해제
	free(gData->input_num);
}
void Game(GAMEDATA *gData) {
	GenerateData(&gData->random_num, NUM_OF_CASE);

	while (!gData->isGameEnd) {
		gData->try_count++; //게임이 실행 될 때마다 count 1 증가
		

		printf("==========1~10 사이 숫자 %d 개가 생성되었습니다.===========\n", NUM_OF_CASE);
		PrintData(gData->random_num, NUM_OF_CASE);

		printf("\n==========================================================\n\n 3개 숫자를 입력하시오.\n");
		InputData(&gData->input_num, NUM_OF_CASE);

		printf("==========입력받은 숫자 %d 개는 다음과 같습니다.===========\n", NUM_OF_CASE);
		PrintData(gData->input_num, NUM_OF_CASE);

		printf("\n==========================================================\n\n");

		BallStrikeCalculate(gData);
		printf("Ball 수 = %d \nStrike 수 = %d\n", gData->ball_Count, gData->strike_Count);
		
		GameResult(gData);
	}
}

void SetUp(GAMEDATA *gData) {
	printf("====================숫자 야구 게임====================\n\n");
	srand(time(NULL));
	gData->try_count = 0;
	gData->ball_Count = 0;
	gData->input_Count = 0;
	gData->random_num = NULL;
	gData->input_num = NULL;
}

int main()
{
	GAMEDATA gData = { 0 };
	SetUp(&gData);
	Game(&gData);
	
	return 0;
}