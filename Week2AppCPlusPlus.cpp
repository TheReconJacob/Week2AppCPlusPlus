// Week2AppCPlusPlus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';
char CURRENT_PLAYER = '-';
const int rowLength = 3;
const int columnLength = 3;
bool gameOver = false;

char board[rowLength][columnLength];

int winningStates[8][3][2] =
{
    {{0,0},{0,1},{0,2}},
    {{1,0},{1,1},{1,2}},
    {{2,0},{2,1},{2,2}},
    {{0,0},{1,0},{2,0}},
    {{0,1},{1,1},{2,1}},
    {{0,2},{1,2},{2,2}},
    {{0,0},{1,1},{2,2}},
    {{2,0},{1,1},{0,2}}
};

bool Match(int row, int col, char symbol)
{
    if ((symbol == board[row][0]) &&
        (symbol == board[row][1]) &&
        (symbol == board[row][2]))
    {
        return true;
    }
    if ((symbol == board[0][col]) &&
        (symbol == board[1][col]) &&
        (symbol == board[2][col]))
    {
        return true;
    }
    if ((symbol == board[0][0]) &&
        symbol == board[1][1] &&
        symbol == board[2][2])
    {
        return true;
    }
    if ((symbol == board[2][0]) &&
        symbol == board[1][1] &&
        symbol == board[0][2])
    {
        return true;
    }
    return false;
    
}

bool IsFree(int row, int col)
{
    if (board[row][col] == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Display()
{
    for (int x = 0; x < rowLength; x++)
    {
        for (int y = 0; y < columnLength; y++)
        {
            std::cout << board[x][y] << "\t";
        }
        std::cout << "\n\n\n";
    }
    if (!gameOver)
    {
        std::cout << "-----------------\n\n\n";
    }
}

void SetValue(int row, int col, char symbol)
{
    if (IsFree(row, col))
    {
        board[row][col] = symbol;
        Display();

        if (Match(row, col, symbol))
        {
            std::cout << "\n\n" << CURRENT_PLAYER << " is the winner!\n\n";
            gameOver = true;
        }

        if (CURRENT_PLAYER == PLAYER_1)
        {
            CURRENT_PLAYER = PLAYER_2;
        }
        else
        {
            CURRENT_PLAYER = PLAYER_1;
        }
    }
    else
    {
        SetValue((rand() % rowLength), (rand() % columnLength), CURRENT_PLAYER);
    }
}

void Initialise()
{
    for (int x = 0; x < rowLength; x++)
    {
        for (int y = 0; y < columnLength; y++)
        {
            board[x][y] = '-';
        }
    }
    Display();
    CURRENT_PLAYER = PLAYER_1;
}

int main()
{
    srand(time(0));

    int totalLength = rowLength * columnLength;
    int count = 1;

    Initialise();
    SetValue(0, 0, CURRENT_PLAYER);

    for (count = 2; count < totalLength; count++)
    {
        if(!gameOver)
        {
            SetValue((rand() % rowLength), (rand() % columnLength), CURRENT_PLAYER);
        }
    }
    if (count == 9 && !gameOver)
    {
        gameOver = true;
        SetValue((rand() % rowLength), (rand() % columnLength), CURRENT_PLAYER);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
