#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <algorithm>
#include <excpt.h>
#include <cstdlib>
using namespace std;

size_t sampleHash(const std::string &key)
{
  unsigned long hash = 5381;
  for (char ch : key)
  {
    hash = ((hash << 5) + hash) + ch;
  }
  return hash % 1000000;
  // else
  // {
  //   throw(runtime_error("IDK"));
  // }
}

class HashFunctionTester
{
private:
  std::vector<std::string> randomStrings;
  size_t (*hashFunc)(const std::string &);

public:
  HashFunctionTester(size_t (*func)(const std::string &), int numStrings = 100000000) : hashFunc(func)
  {
    // Generate random string
    for (int i = 0; i < numStrings; i++)
    {
      string s = generateRandomString(22);
      // if (find(randomStrings.begin(), randomStrings.end(), s) == randomStrings.end())
      // {
      //   randomStrings.push_back(s);
      // }
      randomStrings.push_back(s);
    }
    printf("Size= %d \n", randomStrings.size());
  }

  std::string generateRandomString(int length = 22)
  {
    vector<char> a;
    a.push_back('0');
    a.push_back('1');
    a.push_back('2');
    a.push_back('3');
    a.push_back('4');
    a.push_back('5');
    a.push_back('6');
    a.push_back('7');
    a.push_back('8');
    a.push_back('9');
    vector<char> b;
    b.push_back('A');
    b.push_back('B');
    b.push_back('C');
    b.push_back('D');
    const char alphanum[] = "0123456789ABCD";
    std::string result = "";
    int k = 0;
    for (int i = 0; i < length; i++)
    {
      if (i < 4)
      {
        int o = rand() % (4 - i);
        result += b[o];
        b.erase(b.begin() + o);
      }
      else if (i == 11)
      {
        result += '_';
      }
      else if (k < 10)
      {
        // cout << "Yes\n";
        int j = rand() % (10 - k);
        result += a[j];
        a.erase(a.begin() + j);
        k++;
      }
      else
      {
        result += alphanum[(rand()) % (10)];
      }
    }
    if (result == "")
    {
      cout << result << "        Ljhytrryy ";
      throw(runtime_error("njk"));
    }
    return result;
  }

  void testUniformity()
  {
    std::unordered_map<size_t, int> hashCounts;
    int min_hash_val = 99999999;
    int max_hash_val = 0;

    for (const auto &s : randomStrings)
    {
      size_t hashValue = hashFunc(s);
      hashCounts[hashValue]++;
      if (hashValue < min_hash_val)
      {
        min_hash_val = hashValue;
      }
      if (hashValue > max_hash_val)
      {
        max_hash_val = hashValue;
      }
    }

    double averageCount = static_cast<double>(randomStrings.size()) / hashCounts.size();
    std::cout << "Average count per bucket: " << averageCount << std::endl;
    cout << "min=" << min_hash_val << "          max=" << max_hash_val << endl;
  }

  void testCollisionRate()
  {
    int max_hash_sz = 0;
    int min_hash_sz = 8824784;
    int collision_count = 0;
    int total_insert = 0;
    vector<int> arr(1000000, 0);
    for (const auto &s : randomStrings)
    {
      // cout << s << endl;
      int hashValue = hashFunc(s);
      // cout << hashValue << " ";
      total_insert++;

      if (arr[hashValue] > 0)
      {
        collision_count++;
        // cout << hashValue << " H      s" << s << endl;
      }
      arr[hashValue]++;
      if (arr[hashValue] > max_hash_sz)
      {
        max_hash_sz = arr[hashValue];
      }
    }
    printf("Total insertions:%d      Total collision:%d\n", total_insert, collision_count);
    float avg = float(collision_count * 100) / float(total_insert);
    printf("Collision rate:%f  \n", avg);
    cout << "MAx_hash_sz=" << max_hash_sz << "\n";
  }

  void timeTaken()
  {
    // TODO
  }

  void avalancheEffect()
  {
    int avg_avalache = 0;
    int count = 1;
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (const auto &s : randomStrings)
    {
      int hashValue = hashFunc(s);
      string p = s;
      p[12 + rand() % 9] = alphanum[rand() % (10)];
      int hashvalue2 = hashFunc(p);
      avg_avalache += abs(hashvalue2 - hashValue) > 0;
      count += 1;
    }
    printf("Avlance Effect :%f %  \n", float(avg_avalache) / count);
  }
};
int main()
{

  HashFunctionTester tester(sampleHash);

  std::cout << "Testing Uniformity..." << std::endl;
  tester.testUniformity();

  // std::cout << "\nTime taken..." << std::endl;
  // tester.timeTaken();

  std::cout << "\nTesting Collision Rate..." << std::endl;
  tester.testCollisionRate();

  std::cout << "\nTesting Avalanche Effect..." << std::endl;
  tester.avalancheEffect();
  // cout << sampleHash("YFOB3920756_4274937345");
  return 0;
}