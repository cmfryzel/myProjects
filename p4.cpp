#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Node{
 public:   
    int value = 0;
    Node* left;
    Node* right;

};

Node* order(vector<int> in, vector<int> post){
    if(in.size()==0){
        return nullptr;
    }

    int root = post[post.size()-1];
    int rootIn;

    for(int i = 0; i<in.size(); i++){
         if(root == in[i]){
             rootIn = i;
         }
    }
    vector<int> leftIn;
    vector<int> rightIn;
    vector<int> rightPost;
    vector<int> leftPost;

    for(int i = 0; i<in.size(); i++)
    {
        if(i<rootIn){
            leftIn.push_back(in[i]);
            leftPost.push_back(post[i]);
        }
        if(i>rootIn){
            rightIn.push_back(in[i]);
            rightPost.push_back(post[i-1]);
        }
    }
    
    Node* node = new Node;
    node->value = root;
    node->left = order(leftIn, leftPost);
    node->right = order(rightIn, rightPost);
    return node;
}

int main(int argc, char** argv){


fstream file1;
fstream file2;
fstream file3;

file1.open(argv[1]);
file2.open(argv[2]);
file3.open(argv[3]);

vector<int> inorder;
vector<int> postorder;


while(!file1.eof())
{
    int t;
    file1 >> t;
    if (file1.fail())
    {
        break;
    }
    inorder.push_back(t);
}

while(!file2.eof())
{
    int t;
    file2 >> t;
    if (file2.fail())
    {
        break;
    }
    postorder.push_back(t);
}

Node* tree = order(inorder, postorder);
Node* curTree = tree;

while(!file3.eof())
{
    char t;
    file3 >> t;
    if (file3.fail())
    {
        break;
    }
    if(t=='0' || t=='1'){
        if(t=='0'){
            curTree=curTree->left;
        }
        if(t=='1'){
            curTree=curTree->right;
        }
        if(curTree->value<128){
            cout << char(curTree->value);
            curTree = tree;
        }
    }
}


}