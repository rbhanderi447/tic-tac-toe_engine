/*

Hello, this is my biggest project in my whole programming journey till yet !

This is a simple Tic-Tac-Toe engine without AI/ML or OOP.

The concept is iterate through each and every position in the board and if
you find the place empty calculate the points and store them in an array.
Then, choose the highest point-value position.

*/

#include <iostream>
#include <random>
#include <vector>
using namespace std;

int n = 3;


// printing the board

void printBoard(const vector<vector<char>>& board) {
  cout << '|' << board[0][0] << '|' << board[0][1] << '|' << board[0][2] << '|'
       << endl;
  cout << '|' << board[1][0] << '|' << board[1][1] << '|' << board[1][2] << '|'
       << endl;
  cout << '|' << board[2][0] << '|' << board[2][1] << '|' << board[2][2] << '|'
       << endl;
  cout << endl;
}


// getting input from user

void getBoxInput(vector<vector<char>>& board, char player) {

  int i, j;

  cout << "Which Box You Wanna Choose ? ";
  cin >> i >> j;

  board[i - 1][j - 1] = player;
}


// this func is gonna check the row and calc the points

int checkRow(const vector<vector<char>>& board, int i, int j,
             char choice_final) {

  int pt = 0;

  if (i == 0) {
    if (board[i][1] == choice_final && board[i][2] == choice_final)
      pt += 100;

    if (board[i][1] != choice_final && board[i][2] != choice_final)
      pt += 50;

    if (board[i][1] == choice_final || board[i][2] == choice_final)
      pt += 2;

    if (board[i][1] != '-' || board[i][2] != '-')
      pt += 1;
  }

  else if (i == 1) {
    if (board[i][0] == choice_final && board[i][2] == choice_final)
      pt += 100;

    if (board[i][0] != choice_final && board[i][2] != choice_final)
      pt += 50;

    if (board[i][0] == choice_final || board[i][2] == choice_final)
      pt += 2;

    if (board[i][0] != '-' || board[i][2] != '-')
      pt += 1;
  }

  else {
    if (board[i][0] == choice_final && board[i][1] == choice_final)
      pt += 100;

    if (board[i][0] != choice_final && board[i][1] != choice_final)
      pt += 50;

    if (board[i][0] == choice_final || board[i][1] == choice_final)
      pt += 2;

    if (board[i][0] != '-' || board[i][1] != '-')
      pt += 1;
  }

  return pt;
}


// this func is gonna check the column and calc the points

int checkColumn(const vector<vector<char>>& board, int i, int j,
                char choice_final) {

  int pt = 0;

  if (i == 0) {
    if (board[1][j] == choice_final && board[2][j] == choice_final)
      pt += 100;

    if (board[1][j] != choice_final && board[2][j] != choice_final)
      pt += 50;

    if (board[1][j] == choice_final || board[2][j] == choice_final)
      pt += 2;

    if (board[1][j] != '-' || board[2][j] != '-')
      pt += 1;
  }

  else if (i == 1) {
    if (board[0][j] == choice_final && board[2][j] == choice_final)
      pt += 100;

    if (board[0][j] != choice_final && board[2][j] != choice_final)
      pt += 50;

    if (board[0][j] == choice_final || board[2][j] == choice_final)
      pt += 2;

    if (board[0][j] != '-' || board[2][j] != '-')
      pt += 1;
  }

  else {
    if (board[0][j] == choice_final && board[1][j] == choice_final)
      pt += 100;

    if (board[0][j] != choice_final && board[1][j] != choice_final)
      pt += 50;

    if (board[0][j] == choice_final || board[1][j] == choice_final)
      pt += 2;

    if (board[0][j] != '-' || board[1][j] != '-')
      pt += 1;
  }

  return pt;
}


// diagonal 1
// [0][0] -> [1][1] -> [2][2]

