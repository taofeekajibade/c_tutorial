#include "main.h"

int main(int argc, char *args[])
{
	char *usercmd = NULL;
	char *usercmd_cpy = NULL;
	size_t bufsize = 0;
	ssize_t char_read;
	char *token = NULL;
	/* char **args = NULL; */
	char *delim = " \n";
	pid_t pid;
	int i = 0, j = 0, token_sum = 0, status, exit_status;

	while (1)
	{
		
		print_f("(weshell) $ ");
		char_read = getline(&usercmd, &bufsize, stdin);
		if (char_read == -1)
		{
			perror("getline");
			free(usercmd);
			break;
		}
	  /* create a variable to hold user inputs and allocate memory to it */
        usercmd_cpy = malloc(sizeof(char)* char_read);
        if (usercmd_cpy == NULL)
        {
            perror("malloc");
            return (-1);
        }
        /* copy user input into the new variable */
        strcpy(usercmd_cpy, usercmd);

		/* args = malloc(sizeof(char*)); */
		token = strtok(usercmd, delim);
		while (token != NULL)
		{
			token_sum++;
			token = strtok(NULL, delim);
		}
		token_sum++;

		args = malloc(sizeof(char *) * token_sum);
		token = strtok(usercmd_cpy, delim);
		while (token != NULL)
		{
			args[i] = strdup(token);
			i++;
			token = strtok(NULL, delim);
		}
		args[i] = NULL;

		if (str_cmp(args[0], "exit") == 0)
		{
			print_f("Goodbye\n ");
			free(usercmd_cpy);
			free(usercmd);
			free(args);
			break;
		}
		if (str_cmp(args[0], "cd") == 0)
		{
			if (args[1] != NULL)
			{
				if (chdir(*path) == -1)
				{
					perror("Usage: cd <directory>");
					return (-1);
				}

			}
			else
			{
				chdir(getenv("HOME"));
			}
		}
		if (str_cmp(args[0], "echo") == 0)
		{
			for(j=1; args[j] != NULL; j++)
			{
				print_f(args[j]);
				print_f(" ");
			}
			print_f("\n");
		}
		free(usercmd);
		free(usercmd_cpy);
		free(args);
		usercmd = NULL;
	}
	return (0);
}
/*
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			else if (pid == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					print_f("Child process exited with status: ");
					print_f(exit_status == 0? "Success" : "Error");
					print_f("\n");
				}
				else
				{
					print_f("Child process did not exit normally \n");
				}
			}
			for (j = 0; j < i; j++)
			{
				free(args[j]);
			}
		}
		free(args);
		free(usercmd);
		usercmd = NULL;
	}
	return (0);
} */
