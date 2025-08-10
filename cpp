#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t\t                       \n";
    cout<<"\t\t\t\t\t  Shopping menu bar    \n";
    cout<<"\t\t\t\t\t                       \n";
    cout<<"\t\t\t\t\t_______________________\n";


    cout<<"\t\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t\t|   1)Administrator      |\n";
    cout<<"\t\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t\t|   2)Buyer              |\n";
    cout<<"\t\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t\t|   3)Exit               |\n";
    cout<<"\t\t\t\t\t|________________________|\n";

    cout<<"\n\t\t\t\t   Please select an option     \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t\t\t   Please Login\n";
            cout<<"\t\t\t\t\t   Enter Email:\t";
            cin>>email;
            cout<<"\t\t\t\t\t   Enter Password:";
            cin>>password;

            if(email=="manoj@gmail.com" && password=="manoj@123")
            {
                administrator();
            }
            else
            {
                cout<<"\t\t\t\t\t   Invalid email/password\n";
            }
            break;

        case 2:
            {
                buyer();
            }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout<<"\t\t\t\t\t   Please Select from the given options\n";
        }
    }
    goto m;
}

void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t\t\t   Administrator menu\n";
    cout<<"\n\t\t\t\t\t|___1) Add the Product_______|\n";
    cout<<"\t\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t\t|___2) Modify the Product____|\n";
    cout<<"\t\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t\t|___3) Delete the Product____|\n";
    cout<<"\t\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t\t|___4) Back to main menu_____|\n";

    cout<<"\n\t\t\t\t\t   Please Enter your choice\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default:
            cout<<"\t\t\t\t\t   Invalid Chaice\n";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t\t\t   Buyer\n";
    cout<<"\t\t\t\t\t____________________\n";
    cout<<"\t\t\t\t\t                    \n";
    cout<<"\t\t\t\t\t   1) Buy Product   \n";
    cout<<"\t\t\t\t\t                    \n";
    cout<<"\t\t\t\t\t   2) Go Back       \n";
    cout<<"\t\t\t\t\t____________________\n";

    cout<<"\t\t\t\t\t   Enter your Choice:\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();

        default:
            cout<<"\t\t\t\t\t   Invalid Choice\n";

    }
goto m;
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t   Add new Product\n";
    cout<<"\n\n\t\t\t\t   Product code of the Product:\t";
    cin>>pcode;
    cout<<"\n\n\t\t\t\t   Name of the Product:\t";
    cin>>pname;
    cout<<"\n\n\t\t\t\t   Price of the Product:\t";
    cin>>price;
    cout<<"\n\n\t\t\t\t   Discont on the Product:\t";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    

    if(token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }
    cout<<"\n\n\t\t\t   Record inserted !\n";
}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\t\t\t\t\t   Modify the Record\n";
    cout<<"\t\t\t\t\t   Product code:\n";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\t\t\t\t\t   File doesn't exist!\n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t\t\t   Product new code:\t";
                cin>>c;
                cout<<"\n\t\t\t\t   Name of the Product:\t";
                cin>>n;
                cout<<"\n\t\t\t\t   Price:\t";
                cin>>p;
                cout<<"\n\t\t\t\t   Discount:\t";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t\t\t   Record edited!\n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\t\t\t\t   Recorde not found sorry!\n";
        }
    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int tok=0;
    cout<<"\n\t\t\t\t   Delete Product\n";
    cout<<"\n\t\t\t\t   Product code:\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\t\t\t   File doesn't exist\n";
    }

    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\t\t\t\t   Product deleted successfully\n";
                tok++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(tok==0)
        {
            cout<<"\n\t\t\t\t   Record Not found\n";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n__________________________________\n";
    cout<<"ProNo.\t\tName\t\tPrice\n";
    cout<<"\n\n__________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    //int count;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\t\t\t\t   RECEIPT\n";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t\t\t\t   Empty database\n";
    }

    else
    {
        data.close();

        list();

        cout<<"\n___________________________________\n";
        cout<<"\n                                   \n";
        cout<<"\n          Please place the order   \n";
        cout<<"\n                                   \n";
        cout<<"\n___________________________________\n";

        do
        {
            m:
            cout<<"\n\t\t\t\t   Enter the product code:\n";
            cin>>arrc[c];
            cout<<"\n\t\t\t\t   Enter the productquantity:\n";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\t\t\t\t   Duplicate product code. Please try again!\n";
                    goto m;
                }
            }
            c++;
            //cout<<c;
            cout<<"\n\t\t\t\t   Do you want to buy another product? If yes then press y else no press n\n";
            //count=c;
            cin>>choice;
        }
        while(choice=='y');
        
        cout<<"\n\t\t\t\t   _________RECEIPT__________\n";
        cout<<"\nProduct No\t ProductName\t Productquantity\t Price\t  amount\t Amount with discout\n";

        //cout<<"\nmy name is c="<<c;
        for(int i=0;i<c;i++)
        {
            //cout<<"\nmy name is c="<<c;
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    //cout<<"\nmy name is i="<<i;
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
                //data.close();
            }
            data.close();
        }
        //data.close();
    }
    data.close();
    cout<<"\n\n__________________________________________";
    cout<<"\n Total Amount: "<<total;
}

int main()
{
    shopping s;
    s.menu();
}
