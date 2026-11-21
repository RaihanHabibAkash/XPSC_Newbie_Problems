// Problem: D. Epic Transformation
// Platform: Codeforces
// Rating: 1400
// Link: https://codeforces.com/contest/1506/problem/D
// Solved: STL map, STL Priority Queue
/*
You are given an array a
 of length n
 consisting of integers. You can apply the following operation, consisting of several steps, on the array a
 zero or more times:

you select two different numbers in the array ai
 and aj
;
you remove i
-th and j
-th elements from the array.
For example, if n=6
 and a=[1,6,1,1,4,4]
, then you can perform the following sequence of operations:

select i=1,j=5
. The array a
 becomes equal to [6,1,1,4]
;
select i=1,j=2
. The array a
 becomes equal to [1,4]
.
What can be the minimum size of the array after applying some sequence of operations to it?

Input
The first line contains a single integer t
 (1≤t≤104
). Then t
 test cases follow.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) is length of the array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum possible size of the array after applying some sequence of operations to it.

Example
InputCopy
5
6
1 6 1 1 4 4
2
1 2
2
1 1
5
4 5 4 5 4
6
2 3 2 1 3 1
OutputCopy
0
0
2
1
0
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        map<int,int> mp;

        while(n--) {
            int val; cin >> val;
            mp[val]++;
        }

        priority_queue<int> pq;
        for(auto [x,y] : mp) pq.push(y);

        while(pq.size() >= 2) {
            int x, y;
            x = pq.top(), pq.pop();
            y = pq.top(), pq.pop();

            x--, y--;

            if(x > 0) pq.push(x);
            if(y > 0) pq.push(y);
        }

        // Max 1 element left
        int ans = 0;
        if(!pq.empty()) ans += pq.top();

        cout << ans << endl;
    }

    return 0;
}