#include <iostream>

using namespace std;
const int N=5;
int T[N][N];
bool mozliwe(int i, int w, int k, int &w2, int &k2)
{
int dk[]={1,2,2,1,-1,-2,-2,-1};
int dw[]={-2,-1,1,2,2,1,-1,-1};
w2=w+dw[i];
k2=k+dk[i];
return w2>=0 and w2<N and k2>=0 and k2<N and T[w2][k2]==0;
}

void wyswietl()
	{
		for(int i=0; i<N*N; i++)
			{
			cout<<T[i/N][i%N]<<"  ";
			if(i%N==N-1) cout<<endl;
			}
cout<<endl<<endl<<endl;
return;
	}

void skoczek(int w, int k, int numer, int &l)
{
//skoczek(T,0,0,1)
T[w][k]=numer;
int w2,k2;
if (numer==N*N) 
{
wyswietl();
}
for(int i=0; i<N; i++)
	{
	if (mozliwe(i,w,k,w2,k2)) skoczek(w2,k2, numer+1, l);
	}
T[w][k]=0;
return;	
}

int main()
{
int l=0;
for(int i=0; i<N*N; i++)
T[i%N][i/N]=0;
skoczek(0,0,1,l);
cout<<endl<<l<<endl;
return 0;
}
