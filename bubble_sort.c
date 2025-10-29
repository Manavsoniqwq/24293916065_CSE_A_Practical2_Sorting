#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubbleSort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void generateRandomArray(int array[], int size){
    for(int i = 0; i < size; i++)
        array[i] = rand() % 100000;
}

int main() {
    int input_size[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int MAX_ITERATIONS = 5;

    srand(time(NULL));

    printf("Array Size\tTotal Time (seconds)\n");
    printf("--------------------------------------\n");

    for(int i = 0; i < 10; i++){
        int size = input_size[i];
        int array[size];
        
        double total_time = 0;
        
        for(int iter = 0; iter < MAX_ITERATIONS; iter++) {
            generateRandomArray(array, size);
            
            clock_t start = clock();
            bubbleSort(array, size); 
            clock_t end = clock();
            
            total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
        }
        
        printf("%d\t\t%lf\n", size, total_time);
    }
    return 0;
}
