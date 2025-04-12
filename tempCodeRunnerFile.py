import matplotlib.pyplot as plt
from math import sqrt

# Point class for handling coordinates
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"({self.x}, {self.y})"

# Calculate the Euclidean distance between two points
def distance(p1, p2):
    return sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)

# Dynamic programming solution to find minimum triangulation and diagonals
def minTriangulation(points):
    n = len(points)
    dp = [[float('inf')] * n for _ in range(n)]
    diagonal_coords = [[[] for _ in range(n)] for _ in range(n)]

    # Base case: adjacent vertices have zero cost
    for i in range(n):
        dp[i][(i + 1) % n] = 0

    # Fill DP table
    for length in range(2, n):  # Length of the sub-polygon
        for i in range(n):
            j = (i + length) % n
            for k in range(i + 1, j):
                k %= n
                cost = dp[i][k] + dp[k][j] + distance(points[i], points[j])
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    diagonal_coords[i][j] = diagonal_coords[i][k] + diagonal_coords[k][j] + [(points[i], points[j])]

    return dp[0][n - 1], diagonal_coords[0][n - 1]

# Parse a polygon from a line of input
def parsePolygon(line):
    points = []
    for pair in line.split():
        x, y = map(float, pair.split(','))
        points.append(Point(x, y))
    return points

# Plot the polygon and its diagonals
def plotPolygon(points, diagonals):
    plt.figure(figsize=(8, 8))

    # Plot the polygon edges
    x = [p.x for p in points] + [points[0].x]
    y = [p.y for p in points] + [points[0].y]
    plt.plot(x, y, 'b-', label="Polygon Edges")

    # Plot the diagonals
    for p1, p2 in diagonals:
        plt.plot([p1.x, p2.x], [p1.y, p2.y], 'r--', label="Diagonal" if 'Diagonal' not in plt.gca().get_legend_handles_labels()[1] else "")

    # Highlight vertices
    for p in points:
        plt.plot(p.x, p.y, 'ko')

    plt.xlabel("X")
    plt.ylabel("Y")
    plt.title("Polygon with Triangulation")
    plt.legend()
    plt.axis('equal')
    plt.show()

# Main function
if __name__ == "__main__":
    filename = input("Enter the filename: ")

    try:
        with open(filename, 'r') as file:
            for line_number, line in enumerate(file, 1):
                line = line.strip()
                if not line:
                    continue

                print(f"\nProcessing Polygon {line_number}:")
                # Parse the polygon
                points = parsePolygon(line)

                # Compute the triangulation
                min_cost, diagonals = minTriangulation(points)
                print(f"Minimum triangulation cost: {min_cost}")
                print("Diagonals:")
                for d in diagonals:
                    print(f"{d[0]} -> {d[1]}")

                # Plot the polygon with diagonals
                plotPolygon(points, diagonals)

    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
