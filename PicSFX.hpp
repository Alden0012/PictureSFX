// Cool Functions!
#ifndef PicSFX_hpp
#define PicSFX_hpp
#include <vector>
#include <iostream>
using namespace std;
struct Pixel{
	int r,g,b;
};
Pixel operator+(Pixel A, Pixel B){ // i dont even think i need this
	Pixel C;
	C.r = A.r + B.r;
	C.g = A.g + B.g;
	C.b = A.b + B.b;
	return C;
}
Pixel operator/(Pixel A,int B){ // probably need this though 
	Pixel C;
	C.r = A.r/B;
	C.g = A.g/B;
	C.b = A.b/B;
	return C;
}

vector<vector<Pixel>> InitializeVector(){
	int w,h;
	int re,gr,bl;
	Pixel p;
	char q;
	string z;
	string c;
	//the laziest way to possibly seperate stuff part 1
	cin >> z >> z >> z >> z  >> w >> q >>  h >> z;
	//cout << w << " " << h;
	vector<vector<Pixel>> outVector;

	for(int i = 0;i < w;i++){
		vector<Pixel> row;
		for(int j = 0;j<h;j++){
			row.push_back({0,0,0});
			//cout << c << endl
		}
		outVector.push_back(row);
	}
	for(int j = 0;j<h;j++){
		for(int i = 0;i<w;i++){
			//dont do this
			cin >>  c >> q >> re >> q >> gr >> q >> bl >> z >> z >> z;
			outVector[i][j].r = re;
			outVector[i][j].g = gr;
			outVector[i][j].b = bl;
		}
	}
	
	vector<vector<Pixel>> NoutVector;
	return outVector;
}
void OutputVector(vector<vector<Pixel>> Input){
	int w = Input.size();
	int h = Input[0].size();
	cout << "# ImageMagick pixel enumeration: " << w << ","<< h << "," << 65535 <<",srgb" << endl; // i have no idea that that number means btw
	for(int i = 0;i<w;i++){
		for(int j = 0;j<Input[i].size();j++){
			cout << i << "," << j << ": (" << Input[i][j].r << "," << Input[i][j].g << "," << Input[i][j].b << ")" << endl;
		}
	}
}



vector<vector<Pixel>> Blur(vector<vector<Pixel>> Input){
	vector<vector<Pixel>> outVector;
	const int w = Input.size();
	const int h = Input[0].size();
	for(int i = 0;i < w;i++){
		vector<Pixel> row;
		for(int j = 0;j<h;j++){
			row.push_back({0,0,0});
			//cout << c << endl
		}
		outVector.push_back(row);
	}
	for(int i = 0;i < w;i++){
		for(int j = 0;j<h;j++){
				if (i == 0){ // how 2 make if else nested if loops and terrible code tutorial 2020 
					if(j == 0){
						outVector[i][j] = (Input[i][j] + Input[i+1][j+1] + Input[i][j+1] + Input[i+1][j])/4;
						//cout << "corner" << endl;
					}
					else if(j == (h-1)){
						outVector[i][j] = (Input[i][j] + Input[i+1][j-1] + Input[i][j-1] + Input[i+1][j])/4;
						//cout << "corner" << endl;
					}
					else{
						outVector[i][j] = (Input[i][j] + Input[i+1][j+1] + Input[i][j+1] + Input[i+1][j] + Input[i+1][j-1] + Input[i][j-1])/6;
					}
				}
				else if (i == (w-1)){

					if (j == 0){
						outVector[i][j] = (Input[i][j] + Input[i-1][j+1] + Input[i][j+1] + Input[i-1][j])/4;
						//cout << "corner" << endl;
					}
					else if(j == (h-1)){
						outVector[i][j] = (Input[i][j] + Input[i-1][j-1] + Input[i][j-1] + Input[i-1][j])/4;
						//cout << "corner" << endl;
					}
					else{
						outVector[i][j] = (Input[i][j] + Input[i-1][j+1] + Input[i][j+1] + Input[i-1][j] + Input[i-1][j-1] + Input[i][j-1])/6;
					}
				}
				else{
					if(j == 0){
						outVector[i][j] = (Input[i][j] + Input[i+1][j+1] + Input[i][j+1] + Input[i+1][j] + Input[i-1][j] + Input[i-1][j+1])/6;				
					}
					else if(j == (h-1)){
						outVector[i][j] = (Input[i][j] + Input[i-1][j-1] + Input[i][j-1] + Input[i-1][j] + Input[i+1][j] + Input[i+1][j-1])/6;
					}
					else{
						outVector[i][j] = (Input[i][j] + Input[i+1][j+1] + Input[i][j+1] + Input[i+1][j] + Input[i+1][j-1] + Input[i][j-1] + Input[i+1][j-1] + Input[i][j-1] + Input[i-1][j-1])/9;
					}
				}

			}
		}
		return outVector;
	}
	




#endif