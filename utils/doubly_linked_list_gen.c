#include "../include/list_generator.h"

void	initialize_doubly_linked_list(t_dll *dll)
{
	if (dll == NULL)
		return ;
	dll->content = NULL;
	dll->previous = NULL;
	dll->next = NULL;
	return ;
}

void	add_next_node(t_dll *dll)
{
	t_dll	*newnode;

	if (dll == NULL)
		return ;
	newnode = (t_dll *)malloc(sizeof(t_dll));
	if (newnode == NULL)
		return ;
	newnode->next = NULL;
	newnode->content = NULL;
	newnode->previous = dll;
	dll->next = newnode;
}

void	add_previous_node(t_dll *dll)
{
	t_dll	*newnode;

	if (dll == NULL)
		return ;
	newnode = (t_dll *)malloc(sizeof(t_dll));
	if (newnode == NULL)
		return ;
	newnode->next = dll;
	newnode->content = NULL;
	newnode->previous = NULL;
	dll->previous = newnode;
}

void	destroy_doubly_linked_list_content(t_dll *dll)
{
	if (dll == NULL)
		return ;
	if (dll->content != NULL)
		free(dll->content);
	return ;
}

void	destroy_doubly_linked_list(t_dll *dll)
{
	t_dll *temp;
	
	if (dll == NULL)
		return ;
	temp = dll->previous;
	while (temp != NULL)
	{
		dll = dll->previous;
		temp = dll->previous;
	}
	while (dll != NULL)
	{
		temp = dll;
		dll = dll->next;
		destroy_doubly_linked_list_content(temp);
		free(temp);
	}
	return ;
}

t_dll	*doubly_linked_list_generator(int lengthbackward, int lengthforward)
{
	t_dll	*dll;
	t_dll	*temp;

	if ((lengthbackward < 0 && lengthforward < 0))
		return (NULL);
	dll = (t_dll *)malloc(sizeof(t_dll));
	if (dll == NULL)
		return (NULL);
	initialize_doubly_linked_list(dll);
	if (lengthbackward == 0 && lengthforward == 0)
		return (dll);
	temp = dll;
	while (lengthbackward-- > 0)
	{
		add_previous_node(dll);
		if (dll->previous == NULL)
			return (destroy_doubly_linked_list(dll), NULL);
		dll = dll->previous;
	}
	while (lengthforward-- > 0)
	{
		add_next_node(temp);
		if (temp->next == NULL)
			return (destroy_doubly_linked_list(dll), NULL);
		temp = temp->next;
	}
	return (dll);
}
