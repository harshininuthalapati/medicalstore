#include <bits/stdc++.h>
#include <windows.h>
#include "customer_and_suplier.h"
//#include"login.h"
// please make sure that you comment your work well so that others can understand

using namespace std;

class exp_date;     //a linked list node
class medicine;     //contains medicine info
class date;     //date class created to store date
date cs_to_date(char *c);      //this function converts dd/mm/yyyy to date class
void stock_management_menue();
void cre_med();
void create_today_date();
bool operator<(date &a,date &b);
void write_pl();
void sort_medical_list();
void wri_med();
void create_bill_list();
class bill;
void str_pl();
void enter_completing_stock();
void edit_stock();
void edit(medicine &o);
void write_bill();
void supplier_menue();
void test_display();
void customer_menue();
void node_remove(exp_date *head, exp_date *r);
exp_date* node_insert(exp_date *head, exp_date *r);
void insert_medicine_in_stock(string name,exp_date o);
void supplier_menue();
void order_from_supplier();
void create_bill();
int exist_or_not(string nm);
float remove_med(int i,int qua);
void bill_display_print();
void display_med_supplied();
void display_customer_data();
void purchasedata_of_cust();
void display_all_medicines();
void display_completing_stock();
void check_status();


vector<medicine> medical_list;      //stores the list of medical items, apply sorting on them
vector<bill> bill_list;
vector<medicine> depleting_stock;
double total_loss=0;
double total_profit=0;
int id_max=0;



void customer_menue()
{
    string c;
    int n;
    while(true)
    {
        system("cls");
        system("color FD");
        cout<<"\n";
        cout<<setw(30)<<""<<"CUSTOMER MENUE "<<endl;
        cout<<setw(30)<<""<<"-------------------\n"<<endl;
        cout<<setw(30)<<""<<"1.Display Customer Data\n"<<endl;
        cout<<setw(30)<<""<<"2.Display Purchase Data of perticular customer\n"<<endl;
        cout<<setw(30)<<""<<"3.Create Bill\n"<<endl;
        cout<<setw(30)<<""<<"4.print bill\n"<<endl;
        cout<<setw(30)<<""<<"5.Exit\n"<<endl;
        cout<<setw(30)<<""<<"Enter choice : ";
        cin>>n;
        if(n==1){
            display_customer_data();
        }
        else if(n==2){
            purchasedata_of_cust();
        }
        else if(n==3){
            create_bill();
        }
        else if(n==4)
        {
            bill_display_print();
        }
        else if(n==5){
            break;
        }
        else
        {
            cout<<"Invalid Input "<<endl;
            cout<<"Enter any key to continue :";
            cin>>c;
        }

    }
}

void display_customer_data()
{
    system("cls");
    string c;
    int n=customer_list.size();
        cout<<"\n";
        cout<<setw(10)<<""<<"****************************CUSTOMER INFO****************************\n"<<endl;
        //cout<<"\n\n"<<endl;
        cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
        cout<< setw(10)<<""<< "ID" << left << setw(30)<<"" << "NAME" << left<< setw(15)<<""<< "PHONE NUMBER" << endl;
        cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setw(10)<<""<<customer_list[i].id<<setw(15)<<""<<left<<setw(10)<<customer_list[i].name<<left<<setw(15)<<""<<customer_list[i].ph<<endl;

    }
    cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
    cout<<"\nEnter any key to exit : ";
    cin>>c;
}

void stock_management_menue(){
    //complete this feature
    string c;
    int n=-1;
    enter_completing_stock();
    while(true){
        system("cls");
        system("color F6");
        cout<<"\n";
        cout<<setw(35)<<""<<"STOCK MENUE "<<endl; //iomanip
        cout<<setw(35)<<""<<"-------------------\n"<<endl;
        cout<<setw(35)<<""<<"1.Display medicines\n"<<endl;
        cout<<setw(35)<<""<<"2.Display completing stock\n"<<endl;
        cout<<setw(35)<<""<<"3.Edit stock\n"<<endl;
        cout<<setw(35)<<""<<"4.Exit\n"<<endl;
        cout<<setw(35)<<""<<"Enter choice : ";
        cin>>n;
        if(n==1){
                display_all_medicines();
        }
        else if(n==2){
                display_completing_stock();
        }
        else if(n==3){
            edit_stock();
        }
        else if(n==4){
            break;
        }
        else{
            cout<<"invalid input"<<endl;
            cout<<"Enter any key to continue :";
            cin>>c;
            //n=-1;
        }
    }
}

