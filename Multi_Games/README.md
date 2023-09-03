# 🐍 Snake and Ladder Game & Tic-Tac-Toe 🎲

Welcome to the Snake and Ladder Game and Tic-Tac-Toe combined program in C. You can choose to play either Snake and Ladder or Tic-Tac-Toe.

## Snake and Ladder Game 🐍🎲

### Rules:
- The game begins with any dice value.
- If a 6 is rolled, you earn an extra chance to play.
- Snakes: 99 to 1, 65 to 40, 25 to 9.
- Ladders: 70 to 93, 60 to 83, 13 to 42.

To play Snake and Ladder, choose 's' or 'S' when prompted.

## Tic-Tac-Toe Game ⭕❌

### Rules:
- Two players take turns marking spaces on a 3x3 board.
- The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins.
- If all spaces are filled, the game ends in a draw.

To play Tic-Tac-Toe, choose 't' or 'T' when prompted.

## Usage Instructions 🚀

1. Compile the code using a C compiler.
2. Run the program.
3. Choose either Snake and Ladder ('s' or 'S') or Tic-Tac-Toe ('t' or 'T').
4. Follow the on-screen instructions to play the selected game.

## Sample Output 📝

- Snake and Ladder Game board will be displayed.
- Tic-Tac-Toe Game board will be displayed.

### Test Case 1: Snake and Ladder Game 🐍🎲

1.  Start the game by choosing 's' or 'S'.
2.  Roll the dice 🎲 and verify that the player's position is updated correctly on the game board.
3.  Check if the game recognizes when a 6 is rolled and awards an extra turn.
4.  Test that the game correctly moves the player when landing on snakes 🐍 (e.g., 99 to 1) and ladders 🪜 (e.g., 13 to 42).
5.  Ensure the game ends and declares a winner 🏆 when a player reaches position 100.
6.  Verify that the game handles invalid input gracefully (e.g., entering 'r' for a roll) and prompts the player for a valid action.

### Test Case 2: Tic-Tac-Toe Game 🎯🧡

1.  Start the game by choosing 't' or 'T'.
2.  Verify that the Tic-Tac-Toe board is displayed correctly at the beginning.
3.  Test player 1's move by entering a valid cell number (e.g., 1, 5, 9) and check if their mark ('X') is correctly placed.
4.  Ensure player 2's move is working by entering a valid cell number (different from player 1's choice) and check if their mark ('O') is correctly placed.
5.  Test that the game detects a win when a player forms a winning combination of marks.
6.  Check if the game recognizes a draw when all cells are filled.
7.  Verify that the game handles invalid input gracefully (e.g., entering a cell number that is already occupied or outside the valid range) and prompts the player for a valid move.
8.  Test restarting the game (choosing 't' or 'T' again) and confirm that the board is reset.

## Important Notes 📌

- Enjoy playing both games!
- The code includes options to clear the screen for better visibility.

Thank you for using our Snake and Ladder Game and Tic-Tac-Toe program! 🎮
