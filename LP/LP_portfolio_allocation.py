# solving the linear programming example Operations Research Problems: Statements and Solu# tions. Springer, 2014.

from scipy.optimize import linprog

# quantities ordered A_1 B_1 C_1 D_1, A_2 B_2 C_2 D_2, etc.
c = [1,1,1,1,0,0,0,0,0,0,0,0,0,0]
A_eq = [[1.05, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0], 
        [0, 1.13, 0, 0, 1.05, 0, 0, 0, -1, -1, -1, 0, 0, 0], 
        [0, 0, 1.28, 0, 0, 1.13, 0, 0, 1.05, 0, 0, -1, -1, 0], 
        [0, 0, 0, 1.4, 0, 0, 1.28, 0, 0, 1.13, 0, 1.05, 0, -1], 
        [0, 0, 0, 0, 0, 0, 0, 1.4, 0, 0, 1.28, 0, 1.13, 1.05]]
b_eq = [0, 20000, 22000, 24000, 26000]

A_ub = [[-0.2, -0.2, 0.8, 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
        [0, -0.2, 0.8, 0.8, -0.2, -0.2, 0.8, 0.8, 0, 0, 0, 0, 0, 0],
        [0, 0, 0.8, 0.8, 0, -0.2, 0.8, 0.8, -0.2, -0.2, 0.8, 0, 0, 0],
        [0, 0, 0, 0.8, 0, 0, 0.8, 0.8, 0, -0.2, 0.8, 0, -0.2, -0.2],
        [0, 0, 0, 0, 0, 0, 0, 0.8, 0, 0, 0.8, 0, -0.2, 0.8]]
b_ub = [0,0,0,0,0]

A1_bounds = (0,None)
A2_bounds = (0,None)
A3_bounds = (0,None)
A4_bounds = (0,None)
A5_bounds = (0,None)
B1_bounds = (0,None)
B2_bounds = (0,None)
B3_bounds = (0,None)
B4_bounds = (0,None)
C1_bounds = (0,None)
C2_bounds = (0,None)
C3_bounds = (0,None)
D1_bounds = (0,None)
D2_bounds = (0,None)

res = linprog(c, A_eq=A_eq, b_eq=b_eq, A_ub=A_ub, b_ub=b_ub,
              bounds=(A1_bounds,A2_bounds,A3_bounds,A4_bounds,A5_bounds,
                      B1_bounds,B2_bounds,B3_bounds,B4_bounds,
                      C1_bounds,C2_bounds,C3_bounds,
                      D1_bounds,D2_bounds),
              options = {'disp':True})

# why does this fail?  Search for typos
print res