void write_pl()
{
    ifstream file;
    file.open("pl.txt");
    string a;
    int n;
    getline(file,a);
    total_profit=stof(a);
    getline(file,a);
    total_loss=stof(a);
    //cout<<"total_loss: "<<total_loss<<endl;
    file.close();
    //cout<<total_profit<<endl;
    //cout<<total_loss<<endl;
}

void str_pl()
{
    ofstream file;
    file.open("pl.txt");
    file<<total_profit<<endl;
    file<<total_loss<<endl;
    file.close();
}

class date{
    int d,m,y;
public:
    date(int d,int m, int y){
        this->d=d;
        this->m=m;
        this->y=y;
    }
    date(){}
    void display(){
        cout<<d<<"/"<<m<<"/"<<y<<endl;
    }
    friend bool operator<(date &a,date &b);
    int da(){return d;}
    int mo(){return m;}
    int ye(){return y;}
    //friend wri_med();
    friend void write_bill();
    friend void display_med_supplied();
    friend ostream& operator<<(ostream &os,date &o){
    return os<<o.d<<"/"<<o.m<<"/"<<o.y;
}
};

bool operator<(date &a,date &b){
    if(a.y<b.y){
        return true;
    }
    else if(a.y==b.y){
        if(a.m<b.m)
            return true;
        else if(a.m>b.m)
            return false;
        else{
            if(a.d<b.d)
                return true;
            else
                return false;
        }
    }
    else
        return false;
}

date current_date; //stores the current date

void create_today_date()
{
    int y,m,d;
   time_t now = time(0);

   tm *ltm = localtime(&now);
    y=1900+ltm->tm_year;
    m=1 + ltm->tm_mon;
    d=ltm->tm_mday;
   // print various components of tm structure.
   //cout<<d<<"/"<<m<<"/"<<y;
   date o(d,m,y);
   current_date=o;
}

date cs_to_date(char *c){   //  dd/mm/yyyy
    int d,m,y,i,n=0;
    char s[20];
    for(i=0;c[i]!='/';i++){
        s[n]=c[i];
        n++;
    }
    s[n]='\0';
    d=stoi(s);
    i++;
    n=0;
    //cout<<"str m: "<<s<<endl;
    for(;c[i]!='/';i++){
        s[n]=c[i];
        n++;
    }
    s[n]='\0';
    m=stoi(s);
    i++;
    n=0;
    //cout<<"str m: "<<s<<endl;
    for(;c[i]!='\0';i++){
        s[n]=c[i];
        n++;
    }
    s[n]='\0';
    //cout<<"str m: "<<s<<endl;
    y=stoi(s);
    date o(d,m,y);
    //cout<<d<<" "<<m<<" "<<y<<endl;
    return o;
}


class medicine{
    int id;     //write a system that stores the highest value of id in a global variable
    string name;
    int quantity;
    float cost;
    exp_date *head;
public:
    friend void cre_med();
    friend void display_med_supplied();
    medicine(){}
    medicine(int n, string na, int q, float c){
        this->id=n;
        name=na;
        quantity=q;
        cost=c;
    }
    void display(){
        cout<<"Id: #"<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"amount: "<<quantity<<endl;
        cout<<"cost: "<<cost<<endl;
    }
    friend void sort_medical_list();
    friend void wri_med();
    friend void edit_stock();
    friend void edit(medicine &o);
    friend void enter_completing_stock();
    friend void insert_medicine_in_stock(string name,exp_date o);
    friend int exist_or_not(string nm);
    friend void create_bill();
    friend float remove_med(int i,int qua);
    friend void display_all_medicines();
    friend void display_completing_stock();
    friend void purchasedata_of_cust();
};

class exp_date{
    date o;
    float cp;
    int q;
public:
    exp_date(date o, float cp, int q){
        this->o=o;
        this->cp=cp;
        this->q=q;
    }
    exp_date *next=NULL;  //this next node is kept publis
    void display()
    {
        cout<<"exp date: ";
        o.display();
        cout<<endl;
        cout<<"cp: "<<cp<<endl;
        cout<<"quantity: "<<q<<endl;
    }
    friend void wri_med();
    friend void enter_completing_stock();
    friend void edit_stock();
    friend void insert_medicine_in_stock(string name,exp_date o);
    friend float remove_med(int i,int qua);
    friend void cre_med();
};

void node_remove(exp_date *head, exp_date *r){
    exp_date *p;
    p=head;
    if(head==r){
        head=r->next;
        p=r;
    }
    else{
        while(p->next==r){
            p=p->next;
            p=r;
        }
        if(r->next==NULL){
            p->next-NULL;
            p=r;
        }
        else{
            p->next=r->next;
            p=r;
        }
    }
    free(p);
}

