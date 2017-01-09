# a degenerate linear program
# last modified: January 4, 2017

from scipy.optimize import linprog

c = [-1,2]
A = [[1,-1],[-1,1]]
b = [0,0]
x0_bounds = (0, None)
x1_bounds = (0, None)

res = linprog(c, A_ub=A, b_ub=b, bounds=(x0_bounds, x1_bounds),
              options={'disp':True})

print res
