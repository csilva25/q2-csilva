#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(BOARD_ROWS);
    for (int row_it = 0; row_it < BOARD_ROWS; row_it++)
    {
        board[row_it].resize(BOARD_COLS);
        for (int col_it = 0; col_it < BOARD_COLS;col_it++)
            board[row_it][col_it] = Blank;
    }
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (int row_it = 0; row_it < BOARD_ROWS; row_it++)
        for (int col_it = 0; col_it < BOARD_COLS;col_it++)
            board[row_it][col_it] = Blank;
    
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece temp = turn;
    if (column < 0 || column > BOARD_COLS)
    {
        toggle();
        return Invalid;
    }
    else if (board[2][column] != Blank)
    {
        return Blank;
    }
    else
    {
        for (int i = 2; board[i][column] == Blank && i >= 0;i--)
            if (board[i][column] != Blank)
                board[i+1][column] = turn;
        toggle();
        return temp;
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if (column < 0 || row < 0 || column > BOARD_COLS || row > BOARD_ROWS)
        return Invalid;
    else
        return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    Piece winner = Blank;
    for (int i = 0; i < BOARD_ROWS; i++ )
    {
            if(board[i][0] == Blank || board[i][1] == Blank
               || board[i][2] == Blank)
                winner = Invalid;
           else if (board[i][0] == board[i][1] == board[i][2])
                winner = board[i][0];
            else
                winner = Blank;
        
    }
    for (int i = 0; i < BOARD_COLS; i++ )
    {
        if(board[0][i] == Blank || board[1][i] == Blank
           || board[2][i] == Blank || board[3][i] == Blank)
            winner = Invalid;
        else if (board[0][i] == board[1][i] == board[2][i])
            winner = board[0][i];
        else
            winner = Blank;
        
    }
    return winner;
}



void Piezas::toggle()
{
    if (turn == X)
        turn = O;
    else
        turn =X;
}
