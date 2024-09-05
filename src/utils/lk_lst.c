#include "../../include/rm_return.h"

void	free_lst(t_lst **lst)
{
	t_lst	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->line_content)
			free((*lst)->line_content);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
}

t_lst	*lst_last(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	addback(t_lst **head, t_lst *new)
{
	t_lst	*last;

	if (*head)
	{
		last = lst_last(*head);
		last->next = new;
		new->prev = last;
	}
	else
		*head = new;
}

t_lst	*new_node(char *line)
{
	t_lst	*document;

	document = calloc(1, sizeof(t_lst));
	if (!document)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (line)
		document->line_content = strdup(line);
	document->next = NULL;
	document->prev = NULL;
	return (document);
}