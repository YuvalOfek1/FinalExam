#include "exam.h"

int oneinarow(int matrix[], int cols, int* start_index)
{
	int count = 0, i, flag = 0;
	for (i = 0; i < cols; i++)
	{
		if (matrix[i] == 1)
		{
			if (count == 0)
			{
				*start_index = i;
			}
			count++;
		}

	}
	return count;
}




int* FromMatToArr(int matrix[][COLS], int rows, int cols, int* rsize)
{
	int* backarr = (int*)malloc(rows * sizeof(int));
	*rsize = 0;
	int index;
	int count;
	for (int i = 0; i < rows; i++)
	{
		index = 0;
		count = oneinarow(&matrix[i], cols, &index);
		if (count)
		{
			backarr[*rsize] = (i * 100) + (index * 10) + index + count - 1;
			*rsize += 1;
		}
	}
	return backarr;


}