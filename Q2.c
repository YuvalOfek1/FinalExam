#include "exam.h"

int replaceDigit(int num)
{
	if (num == 0)
		return 0;
	if (num % 10 == 0)
		return replaceDigit(num / 10) * 10 + 9;
	else return replaceDigit(num / 10) * 10 + num % 10 - (2 - (num % 10) % 2);
}
