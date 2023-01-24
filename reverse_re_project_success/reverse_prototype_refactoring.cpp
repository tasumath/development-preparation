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

            int next_Black_memory = -2;

            for(int i = Start_Row_number - 1; i >= 0; i--){
                if(board_number[i][start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_Column_number] == 1){
                    next_Black_memory = i;
                    break;
                }
                if(i == 0 && board_number[i][start_Column_number] == 0){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Row_number; i >= next_Black_memory; i--){
                    board_number[i][start_Column_number] = 1;
                    board.PlacePiece(i,start_Column_number,White);
                }
            }

}

void board_change_function_East_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            for(int i = Start_Column_number + 1; i < 8; i++){
                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }

                if(i == 7 && board_number[Start_Row_number][i] == 0){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){

                for(int i = Start_Column_number + 1; i <= next_Black_memory; i++){
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                }
            }
}

void board_change_function_South_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            for(int i = Start_Row_number + 1; i < 8; i++){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1){
                    next_Black_memory = i;
                    break;
                }

                if(i == 7 && board_number[i][Start_Column_number] == 0){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Row_number + 1; i <= next_Black_memory; i++){
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                }
            }
}

void board_change_function_West_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            for(int i = Start_Column_number - 1; i >= 0; i--){
                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }
                if(i == 0 && board_number[Start_Row_number][i] == 0){
                    next_Black_memory = -1;
                    break;
                }
                
            }

            if(next_Black_memory != -1){
                for(int i = Start_Column_number; i >= next_Black_memory; i--){
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                }
            }
}

void board_change_function_Northeast_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            Start_Row_number = Row_number - 1;

            for(int i = Start_Column_number + 1; i < 8; i++){
                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }

                if((Start_Row_number == 0 || i == 7) && board_number[Start_Row_number][i] == 0){
                    next_Black_memory = -1;
                    break;
                }
                Start_Row_number--;
            }

            Start_Row_number = Row_number - 1;

            if(next_Black_memory != -1){
                for(int i = Start_Column_number + 1; i <= next_Black_memory; i++){
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                    Start_Row_number--;
                }
            }
}

void board_change_function_Northwest_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;
            Start_Column_number = Column_number - 1;

            for(int i = Start_Row_number - 1; i >= 0; i--){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1){
                    next_Black_memory = i;
                    break;
                }
                if((Start_Column_number == 0 || i == 0) && board_number[i][Start_Column_number] == 0){
                    next_Black_memory = -1;
                    break;
                }
                Start_Column_number--;
            }

            Start_Column_number = Column_number - 1;

            if(next_Black_memory != -1){
                for(int i = Start_Row_number - 1; i >= next_Black_memory; i--){
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                    Start_Column_number--;
                }
            }

}

void board_change_function_Southeast_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            Start_Column_number = Column_number + 1;

            for(int i = Start_Row_number + 1; i < 8; i++){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 1){
                    next_Black_memory = i;
                    break;
                }

                if((Start_Column_number == 7 || i == 7) && board_number[i][Start_Column_number] == 0){
                    next_Black_memory = -1;
                    break;
                }
                Start_Column_number++;
            }

            Start_Column_number = Column_number + 1;

            if(next_Black_memory != -1){

                for(int i = Start_Row_number + 1; i <= next_Black_memory; i++){
  
                    board_number[i][Start_Column_number] = 1;
                    board.PlacePiece(i,Start_Column_number,White);
                    Start_Column_number++;
                }
            }
}

void board_change_function_Southwest_direction_White(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;
            Start_Row_number = Row_number + 1;

            for(int i = Start_Column_number - 1; i >= 0; i--){

                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }
                if((Start_Row_number == 7 || i == 0) && board_number[Start_Row_number][i] == 0){
                    next_Black_memory = -1;
                    break;
                }
                Start_Row_number++;

            }

            Start_Row_number = Row_number + 1;

            if(next_Black_memory != -1){
                for(int i = Start_Column_number - 1; i >= next_Black_memory; i--){
                    board_number[Start_Row_number][i] = 1;
                    board.PlacePiece(Start_Row_number,i,White);
                    Start_Row_number++;
                }
            }
}


////////////////////////////////////////////////////////////////////////////////////

// Functions that performs changes to the board when a bLack stone is placed

