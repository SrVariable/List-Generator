#include "../include/list_generator.h"
#include <stdio.h>

int	main(void)
{
	int		lenghtbackwards;
	int		lenghtafterwards;
	t_dll	*doublylinkedlist;

	printf("Introduce the lenght of your doubly linked list backwards: ");
	scanf("%d", &lenghtbackwards);
	printf("Introduce the lenght of your doubly linked list afterwards: ");
	scanf("%d", &lenghtafterwards);
	doublylinkedlist = doubly_linked_list_generator(lenghtbackwards, lenghtafterwards);
	if (doublylinkedlist == NULL)
		return (1);
	destroy_doubly_linked_list(doublylinkedlist);
	return (0);
}