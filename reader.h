#pragma once
//�����࣬�������ߵ����ϣ�����������֤�ı�ţ�����֤����Ч�ڣ����߽��Ĺ���ͼ���δ�黹��ͼ�飻
#include<iostream>
#include<vector>
using namespace std;
class Reader {
private:  
    string Reader_name = "����";
    string Reader_number = "���";
    string Reader_date = "2001-1-1";
    vector<string>Reader_Borrowed;
    vector<string>Reader_NotReturn;
public:
    Reader() {}
    Reader(string name, string number, string date);
    Reader & operator = ( Reader &person);
    
    //�ӿں���***************************************************//
    string R_name();
    string R_number();
    string R_date();
    void Borrowed();
    void NotReturn();
    //*******************************************************//
 
    void show();  //��ʾ������Ϣ
    friend void service_borrow(Reader& person);
    friend void service_return(Reader& person);
    friend void service_update_reader(Reader& person);
};
