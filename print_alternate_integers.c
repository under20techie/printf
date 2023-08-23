#include "main.h"
#include <string.h>
/**
 * print_hex - prints a number in hexadecimal base, in lowercase
 * @l: the va_list containing the number to print
 * @f: pointer to the flags struct
 * @m: pointer to the length modifier struct
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_hex (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
	unsigned long  int num;
	char *str;
        int count = 0;

        if (m->l == 1)
        	num = va_arg(l, unsigned long);
        else if (m->h == 1)
                num = (unsigned short)va_arg(l, unsigned int);
        else if (m->hh == 1)
                num = (unsigned char)va_arg(l, unsigned int);
        else if (m->z == 1)
                num = va_arg(l, size_t);
        else
                num = va_arg(l, unsigned int);
	
        str = convert(num, 16, 1);
	count += strlen (str);

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

	if (f->space == 1 && f->plus  == 0)
         	count += _putchar(' ');
	else if (f->plus == 1)
            	count += _putchar('+');
	if (f->hash == 1 && str[0] != '0')
                count += _puts("0x");

        count += apply_width_precision(str, f, fld_wdth, prec_sn, count);
        return count;
}

/**
 * print_hex_big - prints a number in hexadecimal base, in uppercase
 * @l: the va_list containing the number to print
 * @f: pointer to the flags struct
 * @m: pointer to the length modifier struct
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_hex_big (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        unsigned long int num;
        char *str;
        int count = 0;

        if (m->l == 1)
                num = va_arg(l, unsigned long);
        else if (m->h == 1)
                num = (unsigned short)va_arg(l, unsigned int);
        else if (m->hh == 1)
                num = (unsigned char)va_arg(l, unsigned int);
        else if (m->z == 1)
                num = va_arg(l, size_t);
        else
                num = va_arg(l, unsigned int);
	
        str = convert(num, 16, 0);
	count += strlen(str);


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

	if (f->space == 1 && f->plus  == 0)
                count += _putchar(' ');
        else if (f->plus == 1)
                count += _putchar('+');
        
        if (f->hash == 1 && str[0] != '0')
                count += _puts("0X");

        count += apply_width_precision(str, f, fld_wdth, prec_sn, count);
        return count;
}

/**
 * print_binary - prints a number in base 2
 * @l: the va_list containing the number to print
 * @f: pointer to the flags struct
 * @m: pointer to the length modifier struct
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_binary (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        unsigned long int num;
        char *str;
        int count = 0;

        if (m->l == 1)
                num = va_arg(l, unsigned long);
        else if (m->h == 1)
                num = (unsigned short)va_arg(l, unsigned int);
        else if (m->hh == 1)
                num = (unsigned char)va_arg(l, unsigned int);
        else if (m->z == 1)
                num = va_arg(l, size_t);
        else
                num = va_arg(l, unsigned int);
        str = convert(num, 2, 1);
	count += strlen(str);

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

	if (f->space == 1 && f->plus  == 0)
                count += _putchar(' ');
        else if (f->plus == 1)
                count += _putchar('+');
	if (f->hash == 1 && str[0] != '0')
                count += _puts("ob");
        count += apply_width_precision(str, f, fld_wdth, prec_sn, count);
        return count;
}

/**
 * print_octal - prints a number in base 8
 * @l: the va_list containing the number to print
 * @f: pointer to the flags struct
 * @m: pointer to the length modifier struct
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_octal (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        unsigned long int num;
        char *str;
        int count = 0;

        if (m->l == 1)
                num = va_arg(l, unsigned long);
        else if (m->h == 1)
                num = (unsigned short)va_arg(l, unsigned int);
        else if (m->hh == 1)
                num = (unsigned char)va_arg(l, unsigned int);
        else if (m->z == 1)
                num = va_arg(l, size_t);
        else
                num = va_arg(l, unsigned int);
        str = convert(num, 8, 1);
	count += strlen(str);

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

	if (f->plus == 1 && f-> space == 0)
                count += _putchar('+');
        else if (f->space == 1)
                count += _putchar(' ');
        if (f->hash == 1 && str[0] != '0')
                count += _putchar('0');

        count += apply_width_precision(str, f, fld_wdth, prec_sn, count);
        return count;
}
