#include<iostream>
using namespace std;

class rev{
    int n;
    int arr[20];
    public:
        rev(){
            cout<<"Enter the no. of elemnets: "<<endl;
            cin>>n;
        }

        void accept(){
            cout<<"Enter the elements of the array: "<<endl;
            
            int i=0;
            while(i < n){
                cout<<"Enter the element at place "<<i+1<<" :"<<endl;
                cin>>arr[i];
                i++;
            }
        }

        void revit(){
            for(int i=n-1;i>=0;i--){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
        
        void display(){
            int i=0;
            while(i<n){
                cout<<arr[i]<<"\t";
                i++;
            }
            cout<<endl;
        }
        
};

int main(){
    rev arr;
    int ch;

    do{
        cout<<"MENU"<<endl;
        cout<<"1.Accept elements: "<<endl;
        cout<<"2.Reverse the array: "<<endl;
        cout<<"3.Display the array: "<<endl;
        cout<<"4.Exit"<<endl;

        cout<<"Enter your wish: "<<endl;
        cin>>ch;

        switch(ch){
            case 1:
                arr.accept();
                break;

            case 2: 
                arr.revit();
                break;

            case 3:
                arr.display();
                break;

            case 4:
                cout<<"Exiting the program..."<<endl;
                break;
        }
    }while(ch!=4);
    return 0;
}
