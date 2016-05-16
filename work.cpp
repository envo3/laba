#include "menu.h"
#include <iostream>
#include <iomanip>
#include <ctime>

int add_abonent(std::vector<abonent> &all)
{
    long int nome;
    float balan;
    char famili[20],imy[20],otchestv[20];
    std::cout<<"номер:";
    std::cin>>nome;              
    std::cout<<"стартовый баланс:";
    std::cin>>balan; 
    std::cout<<"Фамилия:";
    std::cin>>famili;
    std::cout<<"Имя:";
    std::cin>>imy;
    std::cout<<"Отчество:";
    std::cin>>otchestv;
    time_t a=0;
    all.push_back(abonent());
    all[all.size()-1].zapoln(nome,balan,famili,imy,otchestv,a);
    return 1;
}

int show_all(std::vector<abonent> &all)
{
    std::cout<<"Индекс  Номер        Баланс  Фамилия             Имя                 Отчество            Время в сети\n";
    std::cout<<"_________________________________________________________________________________________________________\n";
    int i;
    for(i=0;i<all.size();i++)
    {
    if(all[i].give_call_nomer())
            {
            if(all[i].status_timer()) std::cout<<'$'<<std::setw(7)<<std::left<<i;
            else std::cout<<'&'<<std::setw(7)<<std::left<<i;
            }
    else std::cout<<'#'<<std::setw(7)<<std::left<<i;
    all[i].show();
    std::cout<<"_________________________________________________________________________________________________________\n";
    }
}

int find(std::vector<abonent> &all)
{
    long int nome;
    char famili[20],imy[20],otchestv[20];
    std::cout<<"номер:";
    std::cin>>nome;              
    std::cout<<"Фамилия:";
    std::cin>>famili;
    std::cout<<"Имя:";
    std::cin>>imy;
    std::cout<<"Отчество:";
    std::cin>>otchestv;
    int i;
    for(i=0;i<all.size();i++)
    if((nome=all[i].give_nomer())||(all[i].srav_familia(famili))||(all[i].srav_imya(imy))||(all[i].srav_otchestvo(otchestv)))
    all[i].show();
}

int popolnit_balans(std::vector<abonent> &all)
{
    long int nome;
    std::cout<<"номер:";
    std::cin>>nome;             
    int i,index=-1; 
    for(i=0;i<all.size();i++)
    if(nome=all[i].give_nomer()) index=i;
    if(index>-1)
    {
    std::cout<<"Номер        Баланс  Фамилия             Имя                 Отчество            Время в сети\n";
    all[i].show();
    float balan;
    std::cout<<"изменение баланса:";
    std::cin>>balan; 
    all[index].change_balans(balan);
    }
    else std::cout<<"Абонент не найден\n";
}

int sort(std::vector<abonent> &all)
{
    abonent temp;              
    int i,j;
    for(i=all.size()-1;i>0;i--)    
    if ( all[i].give_nomer()<all[i-1].give_nomer())
        {     
        temp=all[j];           
        all[j]=all [j+1];    
        all[j+1]=temp;
        }
    return 1;
}

int frost_abonent(std::vector<abonent> &all)
{
    abonent temp;
    long int nome;
    std::cout<<"номер:";
    std::cin>>nome;             
    int i,index;
    for(i=0;i<all.size();i++)
    if(nome==all[i].give_nomer()) index=i;
    if(index>-1)
    {
    if(all[index].change_status())
        {
        all[index].change_status();    
        std::cout<<"abonent"<<all[index].give_nomer()<<" is frost"<<std::endl;
        }
    else
        {
        all[index].change_status();    
        std::cout<<"abonent"<<all[index].give_nomer()<<" yet is frost"<<std::endl;
        }
    }
    else std::cout<<"error";
}

int hot_abonent(std::vector<abonent> &all)
{
    abonent temp;
    long int nome;
    std::cout<<"номер:";
    std::cin>>nome;             
    int i,index;
    for(i=0;i<all.size();i++)
    if(nome==all[i].give_nomer()) index=i;
    if(index>-1)
    {
    if(!all[index].change_status())
        {
        all[index].change_status();    
        std::cout<<"abonent"<<all[index].give_nomer()<<" is hot"<<std::endl;
        }
    else
        {
        all[index].change_status();    
        std::cout<<"abonent"<<all[index].give_nomer()<<" yet is hot"<<std::endl;
        }

    }
    else std::cout<<"error";
}