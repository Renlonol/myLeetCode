#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
    node(int d) : data(d), next(nullptr) {}
};

void print_list(struct node *head)
{
    while(head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}


struct node* create_list(int n)
{
    struct node *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        if (!head)
        {
            head = new node(d);
            continue;
        }
        struct node *new_node = new node(d);
        new_node->next = head;
        head = new_node;
    }
    return head;
}

//O(n^2)
struct node* sort_list(struct node* head)
{
    if (!head || !head->next)
        return head;

    struct node head_node(-1);
    head_node.next = head;

    struct node* p = &head_node;
    while (p->next) {
        struct node* q = p;
        int min_data = q->next->data;
        struct node* min_node_prev = p;
        // find the prev node of the min node
        while (q->next)
        {
            if (q->next->data < min_data)
            {
                min_node_prev = q;
                min_data = q->next->data;
            }
            q = q->next;
        }
        // move the min node
        if (min_node_prev != p)
        {
            struct node* min_node = min_node_prev->next;
            min_node_prev->next = min_node->next;
            min_node->next = p->next;
            p->next = min_node;
        }
        //print_list(head_node.next);
        p = p->next;
    }
    return head_node.next;
}

struct node* merge_sorted_list(struct node* mhead, struct node* nhead)
{
    if(!mhead)
        return nhead;

    if(!nhead)
        return mhead;

    struct node head_node(-1);
    struct node* p = &head_node;

    while (mhead && nhead)
    {
        if(mhead->data < nhead->data)
        {
            p->next = mhead;
            mhead = mhead->next;
        }
        else
        {
            p->next = nhead;
            nhead = nhead->next;
        }
        p->next->next = nullptr;
        p = p->next;
    }

    if(!mhead && nhead)
    {
        while(nhead)
        {
            p->next = nhead;
            nhead = nhead->next;
            p->next->next = nullptr;
            p = p->next;
        }
    }

    if(!nhead && mhead)
    {
        while(mhead)
        {
            p->next = mhead;
            mhead = mhead->next;
            p->next->next = nullptr;
            p = p->next;
        }
    }

    return head_node.next;
}


int main()
{
    int N, M;
    cin >> N;
    struct node* nhead = create_list(N);
    nhead = sort_list(nhead);
    //print_list(head);

    cin >> M;
    struct node* mhead = create_list(M);
    mhead = sort_list(mhead);

    struct node* merged_head =  merge_sorted_list(nhead, mhead);
    print_list(merged_head);
    return 0;
}
