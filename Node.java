class Node
{
    int data;   Node Right, Left;
    int x, y;
    public Node()
    {
        data = 0; x = 0; y = 0;
        Right = null;
        Left = null;
    }
    public Node(int data)
    {
        this.data = data; x = 0; y = 0;
        Right = null;
        Left = null;
    }
    public Node(int data, int x, int y)
    {
        this.data = data;
        this.x = x;     this.y = y;
        Right = null;   Left = null;
    }
}
