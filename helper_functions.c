#include "main.h"
#include <string.h>
/**:w
 * print_padding - prints padding characters
 * @c: the character to print
 * @n: the number of times to print the character
 *
 * Return: number of characters printed
 */
int print_padding (char c, int n)
{
        int count = 0;
	int i = 0;
        for (i = 0; i < n; i++)
                count += _putchar(c);

        return count;
}
/**
 * count_signed_digits - counts the number of digits in a signed decimal number
 * @n: the signed decimal number
 * Return: the number of digits
 */
int count_signed_digits (long int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

/**
 * count_unsigned_digits - counts the number of digits in an unsigned decimal number
 * @n: the unsigned decimal number
 * Return: the number of digits
 */
int count_unsigned_digits (unsigned long int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}
/**
 * print_number - helper function that loops through
 * an integer and prints all its digits using recursion.
 * @n: integer to be printed
 */
void print_number (long int n)
{
	unsigned long int n1 = 0;

        if (n < 0 )
	{
                n1 = -n;
	}
        else
                n1 = n;

        if (n1 / 10)
	{
                print_number(n1 / 10);
	}
        _putchar ((n1 % 10) + '0');
}

int apply_width_precision (char *str, flags_t *f, int fld_wdth, int prec_sn, int  no_ofchar)
{
        int count = 0;
        int padding = ' ';
	(void)prec_sn;

        if (fld_wdth > no_ofchar  && f->dash_flag != 1 && f->zero_flag == 1)
	{
		count += print_padding('0', fld_wdth - no_ofchar);
		 _puts(str);
		return (count);
	}
	if (fld_wdth > no_ofchar && f->dash_flag == 0  && f->zero_flag == 0)
        {
		count += print_padding(padding, fld_wdth - no_ofchar);
		_puts(str);
                return (count);
        }
        if (fld_wdth > no_ofchar  && f->dash_flag == 1)
	{
		_puts(str);
		count += print_padding(padding, fld_wdth - no_ofchar);
	}
	if (count == 0)
	{
		_puts(str);
	}	
        return (count);
}
