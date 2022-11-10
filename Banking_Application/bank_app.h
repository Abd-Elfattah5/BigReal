#ifndef BANK_APP_H_INCLUDED
#define BANK_APP_H_INCLUDED

#pragma once

#endif // BANK_APP_H_INCLUDED
static int hidden = 1;
class Client{
protected:
    string name,address;int phone_num;
public:
     Client(){
         cout<<"Your Name :";cin>>name;
         cout<<endl;
         cout<<"Your address :";cin>>address;
         cout<<endl;
         cout<<"Your Phone Number: ";cin>>phone_num;

    }


};
class B_account:public Client{
protected:
      int ID = hidden;int balance;
public:
    B_account(int balance){
        this->balance = balance;
        ofstream user_info;
        string id= "FCAI_";
        id+=to_string(ID);
        user_info.open(id +".txt");
        user_info <<"Basic"<< endl<<ID << endl << name << endl << address << endl << phone_num << endl<<balance;
        user_info.close();

        hidden++;
    }
    B_account(){
        this->balance =200;
                ofstream user_info;
        string id= "FCAI_";
        id+=to_string(ID);
        user_info.open(id +".txt");
        user_info <<"Basic"<< endl<<ID << endl << name << endl << address << endl << phone_num << endl<<balance;
        user_info.close();
        hidden++;
    }
    void withdraw(int draw){
        if(draw > balance){
            cout<<"Balance not enough to withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<balance;
        }else{
            balance = balance - draw;
            cout<<"Succesfully withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<balance<<endl;
        }
    }
    void deposit(int depo){
        balance+=depo;
        cout<<"Your Current Balance is :"<<balance<<endl;
    }

};

class E_account: public Client{
    int miniBalance;int ID = hidden;
public:
    E_account(int miniBalance = 1000){
        this->miniBalance = miniBalance;
                ofstream user_info;
        string id= "FCAI_";
        id+=to_string(ID);
        user_info.open(id +".txt");
        user_info <<"Saving_account"<< endl<<ID << endl << name << endl << address << endl << phone_num << endl<<miniBalance;
        user_info.close();

        hidden++;
    }
    void withdraw(int draw){
        if(draw > miniBalance){
            cout<<"Balance not enough to withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<miniBalance<<endl;
        }else{
            int temp = miniBalance - draw;

            if(temp < 1000){
                cout<<"Balance shouldn't be below 1000 after draw :"<<draw<<endl;
                cout<<"Current Balance is"<<draw<<endl;
            }else {
                miniBalance = miniBalance - draw;
            cout<<"Succesfully withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<miniBalance<<endl;
            }

        }
    }
    void deposit(int depo){
        if(depo >= 100){
            miniBalance+=depo;
            cout<<"Successfully Deposited"<<miniBalance<<endl;
        }else{
            cout<<"You can't deposit less than 100"<<endl;
            cout<<"Current Balance is: "<<miniBalance<<endl;
        }
    }
};
class Banking_App{
char a;
public:
    Banking_App(){
        cout<<"Welcome to FCAI Banking Application"<<endl;
        cout<<"1. Create a New Account"<<endl;
        cout<<"2. List Clients and Accounts"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Deposit Money"<<endl;
        cout<<"5. Quit"<<endl;
        cout<<endl;
        while(a != '5'){
            cout<<"Please Enter Choice: ";cin>>a;
            if(a == '1'){
                one();
            }else if(a == '2'){
                for(int i = 1;i<hidden;i++){

                string id = "FCAI_";
                id+=to_string(i);
                            ifstream find_account(id + ".txt");
                    string account_type,ID,name,password,pho,address,balance;
            getline(find_account, account_type);
            getline(find_account, ID);
            getline(find_account, name);
            getline(find_account, pho);
            getline(find_account, address);
            getline(find_account, balance);
            cout<<"Account_Type: "<<account_type<<endl;
            cout<<"ID: FCAI_ "<<ID<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Phone_Number: "<<pho<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Balance: "<<balance<<endl;

            cout<<"---------------------"<<endl;
                }
            }
            else if(a == '3'){
                int draw;
                int n;
                cout<<"Please Enter your ID from 0 to 4"<<endl;
                cin>>n;
                string id = "FCAI_";
                id+=to_string(n);
                            ifstream find_account(id + ".txt");
                    string account_type,ID,name,password,pho,address,balance;
            getline(find_account, account_type);
            getline(find_account, ID);
            getline(find_account, name);
            getline(find_account, pho);
            getline(find_account, address);
            getline(find_account, balance);
            int bal = stoi(balance);
            cout<<"Enter Money you want to draw"<<endl;
            cin>>draw;
                if(account_type == "Basic"){
                    if(draw > bal){
                    cout<<"Balance not enough to withdraw : "<<draw<<endl;
                    cout<<"Your Current Balance is: "<<bal;
                    }else{
                        bal = bal - draw;
                        cout<<"Succesfully withdraw : "<<draw<<endl;
                        cout<<"Your Current Balance is: "<<bal<<endl;
                    }
                    ofstream user_info;
                            user_info.open(id +".txt");
        user_info <<"Basic"<< endl<<ID << endl << name << endl << address << endl << pho << endl<<bal;
        user_info.close();
        }else{
        if(draw > bal){
            cout<<"Balance not enough to withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<bal<<endl;
        }else{
            int temp = bal - draw;

            if(temp < 1000){
                cout<<"Balance shouldn't be below 1000 after draw :"<<draw<<endl;
                cout<<"Current Balance is"<<draw<<endl;
            }else {
                bal = bal - draw;
            cout<<"Succesfully withdraw : "<<draw<<endl;
            cout<<"Your Current Balance is: "<<bal<<endl;
            }

        }
                            ofstream user_info;
                            user_info.open(id +".txt");
        user_info <<"Saving_Account"<< endl<<ID << endl << name << endl << address << endl << pho << endl<<bal;
        user_info.close();
                }
            }else if(a == '4'){
                int deposit;
                int n;
                cout<<"Please Enter your ID from 0 to 4"<<endl;
                cin>>n;
                string id = "FCAI_";
                id+=to_string(n);
                            ifstream find_account(id + ".txt");
                    string account_type,ID,name,password,pho,address,balance;
            getline(find_account, account_type);
            getline(find_account, ID);
            getline(find_account, name);
            getline(find_account, pho);
            getline(find_account, address);
            getline(find_account, balance);
            int bal = stoi(balance);
            cout<<"Enter Money you want to Depoist"<<endl;
            cin>>deposit;
                if(account_type == "Basic"){

        bal+=deposit;
        cout<<"Your Current Balance is :"<<bal<<endl;

                    ofstream user_info;
                            user_info.open(id +".txt");
        user_info <<"Basic"<< endl<<ID << endl << name << endl << address << endl << pho << endl<<bal;
        user_info.close();
        }else{
                        if(deposit >= 100){
            bal+=deposit;
            cout<<"Successfully Deposited"<<bal<<endl;
        }else{
            cout<<"You can't deposit less than 100"<<endl;
            cout<<"Current Balance is: "<<bal<<endl;
        }
                            ofstream user_info;
                            user_info.open(id +".txt");
        user_info <<"Saving_Account"<< endl<<ID << endl << name << endl << address << endl << pho << endl<<bal;
        user_info.close();
                }

            }
        }

    }
};
