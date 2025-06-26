#include <iostream>

using namespace std;


//function of TOH
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if(n==1)
    {
        cout<<"Move disk 1 from "<<source<<" to " <<destination<<endl;
        return;
    }
        // Recursive case:
    // Step 1: Move top n-1 disks from source to auxiliary
    towerOfHanoi(n-1,source,auxiliary,destination);
    // Step 2: Move the nth disk from source to destination
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    // Step 3: Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n-1,auxiliary,destination,source);

}



int main()
{
    int n;
    cout<<" Enter the number of disks: ";
    cin>>n;
    towerOfHanoi(n,'A','C','B');
    return 0;
}
