#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
#include <map>
#include <vector>

enum TokenType
{
    NUMBER,
    VARIABLE,
    OPERATOR,
    FUNCTION,
    LEFT_PAREN,
    RIGHT_PAREN
};

struct Token
{
    TokenType type;
    double value;
    std::string op;
};

std::vector<Token> tokenize(const std::string& expr)
{
    std::vector<Token> tokens;
    std::string number;

    for (size_t i = 0; i < expr.size(); ++i)
    {
        char c = expr[i];

        if (std::isdigit(c) || (c == '.' && !number.empty()))
            number += c;
        else
        {
            if (!number.empty())
            {
                tokens.push_back({NUMBER, std::stod(number), ""});
                number.clear();
            }
            if (c == 't')
                tokens.push_back({VARIABLE, 0, ""});
            else if (c == '+' || c == '*' || c == '/' || c == '^')
                tokens.push_back({OPERATOR, 0, std::string(1, c)});
            else if (c == '-')
            {
                if (tokens.empty() || tokens.back().type == LEFT_PAREN || tokens.back().type == OPERATOR)
                {
                    tokens.push_back({NUMBER, 0, ""});
                    tokens.push_back({OPERATOR, 0, "-"});
                }
                else
                    tokens.push_back({OPERATOR, 0, "-"});
            }
            else if (c == '(')
                tokens.push_back({LEFT_PAREN, 0, ""});
            else if (c == ')')
                tokens.push_back({RIGHT_PAREN, 0, ""});
            else
            {
                std::string func;
                if (expr.substr(i, 3) == "sin")
                {
                    func = "sin";
                    i += 2;
                }
                else if (expr.substr(i, 3) == "cos")
                {
                    func = "cos";
                    i += 2;
                }
                else if (expr.substr(i, 3) == "tan")
                {
                    func = "tan";
                    i += 2;
                }
                else if (expr.substr(i, 3) == "exp")
                {
                    func = "exp";
                    i += 2;
                }
                if (!func.empty())
                    tokens.push_back({FUNCTION, 0, func});
            }
        }
    }
    if (!number.empty())
        tokens.push_back({NUMBER, std::stod(number), ""});
    return tokens;
}

std::vector<Token> infixToPostfix(const std::vector<Token>& tokens)
{
    std::vector<Token> output;
    std::stack<Token> operators;

    std::map<std::string, int> precedence = {
        {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3}
    };

    for (const Token& token : tokens)
    {
        if (token.type == NUMBER || token.type == VARIABLE)
            output.push_back(token);
        else if (token.type == FUNCTION)
            operators.push(token);
        else if (token.type == OPERATOR)
        {
            while (!operators.empty() && operators.top().type != LEFT_PAREN &&
                  ((token.op != "^" && precedence[operators.top().op] >= precedence[token.op]) ||
                  (token.op == "^" && precedence[operators.top().op] > precedence[token.op])))
            {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        else if (token.type == LEFT_PAREN)
            operators.push(token);
        else if (token.type == RIGHT_PAREN)
        {
            while (!operators.empty() && operators.top().type != LEFT_PAREN)
            {
                output.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
            if (!operators.empty() && operators.top().type == FUNCTION)
            {
                output.push_back(operators.top());
                operators.pop();
            }
        }
    }
    while (!operators.empty())
    {
        output.push_back(operators.top());
        operators.pop();
    }
    return output;
}

double evaluatePostfix(const std::vector<Token>& postfix, double t)
{
    std::stack<double> values;

    for (const Token& token : postfix)
    {
        if (token.type == NUMBER)
            values.push(token.value);
        else if (token.type == VARIABLE)
            values.push(t);
        else if (token.type == OPERATOR)
        {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();

            if (token.op == "+") values.push(a + b);
            else if (token.op == "-") values.push(a - b);
            else if (token.op == "*") values.push(a * b);
            else if (token.op == "/") values.push(a / b);
            else if (token.op == "^") values.push(std::pow(a, b));
        }
        else if (token.type == FUNCTION)
        {
            double a = values.top(); values.pop();
            if (token.op == "exp") values.push(std::exp(a));
            else if (token.op == "sin") values.push(std::sin(a));
            else if (token.op == "cos") values.push(std::cos(a));
            else if (token.op == "tan") values.push(std::tan(a));
        }
    }
    return values.top();
}

int main()
{
    std::string formulaX1, formulaY1, formulaX2, formulaY2;
    std::cout << "Enter formula for x1: ";
    std::getline(std::cin, formulaX1);
    std::cout << "Enter formula for y1: ";
    std::getline(std::cin, formulaY1);
    std::cout << "Enter formula for x2: ";
    std::getline(std::cin, formulaX2);
    std::cout << "Enter formula for y2: ";
    std::getline(std::cin, formulaY2);

    auto tokensX1 = tokenize(formulaX1);
    auto tokensY1 = tokenize(formulaY1);
    auto tokensX2 = tokenize(formulaX2);
    auto tokensY2 = tokenize(formulaY2);

    auto postfixX1 = infixToPostfix(tokensX1);
    auto postfixY1 = infixToPostfix(tokensY1);
    auto postfixX2 = infixToPostfix(tokensX2);
    auto postfixY2 = infixToPostfix(tokensY2);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Vector Simulation");
    window.setFramerateLimit(200);

    sf::CircleShape point1(5);
    sf::CircleShape point2(5);
    point1.setFillColor(sf::Color::Red);
    point2.setFillColor(sf::Color::Yellow);

    float t = 0.0f;
    const float dt = 0.01f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float x1 = evaluatePostfix(postfixX1, t);
        float y1 = evaluatePostfix(postfixY1, t);
        float x2 = evaluatePostfix(postfixX2, t);
        float y2 = evaluatePostfix(postfixY2, t);

        point1.setPosition(100 + x1 * 10, 500 - y1 * 10);
        point2.setPosition(100 + x2 * 10, 500 - y2 * 10);

        t += dt;

        window.clear();
        window.draw(point1);
        window.draw(point2);
        window.display();
    }

    return 0;
}


/*
t ^ 2
3 * t
t ^ 2
2

10*sin(t)
5*cos(t)
5*t
10-t

t
t
- t
t

10 * cos ( t )
10 * sin ( t )
5 * cos ( t )
5 * sin ( t )


t^2
0
10+10*t
0
*/
