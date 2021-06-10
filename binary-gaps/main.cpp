#include <iostream>
#include <vector>
using namespace std;
int solution(int N);

int main()
{
    
    long int number;
    int sequence = 0;
    cout<<"Enter Decimal value ";
    cin>>number;
    cout<<endl;
    sequence = solution(number);
    cout<<"The longest sequence is "<<sequence<<endl;
    
}

int solution(int N)
{
    vector <int> binary_sequence;
    bool startCounting = false;
    int counter = 0;
    int longestSequence = 0;
    //Conversion of Decimal number to Binary sequence
    while(N > 0)
    {
        int remain = N%2;
        binary_sequence.push_back(remain);
        N/=2;
    }
    //Converted to the following sequence
    //int i=0; i<binary_sequence.size(); i++
    cout<<"The Converted sequence is: ";
    for(int i=binary_sequence.size()-1; i>=0; i--){
        cout<<binary_sequence.at(i);
    }
    cout<<endl<<endl;

    //Counting the longest Sequence
    for(int i=binary_sequence.size()-1; i>=0; i--){

        //Check if Counting should start or stop
        if(binary_sequence.at(i) == 1 && startCounting == false){
            cout<<"Found 1 Starting Counting..."<<endl;
            startCounting = true;
            continue;
        }

        //If counting has started, increment the counter
        else if (binary_sequence.at(i) == 0 && startCounting == true){
            cout<<"Incrementing COunter"<<endl;
            counter++;
            continue;
        }
        
        else if (binary_sequence.at(i) == 1 && startCounting == true){
            if(counter < 1){
                cout<<"Nothing to do"<<endl;
                continue;
            }
            cout<<"Found 1 again. Stopping Counting..."<<endl;
            if(counter > longestSequence){
                longestSequence = counter;
            }
            
            counter = 0;
        }

    }


    return longestSequence;
}