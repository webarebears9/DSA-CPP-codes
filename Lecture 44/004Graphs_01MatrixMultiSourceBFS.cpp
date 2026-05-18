class Solution {
public:

    // time : O(mn)
    // space: O(mn)

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    // i,jth cell corr. to a src (hospital)
                    q.push({i, j});
                    distMat[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            int nx = i;
            int ny = j + 1;

            if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                distMat[nx][ny] = 1 + distMat[i][j];
            }

            nx = i;
            ny = j - 1;

            if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                distMat[nx][ny] = 1 + distMat[i][j];
            }

            nx = i - 1;
            ny = j;

            if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                distMat[nx][ny] = 1 + distMat[i][j];
            }

            nx = i + 1;
            ny = j;

            if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                distMat[nx][ny] = 1 + distMat[i][j];
            }

        }

        return distMat;
    }
};