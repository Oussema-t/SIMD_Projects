#include <iostream>
#include <vector>
#include <chrono>

void func(std::vector<int>& arr) {
for (int i = 0; i < arr.size(); i++) {
int temp = arr[i] * 2 + 1;
arr[i] = ((((temp* 3)- 2)* 4) / 2);
}
}
int main() {
auto start = std::chrono::high_resolution_clock::now();
std::vector<int> v(100000);
for (auto i = v.begin(); i != v.end(); ++i) {
    *i = std::distance(v.begin(), i) + 1;
}

std:: cout<< "The main VECTOR: "<< std::endl; 
 for (auto i : v) {
    std::cout << i << " ";
}    
std:: cout<< ""<< std::endl; 

std:: cout<< "The result VECTOR: "<< std::endl; 
func(v);
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

std::cout << "Elapsed time: " << elapsed << " nanoseconds" << std::endl;
 return 0;
}
   
