#include <iostream>

using namespace std;

class TicTacToe
{
public:
    // TTT board, empty by default
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // used for keeping track what's in each space, and what value each player has
    enum Entry
    {
        EMPTY = ' ',
        PLAYER_ONE = 'x',
        PLAYER_TWO = 'o'
    };

    // has the board been completely filled?
    bool isFull()
    {
        bool result = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Entry::EMPTY)
                    result = false;
            }
        }

        return result;
    }

    // has someone won?
    bool isVictory(Entry e)
    {

        // first col
        if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return true;
        }

        // second col
        else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return true;
        }

        // third col
        else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // first row
        else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        // second row
        else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return true;
        }

        // third row
        else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 1
        else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 2
        else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        return false;
    }

    // return size of the board; mostly just in case I wanted to make the board expandable
    int getSize()
    {
        return 3;
    }


    void dump()
    {
        cout << "----------------------------------------" << endl << endl;
        for (int i = 0; i < getSize(); i++)
        {
            for (int j = 0; j < getSize(); j++)
            {
                cout << " | " << board[i][j] << " | ";
            }

            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }

};

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

static bool getComputerMove(TicTacToe::Entry computer, TicTacToe& t)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;

    //Check for AI win
    // first col
    if (t.board[0][0] == ('o') && t.board[0][1] == ('o') && t.board[0][2] == t.EMPTY)
    {
        t.board[0][2] = ('o');
    }
    else if (t.board[0][0] == ('o') && t.board[0][1] == t.EMPTY && t.board[0][2] == ('o'))
    {
        t.board[0][1] = ('o');
    }
    else if (t.board[0][0] == t.EMPTY && t.board[0][1] == ('o') && t.board[0][2] == ('o'))
    {
        t.board[0][0] = ('o');
    }

    // second col
    else if (t.board[1][0] == ('o') && t.board[1][1] == ('o') && t.board[1][2] == t.EMPTY)
    {
        t.board[1][2] = ('o');
    }
    else if (t.board[1][0] == ('o') && t.board[1][1] == t.EMPTY && t.board[1][2] == ('o'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[1][0] == t.EMPTY && t.board[1][1] == ('o') && t.board[1][2] == ('o'))
    {
        t.board[1][0] = ('o');
    }

    // third col
    else if (t.board[2][0] == ('o') && t.board[2][1] == ('o') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[2][0] == ('o') && t.board[2][1] == t.EMPTY && t.board[2][2] == ('o'))
    {
        t.board[2][1] = ('o');
    }
    else if (t.board[2][0] == t.EMPTY && t.board[2][1] == ('o') && t.board[2][2] == ('o'))
    {
        t.board[2][0] = ('o');
    }

    // first row
    else if (t.board[0][0] == ('o') && t.board[1][0] == ('o') && t.board[2][0] == t.EMPTY)
    {
        t.board[2][0] = ('o');
    }
    else if (t.board[0][0] == ('o') && t.board[1][0] == t.EMPTY && t.board[2][0] == ('o'))
    {
        t.board[1][0] = ('o');
    }
    else if (t.board[0][0] == t.EMPTY && t.board[1][0] == ('o') && t.board[2][0] == ('o'))
    {
        t.board[0][0] = ('o');
    }

    // second row
    else if (t.board[0][1] == ('o') && t.board[1][1] == ('o') && t.board[2][1] == t.EMPTY)
    {
        t.board[2][1] = ('o');
    }
    else if (t.board[0][1] == ('o') && t.board[1][1] == t.EMPTY && t.board[2][1] == ('o'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][1] == t.EMPTY && t.board[1][1] == ('o') && t.board[2][1] == ('o'))
    {
        t.board[0][1] = ('o');
    }

    // third row
    else if (t.board[0][2] == ('o') && t.board[1][2] == ('o') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[0][2] == ('o') && t.board[1][2] == t.EMPTY && t.board[2][2] == ('o'))
    {
        t.board[1][2] = ('o');
    }
    else if (t.board[0][2] == t.EMPTY &&t.board[1][2] == ('o') && t.board[2][2] == ('o'))
    {
        t.board[0][2] = ('o');
    }

    // diagonal 1
    else if (t.board[0][0] == ('o') && t.board[1][1] == ('o') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[0][0] == ('o') && t.board[1][1] == t.EMPTY && t.board[2][2] == ('o'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][02] == t.EMPTY && t.board[1][1] == ('o') && t.board[2][2] == ('o'))
    {
        t.board[0][0] = ('o');
    }

    // diagonal 2
    else if (t.board[0][2] == ('o') && t.board[1][1] == ('o') && t.board[2][0] == t.EMPTY)
    {
        t.board[2][0] = ('o');
    }
    else if (t.board[0][2] == ('o') && t.board[1][1] == t.EMPTY && t.board[2][0] == ('o'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][2] == t.EMPTY && t.board[1][1] == ('o') && t.board[2][0] == ('o'))
    {
        t.board[0][2] = ('o');
    }


    //Check for Player win
    // first col
    if (t.board[0][0] == ('x') && t.board[0][1] == ('x') && t.board[0][2] == t.EMPTY)
    {
        t.board[0][2] = ('o');
    }
    else if (t.board[0][0] == ('x') && t.board[0][1] == t.EMPTY && t.board[0][2] == ('x'))
    {
        t.board[0][1] = ('o');
    }
    else if (t.board[0][0] == t.EMPTY && t.board[0][1] == ('x') && t.board[0][2] == ('x'))
    {
        t.board[0][0] = ('o');
    }

    // second col
    else if (t.board[1][0] == ('x') && t.board[1][1] == ('x') && t.board[1][2] == t.EMPTY)
    {
        t.board[1][2] = ('o');
    }
    else if (t.board[1][0] == ('x') && t.board[1][1] == t.EMPTY && t.board[1][2] == ('x'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[1][0] == t.EMPTY && t.board[1][1] == ('x') && t.board[1][2] == ('x'))
    {
        t.board[1][0] = ('o');
    }

    // third col
    else if (t.board[2][0] == ('x') && t.board[2][1] == ('x') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[2][0] == ('x') && t.board[2][1] == t.EMPTY && t.board[2][2] == ('x'))
    {
        t.board[2][1] = ('o');
    }
    else if (t.board[2][0] == t.EMPTY && t.board[2][1] == ('x') && t.board[2][2] == ('x'))
    {
        t.board[2][0] = ('o');
    }

    // first row
    else if (t.board[0][0] == ('x') && t.board[1][0] == ('x') && t.board[2][0] == t.EMPTY)
    {
        t.board[2][0] = ('o');
    }
    else if (t.board[0][0] == ('x') && t.board[1][0] == t.EMPTY && t.board[2][0] == ('x'))
    {
        t.board[1][0] = ('o');
    }
    else if (t.board[0][0] == t.EMPTY && t.board[1][0] == ('x') && t.board[2][0] == ('x'))
    {
        t.board[0][0] = ('o');
    }

    // second row
    else if (t.board[0][1] == ('x') && t.board[1][1] == ('x') && t.board[2][1] == t.EMPTY)
    {
        t.board[2][1] = ('o');
    }
    else if (t.board[0][1] == ('x') && t.board[1][1] == t.EMPTY && t.board[2][1] == ('x'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][1] == t.EMPTY && t.board[1][1] == ('x') && t.board[2][1] == ('x'))
    {
        t.board[0][1] = ('o');
    }

    // third row
    else if (t.board[0][2] == ('x') && t.board[1][2] == ('x') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[0][2] == ('x') && t.board[1][2] == t.EMPTY && t.board[2][2] == ('x'))
    {
        t.board[1][2] = ('o');
    }
    else if (t.board[0][2] == t.EMPTY && t.board[1][2] == ('x') && t.board[2][2] == ('x'))
    {
        t.board[0][2] = ('o');
    }

    // diagonal 1
    else if (t.board[0][0] == ('x') && t.board[1][1] == ('x') && t.board[2][2] == t.EMPTY)
    {
        t.board[2][2] = ('o');
    }
    else if (t.board[0][0] == ('x') && t.board[1][1] == t.EMPTY && t.board[2][2] == ('x'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][02] == t.EMPTY && t.board[1][1] == ('x') && t.board[2][2] == ('x'))
    {
        t.board[0][0] = ('o');
    }

    // diagonal 2
    else if (t.board[0][2] == ('x') && t.board[1][1] == ('x') && t.board[2][0] == t.EMPTY)
    {
        t.board[2][0] = ('o');
    }
    else if (t.board[0][2] == ('x') && t.board[1][1] == t.EMPTY && t.board[2][0] == ('x'))
    {
        t.board[1][1] = ('o');
    }
    else if (t.board[0][2] == t.EMPTY && t.board[1][1] == ('x') && t.board[2][0] == ('x'))
    {
        t.board[0][2] = ('o');
    }


    //Center open?
    else if (t.board[1][1] == t.EMPTY)
    {
        t.board[1][1] = ('o');
    }

    //Corners open?
    else if (t.board[0][0] == t.EMPTY || t.board[2][0] == t.EMPTY || t.board[0][2] == t.EMPTY || t.board[2][2] == t.EMPTY)
    {
        int RandResult;
        bool foundAndFilled;
        foundAndFilled = false;
        do {
            RandResult = rand() % 4 + 1;
            cout << RandResult << endl;
            if (RandResult == 1)
            {
                if (t.board[0][0] == t.EMPTY)
                {
                    t.board[0][0] = ('o');
                    foundAndFilled = true;
                }
            }
            else if (RandResult == 2)
            {
                if (t.board[2][0] == t.EMPTY)
                {
                    t.board[2][0] = ('o');
                    foundAndFilled = true;
                }
            }
            else if (RandResult == 3)
            {
                if (t.board[0][2] == t.EMPTY)
                {
                    t.board[0][2] = ('o');
                    foundAndFilled = true;
                }
            }
            else if (RandResult == 4)
            {
                if (t.board[2][2] == t.EMPTY)
                {
                    t.board[2][2] = ('o');
                    foundAndFilled = true;
                }
            }
        } while (!foundAndFilled);
    }

    //sides open?
    else if (t.board[0][1] == t.EMPTY || t.board[1][0] == t.EMPTY || t.board[1][2] == t.EMPTY || t.board[2][1] == t.EMPTY)
    {
    int RandResult;
    bool foundAndFilled;
    foundAndFilled = false;
    do {
        RandResult = rand() % 4 + 1;
        if (RandResult == 1)
        {
            if (t.board[0][1] == t.EMPTY)
            {
                t.board[0][1] = ('o');
                foundAndFilled = true;
            }
        }
        else if (RandResult == 2)
        {
            if (t.board[2][1] == t.EMPTY)
            {
                t.board[2][1] = ('o');
                foundAndFilled = true;
            }
        }
        else if (RandResult == 3)
        {
            if (t.board[1][2] == t.EMPTY)
            {
                t.board[1][2] = ('o');
                foundAndFilled = true;
            }
        }
        else if (RandResult == 4)
        {
            if (t.board[2][1] == t.EMPTY)
            {
                t.board[2][1] = ('o');
                foundAndFilled = true;
            }
        }
    } while (!foundAndFilled);
    }

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, t));


    t.dump();

    cout << endl;

    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}