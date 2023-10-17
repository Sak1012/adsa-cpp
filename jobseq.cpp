#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;

    Job(char i, int d, int p) : id(i), deadline(d), profit(p) {}

    bool operator<(const Job& other) const {
        return profit > other.profit;
    }
};

void jobSchedulingWithDeadlines(vector<Job>& jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end());

    vector<char> result(n, '0');
    vector<bool> slot(n, false);

    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                cout << "Job " << jobs[i].id << " scheduled at position " << j << endl;
                break;
            }
        }
    }

    cout << "Optimal Job Schedule: ";
    for (char jobId : result) {
        if (jobId != '0') {
            cout << jobId << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobSchedulingWithDeadlines(jobs);

    return 0;
}

