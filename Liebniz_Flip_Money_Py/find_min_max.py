
# homework 6 : Programming for Engineers
# Elana Lapins, 11/3/2021

cases = int(input())

for i in range(cases):
    print("Case: ", i, "\n")
    list = input()
    split = list.split(" ")
    for i in range(0,len(split)):
        split[i] = int(split[i]) #convert to int list

    min, max = split[0], split[0]

    for j in range(len(split)):
        if(split[j]< min):
            min = split[j]
        elif(split[j]>max):
            max = split[j]
        else:
            continue
    print("Min = {}, Max = {}".format(min, max));