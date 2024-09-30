#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;
	//t_list	temp_node;
	//t_list	*curr_node;

	size = 0;
	/* curr_node->next = lst;
	while(curr_node->next != NULL)
	{
		temp_node = curr_node;
		curr_node->next = temp_node.next;
		size++;
	} */
	return (size);
}
