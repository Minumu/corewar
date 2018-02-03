#include "asm.h"

int     main(int ac, char **av)
{
    int fd;
    t_asm *asem;

    init_struct(&asem);
    fd = open(av[ac - 1], O_RDONLY);
    if (ac < 2)
        error_usage();
    if (!check_filename(av[ac - 1], asem) || fd < 0)
        error_name(av, ac);
    if (ft_strequ("-a", av[1]))
        asem->print = 1;
    if (!validation(fd, 0, asem))
        ft_put_error("Validation Error");
    generate_bytecode(asem);
}