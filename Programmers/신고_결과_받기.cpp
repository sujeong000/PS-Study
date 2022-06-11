#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

pair<string, string> split(string s) {
    string a = "", b = "";
    int idx = 0;
    
    while (s[idx] != ' ') {
        a += s[idx++];
    }
    idx++;
    while (idx < s.size()) {
        b += s[idx++];
    }
    
    return {a, b};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, set<string>> reporters;
    map<string, int> mailCnt;
    
    for (auto reportString: report) {
        pair<string, string> x = split(reportString);
        string reporter = x.first;
        string reported = x.second;
        reporters[reported].insert(reporter);
    }
    
    for (auto x: reporters) {
        set<string> st = x.second;
        if (st.size() >= k) {
            for (auto reporter: st) {
                mailCnt[reporter]++;
            }
        }
    }
    
    for (auto user: id_list) {
        answer.push_back(mailCnt[user]);
    }
    
    return answer;
}
