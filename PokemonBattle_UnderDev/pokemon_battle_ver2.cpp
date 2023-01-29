#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<time.h>
using namespace std;

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

    //HP更新
    void hp_ref(int damage_reff){
        if(damage_reff <= 0) damage_reff = 1;

        hit_point = hit_point - damage_reff;
        
        if(hit_point <= 0){
            hit_point = 0;
        }
    }

    //能力値の変化
    void change_ability(string skill_name_ref){
      if(skill_name_ref == "つるぎのまい"){
        attack_value = attack_value*2;
        cout<<"ガブリアスの攻撃力がグーンと上がった"<<endl;
      }
    }
    
    //優先度の高い技の場合,一ターンだけ能力値を上げる.
    void speedup_1turn(){
        speed_value = speed_value + 1000;
    }

    //ターン終了時に元に戻す.
    void speeddown_1turn(){
        speed_value = speed_value - 1000;
   }
    
};

//ダメージ計算陽の関数
int damage_calculating(int skill_ref,int level_ref,int pokemon1_attack_ref,int pokemon2_defence_ref,int pokemon1_extra_a_ref,int pokemon2_extra_d_ref){
    //skill_p1_refが負の値の時は特殊攻撃になる.
    int damage_value = 0;
    if(skill_ref == -1) return damage_value = 0;

    if(skill_ref < 0){
        int extra_a_value = abs(skill_ref);
        damage_value = ( (level_ref * 2/5 + 2 ) * extra_a_value * pokemon1_extra_a_ref / pokemon2_extra_d_ref ) /50  + 2;
    }
    else{
        damage_value = ( (level_ref * 2/5 + 2 ) * skill_ref * pokemon1_attack_ref / pokemon2_defence_ref ) /50  + 2;
    }
    
    //乱数により,ダメージの最終決定を行う.
    srand((unsigned int)time(NULL));
    int damage_correction = rand() % 16;
    damage_value = damage_value - damage_correction;

    if(damage_value == 0) damage_value = 1; 
    return damage_value;
}

//優先度判定(バレットパンチしかない) 未完成なので改良する.
int priority_skill_possible(int p1,int p2,int turn_pri,string poke1_skill_n1,string poke1_skill_n2,string poke1_skill_n3,string poke1_skill_n4,string poke2_skill_n1,string poke2_skill_n2,string poke2_skill_n3,string poke2_skill_n4){
  int turn_decide = -1;
  if(p1 == 2) turn_decide = 0;
  /*/
  if(poke1_skill_n1 == "バレットパンチ" || poke1_skill_n2 == "バレットパンチ" || poke1_skill_n3 == "バレットパンチ" || poke1_skill_n4 == "バレットパンチ"){
     turn_decide = 0;
  }
  else if(poke2_skill_n1 == "バレットパンチ" || poke2_skill_n2 == "バレットパンチ" || poke2_skill_n3 == "バレットパンチ" || poke2_skill_n4 == "バレットパンチ"){
     turn_decide = 1;
  }
  /*/
  return turn_decide;
}



//素早さが同じの場合,先行をランダムに決める.
int priority_pokemon = 2;
int judge_count = 0;

int pokemon1_skill_number_selected;
int pokemon2_skill_number_selected;

