/*
 * DataBase.c
 *
 *  Created on: Feb 13, 2023
 *      Author: Mohamed Refat
 */
#include <stdio.h>
#include "STD_TYPES.h"
#include "Backup.h"


void WriteListSize(uint32_t Size)
{
	FILE *pFile = fopen("ListSize.txt" , "w");
	fprintf(pFile , "%lu" , Size);
	fclose(pFile);
}
uint32_t ReadListSize()
{
	uint32_t Size=0 ;
	FILE *pFile = fopen("ListSize.txt" , "r");
	if(pFile == NULL_ptr)
	{
		Size = 0 ;
	}
	else
	{
		fscanf(pFile , "%lu" , &Size);
	}

	return Size;
}



PatientInfo_t ReadRecords(uint32_t linepos)
{
    FILE *pFile ;
    pFile     = fopen("Data.txt" , "r");
    sint8_t PatientRecordBuffer[200];
    uint32_t  CurrenLine_Num=1 ;
    while(!feof(pFile))
    {
		fgets(PatientRecordBuffer , 200 , pFile);
        if(CurrenLine_Num == linepos)
        {
            break ;
        }
        CurrenLine_Num++;
    }
    fclose(pFile);
    PatientInfo_t P1 = convertToStructForm(PatientRecordBuffer);
    return P1;
}


void WriteRecords(PatientInfo_t Record, uint32_t linepos)
{
    FILE *pFile , *pTempFile ;
    pFile     = fopen("Data.txt" , "r");
    pTempFile = fopen("TempData.txt" , "w");
    sint8_t CurrentLineBuffer[200] ;
    sint8_t PatientRecord[200];

    ConvertToText(Record , PatientRecord);
    uint32_t  CurrenLine_Num=1 ;
    while(!feof(pFile))
    {
        fgets(CurrentLineBuffer , 200 , pFile);
        if(CurrenLine_Num == linepos)
        {
            fputs(PatientRecord , pTempFile);
        }else
        {
            fputs(CurrentLineBuffer , pTempFile);
        }
        CurrenLine_Num++;
    }
    fclose(pTempFile);
    fclose(pFile);
    remove("Data.txt");
    rename("TempData.txt" ,"Data.txt" );
}



void ConvertToText(PatientInfo_t Record , sint8_t TextBuffer[] )
{
    FILE *pFile = fopen("Converting.txt", "w");

    fprintf(pFile,"%-5hd %-30s %-10s %-5hd\n",Record.ID , Record.Name , Record.Gender , Record.Age );
    fclose(pFile);
    pFile = fopen("Converting.txt", "r");
    fgets(TextBuffer , 200 ,pFile);
    fclose(pFile);
    remove("Converting.txt");
}

PatientInfo_t convertToStructForm(sint8_t ParientBuffer[])
{
    FILE *pFile  = fopen("Converting.txt" , "w");
    fputs(ParientBuffer , pFile );
    PatientInfo_t p1 ;
    fclose(pFile);
    pFile = fopen("Converting.txt", "r");
    fscanf(pFile , "%5hd " , &p1.ID);
    fgets(p1.Name , 30 , pFile);
    fscanf(pFile,"%10s ",p1.Gender);
    fscanf(pFile,"%5hd ",&p1.Age);
    fclose(pFile);
    remove("Converting.txt");
    return p1;
}























