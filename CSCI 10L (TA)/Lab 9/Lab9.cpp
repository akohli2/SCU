#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

double average(double arr[], int size){
    double total=0;
    for(int i=0; i<size; i++){
        total=total+arr[i];
    }
    return total/size;
}

struct StudentInfo{
  string firstname;
  string lastname;
  string year;
  double gpa;
};

int main(){
	ifstream in_stream;
	in_stream.open("psych-round2-scores.txt");
	if(in_stream.fail()){
		cout<<"Open failed \n";
		exit(1);
	}
	double avg[125];
	int i = 0;
	while (in_stream>>avg[i]){
		i++;
	}
	in_stream.close();
	double output = average(avg, i);

	ofstream out_stream;
	out_stream.open("output.txt");
	if(out_stream.fail()){
		cout<<"Output failed"<<endl;
		exit(1);
	}
	out_stream<<output;
	for (int j=0;j<i;j++){
		if(avg[j]>output){
			out_stream<<avg[j]<<endl;
		}
	}
	out_stream.close();

	ifstream in_stream2;
	in_stream2.open("studentlist1.txt");
	if (in_stream2.fail()){
		cout<<"open failed"<<endl;
		exit(1);
	}
	StudentInfo arr[9];
	int x=0;
	while (in_stream2>>arr[x].firstname){
		in_stream2>>arr[x].lastname;
		in_stream2>>arr[x].year;
		in_stream2>>arr[x].gpa;
		x++;
	}
	in_stream2.close();
}
