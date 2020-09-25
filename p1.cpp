#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int match(string word, string pattern)
{
    if (word==pattern)
    {
        return 1;
    }
    if (word.length()==pattern.length())
    {
        bool match = true;
        for(unsigned int i = 0; i<word.length(); i++)
        {
            if(word[i]!=pattern[i] && pattern[i]!='?')
            {
                match = false;
            }
        }
        if(match)
        {
            return 1;
        }
    }
    for(unsigned int i =0; i<pattern.length(); i++)
    {
        if(pattern[i]=='?' && pattern[i+1]!='?')
        {
            string newPattern = pattern.substr(0, i) + pattern.substr(i+1);
            if(match(word, newPattern))
            {
                return 1;
            }
        }
        
    }
    return 0;
}

int main(int argc, char** argv)
{
    fstream file;
    string words[10000], fileName, inputWord;
    int numWords = 0;
    int frequency[10000];
    int numAppear = 0;

    //name of file
    fileName = argv[1];

    //open file
    file.open(fileName.c_str());

    //extracting the files words
    while (!file.eof())
    {  
        string word;
        file >> word;
        if (!file.fail())
        {
            int start =0;
            for(unsigned int i =0; i <= word.length(); i++)
            {
                word[i] = tolower(word[i]);
                if(!isalpha(word[i]))
                {
                    if((i-start)!=0)
                    {
                        numAppear++;
                        bool copy = false;
                        for(int j =0; j<numWords; j++)
                        {
                            if(word.substr(start, i-start) == words[j])
                            {
                                copy=true;
                                frequency[j]++;
                                
                            }
                        }
                        if(!copy)
                        {
                            words[numWords] = word.substr(start, i-start);
                            frequency[numWords] = 1;
                            numWords++;
                        }
                    }
                    start = i+1;
                }

            }
            
        }    
    }
   
    cout << "The number of words found in the file was " << numAppear << endl;
    cout << "The number of distinct words found in the file was " << numWords << endl << endl << endl;

    while (!cin.eof())
    {  
        string search;
        cout << endl;
        cout << "Please enter a word: ";
        cin >> search;
        
        if (!cin.fail())
        {
            bool noAppearance = true;
            for(int i=0; i<numWords; i++)
            {
                if(match(words[i], search))
                {
                    cout << "The word " << words[i] << " appears " << frequency[i] << " times in the document" << endl;
                    noAppearance = false;
                }
                
            }
            if (noAppearance)
            {
                cout << "The word " << search << " appears 0 times in the document" << endl;
            }
            
        }
    } 

    


    
    
    //recursive question mark function
    //void findWord(string word)
    //{
    //how many times is word in the file string words

   // }
    
    

    return 0;
    
}

