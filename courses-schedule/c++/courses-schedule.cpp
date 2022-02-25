#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isCyclic(int courseId, map<int, vector<int>>& coursesGraph, vector<bool>& graphPath, vector<bool>& visitedVertices)
{
    // No need to continue if the vertix was visited in a prior DFS
    if (visitedVertices[courseId] == true)
        return false;
    // The vertix was visited in the current courses path, then this is a cycle
    if (graphPath[courseId] == true)
        return true;
    // The course has no relations to other courses
    if (coursesGraph.count(courseId) == 0)
        return false;

    // Add the current course to the path
    graphPath[courseId] = true;
    bool returnValue = false;

    // Perform DFS on the children vertices
    for (int i = 0; i < coursesGraph[courseId].size(); i++)
    {
        returnValue = isCyclic(coursesGraph[courseId][i], coursesGraph, graphPath, visitedVertices);
        // Break if a cycle was detected
        if (returnValue)
            break;
    }

    // Mark the vertix as visited
    visitedVertices[courseId] = true;
    // Remove the vertix from the path (backtracking)
    graphPath[courseId] = false;
    return returnValue;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, vector<int>> coursesGraph;

    // Constructing the Graph Data structure
    for (vector<int> relationsVector : prerequisites)
    {
        coursesGraph[relationsVector[1]].push_back(relationsVector[0]);
    }

    // Tracking the current courses path
    vector<bool> graphPath(numCourses, false);
    // Tracking all the visited courses
    vector<bool> visitedVertices(numCourses, false);

    // Performing DFS on the graph
    for (int i = 0; i < numCourses - 1; i++)
    {
        // Return false once a cycle is detected
        if (isCyclic(i, coursesGraph, graphPath, visitedVertices))
            return false;
    }

    // If no cycles are detected then all courses can be taken
    return true;
}

int main()
{
    vector<vector<int>> testMatrix = { {1, 0},{0 , 1}};
    int numberOfCourses = 2;

    bool canFinishCourses = canFinish(numberOfCourses, testMatrix);
    cout << "Courses " << (canFinishCourses ? "can " : "can't ") << "be finished!" << endl;
}
