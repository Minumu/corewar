#include "cor.h"

int    parse_prog_comment(t_cor *cor, int nb, char *content, int move)
{
    int i;

    i = 0;
    while (i < COMMENT_LENGTH)
    {
        cor->players[nb].comment[i] = content[i + move];
        i++;
    }
    return (i);
}

void   parse_program(t_cor *cor, int nb, char *content, int move)
{
    int i;

    i = 0;
    cor->players[nb].program = ft_strnew(cor->players[nb].prog_size) + 1;
    while (i < (int)cor->players[nb].prog_size)
    {
        cor->players[nb].program[i] = content[i + move];
        i++;
    }
}

int    parse_prog_size(t_cor *cor, int nb, char *content, int move)
{
    int i;
    int size;

    i = 0;
    while (i < 4)
    {
        cor->players[nb].size_bin[i] = (unsigned char) content[i + move];
        i++;
    }
    size = convert_int_from_binary(cor->players[nb].size_bin);
    cor->players[nb].prog_size
            = cor->players[nb].prog_size = (unsigned)size;
    return (i);
}

int    parse_prog_name(t_cor *cor, int nb, char *content, int move)
{
    int i;

    i = 0;
    while (i < PROG_NAME_LENGTH)
    {
        cor->players[nb].prog_name[i] = content[i + move];
        i++;
    }
    return (i);
}

void    parse_magic_number(t_cor *cor, int nb, char *content)
{
    int i;

    i = 0;
    while (i < 4)
    {
        cor->players[nb].magic_bin[i] = (unsigned char) content[i];
        i++;
    }
    cor->players[nb].magic_bin[i] = '\0';
    cor->players[nb].magic =
            (unsigned int) convert_int_from_binary(cor->players[nb].magic_bin);
}