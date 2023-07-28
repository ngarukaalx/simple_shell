#include "main.h"
/**
<<<<<<< HEAD
 * my_stritk - fuction name
 * @str:pointer to char*
 * @delim:pointer to char*
 *
 * Return:char
 */

=======
* my_stritk - Tokenizes a string by a delimiter
* @str: The string to tokenize
* @delim: The delimiter by which to split the string
* Return: Pointer to the start of the next token
*/
>>>>>>> 2ab737de38744301130d3def363eed74253dbcc2
char *my_stritk(char *str, const char *delim)
{
	static char *src;
	char  *p,  *ret = 0;

	if (str != NULL)
		src = str;
<<<<<<< HEAD

	if (src == NULL)
		return (NULL);

=======
	}
	if (src == NULL)
	{
		return (NULL);
	}
>>>>>>> 2ab737de38744301130d3def363eed74253dbcc2
	p = strpbrk(src, delim);
	if (p != NULL)
	{
		*p  = 0;
		ret = src;
		src = ++p;

	}
	else if (*src)
	{
		ret = src;
		src = NULL;
	}

	return (ret);
}
