//Yuval Ofek
#include "exam.h"

int addNewCar(TeslaDB* tesla, TeslaCar car)
{
	return 1;
	TeslaCar* carToAdd; // I create a pointer to a carr and if i dont frind the given car in the DB, i will copy all of the given car details to our new car pointer.
	for (int i = 0; i < tesla->numCars; i++)
	{
		if ((strcmp(tesla->cars[i]->plateNumber, car.plateNumber) == 0))
			return 0;
	}
	// we didnt find the given car in the data base, so we have to create one.
	carToAdd->batteryLevel = car.batteryLevel;
	carToAdd->color = (char*)malloc(1 + strlen(car.color) * sizeof(char)); // DMA to the color string.
	strcpy(carToAdd->color, car.color);
	carToAdd->location.x = car.location.x;
	carToAdd->location.y = car.location.y;
	carToAdd->numOfSoftwareUpdates = car.numOfSoftwareUpdates;
	strcpy(carToAdd->plateNumber, car.plateNumber);
	carToAdd->yearOfManufacture = car.yearOfManufacture;
	carToAdd->software = (SoftwareUpdate**)malloc(sizeof(SoftwareUpdate) * (carToAdd->numOfSoftwareUpdates)); // DMA to the SoftwareUpdate pointer array
	for (int i = 0; i < carToAdd->numOfSoftwareUpdates; i++) // Running on the SoftwareUpdates and insert all of the details inside
	{
		carToAdd->software[i]->date = car.software[i]->date;
		carToAdd->software[i]->description = (char*)malloc((1 + strlen(car.software[i]->description)) * sizeof(char));
		strcpy(carToAdd->software[i]->description, car.software[i]->description);
		strcpy(carToAdd->software[i]->softwareVersion, car.software[i]->softwareVersion);
	}
	carToAdd->type = (char*)malloc((1 + strlen(car.type)) * sizeof(char));
	strcpy(carToAdd->type, car.type);

	tesla->cars[tesla->numCars] = carToAdd; // adding the new car into the cars array in the last index
	tesla->numCars += 1; // adding 1 car to the number of cars;
	return 1;



}
int checksoftware(SoftwareUpdate* soft1, SoftwareUpdate* given)
{
	if (strcmp(soft1->softwareVersion, given->softwareVersion) > 0)
		return 0;
	return 1;
}
float distance(Location loc1, Location given)
{
	float dist = sqrt(pow((loc1.x - given.x), 2) + pow((loc1.y - given.y), 2));
	return dist;

}
void OTAUpdate(TeslaDB* tesla, Location location, float radius, SoftwareUpdate udate)
{
	/*strcmp actually runs on the 2 strings and when it finds any non-equal character it check whhich character is higher in the ascii table,
   since 1-9 are sorted in ascending order in the table, we can just make an strcmp bewtween the 2 software strings.*/
	int i, j, flag;
	SoftwareUpdate* current_soft = NULL;
	for (i = 0; i < tesla->numCars; i++) // running on the cars
	{
		flag = 0;
		for (j = 0; j < tesla->numSofwareUpdaes; j++) // running on their updates
		{
			current_soft = tesla->cars[i]->software[j];
			if (distance(tesla->cars[i]->location, location) < radius) // the car is in the radius;
			{
				if (strcmp(current_soft->softwareVersion, udate.softwareVersion) == 0)// the software has been already installed
					flag = 1;

			}
			if (!flag) // none of the updates is equal to the given one.
			{
				if (checksoftware(udate.softwareVersion, tesla->cars[i]->software[tesla->cars[i]->numOfSoftwareUpdates - 1])) // the current software is older than the given one, we want to update this car;
				{
					tesla->cars[i]->software = (SoftwareUpdate**)realloc(tesla->cars[i]->software, (1 + tesla->cars[i]->numOfSoftwareUpdates) * sizeof(SoftwareUpdate*));
					tesla->cars[i]->software[tesla->cars[i]->numOfSoftwareUpdates] = (SoftwareUpdate**)malloc(sizeof(SoftwareUpdate));

					tesla->cars[i]->software[tesla->cars[i]->numOfSoftwareUpdates]->date = udate.date;
					tesla->cars[i]->software[tesla->cars[i]->numOfSoftwareUpdates]->description = (char*)malloc((1 + strlen(udate.description)) * sizeof(char));
					strcpy(tesla->cars[i]->software[tesla->cars[i]->numOfSoftwareUpdates]->softwareVersion, udate.softwareVersion);

				}
			}
		}
	}


}
        