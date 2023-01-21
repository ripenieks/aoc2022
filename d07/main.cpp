#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

enum Type
{
    File,
    Directory,
};

struct Node
{
    std::string name;
    unsigned int size;
    Node* parent_node;
    Type nodeType;

    Node(const std::string& full_name, unsigned int file_size)
    {
        name = full_name;
        size = file_size;
        parent_node = nullptr;
    }
    
    void printData()
    {
        std::cout << "node name: " << name << std::endl;
        std::cout << "node size: " << size << std::endl;
        std::cout << "parent node: " << (parent_node ? parent_node->name : "null") << std::endl;
        std::cout << "node type: " << nodeType << std::endl;
    }

    // parent should only be dir
    void ResizeParent(unsigned int added_size)
    {
        if (parent_node) 
        {
            parent_node->size += added_size;
            parent_node->ResizeParent(added_size);
        }
    }
};

struct DirectoryNode : Node
{
    std::vector<Node*> contents; 

    DirectoryNode(std::string full_name) : Node(full_name, 0)
    {
        nodeType = Type::Directory;
    }

    void AddNode(Node* node)
    {
        contents.push_back(node);
        node->parent_node = this;
        size += node->size;
        if (parent_node) ResizeParent(node->size);
    }

    void ListContents()
    {
        for (Node* node : contents)
        {
            std::cout << node->name << std::endl;
        }
    }

};

struct FileNode : Node
{
    std::string extension;

    FileNode(std::string full_name, unsigned int file_size) : Node(full_name, file_size)
    {
        nodeType = Type::File;
        extension = full_name.substr(full_name.find('.') + 1, 3);
    }

    void printData()
    {
        this->Node::printData();
        std::cout << "extension: " << extension << std::endl;
    }
};

int first(const std::vector<std::string>& input);
int second(const std::vector<std::string>& input);

int main()
{
    std::vector<std::string> input;
    std::string tmp = "";
    std::cin.tie(0);
    while(std::getline(std::cin, tmp))
    {
        input.push_back(tmp);
    }
    std::cout << first(input) << std::endl;
    std::cout << second(input) << std::endl;
}

int first(const std::vector<std::string>& input)
{
    //FileNode* bile = new FileNode("cringer.txt", 51, nullptr);
    //FileNode* bile1 = new FileNode("pickle", 95, nullptr);
    //FileNode* bile2 = new FileNode("woah.xdd", 52, nullptr);
    //FileNode* bile3 = new FileNode("fugg.wmv", 551, nullptr);

    //DirectoryNode* directory = new DirectoryNode("dirdir", nullptr);
    //directory->AddNode(bile);
    //directory->AddNode(bile2);
    //directory->AddNode(bile3);
    //directory->AddNode(bile1);

    //DirectoryNode* dir2 = new DirectoryNode("subdir", nullptr);
    //directory->AddNode(dir2);

    //FileNode* gamer = new FileNode("nignog", 5, nullptr);
    //FileNode* gamer2 = new FileNode("shitfog", 15, nullptr);

    //dir2->AddNode(gamer);
    //dir2->AddNode(gamer2);

    //directory->printData();
    //dir2->printData();
    
    

    return 0;
}

int second(const std::vector<std::string>& input)
{
    return 0;
}
