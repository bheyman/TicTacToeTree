# TicTacToeTree
Program to enumerate all possible game states of Tic-Tac-Toe

## Establishing Bounds

The first thing we can do is try to establish bounds: removing all rules for a moment, what is the upper bound on the number of games that can be played?
The first player initially has to select one square out of nine.
The second player then selects one square out of eight.
Next, the first player selects one square out of seven.
This will continue until, at most, every square has been selected (it is possible for the game to end before this occurs).
Accordingly, we can get a first pass at an upper limit by calculating:

$9! = 362880$
