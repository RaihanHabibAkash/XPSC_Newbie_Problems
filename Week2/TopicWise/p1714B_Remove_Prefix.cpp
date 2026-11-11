// Problem: B. Remove Prefix
// Platform: Codeforces
// Rating: 800
// Link: https://codeforces.com/contest/1714/problem/B
// Solved: Freq Array
/*
Polycarp was presented with some sequence of integers a
 of length n
 (1≤ai≤n
). A sequence can make Polycarp happy only if it consists of different numbers (i.e. distinct numbers).

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves.

In one move, he can:

remove the first (leftmost) element of the sequence.
For example, in one move, the sequence [3,1,4,3]
 will produce the sequence [1,4,3]
, which consists of different numbers.

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence a
, after removing which all values in the sequence will be unique.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of two lines.

The first line contains an integer n
 (1≤n≤2⋅105
) — the length of the given sequence a
.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — elements of the given sequence a
.

It is guaranteed that the sum of n
 values over all test cases does not exceed 2⋅105
.

Output
For each test case print your answer on a separate line — the minimum number of elements that must be removed from the beginning of the sequence so that all remaining elements are different.

Example
InputCopy
5
4
3 1 4 3
5
1 1 1 1 1
1
1
6
6 5 4 3 2 1
7
1 2 1 7 1 2 1
OutputCopy
1
4
0
0
5
Note
The following are the sequences that will remain after the removal of prefixes:

[1,4,3]
;
[1]
;
[1]
;
[6,5,4,3,2,1]
;
[2,1]
.
It is easy to see that all the remaining sequences contain only distinct elements. In each test case, the shortest matching prefix was removed.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        int arr[n];
        vector<int> freq(n+1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            freq[arr[i]]++;

            if(freq[arr[i]] > 1) cnt++;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) break;

            if(freq[arr[i]] > 1) {
                freq[arr[i]]--;
                cnt--;
            }

            ans++;
        }

        cout << ans << endl;

    }

    return 0;
}