int main(){

    bool hantei = true;
    pokemon_battle pokemon1("メタグロス",50,156,184,153,99,113,93,"アイアンヘッド",80,"バレットパンチ",40,"かわらわり",75,"じしん",100);
    pokemon_battle pokemon2("ガブリアス",50,183,191,99,89,105,154,"かえんほうしゃ",-90,"げきりん",120,"つるぎのまい",-1,"じしん",100);

    while(hantei){

        srand((unsigned int)time(NULL));

        cout<<endl;

        //選択肢によって,ダメージ計算を行う.
        //呼び出すときは,コンストラクタで定義した右辺の変数名.private変数で呼び出そうとするとバグる.

        int damage_cal = 0;

        bool action = false;
        while(!action){
        cout<<pokemon1.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon1.skill_n1()<<" 2:"<<pokemon1.skill_n2()<<" 3:"<<pokemon1.skill_n3()<<" 4:"<<pokemon1.skill_n4()<<endl;
        cout<<"技の番号で選ぶ →";
        cin>>pokemon1_skill_number_selected;
        
        if(pokemon1_skill_number_selected < 1 || 4 < pokemon1_skill_number_selected) cout<<"技の番号を1～4の間で選んでください"<<endl;
        else action = true;
        }

        cout<<endl;

        action = false;
        while(!action){
        cout<<pokemon2.name()<<"はどうする？  "<<"技の番号を選んでください"<<endl;
        cout<<"1:"<<pokemon2.skill_n1()<<" 2:"<<pokemon2.skill_n2()<<" 3:"<<pokemon2.skill_n3()<<" 4:"<<pokemon2.skill_n4()<<endl;
        cout<<"技の番号で選ぶ →";
        cin>>pokemon2_skill_number_selected;

        if(pokemon2_skill_number_selected < 1 || 4 < pokemon2_skill_number_selected) cout<<"技の番号を1～4の間で選んでください"<<endl;
        else action = true;
        }

        //同じ素早さのときは,ランダムで先行を決める.
        if(pokemon1.speed() == pokemon2.speed() && judge_count == 0){
            int turn_de = rand();
            priority_pokemon = turn_de % 2;
            judge_count ++;
        }
        
        //優先度の高い技を使用したとき
        int priority_hantei = -1;
        priority_hantei = priority_skill_possible(pokemon1_skill_number_selected,pokemon2_skill_number_selected,priority_hantei,pokemon1.skill_n1(),pokemon1.skill_n2(),pokemon1.skill_n3(),pokemon1.skill_n4(),pokemon2.skill_n1(),pokemon2.skill_n2(),pokemon2.skill_n3(),pokemon2.skill_n4());
        if(priority_hantei == 0) pokemon1.speedup_1turn();
        //else if(priority_hantei = 1) pokemon2.speedup_1turn();

        cout<<endl;
        
        if(pokemon1.speed() > pokemon2.speed()){
        
        cout<<"先行は"<<pokemon1.name()<<endl;

        damage_cal = 0;
        if(pokemon1_skill_number_selected == 1){

          damage_cal = damage_calculating(pokemon1.skill_p1(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
          
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n1());
        }
        if(pokemon1_skill_number_selected == 2){

          damage_cal = damage_calculating(pokemon1.skill_p2(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
          
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n2());
        }
        if(pokemon1_skill_number_selected == 3){

          damage_cal = damage_calculating(pokemon1.skill_p3(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
        
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n3());
        }
        if(pokemon1_skill_number_selected == 4){

          damage_cal = damage_calculating(pokemon1.skill_p4(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
        
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n4());
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

        if(damage_cal != 0) cout<<pokemon1.name()<<"の攻撃によって"<<pokemon2.name()<<"の残りHPは"<<pokemon2.hp()<<"になりました."<<endl;

        //////////////////////////////////////////////////////////////////////////////////////////////////////////後攻の攻撃になる

        damage_cal = 0;
        if(pokemon2_skill_number_selected == 1){

          damage_cal = damage_calculating(pokemon2.skill_p1(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n1());
        }
        if(pokemon2_skill_number_selected == 2){

          damage_cal = damage_calculating(pokemon2.skill_p2(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n2());
        }
        if(pokemon2_skill_number_selected == 3){

          damage_cal = damage_calculating(pokemon2.skill_p3(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n3());
        }
        if(pokemon2_skill_number_selected == 4){

          damage_cal = damage_calculating(pokemon2.skill_p4(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n4());
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

        if(damage_cal != 0) cout<<pokemon2.name()<<"の攻撃によって"<<pokemon1.name()<<"の残りHPは"<<pokemon1.hp()<<"になりました."<<endl;
        
        if(priority_hantei == 0) pokemon1.speeddown_1turn();
        else if(priority_hantei == 1) pokemon2.speeddown_1turn();

        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if(pokemon1.speed() < pokemon2.speed()){

        cout<<"先行は"<<pokemon2.name()<<endl;

        damage_cal = 0;
        if(pokemon2_skill_number_selected == 1){

          damage_cal = damage_calculating(pokemon2.skill_p1(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n1());
        }
        if(pokemon2_skill_number_selected == 2){

          damage_cal = damage_calculating(pokemon2.skill_p2(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n2());
        }
        if(pokemon2_skill_number_selected == 3){

          damage_cal = damage_calculating(pokemon2.skill_p3(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n3());
        }
        if(pokemon2_skill_number_selected == 4){

          damage_cal = damage_calculating(pokemon2.skill_p4(),pokemon2.lev(),pokemon2.attack(),pokemon1.defence(),pokemon2.extra_a(),pokemon1.extra_d());
          
          if(damage_cal == 0) pokemon2.change_ability(pokemon2.skill_n4());
        }

        //複数のクラスがある際に,pokemon2のHPだけ拾って,void関数でHPを更新するやり方が分からない.→解決した.private変数をclass内でいじる.
        pokemon1.hp_ref(damage_cal);

        //cout<<endl;

        if(pokemon1.hp() == 0 || pokemon2.hp() == 0){
            cout<<endl;
            cout<<pokemon1.name()<<"のHPが0になりました.戦闘を終了します."<<endl;
            if(pokemon1.hp() == 0) cout<<"勝者は"<<pokemon2.name()<<endl;
            else cout<<"勝者は"<<pokemon1.name()<<endl;
            break;
        }

        if(damage_cal != 0) cout<<pokemon2.name()<<"の攻撃によって"<<pokemon1.name()<<"の残りHPは"<<pokemon1.hp()<<"になりました."<<endl;

        //後攻の攻撃
        //cout<<endl;

        damage_cal = 0;
        if(pokemon1_skill_number_selected == 1){

          damage_cal = damage_calculating(pokemon1.skill_p1(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
          
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n1());
        }
        if(pokemon1_skill_number_selected == 2){

          damage_cal = damage_calculating(pokemon1.skill_p2(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
          
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n2());
        }
        if(pokemon1_skill_number_selected == 3){

          damage_cal = damage_calculating(pokemon1.skill_p3(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
        
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n3());
        }
        if(pokemon1_skill_number_selected == 4){

          damage_cal = damage_calculating(pokemon1.skill_p4(),pokemon1.lev(),pokemon1.attack(),pokemon2.defence(),pokemon1.extra_a(),pokemon2.extra_d());
        
          if(damage_cal == 0) pokemon1.change_ability(pokemon1.skill_n4());
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

        if(damage_cal != 0) cout<<pokemon1.name()<<"の攻撃によって"<<pokemon2.name()<<"の残りHPは"<<pokemon2.hp()<<"になりました."<<endl;

        //cout<<endl;

        if(priority_hantei == 0) pokemon1.speeddown_1turn();
        else if(priority_hantei == 1) pokemon2.speeddown_1turn();

        }
  }

  return 0;
}

//2023/01/06
//げきりん→混乱の流れがつくれていない.
//技タイプによるダメージ補正が出来ていない.
//持ち物がない