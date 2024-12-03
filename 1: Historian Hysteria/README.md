# Intuition (Part 1)

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

Transforming into a min heap is as simple as passing in a comparator function as the second argument.

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

# Intuition (Part 2)

This is a easy map problem, or more accurately i need to implement a counter. I need to put every number in the left list as a key in the map, initialized as 0. And then for every matching number in the right list, increment the value of the key in the map. Then i need to run through the left list again and add its value multiplied by its count to the result.

## Hurdles

### Hash Map

If C++ has a built in priority queue, it probably has a built in hash map as well. I will need to look up how to use it and see if it has any special features that I can use.

#### Solution

I found that the C++ standard library has a built in hash map that I can use. I can use the `std::unordered_map` class to create a hash map.

```cpp
unordered_map<int, int> map;
```
