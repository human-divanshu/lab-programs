class Tree():
    def __init__(self, state, children=None):
        self.value = state
        self.children = []
        if children is not None:
            for child in children:
                self.add_child(child)
                
    def __repr__(self):
        return self.name
        
    def add_child(self, node):
        assert isinstance(node, Tree)
        self.children.append(node)
        
# create tree with inital node
tree = Tree([0,0])
