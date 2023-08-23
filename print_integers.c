#include "main.h"
#include <string.h>
/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_int (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
	long int n = 0;
	int  count = 0;
	int sign = 0;

	if (m->l == 1)
        	n = va_arg(l, long int);
	else if (m->h == 1)
        	n = (short int) va_arg(l, int);
	else if (m->hh == 1)
        	n = (signed char) va_arg(l, int);
	else
        	n = va_arg(l, int);

	count += count_signed_digits(n);
	if (n < 0 && (fld_wdth < 0 || fld_wdth < count))
	{
		sign = _putchar ('-');
	}
	
	if (prec_sn == 0)
	{
		count = 0;
		count = zero_precision(count, fld_wdth, f);
		return count;
	}
	if (prec_sn > 0 && prec_sn > count)
		count += print_padding('0', prec_sn - count);
	count += sign;
    	if (f->space == 1 && f->plus == 0  && n >= 0)
        	count  += _putchar(' ');
    	else if (f->plus == 1 &&  n >= 0)
		count += _putchar('+');
	count += apply_width_precision_2(n, f, fld_wdth, prec_sn, count);
	return (count);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of characters printed
 */
int print_unsigned (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
	unsigned long int u = 0;
 	int count = 0;
	char *str;
	if (m->l == 1)
       		 u = va_arg(l, unsigned long int);
	else if (m->h == 1)
        	u = (unsigned short int) va_arg(l, unsigned int);
	else if (m->hh == 1)
        	u = (unsigned char) va_arg(l, unsigned int);
	else
        	u = va_arg(l, unsigned int);

	str = convert(u, 10, 1);
	count = strlen(str);

	if (prec_sn > 1)
		f->zero_flag = 0;
	if (prec_sn == 0)
	{
		count = 0;
		count = zero_precision(count, fld_wdth, f);
		return count;
	}
        if (prec_sn > 1 && prec_sn > count)
            count += print_padding('0', prec_sn - count);
	

	if (f->space == 1 && f->plus == 0)
		count += _putchar(' ');
	else if (f->plus  == 1)
		count  += _putchar('+');
	count += apply_width_precision(str, f,  fld_wdth, prec_sn, count);
    return (count);
}
