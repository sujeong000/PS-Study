#include <string>
#include <vector>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
    
    bool operator<(const Date &d) const {
		if (year != d.year) return year < d.year;
        if (month != d.month) return month < d.month;
        return day < d.day;
	}
};

Date toDate(string date_string) {
    int year = stoi(date_string.substr(0, 4));
    int month = stoi(date_string.substr(5, 7));
    int day = stoi(date_string.substr(8, 10));
    return {year, month, day};
}

Date dateAfterMonth(Date date, int m) {
    Date new_date = date;
    
    new_date.month += m;
    while (new_date.month > 12) {
        new_date.year += 1;
        new_date.month -= 12;
    }
    
    return new_date;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 오늘
    Date today_date = toDate(today);
    
    // 약관별 유효기간 저장
    vector<int> terms_exp(26);
    for (auto term: terms) {
        int term_idx = term[0] - 'A';
        int exp = stoi(term.substr(2, 3));
        terms_exp[term_idx] = exp;
    }

    for (int i=0; i<privacies.size(); i++) {
        string privacy = privacies[i];
        
        // 해당 개인정보의 유효기간 계산
        int term = privacy[11] - 'A';
        int exp = terms_exp[term];
        
        // 유효기간 만료 여부 확인
        Date start_date = toDate(privacy.substr(0, 10));
        Date exp_date = dateAfterMonth(start_date, exp);
        if (!(today_date < exp_date)) {
            answer.push_back(i + 1);    // 파기
        }
    }
    
    return answer;
}
