#include "cor.h"

int main(int ac, char **av)
{
    ac = 0;
    t_cor *cor;
    init_struct(&cor);
    parse_arg(av, cor);
    create_arena(cor);
    if (cor->n == 1)
        init_ncurses(cor);
    corewar(cor);

}