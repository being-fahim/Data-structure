#include <stdio.h>

int main(){
    int n, i, j;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\nIn which position's value do you want to delete: ");
    scanf("%d", &i);
    if(i >= n){
        printf("Delete not possible!");
        }
    else{
        for(j = i + 1; j < n; j++){
            a[j - 1] = a[j];
        }
            n = n - 1;
    }


    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

