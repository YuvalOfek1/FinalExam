#ifndef EXAM_H_
#define EXAM_H_

#ifndef NULL
#define NULL 0
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Q1
#define ROWS 5
#define COLS 10


typedef struct
{
	int x, y;
}Location;

typedef struct
{
	int day, month, year;
}Date;

typedef struct
{
	char softwareVersion[20];
	Date date;
	char* description;
}SoftwareUpdate;

typedef struct
{
	char* type;
	char* color;
	char plateNumber[10];
	int yearOfManufacture;
	SoftwareUpdate** software;
	int numOfSoftwareUpdates;
	int batteryLevel;
	Location location;
}TeslaCar;

typedef struct
{
	TeslaCar** cars;
	int numCars;
	SoftwareUpdate** updates;
	int numSofwareUpdaes;

}TeslaDB;



//Q1
int* FromMatToArr(int matrix[][COLS], int rows, int cols, int* rsize);
//Q2
int replaceDigit(int num);
void fx1();

//Q3

int addNewCar(TeslaDB* tesla, TeslaCar car);
void OTAUpdate(TeslaDB* tesla, Location location, float radius, SoftwareUpdate udate);


#endif