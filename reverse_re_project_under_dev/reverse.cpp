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

/////////////////////////////////////////////////////////////////////
//ここから白色に関する関数.

void board_color_change_function_left_direction(int line_num,int row_num){
 
}

int check_box_Black[3][3];

int main(){
    //Board board;
    //board.Print();

    init_board_number();

    bool battle_pre = true;
    char row;
    int line_number;
    int row_number;

    //先手は白である.
    while(battle_pre){

        board.Print();
        
        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>line_number;

        //check boxの初期化をする.
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                check_box_Black[i][j] = -1;
            }
        }

        
        line_number = line_number - 1;
        row_number = (row - 'A');

        board.PlacePiece(line_number,row_number,White);
        board_number[line_number][row_number] = 1;

        //最近接を探索するための変数になる.置いた石に対して最近接左上から探索開始
        int start_line_number = line_number - 1;
        int start_row_number = row_number - 1;

        //角に置いた場合は,最近接が3マス.4パターンで場合分け
        bool upper_right_edge = false;
        bool upper_left_edge = false;
        bool lower_right_edge = false;
        bool lower_left_edge = false;

        //角でない.かつ端の場合は4パターンある
        
        //start_line_number == 0(盤面の左端かつ角でない)ときは最近接が5マス

        //start_row_number == 0(盤面の上端かつ角でない)ときは最近接が5マス

        //start_line_number == 0(盤面の右端かつ角でない)ときは最近接が5マス

        //start_row_number == 0(盤面の下端かつ角でない)ときは最近接が5マス



        //端に置いていない場合は,最近接が8マスある.その場合の処理である

        for(int i = start_line_number; i <= start_line_number + 2; i++){
            for(int j = start_row_number; j <= start_row_number + 2; j++){
                if(i == line_number && j == row_number) continue;
                if(board_number[i][j] == 0) check_box_Black[i][j] = 0;
                else if(board_number[i][j] == 2) check_box_Black[i][j] = 2;
            }
        }


        //端に置いている場合(line == 0 or row == 0)は,最近接は5マスになる.その場合の処理である
        if(edge_line_hantei == true){

        }

        if(edge_row_hantei == true){

        }

        //最近接が8マスか5マスで,int型 check_box_Black 配列の場合分けも変わる.



        //置いた石に対して左上に黒い石が存在し,変更の可能性がある.
        if(check_box_Black[start_line_number][start_row_number] == 0)


        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board_number[i][j];
            }
            cout<<endl;
        }    

        board.Print();

        row = ' ';
        line_number = 0;

        cout<<"どこに置きますか? 列に対応する英文字→";
        cin>>row;
        cout<<"どこに置きますか? 行に対応する数字→";
        cin>>line_number;

        row_number = (row - 'A');
        line_number = line_number - 1;

        board.PlacePiece(line_number,row_number,Black);
        board_number[line_number][row_number] = 0;

        row_check = row_number - 1;
        line_check = line_number - 1;

     
        board.Print();
    }

}
