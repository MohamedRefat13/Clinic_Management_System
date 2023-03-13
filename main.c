#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "STD_TYPES.h"
#include "Admin.h"
#include "User.h"

sint8_t Password[5] = "1234";
sint8_t Mode[10]={0};
int main()
{
	
	List_t PatentList ;
	System_Init(&PatentList);
HomePage: 
	setbuf(stdout,NULL);
	printf("\n\t\t\t Home Page\t\t\n");
	sint8_t EnterdMode[10] ;
	printf("Choose the Mode [Admin , User]: ");
	scanf("%s",EnterdMode);
	if(!strcmp(EnterdMode , "Admin"))
	{
		goto AdminPage ;
	}else if(!strcmp(EnterdMode , "User"))
	{
		goto UserPage ;
	}
	else
	{
		printf("Please Enter the right Mode \n");
		goto HomePage;
	}


AdminPage:
	printf("\n\t\t\t Admin Page\t\t\n\n");
	sint8_t EnterdPass[20] ;
	static uint16_t NumOfWrongTrails = 0  ;
	printf("Enter The Pasword : ");
	scanf("%s",EnterdPass);
	if(!strcmp(EnterdPass , Password))// Correct Password Case
	{
		NumOfWrongTrails = 0 ;
		printf("\n........... Correct Password ........\n\n");
		printf("You Are in the System now \n");
		while(1)
		{
			uint16_t EnterdOperation = 0 ;
			printf("------------------------------------------------------------\n");
			printf("-\tEnter [ 1 ] to Add New Patient Record              -\n");
			printf("-\tEnter [ 2 ] to Edit Patient Records                -\n");
			printf("-\tEnter [ 3 ] to Reserve a slot with the doctor      -\n");
			printf("-\tEnter [ 4 ] to Cancel reservation.                 -\n");
			printf("-\tEnter any number else to go to the Home Page       -\n");
			printf("------------------------------------------------------------\n");
			printf("Choose  Operation Number : ");
			scanf("%hu",&EnterdOperation);
			switch(EnterdOperation)
			{
				case 1 : Admin_AddNewRecord(&PatentList);       break ;
				case 2 : Admin_EditPatientRecords(&PatentList); break ;
				case 3 : Admin_ReserveASlot(&PatentList);       break ;
				case 4 : Admin_CancelReservation(&PatentList);  break ;
				default:        goto HomePage ;                 break ;
			}
		}
	}else// Wrong Password Case
	{
		printf("Wrong Password \n");
		NumOfWrongTrails ++ ;
		if(NumOfWrongTrails == 3)// Wrong Password for three time
		{
			printf("You enterd the Password wrong for three times \n");
			printf("Try again after 1 Minute \n");
			Sleep(60000);
			goto HomePage ;

		}else
		{
			printf("Try again \n");
			goto AdminPage ;
		}

	}


UserPage:
{
	printf("\n\t\t\t User Page\t\t\n");
	while(1)
	{
		uint16_t EnterdOperation = 0 ;
		printf("------------------------------------------------------------\n");
		printf("-\tEnter [ 1 ] to View patient record                 -\n");
		printf("-\tEnter [ 2 ] to View todays reservations            -\n");
		printf("-\tEnter any number else to go to the Home Page       -\n");
		printf("------------------------------------------------------------\n");
		printf("Choose  Operation Number : ");
		scanf("%hu",&EnterdOperation);
		switch(EnterdOperation)
		{
			case 1 : User_ViewPatientRecord(PatentList); break ;
			case 2 : User_ViewTodaysReservation(PatentList); break ;
			default: goto HomePage ; break ;
		}
	}
}

}
/***
 * Todo
 *
 * 		search for the case of the error
 * 		strcpy(pLocNode->Data.ResrvationTime, AvaliableSlot[EnterdTimePoss-1]; <-- solution
 * 		pLocNode->Data.ResrvationTime =  AvaliableSlot[EnterdTimePoss-1];      <-- problem
 *
 *
 *		Solve Warning message --> [done]
 *
 *		Rename Function in Admin to stats with Admin
 *		complete Functions -->[done]
 *
 *		-->>make the name long string (string with space using gets()
 *
 *		in Function ReserveASlot:
 *			if the admin entered incorrect number to choose the slot time
 *				print an a warning message -->[done]
 *
 *			if there is no avaliable slot
 *				print there is no a vailable slot --> [done]
 *
 *		-->>Separate helper function in a privete file
 *
 *		-->>in Add new record : make a function to  GetPatient info
 *			insted if doing that inside the function
 *
 *		handel case if there is no avaliable slot in Admin_ReserveASlot[done]
 *
 *		-->>replace a double Liked List insted of Linked Stake
 *
 *		--> Handle a case if the user try to edit patient record and there is no patient in the system
 *
 *
 * ***/


