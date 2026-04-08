int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
int	main()
{
	char str1[30] = "hellooo";
	char str2[44] = "hellooooo";
	printf("%s", ft_strcmp(str1, str2));
	return 0;
}
