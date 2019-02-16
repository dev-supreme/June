#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void movieProcess(MOVIEDATA* movieList, int flag);
void addMovie(MOVIEDATA* movieList);
void searchMovie(MOVIEDATA* movieList);

void movieProcess(MOVIEDATA* movieList, int flag) {
	switch (flag)
	{
	case 1:
		addMovie(movieList);
		break;
	case 2:
		searchMovie(movieList);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

void addMovie(MOVIEDATA* movieList) {
	size_t curDataSize = sizeof(*movieList);
	printf("%d\n", curDataSize);
	size_t newDataSize = curDataSize + (sizeof(MOVIEDATA) * 1);
	printf("%d\n", newDataSize);
	movieList = (MOVIEDATA*)realloc(movieList, newDataSize);
}

void searchMovie(MOVIEDATA* movieList) {

}

//메뉴를 보여주는 함수 
int printMenu() {
	int nInput = 0;
	system("cls");
	printf("기능을 선택하세요(숫자를 누르면 해당 기능이 선택됩니다.)\n");
	printf("1:추가\t2:검색\t3:수정\t4:삭제\t5:평점부여\n");
	char ch = _getch();
	return ch;
}
void Menu(int* flag) {
	printf("1:추가\t2:검색\t3:수정\t4:삭제\t5:평점부여\n");
	while (1) {
		char ch = _getch(); //_getch는 버퍼를 거치지 않고 곧바로 데이터 반환.
		if ('1' == ch) {
			printf("영화추가하기\n");
			*flag = 1;
			break;
		}
		else if ('2' == ch) {
			printf("영화검색하기\n");
			*flag = 2;
			break;
		}
		else if ('3' == ch) {
			printf("영화수정하기\n");
			*flag = 3;
			break;
		}
		else if ('4' == ch) {
			printf("영화삭제하기\n");
			*flag = 4;
			break;
		}
		else if ('5' == ch) {
			printf("영화평점부여하기\n");
			*flag = 5;
			break;
		}
		else { //예외처리
			printf("ERROR. 다시 시도하세요\n");
			*flag = 0;
			continue;
		}
	}
	printf("메뉴선택종료\n");
}

int main()
{
	const int MOVIENUM = 5; //영화 데이터의 갯수. 
	int nFlag = 0;//기능 선택 flag
	
	MOVIEDATA* movieList = (MOVIEDATA*)malloc(sizeof(MOVIEDATA) * MOVIENUM);
	Menu(&nFlag);
	printf("malloc size : %d\n", sizeof(*movieList));
	movieProcess(movieList, nFlag);
	printf("realloc size : %d\n", sizeof(*movieList));
	free(movieList);
	movieList = NULL;
	
	return 0;
}