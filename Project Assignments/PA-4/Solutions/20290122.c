#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//Structures created for storing data
struct Flight_details
{
    int flight_numbers;
    char departure_city[15];
    char arrival_city[15];
    char departure_day[15];
    char departure_time[15];
    char arrival_day[15];
    char arrival_time[15];
};

struct Passengers
{
    int flight_numbers;
    char name[15];
    char surname[15];
    char departure_city[15];
    char arrival_city[15];
    char departure_day[15];
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//Funtion prototypes
void addFlight(struct Flight_details *flights, int i);
void make_reservation(struct Flight_details *flights, struct Passengers *passengers, int i, int number);
void searcFlight(struct Flight_details *flights, struct Passengers *passengers, int number);
void printFlight(struct Flight_details *flights, struct Passengers *passengers, int number);
void printWithPerson(struct Flight_details *flights, struct Passengers *passengers, int number);
void printReservation(struct Flight_details *flights, struct Passengers *passengers, int number);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//Main function
int main()
{/*
    #ifndef ONLINE_JUDGE
  
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    #endif*/
    struct Flight_details *flights;
    struct Passengers *passengers;
    int number_of_flights, number_of_passengers;
    char commands[10], endcom[4] = "END";
    
    if (scanf("%d", &number_of_flights)==EOF) exit(0);

    flights = (struct Flight_details*) malloc(number_of_flights * sizeof(struct Flight_details));

    for (int i = 0; i < number_of_flights; i++)
    {
        addFlight(flights, i);
    }

    scanf("%d", &number_of_passengers);

    passengers = (struct Passengers*) malloc(number_of_passengers * sizeof(struct Passengers));

    for (int i = 0; i < number_of_passengers; i++)
    {
        scanf("%s %s %s %s %s", (passengers+i)->name, (passengers+i)->surname, (passengers+i)->departure_city, (passengers+i)->arrival_city, (passengers+i)->departure_day);        
        make_reservation(flights, passengers, i, number_of_flights);
    }

    while (1)
    {
        scanf("%s", commands);
        if (strcmp(commands, endcom)==0) break;
        if (strcmp(commands, "search") == 0) searcFlight(flights, passengers, number_of_flights);           
        else if (strcmp(commands, "print") == 0) printFlight(flights, passengers, number_of_flights);
        else if (strcmp(commands, "printR") == 0) printReservation(flights, passengers, number_of_flights);
        else if (strcmp(commands, "printwP") == 0) printWithPerson(flights, passengers, number_of_flights);
    }
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that adds Flight to the system
void addFlight(struct Flight_details *flights, int i)
{
    scanf("%d %s %s %s %s %s %s", &(flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
    (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that makes reservation for passengers
void make_reservation(struct Flight_details *flights, struct Passengers *passengers, int i, int number)
{
    int counter = 0; 
    int found = 0;
    while (counter<=number)
    {
        if (strcmp((passengers+i)->departure_city, (flights+counter)->departure_city) == 0 && strcmp((passengers+i)->arrival_city, (flights+counter)->arrival_city) == 0
        && strcmp((passengers+i)->departure_day, (flights+counter)->departure_day) == 0)
        {
            found = 1;
            (passengers+i)->flight_numbers = (flights+counter)->flight_numbers;
            break;
        }
        counter++;
    }
    if (found == 0)
    {
        printf("%s %s %s %s %s ", (passengers+i)->name, (passengers+i)->surname, (passengers+i)->departure_city, (passengers+i)->arrival_city, (passengers+i)->departure_day);
        printf("No reservation\n\n");
    }    
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that Searches for Flight details
void searcFlight(struct Flight_details *flights, struct Passengers *passengers, int number)
{
    char new_command[20];
    scanf("%s", new_command);
    if (strcmp(new_command, "flightNumber") == 0)
    {
        int flight_num = 0, found = 0;
        scanf("%d", &flight_num);
        for (int i = 0; i < number; i++)
        {
            if ((flights+i)->flight_numbers == flight_num)
            {
                printf("%d %s %s %s %s %s %s\n\n", (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
                (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);
                found = 1;
                break;
            }
        }
        if (found == 0) printf("No flight with number %d\n\n", flight_num);        
    }
    else if (strcmp(new_command, "departure") == 0)
    {
        char dep_city[15];
        int found = 0;
        scanf("%s", dep_city);
        for (int i = 0; i < number; i++)
        {
            if (strcmp((flights+i)->departure_city, dep_city) == 0)
            {
                printf("%d %s %s %s %s %s %s\n", (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
                (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);
                found = 1;
            }
        }
        if (found == 0) printf("No departure city %s\n\n", dep_city);
        else printf("\n");
    }
    else if (strcmp(new_command, "arrival") == 0)
    {
        char arrive_city[15];
        int found = 0;
        scanf("%s", arrive_city);
        for (int i = 0; i < number; i++)
        {
            if (strcmp((flights+i)->arrival_city, arrive_city) == 0)
            {
                printf("%d %s %s %s %s %s %s\n", (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
                (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);
                found = 1;
            }
        }
        if (found == 0) printf("No arrival city %s\n\n", arrive_city);
        else printf("\n");
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that prints Flight details
void printFlight(struct Flight_details *flights, struct Passengers *passengers, int number)
{   
    int flight_num, counter = 0, found = 0;
    scanf("%d", &flight_num);
    for (int i = 0; i < number; i++)
    {
        if (found==0 && flight_num == (flights+i)->flight_numbers)
        {
            printf("%d %s %s %s %s %s %s", (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
            (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);    
            found = 1;
        }
        if (flight_num == (passengers+i)->flight_numbers)
        {
            counter++;
        }
    }
    printf(" %d\n\n", counter);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that prints Flight details with Passenger info
void printWithPerson(struct Flight_details *flights, struct Passengers *passengers, int number)
{
    int flight_num, counter = 0, found = 0;
    char people[100][2][15];
    scanf("%d", &flight_num);
    for (int i = 0; i < number; i++)
    {
        if (found==0 && flight_num == (flights+i)->flight_numbers)
        {
            printf("%d %s %s %s %s %s %s", (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, (flights+i)->departure_day,
            (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);    
            found = 1;
        }
        if (flight_num == (passengers+i)->flight_numbers)
        {
            strcpy(people[counter][0], (passengers+i)->name);
            strcpy(people[counter][1], (passengers+i)->surname);
            counter++;
        }
    }
    printf(" %d\n", counter);
    if (counter>0)
    {
        for (int k = 0; k < counter; k++)
        {
            printf("%s %s\n", people[k][0], people[k][1]);
        }           
    }
    printf("\n");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//The function that prints the Passenger info and Reserved Flight details
void printReservation(struct Flight_details *flights, struct Passengers *passengers, int number)
{
    char nm[15], srnm[15];
    scanf("%s %s", nm, srnm);
    for (int k = 0; k < number; k++)
    {
        if ((strcmp(nm, (passengers+k)->name) == 0) && (strcmp(srnm, (passengers+k)->surname) == 0))
        {
            for(int i=0; i < number; i++)
            {
                if ((passengers+k)->flight_numbers == (flights+i)->flight_numbers)
                {
                    printf("%s %s %d %s %s %s %s %s %s\n\n", nm, srnm, (flights+i)->flight_numbers, (flights+i)->departure_city, (flights+i)->arrival_city, 
                    (flights+i)->departure_day, (flights+i)->departure_time, (flights+i)->arrival_day, (flights+i)->arrival_time);
                    break;    
                }
            }
            break;
        }
    }
}