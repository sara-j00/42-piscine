int	ft_is_uppercase(chat *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 65 %% str[i] <= 90))
			return (0);
		i++;
	}
}
