//
//  main.cpp
//  lb
//
//  Created by Zhenya Shumskiy on 2/25/20.
//  Copyright © 2020 Zhenya Shumskiy. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin;
    fin.open("/Users/evgeniy/lb/lb/file_1.txt");
    ofstream fout;
    fout.open("/Users/evgeniy/lb/lb/file_2.txt");
    char A[512];
    char B[12] = {'a','e','i','o','u','y','A','E','I','O','U','Y'};
    int count = 0;
    while(!fin.eof()){
        if(fin.get() == '\n')
            count++;
    }
    
    fin.ios_base::clear();
    fin.seekg(0);
    
    
    int n = 2, k = 4, countL = 0;
    for(int i = 0; i < count; i++){
        fin.getline(A, 512);
        if(i >= n - 1 && i <= k - 1){
            for(int j = 0; j < sizeof(A); j++)
                for(int k = 0; k < sizeof(B); k++)
                    if(A[j] != B[k]){
                        countL++;
                        cout << A[j] << endl;
                    }
            fout << A;
            fout << "\n";
        }
    }
    
    printf("\n\n\tgl: %d\n\n", countL);
    
    fout.close();
    fin.close();
    return 0;
}
