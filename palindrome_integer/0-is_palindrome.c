#include "palindrome.h"
#include <stdio.h>

int is_palindrome(unsigned long n){
	unsigned long reversed = 0;
	unsigned long check = n;

	if ( n <= 10){
		return 1;
	}
	while (n != 0)
	{
		reversed = reversed * 10 + n % 10;
		n = n / 10;
	}
	return reversed == check;
}
