#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

bool max_n_between(int a, int b, int n)
{
  return abs(a - b) <= n;
}

int process_line(std::string line)
{
  const char *delimiter = " ";

  char *token = strtok(line.data(), delimiter);

  std::vector<int> numbers;

  int num;

  while (token != NULL)
  {
    num = std::stoi(token);
    numbers.push_back(num);
    token = strtok(NULL, delimiter);
  }

  if (numbers.size() < 2)
    return 0;

  int dir = numbers[0] - numbers[1];

  if (dir == 0)
    return 0;

  for (int i = 0; i < numbers.size() - 1; i++)
  {
    if (dir < 0)
    {
      if (numbers[i] >= numbers[i + 1] || !max_n_between(numbers[i], numbers[i + 1], 3))
      {
        return 0;
      }
    }
    else
    {
      if (numbers[i] <= numbers[i + 1] || !max_n_between(numbers[i], numbers[i + 1], 3))
      {
        return 0;
      }
    }
  }

  return 1;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);
  std::string line;

  int result = 0;

  while (std::getline(file, line))
  {
    if (process_line(line))
    {
      result++;
    }
  }

  std::cout << result << std::endl;

  return 0;
}