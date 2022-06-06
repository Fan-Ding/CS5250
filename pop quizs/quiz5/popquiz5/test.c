#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    printf("Sorry, I’m staying… not going anywhere.\n");
} 
void sig_handler2(int signo)
{
    printf("Alright, since you really want me dead. Goodbye, cruel world!\n");
    exit(0);
}
int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR || signal(SIGUSR1, sig_handler2) == SIG_ERR)
        printf("can't catch SIGINT\n");
    while(1) 
        sleep(1);
    return 0;
}