// Problem: C. Boxes Packing
// Platform: Codeforces
// Rating: 1200
// Link: https://codeforces.com/problemset/problem/903/C
// Solved: Map
/*
Mishka has got n empty boxes. For every i (1 ≤ i ≤ n), i-th box is a cube with side length ai.

Mishka can put a box i into another box j if the following conditions are met:

i-th box is not put into another box;
j-th box doesn't contain any other boxes;
box i is smaller than box j (ai < aj).
Mishka can put boxes into each other an arbitrary number of times. He wants to minimize the number of visible boxes. A box is called visible iff it is not put into some another box.

Help Mishka to determine the minimum possible number of visible boxes!

Input
The first line contains one integer n (1 ≤ n ≤ 5000) — the number of boxes Mishka has got.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109), where ai is the side length of i-th box.

Output
Print the minimum possible number of visible boxes.

Examples
InputCopy
3
1 2 3
OutputCopy
1
InputCopy
4
4 2 4 3
OutputCopy
2
Note
In the first example it is possible to put box 1 into box 2, and 2 into 3.

In the second example Mishka can put box 2 into box 3, and box 4 into box 1.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        mp[val]++;
    }

    int mx = 0;
    for(auto [x, y] : mp) mx = max(y, mx);
    
    cout << mx << endl;
    
    return 0;
}