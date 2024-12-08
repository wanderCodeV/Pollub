import re

# Функция для извлечения выражений mul(x, y)
def extract_mul_expressions(input_string):
    # Регулярное выражение для нахождения mul(x, y), где x и y — цифры
    pattern = r'mul\((\d{1,3}),(\d{1,3})\)'
    return re.findall(pattern, input_string)

# Функция для обработки инструкций do() и don't() и вычисления результата
def calculate_result(input_string):
    # Инициализация переменных
    result = 0
    allow_mul = True  # Изначально mul отключен
    i = 0
    length = len(input_string)

    while i < length:
        # Включение mul с do()
        if input_string[i:i+4] == 'do()':
            allow_mul = True
            i += 4  # Перемещаемся на 4 символа после do()
        # Отключение mul с don't()
        elif input_string[i:i+7] == "don't()":
            allow_mul = False
            i += 7  # Перемещаемся на 7 символов после don't()
        # Обработка mul(x, y)
        elif input_string[i:i+3] == 'mul':
            # Ищем выражение mul(x, y)
            match = re.match(r'mul\((\d{1,3}),(\d{1,3})\)', input_string[i:])
            if match:
                x, y = map(int, match.groups())
                if allow_mul:
                    result += x * y  # Выполняем умножение, если разрешено
                # Перемещаем индекс на длину найденного выражения mul(x, y)
                i += len(match.group(0))
            else:
                i += 1  # Если не нашли, просто двигаем индекс
        else:
            i += 1  # Если не найдено ни одно из условий, двигаемся по символу

    return result

# Чтение строки из файла 'input.txt'
with open('input.txt', 'r') as file:
    input_string = file.read()

# Вычисление результата
result = calculate_result(input_string)
print("Результат:", result)

