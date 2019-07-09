#include <iostream>
using namespace std;

enum BoardFigure
    {
        Empty = 0,
        Pawn = 1,
        Rook = 2,
        Horse = 3,
        Elephant = 4,
        Queen = 5,
        King = 6
    };

int main()
{
    BoardFigure Board [8][8] = {Empty};

    Board[0][0] = Rook;
    Board[0][7] = Rook;

    Board[7][0] = Rook;
    Board[7][7] = Rook;

    Board[0][1] = Horse;
    Board[0][6] = Horse;

    Board[7][1] = Horse;
    Board[7][6] = Horse;

    Board[0][2] = Elephant;
    Board[0][5] = Elephant;

    Board[7][2] = Elephant;
    Board[7][5] = Elephant;

    Board[0][3] = Queen;
    Board[7][3] = Queen;

    Board[0][4] = King;
    Board[7][4] = King;

    for(int i = 0; i < 8; i++){
        Board[1][i] = Pawn;
        Board[6][i] = Pawn;
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j< 8; j++){
            cout << Board[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
