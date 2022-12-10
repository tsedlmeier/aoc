#!/usr/bin/python
# inp = open('test', 'r')
inp = open('input_con', 'r')
con = inp.read().replace('\n',' ').split(' ')

# stacks = ["NZ","DCM","P"];
stacks = ["CSGB","GVNJHWMT","SQM","MNWTLSB","PWGVTFZJ","SHQGBTC","WBPJT","MQTFZCDG","FPBHSN"]

for i in range(3,len(con),3):
    n = int(con[i-3])
    src = int(con[i-2])-1
    dst = int(con[i-1])-1

    tmp = dst
    print(con[i-3],con[i-2],con[i-1])
    stacks[dst] = str(stacks[src][0:n])[::-1] + stacks[dst]
    stacks[src] = stacks[src][n:]
    print(stacks)

for i in stacks:
    print(i[0])

