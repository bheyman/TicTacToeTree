# TicTacToeTree
According to [Wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe): 

> Tic-tac-toe (American English), noughts and crosses (Commonwealth English), or Xs and Os (Canadian or Irish English) is a paper-and-pencil game for two players who take turns marking the spaces in a three-by-three grid with *X* or *O*. 
The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner. 

Tic-tac-toe is a "solved game", meaning that the outcome is prediable from any state of play, given optimal strategy by both players.
In tic-tac-toe's case, optimal play by both players leads to a draw in every case.
As the WOPR computer says in the film "WarGames":

> A STRANGE GAME. THE ONLY WINNING MOVE IS NOT TO PLAY.

I thought it might be fun to try to represent this visually; to create some kind of art piece that shows every possible game that could be played.
The goal of this project is the following: 
1. Find every possible valid configuration of a tic-tac-toe board. 
2. Determine which boards follow from previous boards. 
3. Use this information to make some kind of pretty graphic.

## Is This Feasible?

The first thing we can do is try to establish bounds; this will help us determine if computation is feasible, and whether or not we need to be clever.
If the problem is small enough, it may be possible to brute force the solution by simple iteration.

Consider, as an upper bound, how many different ways two players can take turns marking squares on a three-by-three grid.
The first player initially has to select one square out of nine.
The second player then selects one square out of eight.
Next, the first player selects one square out of seven.
This will continue until, at most, every square has been selected.
Accordingly, we can get a first pass at an upper limit by calculating:

$9! = 362880$

To a modern computer, this number is not very large.
For instance, the storage requirements of representing all of these possibilities.
If we had to represent each square as a four-byte integer:

$4 \text{ }\frac{\text{bytes}}{\text{square}} \times 9 \text{ }\frac{\text{squares}}{\text{board}} \times 362880 \text{ boards} \approx 13 \text{ MB}$

This is miniscule compared to the memory of a modern computer.
It appears like we should not have an issue brute forcing the answer to this problem.

## Invalid End States

Consider the following three examples:





1. Eliminating impossible states i.e., ones where the game should have ended
2. Eliminating duplicate states i.e., two boards that are the same, reached thru different order
3. Eliminating rotation/mirror states i.e., one board is a rotation/mirror of another (behavior is same)
