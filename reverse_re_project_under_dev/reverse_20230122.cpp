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
        board[0][1] = White;
        board[0][2] = Black;
        board[0][3] = White;
        //board[4][3] = Black;
        board[1][0] = Black;
        board[2][0] = Black;
        board[3][0] = Black;
        board[4][0] = Black;
        board[5][0] = White;

        board[1][1] = Black;
        board[2][2] = White;
        //board[3][3] = Black;

        board[1][7] = Black;
        board[2][7] = White;
        board[3][7] = Black;

        board[1][6] = Empty;
        board[2][5] = Black;
        //board[3][4] = White;

        board[0][6] = Black;
        board[0][5] = Black;
        board[0][4] = White;

        board[6][7] = Black;
        board[5][7] = White;
        board[4][7] = Black;

        board[6][6] = Empty;
        board[5][5] = White;
        //board[4][4] = Black;

        board[7][6] = Black;
        board[7][5] = Black;
        board[7][4] = White;
        board[6][6] = Black;

        board[6][1] = Black;
        board[1][6] = Black;
        board[2][5] = White;
        board[5][2] = White;
        board[6][0] = Black;
        board[7][1] = Black;
        board[7][2] = White;

        
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
    board_number[0][1] = 2;
    board_number[0][2] = 0;
    board_number[0][3] = 1;

    board_number[1][0] = 0;
    board_number[2][0] = 0;
    board_number[3][0] = 0;
    board_number[4][0] = 0;
    board_number[5][0] = 1;

    board_number[1][1] = 0;
    board_number[2][2] = 1;
    //board_number[3][3] = 0;

    board_number[1][7] = 0;
    board_number[2][7] = 1;
    board_number[3][7] = 0;

    board_number[6][1] = 2;
    board_number[5][2] = 1;
    //board_number[4][3] = 0;

    board_number[0][6] = 0;
    board_number[0][5] = 0;
    board_number[0][4] = 1;

    board_number[6][7] = 0;
    board_number[5][7] = 1;
    board_number[4][7] = 0;

    board_number[6][6] = 2;
    board_number[5][5] = 1;
    //board_number[4][4] = 0;

    board_number[7][6] = 0;
    board_number[7][5] = 0;
    board_number[7][4] = 1;
    board_number[6][6] = 0;
    //board_number[5][0] = 1;

    board_number[6][1] = 0;
    board_number[1][6] = 0;
    board_number[2][5] = 1;
    board_number[5][2] = 1;
    board_number[6][0] = 0;
    board_number[7][1] = 0;
    board_number[7][2] = 1;
 

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

        //最近接が3,5マスのいずれかの場合,それをカウントする.
        int case_count = 0;

        cout<<line_number<<row_number<<endl;

        //左端に白色の碁石を置いた場合の処理
        //1.行を固定して列で石の配置を探索する.
        bool upper_left_edge = false;
        if(line_number == 0 && row_number == 0 && case_count == 0){
            upper_left_edge = true;
            case_count++;

            //最近接を探索するための変数になる.
            int start_line_number = line_number;
            int start_row_number = row_number;
            int check_box[8];
            
            //行を固定して1列目(配列的には0列目)の石の配置を調べる.
            for(int i = start_row_number; i < 8; i++){
                if(board_number[start_line_number][i] == 1) check_box[i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[i] = 2;
            }

            int next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number + 1; i < 8; i++){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    //cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number + 1; i <= next_Black_memory; i++){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                }
            }
            //ここまでが行を固定して 1~8 列目(配列的には 0~7 列目)の石の配置を調べるアルゴリズムになる.


            //次に列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べる.
            for(int i = start_line_number; i < 8; i++){
                if(board_number[i][start_row_number] == 1) check_box[i] = 1;
                if(board_number[i][start_row_number] == 0) check_box[i] = 0;
                if(board_number[i][start_row_number] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number + 1; i < 8; i++){
                if(board_number[i][start_row_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_row_number] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number + 1; i <= next_Black_memory; i++){
                    board_number[i][start_row_number] = 1;
                    board.PlacePiece(i,start_row_number,White);
                }
            }
            //ここまでが列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べるアルゴリズムになる.


            //次に1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べる.
            for(int i = start_line_number; i < 8; i++){
                if(board_number[i][i] == 1) check_box[i] = 1;
                if(board_number[i][i] == 0) check_box[i] = 0;
                if(board_number[i][i] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number + 1; i < 8; i++){
                if(board_number[i][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][i] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number + 1; i <= next_Black_memory; i++){
                    board_number[i][i] = 1;
                    board.PlacePiece(i,i,White);
                }
            }
            //ここまでが,1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べるアルゴリズムになる.
        }
        //1/21 11:52 左端に白石を置いた際のアルゴリズムは完了した.(黒の場合も同じ要領でやればよい)

        //角に置いた場合は,最近接が3マス.4パターンで場合分け
        bool upper_right_edge = false;
        if(line_number == 0 && row_number == 7 && case_count == 0){
            upper_right_edge = true;
            case_count++;

            //最近接を探索するための変数になる.
            int start_line_number = line_number;
            int start_row_number = row_number;
            int check_box[8];
            
            //行を固定して1列目(配列的には0列目)の石の配置を調べる.←
            for(int i = start_row_number; i >= 0; i--){
                if(board_number[start_line_number][i] == 1) check_box[start_row_number - i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[start_row_number - i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[start_row_number - i] = 2;
            }

            int next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number - 1; i >= 0; i--){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number; i >= next_Black_memory; i--){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                }
            }
            //ここまでが行を固定して 1~8 列目(配列的には 0~7 列目)の石の配置を調べるアルゴリズムになる.


            //次に列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べる.
            for(int i = start_line_number; i < 8; i++){
                if(board_number[i][start_row_number] == 1) check_box[i] = 1;
                if(board_number[i][start_row_number] == 0) check_box[i] = 0;
                if(board_number[i][start_row_number] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number + 1; i < 8; i++){
                if(board_number[i][start_row_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_row_number] == 1){
                    next_Black_memory = i;
                    cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number; i <= next_Black_memory; i++){
                    board_number[i][start_row_number] = 1;
                    board.PlacePiece(i,start_row_number,White);
                }
            }
            //ここまでが列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べるアルゴリズムになる.


            //次に1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,左斜め下への遷移し石の配置を調べる.
            for(int i = start_row_number; i >= 0; i--){
                if(board_number[start_line_number][i] == 1) check_box[i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[i] = 2;
                start_line_number++;
            }

            next_Black_memory = -2;
            start_line_number = line_number - 1;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number - 1; i >= 0; i--){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }
                start_line_number++;
            }

            start_line_number = line_number + 1;

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number - 1; i >= next_Black_memory; i--){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                    start_line_number++;
                }
            }
        }
        //ここまでが,1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,左斜め下への遷移し石の配置を調べるアルゴリズムになる.
        //1/21 23:24 右端に白石を置いた際のアルゴリズムは完了した.(黒の場合も同じ要領でやればよい)

        
        bool lower_right_edge = false;

        if(line_number == 7 && row_number == 7 && case_count == 0){
            lower_right_edge = true;
            case_count++;

            //最近接を探索するための変数になる.
            int start_line_number = line_number;
            int start_row_number = row_number;
            int check_box[8];
            
            //行を固定して8列目(配列的には7列目)の石の配置を調べる.
            for(int i = start_row_number; i >= 0; i--){
                if(board_number[start_line_number][i] == 1) check_box[i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[i] = 2;
            }

            int next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number - 1; i >= 0; i--){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    //cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number; i >= next_Black_memory; i--){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                }
            }
            //ここまでが行を固定して 1~8 列目(配列的には 0~7 列目)の石の配置を調べるアルゴリズムになる.


            //次に列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べる.
            for(int i = start_line_number; i >= 0; i--){
                if(board_number[i][start_row_number] == 1) check_box[i] = 1;
                if(board_number[i][start_row_number] == 0) check_box[i] = 0;
                if(board_number[i][start_row_number] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number - 1; i >= 0; i--){
                if(board_number[i][start_row_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_row_number] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number - 1; i >= next_Black_memory; i--){
                    board_number[i][start_row_number] = 1;
                    board.PlacePiece(i,start_row_number,White);
                }
            }
            //ここまでが列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べるアルゴリズムになる.


            //次に1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べる.
            for(int i = start_line_number; i >= 0; i--){
                if(board_number[i][i] == 1) check_box[i] = 1;
                if(board_number[i][i] == 0) check_box[i] = 0;
                if(board_number[i][i] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number - 1; i >= 0; i--){
                if(board_number[i][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][i] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number - 1; i >= next_Black_memory; i--){
                    board_number[i][i] = 1;
                    board.PlacePiece(i,i,White);
                }
            }
            //ここまでが,1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べるアルゴリズムになる.
        }
    
        //1/21 11:52 右端下に白石を置いた際のアルゴリズムは完了した.(黒の場合も同じ要領でやればよい)

        bool lower_left_edge = false;
        if(line_number == 7 && row_number == 0 && case_count == 0){
            upper_left_edge = true;
            case_count++;

            //最近接を探索するための変数になる.
            int start_line_number = line_number;
            int start_row_number = row_number;
            int check_box[8];
            
            //行を固定して1列目(配列的には0列目)の石の配置を調べる.←
            for(int i = start_row_number; i < 8; i++){
                if(board_number[start_line_number][i] == 1) check_box[start_row_number - i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[start_row_number - i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[start_row_number - i] = 2;
            }

            int next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number + 1; i < 8; i++){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    //cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number; i <= next_Black_memory; i++){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                }
            }
            //ここまでが行を固定して 1~8 列目(配列的には 0~7 列目)の石の配置を調べるアルゴリズムになる.


            //次に列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べる.
            for(int i = start_line_number; i >= 0; i--){
                if(board_number[i][start_row_number] == 1) check_box[i] = 1;
                if(board_number[i][start_row_number] == 0) check_box[i] = 0;
                if(board_number[i][start_row_number] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.
            //cout<<"start_line_number"<<start_line_number<<endl;
            //cout<<"start_row_number"<<start_row_number<<endl;

            for(int i = start_line_number - 1; i >= 0; i--){
                if(board_number[i][start_row_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_row_number] == 1){
                    next_Black_memory = i;
                    //cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number; i >= next_Black_memory; i--){
                    board_number[i][start_row_number] = 1;
                    board.PlacePiece(i,start_row_number,White);
                }
            }
            //ここまでが列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べるアルゴリズムになる.


            //次に1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め上への遷移し石の配置を調べる.
            for(int i = start_row_number; i < 8; i++){
                if(board_number[start_line_number][i] == 1) check_box[i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[i] = 2;
                start_line_number--;
            }

            next_Black_memory = -2;
            start_line_number = line_number - 1;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number + 1; i < 8; i++){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    break;
                }
                start_line_number--;
            }

            start_line_number = line_number - 1;

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number + 1; i <= next_Black_memory; i++){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                    start_line_number--;
                }
            }
        }
        //ここまでが,1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,左斜め下への遷移し石の配置を調べるアルゴリズムになる.
        //1/22 0:33 右端に白石を置いた際のアルゴリズムは完了した.(黒の場合も同じ要領でやればよい)

        /*/
        bool lower_left_edge = false;

        if(line_number == 7 && row_number == 0 && case_count == 0){
            lower_right_edge = true;
            case_count++;

            //最近接を探索するための変数になる.
            int start_line_number = line_number;
            int start_row_number = row_number;
            int check_box[8];
            
            //行を固定して8列目(配列的には7列目)の石の配置を調べる.
            for(int i = start_row_number; i >= 0; i--){
                if(board_number[start_line_number][i] == 1) check_box[i] = 1;
                if(board_number[start_line_number][i] == 0) check_box[i] = 0;
                if(board_number[start_line_number][i] == 2) check_box[i] = 2;
            }

            int next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_row_number + 1; i < 8; i++){
                if(board_number[start_line_number][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[start_line_number][i] == 1){
                    next_Black_memory = i;
                    //cout<<i<<endl;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_row_number; i <= next_Black_memory; i++){
                    board_number[start_line_number][i] = 1;
                    board.PlacePiece(start_line_number,i,White);
                }
            }
            //ここまでが行を固定して 1~8 列目(配列的には 0~7 列目)の石の配置を調べるアルゴリズムになる.


            //次に列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べる.
            for(int i = start_line_number; i >= 0; i--){
                if(board_number[i][start_row_number] == 1) check_box[i] = 1;
                if(board_number[i][start_row_number] == 0) check_box[i] = 0;
                if(board_number[i][start_row_number] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number - 1; i >= 0; i--){
                if(board_number[i][start_row_number] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][start_row_number] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number - 1; i >= next_Black_memory; i--){
                    board_number[i][start_row_number] = 1;
                    board.PlacePiece(i,start_row_number,White);
                }
            }
            //ここまでが列を固定して 1~8 行目(配列的には 0~7 行目)の石の配置を調べるアルゴリズムになる.


            //次に1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べる.
            for(int i = start_line_number; i >= 0; i--){
                if(board_number[i][i] == 1) check_box[i] = 1;
                if(board_number[i][i] == 0) check_box[i] = 0;
                if(board_number[i][i] == 2) check_box[i] = 2;
            }

            next_Black_memory = -2;

            //check_box[8]配列に石の配列を記憶させたら盤面の変更があるかどうかを判定する.
            //最近接が白,黒,何もないの3通りある.方針としては,次の[白],[何もない位置]までチェックを行う.
            //(*)WWと続いた場合は,次のfor文で制限をかけているため,バグらなかった.

            for(int i = start_line_number - 1; i >= 0; i--){
                if(board_number[i][i] == 2){
                    next_Black_memory = -1;
                    break;
                }
                if(board_number[i][i] == 1){
                    next_Black_memory = i;
                    break;
                }
            }

            //次の白石がある位置まで白色で書き換える.
            if(next_Black_memory != -1){
                //(*)start_row_number変数に対して,+1した所からスタートする.もし最近接が白であれば,start_row_number == next_Black_memoryになるため,ループが回らない.
                for(int i = start_line_number - 1; i >= next_Black_memory; i--){
                    board_number[i][i] = 1;
                    board.PlacePiece(i,i,White);
                }
            }
            //ここまでが,1~8 行目(配列的には 0~7 行目),1~8 列目(配列的には 0~7 列目)を同時に動かす.つまり,右斜め下への遷移し石の配置を調べるアルゴリズムになる.
        }
        //1/21 11:52 右端下に白石を置いた際のアルゴリズムは完了した.(黒の場合も同じ要領でやればよい)
        /*/


        //角でない.かつ端の場合は4パターンある
        bool left_side = false;
        bool upper_right_line = false;
        bool right_side = false;
        bool lower_left_line = false;
        
        //start_line_number == 0(盤面の左端かつ角でない)ときは最近接が5マス

        //start_row_number == 0(盤面の上端かつ角でない)ときは最近接が5マス

        //start_line_number == 0(盤面の右端かつ角でない)ときは最近接が5マス

        //start_row_number == 0(盤面の下端かつ角でない)ときは最近接が5マス

        //最近接を探索するための変数になる.置いた石に対して最近接左上から探索開始
        int start_line_number = line_number - 1;
        int start_row_number = row_number - 1;

        //端に置いていない場合は,最近接が8マスある.その場合の処理である

        for(int i = start_line_number; i <= start_line_number + 2; i++){
            for(int j = start_row_number; j <= start_row_number + 2; j++){
                if(i == line_number && j == row_number) continue;
                if(board_number[i][j] == 0) check_box_Black[i][j] = 0;
                else if(board_number[i][j] == 2) check_box_Black[i][j] = 2;
            }
        }


        //端に置いている場合(line == 0 or row == 0)は,最近接は5マスになる.その場合の処理である
        

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



     
        board.Print();
    }

 
}