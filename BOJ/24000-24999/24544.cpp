#include <iostream>

using namespace std;

int arr[1001];

int main()
{
    int N;
    
    cin >> N;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    long long total_sum = 0;
    long long my_view_sum = 0;
    
    int is_my_view;
    
    for(int i=0; i<N; i++) {
        cin >> is_my_view;
        
        total_sum += arr[i];
        if (is_my_view) my_view_sum += arr[i];
    }
    
    cout << total_sum << "\n";
    cout << total_sum - my_view_sum << "\n";

    return 0;
}
