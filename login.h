#include<bits/stdc++.h>
using namespace std;
/*QByteArray AESWrapper::md5 ( const QByteArray& data) {
    unsigned char * tmp_hash;
    tmp_hash = MD5((const unsigned char*)data.constData(), data.length(), NULL);
    return QByteArray((const char*)tmp_hash, MD5_DIGEST_LENGTH);
}*/


#include "md5.h"

using std::cout; using std::endl;


void new_application();
void create_all_files_new();

int game()
{
    string ki="bnmsi46fvndfkjgrs7";
    cout << "md5 of 'grape': " << md5(ki) << endl;
    string mi;
    mi=md5("AP21110010413");
    cout<<mi<<endl;
    int k;
    cin>>k;
    return 0;
}

//sriram AP21110010410
//harshni AP21110010435
// yashwanthi AP21110010437
// vamsi AP21110010413

void new_application()
{
    ifstream f;
    string g;
    char c[999];
    f.open("login1.txt");
    if(f.good()){

    }
    else{
        create_all_files_new();
    }
    f.close();
}

void create_all_files_new()
{
    cout<<"HI New User\n\n\n"<<endl;
    ofstream fi;
    string user,pass;
    int n;
    fi.open("login.txt");
    fi.close();
    fi.open("bills.txt");
    fi.close();
    fi.open("pl.txt");
    fi.close();
    fi.open("customer.txt");
    fi.close();
    fi.open("supplier.txt");
    fi.close();
    fi.open("medicines.txt");
    fi.close();
    fi.open("login.txt");
    cout<<"Enter number of new users"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter user name: "<<endl;
		cin>>user;
		cout<<"enter password for user name: "<<endl;
		cin>>pass;
		pass=md5(pass);
        user=md5(user);
        fi<<user<<" "<<pass<<endl;
    }
    fi.close();
}

void pass()
{
    ifstream x("login.txt");
    string username,user,mike;
        string password,pass;


        cout<<"\t\t\t\t\t\tLOGIN TO SRM AP MEDICAL STORE\n\n"<<endl;




            cout<<"\t\t\t\t**********************************************************"<<endl;
            cout<<"\t\t\t\t\t\t    Enter username: ";
            cin>>username;
            cout<<"\t\t\t\t\t\t    Enter password: ";
            cin>>password;
            cout<<"\t\t\t\t********************************************************"<<endl;
            password=md5(password);
            mike=username;
            username=md5(username);
            int temp=0;
            while(x>>user)
            {
                x>>pass;
                if(username==user && password==pass)
                {
                    temp=1;
                    //mike=user;
                    break;
                }
                else if(username!=user && password==pass)
                {
                    temp=2;
                }
                else if(username==user && password!=pass)
                {
                    temp=3;
                }
            }
            if(temp==0)
            {
                cout<<"User not found"<<endl;
            }
            else if(temp==2)
            {
                cout<<"Check username"<<endl;
            }
            else if(temp==3)
            {
                cout<<" Opps! Incorrect password"<<endl;
            }
            else if(temp==1){
                    cout<<"Sucess"<<endl;
                cout<<"user found"<<endl;
                cout<<endl;
                    cout<<"login sucessfull\nwelcome "<<mike<<"\a\a\a\a\a\a\a\a"<<endl;
            }
		string makx;
		cout<<"Enter any key to proceed: "<<endl;
		cin>>makx;
        if(temp==3||temp==0||temp==2){
            exit(0);
        }

}
