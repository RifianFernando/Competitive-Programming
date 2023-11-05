#include<bits/stdc++.h>

using namespace std;

struct Team {
    string name;
    string institution;
    int rank;
};

pair<int, vector<string>> find_champion(const vector<Team>& teams, int M, int K) {
    int n = teams.size();
    int countTeamWinner = 0;
    vector<string> teamWinner;

    return {countTeamWinner, teamWinner};
}

int main () {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Team> teams(N);
    for (int i = 0; i < N; i++) {
        cin >> teams[i].name >> teams[i].institution;
        teams[i].rank = i + 1;
    }

    auto result = find_champion(teams, M, K);
    cout << result.first << endl;

    for (const auto& s : result.second) {
        cout << s << endl;
    }


    return 0;
}; 