#ifndef AEROFLOT_H
#define AEROFLOT_H

#define STRING_SIZE 256

typedef unsigned int uint;
typedef struct {
	char destination[STRING_SIZE];
	uint flight_number;
	char aircraft_type[STRING_SIZE];
	uint employed_seats;
	uint seats;
} Aeroflot;

#endif // AEROFLOT_H
