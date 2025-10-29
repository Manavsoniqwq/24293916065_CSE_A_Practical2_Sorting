#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void combine_sorted_halves(int data_array[], int start_index, int middle_index, int end_index) {
    int temp_storage[end_index - start_index + 1];

    int left_pointer = start_index; 
    int right_pointer = middle_index + 1;
    int storage_index = 0;

    while (left_pointer <= middle_index && right_pointer <= end_index) {
        if (data_array[left_pointer] <= data_array[right_pointer]) 
            temp_storage[storage_index++] = data_array[left_pointer++];
        else 
            temp_storage[storage_index++] = data_array[right_pointer++];
    }

    while (left_pointer <= middle_index) 
        temp_storage[storage_index++] = data_array[left_pointer++];
    
    while (right_pointer <= end_index) 
        temp_storage[storage_index++] = data_array[right_pointer++];

    for (int i = 0; i < storage_index; i++) 
        data_array[start_index + i] = temp_storage[i];
}


void sort_by_merging(int data_array[], int start_index, int end_index) {
    if (start_index >= end_index) return;

    int middle_index = start_index + (end_index - start_index) / 2;

    sort_by_merging(data_array, start_index, middle_index);
    sort_by_merging(data_array, middle_index + 1, end_index);
    combine_sorted_halves(data_array, start_index, middle_index, end_index);
}

void fill_array_with_random_numbers(int data_array[], int array_size){
    for (int i = 0; i < array_size; i++)
        data_array[i] = rand() % 100000;
}


int main() {
    const int number_of_sizes = 10;
    int array_sizes_to_test[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    const int benchmark_iterations = 1000;

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
            sort_by_merging(data_array, 0, current_size - 1);
            clock_t end_time = clock();
            
            total_elapsed_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        }
        
        printf("%d\t\t%lf\n", current_size, total_elapsed_time);
    }
    return 0;
}