exp_date* node_insert(exp_date *head, exp_date r){
    exp_date *q;
    q=new exp_date(r);
    q->next=NULL;
    q->next=head;
    head=q;
    return head;
}

void enter_completing_stock(){
    int k=10,na=0,ia=0;
    int n=medical_list.size();
    for(int i=0;i<n;i++){
        if(medical_list[i].quantity<=k){
            na++;
            depleting_stock.resize(na);
            depleting_stock[ia]=medical_list[i];
            ia++;
        }
    }
}

void edit(medicine &o){
    cout<<setw(40)<<""<<" Editing "<<o.name<<endl;
    cout<<"\nEnter '-' to skip ones u dont want to edit"<<endl;
    string ss,bs="-",ds;
    cout<<"edit name: ";
    getline(cin,ds);
    getline(cin,ss);
    if(ss!=bs){
        o.name=ss;
    }
    cout<<"edit cost: ";
    getline(cin,ss);
    if(ss!=bs){
        o.cost=stoi(ss);
    }
}

void edit_stock(){
    int n,l=medical_list.size();
    while(true){
        system("cls");
        cout<<setw(40)<<""<<"Editing stock"<<endl;
        cout<<"\nEnter id of stock to edit (enter -1 to exit): ";
        cin>>n;
        if(n==-1)
            break;
        for(int i=0;i<l;i++){
            if(n==medical_list[i].id){
                edit(medical_list[i]);
            }
        }
    }

}

void sort_medical_list()
{
    int n=medical_list.size();
    for(int k=1; k<n; k++)
    {
        medicine temp = medical_list[k];
        int j= k-1;
        while(j>=0 && temp.name.compare(medical_list[j].name)<=0)
        {
            medical_list[j+1] = medical_list[j];
            j = j-1;
        }
        medical_list[j+1] = temp;
    }
}

void wri_med()
{
    int n,s=0;
    ofstream file;
    file.open("medicines.txt");
    for(int i=0;i<medical_list.size();i++){
        s=0;
        file<<medical_list[i].id<<endl;
        file<<medical_list[i].name<<endl;
        file<<medical_list[i].quantity<<endl;
        file<<medical_list[i].cost<<endl;
        exp_date *he;
        he=medical_list[i].head;
        exp_date *p;
        p=he;
        while(p!=NULL){
            p=p->next;
            s++;
        }
        file<<s<<endl;
        p=he;
        while(p!=NULL){
            file<<p->o.da()<<"/"<<p->o.mo()<<"/"<<p->o.ye()<<endl;
            file<<p->cp<<endl;
            file<<p->q<<endl;
            p=p->next;
        }
    }
}

void cre_med()
{
    int nk=0;
    int i=0;
    //medical_list.resize(nk);
    ifstream file;
    int x,n,numb,st;
    float k,cp;
    char *c;
    int tempq;
    float temc;
    bool tre=false;
    c=(char*)malloc(20*sizeof(char));
    file.open("medicines.txt");     //make a text file with same name as this one in the same folder as this program
    // below is the format in which the data is stored in the file, use it for writing data into files

    /*

        medicine id
        medicine name
        total quantity of medicine
        cost per unit
        number->this number indicates the number of different expiry dates
        date in dd/mm/yyyy format
        cp of each unit
        quantity of the tablet
        //the above 3 line repeat n times

    */
    string s,na;
    while(getline(file,na)){
        //cout<<"--------------------------------------------------------------"<<endl;
        n=stoi(na);
        if(id_max<n)
            id_max=n;
        getline(file,s);
        //cout<<s<<endl;
        getline(file,na);
        x=stoi(na);
        getline(file,na);
        k=stof(na); // stoi changes string to int or float
        medicine o(n,s,x,k);
        //o.display();
        getline(file,na);
        numb=stoi(na);
        exp_date *head,*q,*p;
        file.getline(c,20);
        date d=cs_to_date(c);
        getline(file,na);
        cp=stof(na);
        getline(file,na);
        st=stoi(na);
        tempq=st;
        temc=cp;
        head=new exp_date(d,cp,st);
        head->next=NULL;
        p=head;
        numb=numb-1;
        //cout<<"cp: "<<p->cp<<endl;
        if(d<current_date|| st==0)
            tre=true;
        //cout<<"numb: "<<numb<<endl;
        while(numb){
            file.getline(c,20);
            date d=cs_to_date(c);
            getline(file,na);
            cp=stof(na);
            getline(file,na);
            st=stoi(na);
            if(d<current_date || st==0){
                total_loss+=(float)cp*st;
                o.quantity-=st;
            }
            else{
                q=new exp_date(d,cp,st);
                p->next=q;
                q->next=NULL;
                p=q;
                //cout<<"cp: "<<p->cp<<endl;
            }

            numb-=1;
        }
        if(tre){
            head=head->next;
            o.quantity-=tempq;
            total_loss+=(float)temc*tempq;
            tre=false;
        }

        o.head=head;
        p=o.head;
        /*while(p!=NULL){
                cout<<"****************"<<endl;
            p->display();
            p=p->next;
        }*/

        nk++;
        medical_list.resize(nk);
        medical_list[i]=o;      //entering newly created object into the vector

        i++;
    }
    file.close();
}
void display_all_medicines()
{
    system("cls");
    cout<<setfill(' ');
    char c;
    //cout<<"**********************************************************************"<<endl;
    int n=35,k=29;
    k=(k-13)/2;
    sort_medical_list();
    cout<<"\n"<<endl;
    cout<<setw(50)<<" "<<"MEDICINE LIST"<<endl;
    cout<<"\n"<<endl;
    cout<<setw(n)<<""<<" "<<setfill('_')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    cout<<setw(n)<<""<<left<<"|  id  |"<<setw(k)<<""<<"Medicine Name"<<setw(k)<<""<<"|  Quantity  |"<<endl;
    cout<<setw(n)<<""<<" "<<setfill('-')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    int in=medical_list.size();
    for(int i=0;i<in;i++){
            int id=medical_list[i].id;
            cout<<setw(n)<<""<<"| "<<left<<setw(5)<<medical_list[i].id<<"|"<<" "<<left<<setw(k+k+12)<<medical_list[i].name<<"| "<<left<<setw(11)<<medical_list[i].quantity<<"|"<<endl;
    }
    cout<<setw(n)<<""<<" "<<setfill('-')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    cout<<" Enter any key to Exit:  ";
    cin>>c;
}

