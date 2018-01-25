#include "cor.h"

int    convert_int_from_binary(unsigned char *str)
{
    int nbr;

    nbr = str[0] << 24;
    nbr += str[1] << 16;
    nbr += str[2] << 8;
    nbr += str[3];
    return (nbr);
}