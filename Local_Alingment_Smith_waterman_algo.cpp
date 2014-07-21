/* Local Alingment with Smit Waterman algo */ 
/* Score Gap = -2 MissMatch=-1 Match=+2 */
/* In this program give input as 1> ACCTAAGG   2>GGCTCAATCA it generate as same output as given in following slide
http://www.slideshare.net/avrilcoghlan/the-smith-waterman-algorithm  */

#include<iostream>
using namespace std;
int main()
{
	string S,T;
	int gap=-2,missmatch=-1,match=2;
	int max=0,ii=0,jj=0;
	cout<<"Enter String 1 :- ";
	cin>>S;
	cout<<"Enter String 2 :- ";
	cin>>T;
	int lenS=S.length();
	int lenT=T.length();
	int array[lenS+1][lenT+1];
	
	for(int i=0;i<=lenS;i++)
	{
		for(int j=0;j<=lenT;j++)
		{
			if(i==0 || j==0)
			{
					array[i][j]=0;   //set (0,0),(i,0),(0,j) cordinate of graph is 0
			}	
		}
	}
	for(int i=1;i<=lenS;i++)
	{
		for(int j=1;j<=lenT;j++)
		{
				int value;
				if(S[i-1]==T[j-1])
				{
					value=array[i-1][j-1] + match ; // if match found add match value in digonal last value means VALUE=(i-1,j-1)+2;
				}
				else
				{
					value=array[i-1][j-1] + missmatch ;  // if match found add missmatch value in digonal last value means VALUE=(i-1,j-1)+ (-1);
				}
				if(value < array[i-1][j] + gap )
				{
					value = (array[i-1][j]) + gap ; // if (i-1,j) + gape value is greter then above gate VALUE then VALUE = (i-1,j) + gape value 
				}
				if(value < (array[i][j-1]) + gap )
				{
					value = (array[i][j-1]) + gap ; // if (i,j-1) + gape value is greter then above gate VALUE then VALUE = (i,j-1) + gape value
				}
				if (value>0)
				{
					array[i][j]=value;  // assing this VALUE in (i,j) if value is greter then 0
					if(max<value)
					{
						max=value;
						ii=i;   // save index of high score in matrix
						jj=j;
					}
				}
				else
				{
					array[i][j]=0;
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
	/* Find Bast Match means Optimal Solution (BackTrack)*/
	/*Score Gap = -2 MissMatch=-1 Match=+2 */
	int i=ii;
	int j=jj;
	string newS="",newT="";
	while(array[i][j]!=0)
	{
			if(array[i][j]==array[i-1][j-1] + match)
			{
				newS=S[i-1]+newS;
				newT=T[j-1]+newT;
				i--;
				j--;
			}
			else if(array[i][j]==array[i-1][j-1] + missmatch)
			{
				newS=S[i-1]+newS;
				newT=T[j-1]+newT;
				i--;
				j--;
			}
			else if(array[i][j]==(array[i-1][j] + gap ))
			{
				newS=S[i-1]+newS;
				newT="_"+newT;
				i--;
			}
			else if(array[i][j]==(array[i][j-1] + gap ))
			{
				newS="_"+newS;
				newT=T[j-1]+newT;
				j--;
			}		
	}
	cout<<"string 1 :- "<<newS<<endl;
	cout<<"string 2 :- "<<newT<<endl;
return 0;
}
