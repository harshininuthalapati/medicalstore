#include<bits/stdc++.h>
using namespace std;

class supplier;
class medicine_suply;
class customer;
void create_customer();
void create_supplier();
void write_customer();
void write_supplier();
void add_supplier();
void display_supplier_info();
void display_customer_data();
void purchasedata_of_cust();

vector<customer> customer_list;
vector<supplier> supplier_list;
int max_sup_id=0;


class medicine_suply{
    string name;
    int quantity;
    float cost;
    public:
    friend void create_supplier();
    void display()
    {
       cout<<"NAME : "<<name<<endl;
       cout<<"QUANTITY : "<<quantity<<endl;
       cout<<"TOTAL COST :"<<cost<<endl;
    }
    friend void create_bill_list();
    friend void write_supplier();
    friend void write_bill();
    medicine_suply(string &na,int &q, float &c){
        name=na;
        quantity=q;
        cost=c;
    }
    medicine_suply(){}
    friend void display_med_supplied();
    friend void purchasedata_of_cust();
    friend void bill_display_print();
};

class supplier{
    int id;
    string ph;
    string name;
    vector<medicine_suply> medicines_supplied_list;
    public:
    supplier(){}
    friend void create_supplier();
    friend void display_supplier_info();
    void display()
        {
            cout<<"ID : "<<id<<endl;
            cout<<"NAME : "<<name<<endl;
            cout<<"PHONE NUMBER : "<<ph<<endl;
            for(int i=0;i<medicines_supplied_list.size();i++){
                cout<<"---------------------------------------"<<endl;
                medicines_supplied_list[i].display();
            }
        }
    supplier(int id,string na,string ph){
        this->id=id;
        name=na;
        this->ph=ph;
    }
    friend void write_supplier();
    friend void order_from_supplier();
    friend void add_supplier();
    friend void display_med_supplied();

};

class customer{
    protected:
        string id;
        string ph;
        string name;
    public:
        friend void create_customer();
        friend void purchasedata_of_cust();
        customer(){}
        void display()
        {
            cout<<"ID : "<<id<<endl;
            cout<<"NAME : "<<name<<endl;
            cout<<"PHONE NUMBER : "<<ph<<endl;
        }
        customer(string i, string na, string pn)
        {
            id=i;
            name=na;
            ph=pn;
        }
        friend void write_customer();
        friend void display_customer_data();
        friend void bill_display_print();
};

//customer.txt format
/*
    id
    name
    phone
*/

void create_customer()
{
    ifstream file;
    file.open("customer.txt");
    string id,ph,name;
    int i=0,n=0;
    while(getline(file,id))
    {
        //cout<<"--------------------------------------------------------------"<<endl;
        getline(file,name);
        getline(file,ph);
        customer o;
        o.id=id;
        o.ph=ph;
        o.name=name;
        n++;
        customer_list.resize(n);
        customer_list[i]=o;
        i++;
    }
    file.close();
    /*ofstream fi;
    fi.open("customer.txt",ios::app);
    while(1){
        cout<<"Enter -1 to exit"<<endl;
        getline(cin,na);
        if(na==b)
            break;
        cout<<"Enter id: "<<endl;
        getline(cin,na);
        fi<<na<<endl;
        cout<<"Enter name: ";
        getline(cin,na);
        fi<<na<<endl;
        cout<<"Enter Phone number: ";
        getline(cin,na);
        fi<<na<<endl;
    }
    fi.close();*/
}
void create_supplier()
{
    ifstream file;
    file.open("supplier.txt");
    int dum=0;
    string id,ph,name,k;
    int i=0,n=0,num,j=0,kl=0;
    while(getline(file,id))
    {
        //cout<<"--------------------------------------------------------------"<<endl;
        getline(file,name);
        getline(file,ph);
        supplier o;
        o.id=stoi(id);
        dum=stoi(id);
        o.ph=ph;
        o.name=name;
        getline(file,k);
        num=stoi(k);
        if(dum>max_sup_id)
        {
            max_sup_id=dum;
        }
        for(int inte=0;inte<num;inte++){
            medicine_suply m;
            getline(file,k);
            m.name=k;
            getline(file,k);
            m.quantity=stoi(k);
            getline(file,k);
            m.cost=stoi(k);
            kl++;
            o.medicines_supplied_list.resize(kl);
            o.medicines_supplied_list[j]=m;
            j++;
        }
        n++;
        supplier_list.resize(n);
        supplier_list[i]=o;
        i++;
        j=0;
        kl=0;
    }
    file.close();
    /*ofstream fi;
    fi.open("customer.txt",ios::app);
    while(1){
        cout<<"Enter -1 to exit"<<endl;
        getline(cin,na);
        if(na==b)
            break;
        cout<<"Enter id: "<<endl;
        getline(cin,na);
        fi<<na<<endl;
        cout<<"Enter name: ";
        getline(cin,na);
        fi<<na<<endl;
        cout<<"Enter Phone number: ";
        getline(cin,na);
        fi<<na<<endl;
    }
    fi.close();*/
}

void write_customer()
{
    string na;
    int b=-1;
    ofstream fi;
    fi.open("customer.txt");
    for(int i=0;i<customer_list.size();i++)
    {
        fi<<customer_list[i].id<<endl;
        fi<<customer_list[i].name<<endl;
        fi<<customer_list[i].ph<<endl;
    }
    fi.close();
}

void write_supplier()
{
    string na;
    int num;
    ofstream fi;
    fi.open("supplier.txt");
    for(int j=0;j<supplier_list.size();j++)
    {
        fi<<supplier_list[j].id<<endl;
        fi<<supplier_list[j].name<<endl;
        fi<<supplier_list[j].ph<<endl;
        num=supplier_list[j].medicines_supplied_list.size();
        fi<<num<<endl;
        for(int i=0;i<num;i++)
        {
            fi<<supplier_list[j].medicines_supplied_list[i].name<<endl;
            fi<<supplier_list[j].medicines_supplied_list[i].quantity<<endl;
            fi<<supplier_list[j].medicines_supplied_list[i].cost<<endl;
        }
    }
    fi.close();
}

void add_supplier()
{
    string na,ph;
    int j=0,n,id;
    cout<<"How many suppliers do you want to add : "<<endl;
    cin>>n;
    cout<<"Adding New Supplier "<<endl;
    cout<<"********"<<endl;
    for(int ne=0;ne<n;ne++)
    {

        max_sup_id++;
        id=max_sup_id;
        cout<<"Enter Name : "<<endl;
        if(ne==0)
            getline(cin,na);
        getline(cin,na);
        //getline(cin,na);
        cout<<"Enter Phone Number : "<<endl;
        getline(cin,ph);
        //getline(cin,ph);
        supplier s(id,na,ph);
        int i=supplier_list.size();
        i++;
        supplier_list.resize(i);
        supplier_list[i-1]=s;
    }
    cout<<"Successfully added new supplier"<<endl;
    string c;
    cout<<"Enter any key to exit : "<<endl;
    cin>>c;

}
