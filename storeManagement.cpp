#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string itemid, itemname;
    int itemprice, itemquantity;
    fstream file, file2;
    int itemtotal = 0, quantity, itemrate;
    string search;
    char choice1;

public:
    void addproduct();
    void viewproduct();
    void buyproduct();
} obj;

int main(){
    char choice;

    cout<<"Press A to Add Product"<<endl;
    cout<<"Press 1 to View & Buy Product"<<endl;
    cout<<"Press 0 to Exit"<<endl;
    cin>>choice;

    switch(choice){
        case 'A':
            obj.addproduct();
            break;

        case '1':
            obj.viewproduct();
            obj.buyproduct();
            break;

        case '0':
            cout<<"You have exited the program";
            break;

        default:
            cout<<"Invalid choice";
    }
}


void temp::addproduct(){
    cout<<"Enter item name: ";
    cin>>itemname;

    cout<<"Enter item id: ";
    cin>>itemid;

    cout<<"Enter price: ";
    cin>>itemprice;

    cout<<"Enter quantity: ";
    cin>>itemquantity;

    file.open("store.txt", ios::app);
    file << itemname << " " 
         << itemid << " " 
         << itemprice << " " 
         << itemquantity << endl;
    file.close();
}


void temp::viewproduct(){
    cout<<"\nItem Name\tID\tPrice\tQuantity\n";

    file.open("store.txt", ios::in);
    while(file >> itemname >> itemid >> itemprice >> itemquantity){
        cout<<itemname<<"\t\t"
            <<itemid<<"\t"
            <<itemprice<<"\t"
            <<itemquantity<<endl;
    }
    file.close();
}



void temp::buyproduct(){
    choice1 = 'y';

    while(choice1 == 'y'){

        file.open("store.txt", ios::in);
        file2.open("temp.txt", ios::out);

        cout<<"Enter product id: ";
        cin>>search;

        cout<<"Enter quantity to buy: ";
        cin>>quantity;

        while(file >> itemname >> itemid >> itemprice >> itemquantity){

            if(search == itemid){
                itemquantity -= quantity;

                itemrate = quantity * itemprice;
                itemtotal += itemrate;

                cout<<"Item Purchased!"<<endl;
            }

            file2 << itemname << " "
                  << itemid << " "
                  << itemprice << " "
                  << itemquantity << endl;
        }

        file.close();
        file2.close();

        remove("store.txt");
        rename("temp.txt","store.txt");

        cout<<"Current Total Bill: "<<itemtotal<<endl;
        cout<<"Continue shopping (y/n): ";
        cin>>choice1;
    }
}
