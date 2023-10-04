import math
def calculate_cylinder_volume(radius, height):
    """
    This function calculates the volume of a cylinder given its radius and height.
    :param radius: float, the radius of the cylinder
    :param height: float, the height of the cylinder
    :return: float, the volume of the cylinder
    """
    return math.pi * radius * radius * height

# Test the function
radius = 5
height = 10
volume = calculate_cylinder_volume(radius, height)
print(f"The volume of the cylinder with radius {radius} and height {height} is {volume}")
