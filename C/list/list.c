#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing the student
typedef struct Student 
{
    char surname[20];
    char name[10];
    char patronymic[20];
    
    int age;
    int average_score;
    
    struct Student *next;
    struct Student *prev;
    
} stud;

// Structure representing the list of students
typedef struct 
{
    stud *head;
    stud *tail;
    size_t size;
    
} stud_List;

/**
 * @brief Prints the entire student list.
 * @param list A pointer to the student list.
 * @return void.
 */
void printstud_List(stud_List *list);

/**
 * @brief Creates and initializes a new student list.
 * @return A pointer to the newly created student list.
 */
stud_List* createList();

/**
 * @brief Adds a student to the beginning of the list.
 * @param list A pointer to the student list.
 * @return void
 */
void addStudBeg(stud_List *list);

/**
 * @brief Adds a student to the end of the list.
 * @param list A pointer to the student list.
 * @return void
 */
void addStudEnd(stud_List *list);


/**
 * @brief Sorts the student list by surname and name.
 * @param list A pointer to the student list.
 * @return void
 */
void sortStudList(stud_List *list);

/**
 * @brief Searches and prints students by a given surname.
 * @param list A pointer to the student list.
 * @param surname The surname to search for.
 * @return void
 */
void searchAndPrintBySurname(stud_List *list, const char *surname);

/**
 * @brief Deletes all students with a given surname from the list.
 * @param list A pointer to the student list.
 * @param surname The surname of the students to delete.
 * @return The number of students deleted.
 */
int del_Nth(stud_List * list, char *surname);


/**
 * @brief Finds a student by surname.
 * @param list A pointer to the student list.
 * @param surname The surname to search for.
 * @return A pointer to the found student, or NULL if not found.
 */
stud *findStudentBySurname(stud_List *list, const char *surname);

/**
 * @brief Adds a new student after a student with a specific surname.
 * @param list A pointer to the student list.
 * @param surname The surname after which the new student should be added.
 * @param newStudentData The new student data to add.
 * @return void
 */
void addStudentAfter(stud_List *list, const char *surname, stud *newStudentData);

/**
 * @brief Prints students by performance categories.
 * @param list A pointer to the student list.
 * @return void
 */
void printStudByPerf(stud_List *list);

/**
 * @brief Helper function to print students by performance categories to a specified file.
 * @param list A pointer to the student list.
 * @param output A file pointer to write the output.
 * @return void
 */
void printStudentsByPerformanceHelper(stud_List *list, FILE *output); 

/**
 * @brief Frees the memory allocated for the student list.
 * @param list A pointer to the student list.
 * @return void
 */
void freeList(stud_List *list);

/**
 * @brief Loads the student list from a file.
 * @param list A pointer to the student list.
 * @param filename The name of the file to load the list from.
 * @return void
 */
void loadListFromFile(stud_List *list, const char *filename);

/**
 * @brief Saves the student list to a file.
 * @param list A pointer to the student list.
 * @param filename The name of the file to save the list to.
 * @return void
 */
void saveListToFile(stud_List *list, const char *filename);

/**
 * @brief Prints students by performance categories to a specified file.
 * @param list A pointer to the student list.
 * @param filename The name of the file to print the students to.
 * @return void
 */
void printStudentsByPerformanceToFile(stud_List *list, const char *filename);

