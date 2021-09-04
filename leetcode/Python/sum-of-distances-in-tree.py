class Solution:
    def __init__(self):
        self.node_count = None
        self.sol = None
        self.graph = None
    def postorder(self, node, parent_node):
        '''
        calculate node_nums and dist value of child node
        '''
        self.node_count[node]=1
        for child_node in self.graph[node]:
            if child_node == parent_node:
                continue
            self.postorder(child_node,node)
            self.node_count[node]+=self.node_count[child_node]
            self.sol[node]+=self.sol[child_node]+self.node_count[child_node]
    def preorder(self, node, parent_node):
        '''
        calculate final dist val while traversiong node using (precalculated dist value of child_node)
        '''
        for child_node in self.graph[node]:
            if child_node == parent_node:
                continue
            self.sol[child_node]=self.sol[node]+len(self.graph)-2*self.node_count[child_node]
            self.preorder(child_node,node)
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        # 1. init variable
        self.node_count = [0]*n
        self.sol = [0]*n
        self.graph = [list() for i in range(n)]
        # 2. make graph
        for e in edges:
            self.graph[e[0]].append(e[1])
            self.graph[e[1]].append(e[0])
        # 3. postorder (to get dist, node_count of child)
        self.postorder(0,0)
        # 4. preorder (to get final dist value using precalculated dist of child)
        self.preorder(0,0)
        return self.sol
    