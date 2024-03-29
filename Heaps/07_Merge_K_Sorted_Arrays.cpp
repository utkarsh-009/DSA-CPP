/*
Input:
    K = 3
    arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
    Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted arrays of size 3, 3, 3. arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
*/

#define ppi pair<int, pair<int, int>>

// [TC: O(k*k*logk) = (no of arrays)*(size of arrays)*log(no of arrays)]
class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        // pair<int,pair<int,int>> => <value, <pos of array, index of value in array>>
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

        // Initially, we are pushing first element of all k sorted array.
        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }

        // Now, we make sure that size of heap remains k, i.e.
        //  As soon as we put the minimum element of a specific array in ans => We push the next element of that array in heap.
        while (!pq.empty())
        {
            int mini = pq.top().first;
            int pos = pq.top().second.first;
            int idx = pq.top().second.second;
            pq.pop();

            ans.push_back(mini);
            idx++;

            if (idx < k)
            {
                pq.push({arr[pos][idx], {pos, idx}});
            }
        }

        return ans;
    }
};