#include "../include/list_generator.h"
#include <stdio.h>

int	main(void)
{
	int		length;
	t_ll	*linkedlist;

	printf("Introduce the length of your linked list: ");
	scanf("%d", &length);
	linkedlist = linked_list_generator(length);
	if (linkedlist == NULL)
		return (1);
	destroy_linked_list(linkedlist);
	return (0);
}
