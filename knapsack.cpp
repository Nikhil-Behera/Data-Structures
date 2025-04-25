//greedy about profit
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class knapsack{
    private:
        int items[20][2];
        int ka;
        int max_profit;

    public:
        int get_knapsack_amount(){
            int amount;
            cout<<"Enter the knapsack amount: "<<endl;
            cin>>amount;
            return amount ;
        }     

        void input(int len,int items[][2]){
            cout<<"Here on enter the input for the profit array: "<<endl;
            
            for(int i=0;i<len;i++){
                cout<<"Enter the profit of the "<<i+1<<"element: "<<endl;
                cin >> items[i][0];
                // cin >> arr[i][0];
            }
            cout<<"Here on enter the input for the weight array: "<<endl;
            for(int i=0;i<len;i++){
                cout<<"Enter the weight for the "<<i+1<<"element :"<<endl;
                cin>>items[i][1];
                // cin >> arr[i][1];
            }
        }
        void sortf(int len,int items[][2]){
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len-1;j++){
                    if(items[j][0]<items[j+1][0]){
                        swap(items[j][0] , items[j+1][0]);
                        swap(items[j][1] , items[j+1][1]);
                    }
                }
            }
        }

        void max_prof(int len , int items[][2]){
            sortf(len,items);
            int bag = get_knapsack_amount();
            max_profit = 0;
            int curr_w =0;
            for(int i=0;i<len;i++){
                if(curr_w + items[i][1] > bag){
                    break;
                }
                else{
                    max_profit += items[i][0];
                    curr_w += items[i][1]; 
                }
            }

        }

        void display(){
            cout<<"The max profit is : "<<max_profit<<endl;
        }

};

int main(){
    knapsack lol;
    int len;
    cout<<"Enter the length of the profit and weight arrays: "<<endl;
    cin>>len;

    int items[20][2] = {};

    lol.input(len,items);
    lol.max_prof(len,items);
    lol.display();

    return 0;
}
