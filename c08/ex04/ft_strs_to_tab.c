#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	 
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		len;

	len = ft_strlen(str);
	copy = malloc(sizeof(char) * (len));
	if (!copy)
		return (NULL);
	len = 0;
	while (str[len])
	{
		copy[len] = str[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	struct s_stock_str *s;

	s = malloc(sizeof(struct s_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		i++;
	}
	return (s);
}