void display_completing_stock()
{
    system("cls");
    string c;
    cout<<setfill(' ');
    int n=35,k=29;
    k=(k-13)/2;
    cout<<"\n"<<endl;
    cout<<setw(50)<<" "<<"DEPLETING STOCK"<<endl;
    cout<<"\n"<<endl;
    cout<<setw(n)<<""<<" "<<setfill('_')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    cout<<setw(n)<<""<<left<<"|  id  |"<<setw(k)<<""<<"Medicine Name"<<setw(k)<<""<<"|  Quantity  |"<<endl;
    cout<<setw(n)<<""<<" "<<setfill('-')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    int in=depleting_stock.size();
    for(int i=0;i<in;i++){
            int id=medical_list[i].id;
            cout<<setw(n)<<""<<"| "<<left<<setw(5)<<depleting_stock[i].id<<"|"<<" "<<left<<setw(k+k+12)<<depleting_stock[i].name<<"| "<<left<<setw(11)<<depleting_stock[i].quantity<<"|"<<endl;
    }
    cout<<setw(n)<<""<<" "<<setfill('-')<<setw(33+k+k)<<""<<endl;
    cout<<setfill(' ');
    cout<<"   Enter any key to Exit:  ";
    cin>>c;
}
class bill{
    string id;
    date d;
    vector<medicine_suply> medicines_supplied_list;
public:
    bill(){}
    void display()
    {

        cout<<"Id : "<<id<<endl;
        d.display();
        for(int i=0;i<medicines_supplied_list.size();i++){
            cout<<"----------------------------------------"<<endl;
            medicines_supplied_list[i].display();
        }
    }

    //vector<bill> bill_list;
   // vector<medicine> medical_list;
    friend void create_bill_list();
    friend void write_bill();
    friend void create_bill();
    friend void purchasedata_of_cust();
    friend void bill_display_print();
};

void create_bill_list()
{
    ifstream file;
    file.open("bills.txt");
    string c,k;
    int ni,nk=0,bi=0,bn=0;
    float n;
    char da[20];
    while(getline(file,c)){
            //cout<<"h11"<<endl;
        bill o;
        o.id=c;
        //cout<<"id: "<<c<<endl;
        file.getline(da,20);
        //cout<<"date: "<<da<<endl;
        date d=cs_to_date(da);
        o.d=d;
        //d.display();
        getline(file,c);
        //cout<<"size: "<<c<<endl;
        nk=stoi(c);
        o.medicines_supplied_list.resize(nk);
        for(int i=0;i<nk;i++){
                //cout<<"h33"<<endl;
            medicine_suply ob;
            getline(file,c);
            //cout<<"name: "<<c<<endl;
            ob.name=c;
            getline(file,c);
            //cout<<"qua: "<<c<<endl;
            ni=stoi(c);
            ob.quantity=ni;
            getline(file,c);
            //cout<<"cost: "<<c<<endl;
            n=stof(c);
            ob.cost=n;
            o.medicines_supplied_list[i]=ob;
        }
        bn++;
        bill_list.resize(bn);
        bill_list[bi]=o;
        bi++;
    }
    //cout<<"hi"<<endl;
    file.close();
}

