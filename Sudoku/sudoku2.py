# Programming for Engineers - Homework 7
# Elana Lapins, due: 11/24/2021


import sudoku

filepath = input("Enter input filepath: ")

board = sudoku.read_board(filepath)

print(board)

row = int(input("Enter row: "))
col = int(input("Enter column: "))
num = int(input("Enter number: "))

S = list(map(int,board.split()))

n = []
r1 = S[:9]
r2 = S[9:18] 
r3 = S[18:27]
r4 = S[27:36]
r5 = S[36:45]
r6 = S[45:54]
r7 = S[54:63]
r8 = S[63:72]
r9 = S[72:81]

n = [r1, r2, r3, r4, r5, r6, r7, r8, r9]

n[row][col] = num

sudoku.print_it(n)










