#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int array[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%100 +1;
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("/n");
    for(int i = 0; i < size; i++)
    {
        for(int j=0; j< size-1; j++)
        {
            if(array[j]> array[j+1])
            {
                int swap = array[j];
                array[j] = array[j+1];
                array[j+1] = array[swap];
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 0;
}
