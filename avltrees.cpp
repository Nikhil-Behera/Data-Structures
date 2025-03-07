#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class node {
public:
    string word;
    string meaning;
    node* left;
    node* right;
    int height;

    node(string w, string m) {
        word = w;
        meaning = m;
        left = right = nullptr;
        height = 1; 
    }
};

class avl{
public:
    node* root;
    
        avl() {
        root = nullptr;
    }
 
    int height(node* temp) {
        return (temp == nullptr) ? 0 : temp->height;
    }

    int diff(node* temp) {
        return (temp == nullptr) ? 0 : height(temp->left) - height(temp->right);
    }

    node* rr_rotation(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    node* ll_rotation(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
   
    node* lr_rotation(node* temp) {
        temp->left = ll_rotation(temp->left);
        return rr_rotation(temp);
    }

    node* rl_rotation(node* temp) {
        temp->right = rr_rotation(temp->right);
        return ll_rotation(temp);
    }

    node* balance(node* temp) {
        int balanceFactor = diff(temp);

        if (balanceFactor > 1 && diff(temp->left) >= 0) {
            return rr_rotation(temp);
        }
       if (balanceFactor > 1 && diff(temp->left) < 0) {
            return lr_rotation(temp);
        }
        if (balanceFactor < -1 && diff(temp->right) <= 0) {
            return ll_rotation(temp);
        }
       if (balanceFactor < -1 && diff(temp->right) > 0) {
            return rl_rotation(temp);
        }
        return temp;
    }

    node* insert(node* temp, string word, string meaning) {
        if (temp == nullptr) {
            return new node(word, meaning);
        }

        int res = strcmp(word.c_str(), temp->word.c_str());
        if (res < 0) {
            temp->left = insert(temp->left, word, meaning);
        } else if (res > 0) {
            temp->right = insert(temp->right, word, meaning);
        } else {
            cout << "Word already exists in the dictionary!" << endl;
            return temp;
        }

        temp->height = 1 + max(height(temp->left), height(temp->right));

        return balance(temp);
    }

    void insert() {
        string word, meaning;
        cout << "Enter the word to be added: ";
        cin >> word;
        cout << "Enter its meaning: ";
        cin.ignore();
        getline(cin, meaning);

        root = insert(root, word, meaning);
        cout << "Word added successfully!" << endl;
    }

    void inOrder(node* temp) {
        if (temp != nullptr) {
            inOrder(temp->left);
            cout << "Word: " << temp->word << " - Meaning: " << temp->meaning << endl;
            inOrder(temp->right);
        }
    }

    void preOrder(node* temp) {
        if (temp != nullptr) {
            cout << "Word: " << temp->word << " - Meaning: " << temp->meaning << endl;
            preOrder(temp->left);
            preOrder(temp->right);
        }
    }

    void postOrder(node* temp) {
        if (temp != nullptr) {
            postOrder(temp->left);
            postOrder(temp->right);
            cout << "Word: " << temp->word << " - Meaning: " << temp->meaning << endl;
        }
    }

    void display(node* temp) {
        if (temp == nullptr) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        queue<node*> q;
        q.push(temp);
        while (!q.empty()) {
            node* curr = q.front();
            q.pop();
            cout << "Word: " << curr->word << " - Meaning: " << curr->meaning << endl;
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
};

int main() {
    avl dictionary;
    int ch;
    while (1) {
        cout << "Menu: "<<endl;
        cout << "1. Insert data"<<endl;
        cout << "2. Preorder traversal"<<endl;
        cout << "3. Inorder traversal"<<endl;
        cout << "4. Postorder traversal"<<endl;
        cout << "5. Level order traversal"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter choice: "<<endl;


        cin >> ch;

        switch (ch) {
            case 1:
                dictionary.insert();
                break;
            case 2:
                cout << "Preorder traversal is:"<<endl;
                dictionary.preOrder(dictionary.root);
                break;
            case 3:
                cout << "Inorder traversal is:" <<endl;
                dictionary.inOrder(dictionary.root);
                break;
            case 4:
                cout << "Postorder traversal is given below:"<<endl;
                dictionary.postOrder(dictionary.root);
                break;
            case 5:
                cout << "Level order traversal is below:"<<endl;
                dictionary.display(dictionary.root);
                break;
            case 6:
                cout << "Exiting the program...." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option."<<endl;
        }
    }
    return 0;
}