void write_bill()
{
    ofstream file;
    file.open("bills.txt");
    int x;
    x=bill_list.size();
    for(int i=0;i<x;i++)
    {
        file<<bill_list[i].id<<endl;
        file<<bill_list[i].d.d<<"/"<<bill_list[i].d.m<<"/"<<bill_list[i].d.y<<endl;
        int k=bill_list[i].medicines_supplied_list.size();
        file<<k<<endl;
        //cout<<"k is: "<<k<<endl;
        for(int j=0;j<k;j++)
        {
            file<<bill_list[i].medicines_supplied_list[j].name<<endl;
            file<<bill_list[i].medicines_supplied_list[j].quantity<<endl;
            file<<bill_list[i].medicines_supplied_list[j].cost<<endl;
        }
    }
    file.close();
}

void insert_medicine_in_stock(string name,exp_date o){
    int flag=-1;
    int n=medical_list.size();
    for(int i=0;i<n;i++){
        if(name==medical_list[i].name){
            flag=i;
        }
    }
    if(flag==-1){
        medicine m;
        m.name=name;
        m.cost=30;
        m.quantity=o.q;
        id_max+=1;
        m.id=id_max;
        m.head=NULL;
        medical_list.resize(n+1);
        medical_list[n]=m;
        flag=medical_list.size()-1;
    }
    o.next=NULL;
    medical_list[flag].head=node_insert(medical_list[flag].head,o);

}

void supplier_menue()
{
    string c;
    int n=-1;
    while(true)
    {
        system("color FC");
        system("cls");
        cout<<"\n";
        cout<<setw(30)<<""<<"SUPPLIER MENUE "<<endl;
        cout<<setw(30)<<""<<"-------------------\n"<<endl;
        cout<<setw(30)<<""<<"1.Add Order from supplier\n"<<endl;
        cout<<setw(30)<<""<<"2.Add New supplier\n"<<endl;
        cout<<setw(30)<<""<<"3.Display supplier info\n"<<endl;
        cout<<setw(30)<<""<<"4.Display Medicines supplied by a supplier\n"<<endl;
        cout<<setw(30)<<""<<"5.check status\n"<<endl;
        cout<<setw(30)<<""<<"6.Exit\n"<<endl;
        cout<<setw(30)<<""<<"Enter choice : ";
        cin>>n;
        if(n==1)
        {
            order_from_supplier();
        }
        else if(n==2)
        {
            add_supplier();
        }
        else if(n==3)
        {
            display_supplier_info();
        }
        else if(n==4)
        {
            display_med_supplied();
        }
        else if(n==5)
        {
            check_status();
        }
        else if(n==6)
        {
            break;
        }
        else
        {
            cout<<"Invalid Input\n";
            cout<<"Enter any key to continue :";
            cin>>c;
        }

    }
}

void order_from_supplier()
{
    int id,f=-1,qu;
    string nn;
    float co;
    cout<<"Enter supplier id"<<endl;
    cin>>id;
    int n=supplier_list.size();
    for(int i=0;i<n;i++)
    {
        if(id==supplier_list[i].id)
        {
            f=i;
            break;
        }
    }
    if(f==-1)
        cout<<"Invalid Id"<<endl;
    else
    {
        int n,d,m,y,vl;
        cout<<"How many types of medicine : "<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter medicine name :"<<endl;
            getline(cin,nn);
            getline(cin,nn);
            cout<<"Enter quantity of the medicine :"<<endl;
            cin>>qu;
            cout<<"Enter cost of the medicine :"<<endl;
            cin>>co;
            medicine_suply o(nn,qu,co);
            vl=supplier_list[f].medicines_supplied_list.size();
            supplier_list[f].medicines_supplied_list.resize(vl+1);
            supplier_list[f].medicines_supplied_list[vl]=o;
            cout<<"Enter Expiry date of the medicine : "<<endl;
            cin>>d>>m>>y;
            date da(d,m,y);
            exp_date ex(da,co/qu,qu);
            insert_medicine_in_stock(nn,ex);
        }
    }
}

