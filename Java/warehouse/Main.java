import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main 
{
    private static final ArrayList<Product> products = new ArrayList<>();

    public static void main(String[] args) 
    {
        // Adding some products to the warehouse for testing
        products.add(new Product("Apples", 2.5, 100));
        products.add(new Product("Bananas", 1.8, 150));
        products.add(new Product("Oranges", 3.0, 80));

        Scanner scanner = new Scanner(System.in);

        while (true) 
        {
            System.out.println("\n1. Print all products");
            System.out.println("2. Add a new product");
            System.out.println("3. Add quantity to a product");
            System.out.println("4. Remove quantity from a product");
            System.out.println("5. Calculate total value of all products");
            System.out.println("6. Remove a product");
            System.out.println("7. Update price of a product");
            System.out.println("8. Exit\n");

            System.out.print("Enter your choice: ");
            int choice = -1;
            try {
                choice = scanner.nextInt();
                scanner.nextLine();  // Consume newline
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.nextLine();  // Clear invalid input
                continue;
            }

            switch (choice) {
                case 1:
                    printAllProducts();
                    break;
                case 2:
                    addNewProduct(scanner);
                    break;
                case 3:
                    handleAddProductQuantity(scanner);
                    break;
                case 4:
                    handleRemoveProductQuantity(scanner);
                    break;
                case 5:
                    System.out.println("Total value of all products: " + calculateTotalValue());
                    break;
                case 6:
                    //removePriceIfZero(scanner);
                    removeProductByName(scanner);
                    break;
                case 7:
                    updateProductPrice(scanner);
                    break;
                case 8:
                    System.out.println("Exiting program.");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    /**
     * Method to print all products
     */
    public static void printAllProducts() 
    {
        for (Product product : products) {
            product.print();
        }
    }

    /**
     * Method to add a new product
     *
     * @param scanner the scanner object to read user input
     */
    public static void addNewProduct(Scanner scanner) 
    {
        System.out.print("Enter product name: ");
        String name = scanner.nextLine();

        // Check if the product already exists
        if (findProductByName(name) != null) 
        {
            System.out.println("Product already exists.");
            return;
        }

        System.out.print("Enter price per kilogram: ");
        double priceKg = scanner.nextDouble();

        System.out.print("Enter quantity: ");
        double quantity = scanner.nextDouble();
        
        scanner.nextLine();  // Consume newline

        try {
            Product newProduct = new Product(name, priceKg, quantity);
            products.add(newProduct);

            System.out.println("Product added successfully.");

        } catch (IllegalArgumentException e) {
            System.out.println("Invalid input. " + e.getMessage());
        }
    }

    /**
     * Method to add quantity to a product by name
     *
     * @param name     the name of the product
     * @param quantity the quantity to add
     */
    public static void addProductQuantity(String name, double quantity) 
    {
        Product product = findProductByName(name);

        if (product != null) {
            product.addQuantity(quantity);
            System.out.println("Added " + quantity + "kg to " + name);
        } else {
            System.out.println("Product not found.");
        }
    }

    /**
     * Method to remove quantity from a product by name
     *
     * @param name     the name of the product
     * @param quantity the quantity to remove
     */
    public static void removeProductQuantity(String name, double quantity) 
    {
        Product product = findProductByName(name);

        if (product != null) {
            product.removeQuantity(quantity);
            System.out.println("Removed " + quantity + "kg from " + name);
        } else {
            System.out.println("Product not found.");
        }
    }

    /**
     * Method to calculate total value of all products
     *
     * @return total value of all products
     */
    public static double calculateTotalValue() 
    {
        double totalValue = 0;
        for (Product product : products) {
            totalValue += product.getTotalValue();
        }
        return totalValue;
    }

    /**
     * Method to find a product by name
     *
     * @param name the name of the product
     * @return the product, or null if not found
     */
    private static Product findProductByName(String name) 
    {
        for (Product product : products) 
        {
            if (product.getName().equalsIgnoreCase(name)) {
                return product;
            }
        }
        return null;
    }

    /**
     * Handles the process of adding product quantity by prompting the user for input
     *
     * @param scanner the scanner object to read user input
     */
    private static void handleAddProductQuantity(Scanner scanner) 
    {
        System.out.print("Enter product name: ");
        String addName = scanner.nextLine();

        System.out.print("Enter quantity to add: ");
        try {
            double addQuantity = scanner.nextDouble();
            addProductQuantity(addName, addQuantity);
        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please enter a valid quantity.");
            scanner.nextLine();  // Clear invalid input
        }
    }

    /**
     * Handles the process of removing product quantity by prompting the user for input
     *
     * @param scanner the scanner object to read user input
     */
    private static void handleRemoveProductQuantity(Scanner scanner) 
    {
        System.out.print("Enter product name: ");
        String removeName = scanner.nextLine();

        System.out.print("Enter quantity to remove: ");
        try {
            double removeQuantity = scanner.nextDouble();
            removeProductQuantity(removeName, removeQuantity);
        } catch (InputMismatchException e) {
            System.out.println("Invalid input. Please enter a valid quantity.");
            scanner.nextLine();  // Clear invalid input
        }
    }

    // /**
    //  * Removes the price of a product if the current price is zero
    //  *
    //  * @param scanner the scanner object to read user input
    //  */
    // private static void removePriceIfZero(Scanner scanner) {
    //     System.out.print("Enter product name: ");
    //     String name = scanner.nextLine();
    //     Product product = findProductByName(name);

    //     if (product != null) {
    //         if (product.getPriceKg() == 0) {
    //             System.out.println("Price for " + name + " is already zero.");
    //         } else {
    //             product.setPriceKg(0);
    //             System.out.println("Price for " + name + " has been set to zero.");
    //         }
    //     } else {
    //         System.out.println("Product not found.");
    //     }
    // }

    /**
     * Updates the price of a product to a new value
     *
     * @param scanner the scanner object to read user input
     */
    private static void updateProductPrice(Scanner scanner) 
    {
        System.out.print("Enter product name: ");
        String name = scanner.nextLine();
        Product product = findProductByName(name);

        if (product != null) 
        {
            System.out.print("Enter the new price per kilogram: ");

            try {
                double newPriceKg = scanner.nextDouble();
                product.setPriceKg(newPriceKg);
                System.out.println("Price for " + name + " has been updated to " + newPriceKg + " per kg.");

            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid price.");
                scanner.nextLine();  // Clear invalid input
            }
        } else {
            System.out.println("Product not found.");
        }
    }

    /**
     * Removes a product from the list by its name
     *
     * @param scanner the scanner object to read user input
     */
    private static void removeProductByName(Scanner scanner) 
    {
        System.out.print("Enter product name to remove: ");
        String name = scanner.nextLine();
        Product product = findProductByName(name);

        if (product != null) 
        {
            products.remove(product);
            System.out.println("Product " + name + " has been removed.");

        } else {
            System.out.println("Product not found.");
        }
    }
}

