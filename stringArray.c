#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000
char *lines[MAXLINES];
int read_line(char *,int);
int read_lines(char *lines[],int line_cnt);
void write_lines(char *lines[] ,int line_cnt);
int main(){
int line_cnt;
if ((line_cnt=read_lines(lines,MAXLINES))>=0)
write_lines(lines,line_cnt);
else
printf("Error: input too big\n");

return 0;
}
int read_lines(char *lines[],int maxlines){
int len;
int line_cnt;
char line[MAXLEN];
char *p;
line_cnt=0;
while((len=read_line(line,MAXLEN))>0)
if ((line_cnt>=maxlines)||(p=malloc(len*sizeof(char))) ==NULL)
return -1;
else{
line[len-1]=0;
strcpy(p,line);
lines[line_cnt++]=p;
}
return line_cnt; }

void write_lines(char *lines[],int line_cnt){
int i;
for (i=0;i<line_cnt;i++)
printf("%s\n",lines[i]);
}
int read_line(char line[],int maxline){
int c,i;
for (i=0;(i<maxline-1)&&((c=getchar())!=EOF)&&(c!='\n');++i)
line[i]=c;
if (c=='\n')
line[i++]=c;
line[i]=0;
return i;
}

