#pragma once

#include<iostream>
using namespace std;
#include"reader.h"
class Book {
private:
    string Book_name = "abc";
    string Book_page = "1";
    string Book_author = "efg";
    string Book_press = "������";
    string Book_position = "λ��";
    string Book_number = "123456";
   // int    Book_quantity = 1;   //�����Զ��鼮�����������޸�
public:
    int    Book_quantity = 1;   //�����Զ��鼮�����������޸�
    Book() {};    //Ĭ�Ϲ��캯��
    Book(string name, string page, string author, string press, string position, string number, int quantity);
    //�ӿں���***************************************************//
    string B_name();
    string B_page();
    string B_author();
    string B_press();
    string B_position();
    string B_number();
    int B_quantity();
    void show();  //��ʾ������Ϣ
    //*******************************************************//
    //���������  ��=��
    Book &operator = (const Book& a);
    //****������Ԫ����***************************************//

    friend void service_update_book();      //���ú�������Ϊ��Ԫ������������library.cpp�����øú������鼮����Ϣ�����޸�
    friend void service_borrow(Reader& person);
    friend void service_return(Reader& person);
};

