#include <iostream>
#include <locale>
#include <cstdlib>
#include <cstring>
#include <string>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

char str[1024*1024];

ostream &endp(ostream &stream)
{
  	int k = 0, len_of_page = 5;
  	for(int i=0; i<strlen(str); k+=(str[i++]=='\n') );
	if(k>1&&(k%len_of_page==1||len_of_page<=1)) stream<<"---------------------------------------\n";
	if(str[strlen(str)-2]!='\n') stream<<"������ "<<k<<": ";
    return stream;
}

ostream &endp(ostream &stream, int len_of_page)
{
  	int k = 0;
  	for(int i=0; i<strlen(str); k+=(str[i++]=='\n') );
	if(k>1&&(k%len_of_page==1||len_of_page<=1)) stream<<"---------------------------------------\n";
	if(str[strlen(str)-2]!='\n') stream<<"������ "<<k<<": ";
    return stream;
}

ostream &endp(ostream &stream, int len_of_page, char* s)
{
  	int k = 0;
  	for(int i=0; i<strlen(str); k+=(str[i++]=='\n') );
	if(k>1&&(k%len_of_page==1||len_of_page<=1)) stream<<s<<"\n";
	if(str[strlen(str)-2]!='\n') stream<<"������ "<<k<<": ";
    return stream;
}

void p(int n, int p1, char* p2){
	cout<<"������� 4. \n\n";
	cout<<"����� "<<n+1<<":\n";
	if (n>=1) cout<<"������ ���������� ����� �� ��������: "<<p1<<endl;
	if (n>=2) cout<<"����� ����������� �������: "<<p2<<endl;
	cout<<endl;

	char buff[255],c;
	strcpy(str,"");
	ifstream fin("buffer.txt");
	while(fin){
		fin.getline(buff, 255);
		strcat(buff, "\n");  strcat(str, buff);
		if(n==0) cout<<endp<<buff;
		else if(n==1){
			endp(cout,p1);
			cout<<buff;
		}
		else if(n==2){
			endp(cout,p1,p2);
			cout<<buff;
		}
	}
    fin.close();
}


int main(){
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
		p(0,0,"");
		cout<<"\n\n\n������� �� ����� ������� ��� �������� � ����� 2...\n\n\n";getch();system("cls");
		p(1,8,"");
		cout<<"\n\n\n������� �� ����� ������� ��� �������� � ����� 3...\n\n\n";getch();system("cls");
		p(2,4,"_____________________________________________________________");
		cout<<"\n\n\n������ ������� ����� ������� ��� ������ �� ���������\n\n\n";getch();system("cls");
	getch();

	delete str;
	return 0;
}
