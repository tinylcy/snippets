import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.path as path
import pylab

import numpy as np

x = np.linspace(6, 30, 25)

y1 = [258, 299, 173, 321, 402, 342, 354, 299, 359, 252, 300, 297, 301, 253, 305, 311, 260, 364, 250, 254, 349, 302,
	  298, 252, 302]

y2 = [1, 2, 2, 1, 2, 1, 3, 3, 3, 3, 4, 4, 3, 4, 5, 6, 4, 4, 6, 4, 5, 5, 4, 6, 6]

# Set tick direction.
matplotlib.rcParams['xtick.direction'] = 'in'
matplotlib.rcParams['ytick.direction'] = 'in'

plt.plot(x, y2, '.-')
plt.xlabel('Number of nodes (.)')
plt.ylabel('Time used (ms)')

plt.show()
