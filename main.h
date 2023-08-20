#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>



/* SIZES */

#define S_LONG 2

#define S_SHORT 1



/* width handler */

int handle_write_char(char c, char buffer[],

	int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],

	int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,

	int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,

	int width, int flags, char padd, char extra_c, int padd_start);



int write_unsgnd(int is_negative, int ind,

char buffer[],

	int flags, int width, int precision, int size);





/****************** UTILS ******************/

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);



long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);
