class BTNode():

    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def __str__(self):
        return str(self.value)


class BinarySearchTree():

    def __init__(self, head=None):
        if head:
            self.root = BTNode(head)
            self.size = 1
        else:
            self.root = None
            self.size  = 0

    

    def rec_insert(self, current, value):
        if current == None:
            return BTNode(value)
        
        elif value > current.value:
            current.right = self.rec_insert(current.right, value)
        
        else:
            current.left = self.rec_insert(current.left, value)

        return current


    #Recusrive insert function
    def insert(self, value):
        self.rec_insert(self.root, value)



    def height(self, node):

        #Make sure that this base case works properly
        if node == None:
            return 0
        
        leftHeight = self.height(node.left)
        rightHeight = self.height(node.right)

        height_of_node = max(leftHeight, rightHeight) + 1

        return height_of_node



    def get_total_height(self):

        #Height of an Empty Tree is equal to -1
        if self.head == None:
            return -1

        #Iterate through the tree
            #find the hieght of each node and add it to a list

        
        #sum all elements of the list

        

    ###MAKE RECURSIVE     AND INTEGRATE NUMCHILDREN###
    def delete(self, value):

        #Finding the node  ###MAKE THIS RECURSIVE???###
        node_to_delete = None
        
        parent = None
        cur = self.root

        while cur != None:

            if value == cur.value:
                node_to_delete == cur

            if value < cur.value:
                parent = cur
                cur = cur.left
            elif value > cur.value:
                parent = cur
                cur = cur.right


        #Target Node is a Leaf
        if node_to_delete.left == None and node_to_delete.right == None:

            #If cur is a root Node
            if parent == None:
                self.root = None

            #If cur is not a root Node
            else:

                if parent.left == node_to_delete:
                    parent.left = None
                else:
                    parent.right = None

        


        #Target Node has one child

        #Target Node has left child ony
        elif node_to_delete.left != None and node_to_delete.right == None:

            #If target node is the root node
            if parent == None:
                self.root = node_to_delete.left

            else:
                parent.left = node_to_delete.left


        #Target Node has right child only
        elif node_to_delete.left == None and node_to_delete.right != None:

            #If target node is the root node
            if parent == None:
                self.root = node_to_delete.right

            else:
                parent.right = node_to_delete.right




        #Target Node has two children

        elif node_to_delete.left != None and node_to_delete.right != None:

            #New node is the biggest node in the left subtree
            new_node = self.getMax(node_to_delete.left)

            node_to_delete = new_node

            #find and delete new_node
            ###########################NO IDEA IF THIS WORKS IT MIGHT BREAK EVERYTHING###############
            self.delete(new_node.value)
            

        
    def getMin(root):

        if root == None:
            return -1
        
        while (root.left != None):
            root = root.left

        return root.value
    

    def getMax(root):
        if root == None:
            return -1
        
        while (root.right != None):
            root = root.right

        return root.value


    def numChildren(self, node):
        if node.left == None and node.right == None:
            return 0
        
        elif node.left == None and node.right != None:
            return 1
        
        elif node.left != None and node.right == None:
            return 1
        
        elif node.left != None and node.right != None:
            return 2
        
     
    def pre_order(self, cur, masterString):

       
        if cur == None:
            return masterString
        
        #Build the string
        masterString += "("
        masterString += str(cur.value)
        masterString += ","
        masterString += str(self.numChildren(cur))
        masterString += ")"
        masterString += "|"

        ###THIS ISN'T WORKING BC WE ARE NOT SAVING MASTERSTRING###
        self.pre_order(cur.left, masterString)
        self.pre_order(cur.right, masterString)


    def save(self):

        string = ""
        
        masterString = self.pre_order(self.root, string)

        return masterString




    def restore(self, input_string):

        nodes = input_string.split("|")

        print(nodes)


    



def main():
    my_tree = BinarySearchTree(5)

    my_tree.root.left = BTNode(3)
    my_tree.root.right = BTNode(8)

    print(my_tree.root)
    print(my_tree.root.left)

    my_tree.insert(4)

    print(my_tree.root.left.right)

    print(my_tree.save())



main()
