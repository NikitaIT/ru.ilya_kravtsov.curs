#include <iostream>
#include "my_list.h"
#include "my_2list.h"
using namespace std;
int interpolatingSearch(int a[], int arraySize, int keyOfSearch)
{

    //объявляем необходимые локальные переменные
    //изначально устанавливаем нижний индекс на начало массива,
    //а верний на конец массива
    int low = 0;
    int high = arraySize - 1;
    int mid;

    //цикл интерполирующего поиска
    while (a[low] < keyOfSearch && a[high] >= keyOfSearch)
    {

        //интерполирующий поиск производит оценку новой области поиска
        //по расстоянию между ключом поиска и текущим значение элемента
        mid = low + ((keyOfSearch - a[low]) * (high - low)) / (a[high] - a[low]);

        //если значение в ячейке с индексом mid меньше, то смещаем нижнюю границу
        if (a[mid] < keyOfSearch)

            low = mid + 1;

        //в случае, если значение больше, то смещаем верхнюю границу
        else if (a[mid] > keyOfSearch)

            high = mid - 1;

        //если равны, то возвращаем индекс
        else

            return mid;

    }
    //если цикл while не вернул индекс искомого значения,
        //то проверяем не находится ли оно в ячейке массива с индексом low,
        //иначе возвращаем -1 (значение не найдено)
        if (a[low] == keyOfSearch)

            return low;

        else

            return -1;
}
int main()
{
    int co = 1;
    while(co!=0)
    {
        co = 1;
        cout<< endl<< "0-exet \n Lab nomber: ";
        cin >> co;
        if (co==1) {
            int N=0;
            forward_list<int> list_;
            cout<< endl<< "in: size = ";
            cin >> N;
            cout<< endl<< "in: int_val[" << N << "] = ";
            for(int i=0;i<N;i++)
            {
                int w;
                cin>>w;
                list_.push_back(w);
            }
            list_.print();
            int in = 0;
            while (in!=1) {
                cout << "1-end 2-add 3-pop" << endl;
                cin>>in;
                if(in==2) {
                    int w;
                    cin>>w;
                    list_.push_back(w);
                    list_.print();
                }
                if(in==3) {
                    list_.pop_front();
                    list_.print();
                }
            }
            if(in==1) continue;
            co=-1;
        }
        if (co==2) {
            int N=0;
            dlist<int> list_;
            cout<< endl<< "in: size = ";
            cin >> N;
            cout<< endl<< "in: int_val[" << N << "] = ";
            for(int i=0;i<N;i++)
            {
                int w;
                cin>>w;
                list_.push_back(w);
            }
            list_.console_log();
            int in = 0;
            while (in!=1) {
                cout << "1-end 2-add 3-del 4-print 5-printR" << endl;
                cin>>in;
                if(in==2) {
                    int w;
                    cin>>w;
                    list_.push_back(w);
                    list_.console_log();
                }
                if(in==3) {
                    cout << "Pos:" << endl;
                    int w;
                    cin>>w;
                    list_.del(w);
                    list_.console_log();
                }
                if(in==4) {
                    list_.console_log();
                }
                if(in==5) {
                    list_.console_log_r();
                }

            }
            if(in==1) continue;
            co=-1;
        }

        if (co==3) {
            int N=0;
            cout<< endl<< "in: size = ";
            cin >> N;
            int arr[N];
            cout<< endl<< "in: int_val[" << N << "] = ";
            for(int i=0;i<N;i++)
            {
                cin>>arr[i];
            }
            std::sort(arr,arr + N);
            int isearch;
            cout<< endl<< "in: search = ";
            cin >> isearch;
            cout<< endl<<"out: id = " <<interpolatingSearch(arr,N,isearch);
            co=-1;
        }
    }
    return 0;
}