void board_change_function_East_direction_Black(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;


            for(int i = Start_Column_number + 1; i < 8; i++){
                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 0){
                    next_Black_memory = i;
                    break;
                }
                if(i == 7 && board_number[Start_Row_number][i] == 1){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Column_number + 1; i <= next_Black_memory; i++){
                    board_number[Start_Row_number][i] = 0;
                    board.PlacePiece(Start_Row_number,i,Black);
                }
            }
}

void board_change_function_South_direction_Black(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            for(int i = Start_Row_number + 1; i < 8; i++){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0){
                    next_Black_memory = i;
                    break;
                }
                if(i == 7 && board_number[i][Start_Column_number] == 1){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Row_number + 1; i <= next_Black_memory; i++){
                    board_number[i][Start_Column_number ] = 0;
                    board.PlacePiece(i,Start_Column_number ,Black);
                }
            }
}

void board_change_function_West_direction_Black(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;

            for(int i = Start_Column_number - 1; i >= 0; i--){
                if(board_number[Start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[Start_Row_number][i] == 0){
                    next_Black_memory = i;
                    break;
                }

                if(i == 0 && board_number[Start_Row_number][i] == 1){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Column_number; i >= next_Black_memory; i--){
                    board_number[Start_Row_number][i] = 0;
                    board.PlacePiece(Start_Row_number,i,Black);
                }
            }
}

void board_change_function_North_direction_Black(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;


            for(int i = Start_Row_number - 1; i >= 0; i--){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0){
                    next_Black_memory = i;
                    break;
                }

                if(i == 0 && board_number[i][Start_Column_number] == 1){
                    next_Black_memory = -1;
                    break;
                }
            }

            if(next_Black_memory != -1){
                for(int i = Start_Row_number; i >= next_Black_memory; i--){
                    board_number[i][Start_Column_number] = 0;
                    board.PlacePiece(i,Start_Column_number,Black);
                }
            }
}

void board_change_function_Southeast_direction_Black(int Row_number,int Column_number){

            int Start_Row_number = Row_number;
            int Start_Column_number = Column_number;

            int next_Black_memory = -2;
            Start_Column_number = Column_number + 1;

            for(int i = Start_Row_number + 1; i < 8; i++){
                if(board_number[i][Start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][Start_Column_number] == 0){
                    next_Black_memory = i;
                    break;
                }
                if((Start_Column_number == 7 || i == 7) && board_number[i][Start_Column_number] == 1){
                    next_Black_memory = -1;
                    break;
                }
                Start_Column_number++;
            }

            Start_Column_number = Column_number + 1;

            if(next_Black_memory != -1){
                for(int i = Start_Row_number + 1; i <= next_Black_memory; i++){
                    board_number[i][Start_Column_number] = 0;
                    board.PlacePiece(i,Start_Column_number,Black);
                    Start_Column_number++;
                }
            }
}

void board_change_function_Southwest_direction_Black(int Row_number,int Column_number){

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int next_Black_memory = -2;

            start_Row_number = Row_number + 1;

            for(int i = start_Column_number - 1; i >= 0; i--){
                if(board_number[start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_Row_number][i] == 0){
                    next_Black_memory = i;
                    break;
                }
                if((start_Row_number == 7 || i == 0) && board_number[start_Row_number][i] == 1){
                    next_Black_memory = -1;
                    break;
                }
                start_Row_number++;
            }

            start_Row_number = Row_number + 1;

            if(next_Black_memory != -1){
                for(int i = start_Column_number - 1; i >= next_Black_memory; i--){

                    board_number[start_Row_number][i] = 0;
                    board.PlacePiece(start_Row_number,i,Black);
                    start_Row_number++;
                }
            }
}


void board_change_function_Northeast_direction_Black(int Row_number,int Column_number){

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int next_Black_memory = -2;
            start_Row_number = Row_number - 1;

            for(int i = start_Column_number + 1; i < 8; i++){
                if(board_number[start_Row_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_Row_number][i] == 0){
                    next_Black_memory = i;
                    break;
                }

                if((start_Row_number == 0 || i == 7) && board_number[start_Row_number][i] == 1){
                    next_Black_memory = -1;
                    break;
                }
                start_Row_number--;
            }

            start_Row_number = Row_number - 1;

            if(next_Black_memory != -1){
                for(int i = start_Column_number + 1; i <= next_Black_memory; i++){
                    board_number[start_Row_number][i] = 0;
                    board.PlacePiece(start_Row_number,i,Black);
                    start_Row_number--;
                }
            }
}

