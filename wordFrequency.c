#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXWORD 100		//maxowrd will also be used by getch and ungetch
char buf[MAXWORD];//to be use by the getch()and ungetch()functions
int bufp = 0;
struct tnode *addtree(struct tnode* ,char *);
void treeprint(struct tnode *);
int getword(char *,int);
int getch(void);
void ungetch(int c);
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int main(){
struct tnode *root;
char word[MAXWORD];
root=NULL;
while(getword(word,MAXWORD)!=EOF)
	if(isalpha(word[0]))
		root = addtree(root,word);
		printf("frequency \t word\n");
	treeprint(root);

return 0;
}//function to traverse the tree in preorder traversal
void treeprint(struct tnode *p){
	if (p!=NULL){
		treeprint(p->left);
		printf("%s\t\t %4d\n",p->word,p->count);
		treeprint(p->right);
	}
}

//the talloc fuction that allocate memory of size struct tnode
struct tnode *talloc(void){
	return (struct tnode *)malloc(sizeof(struct tnode));
}
//function to add nodes to the tree with words
struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;
	if(p==NULL){
		p=talloc();
		p->word = strdup(w);
		p->count=1;
		p->left=p->right=NULL;
	}
	else if ((cond=strcmp(w,p->word))==0)
	p->count++;
	else if(cond<0)
		p->left=addtree(p->left,w);
	else 
		p->right=addtree(p->right,w);
	return p;
}
//function to read a word from the specified stream
int getword(char *word,int lim){
	int c;
	char *w=word;
	while (isspace(c=getch()))
		;
	if(c!=EOF)
		*w++=c;
	if(!isalpha(c)){
		*w='\0';
		return c;
	}
	for(; --lim>0;w++)
		if(!isalnum(*w=getch())){
			ungetch(*w);
			break;
		}
		*w='\0';
		return word[0];
}
int getch(void) /* get a (possibly pushed-back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
if (bufp >= MAXWORD)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}
