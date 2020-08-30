import sys

S = input()
T = input()

##print(S)
##print(T)

flag = 0
count = 0

##print(len(T))
tmp_len = len(T)


while 1:

    ##print("")
    for i in range(0, count + 1):
        tmp_st = T[i:tmp_len-count+i]
        print(tmp_st)
        print(S[i:len(S)-count+i])
        if tmp_st in S[i:len(S)-count+i]:
            flag = 1
            break
        
        print("")
    if flag == 1:
        break
    count = count + 1

print(count)
