<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<time.h>
using namespace std;

int skill_number_selected;

class pokemon_battle{
private:
    string pokemon_name; //氏名
    int level;//レベル
    int hit_point; //体力
    int attack_value; //攻撃力
    int defence_value; //防御力
    int extra_attack_value;//特攻
    int extra_defence_value;//特防
    int speed_value;//素早さ

    //特殊攻撃ならマイナスの値で入れる?
    string skill_name1;//技名1
    int skill_power1;//技名1の威力
    string skill_name2;//技名2
    int skill_power2;//技名2の威力
    string skill_name3;//技名3
    int skill_power3;//技名3の威力
    string skill_name4;//技名4
    int skill_power4;//技名4の威力

    public: //コンストラクタ(初期化)
    pokemon_battle(string name,int lev,int hp,int attack,int defence,int extra_a,int extra_d,int speed,string skill_n1,int skill_p1,string skill_n2,int skill_p2,string skill_n3,int skill_p3,string skill_n4,int skill_p4){
        pokemon_name = name;
        level = lev;
        hit_point = hp;
        attack_value = attack;
        defence_value = defence;
        extra_attack_value = extra_a;
        extra_defence_value = extra_d;
        speed_value = speed;
        skill_name1 = skill_n1;
        skill_power1 = skill_p1;
        skill_name2 = skill_n2;
        skill_power2 = skill_p2;
        skill_name3 = skill_n3;
        skill_power3 = skill_p3;
        skill_name4 = skill_n4;
        skill_power4 = skill_p4;
    }

    //ポケモンの名前を返す.
    string name(){
        return pokemon_name;
    }

    //レベルを返す.
    int lev(){
        return level;
    }

    //HP更新
    void hp_ref(int damage_reff){
        if(damage_reff <= 0) damage_reff = 1;

        hit_point = hit_point - damage_reff;
        
        if(hit_point <= 0){
            hit_point = 0;
        }
    }

    //能力値を返す.
    int hp(){
        return hit_point;
    }
    int attack(){
        return attack_value;
    }
    int defence(){
        return defence_value;
    }
    int extra_a(){
        return extra_attack_value;
    }
    int extra_d(){
        return extra_defence_value;
    }
    int speed(){
        return speed_value;
    }

    //技の威力を返す.
    int skill_p1(){
        return skill_power1;
    }
    int skill_p2(){
        return skill_power2;
    }
    int skill_p3(){
        return skill_power3;
    }
    int skill_p4(){
        return skill_power4;
    }
    
    //技名を返す.
    string skill_n1(){
        return skill_name1;
    }
    string skill_n2(){
        return skill_name2;
    }
    string skill_n3(){
        return skill_name3;
    }
    string skill_n4(){
        return skill_name4;
    }
    
};



