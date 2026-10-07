#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cs; cin >> cs;
    while(cs--) {
        int n; cin >> n;
	    int sm = 100 - n;
	    
	    if(sm % 10) sm -= sm % 10;
	        
	    cout << sm << endl;
    }

    return 0;
}