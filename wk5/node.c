

// initialize node to NULL to make sure there's no garbage value there.
node *list = NULL;
node *n = malloc(sizeof(node));

// (*n).number = 1;
n->number = 1;
n->next = NULL; // to signify this is the end of the list

// this allows list to point to first node directly without caring about n
list = n;

// allocate another node
node *n = malloc(sizeof(node));
n->number = 2;
list = n;