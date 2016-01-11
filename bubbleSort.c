//*********************************************************************************
// a bubble sort program to sort an array of strings
// written on the 9 september 2015;
//this bubblesort sorts only strings
//*********************************************************************************
#include<stdlib.h>
#include<stdio.h>
#define N 5
#define MAXLENGTH 15
void swap(char *,char *);//TO SWAP TO STRINGS
void bubble(char a[][MAXLENGTH] ,int n);//TO BUBBLESORT THE ARRAY
void print_array(char a[][MAXLENGTH],int n);//TO PRINT THE ELEMENT OF THE ARRAY
void get_array(char a[][MAXLENGTH] ,int n);//TO GET THE ELEMENTS OF THE ARRAY
int sequentSearch(char *key,char a[][MAXLENGTH] );//TO SEARCH THE ARRAY USING SEQUENTIAL SEARCH
int main(){
    char key[MAXLENGTH];
char array[N][MAXLENGTH];
 get_array( array, N);
 printf("before sorting the array we have \n");
print_array(array,N);

bubble(array,N);
printf("after sorting the array we have\n");
print_array(array,N);
printf("enter the element you want to find int the array\n");
scanf("%s",&key);
if(sequentSearch(key,array)==1)
    printf("item is found inthe array\n");
else printf("not found\n");

return 0;
}
void swap(char *a,char *b){
    char temp[MAXLENGTH];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}
//BUBBLE SORT FUCNTION
void bubble(char a[][MAXLENGTH] ,int n){
int i,j;
for (i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
        if (strcmp(a[j-1],a[j])>0)
        swap(a[j],a[j-1]);
    }
}

}
// PRINT FUCNTION IMPLEMENTATION
void print_array(char a[][MAXLENGTH] ,int n){
int i,j;
for(i=0;i<N;i++){
    printf("%s",a[i]);
    printf("\n");
}
}
//GET ARRAY FUCNTION IMPLEMENTATION
void get_array(char a[][MAXLENGTH] ,int n){
int i;
for (i=0;i<N;i++){
    printf("input a name\n");
    scanf("%s",a[i]);
}
}
//SEQUENTIAL SEARCH FUNCTION IMPLEMENTATION
int sequentSearch(char *key,char a[][MAXLENGTH] ){
    int i;
    int found=0;
    for (i=0;i<N;i++){
        if (strcmp(key,a[i])>0){
            found=0;
            break;
        }
            else if (strcmp(key,a[i])==0)
            return found=1;
    }
}
