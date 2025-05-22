#include "microchell.h"

int ft_error(char *str)
{
    while(*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **av, int i)
{
    if (i != 2)
        ft_error("error: cd: bad arguments\n");
    else if (chdir(av[1]) == -1)
        ft_error("error: cd: cannot change directory to "), ft_error(av[1]), ft_error("\n");
    return 0;
}

int exec(char **av, char **envp, int i)
{
    int fd[2];
    int status;
    int pid;
    int has_pipe = av[i] && !strcmp(av[i], "|");

    if (has_pipe && pipe(fd) == -1)
        ft_error("error: fatal\n");
    pid = fork();
    if (!pid)
    {
        av[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            ft_error("error: fatal\n");
        execve(*av, av, envp);
        return ft_error("error: cannot execute "), ft_error(*av), ft_error("\n");
    }
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            ft_error("error: fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **envp)
{
    int status = 0;
    int i = 0;

    if (ac > 1)
    {
        while(av[i] && av[++i])
        {
            av += i;
            i = 0;
            while(av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            if (!strcmp(*av, "cd"))
                status = cd(av, i);
            else if(i)
                status = exec(av, envp, i);
        }
    }
    return status;
}