int checkDiagonal_1(const vector<vector<char>>& board, int i, int j,
                    char choice_final) {

  int pt = 0;

  if (i == j) {

    if (i == 0) {
      if (board[1][1] == choice_final && board[2][2] == choice_final)
        pt += 100;

      if (board[1][1] != choice_final && board[2][2] != choice_final)
        pt += 50;

      if (board[1][1] == choice_final || board[2][2] == choice_final)
        pt += 2;
    }

    else if (i == 1) {
      if (board[0][0] == choice_final && board[2][2] == choice_final)
        pt += 100;

      if (board[0][0] != choice_final && board[2][2] != choice_final)
        pt += 50;

      if (board[0][0] == choice_final || board[2][2] == choice_final)
        pt += 2;
    }

    else {
      if (board[0][0] == choice_final && board[1][1] == choice_final)
        pt += 100;

      if (board[0][0] != choice_final && board[1][1] != choice_final)
        pt += 50;

      if (board[0][0] == choice_final || board[1][1] == choice_final)
        pt += 2;
    }
  }

  return pt;
}


// diagonal 2
// [0][2] -> [1][1] -> [2][0]

int checkDiagonal_2(const vector<vector<char>>& board, int i, int j,
                    char choice_final) {

  int pt = 0;

  if (i + j == 2) {

    int r1 = 1, c1 = 1;
    int r2, c2;

    if (i == 0) {
      r2 = 2;
      c2 = 0;
    }
    else if (i == 1) {
      r2 = 2;
      c2 = 0;
    }
    else {
      r2 = 0;
      c2 = 2;
    }

    if (board[r1][c1] == choice_final &&
        board[r2][c2] == choice_final)
      pt += 100;

    if (board[r1][c1] != choice_final &&
        board[r2][c2] != choice_final)
      pt += 50;

    if (board[r1][c1] == choice_final ||
        board[r2][c2] == choice_final)
      pt += 2;
  }

  return pt;
}


// check if someone won

bool checkWin(const vector<vector<char>>& board, char player) {

  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player &&
        board[i][1] == player &&
        board[i][2] == player)
      return true;
  }

  for (int j = 0; j < 3; j++) {
    if (board[0][j] == player &&
        board[1][j] == player &&
        board[2][j] == player)
      return true;
  }

  if (board[0][0] == player &&
      board[1][1] == player &&
      board[2][2] == player)
    return true;

  if (board[0][2] == player &&
      board[1][1] == player &&
      board[2][0] == player)
    return true;

  return false;
}

bool checkDraw(const vector<vector<char>>& board){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-')
                return false;
        }
    }
    return true;
}


// the main engine --- this is the bot or computer player

void engine(vector<vector<char>>& board, char choice_final) {

  int points[3][3] = {};

  int highest = -1;
  int bestI = 0;
  int bestJ = 0;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      if (board[i][j] == '-') {

        points[i][j] = 0;

        points[i][j] += checkRow(board, i, j, choice_final);
        points[i][j] += checkColumn(board, i, j, choice_final);
        points[i][j] += checkDiagonal_1(board, i, j, choice_final);
        points[i][j] += checkDiagonal_2(board, i, j, choice_final);

        if (points[i][j] > highest) {
          highest = points[i][j];
          bestI = i;
          bestJ = j;
        }
      }
    }
  }

  board[bestI][bestJ] = choice_final;
}


// main control panel

int main() {

  cout << "Welcome To Tic-Tac-Toe!" << endl;


  // random choice of computer's symbol

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distrib(0, 1);

  int choice = distrib(gen);

  char computer;
  char player;

  if (choice != 0) {
    computer = 'X';
    player = 'O';
  }
  else {
    computer = 'O';
    player = 'X';
  }


  vector<vector<char>> board(3, vector<char>(3, '-'));

  printBoard(board);


  // game loop

  while (true) {

    // player chooses box

    getBoxInput(board, player);

    printBoard(board);

    if (checkWin(board, player)) {
      cout << "You Win!" << endl;
      break;
    }

    if(checkDraw(board)){
      cout << "Draw!" << endl;
      break;
    }

    // computer chooses box

    engine(board, computer);

    printBoard(board);

    if (checkWin(board, computer)) {
      cout << "Computer Wins!" << endl;
      break;
    }

    if(checkDraw(board)){
      cout << "Draw!" << endl;
      break;
    }

  }

  return 0;
}
