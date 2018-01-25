#include "cor.h"

int main(int ac, char **av)
{
    t_cor *cor;
    init_struct(&cor);
    parse_arg(av, cor);
    create_arena(cor);
//    init_great_war(cor);
    start_ncurses(cor);

//    int i = 0;
//    int x = 0;
//    while (i < MEM_SIZE)
//    {
//        x++;
//        if (cor->map[i].cell == 0)
//            printf("%02x ",cor->map[i].cell);
//        else
//            printf("\033[31m%02x\033[0m ", cor->map[i].cell);
//        if (x >= 64)
//        {
//            x = 0;
//            printf("\n");
//        }
//        i++;
//    }
}