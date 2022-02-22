#include <iostream>
#include <map>
#include <string>

using namespace std;

int S, E, Q;
map<string, bool> entry, leave;

int str_to_time(string str) {
    return stoi(str) * 60 + stoi(str.substr(3, 2));
}

int count_attendee() {
    int cnt = 0;
    
    if (entry.size() < leave.size()) {
        for(auto iter = entry.begin(); iter != entry.end(); iter++) {
            if (leave.find(iter->first) != leave.end()) cnt++;
        }
    }
    else {
        for (auto iter = leave.begin(); iter != leave.end(); iter++) {
            if (entry.find(iter->first) != entry.end()) cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    string s, e, q;
    
    cin >> s >> e >> q;
    
    S = str_to_time(s);
    E = str_to_time(e);
    Q = str_to_time(q);
    
    string time_str, name_str;
    
    while(cin >> time_str >> name_str) {
        int chat_time = str_to_time(time_str);
        
        if (chat_time <= S) entry[name_str] = true;
        else if (E <= chat_time && chat_time <= Q) leave[name_str] = true;
    }
    
    cout << count_attendee();

    return 0;
}
