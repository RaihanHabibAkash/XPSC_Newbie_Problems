// Problem: C. Numbers on Whiteboard
// Platform: Codeforces
// Rating: 1000
// Link: https://codeforces.com/contest/1430/problem/C
// Solved: 2 stack, Even-Odd
/*
Numbers 1,2,3,…n
 (each integer from 1
 to n
 once) are written on a board. In one operation you can erase any two numbers a
 and b
 from the board and write one integer a+b2
 rounded up instead.

You should perform the given operation n−1
 times and make the resulting number that will be left on the board as small as possible.

For example, if n=4
, the following course of action is optimal:

choose a=4
 and b=2
, so the new number is 3
, and the whiteboard contains [1,3,3]
;
choose a=3
 and b=3
, so the new number is 3
, and the whiteboard contains [1,3]
;
choose a=1
 and b=3
, so the new number is 2
, and the whiteboard contains [2]
.
It's easy to see that after n−1
 operations, there will be left only one number. Your goal is to minimize it.

Input
The first line contains one integer t
 (1≤t≤1000
) — the number of test cases.

The only line of each test case contains one integer n
 (2≤n≤2⋅105
) — the number of integers written on the board initially.

It's guaranteed that the total sum of n
 over test cases doesn't exceed 2⋅105
.

Output
For each test case, in the first line, print the minimum possible number left on the board after n−1
 operations. Each of the next n−1
 lines should contain two integers — numbers a
 and b
 chosen and erased in each operation.

Example
InputCopy
1
4
OutputCopy
2
2 4
3 3
3 1


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        stack<int> odd, even;

        cout << 2 << endl;
        if(n <= 2) {
            cout << 1 << " " << 2 << endl;
            continue;
        }

        for(int i = 1; i <= n; i++) {
            if(i % 2) odd.push(i);
            else even.push(i);
        }

        int i = 0;
        while(odd.size() >= 2 || even.size() >= 2) {
            int l, r;
            if(even.empty() || (odd.size() >= 2 && odd.top() > even.top()) ) {
                l = odd.top();
                odd.pop();
                r = odd.top(); 
                odd.pop();

                cout << l << " " << r << endl;
                if(( ((l+r)/2) % 2) == 0) even.push(((l+r)/2));
                else odd.push(((l+r)/2));
            }
            else if(odd.empty() || (even.size() >= 2 && even.top() > odd.top())){
                l = even.top();
                even.pop();
                r = even.top();
                even.pop();

                cout << l << " " << r << endl;
                if(( ((l+r)/2) % 2) == 0) even.push(((l+r)/2));
                else odd.push(((l+r)/2));
            }
        }
    }

    return 0;
}