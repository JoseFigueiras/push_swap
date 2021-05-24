#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	arr[4096];

	arr[0] = INT_MIN;
	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		arr[i] = ft_atoi(argv[i]);
		if (is_in(arr[i], arr, i - 1))
			return (0);
		i++;
	}
	return (1);
}
