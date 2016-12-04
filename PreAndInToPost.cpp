/*************************************************************************
	>> File Name: PreAndInToPost.cpp
	>> Author:HuaiShuo 
	>> Created Time: Sun 04 Dec 2016 12:26:46 AM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
void Post(char pre[],char in[]){
    int j = strlen(in);
    char p[100],k[100],pp[100],kk[100];
    p[0]='\0';
    k[0]='\0';
    pp[0]='\0';
    kk[0]='\0';/*初始化*/
    if(j>0){
        /*左半部*/
        int i = 0;
        char one = pre[0];
        for(i = 0;;i++){
            if(i+1==j||(in[i]==one)) break;
            p[i]=pre[i+1];
            k[i]=in[i];
        }
        p[i]='\0';
        k[i]='\0';
        Post(p,k);
        /*右半部*/
        int l = 0;
        for(;i<j-1;i++,l++){
            pp[l]=pre[i+1];
            kk[l]=in[i+1];
        }
        pp[l]='\0';
        kk[l]='\0';
        Post(pp,kk);
        cout<<one<<" ";
    }
    else {
        //if(j=1) cout<<pre[0]<<" ";
        return;
        }
}
int main(){
    char pre[100],in[100];
    cout<<"Please enter the PreOrder"<<endl;
    cin>>pre;
    cout<<"Please enter the InOrder"<<endl;
    cin>>in;
    cout<<"The PostOrder is"<<endl;
    Post(pre,in);
    return 0;
}
