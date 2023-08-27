#include "monty.h"

/**
 * _n_node -  adds a new node at the beginning
 * @top: head for the double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _n_node(stack_t **top, unsigned int l_num)
{
	stack_t *new, *last;
	int i = 0;

	(void)l_num;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (datax.mode == 0 || !*top)
	{
		if (*top)
		{
			new->next = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (datax.mode == 1)
	{
		last = *top;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * _mode_switch -  switch the mode
 * @top: head of double list
 * @l_num: line number for opcode
 * Return: nothing
 */
void _mode_switch(stack_t **top, unsigned int l_num)
{
	(void)top;
	(void)l_num;

	if (strcmp(datax.opcode, "queue") == 0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}



/**
 * _print_tofs -  print the value at the top stack
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _print_tofs(stack_t **top, unsigned int l_num)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);
}

/**
 * _printer -  print all the elements for the dlistint_t list
 * @top: head for the double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _printer(stack_t **top, unsigned int l_num)
{
	stack_t *current = *top;
	int i;

	(void)l_num;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * _rm_tofs - removes the top element of the stack
 * @top: head of double list
 * @l_num: line number for the opcode
 * Return: nothing
 */
void _rm_tofs(stack_t **top, unsigned int l_num)
{

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}

/**
 * _swap - swaps the top two elements of the stack.
 * @top: head for the double list
 * @l_num: line num of opcode
 * Return: nothing
 */
void _swap(stack_t **top, unsigned int l_num)
{
	stack_t *tmp1;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	tmp1 = *top;
	tmp1->prev = tmp1->next;
	if ((*top)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *top;
	}
	*top = tmp1->prev;
	(*top)->prev = NULL;
	(*top)->next = tmp1;
}

/**
 * _add - adds the top two elements of the stack.
 * @top: head of double list
 * @l_num: line number for the opcode
 * Return: nothing
 */
void _add(stack_t **top, unsigned int l_num)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_rm_tofs(&datax.top, datax.line_num);
	(*top)->n += value;
}


/**
 * _sub - subtracts the top element of the stack
 *  from the second top element of the stack.
 * @top: head of double list
 * @l_num: line num for opcode
 * Return: nothing
 */
void _sub(stack_t **top, unsigned int l_num)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_rm_tofs(&datax.top, datax.line_num);
	(*top)->n -= value;
}

/**
 * _nothing - do anything.
 * @top: head of double list
 * @l_num: line number of opcode
 * Return: nothing
 */
void _nothing(stack_t **top, unsigned int l_num)
{
	(void)top;
	(void)l_num;
}

/**
 * _div - divides the second top element of
 * the stack by the top element of the stack.
 * @top: head of double list
 * @l_num: line num of opcode
 * Return: nothing
 */
void _div(stack_t **top, unsigned int l_num)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_rm_tofs(&datax.top, datax.line_num);
	(*top)->n /= value;
}

/**
 * _mod - computes the rest of the division for second
 *  top element of the stack by the top element of the stack.
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _mod(stack_t **top, unsigned int l_num)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_rm_tofs(&datax.top, datax.line_num);
	(*top)->n %= value;
}

/**
 * _mul - multiplies the second top element
 * of the stack with the top element of the stack.
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _mul(stack_t **top, unsigned int l_num)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_rm_tofs(&datax.top, datax.line_num);
	(*top)->n *= value;
}

/**
 * _pchar - prints the char at the top of the stack (ascii).
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _pchar(stack_t **top, unsigned int l_num)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		free_st(datax.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _pstr(stack_t **top, unsigned int l_num)
{
	stack_t *current = *top;
	int i;
	(void)l_num;

	for (i = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 i++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}

/**
 * _rotb - rotates the stack to the bottom.
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _rotb(stack_t **top, unsigned int l_num)
{
	stack_t *last = *top;
	int i;

	if (!*top || (*top)->next == NULL)
		return;
	(void)l_num;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	last->prev->next = NULL;
	(*top)->prev = last;
	(*top) = last;
	last->prev = NULL;
}

/**
 * _rott -  rotates the stack to the top.
 * @top: head of double list
 * @l_num: line num for the opcode
 * Return: nothing
 */
void _rott(stack_t **top, unsigned int l_num)
{
	stack_t *last = *top;
	int i;

	if (!*top)
		return;
	(void)l_num;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	(*top)->prev = last;
	(*top) = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}
