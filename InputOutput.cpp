#include<iostream>
using namespace std;
int main(){
	std::cout << "Hey, CODERS..!"<<endl;
	std::cout << "Enter Your Experience in years....: ";
	int ex;
	std::cin>>ex;
	if(ex==0){
		std::cout<<"You are now Freasher.."<<endl;
	}else{
		if(ex<=2){
			std::cout<<"You are now Beginner.."<<endl;
		}else{
			std::cout<<"You are now Experienced.."<<endl;
		}
	}
	return 0;
}
