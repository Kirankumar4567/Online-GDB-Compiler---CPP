#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>

using namespace std;


int main()
{

mkfifo("famous",0666);
char readbuf[2];
int fd = open("famous", O_RDONLY);
      int read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));

string st=readbuf;
string str="c++ "+st+".cpp -o "+st;
cout<<str<<endl;



 const char *command = str.c_str();
	system(command);
	
int c=0;


c=fork();

if(c>0){
	wait(NULL);
	int n;
	
	vector<int> a;
	vector <int> b;
	ifstream fin("op1.txt");

	while(fin>>n)
	a.push_back(n);
	fin.close();
	fin.open("rop.txt");
	
	while(fin>>n)
	b.push_back(n);
	fin.close();
	if(a.size()!=b.size())
		{
		cout<<"Your code is not producing desired output"<<endl;
		}
	else {
	int tag=1;
	for(int i=0;i<b.size();i++)
	{
	if(a[i]!=b[i]){
		tag=0;
		break;}
	}
	if(tag==1) cout<<"test case passed"<<endl;
	else cout<<"test case failled"<<endl;
	cout<<"desired output : ";
	for(int i=0;i<b.size();i++)
	cout<<b[i]<<" ";
	cout<<endl;
	cout<<"your output : ";
	for(int i=0;i<a.size();i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
	}
	}
else {
	int fd1 = open("in.txt",0);
	int fd2 = open("op1.txt",1);
	dup2(fd1,0);
	dup2(fd2,1);
	
	char *args[]={"./p1",NULL};
		execvp("./p1",args);
	
	}


}
