#ifndef LIST_GENERATOR_H
# define LIST_GENERATOR_H

# include <stdlib.h>

/* Linked List Struct */

typedef struct s_ll
{
	void		*content;
	struct s_ll	*next;
}	t_ll;

/* Doubly Linked List Struct */

typedef struct s_dll
{
	void			*content;
	struct	s_dll	*previous;
	struct	s_dll	*next;
}	t_dll;

/* Linked List Functions */

void	add_node(t_ll *ll);
void	destroy_linked_list(t_ll *ll);
void	destroy_linked_list_content(t_ll *ll);
void	initialize_linked_list(t_ll *ll);
t_ll	*linked_list_generator(int length);

/* Doubly Linked List Functions */

void	initialize_doubly_linked_list(t_dll *dll);
void	add_next_node(t_dll *dll);
void	add_previous_node(t_dll *dll);
void	destroy_doubly_linked_list_content(t_dll *dll);
void	destroy_doubly_linked_list(t_dll *dll);
t_dll	*doubly_linked_list_generator(int lengthbackward, int lengthforward);

#endif