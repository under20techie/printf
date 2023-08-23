#include "main.h"


int get_mod(char s, len_mod *m)
{

        int bool_flag  = 0;
        if (s == 'h' && m->h == 1)
        {
                m->hh = 1;
                m->h = 0;
                bool_flag = 1;
                return(bool_flag);
        }
        switch(s)
        {
                case 'h':
                        m->h = 1;
                        bool_flag = 1;
                        break;
                case 'l':
                        m->l = 1;
                        bool_flag = 1;
                        break;
                case 'j':
                        m->j = 1;
                        bool_flag = 1;
                        break;
                case 't':
                        m->t = 1;
                        bool_flag = 1;
                        break;
                case 'z':
                        m->z = 1;
                        bool_flag = 1;
                        break;

        }

return (bool_flag);

}
