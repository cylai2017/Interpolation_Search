
#include <stdio.h>

int Interpolation_Search(int* array, int array_length, int key){
    int tmp;
    for (int i = 0; i <( array_length-1); i++)
    {
        for (int j = 0; j < (array_length-i-1); j++)
        {
            if (array[j] > array[j+1]) // Decreasing order
            {
                tmp= array[j]; // swap
                array[j]   = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    
    int low, middle, high,Search_Time;
    low=0;
    high=array_length-1;
    Search_Time = 0;
    while(low<=high)
    {
        middle=(high-low)*(key-array[low])/(array[high]-array[low])+ low; // Formula
        Search_Time++;
        if(middle<low || middle>high) return (-1);
        
        if(key<array[middle]) {high=middle-1;}
        else if(key>array[middle]) {low=middle+1;}
        else {
            printf("Searching Times : %d\n",Search_Time);
            return middle; // Return the index of where the key is
        }
    }
    return -1; // If the key can not be found in array
}
