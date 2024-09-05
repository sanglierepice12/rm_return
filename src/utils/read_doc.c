#include "../../include/rm_return.h"

void	ft_put_in_doc(char *dupi, t_var *var)
{
	char	name[1024]/* = "sortie"*/;
	int		fd;
	(void)name;

	printf("Quel est le nom du fichier de sortie ?\n");
	scanf("%1023s", var->name);
	fd = open(var->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror(""));
	dprintf(fd, "%s", dupi);
	close(fd);
}

void	ft_rm_back(char *dest)
{
	size_t i;

	i = 0;
	while (dest[i])
	{
		if (dest[i] == '\n')
			dest[i] = ' ';
		i++;
	}
}

void	ft_put_in_char(t_lst **document, t_var *var)
{
	t_lst	*temp;
	char	*dup;
	size_t	len;

	temp = *document;
	len = 0;
	while (temp->next)
	{
		len += (size_t)strlen(temp->line_content);
		temp = temp->next;
	}
	while (temp->prev)
		temp = temp->prev;
	dup = calloc(len + 1, sizeof(char));
	if (!dup)
		return (perror(""));
	while (temp->next)
	{
		dup = strcat(dup, temp->line_content);
		if (!dup)
			return (perror(""));
		temp = temp->next;
	}
	ft_rm_back(dup);
	ft_put_in_doc(dup, var);
	free(dup);
}

void	ft_read_doc(char *argv)
{
	int		fd, bytes_read;
	char	buf[BUFFERSIZE + 1], response[1024] = "coucou";
	t_lst	*document;
	t_var	var;

	memset(buf, 0, sizeof(buf));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (perror(""));
	document = NULL;
	while ((bytes_read = read(fd, buf, BUFFERSIZE)))
	{
		buf[bytes_read] = '\0';
		addback(&document, new_node(buf));
	}
	addback(&document, new_node(buf));
	if (bytes_read < 0)
		return (close(fd), free_lst(&document), perror(""));
	ft_put_in_char(&document, &var);
	if (strcmp(var.name, argv))
	{
		printf("Supprimer le fichier source ?\n");
		scanf("%1023s", response);
		while (1)
		{
			if (!strcmp(response, "oui"))
				break;
			if (!strcmp(response, "non"))
				break;
			printf("Supprimer le fichier source ? oui / non\n");
			scanf("%1023s", response);
		}
		if (!strcmp(response, "oui"))
			unlink(argv);
	}
	close(fd), free_lst(&document);
}