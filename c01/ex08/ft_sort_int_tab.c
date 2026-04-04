#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int	arr[size];

	int	i;
	while(i < size)
	{
		int	j;
		j = i;
		while (j < size)
		{
			if (tab[i] < tab[j])
				arr[i] = tab[i];
			j++;
		}
		i++;
	}
}

int main()
{
	int arr[8] = {2, 5, 6, 8, 1, 9, 11, 2};
	int *ptr = arr;
	ft_sort_int_tab(arr, 8);
	for (int i=0; i<8; i++)
		printf("%d", arr[i]);
	return 0;
}
