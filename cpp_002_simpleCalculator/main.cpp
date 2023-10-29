#include <iostream>

const char* prompt()
{
  return "Enter an expression with two integers i.e. \"25 + 35\": ";
}

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int multiply(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  return a / b;
}

int main()
{
  int a = 0, b = 0;
  char op = '_';
  int res = 0;
  while (true)
  {
    bool validInput = false;
    while (!validInput)
    {
      std::cout << prompt();
      while (!(std::cin >> a >> op >> b))
      {
        std::cout << "Wrong format try again!" << std::endl;
        std::cout << prompt();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      switch (op) {
        case '+':
          res = add(a, b);
          validInput = true;
          break;
        case '-':
          res = subtract(a, b);
          validInput = true;
          break;
        case '*':
        case '.':
          res = multiply(a, b);
          validInput = true;
          break;
        case '/':
          res = divide(a, b);
          validInput = true;
          break;
        case '^':
          res = 1;
          for (int i = 0; i < b; i++)
          {
            res = multiply(res, a);
          }
          validInput = true;
          break;
        default:
          std::cout << "Unsupported operation, use {+, -, *, /, ^}!" << std::endl;
          validInput = false;
          break;
      }
    }
    std::cout << "The result of " << a << " " << op << " " << b
    << " is " << res << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return 0;
}
