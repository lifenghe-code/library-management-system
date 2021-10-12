#pragma once
//读者类，包含读者的资料，姓名，读书证的编号，读书证的有效期，读者借阅过的图书和未归还的图书；
#include<iostream>
#include<vector>
using namespace std;
class Reader {
private:  
    string Reader_name = "姓名";
    string Reader_number = "编号";
    string Reader_date = "2001-1-1";
    vector<string>Reader_Borrowed;
    vector<string>Reader_NotReturn;
public:
    Reader() {}
    Reader(string name, string number, string date);
    Reader & operator = ( Reader &person);
    
    //接口函数***************************************************//
    string R_name();
    string R_number();
    string R_date();
    void Borrowed();
    void NotReturn();
    //*******************************************************//
 
    void show();  //显示读者信息
    friend void service_borrow(Reader& person);
    friend void service_return(Reader& person);
    friend void service_update_reader(Reader& person);
};
