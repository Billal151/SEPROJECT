#include "head.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <gdbm.h>

//start
using namespace std;

int cnt() //initialise and assign the count variable. Count is assigned to the total number of lines in the input text file
{
    string line, data1, data2;
    ifstream myfile ("lab3Input.txt");
    int count =0;
    
    while ( getline (myfile,line) )
    {
        count = count +1;
    }
    
    return count;
}

int main () {
    
     GDBM_FILE file;
    //Initializes gdbm system. If the file has a size of zero bytes, a file initialization procedure is performed, setting up the initial structure in the file.
    file = gdbm_open("myDB",0, GDBM_WRCREAT | GDBM_READER, 0660, 0);
    
    
    vector<datum> vec;
    datum key1, data3, ndata1;
    string line, data1, data2;
    int keydata, x=0, count = 0, count1 = 0;
    
    
    ifstream myfile ("lab3Input.txt"); //Initialise input stream class to operate on files.
    
    if (myfile.is_open()) //Check if a file is open. Returns whether the stream is currently associated to a file.
    {
        count = cnt();
        
        int carray[count];
        string k, var;
        do
        {
            cout << "Please enter ASC (for ascending order) or DESC (for descending order): \n";
            cin >> k;
        } while((k.compare("desc") && (k.compare("DESC")) && (k.compare("asc")) && (k.compare("ASC"))));
        
        while ( getline (myfile,line) )
        {
            data1= line.substr(0,6);
            data2= line.substr(8,100);
            keydata = stoi(data1);
            carray [x] = keydata;
            
            char *k = new char[data1.length() + 1];
            strcpy(k, data1.c_str());
            char *d = new char[data2.length() + 1];
            strcpy(d, data2.c_str());
            
            key1.dptr = k;
            key1.dsize = data1.length() + 1;
            
            data3.dptr = d;
            data3.dsize = data2.length() + 1;
            
            gdbm_store(file, key1, data3, GDBM_INSERT); //The function gdbm_store inserts or replaces records in the database
            vec.push_back(key1);   //Adds a new element at the end of the vector, after its current last element.
            
            x++;
        }

        
        datum ex1;
        int n = vec.size();
        int A[n];
        
        for (int i = 0; i < n; i++){
            A[i] = stoi(vec[i].dptr); //Convert string to integer
        }
        
        quickSort(A,n,k);
        
        vector<int> C;
        vector<int> ERRORS;
        cout << "\nDuplicate entries in the input file:\n" << endl;
        C.push_back(A[0]);
        
        for (int i = 0; i < n; i++){
            if (A[i]!= A[i+1]){
                C.push_back(A[i+1]);
                count1++;
            }
            else if(A[i] == A[i+1])
            {
                ERRORS.push_back(A[i]);
            }
        }
        
        int errorcount = n-count1;
        
        for(int i=0; i<errorcount; i++){
            cout << ERRORS[i] <<endl;
            
        }
        
        
        int D[C.size()];
        n = C.size();
        for (int i = 0; i < n; i++){
            D[i] = C[i];
        }
        
        
        cout << "\nThe first 15 records in the gdbm store are: \n" << endl;
        
        for (int i = 0; i < 15; i++){
            var = to_string(carray[i]);
            char *v = new char[var.length() + 1];
            strcpy(v, var.c_str());
            
            key1.dptr = v;
            key1.dsize = var.length() + 1;
            
            ex1 = gdbm_fetch(file, key1);
            cout << key1.dptr << " " << ex1.dptr << endl;
        }
        
        cout << "\nThe last 15 records in the gdbm store are: \n" << endl;
        for (int i = n-15; i < n; i++){
            var = to_string(carray[i]);
            char *v = new char[var.length() + 1];
            strcpy(v, var.c_str());
            
            key1.dptr = v;
            key1.dsize = var.length() + 1;
            
            ex1 = gdbm_fetch(file, key1);
            cout << key1.dptr << " " << ex1.dptr << endl ;
        }
        
        
        
        
        ofstream fs;
        fs.open("lab3Output.txt", ofstream::out);
        fs << "The first 15 records in the gdbm store (in sorted " << k << " order) are: \n\n";
        cout << "\nThe first 15 records in the gdbm store (in sorted " << k << " order) are : \n" << endl;
        for (int i = 0; i < 15; i++){
            var = to_string(D[i]);
            char *v = new char[var.length() + 1];
            strcpy(v, var.c_str());
            
            key1.dptr = v;
            key1.dsize = var.length() + 1;
            
            ex1 = gdbm_fetch(file, key1);
            fs << key1.dptr << " " << ex1.dptr << endl;
            cout << key1.dptr << " " << ex1.dptr << endl;
        }
        
        fs << endl << endl;
        fs << "The last 15 records in the gdbm store (in sorted " << k << " order) are : \n\n";
        cout << "\nThe last 15 records in the gdbm store (in sorted " << k << " order) are : \n\n" << endl;
        for (int i = n-15; i < n; i++){
            var = to_string(D[i]);
            char *v = new char[var.length() + 1];
            strcpy(v, var.c_str());
            
            key1.dptr = v;
            key1.dsize = var.length() + 1;
            
            ex1 = gdbm_fetch(file, key1);
            fs << key1.dptr << " " << ex1.dptr << endl;
            cout << key1.dptr << " " << ex1.dptr << endl ;
        }
        
        fs.close();
        gdbm_close(file);	
        
		
    }
    else cout << "Unable to open file"; 
    myfile.close();
    return 0;
}
