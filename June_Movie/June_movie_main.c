﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "June_Movie.h"
void ListInit(List * pList);
int IsListEmpty(List * pList);
void Insert(List * pList, Data data);
void Modify(List * pList);
void Score(List * pList, int score);
int GetAvgScore(const Data data, const int NumofScore);
void PrintList(List * pList);
void PrintData(const Data data);
Node * Search(List * pList, const char * title);
void Delete(List * pList, const char * title);
//메뉴를 보여주는 함수 

void Menu(int* flag) {
	printf("1:추가\t 2:검색\t 3:수정\t 4:삭제\t 5:평점부여\t 6:영화리스트출력\t 7:프로그램종료\n");
	char ch[10]; 
	scanf("%s", ch);
	while (1) {
		if (strlen(ch) != 1) { //strlen을 쓰니까 좀 아까움(비용이 비쌈)
			printf("ERROR. 다시 시도하세요\n");
			*flag = 0;
			break;
		}
		else if ('1' == ch[0]) {
			printf("영화추가하기\n");
			*flag = 1;
			break;
		}
		else if ('2' == ch[0]) {
			printf("영화검색하기\n");
			*flag = 2;
			break;
		}
		else if ('3' == ch[0]) {
			printf("영화수정하기\n");
			*flag = 3;
			break;
		}
		else if ('4' == ch[0]) {
			printf("영화삭제하기\n");
			*flag = 4;
			break;
		}
		else if ('5' == ch[0]) {
			printf("영화평점부여하기\n");
			*flag = 5;
			break;
		}
		else if ('6' == ch[0]) {
			printf("영화리스트 출력!\n");
			*flag = 6;
			break;
		}
		else if ('7' == ch[0]) {
			printf("프로그램종료!\n");
			exit(1);
			break;
		}
		else{ //예외처리
			printf("ERROR. 다시 시도하세요\n");
			*flag = 0;
			break;
		}
	}
	return;
}

int main()
{
	FILE* fp = NULL;
	List movieList;	
	ListInit(&movieList);
	int flag = 0;
	Data movieData;
	movieData.idx = 0;
	char szBuffer[512];
	while (1) {
		Menu(&flag);
		switch (flag)
		{
		case 1: //추가
			fp = fopen("MovieTest.dat", "wb");
			if (fp == NULL) return 0; 
			getchar(); //Buffer Flush
			movieData.idx += 1; //index를 1씩 증가시킨다.
			printf("제목 : "); gets_s(movieData.title,sizeof(movieData.title));
			printf("감독 : "); gets_s(movieData.director, sizeof(movieData.director));
			printf("장르 : "); gets_s(movieData.genre, sizeof(movieData.genre));
			printf("주연배우 : "); gets_s(movieData.actor, sizeof(movieData.actor));
			printf("개봉년도 : "); scanf("%d", &movieData.year);
			getchar(); //Buffer Flush
			fwrite(&movieData, sizeof(Data), 1, fp);
			Insert(&movieList, movieData);
			break;
		case 2: //검색;
			getchar(); //Buffer Flush
			gets_s(szBuffer, sizeof(szBuffer));
			Search(&movieList, szBuffer);
			break;
		case 3: //수정
			break;
		case 4: //삭제
			getchar(); //Buffer Flush
			gets_s(szBuffer, sizeof(szBuffer));
			Delete(&movieList, szBuffer);
			break;
		case 5: //평점부여
			break;
		case 6:
			PrintList(&movieList);
			getchar(); //Buffer Flush
			break;
		default:
			break;
		}
	}
	fclose(fp);
	return 0;
}