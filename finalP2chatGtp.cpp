#include <iostream>
#include <set>
#include <fstream>

#include <string>

using namespace std;

// Function to calculate the number of words that start with an upper case letter
int count_upper_case_words(const set<string>& novel) {
  int count = 0;
  for (const string& word : novel) {
    if (word[0] >= 'A' && word[0] <= 'Z') {
      count++;
    }
  }
  return count;
}

int main() {
    string Name = "Fahad Faruqi";
    cout << "-----------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "-----------------------------------------\n";

    ifstream in("sunHem.txt");

    if(!in){
        cout << "Didn't Open Correctly :/\n";
        return 1;
    }
  // Read the SunHem.txt and store each word into a set<string> container
    set<string> novel;
    string word;
    while (getline(in, word, ' ')) {
        novel.insert(word);
    }

  // Calculate the total number of unique words in the text
    int num_unique_words = novel.size();
    cout << "Number of unique words: " << num_unique_words << endl;

    // Calculate the number of characters in each unique word and store the result
    // in a histogram array, int Hist[20]
    int hist[20] = {0};
    for (const string& word : novel) {
        int len = word.length();
        if (len < 20) {
        hist[len]++;
        }
    }
  // Print the histogram
    cout << "Histogram:" << endl;
    for (int i = 0; i < 20; i++) {
    cout << i << ": " << hist[i] << endl;
    }

    // Calculate the number of words that start with an upper case letter
    int num_upper_case_words = count_upper_case_words(novel);
    cout << "Number of words that start with an upper case letter: " << num_upper_case_words << endl;

return 0;
}
