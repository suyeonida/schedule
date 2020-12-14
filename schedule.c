#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element  �� �̸��� ���� ����� ���ڿ� 
 
//enum type's name
char type_string[MAX_TYPE][20] =    //������ ���� ���ڿ� �ϴ��� ���� ���Ѿ���  
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
char month_string[13][4] =        //�� ���ڿ� �ϴ��� ���� ���Ѿ���  
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions   ���� �� 
typedef enum scheduleType {
	drama=0, 		//��� 
	movie, 			//��ȭ �� 
	advertisement, 	//���� 
	entertainment, 	//���� 
	meeting,		//ȸ�� 
	fitness,		//� 
	privacy			//���λ� 
} scheduleType_e;



//structure definition for a schedule info.  //!!!!���� ���� ����ü!!!! 

typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
	struct schedInfo* next;   //���� ��带 ����Ŵ 
} schedInfo_t;


void sched_printTypes(void)   // //������ ���� ���ڿ� �ϴ��� ���� ���Ѿ���
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj)     //�˻� ��� ������ִ� �Լ�. 
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

void month_search(void) {   //month�� ã��  
	
		int month_num;      
		int i = 0, j = 0, n = 0 ,cnt = 0;
		schedInfo_t* month[N];     // ����Ʈ ������ ��� �ּҰ��� ������ �����͹迭
		schedInfo_t* tmp;         //�ӽ� ����ü �����ͺ���
	    
		tmp = list;  
		
		//printf("which month ? : ");
		//scanf("%lf", &month_num);        //month�� ���ڸ� ����  
		month_num = month; 

		while(tmp != NULL) { //�ӽ������ �����Ͱ� ���� �ƴϸ�  
				n = 0; //�� ī��Ʈ ���� �ʱ�ȭ 
				if(month_num == tmp->month) { // month���ڿ� �����Ͱ� ����Ű�� month�� ������  
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
				tmp = tmp->next;   // ���� ���� �̵�
		
		tmp = list; // �ʱ�ȭ

		if(cnt!=0){  //�˻����� �� ������ �ִٸ� ���  
			j=0;
			  
			printf("--------------------------------------\n");
			printf("%d.Schedule Name : %s (%s)\n",j, month[j]->name, month[j]->type);
			printf("When : %d. %d\n", month[j]->month, month[j]->day);
			printf("Where : %s\n", month[j]->place);
			j++;
		}
		
		if(cnt == 0)   //count�� 0�̸�  
			printf("\n");
		}
}

//print function in case 3

void place_search(void) {             // case 3 : place�� ã��  
		char str[N];                  //����ڰ� �Է��� ���ڿ� �޴� ����  
		schedInfo_t* tmp;            // �ӽ� ����ü �����ͺ���
		schedInfo_t* place[N];       // ����Ʈ ������ ����ּҰ��� ������ �����͹迭
		int i=0, j=0, cnt=0, n=0; 
		
		tmp = list; // �ӽ� ����ü �����ͺ����� ����Ʈ �ּҰ� 
		getchar();
		printf("Which place? : ");
		gets(str);
		while(tmp!=NULL) { // ��� ���� �ƴҶ�����
			n=0;
				if(strstr(tmp->place, str) != NULL) { // �Է�place��  ����� place�� ������
						
						if(i==0) place[i++] = tmp; // ����place�� ����� ����� �ּҸ� ������ ���� ���� ��, ù��° ����ó��
						else { 
								for(j=0; j<i; j++)
										if(place[j]->place == tmp->place) 
											n++; // ������ ����� ����� ���� ���� ���� ��� ī��Ʈ
								if(n==0) place[i++] = tmp; // ������ ���� ������� �����迭�� ����ּҰ�����
						}
				}
				tmp = tmp->next; // ������带 ����Ŵ
		}
		tmp = list_b; // ����ּҰ����� ��ũ�ʱ�ȭ
		if(cnt!=0) 
		j=0; // 0���� ���� �ʱ�ȭ
		while(j<i) {
				
			tmp = list; // ����ּҰ����� ��ũ �ʱ�ȭ
			
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



//get month information from the scheduler info structure  ������ ����ü���� �� ������ ��������  
float sched_getMonth(void* obj)
{
	
}


//get type information from the scheduler info structure������ ����ü���� Ÿ�������� ��������  
int sched_getType(void* obj)
{
	
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{

}

//convert the name of the type into the enum(integer) value  Ÿ���̸��� ���������� �ٲ��ִ� �۾����ִ� �Լ�  
int sched_convertType(char* typeName)
{
	
}

