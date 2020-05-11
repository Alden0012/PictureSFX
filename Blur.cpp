#include<vector>
#include <string>
#include<iostream>
#include "PicSFX.hpp"
using namespace std;
int main(){
	vector<vector<Pixel>> Out = InitializeVector();
	//cout << endl;
	//cout << "i size" << Out.size() << " , " << Out[1].size() << endl;

	Out = Blur(Out);
	OutputVector(Out);
}