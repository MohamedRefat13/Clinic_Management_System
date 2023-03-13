#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"Backup.h"
#include"Admin.h"

sint8_t *AvaliableSlot[6] = {
									"From 2 To 2:30", "From 2:30 To 3",
									"From 3 To 3:30", "From 4 To 4:30",
									"From 4:30 To 5", '\0'
									};
sint16_t NumOfAvailiableSlot = 5 ;

/************************************ System Init **********************************/
void System_Init(List_t *pList)
{

	uint32_t ListSize = ReadListSize();
	/*There are no patients is the system */
	if( ListSize == 0 )
	{
		printf("There is No Data to restore it \n");
		LinkedList_Init(pList);
	}else /*There are  patients in the system */
	{
		uint32_t Counter = 0 ;
		PatientInfo_t LocRecords ;
		LinkedList_Init(pList);
		for(Counter = 1 ; Counter <= ListSize ; Counter++)
		{

			LocRecords = ReadRecords(Counter);
			LocRecords.ResrvationTime = '\0';
			LinkedList_Insert(pList, LocRecords);
			
		}
	}
	printf("SYSTEM IS READY TO START...\n\n");
}
/************************************ Add New Record **********************************/

static PatientInfo_t GetPatientRecord(void);
static PatientInfo_t GetPatientRecord(void)
{
	PatientInfo_t LocPatient ;
    setbuf(stdout,NULL);
    printf("Enter patient ID : ");
    scanf("%hu",&LocPatient.ID);
    printf("Enter patient name : ");
    fflush(stdin);
    gets(LocPatient.Name);
    printf("Enter patient Gender : ");
    scanf("%s",LocPatient.Gender);
    printf("Enter patient age : ");
    scanf("%hu",&LocPatient.Age);

    LocPatient.ResrvationTime = '\0' ;

    return LocPatient ;
}

static Node_t *GetPatientNode(List_t *pList , uint16_t Copy_ID);
static Node_t *GetPatientNode(List_t *pList , uint16_t Copy_ID)
{
	Node_t *pLocal_pHead = pList->pHead;
	Node_t *pLocReturnNode = NULL_ptr ;

	while(pLocal_pHead !=NULL_ptr)
	{
		if(pLocal_pHead->Data.ID == Copy_ID)
		{
			pLocReturnNode = pLocal_pHead;
			break;
		}
		pLocal_pHead = pLocal_pHead->pNextNode;
	}
	return pLocReturnNode ;
}


void Admin_AddNewRecord( List_t *pList )
{   
    PatientInfo_t LocPatient ;
	Node_t *pLocNode ;
	LocPatient = GetPatientRecord();
	
	pLocNode = GetPatientNode(pList , LocPatient.ID );
	if(pLocNode == NULL_ptr)
    {
    	LinkedList_Insert(pList, LocPatient);
		pLocNode = GetPatientNode(pList ,LocPatient.ID );
    	WriteRecords( LocPatient, pLocNode->Node_Num );
    	WriteListSize(pList->Size);
    	printf("Success insertion \n\n");
    }else
	{
		printf("Invalid ID \n\n");
	}
}
/************************************ Edit Patient Records **********************************/
void Admin_EditPatientRecords(List_t *pList )
{
	uint16_t LocID ;
	setbuf(stdout,NULL);
	printf("Enter patinet ID to edit it  : ");
	scanf("%hu",&LocID);

	Node_t *LocNode = GetPatientNode(pList, LocID);
	if(LocNode != NULL_ptr)
	{
		setbuf(stdout,NULL);
		printf("Exist ID\n\n");
		printf("Patient info: %s \t%s\t%hu\n",LocNode->Data.Name , LocNode->Data.Gender , LocNode->Data.Age);
		printf ("Enter Patient right Name  : ");
		fflush(stdin);
		gets(LocNode->Data.Name);
		printf ("Enter Patient right Gender: ");
		scanf("%s",LocNode->Data.Gender);
		printf("Enter Patient right age   : ");
		scanf("%hu",&LocNode->Data.Age);
		WriteRecords(LocNode->Data , LocNode->Node_Num);

		printf("Success editting\n\n");
	}
	else if(LocNode == NULL_ptr)
	{
		printf("Incorrect ID\n\n");
	}else
	{
		/*Do Nothing */
	}
}
/********************************** Reserve a Slot **********************************/
static void DeleteElement(sint8_t **pArray , uint16_t position);
static void DeleteElement(sint8_t **pArray , uint16_t position)
{
	for (int i = position-1 ; i<5 ; i++)
	{
		pArray[i]= pArray[i+1];
	}
}

