//��C++��дһ���򵥵�ͼ�����ϵͳ
//fenghe_li   @ cug_library
// 
// 2021/10/12 @ cug_library 
//����һ�����ҵı�д����Ȼ���ܶ���ʵ�֣��������Կ������������̵Ŀ�ܲ�����࣬����ģ��Ĺ��Խϲ��ֲ��Ҳ�ϲ2021/10/12
#include <iostream>
#include"book.h"
#include"map.h"
#include"library.h"
#include"Reader.h"
using namespace std;
int main() {
    while (true) {
        cout << "��ӭ����ͼ�����ϵͳ����ѡ������Ҫ���еķ�������" << endl;
        cout << "1. ͼ�����  2. ���߷��� 3. �˳�" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") { service_update_book(); continue; }
        else if (choice == "2") {
            while (true) {
                cout << "��ӭ�������߷�����ѡ����Ҫ���еķ������� 1.����ע�� 2.������Ϣ��������� 3.�˳�" << endl;
                string choice;
                cin >> choice;
                if (choice == "1") {
                    cout << "������Ҫע��Ķ��ߵ���Ϣ  ������name ��ţ�number ���ڣ�date  " << endl;
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
                    else { cout << "������Ϣ����" << endl; continue; }
                }
                else if (choice == "2") {
                    Reader temp;
                    int find = 0; //�ж��Ƿ����
                    cout << "���������Ķ���֤���" << endl;
                    string number;
                    cin >> number;
                    for (int i = 0; i <= reader_sum; i++) {
                        if (number == array_R_number[i]) { temp = array_reader[i]; find = 1; break;
                        }
                        else {}
                    }
                    if (find == 1) {
                        while (true) {
                            cout << "��ӭ�������߹������" << endl;
                            cout << "��ѡ����Ҫ���еķ���1. ������� 2.������� 3.������Ϣ���·��� 4.�˳�" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") { service_borrow(temp); continue; }
                            else if (choice == "2") { service_return(temp); continue;}
                            else if (choice == "3") { service_update_reader(temp); continue;}
                            else if (choice == "4") { break; }
                            else { cout << "������������������" << endl; continue; }
                        }
                    }
                    else { cout << "����ı������" << endl; }
                }
                else if (choice == "3") { break; }
                else { cout << "������������������" << endl; continue; }
            }
        }

        else if (choice == "3") { cout << "�ɹ��˳�!" << endl; break; }
        else { cout << "ѡ����������������" << endl; continue; }
        }
    return 0;
}