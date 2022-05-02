import copy
def read_board(filepath):
    with open(filepath,"r") as f:
        sudoku = []
        sudoku = f.read()
        return sudoku

def print_it(board):
    for s in board:
        print(*s)

def is_this_valid(board, row, column, candidate):
    #check if in row twice
    for i in range(9):
        if board[row][i] == candidate:
            return 1
    #check if in column twice
    for i in range(9):
        if board[i][column] == candidate:
            return 2

    #check subgrid
    R = row - row % 3
    C = column - column % 3
    for i in range(3):
        for j in range(3):
            if board[i+R][j+C] == candidate:
                return 3

    return 0   
