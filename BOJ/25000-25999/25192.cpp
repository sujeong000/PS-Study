#include <iostream>
#include <set>

using namespace std;

int N;
set<string> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int ans = 0;
    
    string chat;
    for (int i=0; i<N; i++) {
        cin >> chat;
        
        if (chat == "ENTER") {
            ans += st.size();
            st.clear();
        }
        else st.insert(chat);
    }
    
    ans += st.size();
    
    cout << ans;
    
    return 0;
}
