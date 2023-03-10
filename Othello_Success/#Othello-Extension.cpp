#include <iostream>
#include<vector>
using namespace std;

int board_number[8][8];

enum Piece { Empty, Black, White };

class Board {
public:
    // Initialize the board with all pieces set to Empty
    Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = Empty;
            }
        }
        board[3][3] = White;
        board[4][4] = White;
        board[3][4] = Black;
        board[4][3] = Black;
        
    }

    // Print the board to the console
    void Print() {
        cout << "  ";
        for(int k = 0; k < 8; k++) {
            //Columns are represented by English letters 
            cout << (char)( k + 65 ) <<" ";
        }
        cout<<endl;
        for (int i = 0; i < 8; i++) {
            //Rows are represented by numbers
            cout << ( i + 1 ) << " ";
            for (int j = 0; j < 8; j++) {
                cout << GetPieceChar(board[i][j]) << " ";
            }
            cout << endl;
        }
    }

    // Place a piece of the given color on the board
    void PlacePiece(int x, int y, Piece color) {
        board[x][y] = color;
    }

private:
    Piece board[8][8];

    // Get the character representation of a piece
    char GetPieceChar(Piece piece) {
        switch (piece) {
        case Empty:
            return '.';
        case Black:
            return 'B';
        case White:
            return 'W';
        }
    }
};

Board board;
//Initializing the Othello board
void init_board_number() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board_number[i][j] = 2;
        }
    }

    board_number[3][3] = 1;
    board_number[4][4] = 1;
    board_number[3][4] = 0;
    board_number[4][3] = 0;

}

// Functions that performs changes to the board when a white stone is placed
void board_change_function_North_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Row_number - 1; i >= 0; i--) {
                if(board_number[i][start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][start_Column_number] == 1) {
                    Goal_Position = i;
                    break;
                }
                if(i == 0 && board_number[i][start_Column_number] == 0) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1) {
                for(int i = Start_Row_number; i >= Goal_Position; i--) {
                    board_number[i][start_Column_number] = 1;
                    board.PlacePiece(i,start_Column_number,White);
                }
            }

}

void board_change_function_East_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Column_number + 1; i < 8; i++) {
                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1) {
                    Goal_Position = i;
                    break;
                }

                if(i == 7 && board_number[Start_Row_number][i] == 0) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1) {

                for(int i = Start_Column_number + 1; i <= Goal_Position; i++) {
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                }
            }
}

void board_change_function_South_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Row_number + 1; i < 8; i++) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1) {
                    Goal_Position = i;
                    break;
                }

                if(i == 7 && board_number[i][Start_Column_number] == 0) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1) {
                for(int i = Start_Row_number + 1; i <= Goal_Position; i++) {
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                }
            }
}

void board_change_function_West_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Column_number - 1; i >= 0; i--) {
                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1) {
                    Goal_Position = i;
                    break;
                }
                if(i == 0 && board_number[Start_Row_number][i] == 0) {
                    Goal_Position = -1;
                    break;
                }
                
            }

            if(Goal_Position != -1){
                for(int i = Start_Column_number; i >= Goal_Position; i--) {
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                }
            }
}

void board_change_function_Northeast_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            Start_Row_number = Row_number - 1;

            for(int i = Start_Column_number + 1; i < 8; i++) {
                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1) {
                    Goal_Position = i;
                    break;
                }

                if((Start_Row_number == 0 || i == 7) && board_number[Start_Row_number][i] == 0) {
                    Goal_Position = -1;
                    break;
                }
                Start_Row_number--;
            }

            Start_Row_number = Row_number - 1;

            if(Goal_Position != -1) {
                for(int i = Start_Column_number + 1; i <= Goal_Position; i++) {
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                    Start_Row_number--;
                }
            }
}

void board_change_function_Northwest_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            Start_Column_number = Column_number - 1;

            for(int i = Start_Row_number - 1; i >= 0; i--) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1) {
                    Goal_Position = i;
                    break;
                }
                if((Start_Column_number == 0 || i == 0) && board_number[i][Start_Column_number] == 0) {
                    Goal_Position = -1;
                    break;
                }
                Start_Column_number--;
            }

            Start_Column_number = Column_number - 1;

            if(Goal_Position != -1) {
                for(int i = Start_Row_number - 1; i >= Goal_Position; i--) {
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                    Start_Column_number--;
                }
            }

}

