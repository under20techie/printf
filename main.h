#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
/**
 * struct flags - struct containing all posible  flag characters when a flag specifier is passed to _printf()
 * @plus: flag for the '+' flag character
 * @space: flag for the ' '  flag character
 * @hash: flag for the '#'  flag character
 */
typedef struct flags
{
        int plus;
        int space;
        int hash;
        int zero_flag;
        int dash_flag;
} flags_t;

typedef struct len_modifiers
{
        int h;
        int hh;
        int l;
        int j;
        int t;
        int z;
} len_mod;
/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
        char c;
        int (*f)(va_list ap, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
} ph;

/* print_nums */
int print_int(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_unsigned(va_list l, flags_t *f,len_mod *m, int fld_wdth, int prec_sn);

/* print_bases */
int print_hex(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_hex_big(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_binary(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_octal(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_char(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_n (va_list l, int count);
/* write_funcs */
int _putchar(char c);
int _puts(char *str);
int _strlen (char *s);
/* print_custom */
int print_rot13(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_rev(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_bigS(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* print_address */
int print_address(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* print_percent */
int print_percent(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* check if format char is a digit */
int is_digit (char c);

/* get length  modifier */
int get_mod (char s, len_mod *m);

/* print unsigned long, signed long and an octal */
int print_ld(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_lo(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);
int print_lu(va_list l, flags_t *f, len_mod *m, int fld_wdth, int prec_sn);

/* helper functions */
int apply_width_precision_2(long int n, flags_t *f, int fld_wdth, int prec_sn, int no_ofchar);
int apply_width_precision(char *str, flags_t *f, int fld_wdth, int prec_sn, int no_ofchar);
int apply_str(char *str, flags_t *f, int fld_wdth, int no_ofchar);
void print_number(long int n);
int print_padding(char c, int n);
int count_signed_digits(long int n);
int count_unsigned_digits(unsigned long int n);
void initialize_variables(flags_t *flags, len_mod *mod_f);
int apply_char(int c, flags_t *f, int fld_wdth, int no_ofchar);
int zero_precision(int count, int fld_wdth, flags_t *f);

#endif
