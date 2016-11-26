#include<iostream>
#include<fstream>
#include<string.h>
#include<stack>
using namespace std;
char tried = '*';
char path = '#';
int row;
int col;
bool good(string *a,int i,int j){
	if(i>=0&&j>=0&&i<row&&j<col)
		if(a[i][j]=='1')
			return 1;
	return 0;
}
bool move(string *a,int i,int j){
	//cout<<path<<endl;
	bool done = 0;
	if(good(a,i,j)){
		a[i][j]=tried;
		if(i==row-1&&j==col-1)
			done=1;
		else{
			done = move(a,i+1,j);
			if(!done)
				done = move(a,i,j+1);
			if(!done)
				done = move(a,i-1,j);
			if(!done)
				done = move(a,i,j-1);
		}
		if(done)
			a[i][j]=path;
	}
	return done;
}
int main(){
	string *a = new string [20];
	int i=0;
	ifstream infile("/home/huaishuo/workspace/randmaze.txt");
	if(!infile.is_open()){cout<<"Can't find!!";}
	else{
		while(!infile.eof()){
			getline(infile,a[i],'\n');
			i++;
		}
		for(int ii=0;ii<i;ii++){
			for(int jj=0;jj<i;jj++)
				cout<<a[ii][jj]<<" ";
			cout<<endl;
		}
		row=i;
		col=i;
	//	cout<<i<<"  "<<row<<"  "<<col<<endl;
		if(move(a,0,0)){cout<<"Yes!Found a way!"<<endl;}
		else{cout<<"No!There is no way in this maze....."<<endl;}
		for(int ii=0;ii<i;ii++){
			for(int jj=0;jj<i;jj++){
				if(a[ii][jj]=='#')
					cout<<"\033[31m"<<a[ii][jj]<<" "<<"\033[0m";
				else
					cout<<a[ii][jj]<<" ";}
			cout<<endl;
		}

	}
	return 0;
	//cout<<"hello"<<endl;
}
