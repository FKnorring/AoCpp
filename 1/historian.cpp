
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

string read_input(string path)
{
  ifstream file(path);
  string line;
  string result = "";
  while (getline(file, line))
  {
    result += line;
    result += "\n";
  }
  return result;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " <input_file>" << endl;
    return 1;
  }

  string input = read_input(argv[1]);

  priority_queue<int, vector<int>, greater<int>> list1;
  priority_queue<int, vector<int>, greater<int>> list2;

  int i, j = 0;

  while (i < input.size())
  {
    // Parse first number of line
    j = i;
    while (input[j] != ' ')
    {
      j++;
    }
    list1.push(stoi(input.substr(i, j - i)));

    // Find next number
    i = j;
    while (i < input.size() && input[i] == ' ')
    {
      i++;
    }

    // Parse second number of line
    j = i;
    while (input[j] != '\n')
    {
      j++;
    }
    list2.push(stoi(input.substr(i, j - i)));

    // Jump over newline
    i = j + 1;
  }

  int result = 0;

  while (!list1.empty() && !list2.empty())
  {
    result += abs(list1.top() - list2.top());
    list1.pop();
    list2.pop();
  }

  cout << result << endl;

  return 0;
}