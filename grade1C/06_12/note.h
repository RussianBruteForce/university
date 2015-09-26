#ifndef NOTE_H
#define NOTE_H

#define STRING_SIZE 256

typedef unsigned int uint;
typedef short unsigned int date_t[3];
typedef struct {
	char surname[STRING_SIZE];
	char name[STRING_SIZE];
	uint phone_number;
	date_t birthday; // format {day,month,year}
} Note;

#endif //NOTE_H
