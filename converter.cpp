#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> encode(vector<int> temp);
void toBinary(int value);
void printResult(vector<string> result);

vector<int> binaryValue;
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    
    for (int i = 0; i<MESSAGE.length(); i++) {
        toBinary((int)MESSAGE[i]);
        //cout<<" ";
    }
    
    reverse(binaryValue.begin(), binaryValue.end()); 
     // PRINT THE Binary value VECTOR IF NEEDED
    /* 
    vector<int>::iterator it;
    cout<<endl;
    for(it = binaryValue.begin(); it != binaryValue.end(); it++) {
        cout<<*it;
    }
    cout<<endl;  
   */
   
    cout<<endl;

}


//prints the result of the conversion
void printResult(vector<string> result) {
    vector<string>::iterator it;
    
    for (it = result.begin(); it != result.end(); it++) {
        if((it+1) == result.end()) {
            cout<<*it;
        }
        else {
        cout<<*it<<" ";
        }
    }
}

//takes a binary number and converts it to unary
vector<string> encode(vector<int> binaryValue) {
    vector<int> binValue = binaryValue;
    vector<string> result;
    int oneCount = 0;
    int zeroCount = 0;
    
    vector<int>::iterator it;
    for(it = binValue.begin(); it != binValue.end(); it++) {
      /*cout<<"zerocount"<<zeroCount<<endl;
        cout<<"OneCount"<<oneCount<<endl;
        cout<<"IT = "<<*it<<endl;
        */
        if(*it == 1) {
            if(zeroCount != 0) {
            vector<char> temp;
            for (int i = 0; i < zeroCount; i++) {
             
                temp.push_back('0');
            }
            string tempstr(temp.begin(), temp.end());
            result.push_back(tempstr);
            zeroCount = 0;
            }
            
            if(oneCount==0) {
                result.push_back("0");
                ++oneCount;
                continue;
            }
            oneCount++;
           
        }
        else if(*it == 0) {
            if(oneCount != 0) {
            vector<char> temp;
            for (int i = 0; i < oneCount; i++) {
                temp.push_back('0');
            }
            string tempstr(temp.begin(), temp.end());
            result.push_back(tempstr);
            oneCount = 0;
            }
            
            if(zeroCount==0) {
                result.push_back("00");
                ++zeroCount;
                continue;
            }
            ++zeroCount;
        }
        
        if (((it+1) == binValue.end()) && (oneCount != 0 || zeroCount != 0)) {
            if(zeroCount) {
                vector<char> temp;
                for (int i = 0; i < zeroCount; i++) {
                    temp.push_back('0');
                }
                string tempstr(temp.begin(), temp.end());
                result.push_back(tempstr);
                zeroCount = 0;
            }
            else if (oneCount) {
                vector<char> temp;
                for (int i = 0; i < oneCount; i++) {
                    temp.push_back('0');
                }
                string tempstr(temp.begin(), temp.end());
                result.push_back(tempstr);
                oneCount = 0;
            }
        }
    }
    return result;
}

//converts the ASCII char code to binary
void toBinary(int value) {
    while(value > 0) {
        binaryValue.push_back(value%2);
        value = value / 2;
    } 
}
    
    