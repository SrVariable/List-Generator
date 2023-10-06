#include "../include/list_generator.h"
#include <stdio.h>

int	main(void)
{
	int		lengthbackwards;
	int		lengthafterwards;
	t_dll	*doublylinkedlist;

	printf("Introduce the length of your doubly linked list backwards: ");
	scanf("%d", &lengthbackwards);
	printf("Introduce the length of your doubly linked list afterwards: ");
	scanf("%d", &lengthafterwards);
	doublylinkedlist = doubly_linked_list_generator(lengthbackwards, lengthafterwards);
	if (doublylinkedlist == NULL)
		return (1);
	destroy_doubly_linked_list(doublylinkedlist);
	return (0);
}