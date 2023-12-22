class Solution {
    string arrayToString(vector<int> arr) {
        string str = "";
        for(auto& val : arr) {
            str += to_string(val);
        }
        return str;
    }

    vector<int> getAdjacentCells(int index) {
        vector<int> adj;
        if(index % 3 != 0) adj.push_back(index - 1);
        if(index % 3 != 2) adj.push_back(index + 1);
        if(index / 3 != 0) adj.push_back(index - 3);
        if(index / 3 != 2) adj.push_back(index + 3);
        return adj;
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> start(9);
        int moves = 0;
        vector<int> target = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                start[i * 3 + j] = grid[i][j];
            }
        }

        queue<vector<int>> Q;
        unordered_set<string> visited;
        Q.push(start);
        visited.insert(arrayToString(start));
        while(!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; i++) {
                vector<int> cur = Q.front();
                Q.pop();
                if(cur == target) return moves;
                for(int j = 0; j < 9; j++) {
                    if(cur[j] > 1) {
                        for(auto& adj : getAdjacentCells(j)) {
                            vector<int> newState = cur;
                            newState[j]--;
                            newState[adj]++;
                            string state = arrayToString(newState);
                            if(visited.find(state) == visited.end()) {
                                visited.insert(state);
                                Q.push(newState);
                            }
                        }
                    }
                }
            }
            moves++;
        }
        return moves;
    }
};