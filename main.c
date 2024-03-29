#include "monty.h"
global_t glob = {0, 0, 0};

/**
 * main - Monty interpreter.
 * @ac: Argument counter.
 * @av: Argument vector.
 * Return: On success, returns 0.
 */
int main(int ac, char *av[])
{
	if (ac == 2)
		instructions(av[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * openFile - Opens a file and executes it commands.
 * @filename: Name of the file.
 * @instruction: Struct of functions.
 */
void openFile(char *filename, instruction_t instruction[])
{
	size_t n = 0;
	stack_t *head = NULL;
	unsigned int lineCount = 1, flag = 0;
	int chars = 0;
	char *buffer = NULL, *checkArg, *command;
	FILE *fd;

	fd = fopen(filename, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	for (; 1; lineCount++)
	{
		chars = getline(&buffer, &n, fd);
		if (chars == EOF)
			break;
		command = strtok(buffer, " \t\n"), checkArg = strtok(NULL, " \t\n");
		if (command == NULL || command[0] == '#')
			continue;
		if (checkArg != NULL && _isdigit(checkArg) == 1)
			glob.argument = atoi(checkArg);
		else
		{
			if (checkFunc(command) == 1)
				printErr(lineCount);
			else if (checkFunc(command) == 2)
				continue;
			else if (checkFunc(command) == 3)
				flag++;
		}
		head = cFunc(&head, lineCount, instruction, command);
		if (flag == 0 && head == NULL && glob.pop == 0)
			free(buffer), closeFile(fd), exit(EXIT_FAILURE);
		flag = 0;
	}
	free_all(&head, fd, buffer);
}
