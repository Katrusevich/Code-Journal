/**
 * Represents a product with a name, price per kilogram, and quantity.
 */
class Product 
{

    private String name;
    private double priceKg;
    private double quantity;

    /**
     * Constructs a Product with the specified name, price per kilogram, and quantity.
     *
     * @param name the name of the product
     * @param priceKg the price per kilogram of the product
     * @param quantity the initial quantity of the product
     * @throws IllegalArgumentException if priceKg or quantity is negative
     */

    public Product(String name, double priceKg, double quantity)
    {
        if (priceKg < 0 || quantity < 0) {
            throw new IllegalArgumentException("Price and quantity must be non-negative.");
        }

        this.name = name;
        this.priceKg = priceKg;
        this.quantity = quantity;
    }

     /**
     * Gets the name of the product.
     *
     * @return the name of the product
     */
    public String getName() {
        return name;
    }

    /**
     * Gets the price per kilogram of the product.
     *
     * @return the price per kilogram of the product
     */
    public double getPriceKg() {
        return priceKg;
    }

    /**
     * Gets the current quantity of the product.
     *
     * @return the quantity of the product
     */
    public double getQuantity() {
        return quantity;
    }

    /**
     * Sets the quantity of the product.
     *
     * @param quantity the new quantity of the product
     * @throws IllegalArgumentException if quantity is negative
     */
    public void setQuantity(double quantity) 
    {
        if (quantity < 0) {
            throw new IllegalArgumentException("Quantity must be non-negative.");
        }

        this.quantity = quantity;
    }

    /**
     * Adds the specified quantity to the current quantity of the product.
     *
     * @param quantity the quantity to add
     * @throws IllegalArgumentException if quantity to add is negative
     */
    public void addQuantity(double quantity) 
    {
        if (quantity < 0) {
            throw new IllegalArgumentException("Quantity to add must be non-negative.");
        }

        this.quantity += quantity;
    }

     /**
     * Removes the specified quantity from the current quantity of the product.
     *
     * @param quantity the quantity to remove
     * @throws IllegalArgumentException if quantity to remove is negative
     */
    public void removeQuantity(double quantity) 
    {
        if (quantity < 0) {
            throw new IllegalArgumentException("Quantity to remove must be non-negative.");
        }

        if (this.quantity < quantity) {
            System.out.println("Not enough quantity to remove.");
        } else {
            this.quantity -= quantity;
        }
    }

    /**
     * Calculates the total value of the product based on its price and quantity.
     *
     * @return the total value of the product
     */
    public double getTotalValue() {
        return priceKg * quantity;
    }

    /**
     * Prints information about the product, including its name, price per kilogram, and quantity.
     */
    public void print() {
        System.out.printf("Product: %s, Price per Kg: %.2f, Quantity: %.2f kg%n", name, priceKg, quantity);
    }

    /**
     * Sets the price per kilogram of the product.
     *
     * @param priceKg the new price per kilogram
     * @throws IllegalArgumentException if priceKg is negative
     */
    public void setPriceKg(double priceKg) 
    {
        if (priceKg < 0) {
            throw new IllegalArgumentException("Price per Kg must be non-negative.");
        }

        this.priceKg = priceKg;
    }

}
