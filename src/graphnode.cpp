#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    std::cout << "Call to MoveChatbotHere" << std::endl;
    _chatBot = std::move(chatbot);
    std::cout << "Moved" << std::endl;
    _chatBot.SetCurrentNode(this);
    std::cout << "End Call to MoveChatbotHere" << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    std::cout << "Call to MoveChatbotToNewNode" << std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
}

////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}