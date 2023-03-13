/*
 * User.c
 *
 *  Created on: Feb 1, 2023
 *      Author: Mohamed Refat
 */
#include<stdio.h>
#include "STD_TYPES.h"
#include "Admin.h"
#include "User.h"


static Node_t *LinkedList_GetPatientNode(List_t *pList , uint16_t Copy_ID);
static Node_t *LinkedList_GetPatientNode(List_t *pList , uint16_t Copy_ID)
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
 void User_ViewPatientRecord( List_t PatientList)
 {
	if(PatientList.Size != 0 )
	{
		uint16_t LocID;
		printf("Enter ID to view patient record : ");
		scanf("%hu",&LocID);
		Node_t *pLocNode = LinkedList_GetPatientNode(&PatientList, LocID);
		if(pLocNode != NULL_ptr)
		{
			printf("ID     is : %hu \n",pLocNode->Data.ID);
			printf("Name   is : %s \n",pLocNode->Data.Name);
			printf("Gender is : %s \n",pLocNode->Data.Gender);
			printf("Age    is : %hu \n",pLocNode->Data.Age);
			if(pLocNode->Data.ResrvationTime != '\0')
			{
				printf("Reservation Slot is : %s \n",pLocNode->Data.ResrvationTime);
			}

		}else if (pLocNode == NULL_ptr)
		{
			printf("\nIncorrect ID\n");
		}else
		{
			/*Do Nothing */
		}
	}else
	{
		printf("There is no patient yet...\n\n");
	}	
 }


void User_ViewTodaysReservation( List_t PatientList)
{
	printf("\nTodays patient reservation is : ");
		Node_t *pLocNode ;
		pLocNode = PatientList.pHead ;
		while(pLocNode != NULL_ptr )
		{
			if(pLocNode->Data.ResrvationTime != '\0')
			{
				printf("\nPatient ID %hu ...... Reservation Slot is %s \n",pLocNode->Data.ID , pLocNode->Data.ResrvationTime);
			}
			pLocNode = pLocNode->pNextNode;
		}
		printf(".....................................\n\n");

}
