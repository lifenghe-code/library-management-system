#pragma once

#include<iostream>
using namespace std;
#include"reader.h"
class Book {
private:
    string Book_name = "abc";
    string Book_page = "1";
    string Book_author = "efg";
    string Book_press = "出版社";
    string Book_position = "位置";
    string Book_number = "123456";
   // int    Book_quantity = 1;   //外界可以对书籍的数量进行修改
public:
    int    Book_quantity = 1;   //外界可以对书籍的数量进行修改
    Book() {};    //默认构造函数
    Book(string name, string page, string author, string press, string position, string number, int quantity);
    //接口函数***************************************************//
    string B_name();
    string B_page();
    string B_author();
    string B_press();
    string B_position();
    string B_number();
    int B_quantity();
    void show();  //显示读者信息
    //*******************************************************//
    //重载运算符  “=”
    Book &operator = (const Book& a);
    //****声明友元函数***************************************//

    friend void service_update_book();      //将该函数声明为友元函数，方便在library.cpp中利用该函数对书籍的信息进行修改
    friend void service_borrow(Reader& person);
    friend void service_return(Reader& person);
};

