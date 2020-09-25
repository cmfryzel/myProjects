#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void merge(int array1[], int array1Len, int array2[], int array2Len, int array3[], int array3Len)
{
    int array1In= 0, array2In = 0, array3In = 0;

    while(array1In<array1Len && array2In<array2Len)
    {
        if(array1[array1In]<array2[array2In])
        {
            array3[array3In] = array1[array1In];
            array3In++;
            array1In++;
        }
        else
        {
            array3[array3In] = array2[array2In];
            array3In++;
            array2In++;
        }
        
    }
    while(array1In<array1Len)
    {
        array3[array3In] = array1[array1In];
        array3In++;
        array1In++;
    }
    while(array2In<array2Len)
    {
        array3[array3In] = array2[array2In];
        array3In++;
        array2In++;
    }
}

void merge(string array1[], int array1Len, string array2[], int array2Len, string array3[], int array3Len)
{
    int array1In= 0, array2In = 0, array3In = 0;

    while(array1In<array1Len && array2In<array2Len)
    {
        if(array1[array1In]<array2[array2In])
        {
            array3[array3In] = array1[array1In];
            array3In++;
            array1In++;
        }
        else
        {
            array3[array3In] = array2[array2In];
            array3In++;
            array2In++;
        }
        
    }
    while(array1In<array1Len)
    {
        array3[array3In] = array1[array1In];
        array3In++;
        array1In++;
    }
    while(array2In<array2Len)
    {
        array3[array3In] = array2[array2In];
        array3In++;
        array2In++;
    }
}

void mergesort(int array[], int length)
{
    if(length >1)
    {
        int left[length/2];
        int right[length-length/2];
        for(int i = 0; i<length/2; i++)
        {
            left[i] = array[i];
        }
        for(int i = 0; i<length-length/2; i++)
        {
            right[i] = array[i+length/2];
        }
        mergesort(right, length-length/2);
        mergesort(left, length/2);
        merge(left, length/2, right, length-length/2, array, length);
    }
}

void mergesort(string array[], int length)
{
    if(length >1)
    {
        string left[length/2];
        string right[length-length/2];
        for(int i = 0; i<length/2; i++)
        {
            left[i] = array[i];
        }
        for(int i = 0; i<length-length/2; i++)
        {
            right[i] = array[i+length/2];
        }
        mergesort(right, length-length/2);
        mergesort(left, length/2);
        merge(left, length/2, right, length-length/2, array, length);
    }
}

int main(int argc, char** argv)
{
    fstream file1;
    fstream file2;
    string fileName1, fileName2;



    //name of file
    fileName1 = argv[2];
    fileName2 = argv[3];

    //open file
    file1.open(fileName1.c_str());
    file2.open(fileName2.c_str());

    if(argv[1][0]=='i')
    {
        int file1Count =0;
        while(!file1.eof())
        { 
            int temp;
            file1 >> temp;
            if(file1.fail())
            {
                break;
            }
            file1Count++;
        }
        int file1Numbers [file1Count];
        file1.clear();
        file1.seekg(0);
        int i = 0;
        while(!file1.eof())
        {
            file1 >> file1Numbers[i];
            if(file1.fail())
            {
                break;
            }
            i++;
        }
        int file2Count =0;
        while(!file2.eof())
        { 
            int temp;
            file2 >> temp;
            if(file2.fail())
            {
                break;
            }
            file2Count++;
        }
        int file2Numbers [file2Count];
        file2.clear();
        file2.seekg(0);
        i = 0;
        while(!file2.eof())
        {
            file2 >> file2Numbers[i];
            if(file2.fail())
            {
                break;
            }
            i++;
        }
        mergesort(file1Numbers, file1Count);
        mergesort(file2Numbers, file2Count);
        for(int i=0; i<file1Count; i++)
        {
            for(int j = 0; j<file2Count; j++)
            {
                if(file1Numbers[i]==file2Numbers[j] && (i==0 || file1Numbers[i]!=file1Numbers[i-1]) && (j==0 || file2Numbers[j]!=file2Numbers[j-1]))
                {
                    cout << file1Numbers[i] << endl;
                }
            }
        }
    }
    else
    {
        int file1Count =0;
        while(!file1.eof())
        { 
            string temp;
            file1 >> temp;
            if(file1.fail())
            {
                break;
            }
            file1Count++;
        }
        string file1Words [file1Count];
        file1.clear();
        file1.seekg(0);
        int i = 0;
        while(!file1.eof())
        {
            file1 >> file1Words[i];
            if(file1.fail())
            {
                break;
            }
            i++;
        }
        int file2Count =0;
        while(!file2.eof())
        { 
            string temp;
            file2 >> temp;
            if(file2.fail())
            {
                break;
            }
            file2Count++;
        }
        string file2Words [file2Count];
        file2.clear();
        file2.seekg(0);
        i = 0;
        while(!file2.eof())
        {
            file2 >> file2Words[i];
            if(file2.fail())
            {
                break;
            }
            i++;
        }
        mergesort(file1Words, file1Count);
        mergesort(file2Words, file2Count);
        for(int i=0; i<file1Count; i++)
        {
            for(int j = 0; j<file2Count; j++)
            {
                if(file1Words[i]==file2Words[j] && (i==0 || file1Words[i]!=file1Words[i-1]) && (j==0 || file2Words[j]!=file2Words[j-1]))
                {
                    cout << file1Words[i] << endl;
                }
            }
        }
    }
    
}