#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll N, A, B, C, D, E, F;

ll three_face() {
    vector<ll> arr =
    { A+E+D, A+B+D, A+C+E, A+B+C,
      F+E+D, F+B+D, F+C+E, F+B+C
    };
    
    return *min_element(arr.begin(), arr.end()) * 4;
}

ll two_face() {
    vector<ll> arr =
    { A+E, A+D, A+B, A+C,
      F+E, F+D, F+B, F+C,
      E+D, E+C, C+B, B+D
    };
    
    return *min_element(arr.begin(), arr.end()) * (8*N-12);
}

ll one_face() {
    vector<ll> arr = {A, B, C, D, E, F};
    
    return *min_element(arr.begin(), arr.end()) * ((N-2)*(N-2) + 4*(N*N-N-2*(N-1)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> A >> B >> C >> D >> E >> F;
    if (N == 1) {
        vector<ll> arr = {A, B, C, D, E, F};
        cout << A+B+C+D+E+F - *max_element(arr.begin(), arr.end());
    }
    else {
        cout << three_face() + two_face() + one_face();   
    }

    return 0;
}
