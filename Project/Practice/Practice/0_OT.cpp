#include <iostream>
#include <vector>
// 동적배열
// 정적배열

// 전역금지
using namespace std; //<<< not allowed
// using std::cout; //<<< allowed optionally

// AUTOSAR
// MISRA
// barr~~

int main(void)
{
    // automatically deallocate.
    // std::unique_ptr<int> a = std::

    int* p = new int(3);
    delete(p);

    int a = 3;  //
    int c{ 3 }; // uniform initialize.

    int arr[] = { 1, 2, 1, 2, 1, 2 };
    std::vector<int>arr2 = { 4, 2, 3, 1, 2 };

    // indexing
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i];
    }

    // ranged for
    // for (const auto & num : arr)
    for (int num : arr)
    {
        std::cout << num;
    }

    // iterator
    // more slow than ranged for.
    for (auto i = arr2.begin(); i != arr2.end(); i++)
    {

    }
}