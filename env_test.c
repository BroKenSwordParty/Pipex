#include "stdio.h"
#include "unistd.h"

int	main (int ac, char **av, char **env)
{
	int	i = 0;
	int	j = 0;
	while (env[j])
	{
		i = 0;
		while (env[j][i])
		{
			printf("%c", env[j][i]);
			i ++;
		}
		j++;
	}
	return(0);
}