import sys
# Grid : 3 x 3
Grid = [['E','E','E'],['E','E','E'],['E','E','E']]

# Player class: 'X' or 'O'
class Player:
    def __init__(self, type):
        self.type = type

 # make_move()
    def make_move(self):
        if(is_empty()):
            global Grid
            print(f"Player{self.type} turn: ")
            choice = tuple(map(int,input("Enter the cell: ").split())) # i j
            while not Grid[choice[0]][choice[1]] == 'E':
                print("Invalid move, try again!")
                choice = tuple(map(int,input("Enter the cell: ").split())) # i j
                
            Grid[choice[0]][choice[1]] = self.type
        else:
            print("The game is over!")

def print_grid():
    for i in range(3):
        for j in range(3):
            print(Grid[i][j], end=" ")
        print("")

def is_empty():
    for i in range(3):
        for j in range(3):
            if Grid[i][j] == 'E':
                return True
    return False

def is_winner(p_type):  
    # Horizontal
    for row in Grid:
        if row[0] == p_type and row[1] == p_type and row[2] == p_type:
            return True
    # Vertical
    for i in range(3):
        if Grid[0][i] == p_type and Grid[1][i] == p_type and Grid[2][i] == p_type:
            return True
    # Diagonal
    if Grid[0][0] == p_type and Grid[1][1] == p_type and Grid[2][2] == p_type:
        return True
    if Grid[0][2] == p_type and Grid[1][1] == p_type and Grid[2][0] == p_type:
        return True
    return False

def main():
    p1 = Player('X')
    p2 = Player('O')
    turn = input("Who plays first: ")
    while is_empty():
        print_grid()
        if(turn == "p1"):
            p1.make_move()
            if is_winner('X'):
                print('X is winner!')
                sys.exit(0)
            turn = "p2"
        else:
            p2.make_move()
            if is_winner('O'):
                print('O is winner!')
                sys.exit(0)
            turn = "p1"

if __name__ == "__main__":
    main()