int main(){

    bool hantei = true;
    pokemon_battle pokemon1("キングドラ",50,200,80,75,120,80,90,"なみのり",-80,"りゅうのはどう",-90,"れいとうビーム",-85,"ハイドロポンプ",-110);
    pokemon_battle pokemon2("ルカリオ",50,160,120,75,110,70,90,"はどうだん",-80,"インファイト",100,"ばくれつパンチ",90,"はたく",10);

    while(hantei){

        srand((unsigned int)time(NULL));

        //選択肢によって,ダメージ計算を行う.
        //呼び出すときは,コンストラクタで定義した右辺の変数名.private変数で呼び出そうとするとバグる.
        
        //ダメージ計算をmain関数内でやりたくないが,pokemonの能力をclassより先に定義できないため,出来ない.

        int damage_cal = 0;
        int priority_turn = 2;

        if(pokemon1.speed() == pokemon2.speed()){
            int turn_de = rand();
            priority_turn = turn_de % 2;
        }

        if(pokemon1.speed() > pokemon2.speed() || priority_turn == 0){

        cout<<pokemon1.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon1.skill_n1()<<"2:"<<pokemon1.skill_n2()<<"3:"<<pokemon1.skill_n3()<<"4:"<<pokemon1.skill_n4()<<endl;
        cout<<"番号で選ぶ →";
        cin>>skill_number_selected;

        damage_cal = 0;
        if(skill_number_selected == 1){
            int attack_val = pokemon1.skill_p1();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 2){
            int attack_val = pokemon1.skill_p2();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 3){
            int attack_val = pokemon1.skill_p3();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 4){
            int attack_val = pokemon1.skill_p4();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon2.hp_ref(damage_cal);

        cout<<endl;

        if(pokemon1.hp() == 0 || pokemon2.hp() == 0){
            cout<<endl;
            cout<<pokemon2.name()<<"のHPが0になりました.戦闘を終了します."<<endl;
            if(pokemon2.hp() == 0) cout<<"勝者は"<<pokemon1.name()<<endl;
            else cout<<"勝者は"<<pokemon2.name()<<endl;
            break;
        }

        cout<<pokemon1.name()<<"の攻撃によって"<<pokemon2.name()<<"の残りHPは"<<pokemon2.hp()<<"になりました."<<endl;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////後攻の攻撃になる
        cout<<endl;

        cout<<pokemon2.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon2.skill_n1()<<"2:"<<pokemon2.skill_n2()<<"3:"<<pokemon2.skill_n3()<<"4:"<<pokemon2.skill_n4()<<endl;
        cout<<"番号で選ぶ →";
        cin>>skill_number_selected;

        damage_cal = 0;
        if(skill_number_selected == 1){
            int attack_val = pokemon2.skill_p1();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 2){
            int attack_val = pokemon2.skill_p2();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 3){
            int attack_val = pokemon2.skill_p3();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 4){
            int attack_val = pokemon2.skill_p4();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon1.hp_ref(damage_cal);

        if(pokemon1.hp() == 0 || pokemon2.hp() == 0){
            cout<<endl;
            cout<<pokemon1.name()<<"のHPが0になりました.戦闘を終了します."<<endl;
            if(pokemon1.hp() == 0) cout<<"勝者は"<<pokemon2.name()<<endl;
            else cout<<"勝者は"<<pokemon1.name()<<endl;
            break;
        }

        cout<<pokemon2.name()<<"の攻撃によって"<<pokemon1.name()<<"の残りHPは"<<pokemon1.hp()<<"になりました."<<endl;

        cout<<endl;

        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if(pokemon1.speed() < pokemon2.speed() || priority_turn == 1){

        cout<<pokemon2.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon2.skill_n1()<<"2:"<<pokemon2.skill_n2()<<"3:"<<pokemon2.skill_n3()<<"4:"<<pokemon2.skill_n4()<<endl;
        cout<<"番号で選ぶ →";
        cin>>skill_number_selected;

        damage_cal = 0;
        if(skill_number_selected == 1){
            int attack_val = pokemon2.skill_p1();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 2){
            int attack_val = pokemon2.skill_p2();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 3){
            int attack_val = pokemon2.skill_p3();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 4){
            int attack_val = pokemon2.skill_p4();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon2.lev() * 2/5 + 2 ) * extra_a_value * pokemon2.extra_a() / pokemon1.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon2.lev() * 2/5 + 2 ) * attack_val * pokemon2.attack() / pokemon1.defence() ) / 50 + 2); 
              }
        }

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon1.hp_ref(damage_cal);

        cout<<endl;

        if(pokemon1.hp() == 0 || pokemon2.hp() == 0){
            cout<<endl;
            cout<<pokemon1.name()<<"のHPが0になりました.戦闘を終了します."<<endl;
            if(pokemon1.hp() == 0) cout<<"勝者は"<<pokemon2.name()<<endl;
            else cout<<"勝者は"<<pokemon1.name()<<endl;
            break;
        }

        cout<<pokemon2.name()<<"の攻撃によって"<<pokemon1.name()<<"の残りHPは"<<pokemon1.hp()<<"になりました."<<endl;

        //後攻の攻撃
        cout<<endl;

        cout<<pokemon1.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon1.skill_n1()<<"2:"<<pokemon1.skill_n2()<<"3:"<<pokemon1.skill_n3()<<"4:"<<pokemon1.skill_n4()<<endl;;
        cout<<"使用する技を番号で選ぶ →";
        cin>>skill_number_selected;

        int damage_cal = 0;
        if(skill_number_selected == 1){
            int attack_val = pokemon1.skill_p1();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 2){
            int attack_val = pokemon1.skill_p2();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 3){
            int attack_val = pokemon1.skill_p3();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 4){
            int attack_val = pokemon1.skill_p4();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon2.hp_ref(damage_cal);

        if(pokemon1.hp() == 0 || pokemon2.hp() == 0){
            cout<<endl;
            cout<<pokemon2.name()<<"のHPが0になりました.戦闘を終了します."<<endl;
            if(pokemon2.hp() == 0) cout<<"勝者は"<<pokemon1.name()<<endl;
            else cout<<"勝者は"<<pokemon2.name()<<endl;
            break;
        }

        cout<<pokemon1.name()<<"の攻撃によって"<<pokemon2.name()<<"の残りHPは"<<pokemon2.hp()<<"になりました."<<endl;

        cout<<endl;

        }

        
    }

    return 0;

