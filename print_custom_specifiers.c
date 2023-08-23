#include "main.h"

/**
 * print_bigS - prints non-printable characters
 * (0 < ASCII value < 32 or >= 127) as \x followed by the ASCII code
 * value in hexadecimal (uppercase - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the struct len_mod that determines the length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_bigS (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        int i, count = 0;
        char *res;
        char *s = va_arg(l, char *);

        (void)f;
        (void)m;
        (void)fld_wdth;
        (void)prec_sn;

        if (!s)
                return (_puts("(null)"));

        for (i = 0; s[i]; i++)
        {
                if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
                {
                        _puts("\\x");
                        count += 2;
                        res = convert(s[i], 16, 0);
                        if (!res[1])
                                count += _putchar('0');
                        count += _puts(res);
                }
                else
                        count += _putchar(s[i]);
        }

        return (count);
}

/**
 * print_rev - prints a string in reverse
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the struct len_mod that determines the length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_rev (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        int i = 0, j = 0, k = 0;
        char *s = va_arg(l, char *);
	char *ptr = s;

        (void)f;
        (void)m;
        (void)fld_wdth;
        (void)prec_sn;

	while (*ptr)
	{
		k++;
		ptr++;
	}

        if (!s)
	{
                s = "(null)";
		i += _puts(s);
		return(i);
	}
	ptr--;
        while (j < k)
	{
                i += _putchar(*ptr--);
		j++;
	}
        return (i);
}

/**
 * print_rot13 - prints a string using the rot13 cipher
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the struct len_mod that determines the length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_rot13(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
    char *s = va_arg(l, char *);
    char *ptr = s;
    (void)f;
    (void)m;
    (void)fld_wdth;
    (void)prec_sn;

     while (*ptr)
	{
        	 if (*ptr >= 'a' && *ptr <= 'z')
                {
                        if (*ptr <= 'm')
                                *ptr += 13;
                        else
                                *ptr -= 13;

                }

                if (*ptr >= 'A' && *ptr <= 'Z')
                {
                        if (*ptr <= 'M')
                                *ptr += 13;
                        else
                                *ptr -= 13;

                }
                ptr++;

        }

    return (_puts(s));
}
/**
 * print_percent - prints a percent symbol
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines if a flag is passed to _printf
 * @m: pointer to the struct len_mod that determines the length modifiers
 * @fld_wdth: field width
 * @prec_sn: precision specifier
 *
 * Return: number of characters printed
 */
int print_percent (va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn)
{
        (void)l;
        (void)f;
        (void)m;
        (void)fld_wdth;
        (void)prec_sn;

        return (_putchar('%'));
}
