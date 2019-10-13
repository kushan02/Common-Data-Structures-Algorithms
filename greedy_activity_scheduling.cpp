#include<bits/stdc++.h>

using namespace std;

struct Activity {
    int start_time;
    int finish_time;

    Activity(int s, int f) {
        start_time = s;
        finish_time = f;
    }
};

bool sort_by_finish_time(const Activity &A, const Activity &B) {
    if (A.finish_time == B.finish_time)
        return A.start_time < B.start_time;
    return A.finish_time < B.finish_time;
}


int main() {

    vector<Activity> ar = {
            Activity(5, 9),
            Activity(1, 2),
            Activity(3, 4),
            Activity(0, 6),
            Activity(5, 7),
            Activity(8, 9)
    };

    sort(ar.begin(), ar.end(), sort_by_finish_time);

    int activity_count = 1; // you select the first finishing activity by default
    cout << ar[0].start_time << ", " << ar[0].finish_time << endl;
    int last_finish_time = ar[0].finish_time;

    for (int i = 1; i < ar.size(); ++i) {
        // if the current activity has start time after the finishing of previous activity -> select it
        if (ar[i].start_time >= last_finish_time) {
            cout << ar[i].start_time << ", " << ar[i].finish_time << endl;
            last_finish_time = ar[i].finish_time;
            activity_count++;
        }
    }

    cout << activity_count;


    return 0;
}