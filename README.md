# TicTacToeTree

## Defining The Problem

According to [Wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe): 

> Tic-tac-toe (American English), noughts and crosses (Commonwealth English), or Xs and Os (Canadian or Irish English) is a paper-and-pencil game for two players who take turns marking the spaces in a three-by-three grid with *X* or *O*. 
The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner. 

Tic-tac-toe is a "solved game", meaning that the outcome is predictable from any state of play, given optimal strategy by both players.
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

## Have The Computer Play

The 362880 figure is an overestimate of the number of end states.
This computation includes many instances where the game should not have gotten to a filled board i.e., the game should have ended on an earlier turn.
Rather than attempt to include this rule mathematically, we can simply have the computer play all games of tic-tac-toe, and count how many times the game ends.
We know this is feasible because of the upper bound we established earlier; if each game takes 1 millisecond to complete, then we should only have to wait for approximately 6 minutes.

### Eliminating Impossible Games

Running the simulation yields the following results:

- Game Ends On Turn 5: 1440
- Game Ends On Turn 6: 5328
- Game Ends On Turn 7: 47952
- Game Ends On Turn 8: 72576
- Game Ends On Turn 9: 81792
- Stalemate: 46080

Because the 'X' player always goes on odd turns, and the 'O' player always goes on even turns, we can sum these values up:

- Player 'X' Wins: 131184
- Player 'O' Wins: 77904
- Stalemate: 46080

This tells us something you probably already knew: if you're going to place 'X's and 'O's randomly, it is better to go first.
We have also reduced our total number of end states from the original 362880 to 255168.

![image](/images/possible_games_bar.png)
![image](/images/possible_games_pie.png)

### Eliminating Duplicate Boards

In tic-tac-toe, there are multiple ways to reach the same board state.
Consider the following example:

(Show example of two games that take moves in different orders but end up in the same state)

Two games end up at the same game state by turn 3, and therefore have the same list of possible continuations.
In other words, there's no need to play those games more than once.
Once again, because the problem size is small, we can solve this through brute force.
We will have the computer play a game to its conclusion, and record the game state at each turn.
Then, when the computer plays another game, we can check on each turn if the game state we are on has been seen before.
If it has, then there's no need to continue.
If it hasn't, then the computer can add this new state to the list, and continue playing.
This should get us to a list of all possible board states of tic-tac-toe, for each turn of the game.

Running the simulation yields the following results:

- Turn 1 Boards: 9
- Turn 2 Boards: 72
- Turn 3 Boards: 252
- Turn 4 Boards: 756
- Turn 5 Boards: 1260 (120 Winners)
- Turn 6 Boards: 1520 (148 Winners)
- Turn 7 Boards: 1140 (444 Winners)
- Turn 8 Boards: 390 (168 Winners)
- Turn 9 Boards: 78 (62 Winners)
- Stalemate Boards: 16

It is interesting to see that there are only 16 unique stalemate boards.
These boards can be seen below:

![image](/images/possible_stalemates.png)

### Eliminating Rotations

Rotations don't do anything to change strategy... like rotating the paper... have the computer compare the current board state to all four possible rotations of all the seen states

- Turn 1 Boards: 3
- Turn 2 Boards: 18
- Turn 3 Boards: 64
- Turn 4 Boards: 192
- Turn 5 Boards: 318 (33 Winners)
- Turn 6 Boards: 380 (37 Winners)
- Turn 7 Boards: 285 (111 Winners)
- Turn 8 Boards: 100 (42 Winners)
- Turn 9 Boards: 22 (18 Winners)
- Stalemate Boards: 4

### Eliminating Mirrors

Still too many to represent graphically... One additional thing to eliminate... mirrors images, vertical or horizontal... strategy remains the same... consider rotations of the mirror states as well... same as before, check if these states exist in list of seen states



