void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		int	temp;

		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}
/*
int	main()
{
	int	size = 8;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	*ptr = arr;
	ft_putnbr(ptr, 8);
	for (int i=0; i<size; i++){
		printf("%d", ptr[i]);
	}
	return 0;
}
*/
