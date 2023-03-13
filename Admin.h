/*
 * Admin.h
 *
 *  Created on: Feb 1, 2023
 *      Author: Mohamed Refat
 */
#ifndef _ADMIN_H_
#define _ADMIN_H_
#include "STD_TYPES.h"

/********************** Admin Data types***********************/

/*
 * The following structure is used to define the new data type  << PatientInfo_t >>
 * Struct_t argument ::
 * 					 uint8_t  Name[50]   --> 	array of characters that store the patient name
 *					 uint16_t Age        -->	variable that store the age of the patient
 *					 uint8_t Gender[50]  -->  	array of characters that store the patient gender
 *					 uint16_t ID         -->  	variable that store the patient age
 *					 uint16_t Resrvation -->
 *
 * */

typedef struct
{
	uint8_t Name[50] ;
	uint8_t Gender[10] ;
	uint16_t Age ;
	uint16_t ID ;
	sint8_t *ResrvationTime ;
}PatientInfo_t;

/******************Linked list Data type  **********************/
typedef struct Node_t
{
	PatientInfo_t  Data;
	uint32_t Node_Num;
	struct Node_t *pNextNode;
}Node_t;


typedef struct
{
	Node_t *pHead;
	uint32_t Size;
}List_t;



/********************** Admin Functions Prototype ***********************/
void System_Init(List_t *pList);
void Admin_AddNewRecord(List_t *pList);
void Admin_EditPatientRecords(List_t *pList);
void Admin_ReserveASlot(List_t *pList );
void Admin_CancelReservation(List_t *pList);


/********************** LinkedList Functions Prototype ***********************/

void LinkedList_Init(List_t *pList);
void LinkedList_Insert(List_t *pList , PatientInfo_t Data );






/********************** Single LinkedList  Functions Prototype ***********************/

//void LinkedList_Init(List_t *pList);
//void LinkedList_Insert(List_t *pList , PatientInfo_t Data );





















#endif /*_ADMIN_H_*/
