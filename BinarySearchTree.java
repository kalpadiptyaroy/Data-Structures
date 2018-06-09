import java.util.*;
class BinarySearchTree
{
    Node start = null; int level = 0, a[][];  int f = 0;
    public void input()
    {
        int ch;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1 to continue OR Enter 0 to End");
        do
        {        
            System.out.print("Enter a No: ");
            int n = sc.nextInt();     addToTree(n);
            System.out.print("Enter Command: ");
            ch = sc.nextInt();
        }
        while(ch != 0);
    }
    public void addToTree(int x)
    {
        Node temp = new Node(x, 0, 0);        
        if(start == null)         start = temp;
        else                      placeInTree(start, x);
    }
    public void placeInTree(Node root, int x)
    {
        if(root != null)
        {
            if(root.data == x)
                System.out.println("Data already Exists in the Tree");
            else if(x < root.data)
            {
                if(root.Left == null)
                    root.Left = new Node(x, root.x + 1, (root.y * 2));
                else
                    placeInTree(root.Left, x);
            }
            else
            {
                if(root.Right == null)
                    root.Right = new Node(x, root.x + 1,(root.y * 2) + 1) ;
                else
                    placeInTree(root.Right, x);
            }
        }
    }
    public void countLevels(Node Root)
    {
        if(Root != null)
        {
            level++;    countLevels(Root.Left);     countLevels(Root.Right);
        }         
    }
    public void placeInMatrix(Node Root)
    {
        if(Root != null)
        {
            a[Root.x][Root.y] = Root.data;
            placeInMatrix(Root.Left);    placeInMatrix(Root.Right);
        }
    }
    public int power(int x, int n)
    {
        if(n == 0)         return 1;
        else               return 2 * power(2, n - 1);
    }
    public void displayTree(String s)
    {        
        System.out.println("\n");        
        int row = level + 4, column = power(2, level) + 4;
        a = new int[row][column];

        String factor = "";        
        for(int i = 1; i < power(2, level); i++)
            factor = factor + " ";
        factor = factor + factor;

        placeInMatrix(start);

        if(s.charAt(0) == '*')
        {
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)            
                    if(a[i][j] == 0)
                        System.out.print(factor + "  " + factor + factor + " ");
                    else
                        System.out.print(factor + a[i][j] + factor + factor + " ");              
                System.out.println("\n");     int sp = factor.length();
                factor = factor.substring(0, sp / 2);
            }  
        }
        else
        {
            int sr = Integer.parseInt(s);
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)            
                    if(a[i][j] == 0)
                        System.out.print(factor + "  " + factor + factor + " ");
                    else if(a[i][j] == sr)
                        {
                            System.out.print(factor + "|" + a[i][j] + "|" + factor + factor + " "); f = 1;
                            break;
                        }
                    else 
                        System.out.print(factor + a[i][j] + factor + factor + " ");
                 if(f == 1) break;
                System.out.println("\n");     int sp = factor.length();
                factor = factor.substring(0, sp / 2);
            }  
        }
    }
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        BinarySearchTree ob = new BinarySearchTree();
        ob.input();
        ob.countLevels(ob.start);
        ob.level = (int)(Math.log(ob.level + 1) / Math.log(2)) + 1;
        ob.displayTree("*");
        System.out.print("Enter The No to Search: ");
        int s = sc.nextInt();
        ob.displayTree(Integer.toString(s));
        if(ob.f == 1)
        System.out.println("\nSearch Successful");
        else
        System.out.println("Search Unsuccessful");
    }
}
