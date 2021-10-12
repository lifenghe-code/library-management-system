//用C++编写一个简单的图书管理系统
//fenghe_li   @ cug_library
// 
// 2021/10/12 @ cug_library 
//经过一周左右的编写，虽然功能都能实现，但能明显看出，整个工程的框架不够简洁，各个模块的共性较差，移植性也较差。2021/10/12
#include <iostream>
#include"book.h"
#include"map.h"
#include"library.h"
#include"Reader.h"
using namespace std;
int main() {
    while (true) {
        cout << "欢迎来到图书管理系统，请选择您想要进行的服务类型" << endl;
        cout << "1. 图书服务  2. 读者服务 3. 退出" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") { service_update_book(); continue; }
        else if (choice == "2") {
            while (true) {
                cout << "欢迎来到读者服务，请选择您要进行的服务类型 1.读者注册 2.读者信息管理与更新 3.退出" << endl;
                string choice;
                cin >> choice;
                if (choice == "1") {
                    cout << "请输入要注册的读者的信息  姓名：name 编号：number 日期：date  " << endl;
                    string input;
                    cin.ignore();
                    getline(cin, input);
                    vector<string>information;
                    string temp = "";
                    for (int i = 0; i < input.length(); i++) {
                        if (input[i] != ' ' && i < input.length() - 1) { temp += input[i]; }
                        else if (input[i] == ' ') { information.push_back(temp); temp.clear(); }
                        else if (i == input.length() - 1) { temp += input[i]; information.push_back(temp); temp.clear(); }
                    }
                    if (information.size() == 3) {
                        Reader temp(information[0], information[1], information[2]);
                        information.clear();
                        continue;
                    }
                    else { cout << "输入信息有误" << endl; continue; }
                }
                else if (choice == "2") {
                    Reader temp;
                    int find = 0; //判断是否存在
                    cout << "请输入您的读者证编号" << endl;
                    string number;
                    cin >> number;
                    for (int i = 0; i <= reader_sum; i++) {
                        if (number == array_R_number[i]) { temp = array_reader[i]; find = 1; break;
                        }
                        else {}
                    }
                    if (find == 1) {
                        while (true) {
                            cout << "欢迎来到读者管理服务" << endl;
                            cout << "请选择您要进行的服务，1. 借书服务 2.还书服务 3.读者信息更新服务 4.退出" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") { service_borrow(temp); continue; }
                            else if (choice == "2") { service_return(temp); continue;}
                            else if (choice == "3") { service_update_reader(temp); continue;}
                            else if (choice == "4") { break; }
                            else { cout << "输入有误，请重新输入" << endl; continue; }
                        }
                    }
                    else { cout << "输入的编号有误" << endl; }
                }
                else if (choice == "3") { break; }
                else { cout << "输入有误，请重新输入" << endl; continue; }
            }
        }

        else if (choice == "3") { cout << "成功退出!" << endl; break; }
        else { cout << "选择有误，请重新输入" << endl; continue; }
        }
    return 0;
}