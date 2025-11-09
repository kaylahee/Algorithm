#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr;
    for (int i = 1; i <= 1000; i++){
        for (int j = 0; j < i; j++){
            arr.push_back(i);
        }
    }
    
    int a, b;
    std::cin >> a >> b;
    
    int sum = 0;
    for (int i = a - 1; i < b; i++){
        sum += arr[i];
    }
    std::cout << sum << "\n";
    
    return 0;
}