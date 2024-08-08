# Binary Search Tree in C

This program implements a binary search tree (BST) in C, providing operations such as adding, searching, deleting, and replacing nodes. It also supports tree traversal and counting nodes at each level using a queue.

## Features

- **Add Node**: Insert a new node into the tree.
- **Search Node**: Find a node by its value.
- **Delete Node**: Remove a node from the tree.
- **Replace Node**: Replace a node's value with a new one.
- **Tree Traversals**:
  - Pre-order (Root, Left, Right)
  - In-order (Left, Root, Right)
  - Post-order (Left, Right, Root)
  - Level-order (Breadth-first)
- **Count Nodes**: Display the number of nodes at each level.

## Usage

1. **Compile the Program**:

   ```bash
   gcc -o bst bst.c

## Run the Program
  
1. **Run**:

   ```bash
   ./bst
   
## Menu Options:

- Add, search, delete, or replace nodes.
- Print the tree and perform traversals.
- Count nodes at each level.

# Student List Management in C

This C program manages a list of students with operations to add, delete, search, and sort students. The list is implemented as a doubly linked list and supports reading from and writing to files.

## Features

- **Add Student**: Add a student to the beginning or end of the list, or after a student with a specific surname.
- **Delete Student**: Remove all students with a given surname.
- **Search**: Find and display students by surname.
- **Sort**: Sort the student list by surname and name.
- **Performance Categorization**: Print students categorized by their average scores (Excellent, Good, Satisfactory, Unsatisfactory).
- **File Operations**:
  - **Load**: Load student data from a file.
  - **Save**: Save student data to a file.
  - **Print by Performance**: Save categorized student data to a file.

## Usage

1. **Compile the Program**:

   ```bash
   gcc -o list list.c

## Run the Program
  
1. **Run**:

   ```bash
   ./list
   
## Menu Options:

- Add a student to the start of the list
- Add a student to the end of the list
- Add a student after a specific surname
- View the entire list
- Search for students by surname
- Print students by performance categories
- Delete students with a given surname
- Exit

## Files:

- **students.txt**: Default file for saving/loading student data.
- **grades.txt**: File for saving students categorized by performance.

# Product Management System in Java

This program is a simple product management system implemented in Java. It provides various functionalities for managing a list of products in a warehouse, including adding, updating, and removing products. It also allows you to manage product quantities and calculate the total value of all products.

## Features

- **Print All Products**: Display a list of all products with their details.
- **Add New Product**: Add a new product to the list, including its name, price per kilogram, and quantity.
- **Add Quantity**: Increase the quantity of an existing product.
- **Remove Quantity**: Decrease the quantity of an existing product.
- **Calculate Total Value**: Compute the total value of all products based on their price and quantity.
- **Remove Product**: Remove a product from the list by its name.
- **Update Product Price**: Change the price per kilogram of an existing product.

## Usage

1. **Compile the Program**:

   ```bash
   javac Main.java

## Run the Program
  
1. **Run**:

   ```bash
   java Main
   
## Menu Options:

- Print all products: Lists all products with their details.
- Add a new product: Prompts for product details and adds a new product.
- Add quantity to a product: Allows you to specify a product and the quantity to add.
- Remove quantity from a product: Allows you to specify a product and the quantity to remove.
- Calculate total value of all products: Displays the total value of all products.
- Remove a product: Prompts for the product name and removes it from the list.
- Update price of a product: Allows you to specify a product and the new price per kilogram.
- Exit: Terminates the program.

## License

This project is licensed under the [MIT License](LICENSE).
