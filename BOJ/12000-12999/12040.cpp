#include <iostream>
#include <random>
#include <string.h>

using namespace std;

int N;
string arr[51];

string create_random_string() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dis(0, 25);
    
    int used = 0;
    string ret = "";
    
    while (used != ((1 << 26) - 1)) {
        int rand_num = dis(gen);
        
        if ((used & (1 << rand_num)) != 0) continue;
        
        ret += (char)('A' + rand_num);
        used |= (1 << rand_num);
    }
    
    return ret;
}

bool check_contain(string s, string r) {
    for (int i=0; i<s.size(); i++) {
        bool match = true;
        
        for (int j=0; j<r.size(); j++) {
            if (s[i+j] != r[j]) {
                match = false;
                break;
            }
        }
        
        if (match) return true;
    }
    
    return false;
}

bool validate(string s) {
    for (int i=0; i<N; i++) {
        if (check_contain(s, arr[i])) return false;   
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> N;
        
        for (int i=0; i<N; i++) cin >> arr[i];
        
        string result = "IMPOSSIBLE";
        
        for (int i=0; i<10000; i++) {
            string rand_string = create_random_string();
            
            if (validate(rand_string)) {
                result = rand_string;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << result << "\n";
    }

    return 0;
}
