#include "main.h"

void print_bufer(char bufer[], int *buf_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buf_ind = 0;
	va_list list;
	char bufer[BUF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bufer[buf_ind++] = format[i];
			if (buf_ind == BUF_SIZE)
				print_bufer(bufer, &buf_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_bufer(bufer, &buf_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, bufer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_bufer(bufer, &buf_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_bufer - Prints the contents of the buffer if it exist
 * @bufer: Array of chars
 * @buf_ind: Index at which to add next char, represents the length.
 */
void print_bufer(char bufer[], int *buf_ind)
{
	if (*buf_ind > 0)
		write(1, &bufer[0], *buf_ind);

	*buf_ind = 0;
}
