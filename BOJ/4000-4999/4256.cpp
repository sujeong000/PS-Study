#include <iostream>
#include <cstring>

using namespace std;

int N;
int preorder[1001], inorder[1001], pos[1001];
int l[1001], r[1001];

void postorder(int curr) {
    if (curr == 0) return;
    
    postorder(l[curr]);
    postorder(r[curr]);
    cout << curr << " ";
}

int regenerateTree(int pLo, int pHi, int iLo, int iHi) {
    if (pLo == pHi) return preorder[pLo];
    if (pLo > pHi) return 0;
    
    int root = preorder[pLo];
    int lSize = pos[root] - iLo;
    
    l[root] = regenerateTree(pLo+1, pLo+lSize, iLo, iLo+lSize-1);
    r[root] = regenerateTree(pLo+lSize+1, pHi, iLo+lSize+1, iHi);
    
    return root;
}

void initTestcase() {
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        initTestcase();
        
        cin >> N;
        for (int i=0; i<N; i++) cin >> preorder[i];
        for (int i=0; i<N; i++) {
            cin >> inorder[i];
            pos[inorder[i]] = i;
        }
        
        int root = regenerateTree(0, N-1, 0, N-1);
        postorder(root);
        
        cout << "\n";
    }
  
    return 0;
}
