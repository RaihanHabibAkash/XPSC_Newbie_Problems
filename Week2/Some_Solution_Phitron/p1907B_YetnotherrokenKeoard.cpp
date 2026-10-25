// Problem: B. YetnotherrokenKeoard
// Platform: Codeforces
// Rating: 1000
// Link: https://codeforces.com/problemset/problem/1907/B
// Solved: stacks, Array sorting & indexing
/*
Polycarp has a problem — his laptop keyboard is broken.

Now, when he presses the 'b' key, it acts like an unusual backspace: it deletes the last (rightmost) lowercase letter in the typed string. If there are no lowercase letters in the typed string, then the press is completely ignored.

Similarly, when he presses the 'B' key, it deletes the last (rightmost) uppercase letter in the typed string. If there are no uppercase letters in the typed string, then the press is completely ignored.

In both cases, the letters 'b' and 'B' are not added to the typed string when these keys are pressed.

Consider an example where the sequence of key presses was "ARaBbbitBaby". In this case, the typed string will change as follows: "" →A
 "A" →R
 "AR" →a
 "ARa" →B
 "Aa" →b
 "A" →b
 "A" →i
 "Ai" →t
 "Ait" →B
 "it" →a
 "ita" →b
 "it" →y
 "ity".

Given a sequence of pressed keys, output the typed string after processing all key presses.

Input
The first line of the input data contains an integer t
 (1≤t≤1000
), the number of test cases in the test.

The following contains t
 non-empty lines, which consist of lowercase and uppercase letters of the Latin alphabet.

It is guaranteed that each line contains at least one letter and the sum of the lengths of the lines does not exceed 106
.

Output
For each test case, output the result of processing the key presses on a separate line. If the typed string is empty, then output an empty line.

Example
InputCopy
12
ARaBbbitBaby
YetAnotherBrokenKeyboard
Bubble
Improbable
abbreviable
BbBB
BusyasaBeeinaBedofBloomingBlossoms
CoDEBARbIES
codeforces
bobebobbes
b
TheBBlackbboard
OutputCopy
ity
YetnotherrokenKeoard
le
Imprle
revile

usyasaeeinaedofloominglossoms
CDARIES
codeforces
es

helaoard


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      int n, m = 3;
      cin >> n;
      map<string, vector<int>> mp;
      for (int i = 1;i <= m;i++) {
         for (int j = 1;j <= n;j++) {
            string s;
            cin >> s;
            mp[s].push_back(i);
         }
      }

      // for (auto [x, y] : mp) {
      //    cout << x << " -> ";
      //    for (auto val : y) {
      //       cout << val << " ";
      //    }
      //    cout << '\n';
      // }

      vector<int> ans(m + 1);
      // 1 = 2
      // 2 = 2
      // 3 = 6

      for (auto [x, y] : mp) {
         vector<int> v = y;
         if (v.size() == 1) {
            ans[v[0]] += 3;
         }
         if (v.size() == 2) {
            ans[v[0]]++;
            ans[v[1]]++;
         }
      }

      for (int i = 1;i <= m;i++) {
         cout << ans[i] << " ";
      }
      cout << '\n';

   }
   return 0;
}