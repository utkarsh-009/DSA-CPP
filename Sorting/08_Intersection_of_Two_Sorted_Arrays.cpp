#include <bits/stdc++.h>
using namespace std;


// To print common elements of two array (excluding their duplicates)
void intersectionOf2UnsortedArr(int a[], int b[], int m, int n)
{
    // Initially sorting two given arrays
    sort(a, a + m);
    sort(b, b + n);

    int i = 0, j = 0;
    while (i < m && j < n) // Now we will compare one array element with other array element
    {
        // If there are more than one elements with same value, we will consider only the first and ignore other equal value elements
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        // Comparing elements of two array
        else if (a[i] > b[j])
        {
            j++;
        }
        else if (b[j] > a[i])
        {
            i++;
        }
        else // This condition is when a[i] == b[j], which will be the intersection between two array
        {
            cout << a[i] << " ";
            i++;
        }
    }
}

int main()
{
    int a1[] = {10, 30, 60, 20, 40};
    int a2[] = {20, 2, 20, 30};

    intersectionOf2UnsortedArr(a1, a2, 5, 4);
}