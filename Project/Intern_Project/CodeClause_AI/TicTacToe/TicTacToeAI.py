import copy
import sys
import pygame
import random
import numpy as np

from Constant import *

#Pygame Basic Setting
pygame.init()
screen = pygame.display.set_mode( (WIDTH, HEIGHT))
pygame.display.set_caption('TIC TAC TOE AGAINST AI')
#Background Color
screen.fill(BG_COLOR)

class Board:

    #Constructor
    def __init__(self):
        #All the squares of the screen should start with zero
        self.squares = np.zeros( (ROWS, COLS) )
        self.empty_sqrs = self.squares
        #Number of squares that has been marked by player or AI
        self.sqrs_marked = 0

    def final_state(self, check=False):
        #How to win vertically and draw line for that 
        for col in range(COLS):
            if self.squares[0][col] == self.squares[1][col] == self.squares[2][col] != 0:
                if check:
                    color = CIRC_COLOR if self.squares[0][col]==2 else CROSS_COLOR
                    iniPos = [col * sqr_SIZE + sqr_SIZE // 2, 0]
                    finPos = [col * sqr_SIZE + sqr_SIZE // 2, WIDTH]
                    #Draw line if it fits the condition
                    pygame.draw.line(screen, color, iniPos, finPos, LINE_THICKNESS)

                return self.squares[0][col]

        #How to win Horizontally and draw line for that 
        for row in range(ROWS):
            if self.squares[row][0] == self.squares[row][1] == self.squares[row][2] != 0:
                if check:
                    color = CIRC_COLOR if self.squares[row][0] == 2 else CROSS_COLOR
                    iniPos = (20, row*sqr_SIZE + sqr_SIZE // 2)
                    finPos = (WIDTH - 20, row * sqr_SIZE + sqr_SIZE // 2)
                    #Draw line if it fits the condition
                    pygame.draw.line(screen, color, iniPos, finPos, LINE_THICKNESS)

                return self.squares[row][0]

        #How to win diagonally(1) and draw line for that 
        if self.squares[0][0] == self.squares[1][1] == self.squares[2][2] != 0:
            if check:
                color = CIRC_COLOR if self.squares[1][1] == 2 else CROSS_COLOR
                iniPos = (20,20)
                finPos = (WIDTH-20, HEIGHT-20)
                #Draw line if it fits the condition
                pygame.draw.line(screen, color, iniPos, finPos, CROSS_THICKNESS)
            
            return self.squares[1][1]

        #How to win diagonally(2) and draw line for that
        if self.squares[2][0] == self.squares[1][1] == self.squares[0][2] != 0:
            if check:
                color = CIRC_COLOR if self.squares[1][1] == 2 else CROSS_COLOR
                iniPos = (20, HEIGHT - 20)
                finPos = (WIDTH-20, 20)
                #Draw line if it fits the condition
                pygame.draw.line(screen, color, iniPos, finPos, CROSS_THICKNESS)

            return self.squares[1][1]

        return 0

    #If the square is marked by player or AI, use this method to mark the square on the board
    def mark_sqr(self, row, col, player):
        self.squares[row][col] = player
        # Change 0 to 1
        self.sqrs_marked += 1

    #Check if the squares[row][col] is 0, and if it is, it returns true.
    #Otherwise, it returns false
    def empty_sqr(self, row, col):
        return self.squares[row][col] == 0

    #In the board, if the squares[row][col] is empty, add it in empty_sqrs, then returns the list.
    def get_empty_sqrs(self):
        empty_sqrs = []
        for row in range(ROWS):
            for col in range(COLS):
                if self.empty_sqr(row, col):
                    empty_sqrs.append( (row, col) )
        return empty_sqrs

    # It returns true if all the board is turned from 0 to 1, then the sum is 9. If so, it's true.
    # If the sum is not 9, then return false
    def is_full(self):
        return self.sqrs_marked == 9

class AI:

    #Constructor
    def __init__(self, level=1, player=2):
        self.level = level
        self.player = player

    #AI algorithm MiniMax
    def mini_max(self, board, maximizing):
        #Terminal Case
        case = board.final_state()
        #player 1 wins
        if case == 1:
            #return eval, move
            return 1, None
        
        #player 2 wins
        if case == 2:
            #return eval, move
            return -1, None

        #draw
        elif board.is_full():
            #return eval, move
            return 0, None

        if maximizing:
            max_eval = -100
            best_move = None
            empty_sqrs = board.get_empty_sqrs()

            for (row, col) in empty_sqrs:
                board_copy = copy.deepcopy(board)
                board_copy.mark_sqr(row, col, 1)
                eval = self.mini_max(board_copy, False)[0]
                if eval>max_eval:
                    max_eval = eval
                    best_move = (row, col)

            return max_eval, best_move

        elif not maximizing:
            min_eval = 100
            best_move = None
            empty_sqrs = board.get_empty_sqrs()

            for (row, col) in empty_sqrs:
                board_copy = copy.deepcopy(board)
                board_copy.mark_sqr(row, col, self.player)
                eval = self.mini_max(board_copy, True)[0]
                if eval < min_eval:
                    min_eval = eval
                    best_move = (row, col)

            return min_eval, best_move

    def eval(self, main_board):
        eval, move = self.mini_max(main_board, False)
        print(f'AI has chosen to mark the square in pos {move} with an eval {eval}')
        #return row, col
        return move

class Game:
    #Constructor
    def __init__(self):
        self.board = Board()
        self.ai = AI()
        #1 is cross, 2 is circle
        self.player = 1 
        #Play against AI
        self.gamemode = 'ai'
        self.running = True
        self.bg_lines()

    #Draw the background to separate 3X3
    def bg_lines(self):
        #Background color
        screen.fill( BG_COLOR )

        #Vertical lines to make the board 3X3
        pygame.draw.line(screen, LINE_COLOR, (sqr_SIZE, 0), (sqr_SIZE, HEIGHT), LINE_THICKNESS)
        pygame.draw.line(screen, LINE_COLOR, (WIDTH - sqr_SIZE, 0), (WIDTH - sqr_SIZE, HEIGHT), LINE_THICKNESS)

        #Horizontal lines to make the board 3X3
        pygame.draw.line(screen, LINE_COLOR, (0,sqr_SIZE), (WIDTH, sqr_SIZE), LINE_THICKNESS)
        pygame.draw.line(screen, LINE_COLOR, (0, HEIGHT - sqr_SIZE), (WIDTH, HEIGHT - sqr_SIZE), LINE_THICKNESS)

    #Draw the symbol
    def symbol_draw(self, row, col):
        if self.player == 1:
            #Cross

            #left top 
            start_desc = (col * sqr_SIZE + CROSS_LENGTH, row * sqr_SIZE + CROSS_LENGTH)
            #to right bottom
            end_desc = (col * sqr_SIZE + sqr_SIZE - CROSS_LENGTH, row * sqr_SIZE + sqr_SIZE - CROSS_LENGTH)
            #Draw it(actually print on the screen)
            pygame.draw.line(screen, CROSS_COLOR, start_desc, end_desc, CROSS_THICKNESS)

            #right top
            start_asc = (col * sqr_SIZE + CROSS_LENGTH, row * sqr_SIZE + sqr_SIZE - CROSS_LENGTH)
            #to left bottom
            end_asc = (col * sqr_SIZE + sqr_SIZE - CROSS_LENGTH, row * sqr_SIZE + CROSS_LENGTH)
            #Draw it(actually print on the screen)
            pygame.draw.line(screen, CROSS_COLOR, start_asc, end_asc, CROSS_THICKNESS)

        elif self.player == 2:
            #Circle
            center = (col * sqr_SIZE + sqr_SIZE // 2, row * sqr_SIZE + sqr_SIZE // 2)
            pygame.draw.circle(screen, CIRC_COLOR, center, RADIUS, CIRC_THICKNESS)

    #Make move
    def make_move(self, row, col):
        self.board.mark_sqr(row, col, self.player)
        self.symbol_draw(row, col)
        self.turn_change()

    #Change turn
    def turn_change(self):
        self.player = self.player % 2 + 1

    #Check if it's over. Return True if it is, or return false
    def is_done(self):
        return self.board.final_state(check=False) in [1,2,3] or self.board.is_full()

#Main Method
def main():
    #Print on terminal as well to show user what's going on
    print('You are Cross and AI is Circle\n')
    print('If you lose, it will show how AI won\n')
    #Didnt make a function win because it's impossible to win against AI that has MiniMax Algorithm
    print('If you win, it will show how you won\n')
    print('If you draw, you can click the red button at the top left and close the game\n')
    print('Fill every squares to see the result Draw\n')

    #Objects
    game = Game()
    board = game.board
    ai = game.ai

    #Main Loop
    while True:
        #pygame event
        for event in pygame.event.get():
            #quit event
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            #click event
            if event.type == pygame.MOUSEBUTTONDOWN:
                pos = event.pos
                row = pos[1] // sqr_SIZE
                col = pos[0] // sqr_SIZE

                #player marked sqr
                if board.empty_sqr(row, col) and game.running:
                    game.make_move(row, col)
                    #Show that this movement is made by player
                    print(board.sqrs_marked, 'player')

                    #Game is over(All the boards are filled) but still there's no win, then 
                    if game.is_done():
                        if board.sqrs_marked == 9 and ai.eval != None:
                            print('Draw!')
                        game.running=False

        if game.gamemode == 'ai' and game.player == ai.player and game.running:
            #update the screen
            pygame.display.update()

            #eval
            row, col = ai.eval(board)
            game.make_move(row, col)
            #AI marked
            print(board.sqrs_marked, 'AI')

            if game.is_done():
                #AI wins
                if ai.eval(board) == None:
                    print('AI won!')
                    #It shows the which line has three same symbol and shows how AI won
                    board.final_state(check=True)
        #Update the screen every time to show the difference.
        pygame.display.update()

#Execute the main method
main()




