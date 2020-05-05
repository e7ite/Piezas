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
    this->board.resize(4);
    this->turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (auto& i : this->board)
        for (auto& j : i)
            j = Blank;
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
    auto ChangeTurn = [this]()
    {
        Piece oldPiece = this->turn;
        if (this->turn == X)
            this->turn = O;
        else if (this->turn == O)
            this->turn = X;
        return oldPiece;
    };

    if (column > 4 || column < 0)
    {
        ChangeTurn();
        return Invalid;
    }
    else if (this->board[column].size() == 3)
    {
        ChangeTurn();
        return Blank;
    }

    this->board[column].push_back(this->turn);
    return ChangeTurn();
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if (row > 2 || row < 0 || column > 3 || column < 0)
        return Invalid;
    try
    {
        return this->board.at(column).at(row);
    }
    catch (const std::exception& ex)
    {
        return Blank;
    }
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
    int xRow = 0, xCol = 0, oRow = 0, oCol = 0;
    int curXCol = 0, curOCol = 0;
    int curXRow[3] = { 0 }, curORow[3] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (this->pieceAt(j, i))
            {
                case X:
                    curXRow[j]++;
                    curXCol++;
                    break;
                case O:
                    curORow[j]++;
                    curOCol++;
                    break;
                default:
                    return Invalid;
            }
        }

        xCol = std::max(xCol, curXCol);
        oCol = std::max(oCol, curOCol);
    }

    for (int i = 0; i < 3; i++)
    {
        oRow = std::max(oRow, curORow[i]);
        xRow = std::max(xRow, curXRow[i]);
    }
    xRow = std::max(xRow, xCol);
    oRow = std::max(oRow, oCol);

    if (xRow > oRow)
        return X;
    if (xRow < oRow)
        return O;
    return Blank;
}