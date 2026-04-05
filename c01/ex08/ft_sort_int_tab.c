#include <stdio.h>
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i=0;
	while(i < size)
	{
		int	j;
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
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
