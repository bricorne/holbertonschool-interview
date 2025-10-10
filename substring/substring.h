#ifndef SUBSTRING_H
#define SUBSTRING_H

int *find_substring(char const *s, char const **words, int nb_words, int *n);
void count_word_frequency(char const **words, int nb_words, int *expected_count);
int is_valid_substring(const char *s, int start, int word_len, int nb_words,
	const char **words, int *expected_count);

#endif /* SUBSTRING_H */
