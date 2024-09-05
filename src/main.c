# include "../include/rm_return.h"

int	main(int arc, char **argv)
{
	if (arc < 2)
		ft_set_set();
	else if (access(argv[1], F_OK) == -1)
	{
		printf("Le fichier n'existe pas.\n");
		ft_set_set();
	}
	else
		ft_read_doc(argv[1]);
	printf("\033[0;32mfait ✅\033[0m\n");
	return (0);
}