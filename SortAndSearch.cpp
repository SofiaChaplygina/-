// Сортировка выбором

#include <iostream>
using namespace std;

// Функция для обмена двух значений
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Основная функция сортировки выбором
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) { // Проход по каждому элементу
        int minIndex = i;              // Предположительно минимальный индекс

        // Поиск минимального значения в оставшейся части массива
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;          // Обновляем индекс минимума
            }
        }
        
        // Меняем найденный минимум с текущим элементом
        swap(arr[i], arr[minIndex]);
    }
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Тестовая программа
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Исходный массив:\n";
    printArray(arr, n);
    
    selectionSort(arr, n);   // Сортируем массив
    
    cout << "\nОтсортированный массив:\n";
    printArray(arr, n);
    
    return 0;
}




//Быстрая сортировка 

#include <iostream>
#include <vector>

using namespace std;

// Функция для обмена элементов местами
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива на две части
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1; // Индекс для меньших элементов
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Основная функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Разделяем массив на две части
        quickSort(arr, low, pi - 1); // Рекурсивно сортируем левую часть
        quickSort(arr, pi + 1, high); // Рекурсивно сортируем правую часть
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}




//Бинарный (двоичный, дихотомический) поиск

#include <iostream>
using namespace std;

// Функция бинарного поиска
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        // Нахождение середины текущего отрезка
        int mid = left + (right - left) / 2;
        
        // Проверяем середину
        if (arr[mid] == target) return mid;
        
        // Если середина больше цели, ищем слева
        else if (arr[mid] > target) right = mid - 1;
        
        // Если середина меньше цели, ищем справа
        else left = mid + 1;
    }
    
    // Элемент не найден
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if(result != -1) cout << "Элемент найден на позиции " << result << endl;
    else cout << "Элемент не найден." << endl;
    
    return 0;
}





// Интерполирующий поиск 

#include <iostream>
using namespace std;

// Функция интерполирующего поиска
int interpolationSearch(int arr[], int left, int right, int target) {
    while ((left <= right) && (target >= arr[left]) && (target <= arr[right])) {
        // Вычисляем вероятную позицию следующего сравнения
        int pos = left + (((double)(right-left)/(arr[right]-arr[left]))*(target-arr[left]));
        
        // Если найдено совпадение
        if (arr[pos] == target) return pos;
        
        // Если элемент ниже ожидаемого, двигаемся левее
        if (arr[pos] < target) left = pos + 1;
        
        // Если элемент выше ожидаемого, двигаемся правее
        else right = pos - 1;
    }
    
    return -1; // Элемент не найден
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 23;
    
    int result = interpolationSearch(arr, 0, size - 1, target);
    
    if(result != -1) cout << "Элемент найден на позиции " << result << endl;
    else cout << "Элемент не найден." << endl;
    
    return 0;
}
