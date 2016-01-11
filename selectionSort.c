//***********************************************************************************
//*a selection sort program developed by harisu fanyui to select and sort intergers
// developed today the 9 september 2015
//***********************************************************************************
#include<stdio.h>
#include<stdlib.h>
void swap(int *,int *);
void selectSort(int a[],int n);
void print_elmt(int a[],int n);
void get_elmt(int a[],int n);
int main(){
    int n=5;
    //printf("enter size\n");
   // scanf("%d",&n);
    int arr[5];
    get_elmt(arr,5);
    selectSort(arr,5);
    print_elmt(arr,5);
return 0;
}

void get_elmt(int a[],int n){
    int j;
    for (j=0;j<n;j++)
        scanf("%d",&a[j]);

}
void swap (int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}
void selectSort(int a[],int n){
    int temp,first,last,current;
    for(first=0;first<n-1;first++){
        temp=first;
            for(last=first+1;last<n;last++){
                if (a[last]<a[temp])
                    temp=last;
                    swap(&a[temp],&a[first]);
            }
    }
}
void  print_elmt(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
