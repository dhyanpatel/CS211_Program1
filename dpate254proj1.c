#include <stdio.h>
#include <stdlib.h>

// Copies the elements of one array to the next
void makeArrayCopy(int fromArray[], int toArray[], int size) {
    int i;
    for (i = 0; i < size; i++) { // Loops through every element in the array
        toArray[i] = fromArray[i]; // Sets the element of the new array to the same element from the last
    }
}

void myFavoriteSort(int arr[], int size) { // Insertion Sort
    int i, j, temp;
    for (i = 1; i < size; i++) { // Loops through array
        temp = arr[i]; // Sets Temporary Variable
        j = i - 1;

        while (j >= 0 && arr[j] > temp) { // Sets bounds for Loop and inserts
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; // Sets newest element to the lowest element
    }
}

int linSearch(int arr[], int size, int target, int *numComparisons) { // Linear Search
    int i;
    for (i = 0; i < size; i++) { // Loops Through array
        *numComparisons += 1; // Increases counter for number of Comparisons
        if (arr[i] == target) { // Checks if you found the target
            return i; // Returns the position of the target
        }
    }
    return -1; // Returns -1 if not found
}

int binSearch(int arr[], int size, int target, int *numComparisons) { // Binary Search
    int min = 0; // Lower bound
    int max = size - 1; // Upper Bound
    while (min <= max) { // Continues as long as the lower is <= the upper bound
        *numComparisons += 1; // Increases counter for number of comparisons
        int mid = min + (max - min) / 2; // Finds the middle of the data set
        if (target == arr[mid]) { // Checks if you found the target
            return mid; // Returns the element it was found at
        }
        if (target > arr[mid]) { // Checks if the target is larger than the middle
            min = mid + 1; // Sets the minimum to the old mid
        } else { // Checks if the target is smaller than the middle
            max = mid - 1; // Sets the max to the old mid
        }
    }
    return -1; // Returns -1 if not found
}

int main(int argc, char **argv) {

    int *arr;
    int allocated = 0;
    arr = (int *) malloc(allocated * sizeof(int)); // Sets size of array
    int val;

    /* prompt the user for input */
    printf("Enter in a list of numbers ito be stored in a dynamic array.\n");
    printf("End the list with the terminal value of -999\n");

    /* loop until the user enters -999 */
    int step = 0;
    scanf("%d", &val);
    while (val != -999) // Loops till it finds -999
    {
        if (step >= allocated) { // Increases the allocation of the array
            int *temp = arr;
            arr = (int *) malloc((allocated + 1) * sizeof(int)); // Makes new array with a larger size
            int i;
            for (i = 0; i < allocated; i++) { // Copies the array over
                arr[i] = temp[i];
            }
            free(temp); // Frees space
            allocated++;
        }
        /* store the value into an array */
        arr[step] = val;
        step++;
        /* get next value */
        scanf("%d", &val);
    }

    /* call function to make a copy of the array of values */
    int newArr[allocated];
    makeArrayCopy(arr, newArr, allocated);
    /* call function to sort one of the arrays */
    myFavoriteSort(arr, allocated);
    /* loop until the user enters -999 */
    printf("Enter in a list of numbers to use for searching.  \n");
    printf("End the list with a terminal value of -999\n");
    int numComparisons = 0;
    scanf("%d", &val); // Scans for infput
    printf("Allocated %d", allocated);
    while (val != -999) // Loops till it gets a -999 as input
    {
        numComparisons = 0;
        printf("Value Search For %d\n ", val);
        int temp = linSearch(newArr, allocated, val, &numComparisons); // Runs Linear Search
        /* call function to use the value in a linear search on the unsorted array */
        /* print out info about the linear search results  */
        printf("    Linear Search: ");
        if (temp == -1) { // Checks if the value was found
            printf("Not Found. ");
        } else {
            printf("Found. ");
        }
        printf("Comparisons: %d, Index: %d\n", numComparisons, temp);
        /* call function to use the value in a binary search on the sorted array */

        numComparisons = 0;
        temp = binSearch(arr, allocated, val, &numComparisons); // Runs Binary Search
        /* print out info about the binary search results  */
        printf("     Binary Search: ");
        if (temp == -1) { // Check if value is found
            printf("Not Found. ");
        } else {
            printf("Found, ");
        }
        printf("Comparisons: %d, Index: %d\n", numComparisons, temp);

        /* get next value */
        scanf("%d", &val);
    }


    printf("\nGood bye\n");
    return 0;
}
