import matplotlib.pyplot as plt

# Define the vertices of the polygon
points = [(-101.13, 73.47), (38.63, 118.88), (125.00, 0.00), (38.63, -118.88), (-101.13, -73.47)]

# Diagonals from the example output
diagonals = [((-101.13, 73.47), (-101.13, -73.47)),
             ((38.63, 118.88), (-101.13, -73.47)),
             ((38.63, 118.88), (38.63, -118.88))]

# Extract x and y coordinates for the polygon
polygon_x = [point[0] for point in points] + [points[0][0]]  # Close the polygon
polygon_y = [point[1] for point in points] + [points[0][1]]

# Start plotting
plt.figure(figsize=(8, 8))

# Plot the polygon
plt.plot(polygon_x, polygon_y, 'b-o', label='Polygon')

# Plot the diagonals
for diagonal in diagonals:
    x_coords = [diagonal[0][0], diagonal[1][0]]
    y_coords = [diagonal[0][1], diagonal[1][1]]
    plt.plot(x_coords, y_coords, 'r--', label='Diagonal')

# Add labels and title
plt.title("Polygon with Diagonals")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend(["Polygon", "Diagonals"], loc='upper left')
plt.grid(True)
plt.axis('equal')

# Show the plot
plt.show()
