#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int r, c, age;
    bool dead;
};

int N, M, K;
vector<Tree> trees;
int food[11][11], A[11][11];

bool compareAge(const Tree& lhs, const Tree& rhs) {
    if (lhs.age > rhs.age) return true;
    else return false;
}

void spring() {
    for (int i=trees.size()-1; i>=0; i--) {
        int r = trees[i].r;
        int c = trees[i].c;
        int age = trees[i].age;
        
        if (food[r][c] < age) {
            trees[i].dead = true;
        }
        else {
            food[r][c] -= age;
            trees[i].age++;
        }
    }
}

void summer() {
    vector<Tree> liveTrees;
    
    for (auto tree: trees) {
        if (!tree.dead) liveTrees.push_back(tree);
        else food[tree.r][tree.c] += tree.age/2;
    }
    
    trees = liveTrees;
}

void fall() {
    int n = trees.size();
    for (int i=0; i<n; i++) {
        Tree tree = trees[i];
        
        if (tree.age % 5 != 0) continue;
        
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if (i == 0 && j == 0) continue;
                
                int nr = tree.r-i;
                int nc = tree.c-j;
                if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
                trees.push_back({nr, nc, 1, false});
            }
        }
    }
}

void winter() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            food[i][j] += A[i][j];
        }
    }
}

void simulate() {
    spring();
    summer();
    fall();
    winter();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> A[i][j];
            food[i][j] = 5;
        }
    }
    
    for (int i=0; i<M; i++) {
        int x, y, z; cin >> x >> y >> z;
        trees.push_back({x, y, z, false});
    }
    
    sort(trees.begin(), trees.end(), compareAge);
    
    for (int i=0; i<K; i++) simulate();
    
    cout << trees.size();

    return 0;
}
