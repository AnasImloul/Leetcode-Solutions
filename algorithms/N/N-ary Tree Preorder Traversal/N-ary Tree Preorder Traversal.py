function preorder(root: Node | null): number[] {
  const res: number[] = [];

  const getNodeVal = (node: Node | null): void => {
    if (node) {
      res.push(node.val);

      for (let i = 0; i < node.children.length; i++) {
        getNodeVal(node.children[i]);
      }
    }
  };

  getNodeVal(root);

  return res;
}

