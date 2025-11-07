class node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root=None):
        self.root = root
        self.lar_len = []
    
    def inorder(self):
        ret = []
        def __inorder(node):
            if node == None:return
            __inorder(node.left)
            ret.append(node.data)
            __inorder(node.right)
        __inorder(self.root)
        return ret

    def largest_BST(self):
        res, len1 = self.checkBST(self.root)
        if res:
            return self.root, len1
        else:
            temp = [self.root,]
            new_temp = []
            while len(temp) != 0:
                for i in temp:
                    res, len1 = self.next_BST(i)
                    if res:
                        return res, len1
                    new_temp += [i.left, i.right]
                new_temp1 = []
                for i in new_temp:
                    if i:
                        new_temp1.append(i)
                if len(new_temp1) == 0:
                    return None
                temp = new_temp1

    def next_BST(self, n):
        if n.left:
            res, len = self.checkBST(n.left)
            if res:
                return n.left, len
        if n.right:
            res, len = self.checkBST(n.right)
            if res:
                return n.right, len
        return None, None


    def checkBST(self, n, left=None, pred=None, len=1):
        ret1 = None
        ret2 = None
        len1 = len2 = None
        if n.left:
            if n.data < n.left.data:
                ret1 = False
            else:
                ret1, len1 = self.checkBST(n.left, True, n.data, len+1)
                if ret1 and pred and left==False:
                    if pred > n.left.data:
                        ret1 = False
                if ret1 and pred and left:
                    if pred < n.left.data:
                        ret1 = False
        if n.right:
            if n.data > n.right.data:
                ret2 = False
            else:
                ret2, len2 = self.checkBST(n.right, False, n.data, len+1)
                if ret2 and pred and left==False:
                    if pred > n.right.data:
                        ret2 = False
                if ret2 and pred and left:
                    if pred < n.right.data:
                        ret2 = False
        if not n.left and not n.right:
            return True, len
        if ret1 != None and ret2 != None:
            return ret1 and ret2, max(len1 if len1 else 0, len2 if len2 else 0)
        if ret1 != None:
            return ret1, len1
        else:
            return ret2, len2

bst = BinaryTree()
bst.root = node(4)
bst.root.left = node(2)
bst.root.right = node(7)
bst.root.left.left = node(100)
bst.root.left.right = node(3)
bst.root.right.left = node(-5)
bst.root.right.right = node(12)
b, l = bst.largest_BST()
b = BinaryTree(b)
print(b.inorder(), l)

