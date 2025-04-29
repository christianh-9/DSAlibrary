#include "../include/Graph.h"

Graph::Graph() {

}

Graph::~Graph() {

}

void Graph::addPerson(const std::string &name) {
    if (adjList.find(name) == adjList.end()) {
        adjList[name] = std::vector<std::string>();
    } else {
        std::cout << name << " already exists in the network\n";
    }
}

void Graph::showFriends(const std::string &person) {
    if (adjList.find(person) == adjList.end()) {
        std::cout << person << " is not in the network\n";
        return;
    }

    std::cout << person << "'s friends: ";
    for (const std::string& friendName : adjList[person]) {
        std::cout << friendName << '\n';
    }
}

void Graph::addFriendship(const std::string &person1, const std::string &person2) {
    if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end()) {
        std::cout << "One or both people don't exist in the network\n";
        return;
    }

    adjList[person1].push_back(person2);
    adjList[person2].push_back(person1);
}

bool Graph::isConnected(const std::string &person1, const std::string &person2) {
    if (adjList.find(person1) == adjList.end() || adjList.find(person2) == adjList.end()) {
        return false;
    }
    if (person1 == person2) {
        return true;
    }
    std::map<std::string, bool> visited;
    std::queue<std::string> q;

    q.push(person1);
    visited[person1] = true;

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        for (const std::string& neighbor : adjList[current]) {
            if (neighbor == person2) {
                return true;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}