#include <stdio.h>
#include <conio.h>
int main(){
int n,i,a;
printf("Enter size of the array: ");
scanf("%d" , &n);
int arr[n];
for(i=0 ; i<n ; i++){
    scanf("%d",&arr[i]);
}
int flag=0;
printf("Enter the element to search : ");
scanf("%d",&a);
for (i=0 ; i<n ; i++){
    if (a==arr[i]){
        flag = 0;
        printf("Element found");
        break;
    }
    else{
        flag = 1;
    }
}
if (flag == 1){
    printf("Not found");
}
return 0;
}
