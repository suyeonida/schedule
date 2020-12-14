#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"
#define STRING_SIZE 256
#define N 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

schedInfo_t* list = NULL;    
schedInfo_t* newNode = NULL;

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	FILE *fp;          //���� ������  
	
	char name[200];
	char place[100], typeName[100];	
	size_t size;          //�̰� ����?????? 
	int month;
	int day;
	int type;
	//void *list;
	//void *ndPtr;   //��� ������  
	void *schedInfo;
	int option;    //��� �������� Ȯ��  
	int cnt,i,count;
	int j=0;
	char ch;
	struct schedInfo* tmp = NULL;     // tmp = �ӽ� ����ü �����ͺ���
	
	
	struct genSchedInfo{
			char name[200];
			char place[200];
			char typeName[100];
			int month;
			int day;
			int type;
		};
		
	//1. FILE pointer open & error handling 
	fp= fopen("schedule.dat","r");  //���� �б���� ����	 
	if(fp == NULL){                //error handling 
		printf("invalid path! \n");
		return -1;
	}
	
	//initializing the list    �ʱ� ���� ����  
	printf("Reading the data files... \n");
	list = (void*)list_genList();    //list�����Ϳ�  
	
	//2. read from the file  ���Ϸκ��� �������� �о�Ͷ�. 
	list = NULL; // �Լ������Ҷ����� ���� �ʱ�ȭ
	newNode = NULL; // �Լ������Ҷ����� ���� �ʱ�ȭ
	
	while(1) {        // client.txt ���Ͽ��� �ѹ��� �ѹ��� �޾ƿ� ����. ��带 ���� �� ����Ʈ�� �߰�
				count=0;
				tmp = (schedInfo_t*)malloc(sizeof(schedInfo_t));
				tmp->type = 0; 
				tmp->month = 0; 
				tmp->day =0;     
				
				while((ch=fgetc(fp))!='\n'&& ch!=EOF){   //���Ͽ������� ���ڸ� �ϳ��ϳ� �д´�.
						if(ch==' ') {
							   if(count==1) 
							   	tmp->book_name[i] = '\0';	
							   if(count==2) 
							   	tmp->publisher[i] = '\0';	
							   if(count==3) 
							   	tmp->author[i] = '\0';	
							   if(count==5) 
							   	tmp->location[i] = '\0';	
						i = 0; 
						count++; 
						continue; 
						}
						
						if(count==0)    
							tmp->name[i++] = ch; 
						else if(count==1) 
							tmp->place[i++] = ch;
						else if(count==2)  //schedule type��  int��  
							tmp->scheduleType_e = ((tmp->type)*10)+(ch-48);
						else if(count==3) { 
							tmp->month = ((tmp->month)*10) + (ch-48);} // month��  int ��  
						else if(count==4) 
							tmp->day= ((tmp->day)*10) + (ch-48);          //day��  int  ��
				}     
						
			}	
					if(ch!=EOF) {
						tmp->next = NULL;
						newNode = tmp;
						list_addTail(schedInfo, list);   //add a node at the end of the list 
					}
					else if(ch==EOF) 
						break;	
			
	//fill code here ---- close the file pointer
	fclose(fp);
	printf("Read done! %i schedules are read\n", list_len(list));
	
	
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		printf("1.print all the schedules\n");
		printf("2.search for the schedules in the month\n");
		printf("3.search for the schedules in the place\n");
		printf("4.search for specific type schedule\n");
		printf("5.exit\n\n");
		printf(" select an option.");
		
		//4. get option from keyboard
		scanf("%d", &option);
		
		
		switch(option)
		{
			case 1: //print all the schedules   
				printf("printing all the schedules in the scheduler.....\n\n\n");
				
				total_schedule(void);
			
				break;
				
			case 2:  //scanf�� 2�� �޴� �ٸ�  
				printf("which month ? : ");
				scanf("%i", &month);
				
				//file code here -- print scheduling info elements matching to the month
				month_search();
			
			
				while(list_isEndNode(ndPtr) == 0)
				
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
				}
				
				break;
				
			case 3: // 3�� return �Ѵٸ� 
				
				place_search();
				
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the place
					
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
				}
				
				break;
				
			case 4:  //4�� return �Ѵٸ�  
				printf("which type ?\n");
				sched_printTypes();
				printf("your choice : ");
				scanf("%s", &typeName);
				
				
				if (/* fill code here -- convert the type and check if the type is valid */)
				{
					tmp = list;
					
					type_search(void)
					
					/*while (list_isEndNode(ndPtr) == 0)
					{
						//file code here -- print scheduling info elements matching to the place
						ndPtr = list_getNextNd(ndPtr); //get the next node from the list
						schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
						
						//fill code this part - end
					}*/
				}
				else
				{
					printf("wrong type name!\n");
				}
				break;
				
			case 5:  //5�� �Է��Ѵٸ� ���α׷� exit 
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:    
				printf("wrong command! input again\n");
				break;
		}
		
		
	}
	
	return 0;
}
