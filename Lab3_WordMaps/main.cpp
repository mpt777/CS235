#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <fstream>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
srand(time(NULL)); // this line initializes the random number generated
	int num_Words = stoi(argv[2]); 
	int starting_Value = stoi(argv[3]);

	vector<string> tokens;
    set <string> unique;
		vector<string> allWords;
    string next_line;  // Each data line
		string file_name = argv[1];
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
						//allWords.push_back(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
		ofstream setfile(file_name+"_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
       // cout << ' ' << *it;
				setfile << *it << endl;
		}

	  setfile.close(); //Closes the setfile

		ofstream setfile2(file_name+"_vector.txt");
		for(int i=0; i < tokens.size(); i++){
			setfile2 << tokens.at(i) << endl;
		}
		setfile2.close();

//----------------
// Part 3

map<string, string> wordmap;
string last="";

ofstream setfile3(file_name+"_map.txt");
for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
  wordmap[last]=*it;
  last = *it;
	//setfile3 << wordmap[last] << ", " << last << endl;
	//cout << wordmap[last] << ", " << last << endl;
}

for(auto elem : wordmap)
{
   setfile3 << elem.first << ", " << elem.second << endl;
}
	setfile3.close();

// Part 4
string state = "";
for(int i = 0; i < num_Words; i++){
  //cout << wordmap[state] << " ";
  state = wordmap[state];
}
// Part 5 -- Makes a "wordmap" of every word that is paired with our word. (Since words are common, and many different words come after them)
/*
map<string, vector<string>> word_to_wordmap;
state = "";
for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
  word_to_wordmap[state].push_back(*it);
  state = *it;
}

// so you dont get the same thing every time
// This will pull a randomw word that has a map pair with the word we are on							
state = "";
for (int i = 0; i < num_Words; i++) {
  int ind = rand() % word_to_wordmap[state].size();
  //cout << word_to_wordmap[state][ind] << " ";
  state = word_to_wordmap[state][ind];
}
*/
//Part 6
  map<list<string>, vector<string>> wordmap_context;
  list<string> state_list;
  for (int i = 0; i < starting_Value; i++) {
    state_list.push_back("");
  }
   list<string> state_list_og = state_list;                   
  for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    wordmap_context[state_list].push_back(*it);
    state_list.push_back(*it);
    state_list.pop_front();
  }
	//state_list.clear();
  for (int i = 0; i < starting_Value; i++) {
    state_list.push_back("");
  }
  for (int i = 0; i < num_Words; i++) {
		if(wordmap_context[state_list].size()==0){
			state_list = state_list_og;
		}
    int ind = rand() % wordmap_context[state_list].size();
    cout << wordmap_context[state_list][ind]<<" ";
    state_list.push_back(wordmap_context[state_list][ind]);
    state_list.pop_front();
  }

    cout << endl;
}