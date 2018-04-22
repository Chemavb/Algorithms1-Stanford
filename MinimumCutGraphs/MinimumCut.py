# -*- coding: utf-8 -*-
"""
Created on Sun Apr 22 12:21:06 2018

@author: chema
"""
for k in range(1,100):
    from random import randint
    aList = [[]]
    
    with open("D:\Stanford-Algorithms\MinimumCutGraphs\kargerMinCut.txt") as f:
        for line in f:
            lineList = line.split()
            lineListInt = list(map(int, lineList))
            aList.append(lineListInt[1:])
    
    
    #aList = [[],[2,5,6], [1,5,6,3], [2,7,8,4], [3,7,8], [1,2,6], [5,1,2,7], [6,3,4,8], [7,3,4]]
    #First row of adList = 0 so we use 1st index = 1 (first node/vertix)
    #print(aList[0][0])
    #print(len(aList))
    
    numVertixRemaining = len(aList) - 1
    
    while (numVertixRemaining > 2):
        #random row (random Node Origen)
        i = randint(1, len(aList)-1)
        while len(aList[i]) == 0:
            i = randint(1, len(aList)-1)
            
        #i = 1 #TODO: Change to random
        #j = 0 #TODO: Change to random
        j = randint(0, len(aList[i])-1)
        v = aList[i][j] #New vertix formed after the contraction
        aList[v].extend(aList[i])
        
        for vertix in aList[i]:
            listAdjacents = aList[vertix]
            #Find element i and swap with v
            new_listAdjacents = [v if x==i else x for x in listAdjacents]
            aList[vertix] = new_listAdjacents
        
        #Delete cycles in aList[v]
        listToDeleteCycles = aList[v]
        listNoCycles = [x for x in listToDeleteCycles if x != v]
        aList[v] = listNoCycles
        
        #Delete aList[i]
        aList[i] = []
        
        #One less vertix remaining
        numVertixRemaining = numVertixRemaining - 1
        
    #Count the number of edges between the two vertices remaining
    for vertixList in aList:
        if len(vertixList) != 0: #We have found a reimaing vertix
            print(len(vertixList)) #Print the number of edges with the other remaining vertix.
            break