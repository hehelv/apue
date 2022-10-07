#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 *  * 创建子进程 date，参数是 +%s
 *   * 相当于在 shell 中执行 date +%s 命令
 *    */
int main()
{
    pid_t pid;

    puts("Begin!");

    fflush(NULL);

    pid = fork();
    if(pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)    // child
    {
        execl("/bin/date","date","+%s",NULL);
        perror("execl()");
        exit(1);
    }

    wait(NULL);

    puts("End!");

    exit(0);
}
