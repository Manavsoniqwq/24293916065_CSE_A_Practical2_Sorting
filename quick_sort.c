#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int find_partition_index(int data_array[], int low_index, int high_index) {
    int pivot_value = data_array[high_index];
    int smaller_element_index = low_index - 1;
    
    for (int current_index = low_index; current_index < high_index; current_index++) {
        if (data_array[current_index] <= pivot_value) {
            smaller_element_index++;
            
            int temp = data_array[smaller_element_index];
            data_array[smaller_element_index] = data_array[current_index];
            data_array[current_index] = temp;
        }
    }
    
    int temp = data_array[smaller_element_index + 1];
    data_array[smaller_element_index + 1] = data_array[high_index];
    data_array[high_index] = temp;
    
    return smaller_element_index + 1;
}

void sort_array_quickly(int data_array[], int low_index, int high_index) {
    if (low_index < high_index) {
        int partition_pivot = find_partition_index(data_array, low_index, high_index);
        
        sort_array_quickly(data_array, low_index, partition_pivot - 1);
        sort_array_quickly(data_array, partition_pivot + 1, high_index);
    }
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
            sort_array_quickly(data_array, 0, current_size - 1); 
            clock_t end_time = clock();
            
            total_elapsed_time += ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        }
        
        printf("%d\t\t%lf\n", current_size, total_elapsed_time);
    }
    return 0;
}