void display_supplier_info()
{
    system("cls");
    string c;

    int n=supplier_list.size();
        cout<<setw(10)<<""<<"********************************SUPPLIER INFO********************************\n"<<endl;
        //cout<<"\n\n"<<endl;
        cout<<setw(10)<<""<<"-----------------------------------------------------------------------------"<<endl;
        cout<< setw(10)<<""<< "ID" << left << setw(20)<<"" << "NAME" << left<< setw(40)<<""<< "PHONE NUMBER" << endl;
        cout<<setw(10)<<""<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<setw(10)<<""<<supplier_list[i].id<<setw(20)<<""<<left<<setw(35)<<supplier_list[i].name<<setw(10)<<""<<left<<setw(20)<<supplier_list[i].ph<<endl;

    }
    cout<<"Enter any key to exit : ";
    cin>>c;
}

void display_med_supplied()
{
    system("cls");
    string c;
    int id,x;
    int flag=-1;
    cout<<"Enter ID of the supplier :"<<endl;
    cin>>id;
    int siz=supplier_list.size();
    for(int i=0;i<siz;i++)
    {
        if(id==supplier_list[i].id)
        {
             x=i;
            flag=0;
            break;
        }

    }
    if(flag==-1)
    {
        cout<<"Supplier not found"<<endl;
    }
    else
    {
            cout<<"SUPPLIER NAME : "<<supplier_list[x].name<<endl;
            cout<<"SUPPLIER PHONE NUMBER :"<<supplier_list[x].ph<<endl;
            cout<<"MEDICINES SUPPLIED BY THE SUPPLIER :"<<endl;
            cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
            cout<< setw(10)<<""<< "MEDICINE NAME" << left << setw(20)<<"" << "QUANTITY" << left<< setw(23)<<""<< "COST" << endl;
            cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
            int m=supplier_list[x].medicines_supplied_list.size();
            for(int j=0;j<m;j++)
            {
                cout<<setw(10)<<""<<setw(15)<<supplier_list[x].medicines_supplied_list[j].name<<setw(20)<<""<<left<<setw(15)<<supplier_list[x].medicines_supplied_list[j].quantity<<left<<setw(15)<<""<<supplier_list[x].medicines_supplied_list[j].cost<<endl;
            }


    }
    cout<<setw(10)<<""<<"----------------------------------------------------------------------"<<endl;
    cout<<"\nEnter any key to exit :";
    cin>>c;
}
void test_display()
{
    // uncomment below for loop to display the medicines (use it to check if sorting or inserting new elements is sucessfull)
    cout<<"*********************************************** medical stock"<<endl;

    for(int i=0;i<medical_list.size();i++){
        medical_list[i].display();
    }
    cout<<"**********************************************************"<<endl;
    for(int i=0;i<customer_list.size();i++)
    {
        cout<<"---------------------------------------"<<endl;
        customer_list[i].display();
    }
    cout<<"* supplier *"<<endl;

    for(int i=0;i<supplier_list.size();i++){
        cout<<"***************"<<endl;
        supplier_list[i].display();
    }
    cout<<"**BILL**"<<endl;
    for(int i=0;i<bill_list.size();i++){
        cout<<"******************"<<endl;
        bill_list[i].display();
    }
}

void create_bill(){
    int flag=-1,i;
    string s,na,pn,dummy;
    cout<<"Enter Id of customer: "<<endl;
    getline(cin,s);
    getline(cin,s);
    int n=bill_list.size();
    for(i=0;i<n;i++){
        if(bill_list[i].id==s){
            flag=i;
            //cout<<"hi"<<endl;
            break;
        }
    }
    if(flag==-1){
        cout<<"The customer is not a existing customer, enter customer details"<<endl;
        cout<<"enter name: ";
        getline(cin,na);
        cout<<"Enter phone number: ";
        getline(cin,pn);
        customer co(s,na,pn);
        int k=customer_list.size();
        customer_list.resize(k+1);
        customer_list[k]=co;
        flag=k;
    }
    bill bo;
    int nt;
    cout<<"Enter the number of types medicines to purchase: "<<endl;
    cin>>nt;
    bo.id=s;
    bo.d=current_date;
    bo.medicines_supplied_list.resize(nt);
    getline(cin,dummy);
    for( i=0;i<nt;i++){
        string nm;
        int no_me;
        int qua;
        float cost=0;
        while(1)
        {
            cout<<"Enter name of medicine to buy: ";
            getline(cin,nm);
            no_me=exist_or_not(nm);
            if(no_me!=-1)
                break;
            else
                cout<<"The medicine is not available, try again"<<endl;
        }
        cout<<"Cost of medicine is: "<<medical_list[no_me].cost<<endl;
        int max_qua=medical_list[no_me].quantity;
        cout<<"The quantity available is "<<max_qua<<endl;
        while(1)
        {
            cout<<"Enter quantity to buy: ";
            cin>>qua;
            if(qua<=max_qua)
                break;
            else
                cout<<"Given quantity is not available "<<max_qua<<endl;
        }
        cost=remove_med(no_me,qua);
        cout<<"cost: "<<cost<<endl;
        medicine_suply ms(nm,qua,cost);
        bo.medicines_supplied_list[i]=ms;
    }
    int bni=bill_list.size();
    bill_list.resize(bni+1);
    bill_list[bni]=bo;
    bill_display_print();

}

