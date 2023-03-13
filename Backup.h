/*
 * DataBase.h
 *
 *  Created on: Feb 13, 2023
 *      Author: Mohamed Refat
 */

#ifndef BACK_UP_H
#define BACK_UP_H

#include "Admin.h"
PatientInfo_t ReadRecords(uint32_t linepos);

void WriteRecords(PatientInfo_t Record,uint32_t lineposs);

void  ConvertToText(PatientInfo_t Record , sint8_t TextBuffer[] );

PatientInfo_t convertToStructForm(sint8_t ParientBuffer[]);

void WriteListSize(uint32_t Size);

uint32_t ReadListSize();

#endif /* BACK_UP_H */
