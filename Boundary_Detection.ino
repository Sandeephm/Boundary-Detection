struct node
{
    int info;
    struct node *next;
}*start;
 
/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int);
        void insert_begin(int);
        void insert_pos(int,int);
        void insert_last(int); 
        void delete_pos(int);
        void sort();
        void search(int);
        void update_(int,int);
        void reverse();
        void display_();
        single_llist() 
        {
            start = NULL;
        }
};
 
node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        Serial.println("Memory not allocated \n");
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
 
/*
 * Inserting element in beginning
 */
void single_llist::insert_begin(int value)
{
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    Serial.println("Element Inserted at beginning\n");
}
 
/*
 * Inserting Node at last
 */
void single_llist::insert_last(int value)
{
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
}
 
/*
 * Insertion of node at a given position
 */
void single_llist::insert_pos(int value,int pos)
{
    int counter = 0; 
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        Serial.println("Positon out of range\n");
    }
}
 
/*
 * Sorting Link List
 */
void single_llist::sort()
{
    struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        Serial.println("The List is empty \n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info > s->info)
            {
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}
 
/*
 * Delete element at a given position
 */
void single_llist::delete_pos(int pos)
{
    int i, counter = 0;
    if (start == NULL)
    {
        Serial.println("List is empty");
        return;
    }
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            Serial.println("Position out of range");
        }
        free(s);
    }
}
 
/*
 * Update a given Node
 */
void single_llist::update_(int value,int pos)
{
    int i;
    if (start == NULL)
    {
        Serial.println("List is empty");
        return;
    }
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->info = value; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                return;
            }
            s = s->next;
        }
        s->info = value;  
    }
    Serial.println("Node Updated");
} 
 
/*
 * Searching an element
 */
void single_llist::search(int value)
{
    int pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        Serial.println("List is empty");
        return;
    }
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
        }
        s = s->next;
    }
}
 
/*
 * Reverse Link List
 */
void single_llist::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        Serial.println("List is empty");
        return;
    }
    if (start->next == NULL)
    {
        return;
    }  
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
 
/*
 * Display Elements of a link list
 */
void single_llist::display_()
{
    struct node *temp;
    if (start == NULL)
    {
        Serial.println("The List is Empty");
        return;
    }
    temp = start;
    Serial.println("Elements of list are: ");
    while (temp != NULL)
    {
        Serial.print(temp->info);Serial.print("->");
        temp = temp->next;
        Serial.println("\n");
    }
    Serial.println("NULL");
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{

}