int main() 
{
    stud_List *list = createList();
    
    loadListFromFile(list, "students.txt");
    
    int choice;
    
    char surname[20], name[10], patronymic[20];
    int age, average_score;

    do {
        printf("\nMenu:\n");
        printf("1. Add a student to the start of the list\n");
        printf("2. Add a student to the end of the list\n");
        printf("3. Add a student after a specific surname\n");
        printf("4. View the entire group\n");
        printf("5. Search for students by surname\n");
        printf("6. Withdrawal of students by performance\n");
        printf("7. Delete a student with a given surname\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                addStudBeg(list);

                printf("\nUnsorted: ");
                printstud_List(list);

                sortStudList(list);
            	saveListToFile(list, "students.txt");
                break;
            case 2:
            	addStudEnd(list);

                printf("\nUnsorted: ");
                printstud_List(list);

            	sortStudList(list);
            	saveListToFile(list, "students.txt");
                break;
            case 3:
            	printf("Enter the surname to add a new student after: ");
    			scanf("%49s", surname);
    
    			stud *newStudentData = malloc(sizeof(stud));
    			if (newStudentData == NULL) 
				{
        			printf("Memory allocation failed.\n");
        			exit(EXIT_FAILURE);
    			}
    
    			printf("\nEnter surname: ");
    			scanf("%19s", newStudentData->surname);
    			printf("Enter name: ");
    			scanf("%9s", newStudentData->name);
    			printf("Enter patronymic: ");
   		 		scanf("%19s", newStudentData->patronymic);
    			printf("Enter age: ");
    			scanf("%d", &newStudentData->age);
    			printf("Enter average grade: ");
    			scanf("%d", &newStudentData->average_score);

				addStudentAfter(list, surname, newStudentData);

                printf("\nUnsorted: ");
                printstud_List(list);

				sortStudList(list);
                saveListToFile(list, "students.txt");
                break;
            case 4:
                printstud_List(list);
                saveListToFile(list, "students.txt");
                break;
            case 5:
                printf("Enter the surname to search: ");
    			scanf("%49s", surname);
    			
    			searchAndPrintBySurname(list, surname);
                break;
            case 6:
                printStudByPerf(list); 
            	printStudentsByPerformanceToFile(list, "grades.txt");
            	break;
            case 7:
                printf("Enter the surname of students to delete: ");
                scanf("%49s", surname);

                int deletedCount = del_Nth(list, surname);
    
                if (deletedCount > 0) 
                {
                    printf("%d students with the surname %s were deleted.\n", deletedCount, surname);
                } else {
                    printf("No students with the surname %s found.\n", surname);
                }

                saveListToFile(list, "students.txt");
                break;
            case 8:
                printf("Exiting...\n");
                freeList(list);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void printstud_List(stud_List *list) 
{
    // Check if the list is empty
    if (list == NULL || list->head == NULL) 
	{
        printf("The list is empty.\n");
        return;
    }

    stud *current = list->head;
    
    // Print table header
    printf("\n%-20s %-10s %-20s %-10s %-10s\n", "Surname", "Name", "Patronymic", "Age", "Grade");
    printf("-------------------------------------------------------------------------------\n");
    
    // Go through and print all elements of the list
    while (current != NULL) 
	{
        printf("%-20s %-10s %-20s %-10d %-10d\n", 
               current->surname, 
               current->name, 
               current->patronymic, 
               current->age, 
               current->average_score);
        current = current->next;
    }
    printf("\n");
}

stud_List* createList() 
{
    // Allocate memory for the new list structure
	stud_List *tmp = (stud_List*) malloc(sizeof(stud_List));
    
    if (tmp == NULL) 
	{
        // If memory is not allocated, print an error message
        printf("Error allocating memory\n");
        return NULL;
    }
    
    // Initialize pointers and list size
    tmp->head = tmp->tail = NULL;
    tmp->size = 0;
    
    return tmp;
}

void addStudBeg(stud_List *list) 
{
    // Allocate memory for the new node
    stud* new_node = malloc(sizeof(stud));
    
    if (new_node == NULL) 
	{
        // If memory is not allocated, display an error message
    	printf("Error allocating memory\n");
        return;
	}
	
    // Read student data from the keyboard
	printf("\nEnter surname: ");
    scanf("%19s", new_node->surname);
    printf("Enter name: ");
    scanf("%9s", new_node->name);
    printf("Enter patronymic: ");
    scanf("%19s", new_node->patronymic);
    
    printf("Enter age: ");
    scanf("%d", &new_node->age);
    
    printf("Enter average Grade: ");
    scanf("%d", &new_node->average_score);

    // Add the node to the beginning of the list
    new_node->next = list->head;
    new_node->prev = NULL;
    
    if (list->head != NULL) 
	{ 
        // If the list is not empty, update the pointer to the previous element of the old head
        list->head->prev = new_node; 
    } 
    
    else
    {
        // If the list was empty, set the new node as the tail
    	list->tail = new_node;
	}
    
    list->head = new_node;

    // Increase the size of the list
    list->size++;
}

void addStudEnd(stud_List *list) 
{
    // Allocate memory for the new node
    stud *new_node = malloc(sizeof(stud));
    if (new_node == NULL) 
	{
        printf("Error allocating memory\n");
        return;
    }

    // Read student data from the keyboard
    printf("\nEnter surname: ");
    scanf("%19s", new_node->surname);
    printf("Enter name: ");
    scanf("%9s", new_node->name);
    printf("Enter patronymic: ");
    scanf("%19s", new_node->patronymic);
    printf("Enter age: ");
    scanf("%d", &new_node->age);
    printf("Enter average Grade: ");
    scanf("%d", &new_node->average_score);
    
    // Set next for the new node as NULL, since it will be the last one
    new_node->next = NULL;  
    
    if (list->head == NULL) 
	{
        // If the list is empty, set the new node as the head and tail of the list
        list->head = new_node; 
        list->tail = new_node;
        new_node->prev = NULL;  
    } 
    
    else 
    {
        // Otherwise, add a new node to the end of the list
        list->tail->next = new_node; 
        new_node->prev = list->tail; 
        list->tail = new_node;       
    }

    // Increase the size of the list
    list->size++;  
}

void sortStudList(stud_List *list) 
{
    // Check if there are items to be sorted
    if (!list->head || !list->head->next) return;

    int swapped;
    do 
    {
        swapped = 0;
        stud *current = list->head;
        
        while (current->next) 
        {
            if (strcmp(current->surname, current->next->surname) > 0 || 
               (strcmp(current->surname, current->next->surname) == 0 && strcmp(current->name, current->next->name) > 0)) {
                
                // Exchange nodes if the current node is larger than the next node
                stud *next = current->next;
                stud *prev = current->prev;

                if (prev) 
                {
                    prev->next = next;
                } 
                
                else 
                {
                    list->head = next;
                }
                
                current->next = next->next;
                current->prev = next;
                next->next = current;
                next->prev = prev;

                if (current->next) 
                {
                    current->next->prev = current;
                } 

                else 
                {
                    list->tail = current;
                }

                swapped = 1;
            } 
            
            else 
            {
                current = current->next;
            }
        }
    } while (swapped);
}


void searchAndPrintBySurname(stud_List *list, const char *surname) 
{
    // Check if the list is empty
    if (list == NULL || list->head == NULL) 
	{
        printf("The list is empty.\n");
        return;
    }

    stud *current = list->head;
    int found = 0;

    // Print table header
    printf("\n%-20s %-10s %-20s %-10s %-10s\n", "Surname", "Name", "Patronymic", "Age", "Grade");
    printf("-------------------------------------------------------------------------------\n");

    // Search for students with the specified last name
    while (current != NULL)
	{
        if (strcmp(current->surname, surname) == 0) 
		{
            printf("%-20s %-10s %-20s %-10d %-10d\n",
                   current->surname, 
                   current->name, 
                   current->patronymic, 
                   current->age, 
                   current->average_score);
            found = 1;
        }
        current = current->next;
    }

    if (!found) 
	{
        printf("No student found with the surname '%s'.\n", surname);
    }
}

int del_Nth(stud_List * list, char *surname) 
{
    // Check if the list is empty and if the input data is correct
    if (list == NULL || list->head == NULL || surname == NULL) 
    {
        return 0;
    }
    
    stud *current = list->head;
    int count = 0;
    int surnameCount = 0;

    // First, count the number of students with the same surname
    while (current != NULL) 
    {
        if (strcmp(current->surname, surname) == 0) 
        {
            surnameCount++;
        }
        current = current->next;
    }

    // If multiple students with the same surname are found, ask for the name
    char name[20] = "";
    if (surnameCount > 1) 
    {
        printf("There are %d students with the surname %s. Please enter the name: ", surnameCount, surname);
        scanf("%19s", name);
    }

    current = list->head;
    while (current != NULL) 
    {
        stud *next = current->next;
        if (strcmp(current->surname, surname) == 0 && (surnameCount == 1 || strcmp(current->name, name) == 0)) 
        {
            // Delete the node
            if (current->prev) 
            {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            
            if (current->next) 
            {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current);
            list->size--; 
            count++;
        }
        current = next;
    }

    return count;
}

stud *findStudentBySurname(stud_List *list, const char *surname) 
{
	// Check if the list is empty
    if (list == NULL || list->head == NULL) 
	{
        printf("The list is empty or NULL.\n");
        return NULL;  
    }

    stud *current = list->head;
    
    // Search for a student with the specified last name
    while (current != NULL) 
	{
        if (strcmp(current->surname, surname) == 0)
		{
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addStudentAfter(stud_List *list, const char *surname, stud *newStudentData) 
{
    // Search for a student with the specified last name
    stud *foundStud = findStudentBySurname(list, surname);
    if (foundStud == NULL) 
    {
        printf("No student found with the surname: %s\n", surname);
        free(newStudentData);
        return;
    }

    // Allocate memory for the new student
    stud *newStud = (stud *)malloc(sizeof(stud));
    if (newStud == NULL) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Copy the data
    *newStud = *newStudentData;  

    // Insert a new student after the found one
    newStud->next = foundStud->next;  
    newStud->prev = foundStud;        

    if (foundStud->next != NULL)      
    {
        foundStud->next->prev = newStud;  
    }
    foundStud->next = newStud;  

    if (newStud->next == NULL)  
    {
        list->tail = newStud;   
    }
}

void printStudentsByPerformanceHelper(stud_List *list, FILE *output) 
{
    // Check if the list is empty
    if (list == NULL || list->head == NULL) 
    {
        fprintf(output, "The list is empty.\n");
        return;
    }

    // Print students by grade category
    fprintf(output, "\nExcellent (90-100):\n");
    int found = 0;
    stud *current = list->head;
    while (current != NULL) 
    {
        if (current->average_score >= 90 && current->average_score <= 100) 
        {
            fprintf(output, "%-20s %-10s %-20s %-10d %-10d\n", current->surname, current->name, current->patronymic, current->age, current->average_score);
            found = 1;
        }
        current = current->next;
    }
    if (!found) fprintf(output, "No students found\n");

    fprintf(output, "\nGood (70-89):\n");
    found = 0;
    current = list->head;
    while (current != NULL) 
    {
        if (current->average_score >= 70 && current->average_score <= 89) 
        {
            fprintf(output, "%-20s %-10s %-20s %-10d %-10d\n", current->surname, current->name, current->patronymic, current->age, current->average_score);
            found = 1;
        }
        current = current->next;
    }
    if (!found) fprintf(output, "No students found\n");

    fprintf(output, "\nSatisfactory (50-69):\n");
    found = 0;
    current = list->head;
    while (current != NULL) 
    {
        if (current->average_score >= 50 && current->average_score <= 69) 
        {
            fprintf(output, "%-20s %-10s %-20s %-10d %-10d\n", current->surname, current->name, current->patronymic, current->age, current->average_score);
            found = 1;
        }
        current = current->next;
    }
    if (!found) fprintf(output, "No students found\n");

    fprintf(output, "\nUnsatisfactory (0-49):\n");
    found = 0;
    current = list->head;
    while (current != NULL) 
    {
        if (current->average_score >= 0 && current->average_score <= 49) 
        {
            fprintf(output, "%-20s %-10s %-20s %-10d %-10d\n", current->surname, current->name, current->patronymic, current->age, current->average_score);
            found = 1;
        }
        current = current->next;
    }
    if (!found) fprintf(output, "No students found\n");
}

void printStudByPerf(stud_List *list) 
{
    printStudentsByPerformanceHelper(list, stdout);
}

void freeList(stud_List *list) 
{
    stud *current = list->head;
    while (current != NULL) 
    {
        stud *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void loadListFromFile(stud_List *list, const char *filename) 
{
    FILE *file = fopen(filename, "r");

    if (!file) 
    {
        perror("Error opening file for reading");
        return;
    }

    stud buffer;
    while (fscanf(file, "%19s %9s %19s %d %d",
                  buffer.surname,
                  buffer.name,
                  buffer.patronymic,
                  &buffer.age,
                  &buffer.average_score) == 5) {

        stud *newStudent = malloc(sizeof(stud));

        if (!newStudent) 
        {
            perror("Memory allocation failed");
            fclose(file);
            return;
        }
        *newStudent = buffer;
        newStudent->next = NULL;
        newStudent->prev = NULL;

        if (list->head == NULL) 
        {
            list->head = list->tail = newStudent;
        } 

        else 
        {
            list->tail->next = newStudent;
            newStudent->prev = list->tail;
            list->tail = newStudent;
        }
        list->size++;
    }

    fclose(file);
}

void saveListToFile(stud_List *list, const char *filename) 
{
    FILE *file = fopen(filename, "w");

    if (!file) 
    {
        perror("Error opening file for writing");
        return;
    }

    stud *current = list->head;
    while (current != NULL) 
    {
        fprintf(file, "%s %s %s %d %d\n",
                current->surname, current->name, current->patronymic, current->age, current->average_score);
        current = current->next;
    }

    fclose(file);
}

void printStudentsByPerformanceToFile(stud_List *list, const char *filename) 
{
    FILE *file = fopen(filename, "w");
    if (!file) 
    {
        perror("Error opening file for writing");
        return;
    }

    printStudentsByPerformanceHelper(list, file);

    fclose(file);
}