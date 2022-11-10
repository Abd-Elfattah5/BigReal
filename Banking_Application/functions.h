#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED



#endif // FUNCTIONS_H_INCLUDED

void one(){
    char a;
    char b;
        cout<<"1. Basic Account"<<endl;
        cout<<"2. Saving Account"<<endl;
        cin>>b;
        if(b == '1'){
                B_account d(1500);
                while(a != '5'){
                            cout<<"3. Withdraw Money"<<endl;
                            cout<<"4. Deposit Money"<<endl;
                            cout<<"5. Quit"<<endl;
                            cin>>a;
                            if(a == '3'){
                                int draw;
                                cin>>draw;
                                d.withdraw(draw);
                            }else if(a == '4'){
                                int depo;
                                cin>>depo;
                                d.deposit(depo);
                            }
                }
        }else if(b == '2'){
                E_account d(1500);
                while(a != '5'){

                            cout<<"3. Withdraw Money"<<endl;
                            cout<<"4. Deposit Money"<<endl;
                            cout<<"5. Quit"<<endl;
                            cin>>a;
                            if(a == '3'){
                                int draw;
                                cin>>draw;
                                d.withdraw(draw);
                            }else if(a == '4'){
                                int depo;
                                cin>>depo;
                                d.deposit(depo);
                            }
                }
        }

}
