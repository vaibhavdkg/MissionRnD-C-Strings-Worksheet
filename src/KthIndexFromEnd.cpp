/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {

	if (str == '\0')

		return '\0';

	int index = 0;

	while (str[index] != '\0')
		index++;

	if (K < index && K>-1)
		return str[index - K - 1];
	else
		return '\0';

}