float remove_med(int i,int qua){
    exp_date *p;
    p=medical_list[i].head;
    int te=qua;
    medical_list[i].quantity-=qua;
    float cost=0.0;
    //cout<<"H1"<<endl;
    while(te){
            //cout<<"H2"<<endl;
        if(p->q<te){
            cost+=(float)(p->q)*medical_list[i].cost;
            total_profit+=(medical_list[i].cost-(p->cp))*p->q;
            te=te-p->q;
            p=p->next;
            //cout<<"te is: "<<te<<endl;
            //cout<<"cost is: "<<cost<<endl;
        }
        else{
            p->q-=te;
            total_profit+=(medical_list[i].cost-(p->cp))*te;
            cost+=(float)te*medical_list[i].cost;
            te-=te;
            //cout<<"te is: "<<te<<endl;
            //cout<<"cost is: "<<cost<<endl;
        }
    //cout<<"H3"<<endl;
    }
    //cout<<"H4"<<endl;
    return cost;
}

void bill_display_print()
{
    string c;
    int county=0;
    int h=29,w=10;
    int m=bill_list.size();
    int j=customer_list.size();
    m=m-1;
    system("cls");
    cout<<"\n";
    cout<<setw(40)<<""<<"BILL"<<endl;
    cout<<"Id of the customer :"<<bill_list[m].id<<endl;
    for(int i=0;i<j;i++)
    {
        if(bill_list[m].id==customer_list[i].id)
        {
            cout<<"Name of the customer : "<<customer_list[i].name<<endl;
            cout<<"Phone number of the customer : "<<customer_list[i].ph<<endl;
        }
    }
    int d=bill_list[m].medicines_supplied_list.size();
    cout<<"Date : "<<bill_list[m].d<<endl;
    /*for(int k=0;k<d;k++)
    {
      cout<<"Name of the medicine : "<<bill_list[m].medicines_supplied_list[k].name<<endl;
      cout<<"Quantity of the medicine : "<<bill_list[m].medicines_supplied_list[k].quantity<<endl;
      cout<<"Cost of the medicine : "<<bill_list[m].medicines_supplied_list[k].cost<<endl;
      county=county+bill_list[m].medicines_supplied_list[k].cost;

    }*/
    cout<<setw(h)<<""<<" "<<setfill('_')<<setw(43+w+w)<<""<<endl;
    cout<<setfill(' ');
    cout<<setw(h)<<left<<""<<"|"<<setw(w)<<left<<""<<" MEDICINE NAME "<<setw(w)<<left<<""<<"|"<<"  QUANTITY  "<<"|"<<"     COST     "<<"|"<<endl;
    cout<<setw(h)<<""<<" "<<setfill('-')<<setw(43+w+w)<<""<<endl;
    cout<<setfill(' ');
    for(int k=0;k<d;k++)
        {
            cout<<setw(h)<<""<<left<<"| "<<setw(w+w+14)<<bill_list[m].medicines_supplied_list[k].name<<"| ";
            cout<<left<<setw(11)<<bill_list[m].medicines_supplied_list[k].quantity<<"| ";
            cout<<left<<setw(13)<<bill_list[m].medicines_supplied_list[k].cost<<"|"<<endl;
            county=county+bill_list[m].medicines_supplied_list[k].cost;
        }
    cout<<setw(h)<<""<<" "<<setfill('-')<<setw(43+w+w)<<""<<endl;
    cout<<setfill(' ');
    cout<<"\n"<<endl;

    cout<<"\t\t\t\t\t\t\t\t\tTotal cost : "<<county<<endl;
    cout<<"Enter any key to exit : "<<endl;
    cin>>c;
}

