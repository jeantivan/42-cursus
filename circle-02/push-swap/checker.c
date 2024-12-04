#include "push_swap.h"
#include "get_next_line.h"


int	main(void)
{
	char	*line;
	int		i;

	line = get_next_line(0);
	i = 0;
	while (line)
	{
		ft_printf("Line %i: %s", i, line);
		gnl_safe_free((void **)&line);
		line = get_next_line(0);
		i++;
	}
	return (0);
}