=======
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int skill_number_selected;

class pokemon_battle{
private:
    string pokemon_name; //氏名
    int level;//レベル
    int hit_point; //体力
    int attack_value; //攻撃力
    int defence_value; //防御力
    int extra_attack_value;//特攻
    int extra_defence_value;//特防
    int speed_value;//素早さ

    //特殊攻撃ならマイナスの値で入れる?
    string skill_name1;//技名1
    int skill_power1;//技名1の威力
    string skill_name2;//技名2
    int skill_power2;//技名2の威力
    string skill_name3;//技名3
    int skill_power3;//技名3の威力
    string skill_name4;//技名4
    int skill_power4;//技名4の威力

    public: //コンストラクタ(初期化)
    pokemon_battle(string name,int lev,int hp,int attack,int defence,int extra_a,int extra_d,int speed,string skill_n1,int skill_p1,string skill_n2,int skill_p2,string skill_n3,int skill_p3,string skill_n4,int skill_p4){
        pokemon_name = name;
        level = lev;
        hit_point = hp;
        attack_value = attack;
        defence_value = defence;
        extra_attack_value = extra_a;
        extra_defence_value = extra_d;
        speed_value = speed;
        skill_name1 = skill_n1;
        skill_power1 = skill_p1;
        skill_name2 = skill_n2;
        skill_power2 = skill_p2;
        skill_name3 = skill_n3;
        skill_power3 = skill_p3;
        skill_name4 = skill_n4;
        skill_power4 = skill_p4;
    }

    //ポケモンの名前を返す.
    string name(){
        return pokemon_name;
    }

    //レベルを返す.
    int lev(){
        return level;
    }

    //HP更新
    void hp_ref(int damage_reff){
        hit_point = hit_point - damage_reff;
    }

    //能力値を返す.
    int hp(){
        return hit_point;
    }
    int attack(){
        return attack_value;
    }
    int defence(){
        return defence_value;
    }
    int extra_a(){
        return extra_attack_value;
    }
    int extra_d(){
        return extra_defence_value;
    }
    int speed(){
        return speed_value;
    }

    //技の威力を返す.
    int skill_p1(){
        return skill_power1;
    }
    int skill_p2(){
        return skill_power2;
    }
    int skill_p3(){
        return skill_power3;
    }
    int skill_p4(){
        return skill_power4;
    }
    
    //技名を返す.
    string skill_n1(){
        return skill_name1;
    }
    string skill_n2(){
        return skill_name2;
    }
    string skill_n3(){
        return skill_name3;
    }
    string skill_n4(){
        return skill_name4;
    }
    
};



int main(){

    bool hantei = true;
    pokemon_battle pokemon1("キングドラ",50,200,80,75,120,80,70,"なみのり",-80,"りゅうのはどう",-90,"れいとうビーム",-85,"ハイドロポンプ",-110);
    pokemon_battle pokemon2("ルカリオ",50,160,120,75,110,70,90,"はどうだん",-80,"インファイト",100,"ばくれつパンチ",90,"はたく",10);

    while(hantei){
        
        cout<<pokemon1.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon1.skill_n1()<<"2:"<<pokemon1.skill_n2()<<"3:"<<pokemon1.skill_n3()<<"4:"<<pokemon1.skill_n4();
        cout<<"番号で選ぶ →";
        cin>>skill_number_selected;

        //選択肢によって,ダメージ計算を行う.
        //呼び出すときは,コンストラクタで定義した右辺の変数名.private変数で呼び出そうとするとバグる.

        cout<<pokemon2.hp()<<endl;

        int damage_cal = 0;
        if(skill_number_selected == 1){
            int attack_val = pokemon1.skill_p1();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = ( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) /50  + 2;
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 2){
            int attack_val = pokemon1.skill_p2();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 3){
            int attack_val = pokemon1.skill_p3();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }
        if(skill_number_selected == 4){
            int attack_val = pokemon1.skill_p4();
              if(attack_val < 0){
                int extra_a_value = abs(attack_val);
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * extra_a_value * pokemon1.extra_a() / pokemon2.extra_d() ) / 50 + 2);
              }
              else{
                damage_cal = (( (pokemon1.lev() * 2/5 + 2 ) * attack_val * pokemon1.attack() / pokemon2.defence() ) / 50 + 2); 
              }
        }

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon2.hp_ref(damage_cal);

        cout<<pokemon2.hp()<<endl;

    }
    
>>>>>>> adee3c821f77bb26e0478ba652a54ff11ac2a289
}