#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int pid;
	int status;
	int i;
	pid_t pid1;

	printf("나는 부모입니다 : %d\n 내 아이가 숫자세는걸 기다릴게요\n",getpid());
	if((pid = fork()) == 0)
	{
		printf("나는 응애입니다 : %d\n", getpid());
		for(i = 1; i < 4; i++)
		{
			printf("응애가 숫자를 셉니다 : %d\n",i);
			sleep(1);
		}
	}
	else if(pid > 0)
	{
		pid1 = wait(&status) ;
		printf("나는 부모입니다.");
		for(i = 1; i < 4; i++)
		{
			printf("부모가 숫자를 셉니다 : %d\n",i);
			sleep(1);
		}
	}
	return 0;
}