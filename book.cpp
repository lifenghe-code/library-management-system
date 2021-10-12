#include"book.h"
#include"map.h"

Book::Book(string name, string page, string author, string press, string position, string number, int quantity) :Book_name(name),
Book_page(page), Book_author(author), Book_press(press), Book_position(position), Book_number(number), Book_quantity(quantity)
{
    cout << "成功录入!书籍"<< name << endl;
    array_number[book_sum] = number; array_name[book_sum] = name;
    array_book[book_sum] = *this;
    book_sum++;
}

    Book& Book:: operator = (const Book& a) {
    this->Book_name = a.Book_name;
    this->Book_page = a.Book_page;
    this->Book_author = a.Book_author;
    this->Book_press = a.Book_press;
    this->Book_position = a.Book_position;
    this->Book_number = a.Book_number;
    this->Book_quantity = a.Book_quantity;
    return *this;
}

    string Book::B_name() {
        return Book_name;
    }
    string Book::B_page() {
        return Book_page;
    }
    string Book::B_author() {
        return Book_author;
    }
    string Book::B_press() {
        return Book_press;
    }
    string Book::B_position() {
        return Book_position;
    }
    string Book::B_number() {
        return Book_number;
    }
    int Book::B_quantity() {
        return Book_quantity;
    }


void Book::show() {
    cout << "书籍:" << B_name() << "页数:" << B_page() << "作者:" << B_author();
    cout << "出版社:" << B_press() << "位置:" << B_position() << "编号" << B_number();
}
