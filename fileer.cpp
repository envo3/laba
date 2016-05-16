#include "menu.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <cstring>
#include <iomanip>
int file_start(const char name[],std::vector<abonent> &all)
{
    std::fstream file((char*)name,std::ios::in|std::ios::binary);    
    if(!file) return 0;
    int i,j;
    int size=0;
    file.seekg(0,std::ios::end);
    size=file.tellg();
    for(i=0;i<size/sizeof(abonent);i++)
    all.push_back(abonent());
    for(i=0;i<all.size();i++)
        file.read((char*)&all[i],sizeof(all[i]));    
    return 1;
}

int file_end(const char name[],std::vector<abonent> &all)
{
    int i,j;
    int mas[96];
    std::ofstream fout((char*)name,std::ios::out|std::ios::binary);
    for(i=0;i<all.size();i++)
        {
        std::cout<<"size="<<sizeof(all[i])<<"\nstr=";
        for(j=0;j<sizeof(all[i]);j++)
            {
            std::cout.fill('[');
            std::cout<<((char*)&all[i])[j];
            }
//        for(j=0;j<sizeof(all[i]);j++)
//            {
//            
//            std::cout<<(((char*)&all[i])[j]);
//            mas[j]=((char*)&all[i])[j];
//            }
        std::cout<<"!!\n abo=\n";
        all[i].show();
//        std::cout<<"!!\n numera\n";
//        for(j=0;j<sizeof(all[i]);j++)
//            std::cout<<mas[j]<<"'";
        }
    fout.close();
    return 1;
}