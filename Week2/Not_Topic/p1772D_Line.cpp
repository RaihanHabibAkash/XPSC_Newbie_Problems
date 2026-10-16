// Problem: D. Line
// Platform: Codeforces
// Rating: 1100
// Link: https://codeforces.com/contest/1722/problem/D
// Solved: index logic, sorting
/*
There are n
 people in a horizontal line, each looking either to the left or the right. Each person counts the number of people in the direction they are looking. The value of the line is the sum of each person's count.

For example, in the arrangement LRRLL, where L stands for a person looking left and R stands for a person looking right, the counts for each person are [0,3,2,3,4]
, and the value is 0+3+2+3+4=12
.

You are given the initial arrangement of people in the line. For each k
 from 1
 to n
, determine the maximum value of the line if you can change the direction of at most k
 people.

Input
The input consists of multiple test cases. The first line contains an integer t
 (1≤t≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
) — the length of the line.

The following line contains a string consisting of n
 characters, each of which is either L or R, representing a person facing left or right, respectively — the description of the line.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Please note that the answer for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

Output
For each test case, output n
 space-separated non-negative integers — the maximum value of the line if you can change the direction of at most k
 people for each k
 from 1
 to n
, inclusive.

Example
InputCopy
6
3
LLR
5
LRRLL
1
L
12
LRRRLLLRLLRL
10
LLLLLRRRRR
9
LRLRLRLRL
OutputCopy
3 5 5 
16 16 16 16 16 
0 
86 95 98 101 102 102 102 102 102 102 102 102 
29 38 45 52 57 62 65 68 69 70 
44 50 54 56 56 56 56 56 56 
Note
In the first test case:

k=1
: change the direction of 1
 person to make the line RLR. The total value is 2+1+0=3
.
k=2
: change the direction of 2
 people to make the line RLL. The total value is 2+1+2=5
.
k=3
: change the direction of 2
 people to make the line RLL. The total value is 2+1+2=5
. Note that you have to change the direction of at most k
 people.
In the second test case, it is optimal to only change the direction of the first person for all k
 from 1
 to 5
 (that is, make the line RRRLL).
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        vector<ll> v;
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            char c; cin >> c;
            int l = i-0, r = n-i-1;

            if(c == 'L') {
                if(l < r) v.push_back(r-l);
                sum += l; 
            }
            else {
                if(l > r) v.push_back(l-r);
                sum += r;
            }
        }
        sort(v.begin(), v.end(), greater<ll>());

        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            cout << sum << " ";
        }
        for(int i = v.size(); i < n; i++) cout << sum << " ";
        cout << endl;
    }

    return 0;
}