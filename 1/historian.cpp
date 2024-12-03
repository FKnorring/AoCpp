
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

  cout << input << endl;
  return 0;
}