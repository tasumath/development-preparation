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

void board_change_line_vertical_to_up_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != -1){
                line_kahen--;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_line_vertical_to_down_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != 8){
                line_kahen++;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_line_parallel_to_right_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(row_kahen != 8){
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_line_parallel_to_left_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    cout<<"line_kahen"<<line_kahen<<endl;
    cout<<"row_kahen"<<row_kahen<<endl;

    while(row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        cout<<"hantei_number:"<<hantei_number<<endl;
        cout<<"row_kahen:"<<row_kahen<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        cout<<"hantei_number:"<<hantei_number<<endl;
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(row_kahen != -1){
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_cross_to_up_left_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != -1 || row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != -1 || row_kahen != -1){
                line_kahen--;
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_cross_to_up_right_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != -1 || row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != -1 || row_kahen != 8){
                line_kahen--;
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_cross_to_down_left_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != 8 || row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != 8 || row_kahen != -1){
                line_kahen++;
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

void board_change_cross_to_down_right_White(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != 8 || row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 1){
            while(line_kahen != 8 || row_kahen != 8){
                line_kahen++;
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 1 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 0){
                    board_number[line_kahen][row_kahen] = 1;
                    board.PlacePiece(line_kahen,row_kahen,White);
                }
            }
        }
    }
}

//ここから黒石に関する関数.

void board_change_line_vertical_to_up_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != -1){
                line_kahen--;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_line_vertical_to_down_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != 8){
                line_kahen++;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_line_parallel_to_right_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(row_kahen != 8){
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_line_parallel_to_left_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        cout<<"hantei_number:"<<hantei_number<<endl;
        cout<<"row_kahen:"<<row_kahen<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        cout<<"hantei_number:"<<hantei_number<<endl;
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(row_kahen != -1){
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_cross_to_up_left_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    while(line_kahen != -1 || row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != -1 || row_kahen != -1){
                line_kahen--;
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_cross_to_up_right_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != -1 || row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen--;
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != -1 || row_kahen != 8){
                line_kahen--;
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_cross_to_down_left_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != 8 || row_kahen != -1){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
        row_kahen--;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != 8 || row_kahen != -1){
                line_kahen++;
                row_kahen--;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

void board_change_cross_to_down_right_Black(int line_num,int row_num){
    vector<int> board_cross;
    int line_kahen = line_num;
    int row_kahen = row_num;
    //cout<<"line_kahen"<<line_kahen<<endl;
    //cout<<"row_kahen"<<row_kahen<<endl;

    int cross_num = 0;

    while(line_kahen != 8 || row_kahen != 8){
        int hantei_number = board_number[line_kahen][row_kahen];
        //cout<<"hantei_number"<<hantei_number<<endl;
        if(hantei_number == 1) board_cross.push_back(1);
        if(hantei_number == 0) board_cross.push_back(0);
        if(hantei_number == 2) board_cross.push_back(2);
        line_kahen++;
        row_kahen++;
    }

    line_kahen = line_num;
    row_kahen = row_num;

    for(int i=0;i<(int)board_cross.size();i++){
        int hantei_number = board_cross.front();
        board_cross.erase(board_cross.begin());
        if(hantei_number == 0){
            while(line_kahen != 8 || row_kahen != 8){
                line_kahen++;
                row_kahen++;
                if(board_number[line_kahen][row_kahen] == 0 || board_number[line_kahen][row_kahen] == 2) break;
                if(board_number[line_kahen][row_kahen] == 1){
                    board_number[line_kahen][row_kahen] = 0;
                    board.PlacePiece(line_kahen,row_kahen,Black);
                }
            }
        }
    }
}

int row_check;
int line_check;
int check_box[8][8];
int cnt = 0;

int main() {
    //Board board;
    //board.Print();

    init_board_number();

    bool battle_pre = true;
    bool battle_white = true;
    bool battle_black = true;

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

        row_check = row_number - 1;
        line_check = line_number - 1;

        //置いた石の周りを確かめる.対応する位置に黒白があった場合に関数を呼び出す.
        //(-1,-1)
        
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_cross_to_up_left_White(line_number,row_number);
            board_change_cross_to_down_right_White(line_number,row_number);
        }
        line_check++;
        //(0,-1)
        
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check:"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_line_parallel_to_left_White(line_number,row_number);
            board_change_line_parallel_to_right_White(line_number,row_number);
        }
        line_check++;
        //(1,-1)
        //cout<<"row_check"<<row_check<<endl;
        //cout<<"line_check::"<<line_check<<endl;


        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check::"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_cross_to_up_right_White(line_number,row_number);
            board_change_cross_to_down_left_White(line_number,row_number);
        }
        line_check = line_check - 2;
        row_check++;
        //(-1,0)
        
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_line_vertical_to_down_White(line_number,row_number);
            board_change_line_vertical_to_up_White(line_number,row_number);
        }
        line_check = line_check + 2;
        //(1,0)
       
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check::"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_line_vertical_to_up_White(line_number,row_number);
            board_change_line_vertical_to_down_White(line_number,row_number);   
        }
        line_check = line_check - 2;
        row_check++;
        //(-1,1)
      
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_cross_to_down_left_White(line_number,row_number);
            board_change_cross_to_up_right_White(line_number,row_number);
        }
        line_check++;
        //(0,1)
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check:"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_line_parallel_to_left_White(line_number,row_number);
            board_change_line_parallel_to_right_White(line_number,row_number);
        }
        line_check++;
        //(1,1)
        
        if(board_number[line_check][row_check] == 0){
            //cout<<"line_check::"<<line_check<<endl;
            //cout<<"row_check"<<row_check<<endl;
            board_change_cross_to_down_right_White(line_number,row_number);
            board_change_cross_to_up_left_White(line_number,row_number);
        }
        
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

        row_check = row_number - 1;
        line_check = line_number - 1;

        //置いた石の周りを確かめる.対応する位置に白石があった場合に関数を呼び出す.
        //cout<<"line_number ="<<line_number<<endl;
        //cout<<"row_number ="<<row_number<<endl;

        //(-1,-1)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
       
        
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_cross_to_up_left_Black(line_number,row_number);
            board_change_cross_to_down_right_Black(line_number,row_number);
        }
        line_check++;
        //(0,-1)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;

        
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_line_parallel_to_left_Black(line_number,row_number);
            board_change_line_parallel_to_right_Black(line_number,row_number);
        }
        line_check++;
        //(1,-1)

        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
        
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_cross_to_up_right_Black(line_number,row_number);
            board_change_cross_to_down_left_Black(line_number,row_number);
        }
        line_check = line_check - 2;
        row_check++;
        //(-1,0)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
        
        if(board_number[line_check][row_check] == 1){
           
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_line_vertical_to_down_Black(line_number,row_number);
            board_change_line_vertical_to_up_Black(line_number,row_number);
        }
        line_check = line_check + 2;
        //(1,0)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
       
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_line_vertical_to_up_Black(line_number,row_number);
            board_change_line_vertical_to_down_Black(line_number,row_number);   
        }
        line_check = line_check - 2;
        row_check++;
        //(-1,1)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
      
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_cross_to_down_left_Black(line_number,row_number);
            board_change_cross_to_up_right_Black(line_number,row_number);
        }
        line_check++;
        //(0,1)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
        
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_line_parallel_to_left_Black(line_number,row_number);
            board_change_line_parallel_to_right_Black(line_number,row_number);
        }
        line_check++;
        //(1,1)
        //cout<<"line_check ="<<line_check<<endl;
        //cout<<"row_check ="<<row_check<<endl;
        //cout<<"board_number["<<line_check<<"]["<<row_check<<"]="<<board_number[line_check][row_check]<<endl;
        
        if(board_number[line_check][row_check] == 1){
            //cout<<"line_check ="<<line_check<<endl;
            //cout<<"row_check ="<<row_check<<endl;
            board_change_cross_to_down_right_Black(line_number,row_number);
            board_change_cross_to_up_left_Black(line_number,row_number);
        }
        board.Print();
    }

    return 0;
}
