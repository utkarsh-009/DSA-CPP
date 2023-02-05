#include <bits/stdc++.h>
using namespace std;
#define d 256
const int q = 101;

/*
Raben Karp Search uses hash function + rolling hash concept.
NOTE: length of text is N and length of pattern is M
- We compute the hash function initially for M length
- Formula for Rolling hash Ti will be => Ti+1 = d(Ti - txt[i]*d^(M-1)) + txt[i+m], here d => No of chars used in txt.
ex => txt: "abdabcbabc", pat: "abc"
T0 = 1*5^2 + 2*5^1 + 4*5^0 = 39
T1 = 5*(T0 - txt[0]*5^(2)) + txt[3] =>  5*(T0 - 1*5^(2)) + 1 = 71
- NOTE: Computations are done under modulo q, so as to prevent overflow.
*/

// TC: O((N-M+1)*M)
void RKSearch(string pat, string txt, int M, int N)
{

    // Pre-Compute value of (d^(M-1))%q (As the term is repeatly going to be used in rolling hash)
    int h = 1;
    for (int i = 1; i <= M - 1; i++)
        h = (h * d) % q;

    // Compute hash function for P (pat String) and T0 (First window of length M in txt)
    int p = 0, t = 0;
    for (int i = 0; i < M; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    // Rolling Hash
    for (int i = 0; i <= (N - M); i++)
    {
        // Check for hit => We compare individual characters
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }

        // Compute hash function for next window i.e. ti+1 using ti
        if (i < N - M)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + M]) % q;
            if (t < 0) // if hash function becomes negative
                t = t + q;
        }
    }
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    cout << "All index numbers where pattern found: ";
    RKSearch(pat, txt, 4, 15);

    return 0;
}