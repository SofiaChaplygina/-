// Сортировка обменом (пузырьком) (Bubble Sort) 

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Флаг для отслеживания необходимости продолжения сортировки
        swapped = False
        for j in range(0, n-i-1):
            # Если текущий элемент больше следующего, меняем их местами
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        # Если за проход не было выполнено ни одной перестановки, список уже отсортирован
        if not swapped:
            break
    return arr

# Пример использования
arr = [64, 34, 25, 12, 22, 11, 90]
sorted_arr = bubble_sort(arr)
print("Отсортированный массив:", sorted_arr)




// Сортировка вставками (Insertion Sort) 

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Пример использования
arr = [12, 11, 13, 5, 6]
sorted_arr = insertion_sort(arr)
print("Отсортированный массив:", sorted_arr)




// Пирамидальная сортировка 
 def heapify(arr, n, i):
    largest = i  # Инициализируем наибольший элемент как корень
    left = 2 * i + 1  # Левый дочерний элемент
    right = 2 * i + 2  # Правый дочерний элемент

    # Если левый дочерний элемент больше корня
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Если правый дочерний элемент больше, чем наибольший элемент на данный момент
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Если наибольший элемент не корень
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Меняем местами
        heapify(arr, n, largest)  # Рекурсивно вызываем heapify для поддерева

def heapsort(arr):
    n = len(arr)

    # Построение max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Извлечение элементов из кучи один за другим
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Меняем местами корень (максимальный элемент) с последним элементом
        heapify(arr, i, 0)  # Вызываем heapify на уменьшенной куче

# Пример использования
arr = [12, 11, 13, 5, 6, 7]
heapsort(arr)
print("Отсортированный массив:", arr)





// Последовательный поиск:

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Возвращаем индекс найденного элемента
    return -1  # Если элемент не найден

# Пример использования
arr = [4, 2, 7, 1, 9]
target = 7
result = linear_search(arr, target)

if result != -1:
    print(f"Элемент {target} найден на позиции {result}")
else:
    print(f"Элемент {target} не найден в списке")





// Поиск по Фибоначчи 

def fibonacci_search(arr, x):
    # Создаем первые два числа Фибоначчи
    fib_prev = 0  # F(k-2)
    fib_curr = 1  # F(k-1)
    fib_next = fib_prev + fib_curr  # F(k)

    # Определяем длину массива
    length = len(arr)

    # Ищем ближайшее число Фибоначчи большее длины массива
    while fib_next < length:
        fib_prev = fib_curr
        fib_curr = fib_next
        fib_next = fib_prev + fib_curr

    # Перемещаем границы поиска
    offset = -1

    # Пока ещё можем двигаться вперед
    while fib_next > 1:
        # Выбираем наименьшую границу возможного перехода
        i = min(offset + fib_prev, length - 1)

        # Если найден нужный элемент
        if arr[i] == x:
            return i

        # Если элемент больше нужного, уменьшаем масштаб поиска
        elif arr[i] < x:
            fib_next = fib_curr
            fib_curr = fib_prev
            fib_prev = fib_next - fib_curr
            offset = i

        # Если элемент меньше нужного, продолжаем поиск
        else:
            fib_next = fib_prev
            fib_curr -= fib_prev
            fib_prev = fib_next - fib_curr

    # Последний элемент перед выходом
    if fib_curr and arr[offset + 1] == x:
        return offset + 1

    # Элемент не найден
    return -1


# Тестирование
arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
x = 85
result = fibonacci_search(arr, x)
if result != -1:
    print("Элемент найден на позиции:", result)
else:
    print("Элемент не найден.")
