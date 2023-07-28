#include "main.h"

/**
 * my_stritk - fuction name
 * @str:pointer to char*
 * @delim:pointer to char*
 *
 * Return:char
 */

char *my_stritk(char *str, const char *delim)
{
	static char *src;
	char  *p,  *ret = 0;

	if (str != NULL)
		src = str;

	if (src == NULL)
		return (NULL);

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