void board_change_function_Southeast_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            Start_Column_number = Column_number + 1;

            for(int i = Start_Row_number + 1; i < 8; i++) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1) {
                    Goal_Position = i;
                    break;
                }

                if((Start_Column_number == 7 || i == 7) && board_number[i][Start_Column_number] == 0) {
                    Goal_Position = -1; 
                    break;
                }
                Start_Column_number++;
            }

            Start_Column_number = Column_number + 1;

            if(Goal_Position != -1) {

                for(int i = Start_Row_number + 1; i <= Goal_Position; i++) {
  
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                    Start_Column_number++;
                }
            }
}

void board_change_function_Southwest_direction_White(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;
            Start_Row_number = Row_number + 1;

            for(int i = Start_Column_number - 1; i >= 0; i--) {

                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1) {
                    Goal_Position = i;
                    break;
                }
                if((Start_Row_number == 7 || i == 0) && board_number[Start_Row_number][i] == 0) {
                    Goal_Position = -1;
                    break;
                }
                Start_Row_number++;

            }

            Start_Row_number = Row_number + 1;

            if(Goal_Position != -1) {
                for(int i = Start_Column_number - 1; i >= Goal_Position; i--) {
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                    Start_Row_number++;
                }
            }
}


////////////////////////////////////////////////////////////////////////////////////

// Functions that performs changes to the board when a bLack stone is placed

void board_change_function_East_direction_Black(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;


            for(int i = Start_Column_number + 1; i < 8; i++) {
                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 0) {
                    Goal_Position = i;
                    break;
                }
                if(i == 7 && board_number[Start_Row_number][i] == 1) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1){
                for(int i = Start_Column_number + 1; i <= Goal_Position; i++) {
                    board_number[Start_Row_number][i] = 0;
                    board.PlacePiece(Start_Row_number,i,Black);
                }
            }
}

void board_change_function_South_direction_Black(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Row_number + 1; i < 8; i++) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0) {
                    Goal_Position = i;
                    break;
                }
                if(i == 7 && board_number[i][Start_Column_number] == 1) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1){
                for(int i = Start_Row_number + 1; i <= Goal_Position; i++) {
                    board_number[i][Start_Column_number ] = 0;
                    board.PlacePiece(i,Start_Column_number ,Black);
                }
            }
}

void board_change_function_West_direction_Black(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;

            for(int i = Start_Column_number - 1; i >= 0; i--) {
                if(board_number[Start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 0) {
                    Goal_Position = i;
                    break;
                }

                if(i == 0 && board_number[Start_Row_number][i] == 1) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1) {
                for(int i = Start_Column_number; i >= Goal_Position; i--) {
                    board_number[Start_Row_number][i] = 0;
                    board.PlacePiece(Start_Row_number,i,Black);
                }
            }
}

void board_change_function_North_direction_Black(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;


            for(int i = Start_Row_number - 1; i >= 0; i--) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0) {
                    Goal_Position = i;
                    break;
                }

                if(i == 0 && board_number[i][Start_Column_number] == 1) {
                    Goal_Position = -1;
                    break;
                }
            }

            if(Goal_Position != -1){
                for(int i = Start_Row_number; i >= Goal_Position; i--) {
                    board_number[i][Start_Column_number] = 0;
                    board.PlacePiece(i,Start_Column_number,Black);
                }
            }
}

