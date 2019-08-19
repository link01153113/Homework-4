//
//  main.cpp
//  Homework4
//
//  Created by I-Lin Wu on 2019/8/18.
//  Copyright © 2019 I-Lin Wu. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <cctype>
#include "WordTree.h"
using namespace std;

int main() {
    WordTree k;
    
    k.add("Kim");
    k.add("Kanye");
    k.add("Kanye");
    k.add("Kanye");
    assert(k.distinctWords() == 2);
    assert(k.totalWords() == 4);
    cout << "First Test:" << endl;
    cout << k << endl;
    
    WordTree h;
    
    h.add("Apple");
    h.add("Neko");
    h.add("Inu");
    h.add("Larry");
    h.add("Larry");
    h.add("Neko");
    h.add("Inu");
    h.add("Lin");
    h.add("Jack");
    assert(h.distinctWords() == 6);
    assert(h.totalWords() == 9);
    cout << "Second Test:" << endl;
    cout << h << endl;
          
    
    WordTree w;
    
    w.add("Harry");
    w.add("Niall");
    w.add("Niall");
    w.add("Liam");
    w.add("Louis");
    w.add("Harry");
    w.add("Niall");
    w.add("Zayn");
    cout << "Third Test:" << endl;
    cout << w << endl;
    
    WordTree m(w);
    cout << "Fourth Test:" << endl;
    cout << m << endl;
    
    w = k;
    cout << "Fifth Test:" << endl;
    cout << w << endl;
}
