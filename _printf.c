#include "main.h"

/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed = 0, (*structype)(char *, va_list);
	char q[3];
	va_list pa;

	if (format == NULL)
		return (-1);
	q[2] = '\0';
	va_start(pa, format);
	_putchar(-1);
	while (format[0])
	{
		if (format[0] == '%')
		{
			structype = driver(format);
			if (structype)
			{
				q[0] = '%';
				q[1] = format[1];
				printed += structype(q, pa);
			}
			else if (format[1] != '\0')
			{
				printed += _putchar('%');
				printed += _putchar(format[1]);
			}
			else
			{
				printed += _putchar('%');
				break;
			}
			format += 2;
		}
		else
		{
			printed += _putchar(format[0]);
			format++;
		}
	}
	_putchar(-2);
	return (printed);
}
