char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	// While 'src' doesn't reach the end
	while (src[i] != '\0')
	{
		//'dest' receives the character that is in 'src'
		dest[i] = src[i];
		i++;
	}
	// In the end 'dest' receives the null of 'src'
	dest[i] = src[i];

	//'dest' is returned
	return (dest);
}
/* 
int	main(void)
{
	char	dest[] = "Dest";
	char	src[] = "Source";

	printf("dest before: %s\n", dest);
	ft_strcpy(dest, src);
	printf("dest after: %s\n", dest);
} */
