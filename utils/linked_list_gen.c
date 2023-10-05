#include "../include/list_generator.h"

void	add_node(t_ll *ll)
{
	t_ll	*newnode;

	if (ll == NULL)
		return ;
	newnode = (t_ll *)malloc(sizeof(t_ll));
	if (newnode == NULL)
		return ;
	newnode->content = NULL;
	newnode->next = NULL;
	ll->next = newnode;
	return ;
}

void	destroy_linked_list_content(t_ll *ll)
{
	if (ll == NULL)
		return ;
	if (ll->content != NULL)
		free(ll->content);
	return ;
}

void	destroy_linked_list(t_ll *ll)
{
	t_ll	*temp;

	if (ll == NULL)
		return ;
	while (ll != NULL)
	{
		temp = ll;
		ll = ll->next;
		destroy_linked_list_content(temp);
		free(temp);
	}
	return ;
}

void	initialize_linked_list(t_ll *ll)
{
	if (ll == NULL)
		return ;
	ll->content = NULL;
	ll->next = NULL;
	return ;
}

t_ll	*linked_list_generator(int length)
{
	t_ll	*ll;
	t_ll	*temp;

	if (length < 1)
		return (NULL);
	ll = (t_ll *)malloc(sizeof(t_ll));
	if (ll == NULL)
		return (NULL);
	if (length == 1)
		return (ll);
	initialize_linked_list(ll);
	temp = ll;
	while (length-- > 1)
	{
		add_node(ll);
		if (ll->next == NULL)
			return (destroy_linked_list(ll), NULL);
		ll = ll->next;
	}
	return (temp);
}
