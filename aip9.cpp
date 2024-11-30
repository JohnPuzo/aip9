#include <iostream>
using namespace std;
#include <string>
#include <cctype>


int substr(int k1,string mas1[], string mas2[],int nom[]){
    string num = "0123456789";
    int  n, i, j, j1, k2=0; 
    for( i=0; i<k1;++i)  
    {
        j = 0; 
        n = mas1[i].length(); 
        j1 = -1; 
        while (j < n )
            if (num.find(mas1[i][j]) != -1){
                if (j1 != -1){
                    mas2[k2].assign(mas1[i], j1, j-j1);
                    nom[k2++]=i;
                }
		        while (num.find(mas1[i][j]) != -1) 
                    j ++; 
                j1 = j;    
		    }
            else 
                j ++; 
    }
    return k2;
}

int nompodstr(int k2, string mas2 []){
    int  i, j, max=0, maxi=-1, num; 
    for(i=0; i<k2;++i){
        num = 0;
        j=mas2[i].length()-1;
        while (mas2[i][j] == '.'){
            j--;
            num++;
        }	  
        if (num > max){
            max = num;      
            maxi = i;
        }
    }  
    return maxi; 
}

bool change(string &s){
    bool f = false;
    if (s.find("begin") != -1 or s.find("end") != -1){
        f = true;
        while (s.find("begin") != -1){
            s.replace(s.find("begin"), 5, "{");
        }
        while (s.find("end") != -1){
            s.replace(s.find("end"), 3, "}");
        }
    }
    return f; 
}

void dop(string sub){
    string s;
    int i=0;
    cout << "Enter new string:"<<endl;
    getline(cin, s);
    if (s.length() != sub.length())
        cout << "new string in not an anogram of substring"<<endl;
    else{
        while(i<sub.length() and s.find(sub[i]) != -1){
            s.erase(s.find(sub[i]), 1);
            i++;
        }
        if (i == sub.length())
            cout << "new string is an anogram of substring"<<endl;
        else
            cout << "new string is not an anogram of substring"<<endl;
    }
}

int main()
{
    int num,i,k1=0,k2;
    string s;
    do{
        cout << "Enter number of lines: ";               
        cin >> k1; 
        if (cin.fail())    
            cin.clear(); 
        getline(cin,s) ;          
    }while (k1<=0);
    int nom[5*k1];
    string mas1[k1],mas2[5*k1];
    cout<<"Enter "<<k1<<" strings"<<endl;
    for( i=0; i<k1;++i) 
        getline(cin,mas1[i]);
    k2=substr(k1, mas1,  mas2, nom);
    if (k2 == 0) 
        cout<<"No substrings"<<endl;
    else{
        cout<<"Substrings:"<<endl;
        for(i=0; i<k2; ++i) 
            cout<<mas2[i]<<endl;
        num=nompodstr(k2, mas2);
        if (num==-1)  
            cout<<"No necessary substrings"<<endl;
        else{
            cout<<"Necessary substring:  "<<mas2[num]<<endl;
            cout<<mas1[nom[num]]<<" changes into:"<<endl;
            if (change(mas1[nom[num]]))
                cout<< mas1[nom[num]] ;
            else 
                cout<<"No changes in string"<<endl;
            dop(mas2[num]);
        }
    }
    return 0;
}



