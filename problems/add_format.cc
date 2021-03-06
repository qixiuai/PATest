#include <iostream>
#include <string>
#include <vector>

using namespace std;


std::string format(int num) {
  std::string ret = "";
  std::string flag = "";
  if (num < 0) {
    flag = "-";
    num = -num;
  }
  int counter = 0;
  auto digit_to_str = [&counter, &ret](int digit) {
    if (counter != 3) {
      ret = std::to_string(digit) + ret;
    }
    else {
      ret = std::to_string(digit) + "," + ret;
      counter = 0;
    }
    counter += 1;
  };
  
  while (true) {
    int q = num / 10;
    int rem = num - q * 10;
    digit_to_str(rem);
    num = q;
    std::cout << q << ',';
    if (num == 0) {
      break;
    }
  }
  std::cout << '\n';
  ret = flag + ret;
  return ret;
}

int main()
{
  //int a, b;
  int a;
  /*
  while (cin >> a >> b)
    cout << format(a+b) << endl;
  */
  while (cin >> a) {
    cout << format(a) << endl;
    std::cout << "-----" << std::endl;
  }
  return 0;
}
