#include "main.h"

char *read_line(void)
{
    char *userinput = NULL;
    ssize_t bufsize = 0;

    if (getline(&userinput, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    }
    return (userinput);
}