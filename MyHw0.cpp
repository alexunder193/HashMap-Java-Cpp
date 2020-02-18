#include <iostream>
#include <cstdlib>
#include <list> 
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[]) { 
    ifstream in(argv[1]);
    std::string str;
    std::list<std::string>::iterator it;
    map<std::string, std::map<std::string, int> >::iterator outer ;
	map<std::string, int >::iterator inner ;  
    std::list <std::string> elements;
    while (getline(in, str)) {
    	elements.push_back(str); 
	}
    std::map< std::string, std::map<std::string, int> > m;
    std::map< std::string, int > innerm;
    int pos;
    for (it = elements.begin(); it != elements.end(); it++) {
        string s1 = *it; 
        pos = s1.find("|");
        string firstPart = s1.substr(0, pos);
        string secondPart = s1.substr(pos+1, s1.length()-1);  
        outer = m.find(firstPart);
        if(outer == m.end()) {
            m.insert(std::make_pair(firstPart, innerm));
        }
        inner = m[firstPart].find(secondPart);
        if(inner == m[firstPart].end()) {
        	m[firstPart].insert(std::make_pair(secondPart, m[firstPart].size()+1));
		}     
    }
    cout << std::endl;
    for (it = elements.begin(); it != elements.end(); it++) {
    	string s2 = *it; 
        pos = s2.find("|");
        string firstPart = s2.substr(0, pos);
        string secondPart = s2.substr(pos+1, s2.length()-1);
		cout << firstPart;
		cout << "|";
		cout << secondPart << endl;
        string output = "[" + to_string(m[firstPart][secondPart]) + " of " +  to_string(m[firstPart].size()) + "]" + "\n";
        cout << output;
        cout << "---------";
        cout << "\n";
	}      
    return 0; 
}
