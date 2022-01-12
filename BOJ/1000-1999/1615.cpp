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

vector<pair<int, int>> edges;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	FenwickTree fwt(N);
	
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		edges.push_back({s, e});
	}
	
	sort(edges.begin(), edges.end());
	
	long long result = 0;
	for (int i = 0; i < M; i++) {
	    if (edges[i].second != N) {
	        result += fwt.sum(N - edges[i].second);
	    }
	    fwt.add(N + 1 - edges[i].second, 1);
	}
	cout << result;

	return 0;
}
