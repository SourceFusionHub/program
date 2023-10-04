import math

class Circle:
    def __init__(self, x, y, radius, mass, vx=0, vy=0):
        self.x = x
        self.y = y
        self.radius = radius
        self.mass = mass
        self.vx = vx  # Velocity in x direction
        self.vy = vy  # Velocity in y direction

def are_circles_colliding(circle1, circle2):
    distance = ((circle1.x - circle2.x) ** 2 + (circle1.y - circle2.y) ** 2) ** 0.5
    return distance <= (circle1.radius + circle2.radius)

def resolve_collision(circle1, circle2):
    # Calculate displacement and distance
    dx = circle1.x - circle2.x
    dy = circle1.y - circle2.y
    distance = (dx**2 + dy**2)**0.5

    # Calculate the collision angle
    collision_angle = math.atan2(dy, dx)

    # Calculate velocities in the collision direction for both circles
    v1 = circle1.vx * math.cos(collision_angle) + circle1.vy * math.sin(collision_angle)
    v2 = circle2.vx * math.cos(collision_angle) + circle2.vy * math.sin(collision_angle)

    # Conservation of momentum to find the new velocities after collision
    v1_final = ((circle1.mass - circle2.mass) * v1 + 2 * circle2.mass * v2) / (circle1.mass + circle2.mass)
    v2_final = ((circle2.mass - circle1.mass) * v2 + 2 * circle1.mass * v1) / (circle1.mass + circle2.mass)

    # Adjust the velocities
    circle1.vx = v1_final * math.cos(collision_angle) - circle1.vy * math.sin(collision_angle)
    circle1.vy = v1_final * math.sin(collision_angle) + circle1.vx * math.cos(collision_angle)
    circle2.vx = v2_final * math.cos(collision_angle) - circle2.vy * math.sin(collision_angle)
    circle2.vy = v2_final * math.sin(collision_angle) + circle2.vx * math.cos(collision_angle)

def simulate(circles, time_step):
    for circle in circles:
        circle.x += circle.vx * time_step
        circle.y += circle.vy * time_step
        
        # Collision detection with other circles
        for other_circle in circles:
            if other_circle != circle and are_circles_colliding(circle, other_circle):
                resolve_collision(circle, other_circle)

# Example Usage:
circle1 = Circle(0, 0, 10, 5, 1, 0)
circle2 = Circle(25, 0, 10, 5, -1, 0)

circles = [circle1, circle2]

for _ in range(10):  # simulate 10 steps
    simulate(circles, 1)
    print(f"Circle1 Pos: ({circle1.x}, {circle1.y}), Velocity: ({circle1.vx}, {circle1.vy})")
    print(f"Circle2 Pos: ({circle2.x}, {circle2.y}), Velocity: ({circle2.vx}, {circle2.vy})")
