#include "libft.h"

void	ft_perror_exit(const char *message)
{
	perror(message);
	exit(-1);
}
