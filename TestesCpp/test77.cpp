#include <fstream>

int main() {  
  std::ofstream outfile;

  outfile.open("yourfile.txt", std::ios::out);//std::ios_base::app
  outfile.clear();
  outfile << " aaaa"; 
  return 0;
}