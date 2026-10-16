// Problem: A. Two Frogs
// Platform: Codeforces
// Rating: 800
// Link: https://codeforces.com/problemset/problem/2055/A
// Solved: Frog can't be at same place & it can't go out of 1 <= frog <= n (frog can't go outside of this range)
/*
Roaming through the alligator-infested Everglades, Florida Man encounters a most peculiar showdown.
There are n
 lilypads arranged in a row, numbered from 1
 to n
 from left to right. Alice and Bob are frogs initially positioned on distinct lilypads, a
 and b
, respectively. They take turns jumping, starting with Alice.

During a frog's turn, it can jump either one space to the left or one space to the right, as long as the destination lilypad exists. For example, on Alice's first turn, she can jump to either lilypad a−1
 or a+1
, provided these lilypads are within bounds. It is important to note that each frog must jump during its turn and cannot remain on the same lilypad.

However, there are some restrictions:

The two frogs cannot occupy the same lilypad. This means that Alice cannot jump to a lilypad that Bob is currently occupying, and vice versa.
If a frog cannot make a valid jump on its turn, it loses the game. As a result, the other frog wins.
Determine whether Alice can guarantee a win, assuming that both players play optimally. It can be proven that the game will end after a finite number of moves if both players play optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first and only line of each test case contains three integers n
, a
, and b
 (2≤n≤100
, 1≤a,b≤n
, a≠b
) — the number of lilypads, and the starting positions of Alice and Bob, respectively.

Note that there are no constraints on the sum of n
 over all test cases.

Output
For each test case, print a single line containing either "YES" or "NO", representing whether or not Alice has a winning strategy.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
2 1 2
3 3 1
4 2 3
5 2 4
7 6 2
OutputCopy
NO
YES
NO
YES
YES
Note
In the first test case, Alice has no legal moves. Therefore, Alice loses on the first turn.

In the second test case, Alice can only move to lilypad 2
. Then, Bob has no legal moves. Therefore, Alice has a winning strategy in this case.

In the third test case, Alice can only move to lilypad 1
. Then, Bob can move to lilypad 2
. Alice is no longer able to move and loses, giving Bob the win. It can be shown that Bob can always win regardless of Alice's moves; hence, Alice does not have a winning strategy.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n, x, y; cin >> n >> x >> y;

        while(true) {
            if(x < y) {
                if(x+1 < y) x++;
                else if(x-1 > 0) x--;
                else {
                    cout << "NO" << endl;
                    break;
                }

                if(x < y-1) y--;
                else if(y+1 <= n) y++;
                else {
                    cout << "YES" << endl;
                    break;
                }
            }
            else { // x > y
                if(y < x-1) x--;
                else if(x+1 <= n) x++;
                else {
                    cout << "NO" << endl;
                    break;
                }

                if(y+1 < x) y++;
                else if(y-1 > 0) y--;
                else {
                    cout << "YES" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}