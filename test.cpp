#include <iostream>

int main(){
	std::cout << "Please enter two number:" << std::endl;
	int num1 = 0, num2 = 0;
	std::cin >> num1 >> num2;
	std::cout << "sum of " << num1 << " and " << num2 << " is " << num1 + num2 << std::endl;

	int sum = 0, value = 0,currentValue = 0;
	if(std::cin >> currentValue){
		int count = 1;
		while(std::cin >> value){
			if(value == currentValue){
				count++;
			}
			else{
				std::cout << "currentValue is : " << currentValue << " occurs " << count << " times " << std::endl;
				currentValue = value;
				count = 1;
			}
			sum += value;
		}
	}
	
	std::cout << "sum is : " << sum << std::endl;

	return 0;
}