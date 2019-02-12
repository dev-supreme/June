#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
실습:  영화 데이터베이스 구축
영화 정보를 입력받아 파일이 저장한다. 
영화 정보는 영화 제목, 감독이름, 개봉연도, 장르, 주연배우 등이 있다.
영화 정보에 대해 추가/검색/수정/삭제 가 가능해야 한다. 
영화에 대해 다수가 평점을 부여할 수 있다 (id/score) 
영화 정보 출력 시 평균 평점을 보여준다. 
프로그램 실행 시 메뉴를 출력하고
메뉴에 따라 영화 정보를 추가/검색/수정/삭제/평점 부여를 수행한다. 
모든 데이터는 파일에 저장되도록 구현한다.

//1.영화정보를 담는 구조체 생성(MOVIEDATA)
//2.메뉴출력 및 선택 함수 선언 및 정의
3.메뉴에 따른 각 기능 함수 정의(추가 검색 수정 삭제 평점부여)
-추가 : 영화데이터1개를 추가 함(동적배열로 realloc?)
-검색 : 영화이름으로 검색하게 함. 검색 성공 시 영화 정보 출력 / 실패 경우 검색실패!

-수정 : 영화이름으로 검색 후, 해당 영화데이터를 수정할 수 있음
-삭제 : 영화이름으로 검색 후, 해당 영화데이터 삭제.
-평점부여: 영화이름 검색 후, 평점 부여하는 기능.
		평점은 다수가 부여할 수 있음. 평균평점이 있어야 함.
4.이 모든 정보를 파일로 저장(txt,bin)
*/
typedef struct _movieData {
	char title[64];
	char director[32];
	char genre[32];
	char actor[32];
	int year;
	int score;
	int avg_score;
}MOVIEDATA;
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