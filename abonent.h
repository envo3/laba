#include <iostream>
#include <ctime>
class abonent
{
    //информация об абоненте
    long int nomer;
    float balans;
    char imya[20];
    char familia[20];
    char otchestvo[20];
    long int activnost;
    //Вспомогательные элементы для совершения звонка
    long int call_nomer;
    time_t call_start;
    int status;    
    public:
    //Методы для работы с абонентом
    abonent();
    int zapoln(long int nome,float balan,const char famili[],const char imy[],const char otchestv[],time_t activnos);
    int show();
    int change_balans(float men);
    float give_balans();
    bool change_status();
    //Методы для сравнения
    int srav_familia(const char famili[]);
    int srav_imya(const char imya[]);
    int srav_otchestvo(const char otchestvo[]);
    long int give_nomer();
    abonent &operator =(abonent &ob);
    //для совершения звонка
    int get_call_nomer(long int call_nome);
    long int give_call_nomer();
    int start_calling();
    int status_timer();
    time_t end_calling(); 
    int change_activnost(time_t change);
    //Для файла
    friend int take_all(std::istream &stream,abonent &ob);
    friend int give_all(std::ostream &stream,abonent &ob);
};