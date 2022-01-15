/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int M, x, set;
string query;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> M;
	
	for (int i = 0; i < M; i++) {
	    cin >> query;
	    
	    if (query == "all") {
	        set = (1 << 21) - 1;
	    }
	    else if (query == "empty") {
	        set = 0;
	    }
	    else {
	        cin >> x;
	        
	        if (query == "add") {
	            set |= (1 << x);
	        }
	        else if (query == "remove") {
	            set &= ~(1 << x);
	        }
	        else if (query == "check") {
	            if (set & (1 << x)) {
	                cout << 1 << "\n";
	            }
	            else {
	                cout << 0 << "\n";
	            }
	        }
	        else if (query == "toggle") {
	            set ^= (1 << x);
	        }
	       
	    }
	}

    return 0;
}
