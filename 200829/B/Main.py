import sys

S = input()
T = input()

##print(S)
##print(T)

flag = 0
count = 0

##print(len(T))
s_len = len(S)
t_len = len(T)

start = 0
min = t_len

for start in range(0, s_len - t_len + 1):
    diff = 0
    for i in range(0, t_len):
        if T[i] != S[start + i]:
            diff = diff + 1

    if min > diff:
        min = diff


print(min)
