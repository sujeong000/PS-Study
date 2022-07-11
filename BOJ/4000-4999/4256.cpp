#include <iostream>
#include <cstring>

using namespace std;

int N;
int preorder[1001], inorder[1001], pos[1001];

void postorder(int pLo, int pHi, int iLo, int iHi) {
    if (pLo > pHi) return;
    
    int root = preorder[pLo];
    int lSize = pos[root] - iLo;
    
    postorder(pLo+1, pLo+lSize, iLo, iLo+lSize-1);
    postorder(pLo+lSize+1, pHi, iLo+lSize+1, iHi);
    
    cout << root << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> preorder[i];
        for (int i=0; i<N; i++) {
            cin >> inorder[i];
            pos[inorder[i]] = i;
        }
        
        postorder(0, N-1, 0, N-1);
        cout << "\n";
    }
  
    return 0;
}
