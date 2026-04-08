int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
int main()
{
	char str1[30] = "welcome";
	char str2[54] = "welconeeee";
	printf("%d", ft_strncmp(str1, str2, 5));
	printf("%d", ft_strncmp(str1, str2, 7));
}
