#include <bits/stdc++.h>
#include <regex>

using namespace std;

bool isDigit(const std::string &str) {
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

int extractNumber(const std::string &str, size_t &pos) {
    std::string num;
    while (pos < str.size() && std::isdigit(str[pos])) {
        num += str[pos];
        ++pos;
    }
    return !num.empty() && isDigit(num) ? std::stoi(num) : -1;
}

int calculateMulSum(const std::string &input) {
    size_t pos = 0;
    int totalSum = 0;

    while ((pos = input.find("mul(", pos)) != std::string::npos) {
        size_t start = pos + 4; // Skip "mul("
        size_t end = input.find(")", start);

        if (end == std::string::npos) {
            pos += 3; // Move past "mul" if no closing parenthesis
            continue;
        }

        // Extract x and y arguments
        size_t comma = input.find(",", start);
        if (comma == std::string::npos || comma > end) {
            pos += 3; // Move past "mul" if no valid comma
            continue;
        }

        size_t argPos = start;
        int x = extractNumber(input, argPos);
        if (x < 0 || x > 1000 || input[argPos] != ',') {
            pos += 3; // Skip invalid cases
            continue;
        }

        ++argPos; // Skip the comma
        int y = extractNumber(input, argPos);
        if (y < 0 || y > 1000 || argPos != end) {
            pos += 3; // Skip invalid cases
            continue;
        }

        // Add valid product to total
        totalSum += x * y;
        pos = end + 1; // Move past this "mul(x, y)"
    }

    return totalSum;
}

void first_part( vector <string>  input)
{
    int sum = 0;
   for(auto line:input)
   {
       sum += calculateMulSum(line);
   }
   cout << sum << "\n";
}int extractMulExpressions(const std::string &input_string, size_t &pos, bool &allow_mul) {
    // Ищем "mul(" и ")"
    size_t start = input_string.find("mul(", pos);
    if (start == std::string::npos) {
        return 0; // Не найдено "mul("
    }

    size_t end = input_string.find(")", start);
    if (end == std::string::npos) {
        return 0; // Не найдено закрывающей скобки
    }

    // Извлекаем подстроку внутри "mul(x, y)"
    std::string mul_expr = input_string.substr(start + 4, end - start - 4); // Извлекаем часть между "mul(" и ")"
    size_t comma_pos = mul_expr.find(",");
    if (comma_pos == std::string::npos) {
        return 0; // Если нет запятой, выражение неверное
    }

    // Извлекаем x и y значения
    int x = std::stoi(mul_expr.substr(0, comma_pos));
    int y = std::stoi(mul_expr.substr(comma_pos + 1));

    // Если умножение разрешено, возвращаем произведение
    if (allow_mul) {
        pos = end + 1; // Обновляем позицию после "mul(x, y)"
        return x * y;
    }

    pos = end + 1; // Обновляем позицию после "mul(x, y)"
    return 0; // Если умножение не разрешено, возвращаем 0
}

int calculateResult(const std::string &input_string) {
    int result = 0;
    bool allow_mul = true; // Изначально разрешаем умножение
    size_t pos = 0;
    size_t length = input_string.length();

    while (pos < length) {
        // Ищем 'do()' для включения умножения
        if (input_string.substr(pos, 4) == "do()") {
            allow_mul = true;
            pos += 4; // Двигаем позицию после 'do()'
        }
        // Ищем 'don't()' для отключения умножения
        else if (input_string.substr(pos, 7) == "don't()") {
            allow_mul = false;
            pos += 7; // Двигаем позицию после 'don't()'
        }
        // Обрабатываем "mul(x, y)", если умножение разрешено
        else if (input_string.substr(pos, 3) == "mul") {
            result += extractMulExpressions(input_string, pos, allow_mul);
        } else {
            ++pos; // Если ничего не найдено, двигаем позицию по символу
        }
    }

    return result;
}
void second_part( vector <string>  input)
{
    int sum = 0;
   for(auto line:input)
   {
       sum += calculateResult(line);
   }
   cout << sum << "\n";
}

int main()
{
    ifstream myFile;

    myFile.open("input.txt");

    if (!myFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }
    string line;
    vector <string>  input;
    while(getline(myFile, line))
    {
        input.push_back(line);
    }

    first_part(input);
    second_part(input);
}
