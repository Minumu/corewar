#include "../asm.h"

void    get_magic(t_asm *asem, unsigned int i)
{
    int k;
    int bytes;

    k = 0;
    bytes = 24;
    while (k < 4)
    {
        asem->magic[k] = (i >> bytes) & 0xFF;
        k++;
        bytes -= 8;
    }
}