void board_change_function_Northwest_direction_Black(int Row_number,int Column_number){

            int start_Row_number = Row_number;
            int start_Column_number = Column_number;

            int next_Black_memory = -2;
            start_Column_number = Column_number - 1;

            for(int i = start_Row_number - 1; i >= 0; i--){
                if(board_number[i][start_Column_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_Column_number] == 0){
                    next_Black_memory = i;
                    break;
                }
                if((start_Column_number == 0 || i == 0) && board_number[i][start_Column_number] == 1){
                    next_Black_memory = -1;
                    break;
                }
                start_Column_number--;
            }

            start_Column_number = Column_number - 1;

            if(next_Black_memory != -1){
                for(int i = start_Row_number - 1; i >= next_Black_memory; i--){
                    board_number[i][start_Column_number] = 0;
                    board.PlacePiece(i,start_Column_number,Black);
                    start_Column_number--;
                }
            }
}


int main(){

    init_board_number();

    bool battle_pre = true;
    char row;
    int board_line_number;
    int board_row_number;

    while(battle_pre){

        board.Print();
        cout<<"白の番です"<<endl;
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>board_line_number;
        
        board_line_number = board_line_number - 1;
        board_row_number = (row - 'A');

        board.PlacePiece(board_line_number,board_row_number,White);
        board_number[board_line_number][board_row_number] = 1;

        //最近接が3,5マスのいずれかの場合,それをカウントする.
        int case_count = 0;

        bool upper_left_edge_White = false;

        if(board_line_number == 0 && board_row_number == 0 && case_count == 0){
            upper_left_edge_White = true;
            case_count++;

            board_change_function_East_direction_White(board_line_number,board_row_number);

            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_Southeast_direction_White(board_line_number,board_row_number);

        }

        bool upper_right_edge_White = false;

        if(board_line_number == 0 && board_row_number == 7 && case_count == 0){
            upper_right_edge_White = true;
            case_count++;

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_Southwest_direction_White(board_line_number,board_row_number);

        }

        bool lower_left_edge_White = false;

        if(board_line_number == 7 && board_row_number == 0 && case_count == 0){
            upper_left_edge_White = true;
            case_count++;

            board_change_function_East_direction_White(board_line_number,board_row_number);

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_Northeast_direction_White(board_line_number,board_row_number);

        }

        bool lower_right_edge_White = false;

        if(board_line_number == 7 && board_row_number == 7 && case_count == 0){
            lower_right_edge_White = true;
            case_count++;

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_Northwest_direction_White(board_line_number,board_row_number);

        }

        bool left_side_White = false;

        if(board_line_number != 0 && board_line_number != 7 && board_row_number == 0 && case_count == 0){
            left_side_White = true;
            case_count++;

            board_change_function_East_direction_White(board_line_number,board_row_number);

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_Northeast_direction_White(board_line_number,board_row_number);

            board_change_function_Southeast_direction_White(board_line_number,board_row_number);

        }


        bool upper_side_White = false;

        if(board_line_number == 0 && board_row_number != 0 && board_row_number != 7 && case_count == 0){
            upper_side_White = true;
            case_count++;

            board_change_function_East_direction_White(board_line_number,board_row_number);

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_Southeast_direction_White(board_line_number,board_row_number);

            board_change_function_Southwest_direction_White(board_line_number,board_row_number);

        }

        bool right_side_White = false;

        if(board_line_number != 0 && board_line_number != 7 && board_row_number == 7 && case_count == 0){
            right_side_White = true;
            case_count++;

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_Northwest_direction_White(board_line_number,board_row_number);

            board_change_function_Southwest_direction_White(board_line_number,board_row_number);

        }

        bool lower_side_White = false;

        if(board_line_number == 7 && board_row_number != 0 && board_row_number != 7 && case_count == 0){
            lower_side_White = true;
            case_count++;

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_East_direction_White(board_line_number,board_row_number);

            board_change_function_Northwest_direction_White(board_line_number,board_row_number);

            board_change_function_Northeast_direction_White(board_line_number,board_row_number);

        }

        //これまでのケースに該当しない石の置き方には,最近接のマス目が9マスある.
        if(case_count == 0){
            case_count++;

            board_change_function_North_direction_White(board_line_number,board_row_number);

            board_change_function_East_direction_White(board_line_number,board_row_number);
            
            board_change_function_South_direction_White(board_line_number,board_row_number);

            board_change_function_West_direction_White(board_line_number,board_row_number);

            board_change_function_Northeast_direction_White(board_line_number,board_row_number);

            board_change_function_Southeast_direction_White(board_line_number,board_row_number);

            board_change_function_Southwest_direction_White(board_line_number,board_row_number);

            board_change_function_Northwest_direction_White(board_line_number,board_row_number);

        }

        int empty_count = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board_number[i][j] == 2) empty_count++;
            }
        }

        if(empty_count == 0) break;
        else empty_count = 0;
            

        board.Print();

        /////////////////////////////////////////////////////////////////////////////

        cout<<"黒の番です"<<endl;
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>board_line_number;

        board_row_number = (row - 'A');
        board_line_number = board_line_number - 1;

        board.PlacePiece(board_line_number,board_row_number,Black);
        board_number[board_line_number][board_row_number] = 0;

        //最近接が3,5マスのいずれかの場合,それをカウントする.
        case_count = 0;

        bool upper_left_edge_Black = false;

        if(board_line_number == 0 && board_row_number == 0 && case_count == 0){
            upper_left_edge_Black = true;
            case_count++;

            board_change_function_East_direction_Black(board_line_number,board_row_number);

            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_Southeast_direction_Black(board_line_number,board_row_number);

        }

        bool upper_right_edge_Black = false;

        if(board_line_number == 0 && board_row_number == 7 && case_count == 0){
            upper_right_edge_Black = true;
            case_count++;

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_Southwest_direction_Black(board_line_number,board_row_number);

        }

        bool lower_left_edge_Black = false;

        if(board_line_number == 7 && board_row_number == 0 && case_count == 0){
            upper_left_edge_Black = true;
            case_count++;

            board_change_function_East_direction_Black(board_line_number,board_row_number);

            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_Northeast_direction_Black(board_line_number,board_row_number);

        }

        bool lower_right_edge_Black = false;

        if(board_line_number == 7 && board_row_number == 7 && case_count == 0){
            lower_right_edge_Black = true;
            case_count++;

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_Northwest_direction_Black(board_line_number,board_row_number);

        }

        bool left_side_Black = false;

        if(board_line_number != 0 && board_line_number != 7 && board_row_number == 0 && case_count == 0){
            left_side_Black = true;
            case_count++;

            board_change_function_East_direction_Black(board_line_number,board_row_number);

            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_Northeast_direction_Black(board_line_number,board_row_number);

            board_change_function_Southeast_direction_Black(board_line_number,board_row_number);

        }


        bool upper_side_Black = false;

        if(board_line_number == 0 && board_row_number != 0 && board_row_number != 7 && case_count == 0){
            upper_side_Black = true;
            case_count++;

            board_change_function_East_direction_Black(board_line_number,board_row_number);

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_Southeast_direction_Black(board_line_number,board_row_number);

            board_change_function_Southwest_direction_Black(board_line_number,board_row_number);

        }

        bool right_side_Black = false;

        if(board_line_number != 0 && board_line_number != 7 && board_row_number == 7 && case_count == 0){
            right_side_Black = true;
            case_count++;

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_Northwest_direction_Black(board_line_number,board_row_number);

            board_change_function_Southwest_direction_Black(board_line_number,board_row_number);

        }

        bool lower_side_Black = false;

        if(board_line_number == 7 && board_row_number != 0 && board_row_number != 7 && case_count == 0){
            lower_side_Black = true;
            case_count++;

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_East_direction_Black(board_line_number,board_row_number);

            board_change_function_Northwest_direction_Black(board_line_number,board_row_number);

            board_change_function_Northeast_direction_Black(board_line_number,board_row_number);

        }

        //これまでのケースに該当しない石の置き方には,最近接のマス目が9マスある.
        if(case_count == 0){
            case_count++;
            board_change_function_North_direction_Black(board_line_number,board_row_number);

            board_change_function_East_direction_Black(board_line_number,board_row_number);
            
            board_change_function_South_direction_Black(board_line_number,board_row_number);

            board_change_function_West_direction_Black(board_line_number,board_row_number);

            board_change_function_Northeast_direction_Black(board_line_number,board_row_number);

            board_change_function_Southeast_direction_Black(board_line_number,board_row_number);

            board_change_function_Southwest_direction_Black(board_line_number,board_row_number);

            board_change_function_Northwest_direction_Black(board_line_number,board_row_number);

        }

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board_number[i][j] == 2) empty_count++;
            }
        }

        if(empty_count == 0) break;
        else empty_count = 0;

    }

    int White_count = 0;
    int Black_count = 0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
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