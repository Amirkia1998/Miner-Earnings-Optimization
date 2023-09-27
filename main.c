#include <stdio.h>
#include <limits.h>
#define MAX 100

//PROTOTYPES
int maxSubarraySum(int array[MAX], int l, int r);
int findMaxC(int array[MAX], int l, int r);
int maxOfThree(int a, int b, int c);
int bruteForce(int array[MAX], int l, int r);

//GLOBAL VARS
int begin, end, bruteBegin, bruteEnd, gMax;

//#########################################################################################################
//========================================================== MAIN =========================================
//#########################################################################################################
int main(void) {
    int array[MAX], N;  // array: values    N: size of array
    int i;
    int answer;

    printf("Please Enter number of Elements: ");
    scanf("%d", &N);

    for ( i = 0; i < N; i++)
    {
        printf("Enter %d. Element: ", i);
        scanf("%d", &array[i]);
    }
    
    // recursive function (Divide and Conquer)
    answer = maxSubarraySum(&array, 0, N-1);    
    printf("\nLargest Gain = %d\nSequence: %d-%d", answer, begin, end);

    // Brute Force Approach
    printf("\n-------------------\nBrute Force Approach Result = %d", bruteForce(&array, 0, N-1));
    printf("\nSequence: %d-%d", bruteBegin, bruteEnd);


    printf("\n\n\nEND");
    exit(0);
}


//#########################################################################################################
//========================================================== FUNCTIONS ====================================
//#########################################################################################################
// recursive function
int maxSubarraySum(int array[MAX], int l, int r) {
    int maxL, maxR, maxC, max, m;

    if (l<r)
    {
        m = (l+r)/2;    // m:median

        maxL = maxSubarraySum(array, l, m);     // maxL:maximum sum of left subarray
        maxR = maxSubarraySum(array, m+1, r);   // maxL:maximum sum of right subarray
        maxC = findMaxC(array, l, r);           // maxL:maximum sum of crossed subarray
        
        max = maxOfThree(maxL, maxC, maxR);

        if (max == maxL && max > gMax)
        {
            gMax = max;
            begin = l;
            end = m-1;
        }
        else if (max == maxR && max > gMax)
        {
            gMax = max;
            begin = m+1;
            end = r;
        }
        else if (max > gMax)
        {
            gMax = max;
        }
        
        return max;
    }
    else return array[l];   // or array[r]
}


// finds maximum of subarrays which cross median and contains both left and right elements
int findMaxC(int array[MAX], int l, int r) {
    int m, maxL=INT_MIN, maxR=INT_MIN, maxC=INT_MIN;
    int i, sum=0;
    int startIndex, endIndex;

    m = (l+r)/2;

    if (l == r)
    {
        return array[l];    // or array[r]
    }
    else
    {
        i = m;
        while (i>=l)
        {
            sum += array[i];
            if (sum > maxL)
            {
                maxL = sum;
                startIndex = i;
            }

            i--;
        }
        begin = startIndex;

        sum = 0;
        i = m+1;
        while (i <= r)
        {
            sum += array[i];
            if (sum > maxR)
            {
                maxR = sum;
                endIndex = i;
            }

            i++;
        }
        end = endIndex;

        maxC = maxR + maxL;

        return maxC;
    }
}


// finds maximum of three numbers
int maxOfThree(int a, int b, int c) {
    int i, maxOfThree, arr[MAX];

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    maxOfThree = INT_MIN;

    for ( i = 0; i < 3; i++)
    {
        if (arr[i] > maxOfThree)
        {
            maxOfThree = arr[i];
        }
        
    }
    
    return maxOfThree;
}


int bruteForce(int array[MAX], int l, int r) {
    int i, j, sum, max=INT_MIN;

    for ( i = l; i <= r; i++)
    {
        sum = 0;
        for ( j = i; j <= r; j++)
        {
            sum += array[j];
            if (sum > max)
            {
                max = sum;
                bruteBegin = i;
                bruteEnd = j;
            }
        }
    }
    
    return max;
}

