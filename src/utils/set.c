#include "../../include/rm_return.h"

void	ft_set_set()
{
	char	set[1024];
	struct stat path_stat;

	while (1)
	{
		printf("Quel est le fichier à modifier ?\n");
		scanf("%1023s", set);
		if (stat(set, &path_stat) != 0)
		{
			printf("Le fichier n'existe pas ou une erreur est survenue.\n");
			continue ;
		}
		if (S_ISDIR(path_stat.st_mode))
		{
			printf("Vous avez entré un répertoire. Veuillez entrer un fichier.\n");
			continue ;
		}
		break ;
	}
	ft_read_doc(set);
}