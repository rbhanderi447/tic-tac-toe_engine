# Tic-Tac-Toe Engine

This is a simple Tic-Tac-Toe game made in C++.

This is one of my biggest programming projects so far.

## Features

* Player vs Computer
* Randomly chooses X or O for the computer
* Simple point-based computer engine
* Checks rows, columns, and diagonals
* Detects win and draw
* No AI/ML
* No OOP

## How the Computer Works

The computer checks every empty box on the board.

For each empty box, it calculates points by checking:

* Row
* Column
* Diagonal

Then it stores the points and chooses the box with the highest score.

So the basic idea is:

```text
Check empty box
      ↓
Calculate points
      ↓
Store points
      ↓
Find highest points
      ↓
Computer chooses that box
```

## Input

The player enters the row and column of the box.

For example:

```text
1 2
```

means row 1, column 2.

The board positions are:

```text
1 1   1 2   1 3
2 1   2 2   2 3
3 1   3 2   3 3
```

## Technologies

* C++
* `vector`
* Random number generation

## Future Improvements

I may improve the point system and make the computer player smarter in the future.

## Author

Made as a personal C++ programming project.
