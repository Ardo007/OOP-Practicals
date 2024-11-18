#include <iostream>

int main(){
    int answer;
    

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            answer = i * j;
            std::cout << answer << " ";
        }
        std::cout << '\n';
    }

    

    return 0;
}