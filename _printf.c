#include "main.h"
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int (*print_func)(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
        const char *fmt_str;
	va_list var_args;
    	int count = 0, fld_wdth = 0, prec_sn = 1;
    	flags_t flags;
    	len_mod mod_f;
    	va_start(var_args, format);


    	if (!format || (format[0] == '%' && !format[1]))
        	return (-1);
    	if (format[0] == '%' && format[1] == ' ' && !format[2])
        	return (-1);
    	for (fmt_str = format; *fmt_str; fmt_str++)
    	{
        	initialize_variables(&flags, &mod_f);
        	fld_wdth = 0, prec_sn = 1;
        	if (*fmt_str == '%')
        	{
            		fmt_str++;
            	if (*fmt_str == '%')
            	{
                	count += _putchar('%');
                	continue;
            	}
	    	if (*fmt_str == 'n')
            	{
                	print_n(var_args, count);
                	continue;
            	}
            	while (get_flag(*fmt_str, &flags))
                	fmt_str++;
            	if (is_digit(*fmt_str))
            	{
                	fld_wdth = ((*fmt_str) - '0');
                	fmt_str++;
            	}
            	else if (*fmt_str == '*')
            	{
                	fld_wdth = va_arg(var_args, int);
                	fmt_str++;
            	}
	    	if (fld_wdth < 0)
	    	{
			flags.dash_flag = 1;
			fld_wdth *= -1;
			fmt_str++;
	    	}
            	if (*fmt_str == '.')
            	{
                	fmt_str++;
                if (is_digit(*fmt_str))
                {

                    	prec_sn = ((*fmt_str) - '0');
                    	fmt_str++;
                }
                else if (*fmt_str == '*')
                {
                    	prec_sn = va_arg(var_args, int);
		    	fmt_str++;
                }
		else
		{
		   	prec_sn = 1;
            	}
		}
          	while (get_mod(*fmt_str, &mod_f))
	  	{
                	fmt_str++;
	  	}
          	print_func = get_print(*fmt_str);
          	count += (print_func) ? print_func(var_args, &flags, &mod_f, fld_wdth, prec_sn):
			_printf("%%%c",*fmt_str);
	 	}
        	else
		{
            		count += _putchar(*fmt_str);
		}
	}
    	_putchar(-1);
    	va_end(var_args);
    	return count;
}
