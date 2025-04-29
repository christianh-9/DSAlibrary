//
// Created by Christian Hong on 4/27/25.
//

#ifndef FIRSTPROJECT_GRAPH_H
#define FIRSTPROJECT_GRAPH_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

class Graph {
private:
    std::map<std::string, std::vector<std::string>> adjList;
public:
    Graph();
    ~Graph();

    void addPerson(const std::string& name);
    void addFriendship(const std::string& person1, const std::string& person2);
    void showFriends(const std::string& person);
    bool isConnected(const std::string& person1, const std::string& person2);
};


#endif //FIRSTPROJECT_GRAPH_H
