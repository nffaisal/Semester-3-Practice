import heapq  # gives us the priority queue
graph = {   # the way we can represent our function
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

heuristic = { # giving each node an estimate value
    'A': 5,
    'B': 4,
    'C': 2,
    'D': 6,
    'E': 3,
    'F': 0
}
goal =input("What is Goal State")
frontier =[]
start ='A' # our starting point
reached =set() # a set of values we have already expanded


heapq.heappush(frontier,(heuristic[start], start)) #added the start goal to the frontier and reached
reached.add(start)   #add it to reached as we;;

while frontier:  # until frontier is not empty
   value, node = heapq.heappop(frontier) # take out the tuple from the heap
   
   if node == goal:
     print("Goal found!" + node)
     break
   for child in graph[node]: #for every child value that is connected to the node we tae it and check if it is in reached and frontier yet or not
        if child not in reached:
            heapq.heappush(frontier,(heuristic[child],child))
            reached.add(child)
      
   