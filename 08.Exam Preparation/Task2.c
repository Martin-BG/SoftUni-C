/*Task 2
You must create a program that is checking which amongst
10 vehicles has most power. User inputs data in format
"$vehicleName $horsePower $torque\n" and at the end the
program shall display the name of the vehicle with most HP.
If there are 2 vehicles with equal most HP, the one with
more torque should be present.*/

#include <stdio.h>

#define MAX_NAME_LEN 50
#define VEHICLES 10

typedef struct
{
    char vehicle_name[MAX_NAME_LEN];
    float horse_power;
    float torque;
} Vehicle;

int main(void)
{
    Vehicle vehicles[VEHICLES];
    int index;
    for (index = 0; index < VEHICLES; index++)
    {
        scanf("%s %f %f",
              &vehicles[index].vehicle_name,
              &vehicles[index].horse_power,
              &vehicles[index].torque);

    }

    Vehicle most_powerful = vehicles[0];

    for (index = 1; index < VEHICLES; index++)
    {
        if(vehicles[index].horse_power > most_powerful.horse_power)
        {
            most_powerful = vehicles[index];
        }
        else if (vehicles[index].horse_power == most_powerful.horse_power
                 && vehicles[index].torque > most_powerful.torque )
        {
            most_powerful = vehicles[index];
        }
    }

    printf("%s", most_powerful.vehicle_name);

    return 0;
}
