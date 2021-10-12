#pragma once
#include<iostream>
#include<string>
#include"map.h"
#include<vector>
#include"Reader.h"
#include"book.h"
using namespace std;
bool service_find(string num);
void service_borrow(Reader &person);
void service_return(Reader &person);
void service_update_reader(Reader &person);
void service_update_book();  //图书更新服务

