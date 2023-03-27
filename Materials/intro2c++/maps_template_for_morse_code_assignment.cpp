 
 
//Program to demonstrate use of the map template class. Compile with -std=c++11
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;        

int main( )
{
    map<string, string>  ch_to_morse;

    ch_to_morse["A"] = ".-";
    ch_to_morse["B"] = "-...";
    ch_to_morse["C"] = "-.-.";
    
    map<string, string>  morse_to_ch;
    for (auto iter =ch_to_morse.begin(); iter != ch_to_morse.end(); iter++)
    morse_to_ch[iter->second]= iter->first;
 
    /*
    for (auto iter =ch_to_morse.begin(); iter != ch_to_morse.end(); iter++)
    {
        cout << iter->first << " - " << iter->second << endl;
    }
    
    for (auto iter = morse_to_ch.begin(); iter != morse_to_ch.end(); iter++)
    {
        cout << iter->first << " - " << iter->second << endl;
    }
    
    */
    string tryme="CAB";
    for (int i =0;  i< tryme.length();  i++)
    {
        string tmp (1, tryme[i]); 
        cout << ch_to_morse[tmp] <<endl;;
    }
    cout<<endl;

    for (auto p : tryme)
    {
        string tmp (1,p); 
        cout << ch_to_morse[tmp] <<endl;;
    }
    cout<<endl;
    
    
    // for morse code to English phrases read in the code on per line into a sequential container of strings
    vector<string> tryme2 = {"-.-.",".-", "-..."};//a sequential container of strings to store morse code
     
    
    for (auto p : tryme2)
    {
        cout << morse_to_ch[p];
    }
    cout<<endl;
    
    
    return 0;
}
