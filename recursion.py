def power(x, n):
    if n == 0:
        return 1
    if n < 0:
        return 1 / power(x, -n)
    
    half = power(x * x, n // 2)
    if n % 2 == 0:
        return half
    else:
        return x * half

def main():
    try:
        base = float(input("Введите основание: "))
        exponent = int(input("Введите показатель степени: "))
        
        result = power(base, exponent)
        
        print(f"{base} в степени {exponent} = {result}")
        
    except ValueError:
        print("Ошибка: введите корректные числовые значения")
    except RecursionError:
        print("Ошибка: слишком большое значение степени")

if __name__ == "__main__":
    main()
//Введите основание: 3
//Введите показате�ь степени: 6
//3.0 в степени 6 = 729.0
