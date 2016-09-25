import numpy as np
import matplotlib.pyplot as plt

dimx, dimy = 100, 100
a = np.loadtxt('linac.h2d.asc')
b = a.reshape([dimx, dimy])
CF = plt.contourf(b, 100)
plt.colorbar(CF)
plt.title(b.sum())
plt.show()
