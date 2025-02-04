#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string S,T;
	int Q,ls,rs,lt,rt;
	cin >> S >> T;
	cin >> Q;		
	int flag[Q];
    
	for(int i=0;i<Q;i++)
	{
		cin >> ls >> rs >> lt >> rt;
		string s1=S.substr(ls-1,rs-ls+1);
		string s2=T.substr(lt-1,rt-lt+1);
		if((strcmp(s1.c_str(),s2.c_str()))<0)
            cout << "yifusuyi" << endl;
		else if((strcmp(s1.c_str(),s2.c_str()))>0)
			cout << "erfusuer" << endl;
		else cout << "ovo" << endl;
	}

	return 0;
}