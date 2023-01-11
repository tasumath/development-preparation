#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct menu{
    char name[100];
    int value;
    int menu_number;
};

int main(){

    clock_t start,end;
    start = clock();

    menu m0 = {"小エビのサラダ",350,0};
    menu m1 = {"チキンのシーザーサラダ",350,1};
    menu m2 = {"ガーデンサラダ",350,2};
    menu m3 = {"コーンクリームスープ",150,3};
    menu m4 = {"白菜のクラムチャウダー",300,4};
    menu m5 = {"田舎風ミネストローネ",300,5};
    menu m6 = {"プチフォッカ",150,6};
    menu m7 = {"セットプチフォッカ",100,7};
    menu m8 = {"ほうれん草のくたくた",300,8};
    menu m9 = {"爽やかにんじんサラダ",200,9};
    menu m10 = {"ペコリーノ・ロマーノ",100,10};
    menu m11 = {"ビール",400,11};
    menu m12 = {"シナモンプチフォッカ",200,12};
    menu m13 = {"ミニフィセル",150,13};
    menu m14 = {"ガーリックトースト",150,14};
    menu m15 = {"ブロッコリーのくたくた",300,15};
    menu m16 = {"柔らか青豆とペコリーノチーズの温サラダ",200,16};
    menu m17 = {"バッファローモッツァレラ",300,17};
    menu m18 = {"辛味チキン",300,18};
    menu m19 = {"カリットポテト",250,19};
    menu m20= {"ポップコーンシュリンプ",300,20};
    menu m21 = {"煉獄のたまご",300,21};
    menu m22 = {"イタリア風もつ煮込み",350,22};
    menu m23 = {"エスカルゴのオーブン焼き",400,23};
    menu m24 = {"アロスティチーニ",400,24};
    menu m25= {"チョリソー",400,25};
    menu m26 = {"ムール貝のガーリック焼き",400,26};
    menu m27 = {"エビクリームグラタン",400,27};

    struct menu* data[] = {&m0,&m1,&m2,&m3,&m4,&m5,&m6,&m7,&m8,&m9,&m10,&m11,&m12,&m13,&m14,&m15,&m16,&m17,&m18,&m19,&m20,&m21,&m22,&m23,&m24,&m25,&m26,&m27};
    int len = sizeof(data) / sizeof(data[0]);

    srand(time(NULL)); // 乱数の種を生成


    //メニュー選びに対して、重複を防ぐ配列の用意
    int menu_cnt[28];
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

    //printf("value:%d,%d\n",Answer_number_1,Answer_value_1);
    //printf("value:%d,%d\n",Answer_number_2,Answer_value_2);

    bool select_passed = false;

    remaining_amount = goal_value - (Answer_value_1 + Answer_value_2);

    //ここの条件を商品を追加するたびに変える
    if(100 < remaining_amount && remaining_amount <= 400) select_passed = true;
    else continue;

    int koho_number[27];

    for(int i=0;i<len;i++){
        if(menu_cnt[i] == 0 && remaining_amount == data[i]->value){
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
            decided_array[j] = koho_number[i];
            j--;
        }
    }
    
    srand(time(NULL));
    int index3 = rand() % cnt;
    Answer_number_3 = data[index3]->menu_number;
    //Answer_value_3 = data[index3]->value;

    hantei = true;
    }

    printf("%d円で3品を選びました!\n",goal_value);

    printf("1品目は%sです.2品目は%sです.3品目は%sです.\n",data[Answer_number_1]->name,data[Answer_number_2]->name,data[Answer_number_3]->name);

    end = clock();

    float time = (float)(end - start) / CLOCKS_PER_SEC;
    //printf("実行時間は,%f[s]でした.\n", time);

    return 0;

}

