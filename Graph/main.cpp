#include <iostream>
#include <unordered_set>
#include <unordered_map>
//Adjacency matrix
class Graph{
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
public:

    void printGraph(){
        for(auto [vertex, edges] : adjList){
            std::cout << vertex << ": [ ";
            for(auto edge: edges){
                std::cout << edge << " ";
            }
            std::cout << "]" << std::endl;
        }
    }


    bool addVertex(std::string vertex){
        if(adjList.count(vertex) == 0){//check if vertex is not in the adjList
        adjList[vertex]; // only for the key                adjList[vertex] = "B"; // now with key and value
        return true;
        }
        return false;
    }

    bool addEdge(std::string atWhatVertex, std::string theEdge){
        if(adjList.count(atWhatVertex) != 0 && adjList.count(theEdge) != 0){ //Check if they exists
            adjList.at(atWhatVertex).insert(theEdge); //.at atWhatVertex chooses 'any vertex existing' and returns the value in the key:value pairand .insert inserts the edge
            adjList.at(theEdge).insert(atWhatVertex);
            return true;
        }
        return false;
    }

    bool removeEdge(std::string atWhatVertex, std::string theEdge){
        if(adjList.count(atWhatVertex) != 0 && adjList.count(theEdge) != 0){
            adjList.at(atWhatVertex).erase(theEdge); // from "A"=["B"] to "A"=[]
            adjList.at(theEdge).erase(atWhatVertex); // from "B"=["A"] to "B"=[]
            return true;
        } 
        return false;
    }
    // One of the coolest and complex algorithms i've ever seen
    bool removeVertex(std::string atWhatVertex){
        if(adjList.count(atWhatVertex) == 0) return false;
        for(auto otherVertex :adjList.at(atWhatVertex)){ // Looping through the edges since '.at(atWhatVertex)' returns the value of the key:value pair
            adjList.at(otherVertex).erase(atWhatVertex);

        }
        adjList.erase(atWhatVertex);
        return true;
    }
    
};


int main(){
    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");

    myGraph->removeVertex("D");
    myGraph->printGraph();
    return 0;
}