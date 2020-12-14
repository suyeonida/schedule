#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element  각 이름에 따라 출력할 문자열 
 
//enum type's name
char type_string[MAX_TYPE][20] =    //스켸줄 유형 숫자와 일대일 대응 시켜야해  
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] =        //월 숫자와 일대일 대응 시켜야해  
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions   열거 정 
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 의 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;



//structure definition for a schedule info.  //!!!!정보 정의 구조체!!!! 

typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
	struct schedInfo* next;   //다음 노드를 가리킴 
} schedInfo_t;


void sched_printTypes(void)   // //스켸줄 유형 숫자와 일대일 대응 시켜야해
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj)     //검색 결과 출력해주는 함수. 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}


//print function used in case 1 

void total_schedule(void) {
		schedInfo_t* cur;
		int cnt = 0;
		cur = list;  
		
		while(cur != NULL) {
			printf("---------------------------------\n");
			printf("%d", cnt+1);
			printf("Schedule Name : %s (%s) ", cur->name, cur->type );
			printf("When : %d , %d ", cur->month, cur->day);
			printf("Where: %s \n", cur->place);
			
			cur = cur->next;  
			++cnt;
			printf("\n");
		} 
}

//print function in case 2

void month_search(void) {   //month로 찾기  
	
		int month_num;      
		int i = 0, j = 0, n = 0 ,cnt = 0;
		schedInfo_t* month[N];     // 리스트 변수의 노드 주소값을 저장할 포인터배열
		schedInfo_t* tmp;         //임시 구조체 포인터변수
	    
		tmp = list;  
		
		//printf("which month ? : ");
		//scanf("%lf", &month_num);        //month에 숫자를 받음  
		month_num = month; 

		while(tmp != NULL) { //임시저장소 포인터가 널이 아니면  
				n = 0; //비교 카운트 변수 초기화 
				if(month_num == tmp->month) { // month숫자와 포인터가 가리키는 month가 같으면  
						cnt++; 
						if(i=0) 
							month[i++] = tmp;
						else { 
							for(j=0; j<i; j++)
									if(month[j]->month == tmp->month) 
											n++;
						if(n==0) 
							month[i++] = tmp;
						}
				}
				tmp = tmp->next;   // 다음 노드로 이동
		
		tmp = list; // 초기화

		if(cnt!=0){  //검색했을 때 정보가 있다면 출력  
			j=0;
			  
			printf("--------------------------------------\n");
			printf("%d.Schedule Name : %s (%s)\n",j, month[j]->name, month[j]->type);
			printf("When : %d. %d\n", month[j]->month, month[j]->day);
			printf("Where : %s\n", month[j]->place);
			j++;
		}
		
		if(cnt == 0)   //count가 0이면  
			printf("\n");
		}
}

//print function in case 3

void place_search(void) {             // case 3 : place로 찾기  
		char str[N];                  //사용자가 입력할 문자열 받는 공간  
		schedInfo_t* tmp;            // 임시 구조체 포인터변수
		schedInfo_t* place[N];       // 리스트 변수의 노드주소값을 저장할 포인터배열
		int i=0, j=0, cnt=0, n=0; 
		
		tmp = list; // 임시 구조체 포인터변수에 리스트 주소값 
		getchar();
		printf("Which place? : ");
		gets(str);
		while(tmp!=NULL) { // 노드 끝이 아닐때까지
			n=0;
				if(strstr(tmp->place, str) != NULL) { // 입력place과  저장된 place이 같을때
						
						if(i==0) place[i++] = tmp; // 같은place가 저장된 노드의 주소를 저장한 다음 노드와 비교, 첫번째 예외처리
						else { 
								for(j=0; j<i; j++)
										if(place[j]->place == tmp->place) 
											n++; // 이전에 저장된 노드의 값과 비교후 있을 경우 카운트
								if(n==0) place[i++] = tmp; // 동일한 값이 없을경우 다음배열에 노드주소값저장
						}
				}
				tmp = tmp->next; // 다음노드를 가리킴
		}
		tmp = list_b; // 헤더주소값으로 링크초기화
		if(cnt!=0) 
		j=0; // 0부터 시작 초기화
		while(j<i) {
				
			tmp = list; // 헤더주소값으로 링크 초기화
			
			printf("--------------------------------------\n");
			printf("%d.Schedule Name : %s (%s)\n",j, place[j]->name, place[j]->type);
			printf("When : %s\n", place[j]->day);
			printf("Where : %s\n", place[j]->place);
			j++;
		}
		if(cnt==0) 
			printf("\n"); 
		
	}
	
//print function in case 4

 

//generating a structure of scheduling information   
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;
	
	//error handler

	//allocate memory and set the member variables
	
	
	return (void*)schedPtr;
}



//get month information from the scheduler info structure  스케줄 구조체에서 월 정보를 가져오는  
float sched_getMonth(void* obj)
{
	
}


//get type information from the scheduler info structure스케줄 구조체에서 타입정보를 가져오는  
int sched_getType(void* obj)
{
	
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{

}

//convert the name of the type into the enum(integer) value  타입이름을 정수형으로 바꿔주는 작업해주는 함수  
int sched_convertType(char* typeName)
{
	
}

