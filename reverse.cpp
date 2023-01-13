#include <iostream>
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
        cout<<"  ";
        for(int k=0;k<8;k++){
            cout<<(char)(k + 65) <<" ";
        }
        cout<<endl;
        for (int i = 0; i < 8; i++) {
            cout<< (i+1) <<" ";
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

void init_board_number(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board_number[i][j] = 2;
        }
    }
    board_number[3][3] = 1;
    board_number[4][4] = 1;
    board_number[3][4] = 0; 
    board_number[4][3] = 0;
}

void board_change_line_white(int line_num,int row_num){
    int board_line[8];

    for(int i=0;i<8;i++){
        int hantei_number = board_number[line_num][i];
        if(hantei_number == 1) board_line[i] = 1;
        if(hantei_number == 0) board_line[i] = 0;
        if(hantei_number == 2) board_line[i] = 2;
    }

    for(int i=0;i<8;i++){
        int hantei_number = board_number[line_num][i];
        if(board_line[i] == 1){
            for(int j=i+1;j<8;j++){
                //cout<<"j:"<<j<<endl;
                if(board_number[line_num][j] == 1) break;
                if(board_number[line_num][j] == 0){
                    board_number[line_num][j] = 1;

                    board.PlacePiece(line_num,j,White);

                }
                
            }
            break;
        }
    }
}

void board_change_row_white(int line_num,int row_num){
    int board_row[8];

    for(int i=0;i<8;i++){
        int hantei_number = board_number[i][row_num];
        if(hantei_number == 1) board_row[i] = 1;
        if(hantei_number == 0) board_row[i] = 0;
        if(hantei_number == 2) board_row[i] = 2;
    }

    for(int i=0;i<8;i++){
        int hantei_number = board_number[i][row_num];
        if(board_row[i] == 1){
            for(int j=i+1;j<8;j++){
                //cout<<"j:"<<j<<endl;
                if(board_number[j][row_num] == 1) break;

                if(board_number[j][row_num] == 0){
                    board_number[j][row_num] = 1;
                    board.PlacePiece(j,row_num,White);
                }
            
            }
            break;
        }
    }
}

void board_change_line_Black(int line_num,int row_num){
    int board_line[8];

    for(int i=0;i<8;i++){
        int hantei_number = board_number[line_num][i];
        if(hantei_number == 1) board_line[i] = 1;
        if(hantei_number == 0) board_line[i] = 0;
        if(hantei_number == 2) board_line[i] = 2;
    }

    for(int i=0;i<8;i++){
        int hantei_number = board_number[line_num][i];
        if(board_line[i] == 0){
            for(int j=i+1;j<8;j++){
                //cout<<"j:"<<j<<endl;
                if(board_number[line_num][j] == 0) break;

                if(board_number[line_num][j] == 1){
                    board_number[line_num][j] = 0;

                    board.PlacePiece(line_num,j,Black);

                }
                
            }
            break;
        }
    }
}

void board_change_row_Black(int line_num,int row_num){
    int board_row[8];

    for(int i=0;i<8;i++){
        int hantei_number = board_number[i][row_num];
        if(hantei_number == 1) board_row[i] = 1;
        if(hantei_number == 0) board_row[i] = 0;
        if(hantei_number == 2) board_row[i] = 2;
    }

    for(int i=0;i<8;i++){
        int hantei_number = board_number[i][row_num];
        if(board_row[i] == 0){
            for(int j=i+1;j<8;j++){
                //cout<<"j:"<<j<<endl;
                if(board_number[j][row_num] == 0) break;

                if(board_number[j][row_num] == 1){
                    board_number[j][row_num] = 0;
                    board.PlacePiece(j,row_num,Black);
                }
                
            }
            break;
        }
    }
}


void board_change_cross_to_left_Black(int line_num,int row_num){
    int board_cross[8];
    int line_kahen = 0;
    int row_kahen = row_num + line_num;
    int cross_num = 0;

    for(int i=0;i<8;i++) board_cross[i] = 0;

    while(line_kahen != 7 || row_kahen != 0){
        int hantei_number = board_number[line_kahen][row_kahen];
        if(hantei_number == 1) board_cross[cross_num] = 1;
        if(hantei_number == 0) board_cross[cross_num] = 0;
        if(hantei_number == 2) board_cross[cross_num] = 2;
        line_kahen++;
        row_kahen--;
        cross_num++;
    }

    int cnt = 0 ;
    for(int i=0;i<8;i++){
        if(board_cross[i] > 0) cnt++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<cnt;i++){
        int hantei_number = board_cross[i];
        if(hantei_number == 0){
            while(line_kahen != 7 || row_kahen != 0){
                cout<<line_kahen<<endl;
                cout<<row_kahen<<endl;
                line_kahen++;
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 0) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}


int main() {
    //Board board;
    //board.Print();

    init_board_number();

    bool battle_pre = true;

    //先手は白である.
    while(battle_pre){
        board.Print();

        char row;
        int line_number;
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>line_number;

        int row_number = (row - 'A');
        line_number = line_number - 1;

        board.PlacePiece(line_number,row_number,White);
        board_number[line_number][row_number] = 1;

        board_change_line_white(line_number,row_number);
        board_change_row_white(line_number,row_number);
        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board_number[i][j];
            }
            cout<<endl;
        }    

        board.Print();

        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>line_number;

        row_number = (row - 'A');
        line_number = line_number - 1;

        board.PlacePiece(line_number,row_number,Black);
        board_number[line_number][row_number] = 0;

        board_change_line_Black(line_number,row_number);
        board_change_row_Black(line_number,row_number);
        board_change_cross_to_left_Black(line_number,row_number);
        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board_number[i][j];
            }
            cout<<endl;
        }

        
    }


    return 0;
}
