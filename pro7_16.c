#include <stdio.h> 
#include <stdlib.h>

int get_min_range(int list[], int first, int last)
{
	int temp = first;
	int i;
	for (i = first; i <= last; ++i) {
		if (list[i] < list[temp])
			temp = i;
	}
	return temp;
}

void
select_sort(int list[], int n)
{
	int fill,					/* first element in unsorted subarray */
		temp,
		index_of_min;
	
	for(fill = 0; fill < n-1; ++fill){
		index_of_min = get_min_range(list, fill, n-1);   /* 注意: 这里传递数组作为参数不是用list[], 而是直接用list */
		
		/* Exchange elements at fill and index_of_min */
		if (fill != index_of_min) {
			temp = list[index_of_min];
			list[index_of_min] = list[fill];
			list[fill] = temp; 
		}
	}
}

int main()
{
	int arr[5] = {74, 45, 83, 16, 24};
	select_sort(arr, 5);
	int i;
	for (i =0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}
