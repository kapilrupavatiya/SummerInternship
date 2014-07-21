/* Global Alingment using Needleman Wunsch Algo */
/* Score Gap = -1 MissMatch=-1 Match=+2 
in this program give input as 
1> GTAGTACAGCTCAGTTGGGATCACAGGCTTCT   
2> GTAGAACGGCTTCAGTTGTCACAGCGTTC    
it generate as same as in PDF Pair_wise_alingment page no :- 4 
also Give same out put as below webside 
http://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm */

#include<iostream>
using namespace std;
int main()
{
	string S,T;
	cout<<"Enter String 1 :- ";
	cin>>S;
	cout<<"Enter String 2 :- ";
	cin>>T;
	int lenS,lenT;
	int gap=-1,missmatch=-1,match=2;
	lenS=S.length();
	lenT=T.length();
	int array[lenS+1][lenT+1];
	for(int i=0;i<=lenS;i++)
	{
		for(int j=0;j<=lenT;j++)
		{
			if(i==0 || j==0)
			{
				if(i==0 && j==0)
				{
					array[i][j]=0;   //set (0,0) cordinate of graph is 0
				}
				else if(i==0)
				{
					array[i][j]=array[i][j-1] + gap; //set (0,j) cordinate of graph is value of (0,j-1) + gape value (Here Gape value is -1)
				}
				else
				{
					array[i][j]=array[i-1][j] + gap; //set (i,0) cordinate of graph is value of (i-1,0) + gape value (Here Gape value is -1)
				}
			}
			
			else
			{
				int value=0;
				if(S[i-1]==T[j-1])
				{
					value=array[i-1][j-1] + match ; // if match found add match value in digonal last value means VALUE=(i-1,j-1)+2;
				}
				else
				{
					value=array[i-1][j-1] + missmatch ;  // if match found add missmatch value in digonal last value means VALUE=(i-1,j-1)+(-2);
				}
				if(value < (array[i-1][j]) + gap )
				{
					value = (array[i-1][j]) + gap ; // if (i-1,j) + gape value is greter then above gate VALUE then VALUE = (i-1,j) + gape value 
				}
				if(value < (array[i][j-1]) + gap )
				{
					value = (array[i][j-1]) + gap ; // if (i,j-1) + gape value is greter then above gate VALUE then VALUE = (i,j-1) + gape value
				}
				array[i][j]=value;  // assing this VALUE in (i,j)
			}
		}
	}
	/* Print Scoring Matrix */
	for(int i=0;i<=lenS;i++)
	{
		for(int j=0;j<=lenT;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	/* Find Bast Match means Optimal Solution (BackTrack)
	Score Gap =-1 MissMatch=-1 Match=+2 */
	int i=lenS;
	int j=lenT;
	string newS="",newT="";
	while(i>=0 && j>=0)
	{
			if(array[i][j]==(array[i-1][j] + gap ))
			{
				newS=S[i-1]+newS;
				newT="_"+newT;
				i--;
				cout<<i<<" "<<j<<endl;
				cout<<"S:- "<<newS<<endl;
				cout<<"T:- "<<newT<<endl;
			}
			else if(array[i][j]==(array[i][j-1] + gap ))
			{
				newS="_"+newS;
				newT=T[j-1]+newT;
				j--;
				cout<<i<<" "<<j<<endl;
				cout<<"S:- "<<newS<<endl;
				cout<<"T:- "<<newT<<endl;
			}
			else if(array[i][j] == (array[i-1][j-1] + match))
			{
				newS=S[i-1]+newS;
				newT=T[j-1]+newT;
				i--;
				j--;
				cout<<i<<" "<<j<<endl;
				cout<<"S:- "<<newS<<endl;
				cout<<"T:- "<<newT<<endl;
			}
			else
			{
				newS=S[i-1]+newS;
				newT=T[j-1]+newT;
				i--;
				j--;
				cout<<i<<" "<<j<<endl;
				cout<<"S:- "<<newS<<endl;
				cout<<"T:- "<<newT<<endl;
			}
		}
	cout<<"string 1 :- "<<newS<<endl;
	cout<<"string 2 :- "<<newT<<endl;
return 0;
}
