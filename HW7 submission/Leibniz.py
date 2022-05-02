
# Programming for Engineers - Homework 7
# Elana Lapins, due: 11/24/2021

import math

cases = int(input())

for i in range(cases):
    print("Case: ", i, "\n")

    n = int(input())
    pifour =0

    for i in range(0,n):
        pifour += ( (-1)**i)/( (2*i)+1)

    Pi = pifour*4;

    print("Pi is estimated as: {:.4f}".format(Pi))

    