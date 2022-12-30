#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

class game_battle{
private:
    string full_name; //氏名
    int hit_point; //体力
    int attack_power; //攻撃力
    int defence_power; //防御力
public: //コンストラクタ
    game_battle(string name,int hp,int attack,int defence){
        hit_point = hp;
        attack_power = attack;
        defence_power = defence;
    }
    //攻撃力を返す
    int attack(){
        return attack_power;
    }
    //残りの体力を調べる
    int hp(){
        return hit_point;
    }
    //残りの体力を算出する
    void after_attacked(int MAX_damage){
        hit_point = hit_point - (MAX_damage - defence_power);
    }
};

int main(){
    game_battle suzumu("スズム",1800,100,50);
    game_battle kemu("ケム",1600,120,40);

    int battle_times = 0;

    while(suzumu.hp() > 0 && kemu.hp() > 0){

    suzumu.after_attacked(kemu.attack());
    kemu.after_attacked(suzumu.attack());

    cout<<battle_times<<"回目の攻撃をお互いが行いました.それぞれの残りHPは以下です"<<endl;
    cout<<"スズムの残りのHP:"<<suzumu.hp()<<endl;
    cout<<"ケムの残りのHP:"<<kemu.hp()<<endl;

    battle_times++;
    cout<<endl;
    }

    if(suzumu.hp()==0 && kemu.hp()==0){
        cout<<"共倒れです."<<endl;
    }

    if(suzumu.hp() < 0){
        cout<<"ケムさんの勝ちです."<<endl;
    }
    else{
        cout<<"スズムさんの勝ちです"<<endl;
    }


}