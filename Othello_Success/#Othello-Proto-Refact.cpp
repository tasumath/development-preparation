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


int main(){

    init_board_number();

    bool battle_pre = true;
    char Column;
    int Board_Row_Number;
    int Board_Column_Number;

    while(battle_pre) {

        board.Print();
        cout<<"白の番です"<<endl;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>Board_Row_Number;
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>Column;
        
        Board_Row_Number = Board_Row_Number - 1;
        Board_Column_Number = (Column - 'A');

        board.PlacePiece(Board_Row_Number,Board_Column_Number,White);
        board_number[Board_Row_Number][Board_Column_Number] = 1;

        //最近接が3,5マスのいずれかの場合,それをカウントする.
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

        //これまでのケースに該当しない石の置き方には,最近接のマス目が9マスある.
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

        cout<<"黒の番です"<<endl;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>Board_Row_Number;
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>Column;

        Board_Row_Number = Board_Row_Number - 1;
        Board_Column_Number = (Column - 'A');

        board.PlacePiece(Board_Row_Number,Board_Column_Number,Black);
        board_number[Board_Row_Number][Board_Column_Number] = 0;

        //最近接が3,5マスのいずれかの場合,それをカウントする.
        case_count = 0;

        bool upper_left_edge_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 0 && case_count == 0) {
            upper_left_edge_Black = true;
            case_count++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool upper_right_edge_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number == 7 && case_count == 0) {
            upper_right_edge_Black = true;
            case_count++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_left_edge_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 0 && case_count == 0) {
            upper_left_edge_Black = true;
            case_count++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_right_edge_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number == 7 && case_count == 0) {
            lower_right_edge_Black = true;
            case_count++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool left_side_Black = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 0 && case_count == 0) {
            left_side_Black = true;
            case_count++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }


        bool upper_side_Black = false;

        if(Board_Row_Number == 0 && Board_Column_Number != 0 && Board_Column_Number != 7 && case_count == 0) {
            upper_side_Black = true;
            case_count++;

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool right_side_Black = false;

        if(Board_Row_Number != 0 && Board_Row_Number != 7 && Board_Column_Number == 7 && case_count == 0) {
            right_side_Black = true;
            case_count++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        bool lower_side_Black = false;

        if(Board_Row_Number == 7 && Board_Column_Number != 0 && Board_Column_Number != 7 && case_count == 0) {
            lower_side_Black = true;
            case_count++;

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

        }

        //これまでのケースに該当しない石の置き方には,最近接のマス目が9マスある.
        if(case_count == 0) {
            case_count++;
            board_change_function_North_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_East_direction_Black(Board_Row_Number,Board_Column_Number);
            
            board_change_function_South_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_West_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southeast_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Southwest_direction_Black(Board_Row_Number,Board_Column_Number);

            board_change_function_Northwest_direction_Black(Board_Row_Number,Board_Column_Number);

        }

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

    cout<<"盤面上の白石の数は"<<White_count<<"です"<<endl;
    cout<<"盤面上の黒石の数は"<<Black_count<<"です"<<endl;

    if(White_count > Black_count) cout<<"白の勝ちです!"<<endl;
    else if(White_count < Black_count) cout<<"黒の勝ちです!"<<endl;
    else cout<<"引き分けです!"<<endl;

    return 0;
 
}
