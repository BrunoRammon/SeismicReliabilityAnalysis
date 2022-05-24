#include<iostream>
using namespace std;
int main(int argc, char *argv[], char *envp[]) {
  cout<<"Number of arguments (argc) is"<<argc<<endl;
  cout<<"Program name is "<<argv[0];
  cout<<"\nOther arguments are "<<endl;
  for (int i = 1; i < argc; i++)
   cout <<"argv["<<i<<"] = "<<argv[i] <<endl;
   cout<<"\nEnvironmental Settings are "<<endl;
   for (int i = 0; i < argc; i++)
     cout <<"envp["<<i<<"]="<<envp[i] <<endl;
     return 0;
}

