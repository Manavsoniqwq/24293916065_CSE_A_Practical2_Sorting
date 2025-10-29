#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort_array_by_insertion(int data_array[], int array_size) {
    for (int current_index = 1; current_index < array_size; current_index++) {
        int element_to_insert = data_array[current_index];
        int comparison_index = current_index - 1;
        
        while (comparison_index >= 0 && data_array[comparison_index] > element_to_insert) {
            data_array[comparison_index + 1] = data_array[comparison_index];
            comparison_index--;
        }
        data_array[comparison_index + 1] = element_to_insert;
    }
}


void fill_array_with_random_numbers(int data_array[], int array_size){
    for (int i = 0; i < array_size; i++)
        data_array[i] = rand() % 100000;
}


int main() {
    const int number_of_sizes = 10;
    int array_sizes_to_test[10] = {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500};
    
    const int benchmark_iterations = 5; 

    srand(time(NULL));

    printf("Array Size\tTotal Time (seconds)\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < number_of_sizes; i++){
        int current_size = array_sizes_to_test[i];
        int data_array[current_size];
        
        double total_elapsed_time = 0.0;
        
        for (int iteration_count = 0; iteration_count < benchmark_iterations; iteration_count++) {
            fill_array_with_random_numbers(data_array, current_size);
            
            clock_t start_time = clock();
            
            sort_array_by_insertion(data_array, current_size);
            
            clock_t end_time = clock();
            
            total_elapsed_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        }
        
        printf("%d\t\t%lf\n", current_size, total_elapsed_time);
    }
    return 0;
}