static void PrintAvailiableSlot(sint8_t **pArray);
static void PrintAvailiableSlot(sint8_t **pArray)
{
	uint16_t LocCounter =0 ;
	while(pArray[LocCounter]!='\0')
	{
		printf("Enter [ %d ] to chose %s \n",LocCounter+1 , pArray[LocCounter]);
		LocCounter++;
	}
}

void Admin_ReserveASlot(List_t *pList )
{
	uint16_t LocID;
	if(AvaliableSlot[0] == '\0')
	{
		printf("\nSorry there is no Avaliable Slot \n\n");
	}else
	{
		printf("\nEnter ID to Reserve a slot with the doctor : ");
		scanf("%hu",&LocID);
		Node_t *pLocNode = GetPatientNode(pList, LocID);
		if(pLocNode != NULL_ptr)
		{
			//To make sure not to reserve a slot for this patient again
			if(pLocNode->Data.ResrvationTime == '\0')
			{
				uint16_t EnterdTimePoss;
				printf("Please Chose the a Slot time :\n");
				PrintAvailiableSlot(AvaliableSlot);
				printf("Your time is : ");
				scanf("%hu",&EnterdTimePoss);
				if(EnterdTimePoss> 0 && EnterdTimePoss <=NumOfAvailiableSlot )
				{
					pLocNode->Data.ResrvationTime = AvaliableSlot[EnterdTimePoss-1];
					DeleteElement(AvaliableSlot, EnterdTimePoss);
					NumOfAvailiableSlot -- ;
					printf("\nSuccess Reservation \n\n");
				}else
				{
					printf("Invaild Time \n");
				}

			}else
			{
				printf("\nThis patient alrady hase a reservation slot \n\n");
			}

		}else if (pLocNode == NULL_ptr)
		{
			printf("\nIncorrect ID\n");
		}else
		{
			/*Do Nothing */
		}
	}
}

/***************************************** Cancel Reservation *****************************************/
void Admin_CancelReservation(List_t *pList)
{
	uint16_t LocID;
	printf("Enter ID to Cancel the reservation slot ");
	scanf("%hu",&LocID);
	Node_t *pLocNode =  GetPatientNode(pList, LocID);
	if(pLocNode != NULL_ptr && pLocNode->Data.ResrvationTime != '\0')
	{
		AvaliableSlot[NumOfAvailiableSlot] = pLocNode->Data.ResrvationTime;
		pLocNode->Data.ResrvationTime = '\0';
		NumOfAvailiableSlot++;
		printf("\nRemove Reservation Success \n");

	}else if (pLocNode == NULL_ptr || pLocNode->Data.ResrvationTime == '\0')
	{
		printf("\nIncorrect ID Or this patient doesn't have a reservation slot \n");
	}else
	{
		/*Do Nothing */
	}

}
/******************************** Linked List Function Implemtation **********************************/
void LinkedList_Init(List_t *pList)
{
	pList->pHead = NULL_ptr ;
	pList->Size   = 0;
}

void LinkedList_Insert(List_t *pList ,PatientInfo_t Data )
{
	Node_t *pNode = (Node_t *)malloc(sizeof(Node_t));
	if(pNode != NULL_ptr)
	{

        pNode->Data = Data;
        pNode->pNextNode = NULL_ptr ;
		pNode->Node_Num = (pList->Size + 1);

        if(pList->Size == 0 )
        {
        	pList->pHead = pNode;
        	pList->Size++;
        }else
        {
        	Node_t *pLocNode = pList->pHead ;
        	uint32_t Iterator = 0 ;
        	while(Iterator <( pList->Size - 1) )
        	{
        		pLocNode = pLocNode->pNextNode ;
        		Iterator ++ ;

        	}
        	pLocNode->pNextNode = pNode;

        	pList->Size++;

        }
	}else
	{
		assert( (!(pNode == NULL_ptr))  && "Memory not allocated because there is no memory in Heap ");
	}
}

