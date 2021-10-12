#include"library.h"

static int current_num = 0;

bool service_find(string num) {   //�����鼮��Ų����鼮�Ƿ����
    for (int i = 0; i < book_sum; i++) {
        if (num == array_number[i]) { current_num = i; return true; }
        else if (num != array_name[i] && i < book_sum - 1) continue;
        else { return false; }
    }
}

void service_borrow(Reader &person) {  //�������
    cout << "��ӭ�����������" << endl;
    cout << "��������" << endl;
    string num;
    cin >> num;
    if (service_find(num)) { 
        Book &temp = array_book[current_num];
        cout << "������Ϊ" + num + "�鼮��Ϊ" + array_name[current_num] << endl;
        cout << "��ǰ���ڴ�������Ϊ " <<temp.Book_quantity<< endl;
        temp.Book_quantity--;
        cout << "������ɺ󣬻�ʣ��  " <<temp.Book_quantity << endl;
        person.Reader_Borrowed.push_back(num);
        person.Reader_NotReturn.push_back(num);
    }
    else { cout << "û�ҵ����鼮��" << endl; }
}

void service_return(Reader &person) {  //�������
    cout << "��ӭ�����������" << endl;
    while (true) {
        int find_in_reader = 0; //0��������δ�������鼮�в����� 1�������
        cout << "������Ҫ�������鼮�ı��" << endl;
        string num;
        cin >> num;
        if (service_find(num)) {
            int find = 0;
            for (auto it = person.Reader_NotReturn.begin(); it != person.Reader_NotReturn.end(); it++) {
                if (*it == num) {
                    find = 1;
                    Book& temp = array_book[current_num];
                    temp.Book_quantity++;
                    auto iter = person.Reader_NotReturn.erase(it);
                    cout << "�����ɹ�" << endl;
                    cout << "������ɺ󣬻�ʣ��  " << temp.Book_quantity << endl;
                    break;
                }
            }
            if (find == 1) { break; }
            else { cout << "���ߵ�δ�黹���鼮�У�δ�ҵ�"; continue; }
        }
        else {
            cout << "δ��ѯ�����鼮�����Ƿ�ѡ���������� y/n" << endl;
            string choice;
            cin >> choice;
            if (choice == "y") { continue; }
            else { break; }
        }
    }
}


void service_update_reader(Reader &person) {  //������Ϣ���£���Լ����֤
    while (true) {
        cout << "ȷ��Ҫ�ӳ�ʱ����һ��ֻ���ӳ�һ����  1.ȷ�� 2.�˳�" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") { break; }
        else if (choice == "2") { break; }
        else { cout << "�������������ѡ��" << endl; continue; }
    }
}

void service_update_book() {  // �鼮��Ϣ���£����鼮�����ӣ�ɾ���Լ��Ѵ��ڵ��鼮����Ϣ�ĸ���
    while (true) {
        cout << "��ѡ��Ҫ���еĲ���" << endl;
        cout << "1. ¼���鼮  2.ɾ���鼮  3.�޸Ĺ����鼮����Ϣ  4.�˳�" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") {
            cout << "�������鼮����Ϣ name page author press position number" << endl;
            string input;
            cin.ignore(); //��������Իس����������뻺���������ݣ�������һ���������һ�������Ӱ�졣
            getline(cin,input);
            cout << "����������" << endl;
            int quantity;
            cin >> quantity;
            vector<string>information;
            string temp = "";
            for (int i = 0; i < input.length(); i++) {
                if (input[i] != ' ' && i < input.length() - 1) { temp += input[i]; }
                else if(input[i] == ' '){ information.push_back(temp); temp.clear();}
                else if(i == input.length() - 1){ temp += input[i]; information.push_back(temp); temp.clear();}
            }
            if (information.size() == 6) {
                Book temp(information[0], information[1], information[2],
                    information[3], information[4], information[5], quantity);
                information.clear();
                cout << "¼��ɹ���"; continue;
            }
            else { cout << "������Ϣ����" << endl; continue; }
        }

        else if (choice == "2") {
            while (true) {
                cout << "�������鼮�ı�� �������� ��quit�� �˳�" << endl;
                string number;
                cin >> number;
                if (number == "quit") { break; }
                else {
                    if (service_find(number)) {
                        cout << "������Ϊ" + number << endl;
                        cout << "������Ϊ" + array_name[current_num] << endl;
                        while (true) {
                            cout << "ȷ��Ҫɾ����?  1.ȷ�� 2.����" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") {
                                array_book->Book_quantity = 0;
                                cout << "�Ѿ��ɹ�ɾ��" << endl; break;
                            }
                            else if (choice == "2") { break; }
                            else { cout << "������������������" << endl; continue; }
                        }
                    }
                    else { cout << "δ�ҵ����飬���������Ƿ�����"; continue; }
                }
            }
        }

        else if (choice == "3") {
            while (true) {
                cout << "������Ҫ�޸ĵ��鼮�ı��, �����롮quit���˳�" << endl;
                string number;
                cin >> number;
                if (number == "quit") { break; }
                else {
                    if (service_find(number)) {
                        cout << "�������ϢΪ" << endl;
                        array_book[current_num].show(); cout << endl;
                        while (true) {
                            cout << "������������鼮����Ϣ name page author press position number";
                            cout<<"���� ���롮quit���˳�"<< endl;
                            string input;
                            cin.ignore();
                            getline(cin, input);
                            if (input == "quit") { break; }
                            else {
                                cout << "����������" << endl;
                                int quantity;
                                cin >> quantity;
                                vector<string>information;
                                string temp = "";
                                for (int i = 0; i < input.length(); i++) {
                                    if (input[i] != ' ' && i < input.length() - 1) { temp += input[i]; }
                                    else if (input[i] == ' ') { information.push_back(temp); temp.clear(); }
                                    else if (i == input.length() - 1) { temp += input[i]; information.push_back(temp); temp.clear(); }
                                }
                                if (information.size() == 6) {
                                    array_book[current_num].Book_name     = information[0];
                                    array_book[current_num].Book_page     = information[1];
                                    array_book[current_num].Book_author   = information[2];
                                    array_book[current_num].Book_press    = information[3];
                                    array_book[current_num].Book_position = information[4];
                                    array_book[current_num].Book_number   = information[5];
                                    array_book[current_num].Book_quantity = quantity;
                                    cout << "�޸ĳɹ���" << endl; break;
                                }
                                else { cout << "������Ϣ����" << endl; continue; }
                            }
                        }
                    }
                    else {
                        while (true) {
                            cout << "��Ų����ڣ��Ƿ�ѡ���������룿 1.�������� 2.�˳�" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") { continue; }
                            else if (choice == "2") { break; }
                            else { cout << "���������ڣ�����������" << endl; continue; }
                        }
                    }
                }
            }
        }
        else if (choice == "4") { break; }
        else {
            cout << "ѡ��������������������˳� y �������� n �˳�";
            string choice;
            cin >> choice;
            if (choice == "y") { continue; }
            else { break; }
        }
    }

}

