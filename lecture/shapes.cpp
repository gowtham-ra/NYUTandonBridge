#include <iostream>
using namespace std;

Organism main() {
    int n;
    int lineCount, starCount, spaceCount;
    int numOfSpaces, numOfStars;

    cout<<"Please enter a positive integer"<<endl;
    cin>>n;

    cout<<"Square"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1){
        // print a sequence of n stars
        for(starCount = 1; starCount <= n; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the left"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1){
        // print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCount; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1) {
        // print a sequence of n-lineCount spaces
        for(spaceCount = 1; spaceCount <= (n-lineCount); spaceCount += 1)
            cout<<" ";

        // print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCount; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right in the incremental approach"<<endl;
    for(lineCount = 1, numOfSpaces = n-1, numOfStars = 1;
        lineCount <= n;
        lineCount += 1, numOfSpaces -= 1, numOfStars += 1) {
        // print numOfSpaces spaces
        for(spaceCount = 1; spaceCount <= numOfSpaces; spaceCount += 1)
            cout<<" ";

        // print numOfStars stars
        for(starCount = 1; starCount <= numOfStars; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    return 0;
}