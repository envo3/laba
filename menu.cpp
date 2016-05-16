#include "menu.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
int menu()
{
    char name[20];
    cout<<"Укажите имя файла:";
    cin>>name;
    cout<<"Происходит чтение файла"<<endl;
    vector<abonent> all;
    file_start(name,all);
    char act;
    while(1)
    {
    cout<<"\n    ~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~\n"; 
    cout<<"    ~ '1'(show)-просмотреть килентскуюю базу ~\n";
    cout<<"    ~ '2'(add)-добавить абонента             ~\n";
    cout<<"    ~ '3'-совершить звонок                   ~\n";
    cout<<"    ~ '4'-завершить звонок                   ~\n";
    cout<<"    ~ '5'-поиск                              ~\n";
    cout<<"    ~ '6'-пополнить баланс абонента          ~\n";
    cout<<"    ~ '8'(frost)-заморозить абонента         ~\n";
    cout<<"    ~ '9'(frost)-разаморозить абонента       ~\n";
    cout<<"    ~ '0'-завершить работу                   ~\n";
    cout<<"    ~~~~~~~~~~~~~~~~~~~end~~~~~~~~~~~~~~~~~~~~\n"; 
    cout<<"    act: ";
    cin>>act;
    cin.clear();
    if(act=='0') break;
    switch(act)
        {
        case '1':show_all(all);break;
        case '2':add_abonent(all);sort(all);break;
        case '3':start_call(all);break;
        case '4':end_call(all);break;
        case '5':find(all);break;
        case '6':popolnit_balans(all);break;
        case '8':frost_abonent(all);sort(all);break;
        case '9':hot_abonent(all);sort(all);break;
        default :break;
        }
    }
    cout<<"происходит запись в файл"<<endl;
    file_end(name,all);
}