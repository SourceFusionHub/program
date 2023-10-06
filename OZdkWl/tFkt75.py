import math

def find_volumeOf_cone(radius, height):
    # we know that the volume of cone is 1/3 of volume of cylinder
    # volume of cone = (π*r^2*h)/3

    volume = (math.pi * (radius**2) * height)/3
    return volume


radius = float(input("Enter the radius of the cone (in meters): "))
height = float(input("Enter the height of the cone (in meters): "))

volume = find_volumeOf_cone(radius, height)
print(f"The volume of the cone is {volume:.3f} cubic meters.")
