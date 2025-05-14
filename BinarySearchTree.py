
class TreeNode:
    def __init__(self,newItem, left, right) -> None:
        self.item:int = newItem
        #left is small
        self.left:TreeNode = left
        #right is big
        self.right:TreeNode = right

# it doesn't have any solution about bias
class BinarySearchTree:
    def __init__(self) -> None:
        self.__root:TreeNode = None

    def search(self, x : int) -> TreeNode:
        return self.__searchItem(self.__root, x)
    
    def __searchItem(self, tNode : TreeNode, x : int) -> TreeNode:
        if(tNode == None):
            return None
        elif(x == tNode.item):
            return tNode
        elif(x < tNode.item):
            return self.__searchItem(tNode.left, x)
        else:
            return self.__searchItem(tNode.right, x)

    #insert part    
    def insert(self, newItem):
        self.__root = self.__insertItem(self.__root,newItem)

    #when tNode is None, make new tNode. if left or right tNode is exist, go inside tNode until None
    def __insertItem(self, tNode : TreeNode, newItem) -> TreeNode:
        if(tNode  == None):
            tNode = TreeNode(newItem, None, None)
        elif(newItem < tNode.item): #branch left
            tNode.left = self.__insertItem(tNode.left, newItem)
        else:                       #branch right
            tNode.right = self.__insertItem(tNode.right, newItem)
        return tNode

    #delete part
    def delete(self, x):
        self.__root = self.__deleteItem(self.__root, x)

    def __deleteItem(self, tNode : TreeNode, x) -> TreeNode:
        if(tNode == None):
            return None         #Error, Item not found
        elif(x == tNode.item):  #item found
            tNode = self.__deleteNode(tNode)
        elif(x < tNode.item):
            tNode.left = self.__deleteItem(tNode.left, x)
        else:
            tNode.right = self.__deleteItem(tNode.right, x)
        return tNode    #tNode: parent에 매달리는 노드    
        
    def __deleteNode(self, tNode : TreeNode) -> TreeNode:
        #3 cases
        # 1. tNode == leaf
        # 2. tNode has one child
        # 3. tNode has two child

        if tNode.left == None and tNode.right == None:
            return None
        elif tNode.left == None:
            return tNode.right
        elif tNode.right == None:
            return tNode.left
        else:
            (rtnItem, rtnNode) = self.__deleteMinItem(tNode.right)
            tNode.item = rtnItem
            tNode.right = rtnNode
            return tNode

    def __deleteMinItem(self, tNode : TreeNode) -> TreeNode:
        if tNode.left == None:
            #find min at tNode
            return (tNode.item, tNode.right)
        else:
            (rtnItem, rtnNode) = self.__deleteMinItem(tNode.left)
            tNode.left = rtnNode
            return (rtnItem, rtnNode)
        

    def preOrder(self):
        self.__preOrder(self.__root)

    def __preOrder(self, r : TreeNode):
        if(r != None):
            self.__preOrder(r.left)
            print(r.item)
            self.__preOrder(r.right)


    def isEmpty(self) -> bool:
        return self.__root == None
    def clear(self):
        self.__root = None

bst1 = BinarySearchTree()
bst1.insert(20)
bst1.insert(10)
bst1.insert(5)
bst1.insert(15)
bst1.insert(80)
bst1.insert(90)
bst1.insert(755)
bst1.insert(30)
bst1.insert(77)

bst1.preOrder()

bst1.delete(755)
bst1.delete(10)
