# Brief
The Clinic Management System is being developed in C programming language.
This Clinic Management System is based on the concept of managing a patient’s record at a hospital.
The project is based on Single Linked List Data structure
##  What can the system do?
### In Admin Mode
1) `Add new patient record [ Name , Age ,Gender , ID ]`
2) `Edit Patient Record`
3) `Reserve aSlot with doctor if there is available slot`
4) `Cancel reservation`

### In User Mode
1) `View Patient Record`
2) `View Todays Reservation`
   
# System Features
The system can store patient records in a separate file in case of a system failure. and it is able to restore those records again when the system starts up

---
# Functions description
---
# Admin Functions 
---
##  System_Init()
### Description :
his function s used to initiate the  system  and restore the data the old data of the system 

### Syntax :
`System_Init(List_t *pList);`

### Argument :
`pList` is a pointer to the list of patient 

### Return 
void 

### Note
This function must be called every time you want to start the system
### Example 
```c
int main()
{
    List_t PatientList;
    System_Init(&PatientList);
}
```

##  Admin_AddNewRecord()
### Description :
This function s used to add new  patient record to the system

### Syntax :
`Admin_AddNewRecord(List_t *pList);`

### Argument :
`pList` is a pointer to the list of patient 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    Admin_AddNewRecord(&PatientList);
}
```
---

##  Admin_EditPatientRecords()
### Description :
This function s used to edit patient records if ti exist

### Syntax :
`Admin_EditPatientRecords(List_t *pList);`

### Argument :
`pList` is a pointer to the list of patient 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    Admin_EditPatientRecords(&PatientList);
}
```
---

##  Admin_ReserveASlot()
### Description :
This function is used to  reserve a slot with the doctor if there is aviliable slot

### Syntax :
`Admin_ReserveASlot(List_t *pList);`

### Argument :
`pList` is a pointer to the list of patient 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    Admin_ReserveASlot(&PatientList);
}
```
 
---

##  Admin_CancelReservation()
### Description :
This function is used to  cancel  patient reservation 

### Syntax :
`Admin_CancelReservation(List_t *pList);`

### Argument :
`pList` is a pointer to the list of patient 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    Admin_CancelReservation(&PatientList);
}
```
---
# Admin private Functions
##  LinkedList_Init()
### Description :
This function is used initiate Linked list 

### Syntax :
`LinkedList_Init(List_t *pList);`

### Argument :
`pList` is a pointer to the Linked List

### Return 
void 

### Example 
```c
int main()
{
    List_t List_1;
    LinkedList_Init(&List_1);
}
```
---
##  LinkedList_Insert()
### Description :
This function is used initiate Linked list 

### Syntax :
`LinkedList_Insert(List_t *pList , PatientInfo_t Data );`

### Argument :
`pList` is a pointer to the Linked List
`Data`  is a variable fron a PatientInfo_t data type wich is  
a stuct that is contains patinet info such **[Name , Gender , Age , ID , ReservationTime]**

### Return 
void 

### Example 
```c
int main()
{
    List_t List_1;
    PatientInfo_t p1 = {/* Assigne patient data */}
    LinkedList_Insert(&List_1 , P1);
}
```
---

##  GetPatientRecord()
### Description :
This function is a static function that is used to  scan a patient info from the user and assigne them in a variable from type PatientInfo_t

### Syntax :
`GetPatientRecord();`

### Argument :
void

### Return 
`PatientInfo_t` return patient info after scan them from the Admin

### Example 
```c
int main()
{
    PatientInfo_t P1;
    P1 = GetPatientRecord();
}
```
---
##  GetPatientNode()
### Description :
This function is a static function that is used to search for patient ID in the Linked list ,if ID exist return pointer to it's node else return NULL

### Syntax :
`GetPatientNode(List_t *pList , uint16_t Copy_ID)`

### Argument :
`pList` is a pointer to the Linked List
`Copy_ID` is patient ID to seacrch for it 

### Return 
void

### Example 
```c
int main()
{
    PatientInfo_t P1;
    P1 = GetPatientRecord();
}
```
---

##  DeleteElement()
### Description :
This function is a static function that is used to delete the  reserved time time from array of available slots 

### Syntax :
`DeleteElement(sint8_t **pArray , uint16_t position);`
### Argument :
`pArray` is a pointer array of string 
`position` number of element that you want to delete from array

### Return 
void

### Example 
```c
int main()
{
    sint8_t *AvaliableSlot[6] = {
                                    "From 2 To 2:30", "From 2:30 To 3",
                                    "From 3 To 3:30", "From 4 To 4:30",
                                    "From 4:30 To 5", '\0'
								};
    DeleteElement(AvaliableSlot , 3 );
}
```

---
# User Functions
---

##  User_ViewPatientRecord()
### Description :
This function is is used to View Patient Record if it excists

### Syntax :
`User_ViewPatientRecord(List_t pList);`

### Argument :
`pList` is a copy from the list of patients that you want to view patient record from it 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    User_ViewPatientRecord(PatientList);
}
```
---
##  User_ViewTodaysReservation()
### Description :
This function is used to View Todays Reservation

### Syntax :
`User_ViewTodaysReservation(List_t pList);`

### Argument :
`pList` is a copy from the list of patients 

### Return 
void 

### Example 
```c
int main()
{
    List_t PatientList;
    User_ViewTodaysReservation(PatientList);
}
```
---
