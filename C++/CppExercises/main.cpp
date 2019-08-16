//
//  main.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

/*
#include <iostream>
//#include "ListNode.hpp"
//#include "ListNodeUtilities.hpp"
//#include "TreeNode.hpp"
//#include "TreeNodeUtilities.hpp"
#include "MathUtilities.h"

int main(int argc, const char * argv[]) {
    
    std::string a = "11";
    std::string b = "1";
    std::cout << MathUtilities::addBinary(a,b);
}

*/
#include <iostream>
#include <vector>
#include <string>
#include "MathUtilities.h"
using namespace std;

//class Spell {
//private:
//    string scrollName;
//public:
//    Spell(): scrollName("") { }
//    Spell(string name): scrollName(name) { }
//    virtual ~Spell() { }
//    string revealScrollName() {
//        return scrollName;
//    }
//};
//
//class Fireball : public Spell {
//private: int power;
//public:
//    Fireball(int power): power(power) { }
//    void revealFirepower(){
//        cout << "Fireball: " << power << endl;
//    }
//};
//
//class Frostbite : public Spell {
//private: int power;
//public:
//    Frostbite(int power): power(power) { }
//    void revealFrostpower(){
//        cout << "Frostbite: " << power << endl;
//    }
//};
//
//class Thunderstorm : public Spell {
//private: int power;
//public:
//    Thunderstorm(int power): power(power) { }
//    void revealThunderpower(){
//        cout << "Thunderstorm: " << power << endl;
//    }
//};
//
//class Waterbolt : public Spell {
//private: int power;
//public:
//    Waterbolt(int power): power(power) { }
//    void revealWaterpower(){
//        cout << "Waterbolt: " << power << endl;
//    }
//};
//
//class SpellJournal {
//public:
//    static string journal;
//    static string read() {
//        return journal;
//    }
//};
//string SpellJournal::journal = "";
//
//void counterspell(Spell *spell) {
//
//    /* Enter your code here */
//    if(Fireball* fb = dynamic_cast<Fireball*>(spell) ){
//        fb->revealFirepower();
//    }
//    else if(Frostbite* f = dynamic_cast<Frostbite*>(spell) ){
//        f->revealFrostpower();
//    }
//    else if(Waterbolt* wb = dynamic_cast<Waterbolt*>(spell) ){
//        wb->revealWaterpower();
//    }
//    else if(Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)){
//        ts->revealThunderpower();
//    }
//    else{
//        //Longest Common Subsequence Algorithm
//        string s = spell->revealScrollName();
//        string sj = SpellJournal::read();
//        int arr[s.length()];
//        for(int q = 0; q < s.length(); ++q) arr[q] = 0;
//
//        int temp = 0, max = 0;
//        //loop over all letters in the generic spell
//        for(int i = 0; i < s.length(); ++i){
//            temp = 0;
//            //loop over all the letters in the spell journal
//            for(int j = 0; j < sj.length(); ++j){
//                if(s[i] == sj[j]){
//                    ++temp;
//                    if(arr[i] < temp) arr[i] = temp;
//                    i = j + 1;
//                }
//            }
//            if(temp > max) max = temp;
//        }
//        cout << " " << endl;
//    }
//
//}
//
//class Wizard {
//public:
//    Spell *cast() {
//        Spell *spell;
//        string s; cin >> s;
//        int power; cin >> power;
//        if(s == "fire") {
//            spell = new Fireball(power);
//        }
//        else if(s == "frost") {
//            spell = new Frostbite(power);
//        }
//        else if(s == "water") {
//            spell = new Waterbolt(power);
//        }
//        else if(s == "thunder") {
//            spell = new Thunderstorm(power);
//        }
//        else {
//            spell = new Spell(s);
//            cin >> SpellJournal::journal;
//        }
//        return spell;
//    }
//};

//int main() {
//    int T;
//    cin >> T;
//    Wizard Arawn;
//    while(T--) {
//        Spell *spell = Arawn.cast();
//        counterspell(spell);
//    }
//    return 0;
//}

#include "StringUtilities.hpp"
#include <iostream>

int main(){
    std::string s("1.1.1.1");
    
    std::cout << StringUtilities::defangIPaddr(s);
}
