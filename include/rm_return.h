#ifndef RM_RETURN_H
# define RM_RETURN_H

# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/stat.h>

#ifndef BUFFERSIZE
#define BUFFERSIZE 1
#endif

typedef struct s_var
{
	char	name[1024];
}t_var;

typedef struct s_lst
{
	char			*line_content;
	struct s_lst	*next;
	struct s_lst	*prev;

}t_lst;

/*****************FUNCTIONS***************/

/*******READ*****/
void	ft_read_doc(char *argv);
void	ft_set_set();

/*******NODES*****/
t_lst	*new_node(char *line);
void	addback(t_lst **head, t_lst *new);
void	free_lst(t_lst **lst);

#endif
