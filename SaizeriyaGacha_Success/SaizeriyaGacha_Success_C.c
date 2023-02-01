//コマンドプロンプトで
//g++ -o out SaizeriyaGacha_success_C.c
//out.exeで実行する
//gccだとエラーが出る.原因は分からない

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct menu{
    char name[100];
    int value;
    int calorie;
    double salt_amount;
    int menu_number;
};

int main(){

    clock_t start,end;
    start = clock();

    menu m0 = {"小エビのサラダ",350,127,1.4,0};
    menu m1 = {"チキンのシーザーサラダ",350,203,1.3,1};
    menu m2 = {"ガーデンサラダ",350,173,0.7,2};
    menu m3 = {"コーンクリームスープ",150,146,1.1,3};
    menu m4 = {"白菜のクラムチャウダー",300,273,1.6,4};
    menu m5 = {"田舎風ミネストローネ",300,178,2.2,5};
    menu m6 = {"プチフォッカ",150,214,0.8,6};
    menu m7 = {"セットプチフォッカ",100,107,0.4,7};
    menu m8 = {"ほうれん草のくたくた",300,197,1.7,8};
    menu m9 = {"爽やかにんじんサラダ",200,93,0.9,9};
    menu m10 = {"ペコリーノ・ロマーノ",100,78,0.8,10};
    menu m11 = {"ビール",400,160,0,11};
    menu m12 = {"シナモンプチフォッカ",200,246,0.8,12};
    menu m13 = {"ミニフィセル",150,189,1.0,13};
    menu m14 = {"ガーリックトースト",150,245,1.1,14};
    menu m15 = {"ブロッコリーのくたくた",300,125,1.1,15};
    menu m16 = {"柔らか青豆とペコリーノチーズの温サラダ",200,199,1.0,16};
    menu m17 = {"バッファローモッツァレラ",300,209,0.5,17};
    menu m18 = {"辛味チキン",300,295,1.8,18};
    menu m19 = {"カリッとポテト",250,389,2.1,19};
    menu m20= {"ポップコーンシュリンプ",300,215,1.4,20};
    menu m21 = {"煉獄のたまご",300,319,2.0,21};
    menu m22 = {"イタリア風もつ煮込み",350,202,0.8,22};
    menu m23 = {"エスカルゴのオーブン焼き",400,220,1.3,23};
    menu m24 = {"アロスティチーニ",400,224,0.6,24};
    menu m25= {"チョリソー",400,425,2.9,25};
    menu m26 = {"ムール貝のガーリック焼き",400,170,1.4,26};
    menu m27 = {"エビクリームグラタン",400,505,2.0,27};
    menu m28= {"ミラノ風ドリア",300,521,2.5,28};
    menu m29= {"チーズたっぷりミラノ風ドリア",400,722,3.4,29};
    menu m30 = {"セットプチフォッカ付きミラノ風ドリア",400,628,2.9,30};
    menu m31 = {"半熟卵のミラノ風ドリア",400,604,2.7,31};
    menu m32 = {"マルゲリータピザ",400,557,2.4,32};
    menu m33 = {"バッファローモッツァレラのピザ",500,566,2.2,33};
    menu m34 = {"オリーブアンチョビのマルゲリータピザ",500,648,3.3,34};
    menu m35 = {"たっぷりコーンのピザ",400,624,2.4,35};
    menu m36 = {"ソーセージピザ",400,710,4.1,36};
    menu m37 = {"タラコソースシシリー風",400,548,1.9,37};
    menu m38 = {"ミートソースボロニア風",400,564,2.7,38};
    menu m39 = {"ペンネアラビアータ",400,416,3.0,39};
    menu m40 = {"ペペロンチーノ",300,541,1.6,40};
    menu m41 = {"スープ入り塩味ボンゴレ",500,651,3.0,41};
    menu m42 = {"カルボナーラ",500,740,2.5,42};
    menu m43 = {"イカの墨入りスパゲッティ",500,622,2.5,43};
    menu m44 = {"エビとブロッコリーのオーロラソース",500,665,2.6,44};
    menu m45 = {"ラムのラグーソース",600,453,1.9,45};
    menu m46 = {"ハンバーグステーキ",400,582,2.7,46};
    menu m47 = {"ディアボラ風ハンバーグ",500,653,3.1,47};
    menu m48 = {"イタリアンハンバーグ",500,702,2.9,48};
    menu m49 = {"チョリソーとハンバーグの盛り合わせ",550,700,3.6,49};
    menu m50 = {"ライス",150,303,0.0,50};
    menu m51 = {"若鶏のディアボラ風",500,730,2.8,51};
    menu m52 = {"柔らかチキンのチーズ焼き",500,763,2.8,52};
    menu m53 = {"リブステーキ",1000,548,2.8,53};
    menu m54 = {"コーヒーゼリー＆イタリアンジェラート",350,165,0.1,54};
    menu m55 = {"ジェラート＆シナモンプチフォッカ",450,367,0.9,55};
    menu m56 = {"プリントティラミスの盛り合わせ",500,445,0.2,56};
    menu m57 = {"ティラミスクラシコ",300,229,0.1,57};
    menu m58 = {"チョコレートケーキ",300,166,0.1,58};
    menu m59 = {"フレンチトースト",400,299,0.5,59};
    menu m60 = {"すっきりレモンのシャーベット",200,127,0.0,60};
    menu m61 = {"シチリア産ピスタチオのジェラート",350,145,0.1,61};
    menu m62 = {"トリフアイスクリーム",350,164,0.1,62};
    

    struct menu* data[] = {&m0,&m1,&m2,&m3,&m4,&m5,&m6,&m7,&m8,&m9,&m10,&m11,&m12,&m13,&m14,&m15,&m16,&m17,&m18,&m19,&m20,&m21,&m22,&m23,&m24,&m25,&m26,&m27,&m28,&m29,&m30,&m31,&m32,&m33,&m34,&m35,&m36,&m37,&m38,&m39,&m40,&m41,&m42,&m43,&m44,&m45,&m46,&m47,&m48,&m49,&m50,&m51,&m52,&m53,&m54,&m55,&m56,&m57,&m58,&m59,&m60,&m61};
    int len = sizeof(data) / sizeof(data[0]);

    srand(time(NULL)); // 乱数の種を生成


    //メニュー選びに対して、重複を防ぐ配列の用意
    int menu_cnt[62];
    for(int i=0;i<len;i++) menu_cnt[i] = 0; 

    int select_count = 0;
    bool hantei = false;

    int Answer_number_1;
    int Answer_number_2;
    int Answer_number_3;

    //この変数が,3品でいくらにするかの変数.
    int goal_value = 1000;
    int remaining_amount = 0;

    while(!hantei){

    int index1 = rand() % len;
    menu_cnt[index1]++;

    //printf("一品目:%d:%d",index1,data[index1]->menu_number);

    //メニュー名を引っ張ると面倒なので,メニューのキーナンバーを保持する.
    Answer_number_1 = data[index1]->menu_number;
    int Answer_value_1 = data[index1]->value;

    //二つ目の商品をダブりなく選ぶ.
    int index2;
    bool duplicate = true;

    while(duplicate){
    index2 = rand() % len;
    menu_cnt[index2]++;
    if(menu_cnt[index2] == 2) menu_cnt[index2]--;
    else duplicate = false;
    }

    //メニュー名を引っ張ると面倒なので,メニューのキーナンバーを保持する.
    Answer_number_2 = data[index2]->menu_number;
    int Answer_value_2 = data[index2]->value;

    //printf("二品目:%d:%d",index2,data[index2]->menu_number);

    //printf("value:%d,%d\n",Answer_number_1,Answer_value_1);
    //printf("value:%d,%d\n",Answer_number_2,Answer_value_2);

    bool select_passed = false;

    remaining_amount = goal_value - (Answer_value_1 + Answer_value_2);

    //ここの条件を商品を追加するたびに変える
    if(100 <= remaining_amount && remaining_amount <= 400) select_passed = true;
    else continue;

    int koho_number[63];

    for(int i=0;i<len;i++){
        if(menu_cnt[i] == 0 && remaining_amount == data[i]->value){
            //printf("%s:%d\n",data[i]->name,data[i]->value);
            koho_number[i] =  data[i]->menu_number;
        }
        else{
            koho_number[i] = 0;
        }
    }

    int restart_count = 0 ;
    for(int i=0;i<len;i++){
        if(koho_number[i] == 0) restart_count++; 
    }

    //候補が無い場合は,やり直し.
    if(restart_count == len - 1) continue;

    //ここで時間を食ってたので書き換えた.
    int cnt = 0;
    for(int i=0;i<len;i++){
    if(koho_number[i] > 0) cnt++;
    }

    //cntは値を持つ配列の要素数
    int decided_array[cnt];
    int j = cnt - 1;

    for(int i=0;i<len;i++){
        if(koho_number[i] > 0){
            //printf("%d:::%d\n",i,koho_number[i]);
            decided_array[j] = koho_number[i];
            //printf("%d",decided_array[j]);
            j--;
        }
    }

    
    duplicate = true;
    int index3;

    while(duplicate){
    //srand(time(NULL));
    //cnt + 1と書いてバグってしまった.
    index3 = rand() % (cnt - 1);
    int final_koho_number = koho_number[index3];
    menu_cnt[final_koho_number]++;
    if(menu_cnt[final_koho_number] == 2) menu_cnt[final_koho_number]--;
    else duplicate = false;
    }
    
    index3 = decided_array[index3];
    //printf("%d",index3);
    Answer_number_3 = data[index3]->menu_number;
    //Answer_value_3 = data[index3]->value;

    //printf("三品目:%d:%d",index3,data[index3]->menu_number);

    hantei = true;
    }

    printf("%d円で3品を選びました!\n",goal_value);

    printf("1品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_1]->name,data[Answer_number_1]->value,data[Answer_number_1]->calorie,data[Answer_number_1]->salt_amount);
    printf("2品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_2]->name,data[Answer_number_2]->value,data[Answer_number_2]->calorie,data[Answer_number_2]->salt_amount);
    printf("3品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_3]->name,data[Answer_number_3]->value,data[Answer_number_3]->calorie,data[Answer_number_3]->salt_amount);
    end = clock();

    float time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("実行時間は,%f[s]でした.\n", time);

    return 0;

}

