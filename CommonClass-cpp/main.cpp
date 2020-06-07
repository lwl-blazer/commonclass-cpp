//
//  main.cpp
//  CommonClass-cpp
//
//  Created by luowailin on 2020/3/12.
//  Copyright © 2020 luowailin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "AstarSearch.hpp"
#include <cstring>

using std::cout;
using std::endl;

struct inflatble{
    std::string name;
    float volume;
    double price;
};


void pointers_to_objects(){
    cout << __func__ << "\n";
    vector<int> v{1,2,3,4};
    vector<int> *point_to_v = &v;
    for (int a : v) {
        cout << a << "\n";
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << (*point_to_v)[i] << "\n";
    }
    cout << "The first element of v is: " << (*point_to_v)[0] << "\n";
}

void Addone(int *j){
    (*j)++;
}

void passint_pointers_to_function(){
    cout << __func__ << "\n";
    int i = 1;
    cout << "i=" << i << "\n";
    int *pi = &i;
    Addone(pi);
    cout << "i=" << i << "\n";
}

void instring1(){
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    //cin 面向单词  遇到空白(空格、制表符、换行符)就到结束
    /*
    cout << "Enter you name:\n";
    std::cin >> name;
    cout << "Enter you favorite dessert:\n";
    std::cin >> dessert;
    cout << "I have some delicious " << dessert << " for you" << name << std::endl;
     */
    //cin.getline() 面向行    通过换行符就结束  不包括换行符
   
    /*cout << "Enter you name:\n";
    std::cin.getline(name, ArSize);
    cout << "Enter you favorite dessert:\n";
    std::cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert << " for you" << name << std::endl;
    */
    
    //cin.get()  面向行   通过换行符结束  包括换行符
    cout << "Enter you name:\n";
    std::cin.get(name, ArSize).get();
    cout << "Enter you favorite dessert:\n";
    std::cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert << " for you" << name << std::endl;
    
}

void instring2(){
    char anmial[20] = "bear";
    const char *bird = "wren";
    char *ps;
    
    cout << anmial << " and ";
    cout << bird << "\n";
    
    
    cout << "Enter a kind of animal:";
    std::cin >> anmial;
    
    ps = anmial;
    cout << ps << "!\n";
    cout << "Before using strcpy():\n";
    
    cout << anmial << "at" << (int *)anmial << "\n";
    
    cout << ps << "at" << (int *)ps << endl;
    
    ps = new char[strlen(anmial) + 1];
    strcpy(ps, anmial);
    
    
    cout << "After using strcpy():\n";
    cout << anmial << "at" << (int *)anmial << endl;
    cout << ps << "at" << (int *)ps << endl;
    delete [] ps;
}

int main(int argc, const char * argv[]) {
    // insert code here...

//    instring1();
    instring2();
    
    
    inflatble in1 = {"name", 12, 32};
    std::cout << in1.name << std::endl;
    
    inflatble in2 = in1;
    in1.name = "name2";
    std::cout << in1.name << "  " << in2.name <<std::endl;

    in2.name = "name3";
    std::cout << in1.name << "  " << in2.name <<std::endl;

    
    
    
///    pointers_to_objects();
//    passint_pointers_to_function();
    /*
    AStartSearch star;
    vector<vector<State>> board  = star.ReadBoardFile("/Users/blazer/Documents/blazer/Code/commonclass-cpp/CommonClass-cpp/1.board");
    star.PrintBoard(board);

    
    int init[2]{0, 0};
    int goal[2]{4, 5};
    
    vector<vector<State>>path = star.Search(board, init, goal);
    star.PrintBoard(path);
    */
    
    /*
    Test test;
    test.example();
     */
        
    /*
    int a = 5;
    cout << "The int a equals:" << a << "\n";
    
    int b = test.MultiplyByTwo_passbyvalue(a);
    cout << "b:"<<b<<"\n";
    cout << "a:" <<a << "\n";
    
    int c = 5;
    cout << "c:" << c << "\n";
    int d = test.MultiplyByTwo_passreference(c);
    printf("%p--%p\n", &c, &d);
    cout << "c:" << c << "\n";
    
    int e = 5;
    cout << "e:" << e << "\n";
    int f = test.MultiplyByTwo_passpointer(&e);
    printf("%p--%p\n", &e, &f);
    cout << "e:" << e << "\n";
    */
    
    return 0;
}