void board_change_function_Southeast_direction_Black(int Row_number,int Column_number) {

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int Goal_Position = -2;
            Start_Column_number = Column_number + 1;

            for(int i = Start_Row_number + 1; i < 8; i++) {
                if(board_number[i][Start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0) {
                    Goal_Position = i;
                    break;
                }
                if((Start_Column_number == 7 || i == 7) && board_number[i][Start_Column_number] == 1) {
                    Goal_Position = -1;
                    break;
                }
                Start_Column_number++;
            }

            Start_Column_number = Column_number + 1;

            if(Goal_Position != -1){
                for(int i = Start_Row_number + 1; i <= Goal_Position; i++) {
                    board_number[i][Start_Column_number] = 0;
                    board.PlacePiece(i,Start_Column_number,Black);
                    Start_Column_number++;
                }
            }
}

void board_change_function_Southwest_direction_Black(int Row_number,int Column_number) {

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int Goal_Position = -2;

            start_Row_number = Row_number + 1;

            for(int i = start_Column_number - 1; i >= 0; i--) {
                if(board_number[start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[start_Row_number][i] == 0) {
                    Goal_Position = i;
                    break;
                }
                if((start_Row_number == 7 || i == 0) && board_number[start_Row_number][i] == 1) {
                    Goal_Position = -1;
                    break;
                }
                start_Row_number++;
            }

            start_Row_number = Row_number + 1;

            if(Goal_Position != -1) {
                for(int i = start_Column_number - 1; i >= Goal_Position; i--) {

                    board_number[start_Row_number][i] = 0;
                    board.PlacePiece(start_Row_number,i,Black);
                    start_Row_number++;
                }
            }
}


void board_change_function_Northeast_direction_Black(int Row_number,int Column_number) {

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int Goal_Position = -2;
            start_Row_number = Row_number - 1;

            for(int i = start_Column_number + 1; i < 8; i++) {
                if(board_number[start_Row_number][i] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[start_Row_number][i] == 0) {
                    Goal_Position= i;
                    break;
                }

                if((start_Row_number == 0 || i == 7) && board_number[start_Row_number][i] == 1) {
                    Goal_Position = -1;
                    break;
                }
                start_Row_number--;
            }

            start_Row_number = Row_number - 1;

            if(Goal_Position != -1) {
                for(int i = start_Column_number + 1; i <= Goal_Position; i++) {
                    board_number[start_Row_number][i] = 0;
                    board.PlacePiece(start_Row_number,i,Black);
                    start_Row_number--;
                }
            }
}

void board_change_function_Northwest_direction_Black(int Row_number,int Column_number) {

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int Goal_Position = -2;
            start_Column_number = Column_number - 1;

            for(int i = start_Row_number - 1; i >= 0; i--) {
                if(board_number[i][start_Column_number] == 2) {
                    Goal_Position = -1;
                    break;
                }
                if(board_number[i][start_Column_number] == 0) {
                    Goal_Position = i;
                    break;
                }
                if((start_Column_number == 0 || i == 0) && board_number[i][start_Column_number] == 1) {
                    Goal_Position = -1;
                    break;
                }
                start_Column_number--;
            }

            start_Column_number = Column_number - 1;

            if(Goal_Position != -1) {
                for(int i = start_Row_number - 1; i >= Goal_Position; i--) {
                    board_number[i][start_Column_number] = 0;
                    board.PlacePiece(i,start_Column_number,Black);
                    start_Column_number--;
                }
            }
}

bool TryBoardChanging(int BoardRowNumber,int BoardColumnNumber) {

//???????????????,?????????????????????void?????????????????????????????????bool??????????????????.??????????????????????????????,bool simulation = false;????????????,
//TryBoardChanging?????????????????????,?????????????????????void??????????????????????????????,bool simulation = true;???????????????.
//bool simulation = true;??????????????????

/*/
if(Goal_Position != -1 && simulation == false) {
    for(int i = start_Row_number - 1; i >= Goal_Position; i--) {
        board_number[i][start_Column_number] = 0;
        board.PlacePiece(i,start_Column_number,Black);
        start_Column_number--;
    }
}

else if(Goal_Position != -1 && simulation == true) {
    return true;(ChangeStone???true???????????????)

} 
/*/

}


bool Others_StonePlace_Search() {
    bool ChangeStone = false;
        
        for(int i = 0; i < 8; i++ ) {
            for(int j = 0; j < 8; j++ ) {
                if(board_number[i][j] == 2) {
                    ChangeStone = TryBoardChanging(i,j);
                }
            }
       }

    if(ChangeStone) return true;   
    else if(!ChangeStone) return false;

}


int main(){

    init_board_number();

    bool battle_pre = true;
    char Column;
    int Board_Row_Number;
    int Board_Column_Number;

    int PreBlackStoneMemory = 2;
    int PreWhiteStoneMemory = 2;
    int WhiteStoneMemory = 0;
    int BlackStoneMemory = 0;
    bool NotCorrectStonePlace;

    while(battle_pre) {

    board.Print();

    NotCorrectStonePlace = true;
    while(NotCorrectStonePlace){
        cout<<"???????????????"<<endl;
        cout<<"????????????????????????? ???????????????????????????";
        cin>>Board_Row_Number;
        cout<<"????????????????????????? ??????????????????????????????";
        cin>>Column;
        
        Board_Row_Number = Board_Row_Number - 1;
        Board_Column_Number = (Column - 'A');

        board.PlacePiece(Board_Row_Number,Board_Column_Number,White);
        board_number[Board_Row_Number][Board_Column_Number] = 1;

        //????????????3,5??????????????????????????????,???????????????????????????.
        int case_count = 0;

        bool upper_left_edge_White = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 0 && case_count == 0) {
            upper_left_edge_White = true;
            case_count++;

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool upper_right_edge_White = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 7 && case_count == 0) {
            upper_right_edge_White = true;
            case_count++;

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool lower_left_edge_White = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 0 && case_count == 0) {
            upper_left_edge_White = true;
            case_count++;

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool lower_right_edge_White = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 7 && case_count == 0) {
            lower_right_edge_White = true;
            case_count++;

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool left_side_White = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 0 && case_count == 0) {
            left_side_White = true;
            case_count++;

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_White(Board_Row_Number,Board_Column_Number);

        }


        bool upper_side_White = false;

        if(Board_Row_Number == 0 && Board_Column_Number != 0 && Board_Column_Number != 7 && case_count == 0) {
            upper_side_White = true;
            case_count++;

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool right_side_White = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 7 && case_count == 0) {
            right_side_White = true;
            case_count++;

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_White(Board_Row_Number,Board_Column_Number);

        }

        bool lower_side_White = false;

        if(Board_Row_Number == 7 && Board_Column_Number != 0 && Board_Column_Number != 7 && case_count == 0) {
            lower_side_White = true;
            case_count++;

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_White(Board_Row_Number,Board_Column_Number);

        }

        //???????????????????????????????????????????????????????????????,????????????????????????9????????????.
        if(case_count == 0) {
            case_count++;

            board_change_function_North_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_White(Board_Row_Number,Board_Column_Number);
            
            board_change_function_South_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_White(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_White(Board_Row_Number,Board_Column_Number);

        }

    

    WhiteStoneMemory = 0;
    BlackStoneMemory = 0;

        for(int i = 0; i < 8; i++ ) {
            for(int j = 0; j < 8; j++ ) {
                if(board_number[i][j] == 1) WhiteStoneMemory++;
                else if(board_number[i][j] == 0) BlackStoneMemory++;
            }
        }

    PreBlackStoneMemory = BlackStoneMemory;
    PreWhiteStoneMemory = WhiteStoneMemory;

        //??????????????????????????????,????????????????????????????????????????????????
        if(PreWhiteStoneMemory == WhiteStoneMemory - 1){
            //?????????????????????????????????,?????????????????????????????????????????????????????????
            
            cout<<"????????????????????????????????????????????????????????????."<<endl;

            bool OtherStoneSearch = Others_StonePlace_Search();
            if(OtherStoneSearch){
                NotCorrectStonePlace = true;
                board_number[Board_Row_Number][Board_Column_Number] = 0;
                board.PlacePiece(Board_Row_Number,Board_Column_Number,Empty);
                cout<<"???????????????????????????"<<endl;
            }
            else NotCorrectStonePlace = false;
        }
        else{
            NotCorrectStonePlace = false;
        }
    
    
    }

    int empty_count = 0;
    for(int i = 0; i < 8; i++ ) {
        for(int j = 0; j < 8; j++) {
            if(board_number[i][j] == 2) empty_count++;
        }
    }

    if(empty_count == 0) break;
    else empty_count = 0;
            

    board.Print();

    /////////////////////////////////////////////////////////////////////////////
    NotCorrectStonePlace = true;
    while(NotCorrectStonePlace){

        cout<<"???????????????"<<endl;
        cout<<"????????????????????????? ???????????????????????????";
        cin>>Board_Row_Number;
        cout<<"????????????????????????? ??????????????????????????????";
        cin>>Column;

        Board_Row_Number = Board_Row_Number - 1;
        Board_Column_Number = (Column - 'A');

        board.PlacePiece(Board_Row_Number,Board_Column_Number,Black);
        board_number[Board_Row_Number][Board_Column_Number] = 0;

        //????????????3,5??????????????????????????????,???????????????????????????.
        int WhiteCaseCount = 0;

        bool upper_left_edge_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 0 && WhiteCaseCount == 0) {
            upper_left_edge_Black = true;
            WhiteCaseCount++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool upper_right_edge_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 7 && WhiteCaseCount == 0) {
            upper_right_edge_Black = true;
            WhiteCaseCount++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_left_edge_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 0 && WhiteCaseCount == 0) {
            upper_left_edge_Black = true;
            WhiteCaseCount++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_right_edge_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 7 && WhiteCaseCount == 0) {
            lower_right_edge_Black = true;
            WhiteCaseCount++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool left_side_Black = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 0 && WhiteCaseCount == 0) {
            left_side_Black = true;
            WhiteCaseCount++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }


        bool upper_side_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number != 0 && Board_Column_Number != 7 && WhiteCaseCount == 0) {
            upper_side_Black = true;
            WhiteCaseCount++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool right_side_Black = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 7 && WhiteCaseCount == 0) {
            right_side_Black = true;
            WhiteCaseCount++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_side_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number != 0 && Board_Column_Number != 7 && WhiteCaseCount == 0) {
            lower_side_Black = true;
            WhiteCaseCount++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        //???????????????????????????????????????????????????????????????,????????????????????????9????????????.
        if(WhiteCaseCount == 0) {
            WhiteCaseCount++;
            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);
            
            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        PreBlackStoneMemory;
        PreWhiteStoneMemory;
        WhiteStoneMemory = 0;
        BlackStoneMemory = 0;

        for(int i = 0; i < 8; i++ ) {
            for(int j = 0; j < 8; j++ ) {
                if(board_number[i][j] == 1) WhiteStoneMemory++;
                else if(board_number[i][j] == 0) BlackStoneMemory++;
            }
        }

        //??????????????????????????????,????????????????????????????????????????????????
        if(PreBlackStoneMemory == BlackStoneMemory - 1){
            //?????????????????????????????????,?????????????????????????????????????????????????????????
            
            cout<<"????????????????????????????????????????????????????????????."<<endl;

            bool OtherStoneSearch = Others_StonePlace_Search();
            if(OtherStoneSearch){
                NotCorrectStonePlace = true;
                board_number[Board_Row_Number][Board_Column_Number] = 0;
                board.PlacePiece(Board_Row_Number,Board_Column_Number,Empty);

                cout<<"???????????????????????????"<<endl;
            
            }
            else NotCorrectStonePlace = false;
        }
        else{
            NotCorrectStonePlace = false;
        }

    }

    PreBlackStoneMemory = BlackStoneMemory;
    PreWhiteStoneMemory = WhiteStoneMemory;
    WhiteStoneMemory = 0;
    BlackStoneMemory = 0;

    //??????????????????????????????????????????.
    for(int i = 0; i < 8; i++ ) {
        for(int j = 0; j < 8; j++ ) {
                if(board_number[i][j] == 2) empty_count++;
        }
    }

    if(empty_count == 0) break;
    else empty_count = 0;

    }

    int White_count = 0;
    int Black_count = 0;

    for(int i = 0; i < 8; i++ ) {
        for(int j = 0; j < 8; j++ ) {
            if(board_number[i][j] == 1) White_count++;
            else if(board_number[i][j] == 0) Black_count++;
        }
    }

    board.Print();

    cout<<"???????????????????????????"<<White_count<<"??????"<<endl;
    cout<<"???????????????????????????"<<Black_count<<"??????"<<endl;

    if(White_count > Black_count) cout<<"??????????????????!"<<endl;
    else if(White_count < Black_count) cout<<"??????????????????!"<<endl;
    else cout<<"??????????????????!"<<endl;

    return 0;
 
}
