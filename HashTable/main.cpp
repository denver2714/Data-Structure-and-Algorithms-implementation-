#include <iostream>
#include <vector>

struct Node{
    std::string key;
    int value;
    Node* next;

    Node(std::string key,int value): key(key), value(value), next(nullptr){}
};

class HashTable{
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];
public:
    void printTable() {
        for(int i = 0; i < SIZE; i++) {
            std::cout << i << ":" << "\n";
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        std::cout << "   {" << temp->key << ", " << temp->value << "}" << "\n";
                        temp = temp->next;
                    }
                }
            }
        }
    
    int hash(std::string key){
        int hash = 0;
        for(int i = 0; i < key.length(); i++){
            int asciivalue = int(key[i]);
            hash = (hash + asciivalue * 23) % SIZE;
        }
        return hash;
    }

    void set(std::string key, int value){
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if(dataMap[index] == nullptr) {dataMap[index] = newNode;}
        else{//collision, the key/value pair is chaining
            Node* temp = dataMap[index];
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(std::string key){
        int index = hash(key);
        Node* temp = dataMap[index]; // you dont need to say if(index == nullptr) return 0;
        while(temp){
            if(temp->key == key) return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    std::vector<std::string> keys(){
        std::vector<std::string> allKeys;
        for(int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while(temp != nullptr){
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
    

};


int main() {

    HashTable* myHashTable = new HashTable();


    myHashTable->set("paint", 20);
    myHashTable->set("bolts", 40);
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    std::vector<std::string> myKeys = myHashTable->keys();

    for(auto key: myKeys){
        std::cout << key << " ";
    }

    delete myHashTable;
    return 0;
}