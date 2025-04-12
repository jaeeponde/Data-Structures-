#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Function to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

// Function to compute the minimum cost triangulation of a polygon
double minCostTriangulation(const vector<pair<int, int>>& points, vector<vector<int>>& diagonals) {
    int n = points.size();
    
    // Initialize cost and diagonal matrices
    vector<vector<double>> cost(n, vector<double>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, -1));  // dp[i][j] stores the optimal vertex for the diagonal between i and j

    // Fill the cost matrix for the diagonals between 3 consecutive points
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 2; j < n; ++j) {
            cost[i][j] = dist(points[i], points[j]);
        }
    }

    // DP to calculate the minimum cost for triangulating the polygon
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            cost[i][j] = INT_MAX;

            // Try all possible vertices for the diagonal between i and j
            for (int k = i + 1; k < j; ++k) {
                double q = cost[i][k] + cost[k][j] + dist(points[i], points[j]);
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                    dp[i][j] = k;
                }
            }
        }
    }

    // Reconstruct the diagonals and calculate the sum of their lengths
    double totalCost = cost[0][n - 1];
    int i = 0, j = n - 1;
    while (dp[i][j] != -1) {
        int k = dp[i][j];
        diagonals.push_back({i, k, j});
        totalCost += dist(points[j], points[k]);
        i = k;
    }

    return totalCost;
}

// Function to print the diagonals
void printDiagonals(const vector<pair<int, int>>& points, const vector<vector<int>>& diagonals) {
    for (const auto& diag : diagonals) {
        cout << "Diagonal: (" << points[diag[0]].first << ", " << points[diag[0]].second
             << ") -> (" << points[diag[2]].first << ", " << points[diag[2]].second << ")\n";
    }
}

int main() {
    // Input: Vertices of the polygon
    vector<pair<double, double>> points = {{-101.13,73.47}, {38.63,118.88}, {125.00,0.00}, {38.63,-118.88}, {-101.13,-73.47}}; // Example: Square with 4 vertices

    vector<vector<double>> diagonals;
    double totalCost = minCostTriangulation(points, diagonals);

    cout << "Total cost of triangulation: " << totalCost << endl;
    printDiagonals(points, diagonals);

    return 0;
}

