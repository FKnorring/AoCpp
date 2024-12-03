
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

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

  priority_queue<int, vector<int>, greater<int>> left_queue, right_queue;

  vector<int> left, right;

  int i, j, num = 0;

  while (i < input.size())
  {
    // Parse first number of line
    j = i;
    while (input[j] != ' ')
    {
      j++;
    }
    num = stoi(input.substr(i, j - i));
    left_queue.push(num);
    left.push_back(num);

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
    num = stoi(input.substr(i, j - i));
    right_queue.push(num);
    right.push_back(num);

    // Jump over newline
    i = j + 1;
  }

  // Calculate Part 1
  int result = 0;

  while (!left_queue.empty() && !right_queue.empty())
  {
    result += abs(left_queue.top() - right_queue.top());
    left_queue.pop();
    right_queue.pop();
  }

  cout << result << endl;

  // Calculate Part 2
  unordered_map<int, int> counter;

  for (auto num : left)
  {
    counter[num] = 0;
  }

  for (auto num : right)
  {
    if (counter.find(num) != counter.end())
    {
      counter[num]++;
    }
  }

  result = 0;

  for (auto num : left)
  {
    result += num * counter[num];
  }

  cout << result << endl;

  return 0;
}