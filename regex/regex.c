#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 if it doesn’t.
 */
int regex_match(const char *str, const char *pattern)
{
	int first_match;

	if (*pattern == '\0')
		return (*str == '\0');

	first_match = (*str && (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
