#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;

void bubbleSort(int* arr, int size){  //метод сортировки пузырьком

    int tmp;
    for(int i = 0; i < size - 1; ++i){ // i - номер прохода
        for(int j = 0; j < size - 1; ++j){ // внутренний цикл прохода
            if (arr[j + 1] < arr[j]){
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    cout << "Array after bubbleSort: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // выводим элементы массива
    }
}

int compare(const void * x1, const void * x2) {  // функция сравнения элементов массива
    return (*(int *) x1 - *(int *) x2);  // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}


int main() {

    int arrayForSort [10] = {32,90,11,65,77,34,63,88,31,70,};
    cout << "\n";
    cout << "Array before sorting: \n";
    for (int i : arrayForSort) {
        cout << i << " "; // выводим элементы массива до сортировки
    }
    cout << "\n";

    bubbleSort(arrayForSort,10); //вызываем метод сортировки пузырьком

    cout << "\n";

    qsort(arrayForSort,10,sizeof(int),compare); //метод быстрой сортировки
    cout << "Array after quickSort: \n";
    for (int ix : arrayForSort)
        cout << ix << " ";

    cout << "\n";

/* //задание №1 из методички
    int mas[] = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
    int imin;
    int imax;
    int n = sizeof (mas)/sizeof (int );
    int i;
    imax=0;
    imax=0;
    for(i=0; i<n;i++){
        cout << mas[i] << " ";
    }
    cout << endl;

    for(int i=0; i<n-1;i++){
        imin = i;
        for(int j = i+1; j<n; j++){
            if(mas[j]<mas[imin]){
                imin = j;
            }
            int t = mas[i];
            mas[i] = mas[imin];
            mas[imin] = t;
        }

        for(i=0;i<n;i++){
            cout << mas[i] << " ";
        }
        cout << endl;
    }
*/


    int arr_size; //размер вводимого массива
    cout << "Enter the size of the array: ";
    cin >> arr_size;

    int *ary = new int[arr_size]; //создаём динамический массив

    cout << "Enter the value of the array element: \n";

    bool fail = false;  //заполнение массива
    for (int i = 0; i < arr_size; i++) {
        do {
            cout << "[" << i << "]" << ": ";
            cin >> ary[i];
            if (cin.fail()) {
                cout << "*** Invalid value entered. Re-enter." << endl;
                fail = true;
            }
            cin.clear();
            cin.ignore();
        } while (fail);
    }

    cout << "\n";

    cout << "Array content: \n";

    for (int i = 0; i < arr_size; i++) { //выводим содержимое вводимого массива
        cout << "[" << i << "] = " << ary[i] << " ";
    }
    int countEven = 0;  //счётчик количества чётных элементов во вводимом массиве
    int countOdd = 0;   //счётчик количества нечётных элементов во вводимом массиве

    for(int i = 0; i < arr_size; i++){  //считаем количество чётных и нечётных элементов в массиве
        if(ary[i] % 2 == 0){
            countEven++;
        }else if(ary[i] % 2 != 0){
            countOdd++;
        }
    }

    cout << "\n";

    cout << "Number of even elements: " << countEven << "\n"; //выводим количество чётных элементов в массиве
    cout << "Number of odd elements: " << countOdd << "\n"; //выводим количество нечётных элементов в массиве

    cout << "\n";

    int *arrayOdd = new int[countOdd]; //новый массив для записи нечётных элементов
    int *arrayEven = new int[countEven]; //новый массив для записи чётных элементов

    int k = 0, d = 0;

    for(int i = 0; i < arr_size; i++){  //сортируем элементы массива на чётные и нечётные и заносим их в соответствующие массивы

        if(ary[i] % 2 == 0) {
            arrayEven[k] = ary[i];
            k++;
        }
        if(ary[i] % 2 != 0) {
            arrayOdd[d] = ary[i];
            d++;
        }
    }

    sort(arrayEven,arrayEven+countEven); //метод сортировки по возрастанию

    struct {
        bool operator()(int a, int b) const{
            return a>b; //по убыванию
        }
    }cmp;

    sort(arrayOdd,arrayOdd+countOdd,cmp); //метод сортировки по убыванию

    cout << "New array of even elements: ";

    for (int i = 0; i < countEven; i++) {  //выводим заполненный массив чётных элементов
        cout << "[" << i << "] = " << arrayEven[i] << " ";
    }

    cout << "\n";

    cout << "New array of odd elements: ";

    for (int i = 0; i < countOdd; i++) {  //выводим заполненный массив нечётных элементов
        cout << "[" << i << "] = " << arrayOdd[i] << " ";
    }

    cout << "\n";

    int startIndex; //индекс начала (с какого индекса начинаем отбор элементов в массиве)
    int stopIndex;  //индекс конца (до какого индекса производим отбор элементов в массиве
    int countForNewArray = 8; //количество вводимых элементов массива с клавиатуры
    int *arrayNew = new int [countForNewArray]; //промежуточный массив, из которого элементы перезапишутся в два других


    int *arrayForInputNums = new int [countForNewArray]; //новый массив для заполнения числами с клавиатуры

    cout << "Enter the value of the array element: \n";

    bool failTwo = false;
    for (int i = 0; i < countForNewArray; i++) {  //заполняем массив числами с клавиатуры
        do {
            cout << "[" << i << "]" << ": ";
            cin >> arrayForInputNums[i];
            if (cin.fail()) {
                cout << "*** Invalid value entered. Re-enter." << endl;
                failTwo = true;
            }
            cin.clear();
            cin.ignore();
        } while (failTwo);
    }

    cout << "\n";

    cout << "Array content: \n";

    for (int i = 0; i < countForNewArray; i++) {  //выводим содержимое массива, введенного с клавиатуры
        cout << "[" << i << "] = " << arrayForInputNums[i] << " ";
    }

    cout << "\n";

    cout << "Enter start index: \n";
    cin >> startIndex;
    cout <<"Enter end index: \n";
    cin >> stopIndex;

    int arraySizeFinal = stopIndex-startIndex;  //длина диапазона элементов отбираемых из введённого массива, для формирования нового массива
    int q = 0;
    for(int i = startIndex; i <= stopIndex; ++i){  //берём элементы из диапазона, перезаписываем в промежуточный массив и выводим на экран
            arrayNew[q] = arrayForInputNums[i];
            cout << "[" << i << "] = " << arrayNew[q] << " ";
            q++;
    }

    cout << "\n";

    int *arrayForSortAscendingOrder = new int [arraySizeFinal]; //новый массив для перезаписи элементов из массива arrayNew, для сортировки по возрастанию
    int *arrayForSortDescendingOrder = new int [arraySizeFinal]; //новый массив для перезаписи элементов из массива arrayNew, для сортировки по убыванию

    int w = 0, r = 0;
    for(int i = 0; i < arraySizeFinal; i++){ //перезаписываем элементы
        arrayForSortAscendingOrder[w] = arrayNew[i];
        w++;
    }
    for(int i = 0; i < arraySizeFinal; i++){  //перезаписываем элементы
        arrayForSortDescendingOrder[r] = arrayNew[i];
        r++;
    }

    sort(arrayForSortAscendingOrder,arrayForSortAscendingOrder+arraySizeFinal); //сортировка по возрастанию

    cout << "Array after sorting in ascending order: \n";

    for (int i = 0; i < arraySizeFinal; i++) {  //выводим отсортированный массив
        cout << "[" << i << "] = " << arrayForSortAscendingOrder[i] << " ";
    }

    cout << "\n";

    sort(arrayForSortDescendingOrder,arrayForSortDescendingOrder+arraySizeFinal,cmp); //сортировка по убыванию

    cout << "Array after sorting in descending order: \n";

    for (int i = 0; i < arraySizeFinal; i++) { //выводим отсортированный массив
        cout << "[" << i << "] = " << arrayForSortDescendingOrder[i] << " ";
    }
}