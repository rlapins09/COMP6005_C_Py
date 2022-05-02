# Programming for Engineers - Homework 7
# Elana Lapins, due: 11/24/2021


import sudoku


#filepath = C:\Users\elana\Desktop\Coursework\Comp.For Engineers\Homework7\sudoku1\input.txt
filepath = input("Enter input filepath: ")

board = sudoku.read_board(filepath)

print(board)
