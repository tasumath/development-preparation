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
    menu m19 = {"カリットポテト",250,389,2.1,19};
    menu m20= {"ポップコーンシュリンプ",300,215,1.4,20};
    menu m21 = {"煉獄のたまご",300,319,2.0,21};
    menu m22 = {"イタリア風もつ煮込み",350,202,0.8,22};
    menu m23 = {"エスカルゴのオーブン焼き",400,220,1.3,23};
    menu m24 = {"アロスティチーニ",400,224,0.6,24};
    menu m25= {"チョリソー",400,425,2.9,25};
    menu m26 = {"ムール貝のガーリック焼き",400,170,1.4,26};
    menu m27 = {"エビクリームグラタン",400,505,2.0,27};

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
    if(100 <= remaining_amount && remaining_amount <= 400) select_passed = true;
    else continue;

    int koho_number[27];

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
    index3 = rand() % (cnt+1);
    int final_koho_number = koho_number[index3];
    menu_cnt[final_koho_number]++;
    if(menu_cnt[final_koho_number] == 2) menu_cnt[final_koho_number]--;
    else duplicate = false;
    }
    
    index3 = decided_array[index3];
    //printf("%d",index3);
    Answer_number_3 = data[index3]->menu_number;
    //Answer_value_3 = data[index3]->value;

    hantei = true;
    }

    printf("%d円で3品を選びました!\n",goal_value);

    printf("1品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_1]->name,data[Answer_number_1]->value,data[Answer_number_1]->calorie,data[Answer_number_1]->salt_amount);
    printf("2品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_2]->name,data[Answer_number_2]->value,data[Answer_number_2]->calorie,data[Answer_number_2]->salt_amount);
    printf("3品目は%sです.値段は%d円,カロリーは%dkcal,塩分は%.1fgです.\n",data[Answer_number_3]->name,data[Answer_number_3]->value,data[Answer_number_3]->calorie,data[Answer_number_3]->salt_amount);
    end = clock();

    float time = (float)(end - start) / CLOCKS_PER_SEC;
    //printf("実行時間は,%f[s]でした.\n", time);

    return 0;

}

