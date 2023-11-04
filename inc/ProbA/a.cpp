#include<bits/stdc++.h>

using namespace std;

pair<int, int> find_balance(const vector<int>& student, int rating) {
    int n = student.size();
    int count = 0;
    int max_team_rating = -1;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                vector<int> teamRatings = {student[i], student[j], student[k]};
                int teamRating = accumulate(teamRatings.begin(), teamRatings.end(), 0);
                int ratingDifference = *max_element(teamRatings.begin(), teamRatings.end()) - *min_element(teamRatings.begin(), teamRatings.end());

                if (ratingDifference <= rating) {
                    count++;
                    max_team_rating = max(max_team_rating, teamRating);
                }
            }
        }
    }

    return {count, max_team_rating};
}

int main () {
    int diff, rating;
    cin >> diff; cin >> rating;

    vector<int> arr;
    for (int i = 0; i < diff; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    pair<int, int> result = find_balance(arr, rating);
    if (result.first > 0) {
        cout << result.first << " " << result.second << endl;
    } else {
        cout << result.second << endl;
    }


    return 0;
}; 