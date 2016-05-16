#include <cstring>
#include <iostream>
#include <fstream>
#include "menu.h"

int file_start(const char name[],std::vector<abonent> &all)
{
    
    std::ifstream fin(name,std::ios::in|std::ios::binary); 	
    int i=0;
    if(!fin)
            return 0;

    while(1)
        {
            if(fin.eof()==1) break;
            all.push_back(abonent());
            take_all(fin,all[i]);
            i++;
        };
    fin.close();
    if(all[0].give_nomer()==0) all.pop_back();
    std::cout<<"Информация была считана\n";
    std::cout<<"На данный момент имеется "<<all.size()<< "единиц товара\n";
    return 1;
}

int file_end(const char name[],std::vector<abonent> &all)
{
    int i;
    std::ofstream fout(name, std::ios::out | std::ios::binary);
    if(all.size()>0)
                {
                give_all(fout,all[0]);
                for(i=1;i<all.size();i++)
                    {
                    fout<<"\n";
                    give_all(fout,all[i]);
                    }
                }
    fout.close();
    std::cout<<"Информация была сохранена в файле:"<<(char*)name<<"\n";
}
