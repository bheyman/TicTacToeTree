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

Because the 'X' player always goes on odd turns, and the 'Y' player always goes on even turns, we can sum these values up:

- Player 'X' Wins: 131184
- Player 'Y' Wins: 77904
- Stalemate: 46080

This tells us something you probably already knew: if you're going to place 'X's and 'O's randomly, it is better to go first.


2. Eliminating duplicate states i.e., two boards that are the same, reached thru different order
3. Eliminating rotation/mirror states i.e., one board is a rotation/mirror of another (behavior is same)
