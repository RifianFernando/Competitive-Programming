#include<stdio.h>

int n, m, arr[4005];
int count = 0, total = 0;

void print(){
 if (count == 0) {
  printf("-1\n");
    } else {
        printf("%d %d\n", count, total);
    }
}

void swap(int *x, int *y){
 int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n){
 for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void loop(int j, int i, int m){
    for (int k = j + 1; k < n; k++) {
        if (arr[j] - arr[i] <= m && arr[k] - arr[i] <= m && arr[k] - arr[j] <= m) {
            if (arr[i] + arr[j] + arr[k] > total) {
                total = arr[i] + arr[j] + arr[k];
            }
            count++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m); getchar();
		
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]); getchar();
    }
    
    sort(arr, n);
    
 int i = 0;
    while (i < n-2){
        for (int j = i + 1; j < n - 1; j++) {
         	loop(j, i, m);
        }
        i++;
    }
    
    print();

    return 0;
}
