#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
using namespace std;

vector <int> randomRange(int sizeRange){
    vector <int> range;
    while(range.size() != sizeRange){
        int random = rand() % sizeRange;
        bool valid = true;

        for(int number : range) if(number == random) valid = false;
        if(valid) range.push_back(random);
    }
    return range;
}

int main() {
    string message = "I love to programming in c++";
    string key = "crazy";
    vector <int> numericalSerie;
    vector <string> messageFragmented;
    vector <int> randomIndexs;

    srand(time(0));

    int limit = key.length();
    int rows = ceil((double) message.length() / (double) limit);
    int lettersToSort = limit * rows;

    numericalSerie = randomRange(limit);
    randomIndexs = randomRange(rows);

    int noSpaces = lettersToSort - message.length();
    if(noSpaces != 0)
        for(int s = 0; s < noSpaces; s++)
            message += ' ';

    //FRAGMENTAR LA PALABRA
    string fragment = "";
    for(int i = 0; i < lettersToSort; i++){
        fragment += message[i];
        if((i + 1) % limit == 0){
           messageFragmented.push_back(fragment);
           fragment = "";
        }
    }

    string newMessage = "";
    /*
    // according to the fragmented sort
    for(string frag : messageFragmented){
        for(int randNum : numericalSerie){
            newMessage += frag[randNum];
        }
    }*/
    // random sort of the random indexs
    for(int ind = 0; ind < randomIndexs.size(); ind++){
        string frag = messageFragmented[ randomIndexs[ind] ];
        for(int randNum : numericalSerie) newMessage += frag[randNum];
    }

    cout << newMessage << " ";
    return 0;
}
