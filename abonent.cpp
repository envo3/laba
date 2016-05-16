#include "abonent.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
abonent::abonent()
{
    nomer=0;
    balans=0;
    activnost=0;
    call_nomer=0;
    call_start=0;
}

int abonent::zapoln(long int nome,float balan,const char famili[],const char imy[],const char otchestv[],time_t activnos)
{
    nomer=nome;
    balans=balan;
    strcpy(familia,famili);
    strcpy(imya,imy);
    strcpy(otchestvo,otchestv);
    activnost=activnos;
    call_nomer=0;
    call_start=0;
    return 0;
}

int abonent::show()
{
    std::cout<<setw(13)<<left<<nomer;
    std::cout<<setw(8)<<left<<balans;
    std::cout<<setw(20)<<left<<familia;
    std::cout<<setw(20)<<left<<imya;
    std::cout<<setw(20)<<left<<otchestvo;    
    std::cout<<setw(6)<<right<<activnost/3600;
    std::cout<<':'<<setw(2)<<right<<(activnost%3600)/60;
    std::cout<<':'<<setw(2)<<right<<activnost%60;
    if(status)std::cout<<"     hot";
         else std::cout<<"   frost";
    std::cout<<std::endl;
}

int abonent::srav_familia(const char famili[])
{
    return strcmp(familia,famili);
}

int abonent::srav_imya(const char imy[])
{
    return strcmp(imya,imy);
}

int abonent::srav_otchestvo(const char otchestv[])
{
    return strcmp(otchestvo,otchestvo);
}

long int abonent::give_nomer()
{
    return nomer;
}

int abonent::change_balans(float men)
{
    balans+=men;
    return 1;
}

bool abonent::change_status()
{
    if(status) status=false;
    else status=true;
    return status;
}

float abonent::give_balans()
{
    return balans;
}

int abonent::get_call_nomer(long int call_nome)
{
    call_nomer=call_nome;
    return 1;
}

long int abonent::give_call_nomer()
{
    return call_nomer;
}
int abonent::start_calling()
{
    call_start=time(NULL);
    return 1;
}
int abonent::status_timer()
{
    if(call_start) return 1;
    return 0;
}
time_t abonent::end_calling()
{
    time_t end;
    end=time(NULL);
    call_nomer=0;
    end-=call_start;
    call_start=0;
    return(end);
}

int abonent::change_activnost(time_t change)
{
    activnost+=change;
    return 1;
}

abonent& abonent::operator =(abonent &ob)
{
    nomer=ob.nomer;
    balans=ob.balans;
    strcpy(familia,ob.familia);
    strcpy(imya,ob.imya);
    strcpy(otchestvo,ob.otchestvo);
    activnost=ob.activnost;
    call_nomer=ob.call_nomer;
    call_start=ob.call_start;
    return *this;
}

int take_all(std::istream &stream,abonent &ob)
{
    char buf1[sizeof(long int)],buf2[sizeof(float)],buf3[sizeof(time_t)];
    char buf4[sizeof(long int)],buf5[sizeof(time_t)],buf6[sizeof(int)];
    stream>>(char*)&ob.familia;
    stream>>(char*)&ob.imya;
    stream>>(char*)&ob.otchestvo;
    stream>>(char*)&buf1;
    stream>>(char*)&buf2;
    stream>>(char*)&buf3;
    stream>>(char*)&buf4;
    stream>>(char*)&buf5;
    stream>>buf6;
    ob.nomer=atol(buf1);
    ob.balans=atof(buf2);
    ob.activnost=atol(buf3);
    ob.call_nomer=atol(buf4);
    ob.call_start=atol(buf5);
    ob.status=atoi(buf6);
}
int give_all(std::ostream &stream,abonent &ob)
{
    stream<<(char*)ob.familia<<"\n";
    stream<<(char*)ob.imya<<"\n";
    stream<<(char*)ob.otchestvo<<"\n";
    stream<<ob.nomer<<"\n";
    stream<<ob.balans<<"\n";
    stream<<ob.activnost<<"\n";
    stream<<ob.call_nomer<<"\n";
    stream<<ob.call_start<<"\n";
    stream<<ob.status;
}