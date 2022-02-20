#
# ucost.py
#
# This file provides a function implementing uniform cost search for a
# route finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier.
#
# YOUR COMMENTS INCLUDING CITATIONS
#
# YOUR NAME - THE DATE
#


from route import Node
from route import Frontier


def uniform_cost_search(problem, repeat_check=False):
    """Perform uniform cost search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    if repeat_check == True:
        root = Node(problem.start)
        if root.loc == problem.goal:
            return root
        
        # Priority Queue Sorted by h_eval (h_cost)
        queue = Frontier(root)
        checkState = []
        checkState.append(root)

        while not queue.is_empty():
            node = queue.pop()
            if node.loc == problem.goal:
                return node
            else:
                children = []
                # When h_fun != NONE, then we will calculate the h_cost
                #   for each child of the parent node
                children.extend(node.expand(problem))
                for i in children:
                    if i not in checkState:
                        queue.add(i)
                        checkState.append(i)
        
        return None

    else:
        root = Node(problem.start)
        if root.loc == problem.goal:
            return root
        
        queue = Frontier(root)

        while not queue.is_empty():
            node = queue.pop()
            if node.loc == problem.goal:
                return node
            else:
                children = []
                children.extend(node.expand(problem))
                for i in children:
                    queue.add(i)
        
        return None

    return None
