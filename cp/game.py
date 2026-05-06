import tkinter as tk
from tkinter import messagebox

class TicTacToeGUI:
    def __init__(self, master):
        self.master = master
        self.master.title("Tic-Tac-Toe")
        self.board = [' ' for _ in range(9)]  # Initialize the board with empty spaces
        self.current_player = 'X'  # Player X starts the game

        self.buttons = []
        for i in range(3):
            for j in range(3):
                button = tk.Button(master, text='', font=('Arial', 20), width=5, height=2,
                                   command=lambda row=i, col=j: self.make_move(row, col))
                button.grid(row=i, column=j)
                self.buttons.append(button)

    def make_move(self, row, col):
        index = row * 3 + col
        if self.board[index] == ' ':
            self.board[index] = self.current_player
            self.buttons[index].config(text=self.current_player)
            self.current_player = 'O' if self.current_player == 'X' else 'X'
            winner = self.check_winner()
            if winner:
                self.show_winner(winner)
        else:
            messagebox.showwarning("Invalid Move", "Position already occupied.")

    def check_winner(self):
        # Check rows
        for i in range(0, 9, 3):
            if self.board[i] == self.board[i + 1] == self.board[i + 2] != ' ':
                return self.board[i]

        # Check columns
        for i in range(3):
            if self.board[i] == self.board[i + 3] == self.board[i + 6] != ' ':
                return self.board[i]

        # Check diagonals
        if self.board[0] == self.board[4] == self.board[8] != ' ':
            return self.board[0]
        if self.board[2] == self.board[4] == self.board[6] != ' ':
            return self.board[2]

        # Check for a tie
        if ' ' not in self.board:
            return 'Tie'

        # Game is still ongoing
        return None

    def show_winner(self, winner):
        if winner == 'Tie':
            messagebox.showinfo("Game Over", "It's a tie!")
        else:
            messagebox.showinfo("Game Over", f"Player {winner} wins!")
        self.reset_board()

    def reset_board(self):
        for i in range(9):
            self.board[i] = ' '
            self.buttons[i].config(text='')
        self.current_player = 'X'

def main():
    root = tk.Tk()
    app = TicTacToeGUI(root)
    root.mainloop()

if __name__ == "__main__":
    main()
