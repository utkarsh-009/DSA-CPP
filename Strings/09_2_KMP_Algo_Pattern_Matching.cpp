#include <bits/stdc++.h>
using namespace std;

/*
KMP Algorithm
- Intution: The key idea behind the KMP algorithm is to avoid unnecessary character comparisons by utilizing information
about the pattern itself. It pre-processes the pattern before performing the actual search. This helps to unnecessary character
comparisons by allowing us to skip ahead in the text when a mismatch occurs.
- Preprocessing: Length of longest proper prefix that are also suffix of the pattern.

*/
void fillLPS(string &pat, int *lps)
{
    int n = pat.length();
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while (i < n)
    {
        // Case1: Characters match
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        // Case2: Characters do not match
        else
        {
            // Case2a: there is no proper prefix that matches the suffix at that particular index i.e. lps not found
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            // Case2b: we backtrack to a potential position where a longer proper prefix that is also a suffix may exist.
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void KMP(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];

    // pre-processing the pattern by using longest prefix suffix
    fillLPS(pat, lps);

    // KMP algorithm
    int i = 0, j = 0;
    while (i < n)
    {
        // If the characters match, it means we have found a potential partial match between the pattern and the text
        // Hence, we check for their next characters
        if (j < m && txt[i] == pat[j])
        {
            i++;
            j++;
        }
        // if characters do not match

        // if j has completed traversing pattern string => pattern is found starting from index `i - j` in the text
        if (j == m)
        {
            cout << "Pattern Found at: " << i - j << endl;
            // continue searching for any further occurrences of the pattern.
            j = lps[j - 1];
        }
        // if j has not completed traversing the pattern
        else if (i < n && txt[i] != pat[j])
        {
            // j == 0 => reached the beginning of the pattern without finding partial match => we check for next character in txt
            if (j == 0)
                i++;

            // j != 0 => backtrack to a position in the pattern where we can potentially find another partial match and
            // continue the search from there.
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string txt = "ababcababaad", pat = "ababa";
    KMP(pat, txt);
    return 0;
}

// void fillLPS(string str, int *lps){
//     int n=str.length(),len=0;
//     lps[0]=0;
//     int i=1;
//     while(i<n){
//         if(str[i]==str[len])
//         {len++;lps[i]=len;i++;}
//         else
//         {if(len==0){lps[i]=0;i++;}
//             else{len=lps[len-1];}
//         }
//     }
// }
// void KMP(string pat,string txt){
//     int N=txt.length();
//     int M=pat.length();
//     int lps[M];
//     fillLPS(pat,lps);
//     int i=0,j=0;
//     while(i<N){
//         if(pat[j]==txt[i]){i++;j++;}

//         if (j == M) {
//             printf("Found pattern at index %d ", i - j);
//             j = lps[j - 1];
//         }
//         else if (i < N && pat[j] != txt[i]) {
//             if (j == 0)
//                 i++;
//             else
//                 j = lps[j - 1];
//         }
//     }
// }