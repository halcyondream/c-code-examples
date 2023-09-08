Differences from Chapter 6 code:

- Use of NULL after free statements
- deleteAllNodes functionality
- Constructor and destructor behaviors

Errata:

- In the book, the "enqueue" operation prepends the new list item. This should probably be an append/addTail operation.
- The stack behavior mimicks the queue behavior under the hood. The order in which items are placed versus accessed is the only meaningful difference between the two structures anyway. This saves N-1 operations every time `pop` is called (or `dequeue` in the book).

Other notes:

- Use of header files and a makefile
- Placement of asterisk on the data type (more Go-like)