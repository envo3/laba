#include "menu.h"
#include <iostream>
#include <iomanip>
int start_call(std::vector<abonent> &all)
{
    std::cout<<"Абоненты способные участвовать в звонке:\n";
    std::cout<<"Индекс  Номер          Баланс    Фамилия             Имя                 Отчество            Время в сети\n";
    int i;
    for(i=0;i<all.size();i++)
    {
    if(all[i].give_call_nomer()) continue;
    std::cout<<'#'<<std::setw(7)<<std::left<<i;
    all[i].show();
    }
    int index_start=-1,index_get=-1;
    long int nomer_start,nomer_get;
    std::cout<<"ВВедите номер совершающий:"; 
    std::cin>>nomer_start;         
    std::cout<<"ВВедите номер принимающий:";          
    std::cin>>nomer_get;         
    for(i=0;i<all.size();i++)
    {
    if(all[i].give_call_nomer()) continue;
    if(nomer_start==all[i].give_nomer()) index_start=i;
    if(nomer_get==all[i].give_nomer()) index_get=i;
    }
    if((index_start>-1)&&(index_get>-1)) 
        {
        all[index_start].get_call_nomer(nomer_get);
        all[index_start].start_calling();
        all[index_get].get_call_nomer(nomer_start);
        std::cout<<"Звонок совершён\n";
        }
    else std::cout<<"Вызов не возможен\n";
    
}
int end_call(std::vector<abonent> &all)
{
    std::cout<<"Абоненты способные участвовующие в звонке:\n";
    std::cout<<"Индекс  Номер          Баланс    Фамилия             Имя                 Отчество            Время в сети\n";
    int i;
    for(i=0;i<all.size();i++)
    {
    if(!all[i].give_call_nomer()) continue;
    if(all[i].status_timer()) std::cout<<'$'<<std::setw(7)<<std::left<<i;
    else std::cout<<'&'<<std::setw(7)<<std::left<<i;
    all[i].show(); 
    }
    int index=-1,index_two=-1,buf_int;
    long int nomer,nomer_two,buf_long;
    std::cout<<"ВВедите номер для прекращения звонка:"; 
    std::cin>>nomer;
    time_t timer;  
    float price;   
    for(i=0;i<all.size();i++)
    {
    if(!all[i].give_call_nomer()) continue;
    if(nomer==all[i].give_nomer()) index=i;
    }
    if(index>-1) 
        {
        nomer_two=all[index].give_call_nomer();
        for(i=0;i<all.size();i++)
        if(nomer_two==all[i].give_nomer()) index_two=i;
        
        if(all[index_two].status_timer())
            {
            buf_int=index;
            index=index_two;
            index_two=buf_int;
            buf_long=nomer;
            nomer=nomer_two;
            nomer_two=buf_long;
            }
        timer=all[index].end_calling();
        all[index_two].end_calling();
        all[index].change_activnost(timer);
        price=(timer/60+1)*(-0.90);
        all[index].change_balans(price);
        all[index_two].change_activnost(timer);
        std::cout<<"Звонок прекращен\n";
        std::cout<<"Продолжительность звонка  "<<timer/3600<<':'<<(timer%3600)/60<<':'<<timer/60<<"\n";
        std::cout<<"С абонента "<<nomer<<"  было списано "<<-price<<"\n";
        }
        
    else std::cout<<"Оперперация не возможна\n";
    return 1;
}