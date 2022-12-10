import numpy as np
input = np.loadtxt("input_con.txt")
cnt = 0
for i in range(0,len(input),4):
    if (input[i] <= input[i+2] and input[i+1] >= input[i+3]) or (input[i] >= input[i+2] and input[i+1] <= input[i+3]):
        cnt = cnt+1;

print(cnt)

