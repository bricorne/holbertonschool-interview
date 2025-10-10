#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "substring.h"

/**
 * find_substring - Finds all starting indices in string s where a substring
 * containing all the words from the array `words` exactly once in any order
 * appears.
 * @s: The string to search.
 * @words: The array of words.
 * @nb_words: Number of words in the array `words`.
 * @n: Pointer to an integer where the number of found indices will be stored.
 * Return: An array of starting indices where the substrings are found or
 * NULL if none found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len = strlen(s);
	int word_len = strlen(words[0]);
	int total_len = nb_words * word_len;
	int *indices = NULL;
	int count = 0;
	int *expected_count;
	int *current_count;

	*n = 0;
	if (s_len < total_len)
		return (NULL);

	expected_count = calloc(nb_words, sizeof(int));
	current_count = calloc(nb_words, sizeof(int));

	if (!expected_count || !current_count)
	{
		free(expected_count);
		free(current_count);
		return (NULL);
	}

	count_word_frequency(words, nb_words, expected_count);

	for (int i = 0; i <= s_len - total_len; i++)
	{
		if (is_valid_substring(s, i, word_len, nb_words, words, expected_count))
		{
			indices = realloc(indices, (count + 1) * sizeof(int));
			if (!indices)
			{
				free(expected_count);
				free(current_count);
				return (NULL);
			}
			indices[count++] = i;
		}
	}

	free(expected_count);
	free(current_count);

	*n = count;
	return (indices);
}

/**
 * count_word_frequency - Count the frequency of each word in the words array.
 * @words: The array of words.
 * @nb_words: Number of words in the array `words`.
 * @expected_count: Array to store the count of each word.
 */
void count_word_frequency(char const **words, int nb_words, int *expected_count)
{
	for (int i = 0; i < nb_words; i++)
	{
		expected_count[i] = 0;
		for (int j = 0; j < nb_words; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
				expected_count[i]++;
		}
	}
}

/**
 * is_valid_substring - Check if a substring of s starting at `start` is a valid
 * concatenation of all words in the array `words`.
 * @s: The string to search.
 * @start: The starting index of the substring in s.
 * @word_len: The length of each word in words.
 * @nb_words: Number of words in the array `words`.
 * @words: The array of words.
 * @expected_count: The expected frequency count of each word in the words array.
 * Return: 1 if valid, 0 otherwise.
 */
int is_valid_substring(const char *s, int start, int word_len, int nb_words,
	const char **words, int *expected_count)
{
	int *current_count;
	int j, k;
	char current_word[word_len + 1];

	current_count = calloc(nb_words, sizeof(int));
	if (!current_count)
		return (0);

	memset(current_count, 0, nb_words * sizeof(int));

	for (j = 0; j < nb_words; j++)
	{
		int index = start + j * word_len;
		strncpy(current_word, s + index, word_len);
		current_word[word_len] = '\0';

		for (k = 0; k < nb_words; k++)
		{
			if (strcmp(current_word, words[k]) == 0)
			{
				current_count[k]++;
				if (current_count[k] > expected_count[k])
				{
					free(current_count);
					return (0);
				}
				break;
			}
		}
		if (k == nb_words)
		{
			free(current_count);
			return (0);
		}
	}

	free(current_count);
	return (1);
}
