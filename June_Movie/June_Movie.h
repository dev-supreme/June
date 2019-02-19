#define MAX_SCORE_NUM 3
#define TRUE 1
#define FALSE 0
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
-추가 : 영화데이터1개를 추가 함
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
	int idx;
	int year;
	int score[MAX_SCORE_NUM];
	int avg_score;
}Moviedata;
typedef Moviedata Data;

typedef struct _node {
	Data data;
	struct _node * prev;
	struct _node * next;
}Node;

typedef struct _DLlist {
	Node * head;
	Node * tail;
}DoublyLinkedList;

typedef DoublyLinkedList List;

void ListInit(List * pList);
int IsListEmpty(List * pList);
void Insert(List * pList, Data data);
void Delete(List * pList, const char * title);
void Modify(List * pList);
void Score(List * pList, int score);
int GetAvgScore(const Data data, const int NumofScore);
void PrintList(List * pList);
void PrintData(const Data data);
void PrintDetail(const Data data);
Node * Search(List * pList, const char * title);
