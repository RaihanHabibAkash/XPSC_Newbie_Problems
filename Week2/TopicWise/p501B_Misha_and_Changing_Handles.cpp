// Problem: B. Misha and Changing Handles
// Platform: Codeforces
// Rating: 1100
// Link: https://codeforces.com/problemset/problem/501/B
// Solved: Map find & erase logic
/*
Misha hacked the Codeforces site. Then he decided to let all the users change their handles. A user can now change his handle any number of times. But each new handle must not be equal to any handle that is already used or that was used at some point.

Misha has a list of handle change requests. After completing the requests he wants to understand the relation between the original and the new handles of the users. Help him to do that.

Input
The first line contains integer q (1 ≤ q ≤ 1000), the number of handle change requests.

Next q lines contain the descriptions of the requests, one per line.

Each query consists of two non-empty strings old and new, separated by a space. The strings consist of lowercase and uppercase Latin letters and digits. Strings old and new are distinct. The lengths of the strings do not exceed 20.

The requests are given chronologically. In other words, by the moment of a query there is a single person with handle old, and handle new is not used and has not been used by anyone.

Output
In the first line output the integer n — the number of users that changed their handles at least once.

In the next n lines print the mapping between the old and the new handles of the users. Each of them must contain two strings, old and new, separated by a space, meaning that before the user had handle old, and after all the requests are completed, his handle is new. You may output lines in any order.

Each user who changes the handle must occur exactly once in this description.

Examples
InputCopy
5
Misha ILoveCodeforces
Vasya Petrov
Petrov VasyaPetrov123
ILoveCodeforces MikeMirzayanov
Petya Ivanov
OutputCopy
3
Petya Ivanov
Misha MikeMirzayanov
Vasya VasyaPetrov123
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int q; cin >> q;
    map<string, string> mp;

    while(q--) {
        string s1, s2; cin >> s1 >> s2;

        if(mp.find(s1) == mp.end()) mp[s2] = s1;
        else {
            string newS = mp[s1];
            mp.erase(s1);
            mp[s2] = newS;
        }
    }

    cout << mp.size() << endl;
    for(auto i = mp.begin(); i != mp.end(); i++) cout << i->second << " " <<  i->first << endl;
    // for(auto x : mp) cout << x.second << " " <<  x.first << endl;

    return 0;
}    