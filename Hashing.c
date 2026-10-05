#include <stdio.h>

#define SIZE 10
#define N 8

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index = hashFunction(key);
    int original = index;

    while (table[index] != -1)
    {
        printf("Collision for %d at index %d\n", key, index);
        index = (index + 1) % SIZE;
    }

    table[index] = key;
}

int hashSearch(int table[], int key, int *comparisons)
{
    int index = hashFunction(key);
    int start = index;

    *comparisons = 0;

    while (table[index] != -1)
    {
        (*comparisons)++;

        if (table[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

int linearSearch(int arr[], int n, int key, int *comparisons)
{
    *comparisons = 0;

    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int songs[N] = {105, 210, 315, 420, 525, 630, 735, 840};
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("HASH TABLE INSERTION\n\n");

    for (int i = 0; i < N; i++)
        insert(table, songs[i]);

    printf("\nFinal Hash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d : ", i);

        if (table[i] == -1)
            printf("EMPTY\n");
        else
            printf("%d\n", table[i]);
    }

    printf("\nSEARCH COMPARISON\n");
    printf("--------------------------------------\n");
    printf("ID\tHashing\tLinear Search\n");
    printf("--------------------------------------\n");

    int hashComp, linearComp;

    for (int i = 0; i < N; i++)
    {
        hashSearch(table, songs[i], &hashComp);
        linearSearch(songs, N, songs[i], &linearComp);

        printf("%d\t%d\t%d\n",
               songs[i], hashComp, linearComp);
    }

    return 0;
}