
import math
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Parameters
t_min = 0
t_max = 30
step = 0.01

circle_speed = 50
r = 4
speed = 10
h = 100
a = 10
distance_between_balls = 100

positions = []
balls_positions = []

prev_ball_position = (0, 0, 0)
distance_from_last_ball = 0

for i in range(int(t_min / step), int(t_max / step)):
    t = i * step

    x = -t * math.cos(2 * t) * r + a * math.cos(circle_speed * t)
    y = -t * math.sin(2 * t) * r + a * math.cos(circle_speed * t)
    z = h - a * math.sin(circle_speed * t) - speed * t

    positions.append((x, y, z))
    if len(positions) > 1:
        prev_x, prev_y, prev_z = positions[-2]
        distance_from_last_ball += math.sqrt((x - prev_x)**2 + (y - prev_y)**2 + (z - prev_z)**2)
        if distance_from_last_ball >= distance_between_balls:
            balls_positions.append((x, y, z))
            distance_from_last_ball = 0

balls_positions.insert(0, positions[0])

x_values, y_values, z_values = zip(*positions)
ball_x_values, ball_y_values, ball_z_values = zip(*balls_positions)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(x_values, y_values, z_values, label='Spiral', lw=2, color='green')
ax.scatter(ball_x_values, ball_y_values, ball_z_values, color='red', s = 70, label='Balls')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Spiral with Balls')
ax.set_xlim([-100, 100])
ax.set_ylim([-100, 100])
ax.set_zlim([-100, 100])

plt.legend()
plt.show()
