from copy import deepcopy

state = [[1,1], [1,1]]
choice = [[0, 0], [0, 1], [1, 0], [1, 1]]

def display():
    str1 = f'player 1: {state[0][0]:5d}, {state[0][1]:5d}\n'
    str2 = f'player 2: {state[1][0]:5d}, {state[1][1]:5d}\n'
    print('\n'+'_'*20)
    if player == 0:
        print(str2)
        print(str1)
    else:
        print(str1)
        print(str2)

#select player
print('choose your side')
player = int(input('first(1) or second(2) player?\n'))-1

def isWin(board = state):
    if   board[0] == [0,0]:
        return 0
    elif board[1] == [0,0]:
        return 1
    else:
        return -1

def makeMove(From, To, Player, board = state):
    if board[Player][From] == 0 or board[1-Player][To] == 0 :
        return False
    else:
        board[Player][From] += board[1-Player][To]
        board[Player][From] %= 10
        return True
    
def pruning(a, b, player, node, depth = 100):
    if isWin(node) > 0:
        return isWin(node)*2-1
    if depth == 0:
        return 0
    if player == 0:
        value = 1
        for child in choice:
            temp = deepcopy(node)
            if makeMove(child[0], child[1], 0, temp):
                value = min(value, pruning(a, b, 1-player, temp, depth-1))
                b = min(b, value)
            if b <= a:
                break
        return value
    else: #player == 1
        value = -1
        for child in choice:
            temp = deepcopy(node)
            if makeMove(child[0], child[1], 1, temp):
                value = max(value, pruning(a, b, 1-player, temp, depth-1))
                a = max(b, value)
            if a >= b:
                break
        return value
    
def computerMove():
    if player == 0:
        value = -1
        for child in choice:
            temp = deepcopy(state)
            if makeMove(child[0], child[1], 1, temp):
                cur_value = pruning(-1, 1, 1-current, temp)
                if cur_value >= value:
                    value = cur_value
                    move = child

    else:
        value = 1
        for child in choice:
            temp = deepcopy(state)
            if makeMove(child[0], child[1], 0, temp):
                cur_value = pruning(-1, 1, 1-current, temp)
                if cur_value <= value:
                    value = cur_value
                    move = child
                
    if not makeMove(move[0], move[1], 1-player):
        print('!!!')
    
#start game

current = 0
while(isWin() < 0):
    display()

    if player == current:
        print('make your move!')
        while not makeMove(int(input('from '))-1, int(input('to '))-1, player):
            print('\nthat\'s not valid! try again...\n')
        
    else:
        print('now is computer\'s turn...')
        computerMove()
        
    current = 1-current

#print result

if isWin() == player:
    print('You Win!')
else:
    print('You Lose!')
    
