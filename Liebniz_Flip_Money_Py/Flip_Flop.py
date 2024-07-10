# homework 6: programming for Engineers
# Elana Lapins, 11/3/2021

#inputs: start second, number of seconds to simulate, a, b

#FLIP: on seconds divisible by a
#FLOP: on seconds divisible by b
#FLIPFLOP: on seconds divisible by both a and b
#print number: if not divisible by either

cases = int(input())

for i in range(cases):
    print("Case: ", i, "\n")

    list = input()
    split = list.split(" ")
    for i in range(0,len(split)):
        split[i] = int(split[i]) #convert to int list

    list = split;
    start = list[0]
    duration = list[1]
    a = list[2]
    b = list[3]

    for j in range(start,start+duration):
        if int(j)%a ==0:
            if int(j)%b==0:
                print("flipflop\n")
            else:
                print("flip\n")
        elif int(j)%b ==0:
            print("flop\n")
        else:
            print(j,"\n")
    

