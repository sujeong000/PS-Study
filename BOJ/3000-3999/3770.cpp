#include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 struct FenwickTree {
 	vector<int> tree;

 	FenwickTree(int n) : tree(n+1) {};

 	int sum(int pos) {
 		int ret = 0;
 		while (pos > 0) {
 			ret += tree[pos];
 			pos &= (pos - 1);
 		}

 		return ret;
 	}

 	void add(int pos, int val) {
 		while (pos < tree.size()) {
 			tree[pos] += val;
 			pos += (pos & -pos);
 		}
 	}
 };

 int main()
 {
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);

    int testcase;
    cin >> testcase;
    
    for (int t = 1; t <= testcase; t++) {
        vector<pair<int, int>> edges;
        
        int N, M, K;
     	cin >> N >> M >> K;
        
     	FenwickTree fwt(1001);
        
     	for (int i = 0; i < K; i++) {
     		int s, e;
     		cin >> s >> e;
     		edges.push_back({s, e});
     	}
    
     	sort(edges.begin(), edges.end());
        
     	long long result = 0;
     	for (int i = 0; i < K; i++) {
     	    if (edges[i].second != M) {
     	        result += fwt.sum(M - edges[i].second);
     	    }
     	    fwt.add(M + 1 - edges[i].second, 1);
     	}
     	cout << "Test case " << t << ": " << result << "\n";
    }

 	return 0;
 }
