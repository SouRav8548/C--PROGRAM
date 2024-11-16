#include<iostream>
using namespace std;

int main(){
	cout<<"****************************Welcome to My Coding Era************************"<<endl;
	cout<<endl;
	cout<<"Enter you favourite number in 1 to 7: ";
	int number;
	cin>>number;
	switch(number){
		case 1: 
			cout<<"It is Monday."<<endl;
			break;
		case 2:
			cout<<"It is Tuesday."<<endl;
			break;
		case 3:
			cout<<"It is Wednesday."<<endl;
			break;
		case 4:
			cout<<"It is Thursday."<<endl;
			break;
		case 5:
			cout<<"It is Friday."<<endl;
			break;
		case 6:
			cout<<"It is Saturday."<<endl;
			break;
		case 7:
			cout<<"It is Sunday."<<endl;
			break;
		default:
			cout<<"Please enter 1 to 7, because week days should be seven";
			break;
	}
	return 0;
}
