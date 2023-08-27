#include "monty.h"

/**
 * conter -  count charachter in number
 * @num: number
 * Return: number lentgh
 */
size_t conter(int num)
{
	int len = 0;

	if (!num)
		return (1);
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
 * openf -  open file
 * @filename: file name
 * Return: FILE
 */
FILE *openf(char *filename)
{
	FILE *mfile;

	mfile = fopen(filename, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}

/**
 * verify_n -  verify number for opcode
 * is valid or not
 * @token: token string
 * Return: nothing
 */
void verify_n(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == conter(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		datax.push_value = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_st -  frees the stack
 * @top: head of double list
 * Return: nothing
 */
void free_st(stack_t *top)
{
	stack_t *nav, *nav2;

	nav = top;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	datax.top = NULL;
	fclose(datax.mfile);
}
