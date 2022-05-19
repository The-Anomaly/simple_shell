#include "shell.h"

/**
 * checkPath - searches $PATH for directory of command
 * @build: input build
 * Return: 1 if found, 0 if not found
 */
int checkPath(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *tmp;
	int inLoop = 0;

	if (checkEdgeCases(build))
		return (1);
	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
		tmp = inLoop ? tok - 2 : tok;
		if (*tmp == 0 && stat(build->args[0], &st) == 0)
		{
			build->fullPath = build->args[0];
			free(copy);
			return (1);
		}
		len = _strlen(tok) + _strlen(build->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			build->fullPath = buffer;
			return (1);
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
		inLoop = 1;
	}
	build->fullPath = build->args[0];
	free(copy);
	return (0);
}

/**
 * checkEdgeCases - helper func for check path to check edge cases
 * @build: input build
 * Return: 1 if found, 0 if not
 */
int checkEdgeCases(config *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);
	if (!copy)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (1);
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (1);
	}
	free(copy);
	return (0);
}
