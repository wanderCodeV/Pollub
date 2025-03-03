import math
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

# Parameters 
circle_speed = 20
r = 4
speed = 5
h = 100
distance_between_balls = 100

animation_step = 10
ball_step_factor = animation_step 
ball_points = 100
t_min = 0
t_max = 30
step = 0.01

positions = []
balls_positions = []

prev_ball_position = (0, 0, 0)
distance_from_last_ball = 0

for i in range(int(t_min / step), int(t_max / step)):
    t = i * step

    x = -t * math.cos(t) * (r + math.sin(circle_speed * t))
    y = -t * math.sin(t) * (r + math.sin(circle_speed * t))
    z = h - math.cos(circle_speed * t) - speed * t

    positions.append((x, y, z))
    if len(positions) > 1:
        prev_x, prev_y, prev_z = positions[-2]
        distance_from_last_ball += math.sqrt((x - prev_x)**2 + (y - prev_y)**2 + (z - prev_z)**2)
        if distance_from_last_ball >= distance_between_balls:
            balls_positions.append((x, y, z))
            distance_from_last_ball = 0

balls_positions.insert(0, positions[0])

x_values, y_values, z_values = zip(*positions)

def generate_partial_spiral_ball(center_x, center_y, center_z, radius=6, turns=3, points=100, frame=100):
    t = np.linspace(0, np.pi, points)
    partial_t = t[:frame]
    spiral_x = center_x + radius * np.cos(turns * 2 * partial_t) * np.sin(partial_t)
    spiral_y = center_y + radius * np.sin(turns * 2 * partial_t) * np.sin(partial_t)
    spiral_z = center_z + radius * np.cos(partial_t)
    return spiral_x, spiral_y, spiral_z

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

def update(frame):
    ax.cla()

    max_frame = len(x_values) // animation_step

    ax.plot(x_values[:frame * animation_step], y_values[:frame * animation_step], z_values[:frame * animation_step], lw=2, color='green')

    if frame == max_frame:
        for ball_center in balls_positions:
            ball_x, ball_y, ball_z = generate_partial_spiral_ball(*ball_center, frame=ball_points)
            ax.plot(ball_x, ball_y, ball_z, color='red', lw=1.5)
        ani.event_source.stop()
        

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Christmas Tree with Spiral Balls')
    ax.set_xlim([-100, 100])
    ax.set_ylim([-100, 100])
    ax.set_zlim([-100, 100])

max_frame = len(x_values) // animation_step
ani = FuncAnimation(fig, update, frames=max_frame+1, interval=10)

plt.show()
