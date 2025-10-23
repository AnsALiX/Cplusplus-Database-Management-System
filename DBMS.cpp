#include <iostream>
#include<iomanip>
using namespace std;
struct account_info{
    int account_no;
    string first_name;
    string last_name;
    double balance;
    string account_type;
};
int account_count = 10;
void New_account ( account_info a[])
{
    account_info new_account;
    bool flag = true;
    cout<<"Enter Account no, First Name, Last Name, Balance, Account Type ? ";
    cin>>new_account.account_no;
    cin>>new_account.first_name;
    cin>>new_account.last_name;
    cin>>new_account.balance;
    cin>>new_account.account_type;
    for(int i = 0; i<10; i++)
    {
        if(new_account.account_no==a[i].account_no)
        {
           cout<<"Record Already Exsists"<<endl;
           flag = false;
        }
    }
    if(flag)
{
    a[account_count].account_no = new_account.account_no;
    a[account_count].first_name = new_account.first_name;
    a[account_count].last_name = new_account.last_name;
    a[account_count].balance = new_account.balance;
    a[account_count].account_type = new_account.account_type;
    cout << endl << "Account entered Successfully..." << endl;
    account_count++;
}


}
void Update_Account(account_info b[])
{
    account_info update;
    cout<<"Enter Account no to Update Account Type: ";
    cin>>update.account_no;
    cout<<"Please enter the account type: ";
    cin>>update.account_type;
   bool found = false;
for (int j = 0; j < account_count; j++)
{
    if (update.account_no == b[j].account_no)
    {
        b[j].account_type = update.account_type;
        cout << endl << "Account type successfully updated to " << update.account_type << endl;
        found = true;
        break;
    }
}
if (!found)
    cout << "Account not found!" << endl;
}
void Display(int size, const account_info c[])
{
    for(int i = 0; i<size; i++)
    {
        if(c[i].balance>5000 && c[i].last_name[0]=='A')
        {
            cout<<"Account No: "<<c[i].account_no<<endl;
            cout<<"First Name: "<<c[i].first_name<<endl;
            cout<<"Last Name: "<<c[i].last_name<<endl;
            cout<<"Balance: "<<c[i].balance<<endl;
            cout<<"Account Type: "<<c[i].account_type<<endl;
        }
    }
}
int main()
{
    cout<<setw(70)<<"************************"<<endl;
    cout<<setw(70)<<"Name: Muhammad AnsAli "<<endl;
    cout<<setw(70)<<"Roll no: Sp25-BSE-080 "<<endl;
    cout<<setw(70)<<"Section: B "<<endl;
    cout<<setw(70)<<"Computer no: 41"<<endl;
    cout<<setw(70)<<"Final PF Lab Exam"<<endl;
    cout<<setw(70)<<"************************"<<endl;
    account_info Accounts[100] = {
                    {1001,"Ans","Ali",15000,"Current"},
                    {1002,"Sarmad","Aziz",25000,"Saving"},{1003,"Mubashir","Ramzan",17000,"Current"},
                    {1004,"Makima","chan",28000,"Saving"},{1005,"Denji","Khun",45000,"Current"},
                    {1006,"Hamza","Shahzad",55000,"Saving"},{1007,"Muhammad","Shoaib",95000,"Current"},
                    {1008,"Asmar","Khan",85000,"Saving"},{1009,"Muhammad","Sibtain",34000,"Current"},
                    {1010,"Eren","Yeager",90000,"Saving"}
                     };
    cout<<"Account No "<<setw(25)<<"First Name "<<setw(23)<<"Last Name "<<setw(20)<<" Balance "<<setw(25)<<"Account type "<<endl;
    double highest_balance= 0;
    int b=0;
    for(int i=0; i<10; i++)
    {
        if(Accounts[i].balance>highest_balance)
        {
            highest_balance = Accounts[i].balance;
            b = i;
        }


    }
    for(int i=0; i<10; i++)
    {
        if(Accounts[b].account_type=="Current"){
            cout<<Accounts[b].account_no<<setw(25)<<Accounts[b].first_name<<setw(25)<<Accounts[b].last_name<<setw(23)<<Accounts[b].balance<<setw(25)<<Accounts[b].account_type<<endl;
            break;
        }
    }
    int choice= 0;
    while(true)
    {
        cout<<"Press 1 to Add New Account "<<endl;
        cout<<"Press 2 to update Account "<<endl;
        cout<<"Press 3 to display Account "<<endl;
        cout<<"Press 4 to Exit "<<endl;
        cin>>choice;
        if(choice == 1)
        {
          New_account(Accounts);
        }
        else if(choice == 2)
        {
           Update_Account(Accounts);
        }
        else if(choice == 3)
        {
          Display(100,Accounts);
        }
        else if(choice == 4)
        {
          cout<<"Thank you are using this DBMS May Allah Bless you Ameen!"<<endl;
          break;
        }
        else
        {
            cout<<"Invalid Choice Entered !! Please enter again ";
            cin>>choice;
        }
    }


    return 0;
}
