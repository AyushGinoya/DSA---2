#include<iostream>
#include<queue>
using namespace std;

class node
{
        int data;
        node *lchild;
        node *rchild;
    public:
        node()
        {

        }
        node(int d)
        {
            lchild=rchild=NULL;
            data=d;
        }

        void create(node *root,node *nn)
        {
            if(root->data > nn->data)
            {
                if(root->lchild==NULL)
                {
                    root->lchild=nn;
                }
                else
                {
                    create(root->lchild,nn);
                }
            }
            else
            {
                if(root->rchild==NULL)
                {
                    root->rchild=nn;
                }
                else
                {
                    create(root->rchild,nn);
                }
            }
        }

        void preorder(node *root)
        {
            if(root==NULL)
            {
                return;
            }

            cout<<root->data<<"         ";
            preorder(root->lchild);
            preorder(root->rchild);
        }

        void inorder(node *root)
        {
            if(root==NULL)
            {
                return;
            }
            inorder(root->lchild);
            cout<<root->data<<"         ";
            inorder(root->rchild);
        }

        void postorder(node *root)
        {
            if(root==NULL)
                return;
            postorder(root->lchild);
            postorder(root->rchild);
            cout<<root->data<<"         ";
        }

        void lavelOrder(node *root)
        {
            if(root==NULL)
                return;

            queue <node *> q;
            q.push(root);

            while(!q.empty())
            {
                node *temp=q.front();
                    cout<<temp->data<<"         ";

                    if(temp->lchild!=NULL)
                        q.push(temp->lchild);

                    if(temp->rchild!=NULL)
                        q.push(temp->rchild);

                    q.pop();
            }
        }
};

int main()
{
    int n;
    cout<<"Enter node ";
    cin>>n;
    node *root=NULL;
    node t;

    for(int i=0;i<n;i++)
    {
        int d;
        cout<<"Enter node value ";
        cin>>d;
        if(root==NULL)
        {
            root = new node(d);
        }
        else
        {
            node *New=new node(d);
            t.create(root,New);
        }
    }

    cout<<endl<<endl;
     t.postorder(root);
     cout<<endl<<endl;
     t.preorder(root);
     cout<<endl<<endl;
     t.inorder(root);
     cout<<endl<<endl;
     t.lavelOrder(root);
}
