#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int kor, eng, math;
};

int N;
vector<Student> students;

bool cmp(const Student& lhs, const Student& rhs) {
    if (lhs.kor != rhs.kor) return lhs.kor > rhs.kor;
    if (lhs.eng != rhs.eng) return lhs.eng < rhs.eng;
    if (lhs.math != rhs.math) return lhs.math > rhs.math;
    return lhs.name < rhs.name;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        students.push_back({name, kor, eng, math});
    }
    
    sort(students.begin(), students.end(), cmp);
    
    for (auto student: students) {
        cout << student.name << "\n";
    }

    return 0;
}
