#include <iostream>

int main(){
  std::string s = "abcabcbb";
  int longest = 0, strlen = s.length();

  for(int i=0; i<strlen; i++){
    for(int j=0; j<strlen; j++){
      std::unordered_map<std::string,std::string>map;
      std::cout<<"Count: "<<i<<" "<<s.substr(i,1)<<"\n";
      if(map[s.substr(i,1)]){ continue; }

  }
}
