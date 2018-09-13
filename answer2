#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
#include<time.h>
#include<hash_fun.h>
#define Date char*
#define String node*
using namespace std;

struct node
{
    Date timestamp;
    string data;
    int nodeNumber;
    String nodeId;
    String referenceNodeId;
    vector<String> childReferenceNodeId;
    String genesisReferenceNodeId;
    string HashValue;
} *genesis;

long long int nodeNumber=0;

//computes the hash for a node
string computeHash()
{
    string res;
    res="created by naman";
    return res;
}

//computes the data for a node
string computeData(string val)
{
    return val;
}

//converts a string to int
int stringToInt(string s)
{
    int ans=0;

    for(int i=0; i<s.length(); i++)
    {
        int digit = s[i]-'0';
        ans=ans*10 + digit;
    }
    return ans;
}

//coverts an int to string
string intToString(int val)
{
    string ans;

    while(val!=0)
    {
        int digit = val%10;
        char c = (digit+'0');
        ans = ans + c;
        val/=10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//creates a new node with given value
node* createNode(String parentNode, string val)
{
    node *temp = new node;
    time_t t = time(NULL);
    temp->timestamp = ctime(&t);
    temp->nodeId = temp;
    temp->nodeNumber = ++nodeNumber;
    temp->referenceNodeId = parentNode;
    temp->HashValue = computeHash();
    temp->genesisReferenceNodeId = genesis;
    temp->childReferenceNodeId.push_back(NULL);
    temp->data = computeData(val);
    if(parentNode!=NULL)
    {
        parentNode->childReferenceNodeId.push_back(temp);
    }
    return temp;
}

//returns height of the node from any point
int height(String root)
{
    if(root==NULL)
        return 0;
    int ans = 0;
    for(int i=0; i<root->childReferenceNodeId.size(); i++)
        ans=max(height(root->childReferenceNodeId[i]), ans);

    return ans+1;
}

//edits the value of a given order
bool editValue(String root, string newVal)
{
    int sum = 0;
    int childCount = root->childReferenceNodeId.size();
    for(int i=0; i<childCount; i++)
        if(root->childReferenceNodeId[i]!=NULL)
            sum+=stringToInt(genesis->childReferenceNodeId[i]->data);
    if(stringToInt(newVal)>= sum)
    root->data = newVal;
    else
    {
        cout << "Child nodes have greater value than parent!" << endl;
        return false;
    }

    return true;
}

//shows children of any given order
void showChildren(String root)
{
    int childCount = root->childReferenceNodeId.size();
    for(int i=0; i<childCount; i++)
        if(root->childReferenceNodeId[i]!=NULL)
            cout << genesis->childReferenceNodeId[i]->data << " ";
    cout << endl;
}

//merge order2 into order1
bool merge(String order1, String order2)
{
    //update value of the node
    int newdata = stringToInt(order1->data) + stringToInt(order2->data);
    order1->data = intToString(newdata);
    //merge the children
    for(int i=0; i<order2->childReferenceNodeId.size(); i++)
        if(order2->childReferenceNodeId[i]!=NULL)
            order1->childReferenceNodeId.push_back(order2->childReferenceNodeId[i]);
    String parentOfOrder2 = order2->referenceNodeId;
    int childCount = parentOfOrder2->childReferenceNodeId.size();
    for(int i=0; i<childCount; i++)
        if(order2== parentOfOrder2->childReferenceNodeId[i])
        {
            cout << "Removed memory traces of the old node..";
            parentOfOrder2->childReferenceNodeId[i]=NULL;
            break;
        }
    return true;
}

int main()
{
    //create genesis node
    cout << "First we create genesis node" << endl;
    string data;
    cout << "Enter data for genesis node: ";
    cin >> data;
    genesis = createNode(NULL,data);
    cout << "Genesis node creation completed!" <<endl;
    //create set of child nodes
    int n;
    cout << "Enter number of child nodes you want: ";
    cin >> n;
    int maxVal = stringToInt(genesis->data);
    cout << "Value of parent node: " << maxVal << endl;
    int sum=0;
    int i=0;
    while(i<n)
    {
        cout << "Enter value for child node: ";
        cin >> data;
        if(!(sum+stringToInt(data)>maxVal))
        {
            createNode(genesis,data);
            i++;
            sum+=stringToInt(data);
        }
        else
        cout << "You have exceeded the parent nodes limit!" << endl;
    }
    cout << "Child node values are: ";
    /*
    for(int i=0; i<n+1; i++)
        if(genesis->childReferenceNodeId[i]!=NULL)
            cout << genesis->childReferenceNodeId[i]->data << " ";
    cout << endl;
    */
    showChildren(genesis);
    //create child for any particular node
    String anyRandomNode = genesis->childReferenceNodeId[genesis->childReferenceNodeId.size()-1];
    maxVal = stringToInt(anyRandomNode->data);
    cout << endl << endl;
    cout << "Value of parent node: " << maxVal << endl;
    cout << "Creating child of this parent node.." << endl;
    while(1)
    {
        cout << "Enter value for child node: ";
        cin >> data;
        if(stringToInt(data)<=maxVal)
        {
            node *temp = createNode(anyRandomNode, data);
            cout << "Successfully entered value in random node: " << temp->data << endl;
            break;
        } else
            cout << "Limit exceeded!" << endl;
    }
    //height of node
    cout << endl << endl;
    cout << "Height of the order from genesis is: " << height(genesis) << endl;
    cout << "Height of the order from any random point is: " << height(genesis->childReferenceNodeId[genesis->childReferenceNodeId.size()-1]) << endl;
    cout << endl << endl;

    cout << "Editing value of genesis node.." << endl;
    cout << "Value before modification: " << genesis->data << endl;
    while(1)
    {
        cout << "Enter new data to be entered: ";
        cin >> data;
        if(editValue(genesis, data))
            break;
    }

    cout << "Value after modification: " << genesis->data << endl;
    cout << endl << endl;
    String order1=genesis;
    String order2 = genesis->childReferenceNodeId[genesis->childReferenceNodeId.size()-1];
    cout << "Merging genesis and one of its child nodes.." << endl;
    cout << "Value of genesis before merge: " << genesis->data << endl;
    cout << "Children of genesis before merge: " << endl;
    showChildren(genesis);
    merge(order1,order2);
    cout << endl;
    cout << "Value of genesis after merge: " << genesis->data << endl;
    cout << "Children of genesis after merge: " << endl;
    showChildren(genesis);
    return 0;
}
