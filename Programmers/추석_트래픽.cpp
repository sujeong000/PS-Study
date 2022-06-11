#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll toNum(char c) {
    return c - '0';
}

pair<ll, ll> parse(string t) {
    ll end = 0, duration = 0;
    
    end += toNum(t[11])*10 + toNum(t[12]);
    end *= 60;
    end += toNum(t[14])*10 + toNum(t[15]);
    end *= 60;
    end += toNum(t[17])*10 + toNum(t[18]);
    end *= 1000;
    end += toNum(t[20])*100 + toNum(t[21])*10 + toNum(t[22]);
    
    duration += toNum(t[24])*1000;
    if(t.size() > 27) duration += toNum(t[26])*100;
    if (t.size() > 28) duration += toNum(t[27])*10;
    if (t.size() > 29) duration += toNum(t[28]);
    
    ll start = end - (duration-1);
    
    return {start, end};
}

bool overlap(ll interval, pair<ll, ll> work) {
    if (work.first <= interval && interval <= work.second) return true;
    if (work.first <= interval+999 && interval+999 <= work.second) return true;
    if (interval <= work.first && work.first <= interval+999) return true;
    if (interval <= work.second && work.second <= interval+999) return true;
    return false;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<ll, ll>> works;
    
    for (auto line: lines) {
        pair<ll, ll> work = parse(line);
        works.push_back(work);
    }
    
    for (auto x: works) {
        ll start = x.first;
        ll end = x.second;
        
        int sCnt = 0, eCnt = 0;
        for (auto work: works) {
            if (overlap(start, work)) sCnt++;
            if (overlap(end, work)) eCnt++;
        }
        answer = max(answer, max(sCnt, eCnt));
    }
    
    return answer;
}
