#include"library.h"

static int current_num = 0;

bool service_find(string num) {   //输入书籍编号查找书籍是否存在
    for (int i = 0; i < book_sum; i++) {
        if (num == array_number[i]) { current_num = i; return true; }
        else if (num != array_name[i] && i < book_sum - 1) continue;
        else { return false; }
    }
}

void service_borrow(Reader &person) {  //借书服务
    cout << "欢迎来到借书服务" << endl;
    cout << "请输入编号" << endl;
    string num;
    cin >> num;
    if (service_find(num)) { 
        Book &temp = array_book[current_num];
        cout << "该书编号为" + num + "书籍名为" + array_name[current_num] << endl;
        cout << "当前馆内存有数量为 " <<temp.Book_quantity<< endl;
        temp.Book_quantity--;
        cout << "操作完成后，还剩余  " <<temp.Book_quantity << endl;
        person.Reader_Borrowed.push_back(num);
        person.Reader_NotReturn.push_back(num);
    }
    else { cout << "没找到该书籍！" << endl; }
}

void service_return(Reader &person) {  //还书服务
    cout << "欢迎来到还书服务" << endl;
    while (true) {
        int find_in_reader = 0; //0代表编号在未返还的书籍中不存在 1代表存在
        cout << "请输入要返还的书籍的编号" << endl;
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
                    cout << "返还成功" << endl;
                    cout << "操作完成后，还剩余  " << temp.Book_quantity << endl;
                    break;
                }
            }
            if (find == 1) { break; }
            else { cout << "读者的未归还的书籍中，未找到"; continue; }
        }
        else {
            cout << "未查询到该书籍！，是否选择重新输入 y/n" << endl;
            string choice;
            cin >> choice;
            if (choice == "y") { continue; }
            else { break; }
        }
    }
}


void service_update_reader(Reader &person) {  //读者信息更新，续约借书证
    while (true) {
        cout << "确定要延长时间吗，一次只能延长一个月  1.确定 2.退出" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") { break; }
        else if (choice == "2") { break; }
        else { cout << "输入错误，请重新选择" << endl; continue; }
    }
}

void service_update_book() {  // 书籍信息更新，对书籍的增加，删除以及已存在的书籍的信息的更改
    while (true) {
        cout << "请选择要进行的操作" << endl;
        cout << "1. 录入书籍  2.删除书籍  3.修改馆内书籍的信息  4.退出" << endl;
        string choice;
        cin >> choice;
        if (choice == "1") {
            cout << "请输入书籍的信息 name page author press position number" << endl;
            string input;
            cin.ignore(); //用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响。
            getline(cin,input);
            cout << "请输入数量" << endl;
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
                cout << "录入成功！"; continue;
            }
            else { cout << "输入信息有误" << endl; continue; }
        }

        else if (choice == "2") {
            while (true) {
                cout << "请输入书籍的编号 或者输入 ‘quit’ 退出" << endl;
                string number;
                cin >> number;
                if (number == "quit") { break; }
                else {
                    if (service_find(number)) {
                        cout << "该书编号为" + number << endl;
                        cout << "该书名为" + array_name[current_num] << endl;
                        while (true) {
                            cout << "确认要删除吗?  1.确认 2.返回" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") {
                                array_book->Book_quantity = 0;
                                cout << "已经成功删除" << endl; break;
                            }
                            else if (choice == "2") { break; }
                            else { cout << "输入有误，请重新输入" << endl; continue; }
                        }
                    }
                    else { cout << "未找到该书，请检查输入是否有误"; continue; }
                }
            }
        }

        else if (choice == "3") {
            while (true) {
                cout << "请输入要修改的书籍的编号, 或输入‘quit’退出" << endl;
                string number;
                cin >> number;
                if (number == "quit") { break; }
                else {
                    if (service_find(number)) {
                        cout << "该书的信息为" << endl;
                        array_book[current_num].show(); cout << endl;
                        while (true) {
                            cout << "请重新输入该书籍的信息 name page author press position number";
                            cout<<"或者 输入‘quit’退出"<< endl;
                            string input;
                            cin.ignore();
                            getline(cin, input);
                            if (input == "quit") { break; }
                            else {
                                cout << "请输入数量" << endl;
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
                                    cout << "修改成功！" << endl; break;
                                }
                                else { cout << "输入信息有误" << endl; continue; }
                            }
                        }
                    }
                    else {
                        while (true) {
                            cout << "编号不存在，是否选择重新输入？ 1.重新输入 2.退出" << endl;
                            string choice;
                            cin >> choice;
                            if (choice == "1") { continue; }
                            else if (choice == "2") { break; }
                            else { cout << "操作不存在，请重新输入" << endl; continue; }
                        }
                    }
                }
            }
        }
        else if (choice == "4") { break; }
        else {
            cout << "选择有误，请重新输入或者退出 y 重新输入 n 退出";
            string choice;
            cin >> choice;
            if (choice == "y") { continue; }
            else { break; }
        }
    }

}

