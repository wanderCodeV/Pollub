import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

t_min = 0
t_max = np.pi
step = 0.01
turns = 5

positions = []

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

line = None

for i in range(int(t_min / step), int(t_max / step)):
    t = i * step
    x = np.cos(turns * 2 * t) * np.sin(t)
    y = np.sin(turns * 2 * t) * np.sin(t)
    z = np.cos(t)
    positions.append((x, y, z))
    
    x_values, y_values, z_values = zip(*positions)
    
    if line:
        line.remove()

    line, = ax.plot(x_values, y_values, z_values, label='Spiral', lw=2, color='blue')

    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title('Spiral')

    ax.set_xlim([-1, 1])
    ax.set_ylim([-1, 1])
    ax.set_zlim([-1, 1])

    plt.pause(0.1)
    

plt.legend()
plt.show()