int exist_or_not(string nm){
    int flag=-1;
    int n=medical_list.size();
    for(int i=0;i<n;i++){
        if(medical_list[i].name==nm)
        {
            flag=i;
            break;
        }
    }
    return flag;
}
void purchasedata_of_cust()
{
    system("cls");
    cout<<setfill(' ');
    string id,c;
    int x,flag=-1;
    int h=29,w=10;
    //w=(w-13)/2;
    cout<<"Enter the id of the customer : ";
    getline(cin,id);
    getline(cin,id);
    int n=customer_list.size();
    for(int i=0;i<n;i++)
    {
        if(id==customer_list[i].id)
        {
            flag=0;
            x=i;
            break;
        }
    }
    if(flag==-1)
    {
        cout<<"customer not found"<<endl;
    }
    else
    {
        cout<<"Name of the customer :"<<customer_list[x].name<<endl;
        cout<<"phone number of the customer :"<<customer_list[x].ph<<endl;
        cout<<"medcines bought by the customer on:"<<endl;
        int k=bill_list.size();
        for(int j=0;j<k;j++)
        {
            if(id == bill_list[j].id)
            {
                int d=bill_list[j].medicines_supplied_list.size();
                cout<<"Purchase History on "<<bill_list[j].d<<" :"<<endl;
                cout<<"\n\n"<<endl;                     //AP21110010413
                cout<<setw(h)<<""<<" "<<setfill('_')<<setw(43+w+w)<<""<<endl;
                cout<<setfill(' ');
                //cout<<"\n";
                cout<<setw(h)<<left<<""<<"|"<<setw(w)<<left<<""<<" MEDICINE NAME "<<setw(w)<<left<<""<<"|"<<"  QUANTITY  "<<"|"<<"     COST     "<<"|"<<endl;
                cout<<setw(h)<<""<<" "<<setfill('-')<<setw(43+w+w)<<""<<endl;
                cout<<setfill(' ');
                for(int m=0;m<d;m++)
                {
                    cout<<setw(h)<<""<<left<<"| "<<setw(w+w+14)<<bill_list[j].medicines_supplied_list[m].name<<"| ";
                    cout<<left<<setw(11)<<bill_list[j].medicines_supplied_list[m].quantity<<"| ";
                    cout<<left<<setw(13)<<bill_list[j].medicines_supplied_list[m].cost<<"|"<<endl;
                }
                cout<<setw(h)<<""<<" "<<setfill('-')<<setw(43+w+w)<<""<<endl;
                cout<<setfill(' ');
                cout<<"\n"<<endl;
            }

        }

    }

    cout<<"\nEnter any key to exit : ";
    cin>>c;
}
void check_status()
{
    string c;
    system("cls");
    system("color F3");
    //HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(h,19);
   // system("color F4");
    cout<<"\n\n\n\n\n";
    cout<<setw(40)<<""<<"Total loss : "<<total_loss<<endl;
    //system("color F2");
    cout<<setw(40)<<""<<"Total profit : "<<total_profit<<endl;
    //system("color F1");
    cout<<setw(40)<<""<<"Enter any key to exit :";
    cin>>c;
}
int main()
{
    string c;
    //cout<<"hi";
    system("color F1");
    //new_application();
    //pass();
    create_today_date();
    write_pl();
    cre_med();//this file reads info from file into the object
    sort_medical_list();
    create_customer();
    create_supplier();
    //cout<<"hi";
    create_bill_list();
    //cout<<"h";
    string simple;
    //getline(cin,simple);
    int n=-1;
    while(true){
        system("cls");
        system("color F1");
        cout<<setw(28)<<" "<<"---------------------------------"<<endl;
        cout<<setw(27)<<" "<<"| MEDICAL STORE MANAGEMENT SYSTEM |"<<endl;
        cout<<setw(28)<<" "<<"---------------------------------"<<endl;
        cout<<"\n";
        cout<<setw(35)<<""<<"1.Stock\n"<<endl;
        cout<<setw(35)<<""<<"2.Customer\n"<<endl;
        cout<<setw(35)<<""<<"3.Supplier\n"<<endl;
        cout<<setw(35)<<""<<"4.Exit\n"<<endl;
        cout<<setw(35)<<""<<"Enter choice : ";
        cin>>n;
    //current_date.display();
        //uncomment this line after we have finished stock management menue
        if(n==1){
            stock_management_menue();       //feature 1
        }
        else if(n==2){
            customer_menue();
        }
        else if(n==3){
            supplier_menue();
        }
        else if(n==4){
            break;
        }
        else{
            cout<<"please enter valid choice"<<endl;
            cout<<"Enter any key to continue :";
            cin>>c;
        }
    }

    //cout<<"bill_li size: "<<bill_list.size()<<endl;
    //test_display();
    wri_med();
    str_pl();
    write_bill();
    write_customer();
    write_supplier();
}
