#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

void sort(int *arr, int arr_size);
int get_input_arr_size(int argc, char **argv);
int *generate_arr(int size);
int *generate_arr_with_zeros(int size);
int generate_random_num(int limit);
bool is_arr_contains(int number, int *arr, int arr_size);
void print_arr(int *arr, int arr_size);

int main(int argc, char **argv)
{
    srand(time(NULL));
    int arr_size = get_input_arr_size(argc, argv);
    int *arr = generate_arr(arr_size);

    printf("Array before sort: ");
    print_arr(arr, arr_size);

    sort(arr, arr_size);

    printf("Array after sort: ");
    print_arr(arr, arr_size);

    return 0;
}

void sort(int *arr, int arr_size)
{
    bool is_any_sort_op = false;

    do
    {
        is_any_sort_op = false;
        for (int i = 0; i < arr_size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int num_cache = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = num_cache;
                is_any_sort_op = true;
            }
        }
    } while (is_any_sort_op);
}

int get_input_arr_size(int argc, char **argv)
{
    int arr_size = 5;
    if (argc == 2)
    {
        arr_size = atoi(argv[1]);
    }
    return arr_size;
}

int *generate_arr(int size)
{
    int *arr = generate_arr_with_zeros(size);
    for (int i = 0; i < size; i++)
    {
        int random_num = generate_random_num(size);
        do
        {
            random_num = generate_random_num(size);
        } while (is_arr_contains(random_num, arr, size));
        arr[i] = random_num;
    }
    return arr;
}

int *generate_arr_with_zeros(int size)
{
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

int generate_random_num(int limit)
{
    int random_num = rand() % limit + 1;
    return random_num;
}

bool is_arr_contains(int number, int *arr, int arr_size)
{
    int index = 0;
    bool is_number_in_arr = false;
    while (index < arr_size && !is_number_in_arr)
    {
        if (arr[index] == number)
        {
            is_number_in_arr = true;
        }
        ++index;
    }
    return is_number_in_arr;
}

void print_arr(int *arr, int arr_size)
{
    printf("[");
    if (arr_size > 0)
    {
        printf("%d", arr[0]);
        for (int i = 1; i < arr_size; i++)
        {
            printf(", %d", arr[i]);
        }
    }
    printf("]\n");
}