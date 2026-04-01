//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    string arrangeHorses(int n, const vector<pair<int, int>> &data)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> in_degree(n + 1, 0);
        for (const auto &pair : data)
        {
            int a = pair.first;
            int b = pair.second;
            graph[a].push_back(b);
            in_degree[b]++;
        }
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int horse = 1; horse <= n; horse++)
        {
            if (in_degree[horse] == 0)
            {
                min_heap.push(horse);
            }
        }

        string result;
        while (!min_heap.empty())
        {
            int current_horse = min_heap.top();
            min_heap.pop();
            result += to_string(current_horse);
            for (int neighbor : graph[current_horse])
            {
                in_degree[neighbor]--;
                // If in-degree becomes 0, add to the heap
                if (in_degree[neighbor] == 0)
                {
                    min_heap.push(neighbor);
                }
            }
        }
        if (result.length() != n)
        {
            return ""; // Cycle detected or not all horses are included
        }

        return result;
    }

    // code here
}
}
;

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        vector<vector<int>> data(m, vector<int>(2));
        Matrix::input(data, m, 2);

        Solution obj;
        vector<int> res = obj.arrangingHorses(n, m, data);

        Array::print(res);
    }
}

// } Driver Code Ends