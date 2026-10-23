// Problem: C. Word Game
// Platform: Codeforces
// Rating: 800
// Link: https://codeforces.com/problemset/problem/1722/C
// Solved: Map(String, Vector<int>)
/*
Three guys play a game: first, each person writes down n
 distinct words of length 3
. Then, they total up the number of points as follows:

if a word was written by one person — that person gets 3 points,
if a word was written by two people — each of the two gets 1 point,
if a word was written by all — nobody gets any points.
In the end, how many points does each player have?
Input
The input consists of multiple test cases. The first line contains an integer t
 (1≤t≤100
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤1000
) — the number of words written by each person.

The following three lines each contain n
 distinct strings — the words written by each person. Each string consists of 3
 lowercase English characters.

Output
For each test case, output three space-separated integers — the number of points each of the three guys earned. You should output the answers in the same order as the input; the i
-th integer should be the number of points earned by the i
-th guy.

Example
InputCopy
3
1
abc
def
abc
3
orz for qaq
qaq orz for
cod for ces
5
iat roc hem ica lly
bac ter iol ogi sts
bac roc lly iol iat
OutputCopy
1 3 1 
2 2 6 
9 11 5 
Note
In the first test case:

The word abc
 was written by the first and third guys — they each get 1
 point.
The word def
 was written by the second guy only — he gets 3
 points.

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
        map<string, vector<int>> mp;

        for(int i = 1; i <= 3; i++)
            for(int j = 0; j < n; j++) {
                string s; cin >> s;
                mp[s].push_back(i);
            }

        int one = 0, two = 0, three = 0;
        for(auto [x,y] : mp) {
            if(y.size() == 2) {
                for(auto val : y) {
                    if(val == 1) one++;
                    else if(val == 2) two++;
                    else three++;
                }
            }
            if(y.size() == 1) {
                if(y[0] == 1) one += 3;
                else if(y[0] == 2) two += 3;
                else three += 3;
            }
        }

        cout << one << " " << two << " " << three << endl;
    }

    return 0;
}