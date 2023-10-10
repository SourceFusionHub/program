# Sample list of colors
colors = ["red", "blue", "green", "yellow", "orange"]

# Color to remove
color_to_remove = "green"

# Check if the color is in the list before removing
if color_to_remove in colors:
    colors.remove(color_to_remove)  # Remove the color
    print("Updated list of colors:", colors)
else:
    print("Color not found in the list.")
