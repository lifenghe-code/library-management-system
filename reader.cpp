#include"reader.h"
#include"map.h"
Reader::Reader(string name, string number, string date):
    Reader_name(name), Reader_number(number), Reader_date(date) {
    cout << "成功注册！用户" << name << endl;
    array_R_number[reader_sum] = name;
    array_R_number[reader_sum] = number;
    array_reader[reader_sum] = *this;
    reader_sum++;
}

Reader& Reader::operator=( Reader& person)
{
    this->Reader_name = person.Reader_name;
    this->Reader_number = person.Reader_number;
    this->Reader_date = person.Reader_date;
    this->Reader_Borrowed = person.Reader_Borrowed;
    this->Reader_NotReturn = person.Reader_NotReturn;
    return *this;
}

string Reader::R_name() {
    return Reader_name;
}
string Reader::R_number() {
    return Reader_number;
}
string Reader::R_date() {
    return Reader_date;
}

void Reader::Borrowed()
{
    for (auto it = Reader_Borrowed.begin(); it != Reader_Borrowed.end(); it++){
        cout << *it << " ";
    }
}

void Reader::NotReturn()
{
    for (auto it = Reader_NotReturn.begin(); it != Reader_NotReturn.end(); it++) {
        cout << *it << " ";
    }
}

void Reader::show() {
    cout << "姓名：" << R_name() << "  读书证的编号：" << R_number() << "  读书证的有效期：" << R_date() << endl;

}
