//simple process demonstration program

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	 pid_t child_pid;
	 int m;
	 char *message="start of the fork process\n";
	 printf("fork program is beginning to execute");
	 child_pid=fork();
	 switch(child_pid){
	 case -1:
	 perror("fork error");
	 exit(1);
	 break;
	 case 0:
	 message="this is the child process running";
	 m=3;
	 break;
	 default:
	 message ="this is the parent of the child ";
	 m=5;
	 break;
	 }
	 for (; m > 0;m--){
	 puts(message);
	 sleep(3);
	 }
	return 0;

}
