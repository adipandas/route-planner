#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;
    
    // find the closest nodes to the starting and ending coordinates.
    // Store the nodes in the RoutePlanner's start_node and end_node attributes.
    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);
}


// the distance to the end_node for the h value.
float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return node->distance(*end_node);
}


// Expand the current node by adding all unvisited neighbors to open_list.
void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    current_node->FindNeighbors();
    for (RouteModel::Node * neighbor: current_node->neighbors){
        neighbor->parent = current_node;
        neighbor->h_value = CalculateHValue(neighbor);
        neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
        neighbor->visited = true;
        open_list.push_back(neighbor);
    }
}


// compare two nodes state value
bool CompareNodes(RouteModel::Node *n1, RouteModel::Node *n2){
    return (n1->g_value + n1->h_value)>(n2->g_value + n2->h_value);
}


// sort the open_list and return the next node.
RouteModel::Node *RoutePlanner::NextNode() {
    std::sort(open_list.begin(), open_list.end(), CompareNodes);
    auto nextNode = open_list.back();
    open_list.pop_back();
    return nextNode;
}


// return the final path found from your A* search.
std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {    
    distance = 0.0f;                              
    std::vector<RouteModel::Node> path_found;   // Create path_found vector

    path_found.push_back(*current_node);        // final node as the last element in vector
    while (true){
        auto parent_node = current_node->parent;               
        distance += current_node->distance(*parent_node);
        path_found.push_back(*parent_node);
        current_node = parent_node;

        if (current_node == start_node){
            break;
        }
    }

    std::reverse(path_found.begin(), path_found.end());   // reverse the path.

    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;
}


// A* Search algorithm.
void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;
    
    current_node = start_node;
    open_list.push_back(start_node);
    start_node->visited = true;

    while (open_list.size()>0){
        current_node = NextNode();          // get next node from openlist
        AddNeighbors(current_node);         // handle the neighbors of current node
        if (current_node == end_node){
            m_Model.path = ConstructFinalPath(current_node);        // construct the path
            break;
        }
    }
}
