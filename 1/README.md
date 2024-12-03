## Intuition (Part 1)

My initial thoughts after reading this problem is that this is most efficiently and easily solved by using a min heap or priority queue. Setting up one priority queue for each list of id's, popping them both and adding the absolute difference to the result until both queues are empty.

## Hurdles

### Parsing

#### Reading Files

I do not remember how to properly parse a file or a string in C. I will need to look this up and see if C++ has any built in functions that can help me with this.

##### Solution

I found a simple way to parse input files using the standard library. I can use the `std::ifstream` class to open a file and read it line by line. I can then use the `std::getline` function to read each line into a string. 

```cpp
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
```

#### Priority Queue

It seems like the C++ standard library has a much larger standard library compared to C. I will need to see if i have to implement a priority queue from scratch or if there is a built in one that I can use.

##### Solution

I found that the C++ standard library has a built in priority queue that I can use. I can use the `std::priority_queue` class to create a min heap.

```cpp  
priority_queue<int> pq;
```

## Intuition (Part 2)
