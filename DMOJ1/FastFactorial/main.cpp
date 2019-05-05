#include <iostream>

template<unsigned int n>
struct factorial
{
    enum
    {
        value = n * factorial<n - 1>::value
    };
};

template<>
struct factorial<0>
{
    enum { value = 1 };
};

int main()
{
    int N; 
    std::cin >> N; 

    for (int i = 0; i < N; i++) { 
        int K; 
        std::cin >> K;
        std::cout << factorial<K>::value << std::endl;  
    }
}