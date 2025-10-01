#include <iostream>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    long long sum_a = 0, sum_b = 0;
    long long max_a = LLONG_MIN, min_a = LLONG_MAX;
    long long max_b = LLONG_MIN, min_b = LLONG_MAX;
    long long second_max_a = LLONG_MIN, second_min_a = LLONG_MAX;
    long long second_max_b = LLONG_MIN, second_min_b = LLONG_MAX;
    int max_count_a = 0, min_count_a = 0;
    int max_count_b = 0, min_count_b = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum_a += a[i];
        sum_b += b[i];

        // Update max and min for a
        if (a[i] > max_a) {
            second_max_a = max_a;
            max_a = a[i];
            max_count_a = 1;
        } else if (a[i] == max_a) {
            max_count_a++;
        } else if (a[i] > second_max_a) {
            second_max_a = a[i];
        }

        if (a[i] < min_a) {
            second_min_a = min_a;
            min_a = a[i];
            min_count_a = 1;
        } else if (a[i] == min_a) {
            min_count_a++;
        } else if (a[i] < second_min_a) {
            second_min_a = a[i];
        }

        // Update max and min for b
        if (b[i] > max_b) {
            second_max_b = max_b;
            max_b = b[i];
            max_count_b = 1;
        } else if (b[i] == max_b) {
            max_count_b++;
        } else if (b[i] > second_max_b) {
            second_max_b = b[i];
        }

        if (b[i] < min_b) {
            second_min_b = min_b;
            min_b = b[i];
            min_count_b = 1;
        } else if (b[i] == min_b) {
            min_count_b++;
        } else if (b[i] < second_min_b) {
            second_min_b = b[i];
        }
    }

    for (int i = 0; i < n; i++) {
        // Calculate for a
        long long new_sum_a = sum_a - a[i];
        long long new_max_a, new_min_a;
        if (a[i] == max_a) {
            if (max_count_a > 1) {
                new_max_a = max_a;
                new_min_a = min_a;
            } else {
                new_max_a = second_max_a;
                new_min_a = min_a;
            }
        } else if (a[i] == min_a) {
            if (min_count_a > 1) {
                new_max_a = max_a;
                new_min_a = min_a;
            } else {
                new_max_a = max_a;
                new_min_a = second_min_a;
            }
        } else {
            new_max_a = max_a;
            new_min_a = min_a;
        }
        long long remaining_sum_a = new_sum_a - new_max_a - new_min_a;
        double avg_a = (double)remaining_sum_a / (n - 3);

        // Calculate for b
        long long new_sum_b = sum_b - b[i];
        long long new_max_b, new_min_b;
        if (b[i] == max_b) {
            if (max_count_b > 1) {
                new_max_b = max_b;
                new_min_b = min_b;
            } else {
                new_max_b = second_max_b;
                new_min_b = min_b;
            }
        } else if (b[i] == min_b) {
            if (min_count_b > 1) {
                new_max_b = max_b;
                new_min_b = min_b;
            } else {
                new_max_b = max_b;
                new_min_b = second_min_b;
            }
        } else {
            new_max_b = max_b;
            new_min_b = min_b;
        }
        long long remaining_sum_b = new_sum_b - new_max_b - new_min_b;
        double avg_b = (double)remaining_sum_b / (n - 3);

        double final_score = (avg_a + avg_b) / 2.0;
        cout << fixed << setprecision(10) << final_score << endl;
    }

    return 0;
}